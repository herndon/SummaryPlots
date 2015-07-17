void plot()
{
  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("Sigma.C++");
  setTDRStyle();  
  version=6;
  TString str("SigmaNew_v"); str+=version;
  Sigma()->Print(str+".pdf");
  Sigma()->Print(str+".png");
  return;
}

