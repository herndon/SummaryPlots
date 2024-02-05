#!/usr/bin/env python
import os, argparse, types, sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import matplotlib.transforms as transforms
from matplotlib.ticker import MultipleLocator, FormatStrFormatter
from matplotlib.ticker import LogLocator
import mplhep as hep
import matplotlib as mpl


#import mplcursors
from CrossSectionAnalysisBar import *   

import csv

path = os.getcwd()+'/'

inputfileprefix = "CrossSectionBarchartInputTable"
#inputfileprefix = "CrossSectionBarchartInputTableCurrent"
# start with csv instead of numbers
#os.system('osascript numbers2csv.scpt '+path+inputfileprefix)

ABs = CrossSectionAnalysisBars()



#----------------------------#------------------------#----------------------#
#
# some global options
#
preliminaryLabel = "preliminary"                          # "preliminary" label

#
# command line options
#
parser = argparse.ArgumentParser(formatter_class=argparse.ArgumentDefaultsHelpFormatter)
parser.add_argument('--cadi', '-c', help='always use CADI instead of arXiv number', dest='cadi', \
                        action='store_true', default=False)
parser.add_argument('--verbose', '-v', help='verbose output', dest='verbose', \
                        action='store_true', default=False)
parser.add_argument('--grid', '-g', help='show grid', dest='grid', \
                        action='store_true', default=False)
parser.add_argument('--log', '-l', help='log x scale', dest='logx', \
                        action='store_true', default=False)
parser.add_argument('--jets', '-j', help='X + jets plot', dest='jets', \
                        action='store_true', default=False)
parser.add_argument('--paperformat', '-p', help='Physics Reports format plots', dest='paperformat', \
                        action='store_true', default=False)
parser.add_argument('--ratio', '-r', help='Ratio plot', dest='ratio', \
                        action='store_true', default=False)
parser.add_argument('--batch', '-b', help='batch mode (produce pdf and exit)', dest='batch', \
                        action='store_true', default=False)
parser.add_argument('--output', '-o', help='output file', dest='output', type=str, default=None)
parser.add_argument('categories', nargs='+', choices=ABs.categories.keys())
args = parser.parse_args()
verbose = args.verbose

ABs.setverbose(args.verbose)
ABs.setjets(args.jets)
ABs.setpaperformat(args.paperformat)

if args.paperformat and not args.jets:
    preliminaryLabel = ""



with open('CrossSectionBarChartInputTable.csv') as csvfile:
    reader = csv.reader(csvfile)
    for ir,row in enumerate(reader):
        if not ir:
            labels = row
        else:
            if not row[0]=="":
                auxstring = "ABs.add("+",".join(labels[i]+"=None" if row[i]=="" else labels[i]+'=r"'+row[i]+'"' for i in range(len(row)))+")"
                if verbose: print(auxstring)
                exec(auxstring)


#
# define category
#
if args.categories[0] == 'ALL':
    args.categories = ['QCD', 'EW', 'DB', 'TB', 'VBS', 'TOP', 'HIG']

print (args.categories)
ncat = len(args.categories)

# prefix for output files
filename = 'CMSCrossSectionSummaryBarChart'
if (args.ratio): filename = 'CMSCrossSectionRatioSummaryBarChart'
if (args.jets): filename = 'CMSCrossSectionXJetsSummaryBarChart'


#------------ body ------------------------#

xmin = 1000000000000000.0
xmax = 1.

AB_categories = {}
nbars_tot = 0
for cat in args.categories:
    AB_categories[cat] = CrossSectionAnalysisCategory(args.verbose,args.jets,args.ratio,args.paperformat,cat,ABs)
    if AB_categories[cat].xmax > xmax: xmax = AB_categories[cat].xmax
    if AB_categories[cat].xmin < xmin: xmin = AB_categories[cat].xmin
    nbars_tot += AB_categories[cat].nbars

if verbose: print (AB_categories)
print (xmax)
print (xmin)
        
if args.logx:
    if (xmin < 0.0): xmin = 0.1
    xmin = xmin/20.0
    if args.paperformat: xmin = xmin*15.0
    if largePlot: xmin = xmin/400.0
    xmax = 2.*xmax
    if (not args.jets): xmax = xmax*10.0
    # triboson needs 2000*xmax
    if largePlot: xmax = 2.*xmax
else:
    xmin = 0.
    xmax = 1.05*xmax   
    

#
# define canvas size and margins
#
cnvSizeX = 35.*scale
#cnvSizeX = 50.*scale
cnvMarginLeft = 6.3*scale
if args.paperformat: cnvMarginLeft = 4.2*scale
if largePlot: cnvMarginLeft = 15.0*scale
if args.ratio: cnvMarginLeft = 25.0*scale
cnvMarginRight = 1.3*scale
if args.paperformat: cnvMarginRight = 0.4*scale
if largePlot: cnvMarginRight = 4.0*scale
cnvMarginTop = 1.7*scale
if largePlot: cnvMarginTop = 1.7*scale
cnvMarginBottom = 1.5*scale
cnvSizeY = (nbars_tot+2)*bar_height+cnvMarginTop+cnvMarginBottom
#
# setup matplotlib
#
#plt.rc('text', usetex=True)
#plt.rc('font', family='sans-serif',sans-serif='Tahoma',style='normal',variant='normal',weight='normal',stretch='condensed')
from matplotlib import rcParams
rcParams['font.family'] = 'sans-serif'
#rcParams['font.sans-serif'] = ['Tahoma']
rcParams['font.sans-serif'] = ['DejaVu Sans']
rcParams['font.stretch'] = 'condensed'

plt.style.use([hep.style.ROOT, hep.style.firamath])
plt.style.use(hep.style.CMS)

mpl.rcParams['axes.linewidth'] = 1.2


fig = plt.figure(figsize=(cnvSizeX,cnvSizeY))
# adjust plot size
fig.subplots_adjust(left=cnvMarginLeft/cnvSizeX, right=1.-cnvMarginRight/cnvSizeX, \
                    top=1.-cnvMarginTop/cnvSizeY, bottom=cnvMarginBottom/cnvSizeY)
if verbose: print ([ycat.nbars for ycat in AB_categories.values()])
gs = gridspec.GridSpec(ncat, 1, hspace = 0.0, height_ratios = [ycat.nbars+1 for ycat in AB_categories.values()])

all_axes = []
if verbose: print("Is this the order?", AB_categories.values())
print("Keys", AB_categories.keys())
#for icat,AB_category in reversed(list(enumerate(AB_categories.values()))):
for icat,AB_category in enumerate(AB_categories.values()):
    print("Now adding", AB_category.name_tex)
    print(xmin,xmax)
    ax = AB_category.add_plot(fig,gs[icat],args.cadi,[xmin,xmax],args.logx)
    all_axes.append(ax)

all_axes[-1].tick_params(axis='x', which='both', reset=True, top=False, direction='in')
for tl in all_axes[-1].get_xticklabels():
    tl.set_size(0.75*textsize)

for ax in all_axes:
    ax.tick_params(axis='y', which='both', reset=True, right=False, left=False)
    
for ax in all_axes:
    ax.xaxis.set_major_formatter('{x:9<5.1e}')

    
if args.grid:
    for ax in all_axes:
        ax.xaxis.grid(True, linestyle='--', color='grey', alpha=0.25)
        if args.paperformat: ax.yaxis.grid(True, which='major',linestyle='dotted', color='grey', alpha=0.08)

for ax in all_axes:
    ax.set_xscale('log')
    ax.xaxis.set_major_locator(LogLocator(base=1000))
     
my_xticks = ['','','fb','pb','nb','$\mu$b','b']
all_axes[-1].set_xticklabels(my_xticks)

if (not args.jets) :
    d = 2.0 
    kwargs = dict(marker=[(-1, -d), (1, d)], markersize=12,
              linestyle="none", color='k', mec='k', mew=1, clip_on=False)
    all_axes[-1].plot([0.84, 0.845], [0.0, 0.0], transform=all_axes[-1].transAxes, **kwargs)
    all_axes[0].plot([0.84, 0.845], [1.0, 1.0], transform=all_axes[0].transAxes, **kwargs)


#------------CMS Headers ------------------------#
thdr3 = "Overview of CMS cross section results"
if (args.jets): thdr3 = "CMS X+Jets cross section results"
if (args.ratio): thdr3 = "Ratio comparison of cross section to predictions"
ax1 = all_axes[0]
ymax = ax1.get_ylim()[1]
gap = ax1.transData.inverted().transform_point(ax1.transAxes.transform_point((0.01,0)))
hdr1 = ax1.text(gap[0],ymax+0.5, \
                r"CMS "+preliminaryLabel+"", \
                horizontalalignment='left',verticalalignment='bottom',color='black',weight='bold',
                size=textsize*0.6)
if (not args.jets) :
    hdr2 = ax1.text(xmax,ymax+1.0, \
                    #                r"36 $\mathrm{fb}^{-1}$ (13 TeV)", \
                    r"3 $\mu$b$^{-1}$ - 138 fb$^{-1}$ (2.76,5.02,7,8,13,13.6 TeV)", \
                    horizontalalignment='right',verticalalignment='bottom',color='black',
                    size=textsize*0.6)
if (args.jets) :
    hdr2 = ax1.text(xmax,ymax+1.0, \
                    #                r"36 $\mathrm{fb}^{-1}$ (13 TeV)", \
                    r"2 fb$^{-1}$ - 138 fb$^{-1}$ (7,8,13 TeV)", \
                    horizontalalignment='right',verticalalignment='bottom',color='black',
                    size=textsize*0.6)

    
hdr3 = ax1.text(0.5,0.99, \
                r""+thdr3+"", \
                horizontalalignment='center',verticalalignment='top',color=title_color,weight='bold',
                transform = fig.transFigure,
                size=textsize*2.0)
if not (args.paperformat) :
    hdr4 = ax1.text(0.97,0.025, \
                    r"August 2023", \
                    horizontalalignment='right',verticalalignment='bottom',color='black',weight='bold',
                    transform = fig.transFigure,
                    size=textsize*0.5)

#-------------Foot note--------------------------#
textYPosition1 = 0.03
textYPosition2 = 0.02
textYPosition3 = 0.01

textYPosition1 = 0.020
textYPosition2 = 0.010
textYPosition3 = 0.01


if not (args.ratio) :
    caption = ax1.text(0.03,textYPosition1, \
                       "Measured cross sections and exclusion limits at 95% C.L.",
                       horizontalalignment='left',verticalalignment='center',color='black',
                       transform = fig.transFigure,
                       size=textsize*0.5)

if (args.ratio) :
    caption = ax1.text(0.03,textYPosition1, \
                       "Ratios of measured cross sections to predictions",
                       horizontalalignment='left',verticalalignment='center',color='black',
                       transform = fig.transFigure,
                       size=textsize*0.5)
if not (args.paperformat) :
    caption = ax1.text(0.03,textYPosition2, \
                       "See here for all cross section summary plots",
                       horizontalalignment='left',verticalalignment='center',url='https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsCombined',color='black',
                       transform = fig.transFigure,
                       size=textsize*0.5)

caption = ax1.text(0.25,textYPosition1, \
                "Inner colored bars statistical uncertainty, outer narrow bars statistical+systematic uncertainty",
                horizontalalignment='left',verticalalignment='center',color='black',
                transform = fig.transFigure,
                size=textsize*0.5)

caption = ax1.text(0.25,textYPosition2, \
                   "Light to Dark colored bars: 2.76, 5.02, 7, 8, 13, 13.6 TeV, Black bars: theory prediction",
                horizontalalignment='left',verticalalignment='center',color='black',
                transform = fig.transFigure,
                size=textsize*0.5)



#--------------Output-----------------------------#

if args.output!=None:
    fname = args.output
else:
    analysis_group = "_".join(args.categories)
    fname = path+filename
#    fname = path+filename+"_"+analysis_group
    
plt.savefig(fname=fname+".pdf",format="pdf")
plt.savefig(fname=fname+".svg",format="svg")
plt.savefig(fname=fname+".png",format="png")

if not args.batch:
    plt.show()
sys.exit(0)

#--------------------------------------------------#
