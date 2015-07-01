void plot()
{
  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("Sigma.C++");
  setTDRStyle();  
  version=1;
  TString str("Sigma_v"); str+=version;
  Sigma()->Print(str+".pdf");
  Sigma()->Print(str+".png");
  return;
}

