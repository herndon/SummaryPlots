void plot()
{
  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("Sigma.C++");
  setTDRStyle();  
  version=0;
  TString str("SigmaNew_v"); str+=version;
  Sigma()->Print(str+".png");
  //Sigma()->Print(str+".eps");
  Sigma()->Print(str+".pdf");
  return;
}

