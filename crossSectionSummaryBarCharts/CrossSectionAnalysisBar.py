from math import *
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import matplotlib.transforms as transforms
from matplotlib.ticker import ScalarFormatter
import matplotlib.patches as patches
fig, ax = plt.subplots()

#----------------------------#Configure plot from here#----------------------#
scale = 0.5
textsize = 30.*scale
bar_color = 'xkcd:light orange'
bar_edge_color = 'xkcd:royal blue'
yaxis_label_color = 'black'
section_text_color = 'xkcd:royal blue'
desc_text_color = 'xkcd:royal blue'
title_color = 'xkcd:dark orange'
bar_height  =  0.30*scale
#ratioPlot = False
verbose = False

def adjust_lightness(color,amount=0.5):
    import matplotlib.colors as mc
    import colorsys
    try:
        c = mc.cnames[color]
    except:
        c = color
    c = colorsys.rgb_to_hls(*mc.to_rgb(c))
    return colorsys.hls_to_rgb(c[0], max(0, min(1, amount * c[1])), c[2])


#
# Class describing input for one bar in the summary plot.
#
class CrossSectionAnalysisBar:

    def __init__(self,category="Other",name=None,pub=None,cadi=None,paper=None,lumi=None,model=None,comment=None,\
                 finalstate=None,crossSection=None,eTotm=None,eTotp=None,eStatm=None,eStatp=None,eSystm=None,eSystp=None,\
                 crossSectionR=None,eRTotm=None,eRTotp=None,eRStatm=None,eRStatp=None,eRSystm=None,eRSystp=None,\
                 theoryCrossSection=None,eTheorym=None,eTheoryp=None,flag=None):
        self.category = category               # model category
        self.name = name                       # (unique) name. Reserved names: "line", ""
        self.pub = pub
        #self.pub = pub if not pub == None else ""
        #self.pub = pub if not pub == None else cadi
        self.cadi = cadi
        self.paper = paper
        self.lumi = lumi if not lumi == None else ""
        self.model = model
#        self.comment = comment if not comment == None else ""
        self.comment = comment
        self.finalstate = finalstate
        self.theoryCrossSection = float(theoryCrossSection) if not theoryCrossSection==None else 0.
        self.crossSection = float(crossSection) if not crossSection==None else 0.
        self.eTotm = float(eTotm) if not eTotm==None else 0.
        self.eTotp = float(eTotp) if not eTotp==None else 0.
        self.eStatm = float(eStatm) if not eStatm==None else 0.
        self.eStatp = float(eStatp) if not eStatp==None else 0.
        self.eSystm = float(eSystm) if not eSystm==None else 0.
        self.eSystp = float(eSystp) if not eSystp==None else 0.
        self.crossSectionR = float(crossSection)/self.theoryCrossSection if not crossSection==None else 0.
        self.eRTotm = float(eTotm)/self.theoryCrossSection if not eTotm==None else 0.
        self.eRTotp = float(eTotp)/self.theoryCrossSection if not eTotp==None else 0.
        self.eRStatm = float(eStatm)/self.theoryCrossSection if not eStatm==None else 0.
        self.eRStatp = float(eStatp)/self.theoryCrossSection if not eStatp==None else 0.         
        self.eRSystm = float(eSystm)/self.theoryCrossSection if not eSystm==None else 0.
        self.eRSystp = float(eSystp)/self.theoryCrossSection if not eSystp==None else 0.         
        self.eTheorym = float(eTheorym) if not eTheorym==None else 0.
        self.eTheoryp = float(eTheoryp) if not eTheoryp==None else 0.
        self.theoryCrossSectionR = 1.0
        self.eRTheorym = float(eTheorym)/self.theoryCrossSection if not eTheorym==None else 0.
        self.eRTheoryp = float(eTheoryp)/self.theoryCrossSection if not eTheoryp==None else 0.
        self.flag = float(flag)if not flag==None else 0.

        if self.model == None:
            self.header = ""
            #self.header = self.lumi+r" $\mathrm{fb}^{-1}$"
        elif self.comment == None:
            self.header = self.model
            #self.header = ", ".join((self.model,self.lumi+r" $\mathrm{fb}^{-1}$"))
        else:
            self.header = self.model
            #self.header = " ".join((self.model,self.comment))
            #self.header = ", ".join((self.model,self.comment,self.lumi+r" $\mathrm{fb}^{-1}$"))
        if verbose : print("==>",self.header)

        if self.comment == None:
            self.energy = ""
        else:
            self.energy = self.comment
  
        
    def __str__(self):
        ''' Show object as string.
        '''
        result = "Analysis "+self.name
        if self.category: result += "\n  Category: "+self.category
        if self.header: result += "\n    Model: "+self.header
        if self.crossSection: result += "\n    CrossSection: "+self.crossSection
        if self.barleft: result += "\n    FS-pub: "+self.barleft
        if self.eTotm and self.eTotp: result += "\n (Total) +"+str(self.eTotp)+"-"+str(self.eTotm)
        if self.eStatm and self.eStatp: result += "\n (Stat) +"+str(self.eStatp)+"-"+str(self.eStatm)
        if self.theoryCrossSection: result += "\n    Theory: "+str(self.theoryCrossSection)
        if self.eTheorym and self.eTheoryp: result += "\n (Total) +"+str(self.eTheoryp)+"-"+str(self.eTheorym)
                                                                   
        return result

#
# Container for AnalysisBar objects
#
class CrossSectionAnalysisBars:

    def __init__(self,verbose=False,jets=False,category=None):
        self.allBars = [ ]
        self.barsPerCat = { }

        self.categories = { 'EW' : { 'name_tex' : "Electroweak", 'name_size' : 1., 'color' : 'xkcd:baby blue' }, 
                            'DB' : { 'name_tex' : "di-Boson", 'name_size' : 1., 'color' : 'xkcd:apricot' },
                            'TB' : { 'name_tex' : "tri-Boson", 'name_size' : 1., 'color' : 'xkcd:wheat' },
                            'VBS' : { 'name_tex' : "VBF and VBS", 'name_size' : 1., 'color' : 'xkcd:light olive' },
                            'TOP' : { 'name_tex' : "Top", 'name_size' : 1., 'color' : 'xkcd:lavender' },
                            'HIG' : { 'name_tex' : "Higgs", 'name_size' : 1., 'color' : 'xkcd:blush' },
                            'ALL' : {} }

        self.verbose = verbose
        self.jets = jets

    def setverbose(self,verbose):
        self.verbose = verbose
    def setjets(self,jets):
        self.jets = jets
    
        
    def add(self,category=None,name=None,pub=None,cadi=None,paper=None,lumi=None,model=None,comment=None,\
            finalstate=None,crossSection=None,eTotm=None,eTotp=None,eStatm=None,eStatp=None,eSystm=None,eSystp=None,\
            crossSectionR=None,eRTotm=None,eRTotp=None,eRStatm=None,eRStatp=None,eRSystm=None,eRSystp=None,\
            theoryCrossSection=None,eTheorym=None,eTheoryp=None,flag=None):
        if category==None: category = "Other"
        if flag==None: flag='0'
        if (self.jets and flag == '1') : flag = '0'
        if ((not self.jets) and flag == '2') : flag = '0'
        #        print('name:',name,'flag:',flag)
        if not name or flag=='0':
            #print(cadi+": no analysis bar added")
            return
        al = CrossSectionAnalysisBar(category,name,pub,cadi,paper,lumi,model,comment,finalstate,crossSection,eTotm,eTotp,eStatm,eStatp,eSystm,eSystp,crossSectionR,eRTotm,eRTotp,eRStatm,eRStatp,eRSystm,eRSystp,theoryCrossSection,eTheorym,eTheoryp,flag)
        self.allBars.append(al)
        if not category in self.barsPerCat:
            assert category in self.categories
            self.barsPerCat[category] = [ ]
        self.barsPerCat[category].append(al)
        self.barsPerCat[category].sort(key=lambda x: x.flag)

    def getBars(self,category=None):
        if category==None:
            return self.allBars
        else:
            return self.barsPerCat[category]


        
class CrossSectionAnalysisCategory:
    
    def __init__(self,verbose,jets,ratio,category,ABs):

        self.verbose = verbose;
        self.jets = jets;
        self.ratio = ratio;
        
        self.ABs_list = ABs.getBars(category)
        
        self.name_tex = ABs.categories[category]["name_tex"]
        self.name_size = 1.25*ABs.categories[category]["name_size"]
        self.bar_color = ABs.categories[category]["color"]
        
        self.bars_color = [ ]
        self.bar_positions = [ ]   # y-position of the bar (= index)
        self.bar_labellows = [ ]       # lower limits - for labels
        self.bar_crossSection = [ ]       # cross section
        self.bar_vlows = [ ]       # lower limits
        self.bar_vhighs = [ ]      # upper limits
        self.bar_vstatlows = [ ]       # stat lower limits
        self.bar_vstathighs = [ ]      # stat upper limits
        self.bar_vtheory = [ ]         # theory cross section
        self.bar_vtheorylows = [ ]       # theory lower limits
        self.bar_vtheoryhighs = [ ]      # theory upper limits
        self.bar_vdiffs = [ ]      # difference between upper and lower
        self.bar_vtheorydiffs = [ ]      # difference between upper and lower
        self.bar_vstatdiffs = [ ]      # difference between upper and lower
        self.bar_labels = [ ]      # bar labels
        
        self.xmax = 0.
        self.ax = None

        self.theoryCrossSection = 0.0;

        #print(self.ratio)
        
        index = 0
        for al in self.ABs_list[::-1]:
            self.bar_positions.append(index+1)
            self.bar_labellows.append(0.)
            if self.ratio:
                # set cross section and upper and lower bar edges
                self.bar_crossSection.append(al.crossSection/al.theoryCrossSection)
                self.bar_vlows.append((al.crossSection-al.eTotm)/al.theoryCrossSection)
                self.bar_vhighs.append((al.crossSection+al.eTotp)/al.theoryCrossSection)
                # set stat upper and lower bar edges
                self.bar_vstatlows.append((al.crossSection-al.eStatm)/al.theoryCrossSection)
                self.bar_vstathighs.append((al.crossSection+al.eStatp)/al.theoryCrossSection)
                # bar lable using the cross section
                self.bar_labels.append(al.crossSection)
                # set theory upper and lower bar edges
                self.bar_vtheorylows.append(al.theoryCrossSectionR-al.eRTheorym)
                self.bar_vtheoryhighs.append(al.theoryCrossSectionR+al.eRTheoryp)
            else:
                # set cross section and upper and lower bar edges
                self.bar_crossSection.append(al.crossSection)
                self.bar_vlows.append(al.crossSection-al.eTotm)
                self.bar_vhighs.append(al.crossSection+al.eTotp)
                # set stat upper and lower bar edges
                self.bar_vstatlows.append(al.crossSection-al.eStatm)
                self.bar_vstathighs.append(al.crossSection+al.eStatp)
                # bar lable using the cross section
                self.bar_labels.append(al.crossSection)
                # keep trace of maximum limit
                if (al.crossSection+al.eTotp)>self.xmax: self.xmax = al.crossSection+al.eTotp
                self.bar_vtheorylows.append(al.theoryCrossSection-al.eTheorym)
                self.bar_vtheoryhighs.append(al.theoryCrossSection+al.eTheoryp)
            if self.ratio: self.xmax = 5.0
           # set theory lower and upper limit
            theorystring = "%0.1f fb" % (al.crossSection)
            self.bar_vtheory.append('https://large-type.com/#*'+theorystring+'*')
            bar_color = ABs.categories[category]["color"]
            if al.energy == "7 TeV":
                bars_color = adjust_lightness(bar_color,1.0)
            elif al.energy == "8 TeV":
                bars_color = adjust_lightness(bar_color,0.8)
            else:
                bars_color = adjust_lightness(bar_color,0.6)           
            self.bars_color.append(bars_color)
            self.bar_color = adjust_lightness(bar_color,0.8)

            
            index += 1
        self.nbars = index
        self.xmax = self.xmax*10.0
        if self.ratio: self.xmax = 10.0
        #
        # bars are stacked: subtract lower limits
        #
        for i in range(self.nbars):
            self.bar_vdiffs.append(self.bar_vhighs[i]-self.bar_vlows[i])
            self.bar_vtheorydiffs.append(self.bar_vtheoryhighs[i]-self.bar_vtheorylows[i])
            self.bar_vstatdiffs.append(self.bar_vstathighs[i]-self.bar_vstatlows[i])


            
            
    def add_plot(self,fig,gs,cadi,xlim,logx):
        ax = fig.add_subplot(gs)
        self.ax = ax
        transFD = transforms.blended_transform_factory(fig.transFigure, ax.transData)
        
        # define stacked bars (lower and upper limit)
        barsLow = ax.barh(self.bar_positions,self.bar_vstatlows,align='center',height=0.75,color='white',tick_label="")
        #barsLow = ax.barh(self.bar_positions,self.bar_labellows,align='edge',height=0.75,color='white',tick_label=self.bar_labels)
        barsHigh = ax.barh(self.bar_positions,self.bar_vstatdiffs,align='center',height=0.85,color=self.bars_color,
                           left=self.bar_vstatlows,tick_label="")
        assert len(ax.get_yticklabels())==len(barsHigh)
        bar_height_points = bar_height*barsHigh[0].get_height()*72


        #barsLow = ax.barh(self.bar_positions,self.bar_vtheorylows,align='center',height=0.35,color='white',tick_label="")
        barsHigh = ax.barh(self.bar_positions,self.bar_vdiffs,align='center',height=0.50,color=self.bars_color,left=self.bar_vlows,tick_label="")

        barsHigh = ax.barh(self.bar_positions,self.bar_vtheorydiffs,align='center',height=0.25,color='black',
                           left=self.bar_vtheorylows,tick_label="")
         # absolute bar height(inch) * relative height * 72 points/inch)


        
        
        for i in range(len(barsHigh)):
            ax.get_yticklabels()[i].set_size(0.6*bar_height_points)
            ax.get_yticklabels()[i].set_color(yaxis_label_color)

        if not (self.ratio) : ax.set_xlabel(r"$\sigma$ [fb]",weight='bold',size=0.85*bar_height_points)
        if (self.ratio) : ax.set_xlabel(r"$\sigma_{meas}/\sigma_{th}$",weight='bold',size=0.85*bar_height_points)
        
        # x-axis tick marks inside the plot; no y-axis tick marks
        ax.tick_params(axis='x',which='both',length=0.,labelsize=0.)
        ax.tick_params(axis='y',length=0.)
        # leave 5% space on x-axis
        ax.set_xlim(xlim)
        ax.set_ylim([0,self.nbars+1])
        if logx: plt.xscale('log')
        ax.xaxis.set_major_formatter(ScalarFormatter())
        
        box = patches.Rectangle((0.01,0.2),0.028,(self.nbars+1)-0.4,
                                fill=True, transform=transFD, clip_on=False, color=self.bar_color)
        ax.add_patch(box)

        
        if not self.name_tex == None:
#            tx = ax.text(0.03, 0.5*(self.nbars+1), r"\textbf{"+self.name_tex+"}",
#                         horizontalalignment='center', verticalalignment='center',
#                         transform=transFD, rotation='vertical', size=self.name_size*0.85*bar_height_points)
            tx = ax.text(0.025, 0.5*(self.nbars+1), self.name_tex, usetex=False,
                         horizontalalignment='center', verticalalignment='center', weight='bold',
                         transform=transFD, rotation='vertical', size=self.name_size*0.6*bar_height_points)
        
        #
        # add text to the bars. Start from bottom.
        #
        index = 0
        bar_texts = [ ]
        
        for al in self.ABs_list[::-1]:
            # use CADI or arXiv numbers, with journal ref
            if cadi:
                Pas_Label = al.cadi
            else:
                Pas_Label = al.paper
                Pas_Link  = al.pub
            #
            # analysis description and references
            #
            # 1% from right border; centered with bar in y
            gap = ax.transData.inverted().transform_point(ax.transAxes.transform_point((0.003,0)))
            
            #xloc = gap[0] + self.bar_vlows[index]
            xloc = gap[0] + self.bar_vhighs[index]
            xloclim = self.bar_vhighs[index]
            if logx:
                xloclim = xloclim / exp(gap[0])
            else:
                xloclim -= gap[0]
            
            yloc = barsHigh[index].get_y() + barsHigh[index].get_height()/2.

            xloclumi = ax.transData.inverted().transform_point(gap + ax.transData.transform_point((xlim[1],0)))[0]
            
            # there is some broken logic that ends up with this not being assinged sometimes.
            # bad hack to compensate for shifted text in case of subscript
            if al.paper==None:
                bar_string = al.cadi
                arxiv_url = al.pub
            else:
#                if ( '$' in al.finalstate ) and ( '_' in al.finalstate ):
#                    yloc -= 0.1*barsHigh[index].get_height()
#                bar_string = r"$\bf{"+al.finalstate+":}$ "+Pas_Label
                bar_string = Pas_Label
                #bar_string = Pas_Label + r" ($\bf{"+al.finalstate+"}$)" + r" ($\bf{"+al.lumi+"}$)"
                if cadi:
                    arxiv_url = ''
                else:
                    arxiv_url = r'https://arxiv.org/abs/' + Pas_Link
                    if verbose: print (arxiv_url)

            barreflocation =0.11
            if self.ratio: barreflocation = 0.125
            bar_text = ax.text(barreflocation, yloc, bar_string, horizontalalignment='left',
                       verticalalignment='center', color=desc_text_color,
                       transform = transFD, clip_on=False, size=0.7*bar_height_points,
                       url=arxiv_url, 
                       bbox = dict(color='w', alpha=0.01, url=arxiv_url))
            bar_texts.append(bar_text)

            bar_header = ax.text(0.048, yloc, r""+al.header+"", horizontalalignment='left',
                                verticalalignment='center', color='black',
                                transform = transFD,
                                clip_on=False, size=0.7*bar_height_points, url=arxiv_url, 
                                bbox = dict(color='w', alpha=0.01, url=arxiv_url))
            bar_texts.append(bar_header)

            # 0.09 for full plot 0.08 for jets plot
            energylocation = 0.08;
            if al.energy == "7 TeV":
                bar_energy = ax.text(energylocation, yloc, r""+al.energy+"", horizontalalignment='left',
                                verticalalignment='center', color='black',
                                transform = transFD,
                                clip_on=False, size=0.7*bar_height_points)
            elif al.energy == "8 TeV":
                bar_energy = ax.text(energylocation, yloc, r""+al.energy+"", horizontalalignment='left',
                                verticalalignment='center', color='blue',
                                transform = transFD,
                                clip_on=False, size=0.7*bar_height_points)
            else:
                bar_energy = ax.text(energylocation, yloc, r""+al.energy+"", horizontalalignment='left',
                                verticalalignment='center', color='red',
                                transform = transFD,
                                clip_on=False, size=0.7*bar_height_points)
 
            bar_texts.append(bar_energy)

            if self.ratio:
                if self.bar_vlows[index]>0.:
                    if (al.eSystp > 0) :
                        limstring = r"$\sigma_{meas}$("+al.header+") = "+"$%0.2g^{+%0.2g}_{-%0.2g}(stat)^{+%0.2g}_{-%0.2g} (sys)$ fb" % (al.crossSection,al.eStatp,al.eStatm,al.eSystp,al.eSystm)
                    else :
                        limstring = r"$\sigma_{meas}$("+al.header+") = "+"$%0.2g^{+%0.2g}_{-%0.2g}(tot)$ fb" % (al.crossSection,al.eStatp,al.eStatm)
                        
                else:
                    limstring = r"$\sigma_{meas}$("+al.header+") < "+"%0.2g fb" % (al.crossSection)
                if verbose : print(limstring)
                bar_limit = ax.text(0.20, yloc, limstring, horizontalalignment='left',
                                    verticalalignment='center', color='black',
                                    transform = transFD, clip_on=False, size=0.7*bar_height_points)
                bar_texts.append(bar_limit)
                
                theorystring = r"$\sigma_{th}$("+al.header+") = "+"$%0.2g^{+%0.2g}_{-%0.2g}$ fb" % (al.theoryCrossSection,al.eTheoryp,al.eTheorym)    
                bar_theory = ax.text(0.38, yloc, theorystring, horizontalalignment='left',
                                    verticalalignment='center', color='black',
                                    transform = transFD, clip_on=False, size=0.7*bar_height_points)
                bar_texts.append(bar_theory)
         
                if self.bar_vlows[index]>0.:
                    if (al.eSystp > 0) :
                        ratiostring = r"$\sigma_{meas}/\sigma_{th}$("+al.header+") = "+"$%0.1f^{+%0.1g}_{-%0.1g}(stat)^{+%0.1g}_{-%0.1g} (sys)$" % (self.bar_crossSection[index],al.eRStatp,al.eRStatm,al.eRSystp,al.eRSystm)
                    else :
                       ratiostring = r"$\sigma_{meas}/\sigma_{th}$("+al.header+") = "+"$%0.1f^{+%0.1g}_{-%0.1g}(tot)$" % (self.bar_crossSection[index],al.eRStatp,al.eRStatm)                         
                else:
                    ratiostring = r"$\sigma_{meas}/\sigma_{th}$("+al.header+") < "+"%0.1f" % (self.bar_vhighs[index])
                if verbose : print(limstring)
                bar_ratio = ax.text(0.50, yloc, ratiostring, horizontalalignment='left',
                                    verticalalignment='center', color='black',
                                    transform = transFD, clip_on=False, size=0.7*bar_height_points)
                bar_texts.append(bar_ratio)


                
            #limstring = "%g" % (self.bar_vhighs[index])
            xloclimfactor = 1.5
            if not self.ratio:
                if self.bar_vlows[index]>0.:
                    # limstring = "%0.2g$-$%0.2g " % (self.bar_vlows[index],self.bar_vhighs[index])
                    # define to crossSection instead
                    limstring = r"$\sigma$("+al.header+") = "+"%0.2g fb" % (self.bar_crossSection[index])
                    xloclimfactor = 1.5
                else:
                    limstring = r"$\sigma$("+al.header+") < "+"%0.2g fb" % (self.bar_vhighs[index])

                if self.bar_vtheoryhighs[index]>self.bar_vhighs[index]: xloclimfactor = xloclimfactor*self.bar_vtheoryhighs[index]/self.bar_vhighs[index]

                bar_limit = ax.text(xloclim*xloclimfactor, yloc, limstring, horizontalalignment='left',
                                    verticalalignment='center', color=desc_text_color,
                                    clip_on=True, size=0.7*bar_height_points, url=arxiv_url, 
                                   bbox = dict(color='w', alpha=0.01, url=arxiv_url))
                bar_texts.append(bar_limit)

            lumistring = "%.0f fb$^{-1}$" % (float(al.lumi))
            if float(al.lumi)<1.0:
                lumistring = "%.0f pb$^{-1}$" % (float(al.lumi)*1000.0)
            bar_lumi = ax.text(xloclumi, yloc, r" "+lumistring, horizontalalignment='left',
                                verticalalignment='center', color='black',
                                clip_on=False, size=0.9*bar_height_points)
            
                #annot = ax.annotate("test", xy=(xloclim*xloclimfactor, yloc), xytext=(-2, 2), textcoords="offset points",
            #                    bbox=dict(boxstyle="round", fc="w"),
            #                    arrowprops=dict(arrowstyle="->"))
            #annot.set_visible(False)
 

            
            index += 1
        return ax

