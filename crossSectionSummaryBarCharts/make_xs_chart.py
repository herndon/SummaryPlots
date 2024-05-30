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
    "5.02": r"5.02 TeV ($L \leq 302\,pb^{-1}$)",
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
        label = f"95% CL limit at "+"\n"+label
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
parser.add_option("-d", dest="data_set", default="cms", help="data set (for plot name)")
parser.add_option("-b","--label-buffer", dest="label_buffer", default=0., type=float,
        help="Buffer between cross sections and citation labels (default=0., recommended=0.05)")
parser.add_option("-r","--rotate-label", dest="rotate_label", default=False, action="store_true",
        help="tilt/rotate process labels on axis (useful when labels are overlapping)")
parser.add_option("--cmslabel", "-l", dest="cmslabel", default="",
        help="Label on top of plot (e.g. Preliminary)")
parser.add_option("--rmax", dest="rmax", default=-1, type=float, 
        help="Max value of ratio panel. If -1 show full range (default)")
parser.add_option("--no-date", dest="date_label", default=True, action="store_false",
        help="Remove date label on top of plot")
parser.add_option("--no-ratio", dest="do_ratio", default=True, action="store_false",
        help="Remove ratio panel")
parser.add_option("--no-references", dest="add_references", default=True, action="store_false",
        help="Remove links to publications")
parser.add_option("--horizontal", dest="do_horizontal", default=False, action="store_true",
        help="Make plot horizontally")
parser.add_option("--brokenaxis", dest="do_broken_axis", default=False, action="store_true",
        help="Broken axis for the large cross sections")
parser.add_option("--order-legend", dest="order_legend", default=False, action="store_true",
        help="Order legend, user needs to define order vector below")
(opts, args) = parser.parse_args()


# load dataframe with data
df = pd.read_csv(opts.in_file)
df.set_index("label", inplace=True)

# load yml with plot layout
with open(opts.in_yaml, "r") as yf:
    plot_data = yaml.load(yf, Loader=yaml.SafeLoader)

# class for a single point
class xyPoint:
    '''
    convenience wrapper around point for plotting
    taking into account different axis layouts.
    '''
    def __init__(self, xs, xs_dn, xs_up, ax_pos, width, horizontal=opts.do_horizontal):
        if horizontal:
            self.x = ax_pos 
            self.x_hi = ax_pos+width
            self.x_lo = ax_pos-width
            self.y = xs # cross sections on y axis
            self.y_hi = xs+xs_up        
            self.y_lo = xs-xs_dn
        else:
            self.x = xs # cross sections on x axis
            self.x_hi = xs+xs_up
            self.x_lo = xs-xs_dn        
            self.y = ax_pos
            self.y_hi = ax_pos+width
            self.y_lo = ax_pos-width
    
    @property
    def x_rng(self):
        return [self.x_lo, self.x_hi]
    @property
    def y_rng(self):
        return [self.y_lo, self.y_hi]
    
        
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

        self.horizontal = opts.do_horizontal # FIXME: could also be externalized if class is to be used outside of this script

    def get_xpos(self, x, w):
        '''
        return proper x value taking into account the width w and plotting direction
        '''
        if self.horizontal:
            return (x+w)
        else:
            return -(x+w)

    def get_label(self, x, w=0):
        journal = self.data["paper"]
        cadi = self.data["cadi"]
        #cms_pub = f"https://cms-results.web.cern.ch/cms-results/public-results/publications/{cadi}/"
        arxiv = f"https://arxiv.org/abs/{self.data['arxiv']}"
        if "cds" in arxiv:
            arxiv = self.data['arxiv']
            journal = self.data["cadi"]
        if "doi" in arxiv:
            arxiv = self.data['arxiv']
        return (journal, arxiv, x+w)

    def annotate(self, x, w=0, label=None):
        '''
        print a label next to the data point in the main canvas
        '''
        xp = self.get_xpos(x, w)

        # get max value in this row
        xs_t = self.data["xs_theory"]*self.unit
        up_t = xs_t + self.data["theory_up"]*self.unit 
        dn_t = xs_t - self.data["theory_down"]*self.unit

        xs_m = self.data["xs"]*self.unit 
        up_m = xs_m + self.data["tot_up"]*self.unit 
        dn_m = xs_m - self.data["tot_down"]*self.unit
        if up_m == xs_m: # for limits
            up_m *= 3

        x_max = max([up_m, up_t, xs_t, xs_m])
        x_min = min([dn_m, dn_t, xs_t, xs_m])
        x_min_scale = 1.0
        if label and 't_{tchan}' in label : x_min_scale = 12.0
        if label and 'tW~' in label : x_min_scale = 0.4
        if label and 't_{schan}' in label : x_min_scale = 0.04
        if label == "$\hspace{-0.7} VBF~W$" :  x_min_scale = 0.8
        if label and 'VVV' in label :  x_min_scale = 8.0
        if label and 'WWZ' in label :  x_min_scale = 0.4
        if label == "$\hspace{0.5} t\overline{t}W$" :  x_min_scale = 8.0
        if label and ('ex' in label) and ('WW' in label) :  x_min_scale = 21.0
        if label == "$\hspace{-0.9} Z\gamma\gamma$" : x_min_scale = 16.0

        if label and '\\n' in label:
            label = '"\\n"'.join([f'r"{x}"' for x in label.split('\\n')])
            label = eval(label)

        
        if self.horizontal and opts.do_broken_axis:
            ax.annotate(label, xy=(xp, x_min*x_min_scale/2.0), rotation="horizontal",
                        fontsize=20, va="top", ha="left", color="black")
        elif self.horizontal :
            ax.annotate(label, xy=(xp, x_min*x_min_scale/2.0), rotation="vertical",
                        fontsize=20, va="top", ha="left", color="black")
        else:
            ax.annotate(label, xy=(x_max*1.1, xp),
                fontsize=20, va="center", color="black")
     
            
    def plot_ratio(self, x, w=0): 
        '''
        plot theory and measurement points into ratio panel
        '''
        xp = self.get_xpos(x, w)

        xs_t = self.data["xs_theory"]*self.unit
        dn_t = self.data["theory_down"]*self.unit / xs_t
        up_t = self.data["theory_up"]*self.unit / xs_t
        
        xs_m = self.data["xs"]*self.unit / xs_t
        dn_m = self.data["tot_down"]*self.unit / xs_t
        up_m = self.data["tot_up"]*self.unit / xs_t

        # theory (grey band)
        p = xyPoint(1., dn_t, up_t, xp, self.buf_t)

        if (self.data["theory_down"] > 0.0 ):
            rx.fill_between(p.x_rng, p.y_lo, p.y_hi,
                color=self.color_t, alpha=self.alpha_t, zorder=1
                )

        # experiment 
        color, marker = get_style(str(self.data["com"]))
        if up_m==0. or dn_m==xs_m:
            self.plot_limit(xp, lim=xs_m, up=xs_m+1, 
                color=color, axis=rx)
        else:
            p = xyPoint(xs_m, dn_m, up_m, xp, self.buf_m)

            # colored band
            rx.fill_between(p.x_rng, p.y_lo, p.y_hi, 
                color=color, zorder=2, alpha=self.alpha_m, lw=0.
                )
            # marker
            rx.plot(p.x, p.y, zorder=3, ls="",
                marker=marker, markeredgewidth=3, ms=12,
                fillstyle="none", color="black")

    def plot_theory(self, x, w=0):
        '''
        add theory prediction as grey band in background
        return (type, (legend handel, legend label))
        '''
        xp = self.get_xpos(x, w)

        xs = self.data["xs_theory"]*self.unit
        dn = self.data["theory_down"]*self.unit
        up = self.data["theory_up"]*self.unit
        #print(f"theory xs: {xs}")

        p = xyPoint(xs, dn, up, xp, self.buf_t)

        # grey band
        # deal with case where there are no theory errors
        if (self.data["theory_down"] > 0.0 ):
            hdl = ax.fill_between(p.x_rng, p.y_lo, p.y_hi,
                color=self.color_t, alpha=self.alpha_t, zorder=1
                )
        else:
            hdl = ax.fill_between(p.x_rng, p.y_lo, p.y_hi,
                color='white', alpha=self.alpha_t, zorder=1
                )
           
        return "theory", (hdl, "Theory prediction")

    def plot_limit(self, xp, lim, up, color, axis):
        '''
        plot limit as a hatched band with fading background
        return (legend handle for filled background, legend handle for hatched area) 
        '''

        # plot 50 overlapping patches to create fading color effect
        rng = np.linspace(lim, up, 50)
        for mx in rng:
            p = xyPoint(lim, 0, mx-lim, xp, self.buf_m)
            axis.fill_between(p.x_rng, p.y_lo, p.y_hi,
                hatch="//", color=color, alpha=0.02,
                lw=0., zorder=2, edgecolor=color)

        # hatched band
        p = xyPoint(lim, 0, up-lim, xp, self.buf_m)
        hdl_hatch = axis.fill_between(p.x_rng, p.y_lo, p.y_hi,
            hatch="//", facecolor="none", edgecolor=color,
            linewidth=0, alpha=0.7, zorder=3)

        # for legend create a dummy filled area
        p = xyPoint(lim, 0, 0, xp, self.buf_m)
        hdl_fill = axis.fill_between(p.x_rng, p.y_lo, p.y_hi,
            color=color, alpha=0.2, zorder=3)

        # draw line at limit value
        axis.plot(p.x_rng, p.y_rng,
            color=color, lw=3, zorder=4)
    
        return hdl_fill, hdl_hatch

    def plot_measurement(self, x, w=0):
        '''
        add measurement point
        return (type, ([legend handles], legend label))
        '''
        xp = self.get_xpos(x, w)

        color, marker = get_style(str(self.data["com"]))
        xs = self.data["xs"]*self.unit
        dn = self.data["tot_down"]*self.unit
        up = self.data["tot_up"]*self.unit
        #print(f"measured xs: {xs}")

        # limit encoding
        if up==0. or dn==xs:
            # call dedicated limit function
            hdl_fill, hdl_hatch = self.plot_limit(xp, 
                lim=xs, up=xs*3, color=color, axis=ax)
            return get_legend(self.data["com"], (hdl_fill, hdl_hatch), limit=True)
        else:
            # normal data point
            p = xyPoint(xs, dn, up, xp, self.buf_m)

            # filled color area
            hdl_fill = ax.fill_between(p.x_rng, p.y_lo, p.y_hi,
                color=color, zorder=2, alpha=self.alpha_m, lw=0.
                )
            # marker
            hdl_point = ax.plot(p.x, p.y, zorder=3, ls="",
                marker=marker, markeredgewidth=3, ms=12,
                fillstyle="none", color="black") 
            return get_legend(self.data["com"], (hdl_fill, hdl_point[0]))

# plot
import matplotlib.pyplot as plt
import mplhep
import mplhep.cms
plt.style.use(mplhep.style.CMS)
plt.rcParams.update({"font.size": 50})
if opts.data_set == "sm": plt.rcParams.update({"font.size": 30})

# count plot length first
length = 0
for group in plot_data:
    n_entries = len(plot_data[group]["data"])
    if n_entries == 1:
        length += 2 # if only one entry in process, double the size in the canvas
    else:
        length += n_entries

# setup plot
#if opts.do_horizontal and opts.do_broken_axis:
#    fig, (ax)  = plt.subplots(1, 1, figsize=((4+length/2.)/2.0,(4+length/2.)/(2.0*16.0/9.0)))
#    plt.xticks(fontsize=20)
if opts.do_horizontal:
    if opts.do_ratio:
        fig, (ax, rx) = plt.subplots(2, 1, figsize=(4+length/2., 20.0),
            sharex=True,
            gridspec_kw={"height_ratios": (4,1)})
        plt.subplots_adjust(hspace=0.01)
        plt.xticks(fontsize=35)
    else:
        fig, ax = plt.subplots(1, 1, figsize=((4+length/2.)/2.0,(4+length/2.)/(2.0*16.0/9.0)))
        if opts.data_set=="sm": plt.xticks(fontsize=20)
        if opts.data_set=="sm": plt.yticks(fontsize=20)
        if opts.data_set=="all": plt.xticks(fontsize=30)
#        fig, ax = plt.subplots(1, 1, figsize=((4+length/2.)/2.0, 16))
else:
    if opts.do_ratio:
        fig, (ax, rx) = plt.subplots(1, 2, figsize=(25, 4+length/2.),
            sharey=True,
            gridspec_kw={"width_ratios": (4,1)})
        plt.subplots_adjust(wspace=0.01)
    else:
        fig, ax = plt.subplots(1, 1, figsize=(20, 4+length/2.))

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
    if '\\n' in label:
       label = '"\\n"'.join([f'r"{x}"' for x in label.split('\\n')])
       label = eval(label)
    sublabel = content.get("sublabel","")

    xlabels.append(label)
    w = 0 if len(entries) > 1 and label != "ew\nVV" else 0.25 # extra width for single entries
    #if (opts.do_horizontal and not opts.do_ratio): w = 0

    # different entries per group (usually different c.o.m.)
    for entry in entries:
        # set up data point
        p = DataPoint(entry)

        if entries[entry] == "stack":
            x -= 1+2*w
        
        # plot theory, handle case where there is no theory error 
        l_type, legend = p.plot_theory(x, w)
        if (not l_type in legend_entries) and (p.data["theory_down"] > 0.0):
            legend_entries[l_type] = legend        

        # plot experiment
        l_type, legend = p.plot_measurement(x, w)
        if not l_type in legend_entries:
            legend_entries[l_type] = legend        

        # plot ratio
        if opts.do_ratio:
            p.plot_ratio(x, w)

        # annotate
        if entries[entry] != "stack":
            p.annotate(x, w, label=entries[entry])

        # get publication label
        # will be plotted later as we need to know the max x range of plot
        pub_labels.append(p.get_label(x, w))

        x += 1+2*w # move down in plot
    
    # draw separator at end of group
    ticks.append(x-0.5)

# save fig
timestamp = time.strftime("%Y_%m_%d",time.localtime())
tag=""
if opts.do_horizontal:
    tag += "_horizontal"
if not opts.do_ratio:
    tag += "_noratio"
if not opts.add_references:
    tag += "_norefs"
#out_file = os.path.join(opts.out_dir, f"xs_{opts.data_set}_summary{tag}_{timestamp}.pdf")
out_file = os.path.join(opts.out_dir, f"xs_{opts.data_set}_summary.pdf")

# make nice
if opts.do_horizontal:
    ax.set_yscale("log")
    ticks = np.array(ticks)
    ax.set_xlim([ticks[0], ticks[-1]])
else:
    ax.set_xscale("log")
    ticks = -1*np.array(ticks[::-1])
    ax.set_ylim([ticks[0], ticks[-1]])
label_pos = (ticks[:-1] + ticks[1:])/2.

# draw separator horizontallines

# rotate labels if activated
rotate = 0
if opts.rotate_label:
    rotate = 90
#ax_upper = pickle.loads(p_ax)

    
# set axis labels
if opts.do_ratio:
    axes = [ax, rx]
else:
    axes = [ax]
for axis in axes:
    if opts.do_horizontal:
        axis.set_xticks(ticks=label_pos, minor=False)
        axis.set_xticks(ticks=ticks, minor=True)
        axis.set_xticklabels(xlabels, minor=False, rotation=rotate)
        axis.tick_params(axis="x", which="major", length=0)
        axis.grid(which="minor", axis="x", lw=1, ls=":", color="black", alpha=0.7)
    else:
        axis.set_yticks(ticks=label_pos, minor=False)
        axis.set_yticks(ticks=ticks, minor=True)
        axis.set_yticklabels(xlabels[::-1], minor=False, rotation=rotate, fontsize=35)
        axis.tick_params(axis="y", which="major", length=0)
        axis.grid(which="minor", axis="y", lw=1, ls=":", color="black", alpha=0.7)

# vertical line for ratio
if opts.do_ratio:
    if opts.do_horizontal:
        rx.plot([ticks[0], ticks[-1]], [1., 1.], lw=1, ls="--", color="black", zorder=1)
        if opts.rmax != -1:
            rx.set_ylim([0., opts.rmax])
    else:
        rx.plot([1., 1.], [ticks[0], ticks[-1]], lw=1, ls="--", color="black", zorder=1)
        if opts.rmax != -1:
            rx.set_xlim([0., opts.rmax])

# add space on axis for publication labels
if opts.do_horizontal:
    xmin, xmax = ax.get_ylim()
else:
    xmin, xmax = ax.get_xlim()
lmin = np.log10(xmin)
lmax = np.log10(xmax)
lrng = lmax - lmin
if opts.add_references:
    new_lmax = lmin+lrng*(1.25+opts.label_buffer)
    new_lmin = lmax-lrng*(1.3+opts.label_buffer)
else:
    new_lmax = lmin+lrng*(1.+opts.label_buffer)
    new_lmin = lmax-lrng*(1.+opts.label_buffer)

if opts.do_horizontal and opts.do_broken_axis:
    new_lmin = -4.0
    xmax = 1000000
    plt.yticks([0.0001,0.001,0.01,0.1,1,10,100,1000,10000,100000,1000000])
    newlabels = [item.get_text() for item in ax.get_yticklabels()]
    newlabels = ['$10^{-4}$','$10^{-3}$','$10^{-2}$','$10^{-1}$','1','$10^{1}$','$10^{2}$','$10^{3}$','$10^{4}$','$10^{5}$','$10^{11}$']
    ax.set_yticklabels(newlabels)
    label_lx = new_lmin+lrng*0.02
    label_x = 10**label_lx

    d = 0.4 

    kwargsh = dict(marker=[(0, 0), (1, 0)], markersize=20,
              linestyle="none", color='k', mec='k', mew=1, clip_on=False)
    ax.plot([0.0, 0.0], [0.9355, 0.9355], transform=ax.transAxes, **kwargsh)

    kwargsh = dict(marker=[(0, 0), (1, 0)], markersize=20,
              linestyle="none", color='k', mec='k', mew=1, clip_on=False)
    ax.plot([0.0, 0.0], [0.925, 0.925], transform=ax.transAxes, **kwargsh)

    kwargsh = dict(marker=[(0, 0), (-1, 0)], markersize=20,
              linestyle="none", color='k', mec='k', mew=1, clip_on=False)
    ax.plot([0.0, 0.0], [0.925, 0.925], transform=ax.transAxes, **kwargsh)

    
    kwargsh = dict(marker=[(0, 0), (-1, 0)], markersize=20,
              linestyle="none", color='k', mec='k', mew=1, clip_on=False)
    ax.plot([0.0, 0.0], [0.9148, 0.9148], transform=ax.transAxes, **kwargsh)


    kwargsh = dict(marker=[(0, 0), (1, 0)], markersize=20,
              linestyle="none", color='k', mec='k', mew=1, clip_on=False)
    ax.plot([1.0, 1.0], [0.9355, 0.9355], transform=ax.transAxes, **kwargsh)

    kwargsh = dict(marker=[(0, 0), (1, 0)], markersize=20,
              linestyle="none", color='k', mec='k', mew=1, clip_on=False)
    ax.plot([1.0, 1.0], [0.925, 0.925], transform=ax.transAxes, **kwargsh)

    kwargsh = dict(marker=[(0, 0), (-1, 0)], markersize=20,
              linestyle="none", color='k', mec='k', mew=1, clip_on=False)
    ax.plot([1.0, 1.0], [0.925, 0.925], transform=ax.transAxes, **kwargsh)

    
    kwargsh = dict(marker=[(0, 0), (-1, 0)], markersize=20,
              linestyle="none", color='k', mec='k', mew=1, clip_on=False)
    ax.plot([1.0, 1.0], [0.9148, 0.9148], transform=ax.transAxes, **kwargsh)



    
    
    kwargs = dict(marker=[(-1, -d), (1, d)], markersize=20,
              linestyle="none", color='k', mec='k', mew=1, clip_on=False)
    ax.plot([0.0, 0.0], [0.920, 0.930], transform=ax.transAxes, **kwargs)
    ax.plot([1.0, 1.0], [0.920, 0.930], transform=ax.transAxes, **kwargs)


elif opts.do_horizontal:
    ax.set_ylim([10**new_lmin, xmax])
    label_lx = new_lmin+lrng*0.02
    label_x = 10**label_lx
else:
    ax.set_xlim([xmin/1.0, 11.5**new_lmax])
    label_lx = lmin+lrng*(1.+opts.label_buffer)
    label_x = 10**label_lx
    # divide xmin by 10 for Higgs plot
    
print(new_lmin)
print(10**new_lmin)
print(xmax)
    
# ewjets plot needs xmin/10 above
# ewjets plot needs xmin/100 above
    
# add axis labels and publication labels
if opts.do_horizontal:
    if opts.data_set=="all":    ax.set_ylabel(f"Production cross section, $\sigma$ (pb)", loc="center", fontsize=55)
    if opts.data_set=="sm":     ax.set_ylabel(f"Production cross section, $\sigma$ (pb)", loc="center", fontsize=35)
    if opts.do_ratio:
        rx.set_ylabel(f"Data/Theory", loc="center")
    if opts.add_references:
        for journal, link, y in pub_labels:
            ax.annotate(journal, xy=(y, label_x), rotation="vertical",
                fontsize=20, ha="center", va="bottom", color="blue", url=link)
else:
    ax.set_xlabel(f"Production cross section, $\sigma$ (pb)", loc="center")
    if opts.do_ratio:
        rx.set_xlabel(f"Data/Theory", loc="center")
    if opts.add_references:
        for journal, link, y in pub_labels:
            ax.annotate(journal, xy=(label_x, -y),
                fontsize=20, va="center", color="blue", url=link)

# legend
leg_handles = [legend_entries[e][0] for e in legend_entries]
leg_entries = [legend_entries[e][1] for e in legend_entries]

if opts.do_horizontal:
    ledfontsize = 30
    if opts.data_set=="sm": ledfontsize = 20
    if opts.data_set=="all": ledfontsize = 30
# reorder legend entries if necessary
    if opts.order_legend:
        if opts.data_set=="all": order = [6,0,3,2,5,4,7,1]
        if opts.data_set=="sm": order = [0,3,1,5,4,6,2]
        if opts.data_set=="top": order =  [1,2,3,4,5,0]
        l1 = ax.legend([leg_handles[idx] for idx in order],[leg_entries[idx] for idx in order],
           loc="upper right", ncol=1, fontsize=ledfontsize,frameon=True,edgecolor="white")
    else:
        l1 = ax.legend(leg_handles,leg_entries,
           loc="upper right", ncol=1, fontsize=ledfontsize,frameon=True,edgecolor="white")
else:
# reorder legend entries if necessary
    if opts.order_legend:
        if opts.data_set=="ew": order = [2,3,1,4,5,6,0]
        if opts.data_set=="ewjet": order = [1,2,3,4,0]
        if opts.data_set=="top": order = [1,2,3,4,5,0]
        if opts.data_set=="higgs": order = [1,2,3,4,0]                
        l1 = ax.legend([leg_handles[idx] for idx in order],[leg_entries[idx] for idx in order],
           loc="upper left", ncol=1, fontsize=35,frameon=True,edgecolor="grey")
    else:
        l1 = ax.legend(leg_handles,leg_entries,
           loc="upper left", ncol=1, fontsize=35,frameon=True,edgecolor="grey")
ax.add_artist(l1)
#plt.legend(facecolor='white', framealpha=1)


# cms label and time stamp
rlabel = ""
if opts.date_label:
    rlabel = time.strftime("%B %Y")
mplhep.cms.label(ax=ax, data=True,
    rlabel=rlabel,
    label=opts.cmslabel)

# save figure
plt.tight_layout()
plt.savefig(out_file)
plt.savefig(out_file.replace(".pdf",".png"))
