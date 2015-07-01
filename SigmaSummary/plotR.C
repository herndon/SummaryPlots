void plotR()
{
  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("SigmaR.C++");
  setTDRStyle();  
  version=5; // version=1 --> simplified plot
  TString str("SigmaR_v"); str+=version;
  SigmaR()->Print(str+".pdf");
  SigmaR()->Print(str+".png");
  return;
}

