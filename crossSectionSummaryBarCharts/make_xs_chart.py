###################################
# Author: Jan van der Linden (2024)
# Requires LCG_102 or newer
# source /cvmfs/sft.cern.ch/lcg/views/LCG_102rc1/x86_64-centos7-gcc11-opt/setup.sh
###################################

#cat colors
style = {
    "13.6": ("#7a21dd", "P"),
    "13.0": ("#e42536", "o"),
    "8.0":  ("#5790FC", "^"), 
    "7.0":  ("#f89c20", "v"),
    "5.02": ("#964a8b", "s"),
    "2.76": ("#69d84f", "d")
    }
label_style = {
    "13.6": r"13.6 TeV ($L \leq 5\,fb^{-1}$)",
    "13.0": r"13 TeV ($L \leq 138\,fb^{-1}$)",
    "8.0":  r"8 TeV ($L \leq 19.6\,fb^{-1}$)", 
    "7.0":  r"7 TeV ($L \leq 5\,fb^{-1}$)",
    "5.02": r"5.02 TeV ($L \leq 231\,nb^{-1}$)",
    "2.76": r"2.76 TeV ($L \leq 231\,nb^{-1}$)"
    }
def get_style(com):
    cfg = style.get(str(com), None)
    if cfg is None:
        print(f"ERROR no style set for {com}")
        exit()
    return cfg
def get_legend(com, hdls, limit=False):
    label = label_style.get(str(com), None)
    if label is None:
        print(f"ERROR no label for {com}")
        exit()
    tag = "exp"
    if limit: 
        tag = "limit"
        label = f"95% CL limit at "+label
    return f"{tag}_{com}", (hdls, label)


import os
import pandas as pd
import numpy as np
import time
import yaml
import matplotlib as mpl
import optparse
parser = optparse.OptionParser("""
    python3 make_xs_chart.py -i DATA.csv -y DATA.yml -o OUTDIR [--no-date]
    """)
parser.add_option("-i", dest="in_file", help="Input csv file (data)")
parser.add_option("-y", dest="in_yaml", help="Input yml file (plotting order)")
parser.add_option("-o", dest="out_dir", default=".", help="Output directory")
parser.add_option("-d", dest="data_set", default="cms", help="data set")
parser.add_option("--cmslabel", "-l", dest="cmslabel", default="",
        help="Label on top of plot (e.g. Preliminary)")
parser.add_option("--no-date", dest="date_label", default=True, action="store_false",
        help="Remove date label on top of plot")
(opts, args) = parser.parse_args()


# load dataframe with data
df = pd.read_csv(opts.in_file)
df.set_index("label", inplace=True)

# load yml with plot layout
with open(opts.in_yaml, "r") as yf:
    plot_data = yaml.load(yf, Loader=yaml.SafeLoader)

# class for data points
class DataPoint:
    def __init__(self, label, df=df, unit=1e-3):
        self.label = label
        self.unit = unit
        self.data = df.loc[self.label]

        self.buf_t = 0.4
        self.buf_m = 0.25
        self.color_t = "#9c9ca1"
        self.alpha_t = 1.0
        self.alpha_m = 0.8

    def get_label(self, x, w=0):
        journal = self.data["paper"]
        cadi = self.data["cadi"]
        cms_pub = f"https://cms-results.web.cern.ch/cms-results/public-results/publications/{cadi}/"
        #arxiv = f"https://arxiv.org/abs/{self.data['arxiv']}"
        return (journal, cms_pub, x+w)

    def annotate(self, x, w=0, label=None):
        x *= -1 # fill from top

        # get max value in this row
        xs_t = self.data["xs_theory"]*self.unit
        up_t = self.data["theory_up"]*self.unit + xs_t

        xs_m = self.data["xs"]*self.unit 
        up_m = self.data["tot_up"]*self.unit + xs_m

        x_max = max([up_m, up_t, xs_t, xs_m])
        ax.annotate(label, xy=(x_max*1.1, x),
            fontsize=20, va="center", color="black")
    

    def plot_ratio(self, x, w=0): 
        x *= -1 # fill from top

        xs_t = self.data["xs_theory"]*self.unit
        dn_t = self.data["theory_down"]*self.unit / xs_t
        up_t = self.data["theory_up"]*self.unit / xs_t
        

        xs_m = self.data["xs"]*self.unit / xs_t
        dn_m = self.data["tot_down"]*self.unit / xs_t
        up_m = self.data["tot_up"]*self.unit / xs_t


        # theory
        rx.fill_between([1.-dn_t, 1.+up_t],
            x-w-self.buf_t, x-w+self.buf_t,
            color=self.color_t, alpha=self.alpha_t, zorder=1
            )

        # experiment
        color, marker = get_style(str(self.data["com"]))
        if up_m==0. or dn_m==xs_m:
            self.plot_limit(x, w, lim=xs_m, up=xs_m+1, 
                color=color, axis=rx)
        else:
            rx.fill_between([xs_m-dn_m, xs_m+up_m],
                x-w-self.buf_m, x-w+self.buf_m, color=color,
                zorder=2, alpha=self.alpha_m, lw=0.
                )
            rx.plot(xs_m, x-w, zorder=3, ls="",
                marker=marker, markeredgewidth=3, ms=12,
                fillstyle="none", color="black")

    def plot_theory(self, x, w=0):
        x *= -1 # fill from top

        xs = self.data["xs_theory"]*self.unit
        dn = self.data["theory_down"]*self.unit
        up = self.data["theory_up"]*self.unit
        #print(f"theory xs: {xs}")
        hdl = ax.fill_between([xs-dn, xs+up],
            x-w-self.buf_t, x-w+self.buf_t, 
            color=self.color_t, alpha=self.alpha_t, zorder=1
            )
        return "theory", (hdl, "Theory prediction")

    def plot_limit(self, x, w, lim, up, color, axis):
        rng = np.linspace(lim, up, 50)
        for mx in rng:
            axis.fill_between([lim, mx],
                x-w-self.buf_m, x-w+self.buf_m,
                hatch="//", color=color, alpha=0.02,
                lw=0., zorder=2, edgecolor=color)

        hdl_hatch = axis.fill_between([lim, up],
            x-w-self.buf_m, x-w+self.buf_m,
            hatch="//", facecolor="none", edgecolor=color,
            linewidth=0, alpha=0.7, zorder=3)

        # for legend
        hdl_fill = axis.fill_between([lim, lim],
            x-w-self.buf_m, x-w+self.buf_m,
            color=color, alpha=0.2, zorder=3)

        hdl_line = axis.plot([lim, lim],
            [x-self.buf_m, x+w+self.buf_m],
            color=color, lw=3, zorder=4)
    
        return hdl_fill, hdl_hatch

    def plot_measurement(self, x, w=0):
        x *= -1 # fill from top

        color, marker = get_style(str(self.data["com"]))
        xs = self.data["xs"]*self.unit
        dn = self.data["tot_down"]*self.unit
        up = self.data["tot_up"]*self.unit
        #print(f"measured xs: {xs}")

        # limit encoding
        if up==0. or dn==xs:
            hdl_fill, hdl_hatch = self.plot_limit(x, w, 
                lim=xs, up=xs*3, color=color, axis=ax)
            return get_legend(self.data["com"], (hdl_fill, hdl_hatch), limit=True)
        else:
            hdl_fill = ax.fill_between([xs-dn, xs+up],
                x-w-self.buf_m, x-w+self.buf_m, color=color, 
                zorder=2, alpha=self.alpha_m, lw=0.
                )
            hdl_point = ax.plot(xs, x-w, zorder=3, ls="",
                marker=marker, markeredgewidth=3, ms=12,
                fillstyle="none", color="black") 
            return get_legend(self.data["com"], (hdl_fill, hdl_point[0]))

# plot
import matplotlib.pyplot as plt
import mplhep
import mplhep.cms
plt.style.use(mplhep.style.CMS)
plt.rcParams.update({"font.size": 35})

# count plot length first
length = 0
for group in plot_data:
    n_entries = len(plot_data[group]["data"])
    print(n_entries)
    if n_entries == 1:
        length += 2
    else:
        length += n_entries

# setup plot
fig, (ax, rx) = plt.subplots(1, 2, figsize=(25, 4+length/2.),
        sharey=True,
        gridspec_kw={"width_ratios": (4,1)})
plt.subplots_adjust(wspace=0.01)
x = 0
ticks = [x-0.5]
label_pos = []
xlabels = []
pub_labels = []
legend_entries = {}

# one group, divided by vertical line
for group in plot_data:
    content = plot_data[group]
    entries = content["data"]
    label = content["label"]
    sublabel = content.get("sublabel","")

    xlabels.append(label)
    w = 0 if len(entries) > 1 else 0.5 # extra width for single entries

    # different entries per group (usually different c.o.m.)
    for entry in entries:
        # set up data point
        p = DataPoint(entry)

        # plot theory 
        l_type, legend = p.plot_theory(x, w)
        if not l_type in legend_entries:
            legend_entries[l_type] = legend        

        # plot experiment
        l_type, legend = p.plot_measurement(x, w)
        if not l_type in legend_entries:
            legend_entries[l_type] = legend        

        # plot ratio
        p.plot_ratio(x, w)

        # annotate
        p.annotate(x, w, label=entries[entry])

        # get publication label
        # will be plotted later as we need to know the max x range of plot
        pub_labels.append(p.get_label(x, w))

        x += 1+2*w # move down in plot
    
    # draw separator at end of group
    ticks.append(x-0.5)

# save fig
timestamp = time.strftime("%Y_%m_%d",time.localtime())
out_file = os.path.join(opts.out_dir, f"xs_{opts.data_set}_summary_{timestamp}.pdf")
# make nice
ax.set_xscale("log")

# draw separator horizontallines
ticks = -1*np.array(ticks[::-1])
label_pos = (ticks[:-1] + ticks[1:])/2.
ax.set_ylim([ticks[0], ticks[-1]])
for axis in [ax, rx]:
    axis.set_yticks(ticks=label_pos, minor=False)
    axis.set_yticks(ticks=ticks, minor=True)
    axis.set_yticklabels(xlabels[::-1], minor=False)
    axis.tick_params(axis="y", which="major", length=0)
    axis.grid(which="minor", axis="y", lw=1, ls=":", color="black", alpha=0.7)

# vertical line for ratio
rx.plot([1., 1.], [ticks[0], ticks[-1]], lw=1, ls="--", color="black", zorder=1)
rx.set_xlim([0., 3.])
# add labels for the publications
xmin, xmax = ax.get_xlim()
lmin = np.log10(xmin)
lmax = np.log10(xmax)
new_lmax = lmin+(lmax - lmin)*1.25
ax.set_xlim([xmin, 10**new_lmax])

# labels
ax.set_xlabel(f"Production cross section, $\sigma$ (pb)", loc="center")
rx.set_xlabel(f"Data/Theory", loc="center")
for journal, link, y in pub_labels:
    ax.annotate(journal, xy=(xmax, -y),
        fontsize=20, va="center", color="blue", url=link)

# legend
leg_handles = [legend_entries[e][0] for e in legend_entries]
leg_entries = [legend_entries[e][1] for e in legend_entries]
l1 = ax.legend(leg_handles, leg_entries,
    loc="upper left", ncol=1, fontsize=27)
ax.add_artist(l1)



rlabel = ""
if opts.date_label:
    rlabel = time.strftime("%B %Y")
mplhep.cms.label(ax=ax, data=True,
    rlabel=rlabel,
    label=opts.cmslabel)


plt.tight_layout()
plt.savefig(out_file)
plt.savefig(out_file.replace(".pdf",".png"))
