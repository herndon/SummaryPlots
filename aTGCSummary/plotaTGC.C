void plotaTGC()
{
  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("aTGC.C++");
  setTDRStyle();  
  version=0; // version=1 --> simplified plot
  TString str("aTGC_v"); str+=version;
  aTGC()->Print(str+".pdf");
  aTGC()->Print(str+".png");
  return;
}

