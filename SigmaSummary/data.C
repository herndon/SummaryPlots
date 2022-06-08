// standard versions 0 with verticle stacking of QCD results ,1 without verticle stacking, 2 QCD EWK only, 3 QCD rad only

enum { k_W=0,  k_W8, k_W13, k_W8n, k_W1jet, k_W2jet, k_W3jet, k_W4jet,  k_W1jetn, k_W1jet8n, k_W1jet13, k_W2jetn, k_W2jet8n, k_W2jet13, k_W3jetn, k_W3jet8n, k_W3jet13, k_W4jetn, k_W4jet8n, k_W4jet13, k_W5jetn, k_W5jet8n, k_W5jet13, k_W6jetn, k_W6jet8n, k_W6jet13, k_W7jet8n, k_W1cjet, k_W1cjet8, k_W1cjet13, k_W2bjet, k_W2bjet8, k_Z,  k_Z8,  k_Z13, k_Z1jet, k_Z2jet, k_Z3jet, k_Z4jet, k_Z1jetn, k_Z1jet8, k_Z1jet13, k_Z2jetn,  k_Z2jet8, k_Z2jet13, k_Z3jetn, k_Z3jet8, k_Z3jet13, k_Z4jetn,  k_Z4jet8, k_Z4jet13, k_Z5jetn, k_Z5jet8, k_Z5jet13, k_Z6jetn, k_Z6jet8, k_Z6jet13, k_Z7jet8, k_Z1cjet8, k_Z1cjet13, k_Z1bjet,k_Z1bjet8,  k_Z1bjet13, k_Z2bjet, k_Z2bjet8,  k_Z2bjet13, k_Wp, k_Wm, k_gg, k_ggnew, k_Wg, k_Wg13, k_Wg2jet13, k_Zg, k_Zg8, k_Zg2jet13, k_WV, k_WW, k_WW8, k_WW13, k_WW13fid, k_WW1jet, k_WZ, k_WZ8,  k_WZ13, k_WZ13fid,  k_WZ0jet8, k_WZ1jet8, k_WZ2jet8, k_WZ3jet8, k_ZZ, k_ZZ8,  k_ZZ13,  k_ZZ13fid, k_ZZ0jet8, k_ZZ0jet13, k_ZZ1jet8,  k_ZZ1jet13, k_ZZ2jet8,  k_ZZ2jet13,  k_ZZ3jet8, k_ZZ3jet13, k_VVV13, k_WWW13, k_WWZ13,  k_WZZ13, k_ZZZ13, k_WVg, k_Wgg8,k_Wgg13, k_Zgg8, k_Zgg13, k_VBFW8, k_VBFW13, k_VBFZ, k_VBFZ8, k_VBFZ13, k_EWKWV13, k_exWW,  k_exWW8,  k_EWKWg8, k_EWKWg13, k_EWKWW13, k_SSWW8, k_SSWW13, k_EWKZg8, k_EWKZg13, k_EWKWZ13, k_EWKZZ13,   k_tt,  k_tt8, k_tt13, k_tt1jet, k_tt1jet8,  k_tt0jet13, k_tt1jet13, k_tt2jet, k_tt2jet8, k_tt2jet13, k_tt3jet, k_tt3jet8,  k_tt3jet13, k_tt4jet13, k_tt2cjet13, k_tt2bjet13, k_t, k_t8, k_t13, k_tW, k_tW8, k_tW13, k_tschan, k_tschan8, k_ttg8, k_ttg13, k_tZq8, k_tZq13, k_ttZ,  k_ttZ8, k_ttZ13,   k_tg13, k_ttW8, k_ttW13,   k_tttt8, k_tttt13,  k_HZZ,  k_H1jet, k_ggH, k_ggH8, k_ggH13, k_ggHgg13, k_VBFH, k_VBFH8, k_VBFH13, k_VH, k_VH8, k_VH13,  k_WH13, k_ZH13, k_ttH, k_ttH8, k_ttH13, k_tH13, k_HHbbtautau8, k_HHbbgg8, k_HHComb8, k_HHbbbb13,  k_HHComb13,  k_HHWWbb13,  k_HHbbtautau13,  k_HHbbgg13,  k_incj, k_incg, k_gj, k_Hgg, k_Hgg8, k_H0jet13, k_H1jet13, k_H2jet13, k_H3jet13, k_H4jet13, k_nChan };




// Notes
// 7 and 8 TeV measurements are grouped if the ChanMeasurement short name is the same for both
// To add +jets measurements under the main measurement you need to set subChan to a number greater than 1.


bool big13TeV = false;
bool use13TeV = true;
bool ratioPlot = false;
bool noHiggs = false;
bool noTop = false;

bool exportExeFormat = true;
bool lessLimits = true;
bool noJets = false;

if (version==5||version==6){
 exportExeFormat = false;
 lessLimits = false;
 noJets = false;
}

  float nPlotBins = 0;
  int nPlotChan = 0;
  vector<bool> plotChan( k_nChan, false );
  vector<int>  subChan(k_nChan, 1);
  vector<int>  energy(k_nChan, 8);
  vector<int>  chanFlag(k_nChan, 0);
  vector<string> 
    chanMeasurement( k_nChan ),
    chanResult (     k_nChan ),
    chanLumi   (     k_nChan ),
    chanEnergy (     k_nChan ),
    chanGroup  (     k_nChan ),
    chanCadi       (     k_nChan ),
    chanPreprint   (     k_nChan ),
    chanPublication(     k_nChan );
    

vector<float> 
    chanSigma( k_nChan,0 ), 
    chanEStat( k_nChan,0 ),
    chanESyst( k_nChan,0 ),
    chanETot(  k_nChan,0 ),
    chanEStatp( k_nChan,0 ),
    chanESystp( k_nChan,0 ),
    chanETotp(  k_nChan,0 ),
    chanEStatm( k_nChan,0 ),
    chanESystm( k_nChan,0 ),
    chanETotm(  k_nChan,0 ),
    chanTheo(  k_nChan,0 ),
    chanETheo( k_nChan,0 ),
    chanETheop( k_nChan,0 ),
    chanETheom( k_nChan,0 );



// Set the channel groups
  chanGroup[k_W] = "EW";
  chanGroup[k_W8] = "EW";
  chanGroup[k_W13] = "EW";
  chanGroup[k_Z13] = "EW";

  chanGroup[k_Wp] = "EW";
  chanGroup[k_Wm] = "EW";
  chanGroup[k_W1jet] = "EW";
  chanGroup[k_W2jet] = "EW";
  chanGroup[k_W3jet] = "EW";
  chanGroup[k_W4jet] = "EW";
  chanGroup[k_W1jetn] = "EW";
  chanGroup[k_W2jetn] = "EW";
  chanGroup[k_W3jetn] = "EW";
  chanGroup[k_W4jetn] = "EW";
  chanGroup[k_W5jetn] = "EW";
  chanGroup[k_W6jetn] = "EW";
  chanGroup[k_W1jet8n] = "EW";
  chanGroup[k_W2jet8n] = "EW";
  chanGroup[k_W3jet8n] = "EW";
  chanGroup[k_W4jet8n] = "EW";
  chanGroup[k_W5jet8n] = "EW";
  chanGroup[k_W6jet8n] = "EW";
  chanGroup[k_W7jet8n] = "EW";
  chanGroup[k_W1jet13] = "EW";
  chanGroup[k_W2jet13] = "EW";
  chanGroup[k_W3jet13] = "EW";
  chanGroup[k_W4jet13] = "EW";
  chanGroup[k_W5jet13] = "EW";
  chanGroup[k_W6jet13] = "EW";

  chanGroup[k_W1cjet] = "EW";
  chanGroup[k_W1cjet8] = "EW";
  chanGroup[k_W1cjet13] = "EW";

  chanGroup[k_W2bjet] = "EW";
  chanGroup[k_W2bjet8] = "EW";


  chanGroup[k_Z] = "EW";
  chanGroup[k_Z8] = "EW";
  chanGroup[k_Z1jet] = "EW";
  chanGroup[k_Z2jet] = "EW";
  chanGroup[k_Z3jet] = "EW";
  chanGroup[k_Z4jet] = "EW";


  chanGroup[k_Z1jetn] = "EW";
  chanGroup[k_Z2jetn] = "EW";
  chanGroup[k_Z3jetn] = "EW";
  chanGroup[k_Z4jetn] = "EW";
  chanGroup[k_Z5jetn] = "EW";
  chanGroup[k_Z6jetn] = "EW";
  chanGroup[k_Z1jet8] = "EW";
  chanGroup[k_Z2jet8] = "EW";
  chanGroup[k_Z3jet8] = "EW";
  chanGroup[k_Z4jet8] = "EW";
  chanGroup[k_Z5jet8] = "EW";
  chanGroup[k_Z6jet8] = "EW";
  chanGroup[k_Z1jet13] = "EW";
  chanGroup[k_Z2jet13] = "EW";
  chanGroup[k_Z3jet13] = "EW";
  chanGroup[k_Z4jet13] = "EW";
  chanGroup[k_Z5jet13] = "EW";
  chanGroup[k_Z6jet13] = "EW";
  chanGroup[k_Z7jet8] = "EW";


  chanGroup[k_Z1cjet8] = "EW";
  chanGroup[k_Z1cjet13] = "EW";
  chanGroup[k_Z1bjet] = "EW";
  chanGroup[k_Z1bjet8] = "EW";
  chanGroup[k_Z1bjet13] = "EW";
  chanGroup[k_Z2bjet] = "EW";
  chanGroup[k_Z2bjet8] = "EW";
  chanGroup[k_Z2bjet13] = "EW";



  chanGroup[k_gg]="DB";
  chanGroup[k_Wg]="DB";
  chanGroup[k_Wg13]="DB";
  chanGroup[k_Zg]="DB";
  chanGroup[k_Zg8]="DB";
  //chanGroup[k_Zg13]="";
  chanGroup[k_WV]="DB";
  chanGroup[k_WW]="DB";
  chanGroup[k_WW8]="DB";
  chanGroup[k_WW13]="DB";
  chanGroup[k_WZ]="DB";
  chanGroup[k_WZ8]="DB";
  chanGroup[k_WZ13]="DB";
  chanGroup[k_ZZ]="DB";
  chanGroup[k_ZZ8]="DB";
  chanGroup[k_ZZ13]="DB";


  chanGroup[k_Wg2jet13] = "DB";
  chanGroup[k_Zg2jet13] = "DB";
  
  chanGroup[k_WZ0jet8] = "DB";
  chanGroup[k_WZ1jet8] = "DB";
  chanGroup[k_WZ2jet8] = "DB";
  chanGroup[k_WZ3jet8] = "DB";

  
  chanGroup[k_ZZ0jet13] = "DB";
  chanGroup[k_ZZ1jet13] = "DB";
  chanGroup[k_ZZ2jet13] = "DB";
  chanGroup[k_ZZ3jet13] = "DB";

  chanGroup[k_ZZ0jet8] = "DB";
  chanGroup[k_ZZ1jet8] = "DB";
  chanGroup[k_ZZ2jet8] = "DB";
  chanGroup[k_ZZ3jet8] = "DB";




  chanGroup[k_WVg]="TB";
  chanGroup[k_VVV13]="TB";
  chanGroup[k_WWW13]="TB";
  chanGroup[k_WWZ13]="TB";
  chanGroup[k_WZZ13]="TB";
  chanGroup[k_ZZZ13]="TB";
  chanGroup[k_Wgg8]="TB";
  chanGroup[k_Zgg8]="TB";
  chanGroup[k_Wgg13]="TB";
  chanGroup[k_Zgg13]="TB";

  chanGroup[k_exWW]="VBS";
  chanGroup[k_exWW8]="VBS";

  chanGroup[k_EWKWV13]="VBS";
  chanGroup[k_EWKWW13]="VBS";
  chanGroup[k_SSWW8]="VBS";
  chanGroup[k_SSWW13]="VBS";
  chanGroup[k_EWKWg8]="VBS";
  chanGroup[k_EWKWg13]="VBS";
  chanGroup[k_EWKZg8]="VBS";
  chanGroup[k_EWKZg13]="VBS";
  chanGroup[k_EWKWZ13]="VBS";
  chanGroup[k_EWKZZ13]="VBS";

  chanGroup[k_VBFZ]="VBS";
  chanGroup[k_VBFZ8]="VBS";
  chanGroup[k_VBFZ13]="VBS";
  chanGroup[k_VBFW8]="VBS";
  chanGroup[k_VBFW13]="VBS";

  chanGroup[k_tt]="TOP";
  chanGroup[k_tt8]="TOP";
  chanGroup[k_tt13]="TOP";
  chanGroup[k_tt1jet] = "TOP";
  chanGroup[k_tt2jet] = "TOP";
  chanGroup[k_tt3jet] = "TOP";
  chanGroup[k_tt1jet8] = "TOP";
  chanGroup[k_tt2jet8] = "TOP";
  chanGroup[k_tt3jet8] = "TOP";
  chanGroup[k_tt0jet13] = "TOP";
  chanGroup[k_tt1jet13] = "TOP";
  chanGroup[k_tt2jet13] = "TOP";
  chanGroup[k_tt3jet13] = "TOP";
  chanGroup[k_tt4jet13] = "TOP";
  chanGroup[k_tt2cjet13] = "TOP";
  chanGroup[k_tt2bjet13] = "TOP";
 

  chanGroup[k_t]="TOP";
  chanGroup[k_t8]="TOP";
  chanGroup[k_t13]="TOP";
  chanGroup[k_tschan]="TOP";
  chanGroup[k_tschan8]="TOP";
  chanGroup[k_tW]="TOP";
  chanGroup[k_tW8]="TOP";
  chanGroup[k_tW13]="TOP";
  chanGroup[k_ttg8]="TOP";
  chanGroup[k_ttg13]="TOP";
  chanGroup[k_ttW8]="TOP";
  chanGroup[k_ttZ]="TOP";
  chanGroup[k_ttZ8]="TOP";
  chanGroup[k_ttZ13]="TOP";
  chanGroup[k_ttW13]="TOP";
  chanGroup[k_tg13]="TOP";
  chanGroup[k_ttg8]="TOP";
  chanGroup[k_tZq8]="TOP";
  chanGroup[k_tZq13]="TOP";
  chanGroup[k_tttt8]="TOP";
  chanGroup[k_tttt13]="TOP";

  chanGroup[k_ggH]="HIG";
  chanGroup[k_VBFH]="HIG";
  chanGroup[k_VH]="HIG";
  chanGroup[k_ttH]="HIG";
  chanGroup[k_ggH8]="HIG";
  chanGroup[k_VBFH8]="HIG";
  chanGroup[k_VH8]="HIG";
  chanGroup[k_VH13]="HIG";
  chanGroup[k_WH13]="HIG";
  chanGroup[k_ZH13]="HIG";
  chanGroup[k_ttH8]="HIG";
  chanGroup[k_ttH13]="HIG";
  chanGroup[k_tH13]="HIG";
  chanGroup[k_HHComb8]="HIG";
  //chanGroup[k_HHbbgg13]="";
  //chanGroup[k_HHComb13]="";
  //chanGroup[k_HHbbbb13]="HIG";
  chanGroup[k_HHbbtautau13]="HIG";
  chanGroup[k_ggHgg13]="HIG";
  chanGroup[k_ggH13]="HIG";
  chanGroup[k_VBFH13]="HIG";
  chanGroup[k_HZZ]="HIG";

  chanGroup[k_H0jet13]="HIG";
  chanGroup[k_H1jet13]="HIG";
  chanGroup[k_H2jet13]="HIG";
  chanGroup[k_H3jet13]="HIG";
  chanGroup[k_H4jet13]="HIG";


// Set the channel Energies
  chanEnergy[k_W] = "7 TeV";
  chanEnergy[k_W8] = "8 TeV";
  chanEnergy[k_W13] = "13 TeV";
  chanEnergy[k_Z13] = "13 TeV";

  chanEnergy[k_Wp] = "7 TeV";
  chanEnergy[k_Wm] = "7 TeV";
  chanEnergy[k_W1jet] = "7 TeV";
  chanEnergy[k_W2jet] = "7 TeV";
  chanEnergy[k_W3jet] = "7 TeV";
  chanEnergy[k_W4jet] = "7 TeV";

  chanEnergy[k_Z] = "7 TeV";
  chanEnergy[k_Z8] = "8 TeV";
  chanEnergy[k_Z1jet] = "7 TeV";
  chanEnergy[k_Z2jet] = "7 TeV";
  chanEnergy[k_Z3jet] = "7 TeV";
  chanEnergy[k_Z4jet] = "7 TeV";

  chanEnergy[k_gg] = "7 TeV";
  chanEnergy[k_Wg] = "7 TeV";
  chanEnergy[k_Wg13] = "13 TeV";
  chanEnergy[k_Zg] = "7 TeV";
  chanEnergy[k_Zg8] = "8 TeV";
  //chanEnergy[k_Zg13]="";
  chanEnergy[k_WV] = "7 TeV";
  chanEnergy[k_WW] = "7 TeV";
  chanEnergy[k_WW8] = "8 TeV";
  chanEnergy[k_WW13] = "13 TeV";
  chanEnergy[k_WZ] = "7 TeV";
  chanEnergy[k_WZ8] = "8 TeV";
  chanEnergy[k_WZ13] = "13 TeV";
  chanEnergy[k_ZZ] = "7 TeV";
  chanEnergy[k_ZZ8] = "8 TeV";
  chanEnergy[k_ZZ13] = "13 TeV";

  chanEnergy[k_WVg] = "8 TeV";
  chanEnergy[k_VVV13] = "13 TeV";
  chanEnergy[k_WWW13] = "13 TeV";
  chanEnergy[k_WWZ13] = "13 TeV";
  chanEnergy[k_WZZ13] = "13 TeV";
  chanEnergy[k_ZZZ13] = "13 TeV";
  chanEnergy[k_Wgg8] = "8 TeV";
  chanEnergy[k_Zgg8] = "8 TeV";
  chanEnergy[k_Wgg13] = "13 TeV";
  chanEnergy[k_Zgg13] = "13 TeV";

  chanEnergy[k_exWW] = "7 TeV";
  chanEnergy[k_exWW8] = "8 TeV";

  chanEnergy[k_EWKWV13] = "13 TeV";
  chanEnergy[k_EWKWW13] = "13 TeV";
  chanEnergy[k_SSWW8] = "8 TeV";
  chanEnergy[k_SSWW13] = "13 TeV";
  chanEnergy[k_EWKWg8] = "8 TeV";
  chanEnergy[k_EWKWg13] = "13 TeV";
  chanEnergy[k_EWKZg8] = "8 TeV";
  chanEnergy[k_EWKZg13] = "13 TeV";
  chanEnergy[k_EWKWZ13] = "13 TeV";
  chanEnergy[k_EWKZZ13] = "13 TeV";

  chanEnergy[k_VBFZ] = "7 TeV";
  chanEnergy[k_VBFZ8] = "8 TeV";
  chanEnergy[k_VBFZ13] = "13 TeV";
  chanEnergy[k_VBFW8] = "8 TeV";
  chanEnergy[k_VBFW13] = "13 TeV";

  chanEnergy[k_tt] = "7 TeV";
  chanEnergy[k_tt8] = "8 TeV";
  chanEnergy[k_tt13] = "13 TeV";
  chanEnergy[k_tt1jet] = "7 TeV";
  chanEnergy[k_tt2jet] = "7 TeV";
  chanEnergy[k_tt3jet] = "7 TeV";
  chanEnergy[k_tt1jet8] = "8 TeV";
  chanEnergy[k_tt2jet8] = "8 TeV";
  chanEnergy[k_tt3jet8] = "8 TeV";
  chanEnergy[k_tt0jet13] = "13 TeV";
  chanEnergy[k_tt1jet13] = "13 TeV";
  chanEnergy[k_tt2jet13] = "13 TeV";
  chanEnergy[k_tt3jet13] = "13 TeV";
  chanEnergy[k_tt4jet13] = "13 TeV";
   
  chanEnergy[k_t] = "7 TeV";
  chanEnergy[k_t8] = "8 TeV";
  chanEnergy[k_t13] = "13 TeV";
  chanEnergy[k_tschan] = "7 TeV";
  chanEnergy[k_tschan8] = "8 TeV";
  chanEnergy[k_tW] = "7 TeV";
  chanEnergy[k_tW8] = "8 TeV";
  chanEnergy[k_tW13] = "13 TeV";
  chanEnergy[k_ttg8] = "8 TeV";
  chanEnergy[k_ttg13] = "13 TeV";
  chanEnergy[k_ttW8] = "8 TeV";
  chanEnergy[k_ttZ] = "7 TeV";
  chanEnergy[k_ttZ8] = "8 TeV";
  chanEnergy[k_ttZ13] = "13 TeV";
  chanEnergy[k_ttW13] = "13 TeV";
  chanEnergy[k_tg13] = "13 TeV";
  chanEnergy[k_ttg8] = "8 TeV";
  chanEnergy[k_tZq8] = "8 TeV";
  chanEnergy[k_tZq13] = "13 TeV";
  chanEnergy[k_tttt8] = "8 TeV";
  chanEnergy[k_tttt13] = "13 TeV";

  chanEnergy[k_ggH] = "7 TeV";
  chanEnergy[k_VBFH] = "7 TeV";
  chanEnergy[k_VH] = "7 TeV";
  chanEnergy[k_ttH] = "7 TeV";
  chanEnergy[k_ggH8] = "8 TeV";
  chanEnergy[k_VBFH8] = "8 TeV";
  chanEnergy[k_VH8] = "8 TeV";
  chanEnergy[k_VH13] = "13 TeV";
  chanEnergy[k_WH13] = "13 TeV";
  chanEnergy[k_ZH13] = "13 TeV";
  chanEnergy[k_ttH8] = "8 TeV";
  chanEnergy[k_ttH13] = "13 TeV";
  chanEnergy[k_tH13] = "13 TeV";
  chanEnergy[k_HHComb8] = "8 TeV";
  //chanEnergy[k_HHbbgg13] ="";
  //chanEnergy[k_HHComb13] ="";
  //chanEnergy[k_HHbbbb13] = "13 TeV";
  chanEnergy[k_HHbbtautau13] = "13 TeV";
  chanEnergy[k_ggHgg13] = "13 TeV";
  chanEnergy[k_ggH13] = "13 TeV";
  chanEnergy[k_VBFH13] = "13 TeV";
  chanEnergy[k_HZZ] = "7 TeV";

// with jets plots
 chanEnergy[k_W1jetn] = "7 TeV";
  chanEnergy[k_W2jetn] = "7 TeV";
  chanEnergy[k_W3jetn] = "7 TeV";
  chanEnergy[k_W4jetn] = "7 TeV";
  chanEnergy[k_W5jetn] = "7 TeV";
  chanEnergy[k_W6jetn] = "7 TeV";
  chanEnergy[k_W1jet8n] = "8 TeV";
  chanEnergy[k_W2jet8n] = "8 TeV";
  chanEnergy[k_W3jet8n] = "8 TeV";
  chanEnergy[k_W4jet8n] = "8 TeV";
  chanEnergy[k_W5jet8n] = "8 TeV";
  chanEnergy[k_W6jet8n] = "8 TeV";
  chanEnergy[k_W7jet8n] = "8 TeV";
  chanEnergy[k_W1jet13] = "13 TeV";
  chanEnergy[k_W2jet13] = "13 TeV";
  chanEnergy[k_W3jet13] = "13 TeV";
  chanEnergy[k_W4jet13] = "13 TeV";
  chanEnergy[k_W5jet13] = "13 TeV";
  chanEnergy[k_W6jet13] = "13 TeV";

  chanEnergy[k_W1cjet] = "7 TeV";
  chanEnergy[k_W1cjet8] = "8 TeV";
  chanEnergy[k_W1cjet13] = "13 TeV";

  chanEnergy[k_W2bjet] = "7 TeV";
  chanEnergy[k_W2bjet8] = "8 TeV";

  chanEnergy[k_Z1jetn] = "7 TeV";
  chanEnergy[k_Z2jetn] = "7 TeV";
  chanEnergy[k_Z3jetn] = "7 TeV";
  chanEnergy[k_Z4jetn] = "7 TeV";
  chanEnergy[k_Z5jetn] = "7 TeV";
  chanEnergy[k_Z6jetn] = "7 TeV";
  chanEnergy[k_Z1jet8] = "8 TeV";
  chanEnergy[k_Z2jet8] = "8 TeV";
  chanEnergy[k_Z3jet8] = "8 TeV";
  chanEnergy[k_Z4jet8] = "8 TeV";
  chanEnergy[k_Z5jet8] = "8 TeV";
  chanEnergy[k_Z6jet8] = "8 TeV";
  chanEnergy[k_Z1jet13] = "13 TeV";
  chanEnergy[k_Z2jet13] = "13 TeV";
  chanEnergy[k_Z3jet13] = "13 TeV";
  chanEnergy[k_Z4jet13] = "13 TeV";
  chanEnergy[k_Z5jet13] = "13 TeV";
  chanEnergy[k_Z6jet13] = "13 TeV";
  chanEnergy[k_Z7jet8] = "13 TeV";

  chanEnergy[k_Z1cjet8] = "8 TeV";
  chanEnergy[k_Z1cjet13] = "13 TeV";
  chanEnergy[k_Z1bjet] = "7 TeV";
  chanEnergy[k_Z1bjet8] = "8 TeV";
  chanEnergy[k_Z1bjet13] = "13 TeV";
  chanEnergy[k_Z2bjet] = "7 TeV";
  chanEnergy[k_Z2bjet8] = "8 TeV";
  chanEnergy[k_Z2bjet13] = "13 TeV";

  chanEnergy[k_Wg2jet13] = "13 TeV";
  chanEnergy[k_Zg2jet13] = "13 TeV";
  
  chanEnergy[k_WZ0jet8] = "8 TeV";
  chanEnergy[k_WZ1jet8] = "8 TeV";
  chanEnergy[k_WZ2jet8] = "8 TeV";
  chanEnergy[k_WZ3jet8] = "8 TeV";

  chanEnergy[k_ZZ0jet13] = "13 TeV";
  chanEnergy[k_ZZ1jet13] = "13 TeV";
  chanEnergy[k_ZZ2jet13] = "13 TeV";
  chanEnergy[k_ZZ3jet13] = "13 TeV";

  chanEnergy[k_ZZ0jet8] = "8 TeV";
  chanEnergy[k_ZZ1jet8] = "8 TeV";
  chanEnergy[k_ZZ2jet8] = "8 TeV";
  chanEnergy[k_ZZ3jet8] = "8 TeV";

  chanEnergy[k_tt1jet] = "7 TeV";
  chanEnergy[k_tt2jet] = "7 TeV";
  chanEnergy[k_tt3jet] = "7 TeV";
  chanEnergy[k_tt1jet8] = "8 TeV";
  chanEnergy[k_tt2jet8] = "8 TeV";
  chanEnergy[k_tt3jet8] = "8 TeV";
  chanEnergy[k_tt0jet13] = "13 TeV";
  chanEnergy[k_tt1jet13] = "13 TeV";
  chanEnergy[k_tt2jet13] = "13 TeV";
  chanEnergy[k_tt3jet13] = "13 TeV";
  chanEnergy[k_tt4jet13] = "13 TeV";

  chanEnergy[k_tt2cjet13] = "13 TeV";
  chanEnergy[k_tt2bjet13] = "13 TeV";

  chanEnergy[k_H0jet13]="13 TeV";
  chanEnergy[k_H1jet13]="13 TeV";
  chanEnergy[k_H2jet13]="13 TeV";
  chanEnergy[k_H3jet13]="13 TeV";
  chanEnergy[k_H4jet13]="13 TeV";




if (version==0||version==1||exportExeFormat) {

  plotChan[k_W] = true;
  plotChan[k_W8] = true;
  if (use13TeV) plotChan[k_W13] = true;
  if (use13TeV) plotChan[k_Z13] = true;

  plotChan[k_Wp] = false;
  plotChan[k_Wm] = false;
  if (!noJets) plotChan[k_W1jet] = true;
  if (!noJets) plotChan[k_W2jet] = true;
  if (!noJets) plotChan[k_W3jet] = true;
  if (!noJets) plotChan[k_W4jet] = true;

  plotChan[k_Z] = true;
  plotChan[k_Z8] = true;
  if (!noJets) plotChan[k_Z1jet] = true;
  if (!noJets) plotChan[k_Z2jet] = true;
  if (!noJets) plotChan[k_Z3jet] = true;
  if (!noJets) plotChan[k_Z4jet] = true;



  plotChan[k_gg]=false;
  plotChan[k_Wg]=true;
  plotChan[k_Wg13]=true;
  plotChan[k_Zg]=true;
  plotChan[k_Zg8]=true;
  //plotChan[k_Zg13]=true;
  plotChan[k_WV]=false;
  plotChan[k_WW]=true;
  plotChan[k_WW8]=true;
  plotChan[k_WW13]=true;
  plotChan[k_WZ]=true;
  plotChan[k_WZ8]=true;
  if (use13TeV) plotChan[k_WZ13]=true;
  plotChan[k_ZZ]=true;
  plotChan[k_ZZ8]=true;
  if (use13TeV) plotChan[k_ZZ13]=true;

  plotChan[k_WVg]=true;
  plotChan[k_VVV13]=true;
  plotChan[k_WWW13]=true;
  plotChan[k_WWZ13]=true;
  plotChan[k_WZZ13]=true;
  plotChan[k_ZZZ13]=true;
  plotChan[k_Wgg8]=true;
  plotChan[k_Zgg8]=true;
  plotChan[k_Wgg13]=true;
  plotChan[k_Zgg13]=true;

  if (!lessLimits) plotChan[k_exWW]=true;
  plotChan[k_exWW8]=true;

  plotChan[k_EWKWV13]=true;
  plotChan[k_EWKWW13]=true;
  plotChan[k_SSWW8]=true;
  plotChan[k_SSWW13]=true;
  plotChan[k_EWKWg8]=true;
  plotChan[k_EWKWg13]=true;
  plotChan[k_EWKZg8]=true;
  plotChan[k_EWKZg13]=true;
  plotChan[k_EWKWZ13]=true;
  plotChan[k_EWKZZ13]=true;

  


  plotChan[k_VBFZ]=true;
  plotChan[k_VBFZ8]=true;
  plotChan[k_VBFZ13]=true;
  plotChan[k_VBFW8]=true;
  plotChan[k_VBFW13]=true;

  if (!noTop){  
  plotChan[k_tt]=true;
  plotChan[k_tt8]=true;
  if (use13TeV) plotChan[k_tt13]=true;
  // Removed 7,8 TeV results, no publically avilable numbers
  //if (!noJets) plotChan[k_tt1jet] = true;
  //if (!noJets) plotChan[k_tt2jet] = true;
  //if (!noJets) plotChan[k_tt3jet] = true;
  //if (!noJets) plotChan[k_tt1jet8] = true;
  //if (!noJets) plotChan[k_tt2jet8] = true;
  //if (!noJets) plotChan[k_tt3jet8] = true;
  if (!noJets) plotChan[k_tt0jet13] = true;
  if (!noJets) plotChan[k_tt1jet13] = true;
  if (!noJets) plotChan[k_tt2jet13] = true;
  if (!noJets) plotChan[k_tt3jet13] = true;
  if (!noJets) plotChan[k_tt4jet13] = true;
  
  plotChan[k_t]=true;
  plotChan[k_t8]=true;
  if (use13TeV) plotChan[k_t13]=true;
  if (!lessLimits) plotChan[k_tschan]=true;
  plotChan[k_tschan8]=true;
  plotChan[k_tW]=true;
  plotChan[k_tW8]=true;
  if (use13TeV) plotChan[k_tW13]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_ttg13]=true;
  plotChan[k_ttW8]=true;
  plotChan[k_ttZ]=true;
  plotChan[k_ttZ8]=true;
  if (use13TeV)  plotChan[k_ttZ13]=true;
  if (use13TeV)  plotChan[k_ttW13]=true;
  if (use13TeV)  plotChan[k_tg13]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_tZq8]=true;
  if (use13TeV) plotChan[k_tZq13]=true;
  if (!lessLimits) plotChan[k_tttt8]=true;
  if (use13TeV)  plotChan[k_tttt13]=true;
  }

  if (!noHiggs){
  plotChan[k_ggH]=true;
  plotChan[k_VBFH]=true;
  if (!lessLimits) plotChan[k_VH]=true;
  if (!lessLimits) plotChan[k_ttH]=true;
  plotChan[k_ggH8]=true;
  plotChan[k_VBFH8]=true;
  plotChan[k_VH8]=true;
  if (!lessLimits) plotChan[k_VH13]=true;
  plotChan[k_WH13]=true;
  plotChan[k_ZH13]=true;
  plotChan[k_ttH8]=true;
  plotChan[k_ttH13]=true;
  plotChan[k_tH13]=true;
  if (!lessLimits) plotChan[k_HHComb8]=true;
  //plotChan[k_HHbbgg13]=true;
  //plotChan[k_HHComb13]=true;
  //plotChan[k_HHbbbb13]=true;
  plotChan[k_HHbbtautau13]=true;

  
  plotChan[k_ggHgg13]=false;
  plotChan[k_ggH13]=true;

  plotChan[k_VBFH13]=true;

  
  plotChan[k_HZZ]=false;
  }

  
  chanFlag[k_W] += 1;
  chanFlag[k_W8] += 1;
  if (use13TeV) chanFlag[k_W13] += 1;
  if (use13TeV) chanFlag[k_Z13] += 1;

  chanFlag[k_Wp] += 0;
  chanFlag[k_Wm] += 0;
  if (!noJets) chanFlag[k_W1jet] += 1;
  if (!noJets) chanFlag[k_W2jet] += 1;
  if (!noJets) chanFlag[k_W3jet] += 1;
  if (!noJets) chanFlag[k_W4jet] += 1;

  chanFlag[k_Z] += 1;
  chanFlag[k_Z8] += 1;
  if (!noJets) chanFlag[k_Z1jet] += 1;
  if (!noJets) chanFlag[k_Z2jet] += 1;
  if (!noJets) chanFlag[k_Z3jet] += 1;
  if (!noJets) chanFlag[k_Z4jet] += 1;



  chanFlag[k_gg] += 0;
  chanFlag[k_Wg] += 1;
  chanFlag[k_Wg13] += 1;
  chanFlag[k_Zg] += 1;
  chanFlag[k_Zg8] += 1;
  //chanFlag[k_Zg13] += 1;
  chanFlag[k_WV] += 0;
  chanFlag[k_WW] += 1;
  chanFlag[k_WW8] += 1;
  chanFlag[k_WW13] += 1;
  chanFlag[k_WZ] += 1;
  chanFlag[k_WZ8] += 1;
  if (use13TeV) chanFlag[k_WZ13] += 1;
  chanFlag[k_ZZ] += 1;
  chanFlag[k_ZZ8] += 1;
  if (use13TeV) chanFlag[k_ZZ13] += 1;

  chanFlag[k_WVg] += 1;
  chanFlag[k_VVV13] += 1;
  chanFlag[k_WWW13] += 1;
  chanFlag[k_WWZ13] += 1;
  chanFlag[k_WZZ13] += 1;
  chanFlag[k_ZZZ13] += 1;
  chanFlag[k_Wgg8] += 1;
  chanFlag[k_Zgg8] += 1;
  chanFlag[k_Wgg13] += 1;
  chanFlag[k_Zgg13] += 1;

  if (!lessLimits) chanFlag[k_exWW] += 1;
  chanFlag[k_exWW8] += 1;

  chanFlag[k_EWKWV13] += 1;
  chanFlag[k_EWKWW13] += 1;
  chanFlag[k_SSWW8] += 1;
  chanFlag[k_SSWW13] += 1;
  chanFlag[k_EWKWg8] += 1;
  chanFlag[k_EWKWg13] += 1;
  chanFlag[k_EWKZg8] += 1;
  chanFlag[k_EWKZg13] += 1;
  chanFlag[k_EWKWZ13] += 1;
  chanFlag[k_EWKZZ13] += 1;

  


  chanFlag[k_VBFZ] += 1;
  chanFlag[k_VBFZ8] += 1;
  chanFlag[k_VBFZ13] += 1;
  chanFlag[k_VBFW8] += 1;
  chanFlag[k_VBFW13] += 1;

  if (!noTop){  
  chanFlag[k_tt] += 1;
  chanFlag[k_tt8] += 1;
  if (use13TeV) chanFlag[k_tt13] += 1;
  // Removed 7,8 TeV results, no publically avilable numbers
  //if (!noJets) chanFlag[k_tt1jet] += 1;
  //if (!noJets) chanFlag[k_tt2jet] += 1;
  //if (!noJets) chanFlag[k_tt3jet] += 1;
  //if (!noJets) chanFlag[k_tt1jet8] += 1;
  //if (!noJets) chanFlag[k_tt2jet8] += 1;
  //if (!noJets) chanFlag[k_tt3jet8] += 1;
  if (!noJets) chanFlag[k_tt0jet13] += 1;
  if (!noJets) chanFlag[k_tt1jet13] += 1;
  if (!noJets) chanFlag[k_tt2jet13] += 1;
  if (!noJets) chanFlag[k_tt3jet13] += 1;
  if (!noJets) chanFlag[k_tt4jet13] += 1;
  
  chanFlag[k_t] += 1;
  chanFlag[k_t8] += 1;
  if (use13TeV) chanFlag[k_t13] += 1;
  if (!lessLimits) chanFlag[k_tschan] += 1;
  chanFlag[k_tschan8] += 1;
  chanFlag[k_tW] += 1;
  chanFlag[k_tW8] += 1;
  if (use13TeV) chanFlag[k_tW13] += 1;
  chanFlag[k_ttg8] += 1;
  chanFlag[k_ttg13] += 1;
  chanFlag[k_ttW8] += 1;
  chanFlag[k_ttZ] += 1;
  chanFlag[k_ttZ8] += 1;
  if (use13TeV)  chanFlag[k_ttZ13] += 1;
  if (use13TeV)  chanFlag[k_ttW13] += 1;
  if (use13TeV)  chanFlag[k_tg13] += 1;
  chanFlag[k_tZq8] += 1;
  if (use13TeV) chanFlag[k_tZq13] += 1;
  if (!lessLimits) chanFlag[k_tttt8] += 1;
  if (use13TeV)  chanFlag[k_tttt13] += 1;
  }

  if (!noHiggs){
  chanFlag[k_ggH] += 1;
  chanFlag[k_VBFH] += 1;
  if (!lessLimits) chanFlag[k_VH] += 1;
  if (!lessLimits) chanFlag[k_ttH] += 1;
  chanFlag[k_ggH8] += 1;
  chanFlag[k_VBFH8] += 1;
  chanFlag[k_VH8] += 1;
  if (!lessLimits) chanFlag[k_VH13] += 1;
  chanFlag[k_WH13] += 1;
  chanFlag[k_ZH13] += 1;
  chanFlag[k_ttH8] += 1;
  chanFlag[k_ttH13] += 1;
  chanFlag[k_tH13] += 1;
  if (!lessLimits) chanFlag[k_HHComb8] += 1;
  //chanFlag[k_HHbbgg13] += 1;
  //chanFlag[k_HHComb13] += 1;
  //chanFlag[k_HHbbbb13] += 1;
  chanFlag[k_HHbbtautau13] += 1;

  
  chanFlag[k_ggHgg13] += 0;
  chanFlag[k_ggH13] += 1;

  chanFlag[k_VBFH13] += 1;

  
  chanFlag[k_HZZ] += 0;
  }



 }

if (version==2) {

  plotChan[k_W] = true;
  plotChan[k_W8] = true;
  if (use13TeV) plotChan[k_W13] = true;
  if (use13TeV) plotChan[k_Z13] = true;

  plotChan[k_Wp] = false;
  plotChan[k_Wm] = false;

  plotChan[k_Z] = true;
  plotChan[k_Z8] = true;

  plotChan[k_gg]=false;
  plotChan[k_Wg]=true;
  plotChan[k_Wg13]=true;
  plotChan[k_Zg]=true;
  plotChan[k_Zg8]=true;
  //plotChan[k_Zg13]=true;
  plotChan[k_WV]=false;
  plotChan[k_WW]=true;
  plotChan[k_WW8]=true;
  plotChan[k_WW13]=true;
  plotChan[k_WZ]=true;
  plotChan[k_WZ8]=true;
  if (use13TeV) plotChan[k_WZ13]=true;
  plotChan[k_ZZ]=true;
  plotChan[k_ZZ8]=true;
  if (use13TeV) plotChan[k_ZZ13]=true;

  plotChan[k_WVg]=true;
  plotChan[k_VVV13]=true;
  plotChan[k_WWW13]=true;
  plotChan[k_WWZ13]=true;
  plotChan[k_WZZ13]=true;
  plotChan[k_ZZZ13]=true;
  plotChan[k_Wgg8]=true;
  plotChan[k_Zgg8]=true;
  plotChan[k_Wgg13]=true;
  plotChan[k_Zgg13]=true;

  plotChan[k_exWW]=true;
  plotChan[k_exWW8]=true;

  plotChan[k_EWKWV13]=true;
  plotChan[k_EWKWW13]=true;
  plotChan[k_SSWW8]=true;
  plotChan[k_SSWW13]=true;
  plotChan[k_EWKWg8]=true;
  plotChan[k_EWKWg13]=true;
  plotChan[k_EWKZg8]=true;
  plotChan[k_EWKZg13]=true;
  plotChan[k_EWKWZ13]=true;
  plotChan[k_EWKZZ13]=true;


  plotChan[k_VBFZ]=true;
  plotChan[k_VBFZ8]=true;
  plotChan[k_VBFZ13]=true;
  plotChan[k_VBFW8]=true;
  plotChan[k_VBFW13]=true;

  plotChan[k_tt]=true;
  plotChan[k_tt8]=true;
  if (use13TeV) plotChan[k_tt13]=true;
  //plotChan[k_tt1jet] = true;
  //plotChan[k_tt2jet] = true;
  //plotChan[k_tt3jet] = true;
  //plotChan[k_tt1jet8] = true;
  //plotChan[k_tt2jet8] = true;
  //plotChan[k_tt3jet8] = true;
  //plotChan[k_tt0jet13] = true;
  //plotChan[k_tt1jet13] = true;
  //plotChan[k_tt2jet13] = true;
  //plotChan[k_tt3jet13] = true;
  //plotChan[k_tt4jet13] = true;

  
  plotChan[k_t]=true;
  plotChan[k_t8]=true;
  if (use13TeV) plotChan[k_t13]=true;
  plotChan[k_tschan]=true;
  plotChan[k_tschan8]=true;
  plotChan[k_tW]=true;
  plotChan[k_tW8]=true;
  if (use13TeV)  plotChan[k_tW13]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_ttg13]=true;
  plotChan[k_ttW8]=true;
  plotChan[k_ttZ]=true;
  plotChan[k_ttZ8]=true;
  if (use13TeV)  plotChan[k_ttZ13]=true;
  if (use13TeV)  plotChan[k_ttW13]=true;
  if (use13TeV)  plotChan[k_tg13]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_tZq8]=true;
  if (use13TeV) plotChan[k_tZq13]=true; 
  plotChan[k_tttt8]=true;
  if (use13TeV)  plotChan[k_tttt13]=true;

  
  plotChan[k_ggH]=true;
  plotChan[k_VBFH]=true;
  plotChan[k_VH]=true;
  plotChan[k_ttH]=true;
  plotChan[k_ggH8]=true;
  plotChan[k_VBFH8]=true;
  plotChan[k_VH8]=true;
  plotChan[k_VH13]=true;
  plotChan[k_WH13]=true;
  plotChan[k_ZH13]=true;
  plotChan[k_ttH8]=true;
  plotChan[k_ttH13]=true;
  plotChan[k_tH13]=true;
  plotChan[k_HHComb8]=true;
  //plotChan[k_HHbbgg13]=true;
  //plotChan[k_HHComb13]=true;
  //plotChan[k_HHbbbb13]=true;
  plotChan[k_HHbbtautau13]=true;


  plotChan[k_ggHgg13]=false;
  plotChan[k_ggH13]=true;

   plotChan[k_VBFH13]=true;


  plotChan[k_HZZ]=false;

 }

if (version==3||exportExeFormat) {

  plotChan[k_W] = true;
  plotChan[k_W8] = true;
  if (use13TeV) plotChan[k_W13] = true;
  if (use13TeV) plotChan[k_Z13] = true;

  plotChan[k_W1jetn] = true;
  plotChan[k_W2jetn] = true;
  plotChan[k_W3jetn] = true;
  plotChan[k_W4jetn] = true;
  plotChan[k_W5jetn] = true;
  plotChan[k_W6jetn] = true;

  plotChan[k_W1jet8n] = true;
  plotChan[k_W2jet8n] = true;
  plotChan[k_W3jet8n] = true;
  plotChan[k_W4jet8n] = true;
  plotChan[k_W5jet8n] = true;
  plotChan[k_W6jet8n] = true;
  if (!lessLimits) plotChan[k_W7jet8n] = true;

  plotChan[k_W1jet13] = true;
  plotChan[k_W2jet13] = true;
  plotChan[k_W3jet13] = true;
  plotChan[k_W4jet13] = true;
  plotChan[k_W5jet13] = true;
  plotChan[k_W6jet13] = true;

  
  plotChan[k_W1cjet] = true;
  plotChan[k_W1cjet8] = true;
  plotChan[k_W1cjet13] = true;
  plotChan[k_W2bjet] = true;
  plotChan[k_W2bjet8] = true;


  plotChan[k_Z] = true;
  plotChan[k_Z8] = true;
  plotChan[k_Z1jetn] = true;
  plotChan[k_Z2jetn] = true;
  plotChan[k_Z3jetn] = true;
  plotChan[k_Z4jetn] = true;
  plotChan[k_Z5jetn] = true;
  plotChan[k_Z6jetn] = true;
 
  plotChan[k_Z1jet8] = true;
  plotChan[k_Z2jet8] = true;
  plotChan[k_Z3jet8] = true;
  plotChan[k_Z4jet8] = true;
  plotChan[k_Z5jet8] = true;
  plotChan[k_Z6jet8] = true;
  plotChan[k_Z7jet8] = true;

  plotChan[k_Z1jet13] = true;
  plotChan[k_Z2jet13] = true;
  plotChan[k_Z3jet13] = true;
  plotChan[k_Z4jet13] = true;
  plotChan[k_Z5jet13] = true;
  plotChan[k_Z6jet13] = true;

  
  plotChan[k_Z1cjet8] = true;
  plotChan[k_Z1cjet13] = true;

  plotChan[k_Z1bjet] = true;
  plotChan[k_Z2bjet] = true;
  plotChan[k_Z1bjet8] = true;
  plotChan[k_Z2bjet8] = true;
  plotChan[k_Z1bjet13] = true;
  plotChan[k_Z2bjet13] = true;

  plotChan[k_Wg2jet13] = true;
  plotChan[k_Zg2jet13] = true;
  
  plotChan[k_WZ0jet8] = true;
  plotChan[k_WZ1jet8] = true;
  plotChan[k_WZ2jet8] = true;
  if (!lessLimits) plotChan[k_WZ3jet8] = true;

  
  plotChan[k_ZZ0jet13] = true;
  plotChan[k_ZZ1jet13] = true;
  plotChan[k_ZZ2jet13] = true;
  plotChan[k_ZZ3jet13] = true;

  plotChan[k_ZZ0jet8] = true;
  plotChan[k_ZZ1jet8] = true;
  plotChan[k_ZZ2jet8] = true;
  plotChan[k_ZZ3jet8] = true;


  
  //plotChan[k_tt]=true;
  //plotChan[k_tt8]=true;
  //if (use13TeV) plotChan[k_tt13]=true;
  // Remove 7,8 TeV results not publically available nubmers
  //plotChan[k_tt1jet] = true;
  //plotChan[k_tt2jet] = true;
  //plotChan[k_tt3jet] = true;
  //plotChan[k_tt1jet8] = true;
  //plotChan[k_tt2jet8] = true;
  //plotChan[k_tt3jet8] = true;
  plotChan[k_tt0jet13] = true;
  plotChan[k_tt1jet13] = true;
  plotChan[k_tt2jet13] = true;
  plotChan[k_tt3jet13] = true;
  plotChan[k_tt4jet13] = true;

  plotChan[k_tt2cjet13] = true;
  plotChan[k_tt2bjet13] = true;

  

  plotChan[k_H0jet13] = true;
  plotChan[k_H1jet13] = true;
  plotChan[k_H2jet13] = true;
  plotChan[k_H3jet13] = true;
  plotChan[k_H4jet13] = true;
 

  
  chanFlag[k_W] += 2;
  chanFlag[k_W8] += 2;
  if (use13TeV) chanFlag[k_W13] += 2;
  if (use13TeV) chanFlag[k_Z13] += 2;

  chanFlag[k_W1jetn] += 2;
  chanFlag[k_W2jetn] += 2;
  chanFlag[k_W3jetn] += 2;
  chanFlag[k_W4jetn] += 2;
  chanFlag[k_W5jetn] += 2;
  chanFlag[k_W6jetn] += 2;

  chanFlag[k_W1jet8n] += 2;
  chanFlag[k_W2jet8n] += 2;
  chanFlag[k_W3jet8n] += 2;
  chanFlag[k_W4jet8n] += 2;
  chanFlag[k_W5jet8n] += 2;
  chanFlag[k_W6jet8n] += 2;
  if (!lessLimits) chanFlag[k_W7jet8n] += 2;

  chanFlag[k_W1jet13] += 2;
  chanFlag[k_W2jet13] += 2;
  chanFlag[k_W3jet13] += 2;
  chanFlag[k_W4jet13] += 2;
  chanFlag[k_W5jet13] += 2;
  chanFlag[k_W6jet13] += 2;

  
  chanFlag[k_W1cjet] += 2;
  chanFlag[k_W1cjet8] += 2;
  chanFlag[k_W1cjet13] += 2;
  chanFlag[k_W2bjet] += 2;
  chanFlag[k_W2bjet8] += 2;


  chanFlag[k_Z] += 2;
  chanFlag[k_Z8] += 2;
  chanFlag[k_Z1jetn] += 2;
  chanFlag[k_Z2jetn] += 2;
  chanFlag[k_Z3jetn] += 2;
  chanFlag[k_Z4jetn] += 2;
  chanFlag[k_Z5jetn] += 2;
  chanFlag[k_Z6jetn] += 2;
 
  chanFlag[k_Z1jet8] += 2;
  chanFlag[k_Z2jet8] += 2;
  chanFlag[k_Z3jet8] += 2;
  chanFlag[k_Z4jet8] += 2;
  chanFlag[k_Z5jet8] += 2;
  chanFlag[k_Z6jet8] += 2;
  chanFlag[k_Z7jet8] += 2;

  chanFlag[k_Z1jet13] += 2;
  chanFlag[k_Z2jet13] += 2;
  chanFlag[k_Z3jet13] += 2;
  chanFlag[k_Z4jet13] += 2;
  chanFlag[k_Z5jet13] += 2;
  chanFlag[k_Z6jet13] += 2;

  
  chanFlag[k_Z1cjet8] += 2;
  chanFlag[k_Z1cjet13] += 2;

  chanFlag[k_Z1bjet] += 2;
  chanFlag[k_Z2bjet] += 2;
  chanFlag[k_Z1bjet8] += 2;
  chanFlag[k_Z2bjet8] += 2;
  chanFlag[k_Z1bjet13] += 2;
  chanFlag[k_Z2bjet13] += 2;

  chanFlag[k_Wg2jet13] += 2;
  chanFlag[k_Zg2jet13] += 2;
  
  chanFlag[k_WZ0jet8] += 2;
  chanFlag[k_WZ1jet8] += 2;
  chanFlag[k_WZ2jet8] += 2;
  if (!lessLimits) chanFlag[k_WZ3jet8] += 2;

  
  chanFlag[k_ZZ0jet13] += 2;
  chanFlag[k_ZZ1jet13] += 2;
  chanFlag[k_ZZ2jet13] += 2;
  chanFlag[k_ZZ3jet13] += 2;

  chanFlag[k_ZZ0jet8] += 2;
  chanFlag[k_ZZ1jet8] += 2;
  chanFlag[k_ZZ2jet8] += 2;
  chanFlag[k_ZZ3jet8] += 2;


 

  //chanFlag[k_tt]=true;
  //chanFlag[k_tt8]=true;
  //if (use13TeV) chanFlag[k_tt13]=true;
  // Remove 7,8 TeV results not publically available nubmers
  //chanFlag[k_tt1jet] += 2;
  //chanFlag[k_tt2jet] += 2;
  //chanFlag[k_tt3jet] += 2;
  //chanFlag[k_tt1jet8] += 2;
  //chanFlag[k_tt2jet8] += 2;
  //chanFlag[k_tt3jet8] += 2;
  chanFlag[k_tt0jet13] += 2;
  chanFlag[k_tt1jet13] += 2;
  chanFlag[k_tt2jet13] += 2;
  chanFlag[k_tt3jet13] += 2;
  chanFlag[k_tt4jet13] += 2;

  chanFlag[k_tt2cjet13] += 2;
  chanFlag[k_tt2bjet13] += 2;

  

  chanFlag[k_H0jet13] += 2;
  chanFlag[k_H1jet13] += 2;
  chanFlag[k_H2jet13] += 2;
  chanFlag[k_H3jet13] += 2;
  chanFlag[k_H4jet13] += 2;
 
 
 }



if (version==0) {
  subChan[k_W1jet] = 4;
  subChan[k_W2jet] = 4;
  subChan[k_W3jet] = 4;
  subChan[k_W4jet] = 4;

  subChan[k_Z1jet] = 4;
  subChan[k_Z2jet] = 4;
  subChan[k_Z3jet] = 4;
  subChan[k_Z4jet] = 4;




  subChan[k_tt1jet] = 11;
  subChan[k_tt2jet] = 11;
  subChan[k_tt3jet] = 11;
 
  subChan[k_tt1jet8] = 11;
  subChan[k_tt2jet8] = 11;
  subChan[k_tt3jet8] = 11;

  subChan[k_tt0jet13] = 11;
  subChan[k_tt1jet13] = 11;
  subChan[k_tt2jet13] = 11;
  subChan[k_tt3jet13] = 11;
  subChan[k_tt4jet13] = 11;

  
 }

if (version==4){
	
	//Photon summary plot
	plotChan[k_incj]=true;
	plotChan[k_incg]=true;
	plotChan[k_gj]=true;
	plotChan[k_gg]=true;
	plotChan[k_ggnew]=true;
	plotChan[k_Hgg]=true;
	plotChan[k_Hgg8]=true;
	
}

if (version==8) {


  
  plotChan[k_tt]=true;
  plotChan[k_tt8]=true;
  if (use13TeV) plotChan[k_tt13]=true;
  // Remove 7,8 TeV results, not publically avilable numbers
  //plotChan[k_tt1jet] = true;
  //plotChan[k_tt2jet] = true;
  //plotChan[k_tt3jet] = true;
  //plotChan[k_tt1jet8] = true;
  //plotChan[k_tt2jet8] = true;
  //plotChan[k_tt3jet8] = true;
  plotChan[k_tt0jet13] = true;
  plotChan[k_tt1jet13] = true;
  plotChan[k_tt2jet13] = true;
  plotChan[k_tt3jet13] = true;
  plotChan[k_tt4jet13] = true;

 plotChan[k_tt2cjet13] = true;
 plotChan[k_tt2bjet13] = true;

  
  plotChan[k_t]=true;
  plotChan[k_t8]=true;
  if (use13TeV) plotChan[k_t13]=true;
  plotChan[k_tschan]=true;
  plotChan[k_tschan8]=true;
  plotChan[k_tW]=true;
  plotChan[k_tW8]=true;
  if (use13TeV) plotChan[k_tW13]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_ttg13]=true;
  plotChan[k_ttW8]=true;
  plotChan[k_ttZ]=true;
  plotChan[k_ttZ8]=true;
  if (use13TeV)  plotChan[k_ttZ13]=true;
  if (use13TeV)  plotChan[k_ttW13]=true;
  if (use13TeV)  plotChan[k_tg13]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_tZq8]=true;
  if (use13TeV) plotChan[k_tZq13]=true;
  plotChan[k_tttt8]=true;
  if (use13TeV)  plotChan[k_tttt13]=true;
  
  plotChan[k_ttH]=true;
  plotChan[k_ttH8]=true;
  plotChan[k_ttH13]=true;
  plotChan[k_tH13]=true;


 }

// FOR SM Non Resonant HH 8 TeV RESULTS
if(version == 9){
  plotChan[k_HHbbgg8] = true; // bbgamgam 8 TeV
  plotChan[k_HHbbtautau8] = true; // bbtautau 8 TeV
  plotChan[k_HHComb8] = true; // 8 TeV (bbtautau + bbgamgam) combination
  if(use13TeV){plotChan[k_HHWWbb13] = true;} // 13 TeV bbWW
  if(use13TeV){plotChan[k_HHbbgg13] = true;} // bbgamgam 13 TeV
  if(use13TeV){plotChan[k_HHbbtautau13] = true;} // bbtt 13 TeV
  // Update with new chan
 }


// Ratio plot for dibosons
if (version==5) {

  plotChan[k_ggnew]=true;
  plotChan[k_Wg]=true;
  plotChan[k_Wg13]=true;
  plotChan[k_Zg]=true;
  plotChan[k_Zg8]=true;
  plotChan[k_WV]=true;
  plotChan[k_WW]=true;
  plotChan[k_WW8]=true;
  if (use13TeV) plotChan[k_WW13fid]=true;
  plotChan[k_WZ]=true;
  plotChan[k_WZ8]=true;
  if (use13TeV) plotChan[k_WZ13fid]=true;
  plotChan[k_ZZ]=true;
  plotChan[k_ZZ8]=true;
  if (use13TeV)  plotChan[k_ZZ13]=true;



  
 }

// EWK scattering measurements
if (version==6) {

  plotChan[k_VBFW8]=true;
  plotChan[k_VBFW13]=true;
  plotChan[k_VBFZ]=true;
  plotChan[k_VBFZ8]=true;
  plotChan[k_VBFZ13]=true;
  plotChan[k_exWW]=true;
  plotChan[k_exWW8]=true;
  plotChan[k_EWKWV13]=true;
  plotChan[k_EWKWW13]=true;
  plotChan[k_SSWW8]=true;
  plotChan[k_SSWW13]=true;
  plotChan[k_EWKWg8]=true;
  plotChan[k_EWKWg13]=true;
  plotChan[k_EWKZg8]=true;
  plotChan[k_EWKZg13]=true;
  plotChan[k_EWKWZ13]=true;
  plotChan[k_EWKZZ13]=true;

  //plotChan[k_Wgg8]=true;
  //plotChan[k_Zgg8]=true;


}

// Some plots of interest
if (version==7) {

  plotChan[k_W13]=true;
  plotChan[k_Z13]=true;
  plotChan[k_WZ13]=true;
  plotChan[k_ZZ13]=true;
  plotChan[k_tt13]=true;
  plotChan[k_t13]=true;
  plotChan[k_ttZ13]=true;
}



  float scale_;
  
// W production
  chanMeasurement[k_W]     = "W";
  chanLumi[k_W] = "0.036 fb^{-1}";
  chanCadi[k_W] = "EWK-10-005";
  chanPreprint[k_W] = "1107.4789";
  chanPublication[k_W] = "JHEP 10 (2011) 132";


  scale_ = (1000./W_br_lnu);
if (version==3) scale_ = 1000.*0.4933;
  chanSigma[k_W]  = 10.30 * scale_; 
  chanEStat[k_W]  =  0.02 * scale_;
  chanESyst[k_W]  =  0.10 * scale_;
// stat, sys, theory, lumi
  chanETot[k_W]   =  sqrt( 
			  chanEStat[k_W]*chanEStat[k_W]
			  +
			  chanESyst[k_W]*chanESyst[k_W]
			  + 
			  0.10*0.10
                          +
                          0.41*0.41
			   );
  
  chanTheo[k_W] = 10.44 * scale_;
  chanETheo[k_W] = 0.27 * scale_;
 
// W+ production
  chanMeasurement[k_Wp]    = "W^{ +}";
  chanLumi[k_Wp] = "0.036 fb^{-1}";

  chanSigma[k_Wp]  =  6.04 * scale_; 
  chanEStat[k_Wp]  =  0.02 * scale_;
  chanESyst[k_Wp]  =  0.06 * scale_;
  chanETot[k_Wp]   =  sqrt( 
			   chanEStat[k_Wp]*chanEStat[k_Wp]
			   +
			   chanESyst[k_Wp]*chanESyst[k_Wp]
			   + 
			   0.08*0.08 // theory
			    );
  chanTheo[k_Wp] =  6.15 * scale_;
  chanETheo[k_Wp] = 0.17 * scale_;

// W- production
  chanMeasurement[k_Wm]    = "W^{ -}";
  chanLumi[k_Wm] = "0.036 fb^{-1}";

  chanSigma[k_Wm]  =  4.26 * scale_; 
  chanEStat[k_Wm]  =  0.01 * scale_;
  chanESyst[k_Wm]  =  0.04 * scale_;
  chanETot[k_Wm]   =  sqrt( 
			   chanEStat[k_Wm]*chanEStat[k_Wm]
			   +
			   chanESyst[k_Wm]*chanESyst[k_Wm]
			   + 
			   0.07*0.07 // theory
			    );
  chanTheo[k_Wm] =  4.29 * scale_;
  chanETheo[k_Wm] = 0.11 * scale_;

// W 8 TeV 
  // chanMeasurement[k_W8]    = "W";

  // chanSigma[k_W8]  = 11.88 * scale_; 
  // chanEStat[k_W8]  =  0.03 * scale_;
  // chanESyst[k_W8]  =  0.56 * scale_;
  // chanETot[k_W8]   =  sqrt( 
  // 			  chanEStat[k_W8]*chanEStat[k_W8]
  // 			  +
  // 			  chanESyst[k_W8]*chanESyst[k_W8]
  // 			   );
  // chanTheo[k_W8] = 12.50 * scale_;
  // chanETheo[k_W8] = 0.32 * scale_;

// W 8 TeV PRL 18.2 pb http://arxiv.org/abs/1402.0923
  chanMeasurement[k_W8]    = "W";
  chanLumi[k_W8] = "0.018 fb^{-1}";
  chanCadi[k_W8] = "SMP-12-011";
  chanPreprint[k_W8] = "1402.0923";
  chanPublication[k_W8] = "PRL 112 (2014) 191802";

if (version == 3) scale_ = 1000.*0.4595;


  chanSigma[k_W8]  = 12.21 * scale_; 
  chanEStat[k_W8]  =  0.03 * scale_;
  chanESyst[k_W8]  =  0.40 * scale_;
  chanETot[k_W8]   =  sqrt( 
			  chanEStat[k_W8]*chanEStat[k_W8]
			  +
			  chanESyst[k_W8]*chanESyst[k_W8]
			   );
  chanTheo[k_W8] = 12.18 * scale_;
  chanETheo[k_W8] = 0.32 * scale_;


// W 13 http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-15-004/index.html
  if (use13TeV) chanMeasurement[k_W13]    =  "W";
  chanLumi[k_W13] = "0.043 fb^{-1}";
  chanCadi[k_W13] = "SMP-15-004";
  chanPreprint[k_W13] = "https://cds.cern.ch/record/2093537";
//chanPublication[k_W13] = None

if (big13TeV) chanMeasurement[k_W13]    =  "#splitline{   W}{13Tev}";

if (version == 3) scale_ = 1000.*0.4595;


  chanSigma[k_W13]  = 19.950 * scale_; 
  chanEStat[k_W13]  =  0.120 * scale_;
chanESyst[k_W13]  =  sqrt(.360*.360+.960*.960) * scale_;
  chanETot[k_W13]   =  sqrt( 
			  chanEStat[k_W13]*chanEStat[k_W13]
			  +
			  chanESyst[k_W13]*chanESyst[k_W13]
			   );
  chanTheo[k_W13] = 19.700 * scale_;
  chanETheo[k_W13] = 0.515 * scale_;
// +560-470

// Z production
  chanMeasurement[k_Z]     = "Z";
  chanLumi[k_Z] = "0.036 fb^{-1}";
  chanCadi[k_Z] = "EWK-10-005";
  chanPreprint[k_Z] = "1107.4789";
  chanPublication[k_Z] = "JHEP 10 (2011) 132";

scale_ = (1000.0/Z0_br_ll);
if (version == 3) scale_ = 1000.*0.3876;

  chanSigma[k_Z]  =  0.974 * scale_; 
  chanEStat[k_Z]  =  0.007 * scale_;
  chanESyst[k_Z]  =  0.007 * scale_;
  chanETot[k_Z]   =  sqrt( 
			  chanEStat[k_Z]*chanEStat[k_Z]
			  +
			  chanESyst[k_Z]*chanESyst[k_Z]
			  + 
			  0.018*0.018 // theory
                          +
                          0.039*0.039 // lumi
			   );

  chanTheo[k_Z] =  0.97 * scale_;
  chanETheo[k_Z] = 0.03 * scale_;


  chanResult[k_Z] = "1.004 #pm 0.010 #pm 0.031";
// Z 8 TeV
  // chanMeasurement[k_Z8]    = "Z";

  // chanSigma[k_Z8]  =  1.12 * scale_; 
  // chanEStat[k_Z8]  =  0.01 * scale_;
  // chanESyst[k_Z8]  =  0.05 * scale_;
  // chanETot[k_Z8]   =  sqrt( 
  // 			  chanEStat[k_Z8]*chanEStat[k_Z8]
  // 			  +
  // 			  chanESyst[k_Z8]*chanESyst[k_Z8]
  // 			   );
  // chanTheo[k_Z8] =  1.13 * scale_;
  // chanETheo[k_Z8] = 0.04 * scale_;
 

// Z 8 TeV PRL, 18.2 pb http://arxiv.org/abs/arXiv:1402.0923


  chanMeasurement[k_Z8]    = "Z";
  chanLumi[k_Z8] = "0.018 fb^{-1}";
  chanCadi[k_Z8] = "SMP-12-011";
  chanPreprint[k_Z8] = "1402.0923";
  chanPublication[k_Z8] = "PRL 112 (2014) 191802";

if (version == 3) scale_ = 1000.*0.3725;


  chanSigma[k_Z8]  =  1.15 * scale_; 
  chanEStat[k_Z8]  =  0.01 * scale_;
  chanESyst[k_Z8]  =  0.036 * scale_;
  chanETot[k_Z8]   =  sqrt( 
			  chanEStat[k_Z8]*chanEStat[k_Z8]
			  +
			  chanESyst[k_Z8]*chanESyst[k_Z8]
			   );
  chanTheo[k_Z8] =  1.13 * scale_;
  chanETheo[k_Z8] = 0.04 * scale_;
 
// Z 8 TeV PRL, once published replace with http://cds.cern.ch/record/1728320?ln=en
// !!!!! replace at some point

//   chanMeasurement[k_Z8]    = "Z";
//   if (version == 3) scale_ = 1000.*0.3725;


//   chanSigma[k_Z8]  =  1.139 * scale_; 
//   chanEStat[k_Z8]  =  0.0002 * scale_;
// chanESyst[k_Z8]  =  sqrt(0.0079*0.0079 + 0.0252*0.0252 + 0.0296*0.0296) * scale_;
//   chanETot[k_Z8]   =  sqrt( 
// 			  chanEStat[k_Z8]*chanEStat[k_Z8]
// 			  +
// 			  chanESyst[k_Z8]*chanESyst[k_Z8]
// 			   );
//   chanTheo[k_Z8] =  1.1372 * scale_;
//   chanETheo[k_Z8] = 0.0361 * scale_;
 
// Z 13 http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-15-004/index.html
//   if (use13TeV) chanMeasurement[k_Z13]    =  "Z";
// if (big13TeV) chanMeasurement[k_Z13]    =  "#splitline{   Z}{13Tev}";

// if (version == 3) scale_ = 1000.*0.4595;


//   chanSigma[k_Z13]  = 1.910 * scale_; 
//   chanEStat[k_Z13]  =  0.010 * scale_;
// chanESyst[k_Z13]  =  sqrt(.040*.040+.090*.090) * scale_;
//   chanETot[k_Z13]   =  sqrt( 
// 			  chanEStat[k_Z13]*chanEStat[k_Z13]
// 			  +
// 			  chanESyst[k_Z13]*chanESyst[k_Z13]
// 			   );
//   chanTheo[k_Z13] = 1.870 * scale_;
//   chanETheo[k_Z13] = 0.045 * scale_;
// +50-40

// new Z 13 http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-15-011/index.html
  if (use13TeV) chanMeasurement[k_Z13]    =  "Z";
  chanLumi[k_Z13] = "2.3 fb^{-1}";
  chanCadi[k_Z13] = "SMP-15-011";
  chanPreprint[k_Z13] = "https://cds.cern.ch/record/2140105";
//chanPublication[k_Z13] = None;

if (big13TeV) chanMeasurement[k_Z13]    =  "#splitline{   Z}{13Tev}";

if (version == 3) scale_ = 1000.*0.4595;


  chanSigma[k_Z13]  = 1.870 * scale_; 
  chanEStat[k_Z13]  =  0.002 * scale_;
chanESyst[k_Z13]  =  sqrt(.035*.035+.051*.051) * scale_;
  chanETot[k_Z13]   =  sqrt( 
			  chanEStat[k_Z13]*chanEStat[k_Z13]
			  +
			  chanESyst[k_Z13]*chanESyst[k_Z13]
			   );
  chanTheo[k_Z13] = 1.870 * scale_;
  chanETheo[k_Z13] = 0.045 * scale_;
// +50-40


// W+ jets 1 jet
// As an estimate NLO uncerainties from  http://arxiv.org/abs/1009.2338 are used
// Update to reference !!!!!new http://arxiv.org/abs/1406.7533
  chanMeasurement[k_W1jet] = "#geq1j";
  if (exportExeFormat) chanMeasurement[k_W1jet] = "Wj";
  chanLumi[k_W1jet] = "5 fb^{-1}";

  scale_ = chanSigma[k_W];

  chanSigma[k_W1jet]  = 0.136 * scale_;
  chanEStat[k_W1jet]  =   0.002 * scale_;
  chanETot[k_W1jet]   =  sqrt( 0.007*0.007 + 0.02*0.02 + 0.001*0.001 + 0.00544*0.00544) * scale_;
  chanESyst[k_W1jet]  =  sqrt( chanETot[k_W1jet]*chanETot[k_W1jet] 
			       - 
			       chanEStat[k_W1jet]*chanEStat[k_W1jet]
			       );
  chanTheo[k_W1jet]  = 1.23959384858608246e-01 * scale_;
  chanETheo[k_W1jet] = 0.00505 * scale_;

// W + jets 2 jets
  chanMeasurement[k_W2jet] = "#geq2j";
  if (exportExeFormat) chanMeasurement[k_W2jet] = "W2j";
  chanLumi[k_W2jet] = "5 fb^{-1}";

  chanSigma[k_W2jet]  = 0.026 * scale_;
  chanEStat[k_W2jet]  =   0.001 * scale_;
  chanETot[k_W2jet]   =  sqrt( 0.002*0.002 + 0.004*0.004 + 0.002*0.002 + 0.00104*0.00104) * scale_;
  chanESyst[k_W2jet]  =  sqrt( chanETot[k_W2jet]*chanETot[k_W2jet] 
			       - 
			       chanEStat[k_W2jet]*chanEStat[k_W2jet]
			       );
  chanTheo[k_W2jet]  = 2.30696983635425568e-02 * scale_;
  chanETheo[k_W2jet] = 0.000827 * scale_;

// W + jets 3 jets
  chanMeasurement[k_W3jet] = "#geq3j";
  if (exportExeFormat) chanMeasurement[k_W3jet] = "W3j";
  chanLumi[k_W3jet] = "5 fb^{-1}";

  chanSigma[k_W3jet]  = 0.0041 * scale_;
  chanEStat[k_W3jet]  =   0.0003 * scale_;
  chanETot[k_W3jet]   =  sqrt( 0.0005*0.0005 + 0.0008*0.0008 + 0.0003*0.0003 + 0.000164*0.000164 ) * scale_;
  chanESyst[k_W3jet]  =  sqrt( chanETot[k_W3jet]*chanETot[k_W3jet] 
			       - 
			       chanEStat[k_W3jet]*chanEStat[k_W3jet]
			       );
  chanTheo[k_W3jet]  = 3.99857712909579277e-03 * scale_;
  chanETheo[k_W3jet] = 0.000177 * scale_;

// W + jets 4 jets
  chanMeasurement[k_W4jet] = "#geq4j";
  if (exportExeFormat) chanMeasurement[k_W4jet] = "W4j";
  chanLumi[k_W4jet] = "5 fb^{-1}";

  chanSigma[k_W4jet]  = 0.00059 * scale_;
  chanEStat[k_W4jet]  =   0.00011 * scale_;
  chanETot[k_W4jet]   =  sqrt( 0.00017*0.00017 + 0.00012*0.00012 + 0.00015*0.00015 + 0.0000236*0.0000236) * scale_;
  chanESyst[k_W4jet]  =  sqrt( chanETot[k_W4jet]*chanETot[k_W4jet] 
			       - 
			       chanEStat[k_W4jet]*chanEStat[k_W4jet]
			       );
  chanTheo[k_W4jet]  = 7.47408485040068626e-04 * scale_;
  chanETheo[k_W4jet] = 0.00004 * scale_;



// new W + jets 1 jet 7 TeV
// NL0 uncertainties with Sherpa + blackhat are are used except in the 5 and 6 jet bins
// Cross section is fiducial W->lnu with acceptance
// https://cds.cern.ch/record/1664744, CMS-PAS-SMP-12-023, numbers from AN 2012 331
// https://arxiv.org/abs/1406.7533, Phys. Lett. B 741 (2015) 12
// Exp numbers updated from hepdata

  chanMeasurement[k_W1jetn] = "#geq1j";
  if (exportExeFormat) chanMeasurement[k_W1jetn] = "Wj";
  chanLumi[k_W1jetn] = "5 fb^{-1}";
  chanCadi[k_W1jetn] = "SMP-12-023";
  chanPreprint[k_W1jetn] = "1406.7533";
  chanPublication[k_W1jetn] = "PLB 741 (2015) 12";

  scale_ = 1.0;

  chanSigma[k_W1jetn]  = 479.8 * scale_;
  chanEStat[k_W1jetn]  =   18.26 * scale_;
  chanETot[k_W1jetn]   =   19.6 * scale_;
  chanESyst[k_W1jetn]  =  sqrt( chanETot[k_W1jetn]*chanETot[k_W1jetn] 
			       - 
			       chanEStat[k_W1jetn]*chanEStat[k_W1jetn]
			       );
chanTheo[k_W1jetn]  = 473.0 * scale_;
chanETheo[k_W1jetn] =  sqrt(29.0*29.0 )* scale_;
// + 1.8 - 2.1, +1.7 - 1.9

// new W + jetns 2 jetns  TeV
  chanMeasurement[k_W2jetn] = "#geq2j";
  if (exportExeFormat) chanMeasurement[k_W2jetn] = "W2j";
  chanLumi[k_W2jetn] = "5 fb^{-1}";
  chanCadi[k_W2jetn] = "SMP-12-023";
  chanPreprint[k_W2jetn] = "1406.7533";
  chanPublication[k_W2jetn] = "PLB 741 (2015) 12";

  chanSigma[k_W2jetn]  = 95.62 * scale_;
  chanEStat[k_W2jetn]  =  8.523 * scale_;
  chanETot[k_W2jetn]   =  9.957 * scale_;
  chanESyst[k_W2jetn]  =  sqrt( chanETot[k_W2jetn]*chanETot[k_W2jetn] 
			       - 
			       chanEStat[k_W2jetn]*chanEStat[k_W2jetn]
			       );
chanTheo[k_W2jetn]  = 94.6 * scale_;
chanETheo[k_W2jetn] = sqrt(6.65*6.65) * scale_;
// +2.1 - 1.5, _0.5 -0.6

// new W + jetns 3 jetn  TeV
  chanMeasurement[k_W3jetn] = "#geq3j";
  if (exportExeFormat) chanMeasurement[k_W3jetn] = "W3j";
  chanLumi[k_W3jetn] = "5 fb^{-1}";
  chanCadi[k_W3jetn] = "SMP-12-023";
  chanPreprint[k_W3jetn] = "1406.7533";
  chanPublication[k_W3jetn] = "PLB 741 (2015) 12";

  chanSigma[k_W3jetn]  = 16.55 * scale_;
  chanEStat[k_W3jetn]  =   2.33 * scale_;
  chanETot[k_W3jetn]   =  2.04 * scale_;
  chanESyst[k_W3jetn]  =  sqrt( chanETot[k_W3jetn]*chanETot[k_W3jetn] 
			       - 
			       chanEStat[k_W3jetn]*chanEStat[k_W3jetn]
			       );
chanTheo[k_W3jetn]  = 16.9 * scale_;
chanETheo[k_W3jetn] = sqrt(1.6*1.6) * scale_;
// +0.7 - 0.5, +0.1 - 0.2

// new W + jetns 4 jetn  TeV
  chanMeasurement[k_W4jetn] = "#geq4j";
  if (exportExeFormat) chanMeasurement[k_W4jetn] = "W4j";
  chanLumi[k_W4jetn] = "5 fb^{-1}";
  chanCadi[k_W4jetn] = "SMP-12-023";
  chanPreprint[k_W4jetn] = "1406.7533";
  chanPublication[k_W4jetn] = "PLB 741 (2015) 12";

  chanSigma[k_W4jetn]  = 2.927 * scale_;
  chanEStat[k_W4jetn]  =   0.516 * scale_;
  chanETot[k_W4jetn]   =  0.482 * scale_;
  chanESyst[k_W4jetn]  =  sqrt( chanETot[k_W4jetn]*chanETot[k_W4jetn] 
			       - 
			       chanEStat[k_W4jetn]*chanEStat[k_W4jetn]
			       );
 chanTheo[k_W4jetn]  = 2.60 * scale_;
chanETheo[k_W4jetn] = sqrt( 0.32*0.32) * scale_;
// +0.15 - 0.14, +0.03 - 0.03

// new W + jetns 5 jetn  TeV
  chanMeasurement[k_W5jetn] = "#geq5j";
  if (exportExeFormat) chanMeasurement[k_W5jetn] = "W5j";
  chanLumi[k_W5jetn] = "5 fb^{-1}";
  chanCadi[k_W5jetn] = "SMP-12-023";
  chanPreprint[k_W5jetn] = "1406.7533";
  chanPublication[k_W5jetn] = "PLB 741 (2015) 12";

  chanSigma[k_W5jetn]  = 0.449 * scale_;
  chanEStat[k_W5jetn]  =   0.118 * scale_;
  chanETot[k_W5jetn]   =  0.122 * scale_;
  chanESyst[k_W5jetn]  =  sqrt( chanETot[k_W5jetn]*chanETot[k_W5jetn] 
			       - 
			       chanEStat[k_W5jetn]*chanEStat[k_W5jetn]
			       );
  chanTheo[k_W5jetn]  = 0.546 * scale_;
chanETheo[k_W5jetn] = sqrt( 0.017*0.017) * scale_;
// +0.15 - 0.14, +0.03 - 0.03

// new W + jetns 6 jetn  TeV
  chanMeasurement[k_W6jetn] = "#geq6j";
  if (exportExeFormat) chanMeasurement[k_W6jetn] = "W6j";
  chanLumi[k_W6jetn] = "5 fb^{-1}";
  chanCadi[k_W6jetn] = "SMP-12-023";
  chanPreprint[k_W6jetn] = "1406.7533";
  chanPublication[k_W6jetn] = "PLB 741 (2015) 12";

  chanSigma[k_W6jetn]  = 0.06739 * scale_;
  chanEStat[k_W6jetn]  =   0.02293 * scale_;
  chanETot[k_W6jetn]   =  0.02568 * scale_;
  chanESyst[k_W6jetn]  =  sqrt( chanETot[k_W6jetn]*chanETot[k_W6jetn] 
			       - 
			       chanEStat[k_W6jetn]*chanEStat[k_W6jetn]
			       );
  chanTheo[k_W6jetn]  = 0.0867 * scale_;
chanETheo[k_W6jetn] = sqrt( 0.002*0.002) * scale_;
// +0.15 - 0.14, +0.03 - 0.03



// new W + jets 8 TeV
// Cross section is fiducial W->lnu with acceptance
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-14-023/index.html
// https://arxiv.org/abs/1610.04222 
// Errors from private communication Apichart Hortiangtham <apichart.hortiangtham@cern.ch>
// Blackhat, 1-4, aMC@NLO 5,6

// new W + jet8ns 1 jet8ns  8 TeV


  chanMeasurement[k_W1jet8n] = "#geq1j";
  if (exportExeFormat) chanMeasurement[k_W1jet8n] = "Wj";
  chanLumi[k_W1jet8n] = "19.6 fb^{-1}";
  chanCadi[k_W1jet8n] = "SMP-14-023";
  chanPreprint[k_W1jet8n] = "1610.04222";
  chanPublication[k_W1jet8n] = "PRD 95 052002 (2017)";

scale_ = 1.0;

  chanSigma[k_W1jet8n]  = 629.0 * scale_;
  chanEStat[k_W1jet8n]  =   0.323 * scale_;
  chanETot[k_W1jet8n]   =   53.5 * scale_;
  chanESyst[k_W1jet8n]  =  sqrt( chanETot[k_W1jet8n]*chanETot[k_W1jet8n] 
			       - 
			       chanEStat[k_W1jet8n]*chanEStat[k_W1jet8n]
			       );
chanTheo[k_W1jet8n]  = 581.0 * scale_;
chanETheo[k_W1jet8n] =  11.6 * scale_;
//

// new W + jet8ns 2 jet 8  TeV
  chanMeasurement[k_W2jet8n] = "#geq2j";
  if (exportExeFormat) chanMeasurement[k_W2jet8n] = "W2j";
  chanLumi[k_W2jet8n] = "19.6 fb^{-1}";
  chanCadi[k_W2jet8n] = "SMP-14-023";
  chanPreprint[k_W2jet8n] = "1610.04222";
  chanPublication[k_W2jet8n] = "PRD 95 052002 (2017)";

  chanSigma[k_W2jet8n]  = 130.0 * scale_;
  chanEStat[k_W2jet8n]  =  0.156 * scale_;
  chanETot[k_W2jet8n]   =  13.8 * scale_;
  chanESyst[k_W2jet8n]  =  sqrt( chanETot[k_W2jet8n]*chanETot[k_W2jet8n] 
			       - 
			       chanEStat[k_W2jet8n]*chanEStat[k_W2jet8n]
			       );
chanTheo[k_W2jet8n]  = 121.0 * scale_;
chanETheo[k_W2jet8n] = 4.11 * scale_;
//

// new W + jet8ns 3 jet 8  TeV
  chanMeasurement[k_W3jet8n] = "#geq3j";
  if (exportExeFormat) chanMeasurement[k_W3jet8n] = "W3j";
  chanLumi[k_W3jet8n] = "19.6 fb^{-1}";
  chanCadi[k_W3jet8n] = "SMP-14-023";
  chanPreprint[k_W3jet8n] = "1610.04222";
  chanPublication[k_W3jet8n] = "PRD 95 052002 (2017)";

  chanSigma[k_W3jet8n]  = 24.5 * scale_;
  chanEStat[k_W3jet8n]  =   0.0752 * scale_;
  chanETot[k_W3jet8n]   =  3.39 * scale_;
  chanESyst[k_W3jet8n]  =  sqrt( chanETot[k_W3jet8n]*chanETot[k_W3jet8n] 
			       - 
			       chanEStat[k_W3jet8n]*chanEStat[k_W3jet8n]
			       );
chanTheo[k_W3jet8n]  = 22.0 * scale_;
chanETheo[k_W3jet8n] = 1.56 * scale_;
//

// new W + jet8ns 4 jet 8  TeV
  chanMeasurement[k_W4jet8n] = "#geq4j";
  if (exportExeFormat) chanMeasurement[k_W4jet8n] = "Wj";
  chanLumi[k_W4jet8n] = "19.6 fb^{-1}";
  chanCadi[k_W4jet8n] = "SMP-14-023";
  chanPreprint[k_W4jet8n] = "1610.04222";
  chanPublication[k_W4jet8n] = "PRD 95 052002 (2017)";

  chanSigma[k_W4jet8n]  = 4.55 * scale_;
  chanEStat[k_W4jet8n]  =   0.0371 * scale_;
  chanETot[k_W4jet8n]   =  0.898 * scale_;
  chanESyst[k_W4jet8n]  =  sqrt( chanETot[k_W4jet8n]*chanETot[k_W4jet8n] 
			       - 
			       chanEStat[k_W4jet8n]*chanEStat[k_W4jet8n]
			       );
 chanTheo[k_W4jet8n]  = 3.17 * scale_;
chanETheo[k_W4jet8n] = 0.369 * scale_;
//

// new W + jet8ns 5 jet 8  TeV
  chanMeasurement[k_W5jet8n] = "#geq5j";
  if (exportExeFormat) chanMeasurement[k_W5jet8n] = "W5j";
  chanLumi[k_W5jet8n] = "19.6 fb^{-1}";
  chanCadi[k_W5jet8n] = "SMP-14-023";
  chanPreprint[k_W5jet8n] = "1610.04222";
  chanPublication[k_W5jet8n] = "PRD 95 052002 (2017)";

  chanSigma[k_W5jet8n]  = 0.785 * scale_;
  chanEStat[k_W5jet8n]  =   0.0181 * scale_;
  chanETot[k_W5jet8n]   =  0.231 * scale_;
  chanESyst[k_W5jet8n]  =  sqrt( chanETot[k_W5jet8n]*chanETot[k_W5jet8n] 
			       - 
			       chanEStat[k_W5jet8n]*chanEStat[k_W5jet8n]
			       );
  chanTheo[k_W5jet8n]  = 0.612 * scale_;
chanETheo[k_W5jet8n] = 0.0588 * scale_;
//

// new W + jet8ns 6 jet 8  TeV
  chanMeasurement[k_W6jet8n] = "#geq6j";
  if (exportExeFormat) chanMeasurement[k_W6jet8n] = "W6j";
  chanLumi[k_W6jet8n] = "19.6 fb^{-1}";
  chanCadi[k_W6jet8n] = "SMP-14-023";
  chanPreprint[k_W6jet8n] = "1610.04222";
  chanPublication[k_W6jet8n] = "PRD 95 052002 (2017)";

  chanSigma[k_W6jet8n]  = 0.12 * scale_;
  chanEStat[k_W6jet8n]  =   0.00879 * scale_;
  chanETot[k_W6jet8n]   =  0.0653 * scale_;
  chanESyst[k_W6jet8n]  =  sqrt( chanETot[k_W6jet8n]*chanETot[k_W6jet8n] 
			       - 
			       chanEStat[k_W6jet8n]*chanEStat[k_W6jet8n]
			       );
  chanTheo[k_W6jet8n]  = 0.11 * scale_;
chanETheo[k_W6jet8n] = 0.0249 * scale_;
//

// new W + jet8ns 7 jet 8  TeV
  chanMeasurement[k_W7jet8n] = "#geq7j";
  if (exportExeFormat) chanMeasurement[k_W7jet8n] = "W7j";
  chanLumi[k_W7jet8n] = "19.6 fb^{-1}";
  chanCadi[k_W7jet8n] = "SMP-14-023";
  chanPreprint[k_W7jet8n] = "1610.04222";
  chanPublication[k_W7jet8n] = "PRD 95 052002 (2017)";

  chanSigma[k_W7jet8n]  = 0.0153 * scale_;
  chanEStat[k_W7jet8n]  =   0.0042 * scale_;
  chanETot[k_W7jet8n]   =  0.0186 * scale_;
  chanESyst[k_W7jet8n]  =  sqrt( chanETot[k_W7jet8n]*chanETot[k_W7jet8n] 
			       - 
			       chanEStat[k_W7jet8n]*chanEStat[k_W7jet8n]
			       );
  chanTheo[k_W7jet8n]  = 0.0272 * scale_;
chanETheo[k_W7jet8n] = 0.00891 * scale_;
// +0.15 - 0.14, +0.03 - 0.03




// http://cms.cern.ch/iCMS/analysisadmin/cadilines?line=SMP-16-005
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-16-005/index.html
// CMS PAS SMP-16-005
//Replaced with
// https://arxiv.org/abs/1707.05979 PRD 96 (2017) 072005
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-16-005/



// W + 1 jet, 13 TeV

  chanMeasurement[k_W1jet13] = "#geq1j";
  if (exportExeFormat) chanMeasurement[k_W1jet13] = "Wj";
  chanLumi[k_W1jet13] = "2.2 fb^{-1}";
  chanCadi[k_W1jet13] = "SMP-16-005";
  chanPreprint[k_W1jet13] = "1707.05979";
  chanPublication[k_W1jet13] = "PRD 96 (2017) 072005";

  scale_ = 1.0;

  chanSigma[k_W1jet13]  = 1072.44 * scale_;
  chanETot[k_W1jet13]   =   29.37 * scale_;

  chanTheo[k_W1jet13]  =  1143.973   * scale_;
chanETheo[k_W1jet13] =  ((88.2183+88.8754)/2.0)  * scale_;


// W + 2 jet, 13 TeV

  chanMeasurement[k_W2jet13] = "#geq2j";
  if (exportExeFormat) chanMeasurement[k_W2jet13] = "W2j";
  chanLumi[k_W2jet13] = "2.2 fb^{-1}";
  chanCadi[k_W2jet13] = "SMP-16-005";
  chanPreprint[k_W2jet13] = "1707.05979";
  chanPublication[k_W2jet13] = "PRD 96 (2017) 072005";

scale_ = 1.0;

  chanSigma[k_W2jet13]  = 239.8799   * scale_;
  chanETot[k_W2jet13]   = 16.76156 * scale_;

  chanTheo[k_W2jet13]  =  252.5579  * scale_;
  chanETheo[k_W2jet13] =  ((24.1232+21.8721)/2.0)  * scale_;

// W + 3 jet, 13 TeV

  chanMeasurement[k_W3jet13] = "#geq3j";
  if (exportExeFormat) chanMeasurement[k_W3jet13] = "W3j";
  chanLumi[k_W3jet13] = "2.2 fb^{-1}";
  chanCadi[k_W3jet13] = "SMP-16-005";
  chanPreprint[k_W3jet13] = "1707.05979";
  chanPublication[k_W3jet13] = "PRD 96 (2017) 072005";

scale_ = 1.0;

  chanSigma[k_W3jet13]  = 50.45817 * scale_;
  chanETot[k_W3jet13]   = 4.714946 * scale_;

  chanTheo[k_W3jet13]  =  52.98282 * scale_;
  chanETheo[k_W3jet13] =  ((5.46426+5.56942)/2.0)  * scale_;

// W + 4 jet, 13 TeV

  chanMeasurement[k_W4jet13] = "#geq4j";
  if (exportExeFormat) chanMeasurement[k_W4jet13] = "W4j";
  chanLumi[k_W4jet13] = "2.2 fb^{-1}";
  chanCadi[k_W4jet13] = "SMP-16-005";
  chanPreprint[k_W4jet13] = "1707.05979";
  chanPublication[k_W4jet13] = "PRD 96 (2017) 072005";

scale_ = 1.0;

  chanSigma[k_W4jet13]  = 11.38734 * scale_;
  chanETot[k_W4jet13]   = 1.463355 * scale_;

  chanTheo[k_W4jet13]  =  10.22805 * scale_;
  chanETheo[k_W4jet13] =  ((1.02967+0.96472)/2.0)  * scale_;

// W + 5 jet, 13 TeV

  chanMeasurement[k_W5jet13] = "#geq5j";
  if (exportExeFormat) chanMeasurement[k_W5jet13] = "W5j";
  chanLumi[k_W5jet13] = "2.2 fb^{-1}";

scale_ = 1.0;

  chanSigma[k_W5jet13]  =  2.800503  * scale_;
  chanETot[k_W5jet13]   =  0.4967098 * scale_;
  chanCadi[k_W5jet13] = "SMP-16-005";
  chanPreprint[k_W5jet13] = "1707.05979";
  chanPublication[k_W5jet13] = "PRD 96 (2017) 072005";

  chanTheo[k_W5jet13]  =   2.071021  * scale_;
  chanETheo[k_W5jet13] =   ((0.215587+0.192129)/2.0) * scale_;

// W + 6 jet, 13 TeV

  chanMeasurement[k_W6jet13] = "#geq6j";
  if (exportExeFormat) chanMeasurement[k_W6jet13] = "W6j";
  chanLumi[k_W6jet13] = "2.2 fb^{-1}";
  chanCadi[k_W6jet13] = "SMP-16-005";
  chanPreprint[k_W6jet13] = "1707.05979";
  chanPublication[k_W6jet13] = "PRD 96 (2017) 072005";

scale_ = 1.0;

  chanSigma[k_W6jet13]  =  0.5902639   * scale_;
  chanETot[k_W6jet13]   =  0.1596089 * scale_;

  chanTheo[k_W6jet13]  =   0.4093146  * scale_;
  chanETheo[k_W6jet13] =   ((0.036546+0.026525)/2.0) * scale_;




// W + 1 c jet 7  TeV
// From http://arxiv.org/abs/1310.1138 JHEP 02 (2014) 013
  chanMeasurement[k_W1cjet] = "1c";
  if (exportExeFormat) chanMeasurement[k_W1cjet] = "Wc";
  chanLumi[k_W1cjet] = "5 fb^{-1}";
  chanCadi[k_W1cjet] = "SMP-12-002";
  chanPreprint[k_W1cjet] = "1310.1138";
  chanPublication[k_W1cjet] = "JHEP 02 (2014) 013";

  chanSigma[k_W1cjet]  = 107.7 * scale_;
  chanEStat[k_W1cjet]  = 3.3 * scale_;
  chanESyst[k_W1cjet]   = 6.9 * scale_;
  chanETot[k_W1cjet]  =  sqrt( chanESyst[k_W1cjet]*chanESyst[k_W1cjet] 
			       + 
			       chanEStat[k_W1cjet]*chanEStat[k_W1cjet]
			       );
  chanTheo[k_W1cjet]  = 109.9 * scale_;
chanETheo[k_W1cjet] = 6.4 * scale_;

// W + 1 c jet 8  TeV
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-18-013/index.html
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-18-013/index.html
// https://arxiv.org/abs/2112.00895 Submitted to EPJC


  chanMeasurement[k_W1cjet8] = "1c";
  if (exportExeFormat) chanMeasurement[k_W1cjet8] = "Wc";
  chanLumi[k_W1cjet8] = "19.7 fb^{-1}";
  chanCadi[k_W1cjet8] = "SMP-18-013";
  chanPreprint[k_W1cjet8] = "2112.00895";
  chanPublication[k_W1cjet8] = "Submitted to EPJC";


  chanSigma[k_W1cjet8]  = 117.4 * scale_;
  chanEStat[k_W1cjet8]  = 0.6 * scale_;
  chanESyst[k_W1cjet8]   = 5.4 * scale_;
  chanETot[k_W1cjet8]  =  sqrt( chanESyst[k_W1cjet8]*chanESyst[k_W1cjet8] 
			       + 
			       chanEStat[k_W1cjet8]*chanEStat[k_W1cjet8]
			       );
// charge quarks are > 25 GeV, measurement is fiducial
chanTheo[k_W1cjet8]  = 107.5 * scale_;
chanETheop[k_W1cjet8] = 6.5;
chanETheom[k_W1cjet8] = 6.6;
chanETheo[k_W1cjet8] = 6.55;
// NNPDF NLO MCFM prediction




// W + 1 c jet 13  TeV
// https://arxiv.org/abs/1811.10021 EPJC 79 (2019)269
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-17-014/

  chanMeasurement[k_W1cjet13] = "1c";
  if (exportExeFormat) chanMeasurement[k_W1cjet13] = "Wc";
  chanLumi[k_W1cjet13] = "35.7 fb^{-1}";
  chanCadi[k_W1cjet13] = "SMP-17-014";
  chanPreprint[k_W1cjet13] = "1811.10021";
  chanPublication[k_W1cjet13] = "EPJC 79 (2019) 269";


  chanSigma[k_W1cjet13]  = 1026 * scale_;
  chanEStat[k_W1cjet13]  = 31 * scale_;
  chanESystp[k_W1cjet13]   = 76 * scale_;
  chanESystm[k_W1cjet13]   = 72 * scale_;
  chanESyst[k_W1cjet13]   = 74 * scale_;
  chanETot[k_W1cjet13]  =  sqrt( chanESyst[k_W1cjet13]*chanESyst[k_W1cjet13] 
			       + 
			       chanEStat[k_W1cjet13]*chanEStat[k_W1cjet13]
			       );
// Using NN3.1 PDF - note c quarks are >- 5.0GeV
chanTheo[k_W1cjet13]  = 1030.2 * scale_;
chanETheo[k_W1cjet13] = sqrt(0.053*0.053 +0.027*0.027) * chanTheo[k_W1cjet13];





// W + 2 b jet 7  TeV
// From http://arxiv.org/abs/1312.6608 submitted to PLB
  chanMeasurement[k_W2bjet] = "2b";
  if (exportExeFormat) chanMeasurement[k_W2bjet] = "W2b";
  chanLumi[k_W2bjet] = "5 fb^{-1}";
  chanCadi[k_W2bjet] = "SMP-12-026";
  chanPreprint[k_W2bjet] = "1312.6608";
  chanPublication[k_W2bjet] = "PLB 735 (2014) 204";

  chanSigma[k_W2bjet]  = 0.53 * scale_;
  chanEStat[k_W2bjet]  = 0.05 * scale_;
chanESyst[k_W2bjet]   = sqrt(0.09*0.09 + 0.06*0.06 + 0.01*0.01) * scale_;
  chanETot[k_W2bjet]  =  sqrt( chanESyst[k_W2bjet]*chanESyst[k_W2bjet] 
			       + 
			       chanEStat[k_W2bjet]*chanEStat[k_W2bjet]
			       );
  chanTheo[k_W2bjet]  = 0.55 * scale_;
chanETheo[k_W2bjet] = sqrt(0.03*0.03 + 0.01*0.01 + 0.05*0.05) * scale_;

// W + 2 b jet 8  TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-020/index.html
//https://arxiv.org/abs/1608.07561 EPJC 77 (2017) 92
  chanMeasurement[k_W2bjet8] = "2b";
  if (exportExeFormat) chanMeasurement[k_W2bjet8] = "W2b";
  chanLumi[k_W2bjet8] = "19.8 fb^{-1}";
  chanCadi[k_W2bjet8] = "SMP-14-020";
  chanPreprint[k_W2bjet8] = "1608.07561";
  chanPublication[k_W2bjet8] = "EPJC 77 (2017) 92";


  chanSigma[k_W2bjet8]  = 0.62 * scale_;
  chanEStat[k_W2bjet8]  = 0.03 * scale_;
chanESyst[k_W2bjet8]   = sqrt(0.10*0.10 + 0.06*0.06 + 0.02*0.02) * scale_;
  chanETot[k_W2bjet8]  =  sqrt( chanESyst[k_W2bjet8]*chanESyst[k_W2bjet8] 
			       + 
			       chanEStat[k_W2bjet8]*chanEStat[k_W2bjet8]
			       );
  chanTheo[k_W2bjet8]  = 0.51 * scale_;
chanETheo[k_W2bjet8] = sqrt(0.02*0.02 + 0.06*0.06) * scale_;




// Z + jets 1 jet new!!!!! update reference to http://arxiv.org/abs/1408.3104
// As an estimate NLO uncerainties from http://arxiv.org/abs/1108.2229v2 are used

  chanMeasurement[k_Z1jet] = "#geq1j";
  if (exportExeFormat) chanMeasurement[k_Z1jet] = "Zj";
  chanLumi[k_Z1jet] = "5 fb^{-1}";

scale_ = chanSigma[k_Z];


  chanSigma[k_Z1jet]  = 0.149 * scale_;
  chanEStat[k_Z1jet]  =   0.005 * scale_;
  chanETot[k_Z1jet]   =  sqrt( 0.011*0.011 + 0.022*0.022 + 0.001*0.001 + 0.00596*0.00596) * scale_;
  chanESyst[k_Z1jet]  =  sqrt( chanETot[k_Z1jet]*chanETot[k_Z1jet] 
			       - 
			       chanEStat[k_Z1jet]*chanEStat[k_Z1jet]
			       );
  chanTheo[k_Z1jet]  = 1.49421244859695435e-01 * scale_;
  chanETheo[k_Z1jet] = 0.00537 * scale_;

// Z + jets 2 jets
  chanMeasurement[k_Z2jet] = "#geq2j";
  if (exportExeFormat) chanMeasurement[k_Z2jet] = "Z2j";
  chanLumi[k_Z2jet] = "5 fb^{-1}";

  chanSigma[k_Z2jet]  = 0.027 * scale_;
  chanEStat[k_Z2jet]  =   0.003 * scale_;
  chanETot[k_Z2jet]   =  sqrt( 0.004*0.004 + 0.004*0.004 + 0.001*0.001 + 0.00112*0.00112) * scale_;
  chanESyst[k_Z2jet]  =  sqrt( chanETot[k_Z2jet]*chanETot[k_Z2jet] 
			       - 
			       chanEStat[k_Z2jet]*chanEStat[k_Z2jet]
			       );
  chanTheo[k_Z2jet]  = 2.87458151578903198e-02 * scale_;
  chanETheo[k_Z2jet] = 0.000944 * scale_;

// Z + jets 3 jets
  chanMeasurement[k_Z3jet] = "#geq3j";
  if (exportExeFormat) chanMeasurement[k_Z3jet] = "Z3j";
  chanLumi[k_Z3jet] = "5 fb^{-1}";

  chanSigma[k_Z3jet]  = 0.0042 * scale_;
  chanEStat[k_Z3jet]  =   0.0011 * scale_;
  chanETot[k_Z3jet]   =  sqrt( 0.0012*0.0012 + 0.0008*0.0008 + 0.0003*0.0003 + 0.000168*0.000168) * scale_;
  chanESyst[k_Z3jet]  =  sqrt( chanETot[k_Z3jet]*chanETot[k_Z3jet] 
			       - 
			       chanEStat[k_Z3jet]*chanEStat[k_Z3jet]
			       );
  chanTheo[k_Z3jet]  = 5.09246997535228729e-03 * scale_;
  chanETheo[k_Z3jet] = 0.000215 * scale_;

// Z + jets 4 jet
  chanMeasurement[k_Z4jet] = "#geq4j";
  if (exportExeFormat) chanMeasurement[k_Z4jet] = "Z4j";
  chanLumi[k_Z4jet] = "5 fb^{-1}";

  chanSigma[k_Z4jet]  = 0.00087 * scale_;
  chanEStat[k_Z4jet]  =   0.00050 * scale_;
  chanETot[k_Z4jet]   =  sqrt( 0.00056*0.00056 + 0.00017*0.00017 + 0.00010*0.00010 + 0.0000348*0.0000348) * scale_;
  chanESyst[k_Z4jet]  =  sqrt( chanETot[k_Z4jet]*chanETot[k_Z4jet] 
			       - 
			       chanEStat[k_Z4jet]*chanEStat[k_Z4jet]
			       );
  chanTheo[k_Z4jet]  = 9.34239011257886887e-04 * scale_;
  chanETheo[k_Z4jet] = 0.0000837 * scale_;

// new Z + jets 1 jet TeV
// NL0 uncertainties with Sherpa are used
// cross section includes Z->ll with acceptance.
// http://cds.cern.ch/record/1667906, CMS-PAS-SMP-12-017
// https://arxiv.org/abs/1408.3104
// Phys. Rev. D 91 (2015) 052008
// Number from private communication with fabio.cossutti@cern.ch
// Updated from hep-data

  chanMeasurement[k_Z1jetn] = "#geq1j";
  if (exportExeFormat) chanMeasurement[k_Z1jetn] = "Zj";
  chanLumi[k_Z1jetn] = "5 fb^{-1}";
  chanCadi[k_Z1jetn] = "SMP-12-017";
  chanPreprint[k_Z1jetn] = "1408.3104";
  chanPublication[k_Z1jetn] = "PRD 91 (2015) 052008";

scale_ = 1.0;

  chanSigma[k_Z1jetn]  = 61.43 * scale_;
  chanEStat[k_Z1jetn]  =   3.19 * scale_;
  chanETot[k_Z1jetn]   =   3.19 * scale_;
  chanESyst[k_Z1jetn]  =  sqrt( chanETot[k_Z1jetn]*chanETot[k_Z1jetn] 
			       - 
			       chanEStat[k_Z1jetn]*chanEStat[k_Z1jetn]
			       );
  chanTheo[k_Z1jetn]  = 63.5 * scale_;
  chanETheo[k_Z1jetn] =  sqrt(1.95*1.95 +1.8*1.8 )* scale_;
// + 1.8 - 2.1, +1.7 - 1.9

// new Z + jetns 2 jetns  TeV
  chanMeasurement[k_Z2jetn] = "#geq2j";
  if (exportExeFormat) chanMeasurement[k_Z2jetn] = "Z2j";
  chanLumi[k_Z2jetn] = "5 fb^{-1}";
  chanCadi[k_Z2jetn] = "SMP-12-017";
  chanPreprint[k_Z2jetn] = "1408.3104";
  chanPublication[k_Z2jetn] = "PRD 91 (2015) 052008";

  chanSigma[k_Z2jetn]  = 12.91 * scale_;
  chanEStat[k_Z2jetn]  =  1.54 * scale_;
  chanETot[k_Z2jetn]   =  1.54 * scale_;
  chanESyst[k_Z2jetn]  =  sqrt( chanETot[k_Z2jetn]*chanETot[k_Z2jetn] 
			       - 
			       chanEStat[k_Z2jetn]*chanEStat[k_Z2jetn]
			       );
  chanTheo[k_Z2jetn]  = 11.5 * scale_;
chanETheo[k_Z2jetn] = sqrt(1.8*1.8 + 0.55*0.55) * scale_;
// +2.1 - 1.5, _0.5 -0.6

// new Z + jetns 3 jetn  TeV
  chanMeasurement[k_Z3jetn] = "#geq3j";
if (exportExeFormat) chanMeasurement[k_Z3jetn] = "Z3j";
  chanLumi[k_Z3jetn] = "5 fb^{-1}";
  chanCadi[k_Z3jetn] = "SMP-12-017";
  chanPreprint[k_Z3jetn] = "1408.3104";
  chanPublication[k_Z3jetn] = "PRD 91 (2015) 052008";

  chanSigma[k_Z3jetn]  = 2.50 * scale_;
  chanEStat[k_Z3jetn]  =   0.38 * scale_;
  chanETot[k_Z3jetn]   =  0.38 * scale_;
  chanESyst[k_Z3jetn]  =  sqrt( chanETot[k_Z3jetn]*chanETot[k_Z3jetn] 
			       - 
			       chanEStat[k_Z3jetn]*chanEStat[k_Z3jetn]
			       );
  chanTheo[k_Z3jetn]  = 2.1 * scale_;
chanETheo[k_Z3jetn] = sqrt(0.6*0.6 + 0.15*0.15) * scale_;
// +0.7 - 0.5, +0.1 - 0.2

// new Z + jetns 4 jetn  TeV
  chanMeasurement[k_Z4jetn] = "#geq4j";
  if (exportExeFormat) chanMeasurement[k_Z4jetn] = "Z4j";
  chanLumi[k_Z4jetn] = "5 fb^{-1}";
  chanCadi[k_Z4jetn] = "SMP-12-017";
  chanPreprint[k_Z4jetn] = "1408.3104";
  chanPublication[k_Z4jetn] = "PRD 91 (2015) 052008";

  chanSigma[k_Z4jetn]  = 0.474 * scale_;
  chanEStat[k_Z4jetn]  =   0.082 * scale_;
  chanETot[k_Z4jetn]   =  0.082 * scale_;
  chanESyst[k_Z4jetn]  =  sqrt( chanETot[k_Z4jetn]*chanETot[k_Z4jetn] 
			       - 
			       chanEStat[k_Z4jetn]*chanEStat[k_Z4jetn]
			       );
  chanTheo[k_Z4jetn]  = 0.36 * scale_;
chanETheo[k_Z4jetn] = sqrt( 0.145*0.145 + 0.03*0.03) * scale_;
// +0.15 - 0.14, +0.03 - 0.03

// new Z + jetns 5 jetn  TeV
  chanMeasurement[k_Z5jetn] = "#geq5j";
  if (exportExeFormat) chanMeasurement[k_Z5jetn] = "Z5j";
  chanLumi[k_Z5jetn] = "5 fb^{-1}";
  chanCadi[k_Z5jetn] = "SMP-12-017";
  chanPreprint[k_Z5jetn] = "1408.3104";
  chanPublication[k_Z5jetn] = "PRD 91 (2015) 052008";

  chanSigma[k_Z5jetn]  = 0.079 * scale_;
  chanEStat[k_Z5jetn]  =   0.015 * scale_;
  chanETot[k_Z5jetn]   =  0.015 * scale_;
  chanESyst[k_Z5jetn]  =  sqrt( chanETot[k_Z5jetn]*chanETot[k_Z5jetn] 
			       - 
			       chanEStat[k_Z5jetn]*chanEStat[k_Z5jetn]
			       );
  chanTheo[k_Z5jetn]  = 0.067 * scale_;
chanETheo[k_Z5jetn] = sqrt( 0.011*0.011 + 0.026*0.026) * scale_;
// two more exp bins
// 0.079 ± 0.015



// new Z + jetns 6 jetn  TeV
  chanMeasurement[k_Z6jetn] = "#geq6j";
  if (exportExeFormat) chanMeasurement[k_Z6jetn] = "Z6j";
  chanLumi[k_Z6jetn] = "5 fb^{-1}";
  chanCadi[k_Z6jetn] = "SMP-12-017";
  chanPreprint[k_Z6jetn] = "1408.3104";
  chanPublication[k_Z6jetn] = "PRD 91 (2015) 052008";

  chanSigma[k_Z6jetn]  = 0.0116 * scale_;
  chanEStat[k_Z6jetn]  =   0.0037 * scale_;
  chanETot[k_Z6jetn]   =  0.0037 * scale_;
  chanESyst[k_Z6jetn]  =  sqrt( chanETot[k_Z6jetn]*chanETot[k_Z6jetn] 
			       - 
			       chanEStat[k_Z6jetn]*chanEStat[k_Z6jetn]
			       );
  chanTheo[k_Z6jetn]  = 0.0139 * scale_;
chanETheo[k_Z6jetn] = sqrt( 0.0022*0.0022 + 0.0097*0.0097) * scale_;
// two more exp bins
// 0.0116 ± 0.0037





// !!!!! include 8 TeV Z + jets.  Need numbers
// CMS PAS 13 007
// Replaced with SMP-14-013
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-013/index.html
// https://arxiv.org/abs/1611.03844 submitted to JHEP
    // !!!!! sum to inclusive numbers?


// 1 jet exclusive
  chanMeasurement[k_Z1jet8] = "#geq1j";
  if (exportExeFormat) chanMeasurement[k_Z1jet8] = "Zj";
  chanLumi[k_Z1jet8] = "19.6 fb^{-1}";
  chanCadi[k_Z1jet8] = "SMP-14-013";
  chanPreprint[k_Z1jet8] = "1611.03844";
  chanPublication[k_Z1jet8] = "JHEP 04 (2017) 022";


  chanSigma[k_Z1jet8]  = 59.9 * scale_;
  chanEStat[k_Z1jet8]  =   0.1 * scale_;
  chanESyst[k_Z1jet8]   =   3.8 * scale_;
  chanETot[k_Z1jet8]  =  sqrt( chanESyst[k_Z1jet8]*chanESyst[k_Z1jet8] 
			       + 
			       chanEStat[k_Z1jet8]*chanEStat[k_Z1jet8]
			       );

  chanTheo[k_Z1jet8]  = 61.0 * scale_;
  chanETheop[k_Z1jet8] =  5.3 * scale_;
  chanETheom[k_Z1jet8] =  5.4 * scale_;
  chanETheo[k_Z1jet8] = ((chanETheop[k_Z1jet8]+chanETheom[k_Z1jet8])/2.0) * scale_;

// 2 jet exclusive
  chanMeasurement[k_Z2jet8] = "#geq2j";
  if (exportExeFormat) chanMeasurement[k_Z2jet8] = "Z2j";
  chanLumi[k_Z2jet8] = "19.6 fb^{-1}";
  chanCadi[k_Z2jet8] = "SMP-14-013";
  chanPreprint[k_Z2jet8] = "1611.03844";
  chanPublication[k_Z2jet8] = "JHEP 04 (2017) 022";

scale_ = 1.0;

  chanSigma[k_Z2jet8]  = 12.6 * scale_;
  chanEStat[k_Z2jet8]  =   0.0 * scale_;
  chanESyst[k_Z2jet8]   =   1.2 * scale_;
  chanETot[k_Z2jet8]  =  sqrt( chanESyst[k_Z2jet8]*chanESyst[k_Z2jet8] 
			       + 
			       chanEStat[k_Z2jet8]*chanEStat[k_Z2jet8]
			       );
  chanTheo[k_Z2jet8]  = 12.5 * scale_;
  chanETheop[k_Z2jet8] =  1.3 * scale_;
  chanETheom[k_Z2jet8] =  1.4 * scale_;
  chanETheo[k_Z2jet8] = ((chanETheop[k_Z2jet8]+chanETheom[k_Z2jet8])/2.0) * scale_;


// 3 jet exclusive
  chanMeasurement[k_Z3jet8] = "#geq3j";
  if (exportExeFormat) chanMeasurement[k_Z3jet8] = "Z3j";
  chanLumi[k_Z3jet8] = "19.6 fb^{-1}";
  chanCadi[k_Z3jet8] = "SMP-14-013";
  chanPreprint[k_Z3jet8] = "1611.03844";
  chanPublication[k_Z3jet8] = "JHEP 04 (2017) 022";

scale_ = 1.0;

  chanSigma[k_Z3jet8]  = 2.46 * scale_;
  chanEStat[k_Z3jet8]  =   0.02 * scale_;
  chanESyst[k_Z3jet8]   =   0.29 * scale_;
  chanETot[k_Z3jet8]  =  sqrt( chanESyst[k_Z3jet8]*chanESyst[k_Z3jet8] 
			       + 
			       chanEStat[k_Z3jet8]*chanEStat[k_Z3jet8]
			       );
  chanTheo[k_Z3jet8]  = 2.27 * scale_;
  chanETheop[k_Z3jet8] =  0.32 * scale_;
  chanETheom[k_Z3jet8] =  0.32 * scale_;
  chanETheo[k_Z3jet8] = ((chanETheop[k_Z3jet8]+chanETheom[k_Z3jet8])/2.0) * scale_;

// 4 jet exclusive
  chanMeasurement[k_Z4jet8] = "#geq4j";
  if (exportExeFormat) chanMeasurement[k_Z4jet8] = "Z4j";
  chanLumi[k_Z4jet8] = "19.6 fb^{-1}";
  chanCadi[k_Z4jet8] = "SMP-14-013";
  chanPreprint[k_Z4jet8] = "1611.03844";
  chanPublication[k_Z4jet8] = "JHEP 04 (2017) 022";

scale_ = 1.0;

  chanSigma[k_Z4jet8]  = 0.471 * scale_;
  chanEStat[k_Z4jet8]  =   0.007 * scale_;
  chanESyst[k_Z4jet8]   =   0.075 * scale_;
  chanETot[k_Z4jet8]  =  sqrt( chanESyst[k_Z4jet8]*chanESyst[k_Z4jet8] 
			       + 
			       chanEStat[k_Z4jet8]*chanEStat[k_Z4jet8]
			       );
  chanTheo[k_Z4jet8]  = 0.385 * scale_;
  chanETheop[k_Z4jet8] =  0.049 * scale_;
  chanETheom[k_Z4jet8] =  0.053 * scale_;
 chanETheo[k_Z4jet8] = ((chanETheop[k_Z4jet8]+chanETheom[k_Z4jet8])/2.0) * scale_;

// 5 jet exclusive
  chanMeasurement[k_Z5jet8] = "#geq5j";
  if (exportExeFormat) chanMeasurement[k_Z5jet8] = "Z5j";
  chanLumi[k_Z5jet8] = "19.6 fb^{-1}";
  chanCadi[k_Z5jet8] = "SMP-14-013";
  chanPreprint[k_Z5jet8] = "1611.03844";
  chanPublication[k_Z5jet8] = "JHEP 04 (2017) 022";

scale_ = 1.0;

  chanSigma[k_Z5jet8]  = 0.0901 * scale_;
  chanEStat[k_Z5jet8]  =   0.003 * scale_;
  chanESyst[k_Z5jet8]   =   0.018 * scale_;
  chanETot[k_Z5jet8]  =  sqrt( chanESyst[k_Z5jet8]*chanESyst[k_Z5jet8] 
			       + 
			       chanEStat[k_Z5jet8]*chanEStat[k_Z5jet8]
			       );
  chanTheo[k_Z5jet8]  = 0.0622 * scale_;
  chanETheop[k_Z5jet8] =  0.0073 * scale_;
  chanETheom[k_Z5jet8] =  0.0084 * scale_;
  chanETheo[k_Z5jet8] = ((chanETheop[k_Z5jet8]+chanETheom[k_Z5jet8])/2.0) * scale_;

// 6 jet exclusive
  chanMeasurement[k_Z6jet8] = "#geq6j";
  if (exportExeFormat) chanMeasurement[k_Z6jet8] = "Z6j";
  chanLumi[k_Z6jet8] = "19.6 fb^{-1}";
  chanCadi[k_Z6jet8] = "SMP-14-013";
  chanPreprint[k_Z6jet8] = "1611.03844";
  chanPublication[k_Z6jet8] = "JHEP 04 (2017) 022";

scale_ = 1.0;

  chanSigma[k_Z6jet8]  = 0.0143 * scale_;
  chanEStat[k_Z6jet8]  =   0.0013 * scale_;
  chanESyst[k_Z6jet8]   =   0.0045 * scale_;
  chanETot[k_Z6jet8]  =  sqrt( chanESyst[k_Z6jet8]*chanESyst[k_Z6jet8] 
			       + 
			       chanEStat[k_Z6jet8]*chanEStat[k_Z6jet8]
			       );
  chanTheo[k_Z6jet8]  = 0.0096 * scale_;
  chanETheop[k_Z6jet8] =  0.0011 * scale_;
  chanETheom[k_Z6jet8] =  0.0013 * scale_;
  chanETheo[k_Z6jet8] = ((chanETheop[k_Z6jet8]+chanETheom[k_Z6jet8])/2.0) * scale_;

  // 7 jet exclusive
  chanMeasurement[k_Z7jet8] = "#geq7j";
  if (exportExeFormat) chanMeasurement[k_Z7jet8] = "Z7j";
  chanLumi[k_Z7jet8] = "19.6 fb^{-1}";
  chanCadi[k_Z7jet8] = "SMP-14-013";
  chanPreprint[k_Z7jet8] = "1611.03844";
  chanPublication[k_Z7jet8] = "JHEP 04 (2017) 022";

scale_ = 1.0;

  chanSigma[k_Z7jet8]  = 0.00230 * scale_;
  chanEStat[k_Z7jet8]  =   0.00060  * scale_;
  chanESyst[k_Z7jet8]   =   0.00051  * scale_;
  chanETot[k_Z7jet8]  =  sqrt( chanESyst[k_Z7jet8]*chanESyst[k_Z7jet8] 
			       + 
			       chanEStat[k_Z7jet8]*chanEStat[k_Z7jet8]
			       );
  chanTheo[k_Z7jet8]  = 0.00157 * scale_;
  chanETheop[k_Z7jet8] =  0.00013 * scale_;
  chanETheom[k_Z7jet8] =  0.00019 * scale_;
  chanETheo[k_Z7jet8] = ((chanETheop[k_Z7jet8]+chanETheom[k_Z7jet8])/2.0) * scale_;


chanSigma[k_Z1jet8] = chanSigma[k_Z1jet8] +  chanSigma[k_Z2jet8] +  chanSigma[k_Z3jet8] +  chanSigma[k_Z4jet8] + chanSigma[k_Z5jet8] +  chanSigma[k_Z6jet8] +  chanSigma[k_Z7jet8];

chanSigma[k_Z2jet8] = chanSigma[k_Z2jet8] +  chanSigma[k_Z3jet8] +  chanSigma[k_Z4jet8] + chanSigma[k_Z5jet8] +  chanSigma[k_Z6jet8] +  chanSigma[k_Z7jet8];

chanSigma[k_Z3jet8] = chanSigma[k_Z3jet8] +  chanSigma[k_Z4jet8] + chanSigma[k_Z5jet8] +  chanSigma[k_Z6jet8] +  chanSigma[k_Z7jet8];

chanSigma[k_Z4jet8] = chanSigma[k_Z4jet8] + chanSigma[k_Z5jet8] +  chanSigma[k_Z6jet8] +  chanSigma[k_Z7jet8];

chanSigma[k_Z5jet8] = chanSigma[k_Z5jet8] +  chanSigma[k_Z6jet8] +  chanSigma[k_Z7jet8];

chanSigma[k_Z6jet8] = chanSigma[k_Z6jet8] +  chanSigma[k_Z7jet8];



chanTheo[k_Z1jet8] = chanTheo[k_Z1jet8] +  chanTheo[k_Z2jet8] +  chanTheo[k_Z3jet8] +  chanTheo[k_Z4jet8] + chanTheo[k_Z5jet8] +  chanTheo[k_Z6jet8] +  chanTheo[k_Z7jet8];

chanTheo[k_Z2jet8] = chanTheo[k_Z2jet8] +  chanTheo[k_Z3jet8] +  chanTheo[k_Z4jet8] + chanTheo[k_Z5jet8] +  chanTheo[k_Z6jet8] +  chanTheo[k_Z7jet8];

chanTheo[k_Z3jet8] = chanTheo[k_Z3jet8] +  chanTheo[k_Z4jet8] + chanTheo[k_Z5jet8] +  chanTheo[k_Z6jet8] +  chanTheo[k_Z7jet8];

chanTheo[k_Z4jet8] = chanTheo[k_Z4jet8] + chanTheo[k_Z5jet8] +  chanTheo[k_Z6jet8] +  chanTheo[k_Z7jet8];

chanTheo[k_Z5jet8] = chanTheo[k_Z5jet8] +  chanTheo[k_Z6jet8] +  chanTheo[k_Z7jet8];

chanTheo[k_Z6jet8] = chanTheo[k_Z6jet8] +  chanTheo[k_Z7jet8];




    // Z+jets 13 TeV
    // https://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-15-010/index.html
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-16-015/
// https://arxiv.org/abs/1804.05252 EPJC 78 (2018) 965
    // Theory numbers Private communication from Philippe Gras <philippe.gras@cern.ch>

// 1 jet inclusive
  chanMeasurement[k_Z1jet13] = "#geq1j";
  if (exportExeFormat) chanMeasurement[k_Z1jet13] = "Zj";
  chanLumi[k_Z1jet13] = "2.19 fb^{-1}";
  chanCadi[k_Z1jet13] = "SMP-16-015";
  chanPreprint[k_Z1jet13] = "1804.05252";
  chanPublication[k_Z1jet13] = "EPJC 78 (2018) 965";


  chanSigma[k_Z1jet13]  = 126.2 * scale_;
  chanEStat[k_Z1jet13]  =   0.0023 * chanSigma[k_Z1jet13];
  chanETot[k_Z1jet13]   =   0.057 * chanSigma[k_Z1jet13];
  chanESyst[k_Z1jet13]  =  sqrt( chanETot[k_Z1jet13]*chanETot[k_Z1jet13] 
			       - 
			       chanEStat[k_Z1jet13]*chanEStat[k_Z1jet13]
			       );
  chanTheo[k_Z1jet13]  = 132.149 * scale_;
  chanETheop[k_Z1jet13] =  9.17* scale_;
  chanETheom[k_Z1jet13] =  9.51* scale_;
  chanETheo[k_Z1jet13] =  0.5 * (chanETheop[k_Z1jet13]+chanETheom[k_Z1jet13])* scale_;

// 2 jet inclusive
  chanMeasurement[k_Z2jet13] = "#geq2j";
  if (exportExeFormat) chanMeasurement[k_Z2jet13] = "Z2j";
  chanLumi[k_Z2jet13] = "2.19 fb^{-1}";
  chanCadi[k_Z2jet13] = "SMP-16-015";
  chanPreprint[k_Z2jet13] = "1804.05252";
  chanPublication[k_Z2jet13] = "EPJC 78 (2018) 965";

scale_ = 1.0;

  chanSigma[k_Z2jet13]  = 28.3 * scale_;
  chanEStat[k_Z2jet13]  =   0.0052 * chanSigma[k_Z2jet13];
  chanETot[k_Z2jet13]   =   0.08 * chanSigma[k_Z2jet13];
  chanESyst[k_Z2jet13]  =  sqrt( chanETot[k_Z2jet13]*chanETot[k_Z2jet13] 
			       - 
			       chanEStat[k_Z2jet13]*chanEStat[k_Z2jet13]
			       );
  chanTheo[k_Z2jet13]  = 29.6852 * scale_;
  chanETheop[k_Z2jet13] =  2.53 * scale_;
  chanETheom[k_Z2jet13] =  2.78 * scale_;
  chanETheo[k_Z2jet13] =  0.5 * (chanETheop[k_Z2jet13]+chanETheom[k_Z2jet13])* scale_;




// 3 jet inclusive
  chanMeasurement[k_Z3jet13] = "#geq3j";
  if (exportExeFormat) chanMeasurement[k_Z3jet13] = "Z3j";
  chanLumi[k_Z3jet13] = "2.19 fb^{-1}";
  chanCadi[k_Z3jet13] = "SMP-16-015";
  chanPreprint[k_Z3jet13] = "1804.05252";
  chanPublication[k_Z3jet13] = "EPJC 78 (2018) 965";

scale_ = 1.0;

  chanSigma[k_Z3jet13]  = 6.01 * scale_;
  chanEStat[k_Z3jet13]  =   0.011 * chanSigma[k_Z3jet13];
  chanETot[k_Z3jet13]   =   0.11 * chanSigma[k_Z3jet13];
  chanESyst[k_Z3jet13]  =  sqrt( chanETot[k_Z3jet13]*chanETot[k_Z3jet13] 
			       - 
			       chanEStat[k_Z3jet13]*chanEStat[k_Z3jet13]
			       );
  chanTheo[k_Z3jet13]  = 6.35439 * scale_;
  chanETheop[k_Z3jet13] =  0.655 * scale_;
  chanETheom[k_Z3jet13] =  0.645 * scale_;
  chanETheo[k_Z3jet13] =  0.5 * (chanETheop[k_Z3jet13]+chanETheom[k_Z3jet13])* scale_;

// 4 jet inclusive
  chanMeasurement[k_Z4jet13] = "#geq4j";
  if (exportExeFormat) chanMeasurement[k_Z4jet13] = "Z4j";
  chanLumi[k_Z4jet13] = "2.19 fb^{-1}";
  chanCadi[k_Z4jet13] = "SMP-16-015";
  chanPreprint[k_Z4jet13] = "1804.05252";
  chanPublication[k_Z4jet13] = "EPJC 78 (2018) 965";

scale_ = 1.0;

  chanSigma[k_Z4jet13]  = 1.33 * scale_;
  chanEStat[k_Z4jet13]  =   0.028 * chanSigma[k_Z4jet13];
  chanETot[k_Z4jet13]   =   0.12 * chanSigma[k_Z4jet13];
  chanESyst[k_Z4jet13]  =  sqrt( chanETot[k_Z4jet13]*chanETot[k_Z4jet13] 
			       - 
			       chanEStat[k_Z4jet13]*chanEStat[k_Z4jet13]
			       );
  chanTheo[k_Z4jet13]  = 1.26 * scale_;
  chanETheop[k_Z4jet13] =  0.121 * scale_;
  chanETheom[k_Z4jet13] =  0.124 * scale_;
  chanETheo[k_Z4jet13] =  0.5 * (chanETheop[k_Z4jet13]+chanETheom[k_Z4jet13])* scale_;


// 5 jet inclusive
  chanMeasurement[k_Z5jet13] = "#geq5j";
  if (exportExeFormat) chanMeasurement[k_Z5jet13] = "Z5j";
  chanLumi[k_Z5jet13] = "2.19 fb^{-1}";
  chanCadi[k_Z5jet13] = "SMP-16-015";
  chanPreprint[k_Z5jet13] = "1804.05252";
  chanPublication[k_Z5jet13] = "EPJC 78 (2018) 965";

scale_ = 1.0;

  chanSigma[k_Z5jet13]  = 0.320 * scale_;
  chanEStat[k_Z5jet13]  =   0.048 * chanSigma[k_Z5jet13];
  chanETot[k_Z5jet13]   =   0.14 * chanSigma[k_Z5jet13];
  chanESyst[k_Z5jet13]  =  sqrt( chanETot[k_Z5jet13]*chanETot[k_Z5jet13] 
			       - 
			       chanEStat[k_Z5jet13]*chanEStat[k_Z5jet13]
			       );
  chanTheo[k_Z5jet13]  = 0.262 * scale_;
  chanETheop[k_Z5jet13] =  0.0296 * scale_;
  chanETheom[k_Z5jet13] =  0.0296 * scale_;
  chanETheo[k_Z5jet13] =  0.5 * (chanETheop[k_Z5jet13]+chanETheom[k_Z5jet13])* scale_;

// 6 jet inclusive
  chanMeasurement[k_Z6jet13] = "#geq6j";
  if (exportExeFormat) chanMeasurement[k_Z6jet13] = "Z6j";
  chanLumi[k_Z6jet13] = "2.19 fb^{-1}";
  chanCadi[k_Z6jet13] = "SMP-16-015";
  chanPreprint[k_Z6jet13] = "1804.05252";
  chanPublication[k_Z6jet13] = "EPJC 78 (2018) 965";

scale_ = 1.0;

  chanSigma[k_Z6jet13]  = 0.045 * scale_;
  chanEStat[k_Z6jet13]  =   0.15 * chanSigma[k_Z6jet13];
  chanETot[k_Z6jet13]   =   0.24 * chanSigma[k_Z6jet13];
  chanESyst[k_Z6jet13]  =  sqrt( chanETot[k_Z6jet13]*chanETot[k_Z6jet13] 
			       - 
			       chanEStat[k_Z6jet13]*chanEStat[k_Z6jet13]
			       );
  chanTheo[k_Z6jet13]  = 0.0552 * scale_;
  chanETheop[k_Z6jet13] =  0.00544 * scale_;
  chanETheom[k_Z6jet13] =  0.00582 * scale_;
  chanETheo[k_Z6jet13] =  0.5 * (chanETheop[k_Z6jet13]+chanETheom[k_Z6jet13])* scale_;


// Z + 1 c jet 8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-15-009/index.html
// https://cds.cern.ch/record/2202823
// Updated to
// https://arxiv.org/abs/1711.02143 Eur. Phys. J. C. 78 (2018) 287
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-15-009/index.html
// May want to change to remove Z BF
  chanMeasurement[k_Z1cjet8] = "1c";
  if (exportExeFormat) chanMeasurement[k_Z1cjet8] = "Zc";
  chanLumi[k_Z1cjet8] = "19.6 fb^{-1}";
  chanCadi[k_Z1cjet8] = "SMP-15-009";
  chanPreprint[k_Z1cjet8] = "1711.02143";
  chanPublication[k_Z1cjet8] = "EPJC 78 (2018) 287";

chanSigma[k_Z1cjet8]  = 8.8 * scale_;
  chanEStat[k_Z1cjet8]  =   0.5 * scale_;
  chanESyst[k_Z1cjet8]   =  0.6 * scale_;
  chanETot[k_Z1cjet8]  =  sqrt( chanESyst[k_Z1cjet8]*chanESyst[k_Z1cjet8] 
			       + 
			       chanEStat[k_Z1cjet8]*chanEStat[k_Z1cjet8]
			       );
  chanTheo[k_Z1cjet8]  = 9.46 * scale_;
chanETheo[k_Z1cjet8] = sqrt(0.04*0.04 + 0.15*0.15 + 0.50*0.50) * scale_;
// NLO Madgraph stat + PDF + scale


// Z + c jet 13 TeV
// https://arxiv.org/abs/2012.04119 JHEP 04 (2021) 109
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-19-011/

  chanMeasurement[k_Z1cjet13] = "1c";
  if (exportExeFormat) chanMeasurement[k_Z1cjet13] = "Zc";
  chanLumi[k_Z1cjet13] = "35.9 fb^{-1}";
  chanCadi[k_Z1cjet13] = "SMP-19-011";
  chanPreprint[k_Z1cjet13] = "2012.04119";
  chanPublication[k_Z1cjet13] = "JHEP 04 (2021) 109";

// Other fiducial X+jet measurement include Z->ll BF, value from the paper
scale_ = scale_*0.0336;


chanSigma[k_Z1cjet13]  = 405.4 * scale_;
  chanEStat[k_Z1cjet13]  =   5.6 * scale_;
chanESyst[k_Z1cjet13]   =  sqrt(23.4*23.4+3.7*3.7) * scale_;
  chanETot[k_Z1cjet13]  =  sqrt( chanESyst[k_Z1cjet13]*chanESyst[k_Z1cjet13] 
			       + 
			       chanEStat[k_Z1cjet13]*chanEStat[k_Z1cjet13]
			       );
  chanTheo[k_Z1cjet13]  = 524.9 * scale_;
chanETheo[k_Z1cjet13] = 11.7 * scale_;
// NLO Madgraph scale  + pdf


scale_ = scale_/0.0336;


// new Z + 1 b jet  7  TeV SMP-13-004
// From http://arxiv.org/abs/1402.1521, JHEP 06 (2014) 120
  chanMeasurement[k_Z1bjet] = "#geq1b";
  if (exportExeFormat) chanMeasurement[k_Z1bjet] = "Z1b";
  chanLumi[k_Z1bjet] = "5 fb^{-1}";
  chanCadi[k_Z1bjet] = "SMP-13-004";
  chanPreprint[k_Z1bjet] = "1402.1521";
  chanPublication[k_Z1bjet] = "JHEP 06 (2014) 120";

  chanSigma[k_Z1bjet]  = 3.88 * scale_;
  chanEStat[k_Z1bjet]  =   0.02 * scale_;
  chanETot[k_Z1bjet]   =  0.22 * scale_;
  chanESyst[k_Z1bjet]  =  sqrt( chanETot[k_Z1bjet]*chanETot[k_Z1bjet] 
			       - 
			       chanEStat[k_Z1bjet]*chanEStat[k_Z1bjet]
			       );
  chanTheo[k_Z1bjet]  = 3.99 * scale_;
chanETheo[k_Z1bjet] = 0.27 * scale_;
// a MC@NL0 5 flavor

// new Z + 2 b jet  7  TeV
  chanMeasurement[k_Z2bjet] = "#geq2b";
  if (exportExeFormat) chanMeasurement[k_Z2bjet] = "Z2b";
  chanLumi[k_Z2bjet] = "5 fb^{-1}";
  chanCadi[k_Z2bjet] = "SMP-13-004";
  chanPreprint[k_Z2bjet] = "1402.1521";
  chanPublication[k_Z2bjet] = "JHEP 06 (2014) 120";

  chanSigma[k_Z2bjet]  = 0.36 * scale_;
  chanEStat[k_Z2bjet]  =   0.01 * scale_;
  chanETot[k_Z2bjet]   =  0.07 * scale_;
  chanESyst[k_Z2bjet]  =  sqrt( chanETot[k_Z2bjet]*chanETot[k_Z2bjet] 
			       - 
			       chanEStat[k_Z2bjet]*chanEStat[k_Z2bjet]
			       );
  chanTheo[k_Z2bjet]  = 0.29 * scale_;
chanETheo[k_Z2bjet] = 0.04 * scale_;
// a MC@NL0 5 flavor

// new Z + 1 b jet  8  TeV
//http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-010/index.html
// From  http://arxiv.org/abs/1611.06507 Submitted to Eur. Phys. J. C 77 (2017) 751
  chanMeasurement[k_Z1bjet8] = "#geq1b";
  if (exportExeFormat) chanMeasurement[k_Z1bjet8] = "Z1b";
  chanLumi[k_Z1bjet8] = "19.6 fb^{-1}";
  chanCadi[k_Z1bjet8] = "SMP-14-010";
  chanPreprint[k_Z1bjet8] = "1611.06507";
  chanPublication[k_Z1bjet8] = "EPJC 77 (2017) 751";


  chanSigma[k_Z1bjet8]  = 3.55 * scale_;
  chanEStat[k_Z1bjet8]  =   0.12 * scale_;
  chanETot[k_Z1bjet8]   =  0.21 * scale_;
  chanESyst[k_Z1bjet8]  =  sqrt( chanETot[k_Z1bjet8]*chanETot[k_Z1bjet8] 
			       - 
			       chanEStat[k_Z1bjet8]*chanEStat[k_Z1bjet8]
			       );
  chanTheo[k_Z1bjet8]  = 4.23 * scale_;
chanETheop[k_Z1bjet8] = 0.27 * scale_;
chanETheom[k_Z1bjet8] = 0.37 * scale_;
chanETheo[k_Z1bjet8] = ((chanETheop[k_Z1bjet8]+chanETheom[k_Z1bjet8])/2.0) * scale_;
// a MC@NL0 5 flavor

// new Z + 2 b jet  8  TeV
chanMeasurement[k_Z2bjet8] = "#geq2b";
  if (exportExeFormat) chanMeasurement[k_Z2bjet8] = "Z2b";
  chanLumi[k_Z2bjet8] = "19.6 fb^{-1}";
  chanCadi[k_Z2bjet8] = "SMP-14-010";
  chanPreprint[k_Z2bjet8] = "1611.06507";
  chanPublication[k_Z2bjet8] = "EPJC 77 (2017) 751";

  chanSigma[k_Z2bjet8]  = 0.331 * scale_;
  chanEStat[k_Z2bjet8]  =   0.011 * scale_;
  chanETot[k_Z2bjet8]   =  0.035* scale_;
  chanESyst[k_Z2bjet8]  =  sqrt( chanETot[k_Z2bjet8]*chanETot[k_Z2bjet8] 
			       - 
			       chanEStat[k_Z2bjet8]*chanEStat[k_Z2bjet8]
			       );
  chanTheo[k_Z2bjet8]  = 0.356 * scale_;
chanETheop[k_Z2bjet8] = 0.030 * scale_;
chanETheom[k_Z2bjet8] = 0.031 * scale_;
chanETheo[k_Z2bjet8] = ((chanETheop[k_Z2bjet8]+chanETheom[k_Z2bjet8])/2.0) * scale_;


// Z + 1 b jet 13 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-20-015/
// https://arxiv.org/abs/2112.09659 Submitted to Phys. Rev. D
  chanMeasurement[k_Z1bjet13] = "#geq1b";
  if (exportExeFormat) chanMeasurement[k_Z1bjet13] = "Z1b";
  chanLumi[k_Z1bjet13] = "137 fb^{-1}";
  chanCadi[k_Z1bjet13] = "SMP-20-015";
  chanPreprint[k_Z1bjet13] = "2112.09659";
  chanPublication[k_Z1bjet13] = "Submitted to Phys. Rev. D";


  chanSigma[k_Z1bjet13]  = 6.52 * scale_;
  chanEStat[k_Z1bjet13]  =   0.04 * scale_;
chanESyst[k_Z1bjet13]  =   sqrt(0.40*0.40 + 0.14*0.14) * scale_;
  chanETot[k_Z1bjet13]   =  sqrt( chanESyst[k_Z1bjet13]*chanESyst[k_Z1bjet13] 
			       + 
			       chanEStat[k_Z1bjet13]*chanEStat[k_Z1bjet13]
				 );

  chanTheo[k_Z1bjet13]  = 7.03 * scale_;
chanETheop[k_Z1bjet13] = 0.47 * scale_;
chanETheom[k_Z1bjet13] = 0.47 * scale_;
chanETheo[k_Z1bjet13] = ((chanETheop[k_Z1bjet13]+chanETheom[k_Z1bjet13])/2.0) * scale_;
// MG5 aMC@NLO NLO CP5

// new Z + 2 b jet  13  TeV
  chanMeasurement[k_Z2bjet13] = "#geq1b";
  if (exportExeFormat) chanMeasurement[k_Z2bjet13] = "Z2b";
  chanLumi[k_Z2bjet13] = "137 fb^{-1}";
  chanCadi[k_Z2bjet13] = "SMP-20-015";
  chanPreprint[k_Z2bjet13] = "2112.09659";
  chanPublication[k_Z2bjet13] = "Submitted to Phys. Rev. D";
  chanSigma[k_Z2bjet13]  = 0.65 * scale_;
  chanEStat[k_Z2bjet13]  =   0.03 * scale_;
chanESyst[k_Z2bjet13]  =   sqrt(0.07*0.07 + 0.02*0.02) * scale_;
  chanETot[k_Z2bjet13]   =  sqrt( chanESyst[k_Z2bjet13]*chanESyst[k_Z2bjet13] 
			       + 
			       chanEStat[k_Z2bjet13]*chanEStat[k_Z2bjet13]
				 );

chanTheo[k_Z2bjet13]  = 0.77 * scale_;
chanETheop[k_Z2bjet13] = 0.07 * scale_;
chanETheom[k_Z2bjet13] = 0.07 * scale_;
chanETheo[k_Z2bjet13] = ((chanETheop[k_Z2bjet13]+chanETheom[k_Z2bjet13])/2.0) * scale_;
// MG5 aMC@NLO NLO CP5





// a MC@NL0 5 flavor


scale_ = 1.;

// VBF Z production, EWK Z produciton to ll
// http://cms-results.web.cern.ch/cms-results/public-results/publications/FSQ-12-019/index.html
// https://arxiv.org/abs/1305.7389  	JHEP 10 (2013) 101
 chanMeasurement[k_VBFZ]     = "#scale[0.70]{#splitline{EW}{qqZ}}";
  if (exportExeFormat) chanMeasurement[k_VBFZ] = "VBF Z";
if (version == 6) chanMeasurement[k_VBFZ]     = "#splitline{EWK qq(Z)}{(Z) #rightarrow ll}";
if (ratioPlot) chanMeasurement[k_VBFZ]     = "qqZ";
chanLumi[k_VBFZ] = "5.0 fb^{-1}";
  chanCadi[k_VBFZ] = "FSQ-12-019";
  chanPreprint[k_VBFZ] = "1305.7389";
  chanPublication[k_VBFZ] = "JHEP 10 (2013) 101";


  chanSigma[k_VBFZ]  =   0.154 * scale_; 
  chanEStatp[k_VBFZ]  =   0.024 * scale_;
chanESystp[k_VBFZ]  =   sqrt(0.046*0.046 + 0.027*0.027 + 0.003*0.003) * scale_;
  chanETotp[k_VBFZ]   =  sqrt( 
			   chanEStatp[k_VBFZ]*chanEStatp[k_VBFZ]
			   +
			   chanESystp[k_VBFZ]*chanESystp[k_VBFZ]
			    );

  chanEStatm[k_VBFZ]  =   0.024 * scale_;
  chanESystm[k_VBFZ]  =   sqrt(0.046*0.046 + 0.027*0.027 + 0.003*0.003) * scale_;
  chanETotm[k_VBFZ]   =  sqrt( 
			   chanEStatm[k_VBFZ]*chanEStatm[k_VBFZ]
			   +
			   chanESystm[k_VBFZ]*chanESystm[k_VBFZ]
			    );
  chanEStat[k_VBFZ] = (chanEStatp[k_VBFZ] +chanEStatm[k_VBFZ])/2.0;
  chanESyst[k_VBFZ] = (chanESystp[k_VBFZ] +chanESystm[k_VBFZ])/2.0;
  chanETot[k_VBFZ] = (chanETotp[k_VBFZ] +chanETotm[k_VBFZ])/2.0;
 


  chanTheo[k_VBFZ] =   0.166 * scale_;
  chanETheop[k_VBFZ] =  0.006 * scale_;
  chanETheom[k_VBFZ] =  0.006 * scale_;
  chanETheo[k_VBFZ] = (chanETheop[k_VBFZ] +chanETheom[k_VBFZ])/2.0;

// EWK Z 8 TeV 19.7 fb-1
http://cms-results.web.cern.ch/cms-results/public-results/publications/FSQ-12-035/index.html
// http://arxiv.org/abs/1410.3153  	Eur. Phys. J. C 75 (2015) 66
  chanMeasurement[k_VBFZ8]     = "#scale[0.70]{#splitline{EW}{qqZ}}";
  if (exportExeFormat) chanMeasurement[k_VBFZ8] = "VBF Z";
  if (version == 6) chanMeasurement[k_VBFZ8]     = "#splitline{EWK qq(Z)}{(Z) #rightarrow ll}";
  if (ratioPlot) chanMeasurement[k_VBFZ8]     = "qqZ";
  chanLumi[k_VBFZ8] = "19.7 fb^{-1}";
  chanCadi[k_VBFZ8] = "FSQ-12-035";
  chanPreprint[k_VBFZ8] = "1410.3153";
  chanPublication[k_VBFZ8] = "EPJC 75 (2015) 66";


  chanSigma[k_VBFZ8]  =   0.174 * scale_; 
  chanEStatp[k_VBFZ8]  =   0.015 * scale_;
  chanESystp[k_VBFZ8]  =   0.040 * scale_;
  chanETotp[k_VBFZ8]   =  sqrt( 
			   chanEStatp[k_VBFZ8]*chanEStatp[k_VBFZ8]
			   +
			   chanESystp[k_VBFZ8]*chanESystp[k_VBFZ8]
			    );

  chanEStatm[k_VBFZ8]  =   0.015 * scale_;
  chanESystm[k_VBFZ8]  =   0.040 * scale_;
  chanETotm[k_VBFZ8]   =  sqrt( 
			   chanEStatm[k_VBFZ8]*chanEStatm[k_VBFZ8]
			   +
			   chanESystm[k_VBFZ8]*chanESystm[k_VBFZ8]
			    );
  chanEStat[k_VBFZ8] = (chanEStatp[k_VBFZ8] +chanEStatm[k_VBFZ8])/2.0;
  chanESyst[k_VBFZ8] = (chanESystp[k_VBFZ8] +chanESystm[k_VBFZ8])/2.0;
  chanETot[k_VBFZ8] = (chanETotp[k_VBFZ8] +chanETotm[k_VBFZ8])/2.0;
 


  chanTheo[k_VBFZ8] =   0.208 * scale_;
  chanETheop[k_VBFZ8] =  0.018 * scale_;
  chanETheom[k_VBFZ8] =  0.018 * scale_;
  chanETheo[k_VBFZ8] = (chanETheop[k_VBFZ8] +chanETheom[k_VBFZ8])/2.0;

// EWK Z 13 TeV
//https://arxiv.org/abs/1712.09814
//http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-16-018/
// Eur. Phys. J. C (2018) 78: 589. 


 chanMeasurement[k_VBFZ13]     = "#scale[0.70]{#splitline{EW}{qqZ}}";
  if (exportExeFormat) chanMeasurement[k_VBFZ13] = "VBF Z";
  if (version == 6) chanMeasurement[k_VBFZ13]     = "#splitline{EWK qq(Z)}{(Z) #rightarrow ll}";
  if (ratioPlot) chanMeasurement[k_VBFZ13]     = "qqZ";
  chanLumi[k_VBFZ13] = "35.9 fb^{-1}";
  chanCadi[k_VBFZ13] = "SMP-16-018";
  chanPreprint[k_VBFZ13] = "1712.09814";
  chanPublication[k_VBFZ13] = "EPJC 78 (2018) 589";


  chanSigma[k_VBFZ13]  =   0.534 * scale_; 
  chanEStatp[k_VBFZ13]  =   0.020 * scale_;
  chanESystp[k_VBFZ13]  =   0.057 * scale_;
  chanETotp[k_VBFZ13]   =  sqrt( 
			   chanEStatp[k_VBFZ13]*chanEStatp[k_VBFZ13]
			   +
			   chanESystp[k_VBFZ13]*chanESystp[k_VBFZ13]
			    );

  chanEStatm[k_VBFZ13]  =   0.020 * scale_;
  chanESystm[k_VBFZ13]  =   0.057 * scale_;
  chanETotm[k_VBFZ13]   =  sqrt( 
			   chanEStatm[k_VBFZ13]*chanEStatm[k_VBFZ13]
			   +
			   chanESystm[k_VBFZ13]*chanESystm[k_VBFZ13]
			    );
  chanEStat[k_VBFZ13] = (chanEStatp[k_VBFZ13] +chanEStatm[k_VBFZ13])/2.0;
  chanESyst[k_VBFZ13] = (chanESystp[k_VBFZ13] +chanESystm[k_VBFZ13])/2.0;
  chanETot[k_VBFZ13] = (chanETotp[k_VBFZ13] +chanETotm[k_VBFZ13])/2.0;
 


  chanTheo[k_VBFZ13] =   0.543 * scale_;
  chanETheop[k_VBFZ13] =  sqrt(0.007*0.007 + 0.022*0.022) * scale_;
  chanETheom[k_VBFZ13] =  sqrt(0.009*0.009 + 0.022*0.022) * scale_;
  chanETheo[k_VBFZ13] = (chanETheop[k_VBFZ13] +chanETheom[k_VBFZ13])/2.0;



// EWK W 8 TeV 19.3 fb-1
//  new!!!!!
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-13-012/index.html
// https://arxiv.org/abs/1607.06975  	JHEP 11 (2016) 147

 chanMeasurement[k_VBFW8]     = " #scale[0.70]{#splitline{EW}{qqW}}";
  if (exportExeFormat) chanMeasurement[k_VBFW8] = "VBF W";
  if (version == 6) chanMeasurement[k_VBFW8]     = "#splitline{EWK qqW}{W #rightarrow l#nu}";
  if (ratioPlot) chanMeasurement[k_VBFW8]     = "qqW";
  chanLumi[k_VBFW8] = "19.3 fb^{-1}";
  chanCadi[k_VBFW8] = "SMP-13-012";
  chanPreprint[k_VBFW8] = "1607.06975";
  chanPublication[k_VBFW8] = "JHEP 11 (2016) 147";


chanSigma[k_VBFW8]  =   0.42 * scale_; 
  chanEStatp[k_VBFW8]  =   0.04 * scale_;
chanESystp[k_VBFW8]  =   sqrt(0.09*0.09 + 0.01*0.01) * scale_;
  chanETotp[k_VBFW8]   =  sqrt( 
			   chanEStatp[k_VBFW8]*chanEStatp[k_VBFW8]
			   +
			   chanESystp[k_VBFW8]*chanESystp[k_VBFW8]
			    );

  chanEStatm[k_VBFW8]  =   0.04 * scale_;
  chanESystm[k_VBFW8]  =   sqrt(0.09*0.09 + 0.01*0.01) * scale_;
  chanETotm[k_VBFW8]   =  sqrt( 
			   chanEStatm[k_VBFW8]*chanEStatm[k_VBFW8]
			   +
			   chanESystm[k_VBFW8]*chanESystm[k_VBFW8]
			    );
  chanEStat[k_VBFW8] = (chanEStatp[k_VBFW8] +chanEStatm[k_VBFW8])/2.0;
  chanESyst[k_VBFW8] = (chanESystp[k_VBFW8] +chanESystm[k_VBFW8])/2.0;
  chanETot[k_VBFW8] = (chanETotp[k_VBFW8] +chanETotm[k_VBFW8])/2.0;
 


  chanTheo[k_VBFW8] =   0.50 * scale_;
 chanETheop[k_VBFW8] =  sqrt(0.02*0.02 + 0.02*0.02) * scale_;
  chanETheom[k_VBFW8] = sqrt(0.02*0.02 + 0.02*0.02) * scale_;
  chanETheo[k_VBFW8] = (chanETheop[k_VBFW8] +chanETheom[k_VBFW8])/2.0;



  scale_ = 1.0;

// EWK W 13 TeV 35.9 fb-1
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-17-011/
// https://arxiv.org/abs/1903.04040 Eur. Phys. J. C 80 (2020) 43

 chanMeasurement[k_VBFW13]     = " #scale[0.70]{#splitline{EW}{qqW}}";
  if (exportExeFormat) chanMeasurement[k_VBFW13] = "VBF W";
  if (version == 6) chanMeasurement[k_VBFW13]     = "#splitline{EWK qqW}{W #rightarrow l#nu}";
  if (ratioPlot) chanMeasurement[k_VBFW13]     = "qqW";
  chanLumi[k_VBFW13] = "35.9 fb^{-1}";
  chanCadi[k_VBFW13] = "SMP-17-011";
  chanPreprint[k_VBFW13] = "1903.04040";
  chanPublication[k_VBFW13] = "EPJC 80 (2020) 43";


chanSigma[k_VBFW13]  =   6.23 * scale_; 
  chanEStatp[k_VBFW13]  =   0.12 * scale_;
chanESystp[k_VBFW13]  =   sqrt(0.61*0.61) * scale_;
  chanETotp[k_VBFW13]   =  sqrt( 
			   chanEStatp[k_VBFW13]*chanEStatp[k_VBFW13]
			   +
			   chanESystp[k_VBFW13]*chanESystp[k_VBFW13]
			    );

  chanEStatm[k_VBFW13]  =   0.12 * scale_;
  chanESystm[k_VBFW13]  =   sqrt(0.61*0.61) * scale_;
  chanETotm[k_VBFW13]   =  sqrt( 
			   chanEStatm[k_VBFW13]*chanEStatm[k_VBFW13]
			   +
			   chanESystm[k_VBFW13]*chanESystm[k_VBFW13]
			    );
  chanEStat[k_VBFW13] = (chanEStatp[k_VBFW13] +chanEStatm[k_VBFW13])/2.0;
  chanESyst[k_VBFW13] = (chanESystp[k_VBFW13] +chanESystm[k_VBFW13])/2.0;
  chanETot[k_VBFW13] = (chanETotp[k_VBFW13] +chanETotm[k_VBFW13])/2.0;
 


  chanTheo[k_VBFW13] =   6.81 * scale_;
 chanETheop[k_VBFW13] =  sqrt(0.03*0.03 + 0.26*0.26) * scale_;
  chanETheom[k_VBFW13] = sqrt(0.06*0.06 + 0.26*0.26) * scale_;
  chanETheo[k_VBFW13] = (chanETheop[k_VBFW13] +chanETheom[k_VBFW13])/2.0;



  scale_ = 1.0;



//Jets cross-sections

chanMeasurement[k_incj]     = "Inc. jet";
chanLumi[k_incj] = "5 fb^{-1}";
scale_ = 1000.0;

chanSigma[k_incj]  =  4.202 * 1000. * scale_;
chanEStat[k_incj]  =  10.38 * scale_;
chanESyst[k_incj] =  sqrt(356.5*356.5 + (4.202 * 1000. * 4.4/100.)*(4.202 * 1000. * 4.4/100.)) * scale_;
chanETot[k_incj] = sqrt(
						chanEStat[k_incj]*chanEStat[k_incj]
						+
						chanESyst[k_incj]*chanESyst[k_incj]
						);
chanTheo[k_incj] =  4.327 * 1000. * scale_;
chanETheo[k_incj] = sqrt(190.8*190.8 + 96.95*96.95 + 272.9*272.9) * scale_;


//Photon cross-sections

//Inclusive photons
chanMeasurement[k_incg]     = "Inc. #gamma";
chanLumi[k_incg] = "36 pb^{-1}";
scale_ = 1000.0;

chanSigma[k_incg]  =  39.6157 * scale_;
chanEStat[k_incg]  =  0.724239 * scale_;
chanESyst[k_incg] =  sqrt(6.69145*6.69145 + (39.6157 * 4.4/100.)*(39.6157 * 4.4/100.)) * scale_;
chanETot[k_incg] = sqrt(
					  chanEStat[k_incg]*chanEStat[k_incg]
					  +
					  chanESyst[k_incg]*chanESyst[k_incg]
					  );
chanTheo[k_incg] =  42.9432 * scale_;
chanETheo[k_incg] = sqrt(8.09766*8.09766 + 1.93354*1.93354) * scale_;


//Gamma+jets
  chanMeasurement[k_gj]     = "#gamma+jet";
  chanLumi[k_gj] = "2.1 fb^{-1}";
  scale_ = 1000.0;

chanSigma[k_gj]  =  8.01 * scale_;
chanEStat[k_gj]  =  0.11 * scale_;
chanESyst[k_gj] = sqrt(0.72*0.72+0.18*0.18) * scale_;
chanETot[k_gj] = sqrt(
					  chanEStat[k_gj]*chanEStat[k_gj]
					  +
					  chanESyst[k_gj]*chanESyst[k_gj]
					  );
chanTheo[k_gj] =  7.97 * scale_;
chanETheo[k_gj] = sqrt(0.17*0.17+1.10*1.10) * scale_;
//XS(exp)  =  8.01 +- 0.11(stat) +- 0.72(sys) +- 0.18(lumi)  nb
//XS(th) = 7.97 (+0.17 -0.16)pdf (+1.10 -0.91)scale nb


//Diphoton new
// Update to reference http://arxiv.org/abs/1405.7225 !!!!!new
chanMeasurement[k_ggnew]     = "#gamma#gamma";
//if (version==6) chanMeasurement[k_ggnew]     = "#gamma#gamma, #scale[0.70]{(NNLO th.)}";
chanLumi[k_ggnew] = "5.0 fb^{-1}";
  chanCadi[k_ggnew] = "SMP-13-001";
  chanPreprint[k_ggnew] = "1405.7225";
  chanPublication[k_ggnew] = "EPJC 74 (2014) 3129";



scale_ = 1.0;

chanSigma[k_ggnew]  =  17.2 * scale_;
chanEStat[k_ggnew] = 0.2* scale_;
chanESyst[k_ggnew] = sqrt(1.9*1.9+0.4*0.4)* scale_;
chanETot[k_ggnew] = sqrt(
					  chanEStat[k_ggnew]*chanEStat[k_ggnew]
					  +
					  chanESyst[k_ggnew]*chanESyst[k_ggnew]
					  );
chanTheo[k_ggnew] = 16.2 * scale_;
chanETheo[k_ggnew] = 1.4 * scale_;

// old
//σdata = 16.8 ± 0.2 (stat.) ± 1.8 (syst.) ± 0.4 (lumi) pb
//σNNLO(2γNNLO) = 16.2+1.5(scale) pb


//Hgamgam 7
chanMeasurement[k_Hgg]     = "H#rightarrow#gamma#gamma";
chanLumi[k_Hgg] = "5.1 fb^{-1}";
scale_ = 0.00228;

// chanTheo[k_Hgg] =   (15.13+1.222+0.5785+0.3351+0.08632) * scale_;
// float THuncert_ggH7 = sqrt( (15.13*7.8/100.)*(15.13*7.8/100.) + (15.13*7.6/100.)*(15.13*7.6/100.) )* scale_;
// float THuncert_VBF7 = sqrt( (1.222*0.3/100.)*(1.222*0.3/100.) + (1.222*2.5/100.)*(1.222*2.5/100.) )* scale_;
// float THuncert_WH7 =  sqrt( (0.5785*0.9/100.)*(0.5785*0.9/100.) + (0.5785*2.6/100.)*(0.5785*2.6/100.) )* scale_;
// float THuncert_ZH7 =  sqrt( (0.3351*2.9/100.)*(0.3351*2.9/100.) + (0.3351*2.7/100.)*(0.3351*2.7/100.) )* scale_;
// float THuncert_ttH7 = sqrt( (0.08632*9.3/100.)*(0.08632*9.3/100.) + (0.08632*8.4/100.)*(0.08632*8.4/100.) )* scale_;
chanETheo[k_Hgg] =  0.0015;
/*
chanETheo[k_Hgg] =  sqrt( THuncert_ggH7*THuncert_ggH7 
						 + THuncert_VBF7*THuncert_VBF7 
						 + THuncert_WH7*THuncert_WH7 
						 + THuncert_ZH7*THuncert_ZH7 
						 + THuncert_ttH7*THuncert_ttH7
					);
*/
//ggH7 125.0	 15.13	 +7.1%	 -7.8%	 +7.6%	 -7.1%
//VBF7 125.0	 1.222	 +0.3%	 -0.3%	 +2.5%	 -2.1%
//WH7  125.0	 0.5785	 +0.9%	 -0.9%	 +2.6%	 -2.6%
//ZH7  125.0	 0.3351	 +2.9%	 -2.9%	 +2.7%	 -2.7%
//ttH7 125.0	 0.08632 +3.2%	 -9.3%	 +8.4%	 -8.4%

chanSigma[k_Hgg]  =  1.69 * chanTheo[k_Hgg];
chanEStat[k_Hgg]  =  0.65 * chanTheo[k_Hgg];
chanESyst[k_Hgg] = 0.;
chanETot[k_Hgg] = sqrt(
						 chanEStat[k_Hgg]*chanEStat[k_Hgg]
						 +
						 chanESyst[k_Hgg]*chanESyst[k_Hgg]
						 );

//Hgamgam 8
chanLumi[k_Hgg8] = "19.6 fb^{-1}";
chanMeasurement[k_Hgg8]     = "H#rightarrow#gamma#gamma";

// chanTheo[k_Hgg8] =   (19.27+1.578+0.7046+0.4153+0.1293) * scale_;
// float THuncert_ggH8 = sqrt( (19.27*7.8/100.)*(19.27*7.8/100.) + (19.27*7.5/100.)*(19.27*7.5/100.) )* scale_;
// float THuncert_VBF8 = sqrt( (1.578*0.2/100.)*(1.578*0.2/100.) + (1.578*2.8/100.)*(1.578*2.8/100.) )* scale_;
// float THuncert_WH8 =  sqrt( (0.7046*1.0/100.)*(0.7046*1.0/100.) + (0.5785*2.3/100.)*(0.5785*2.3/100.) )* scale_;
// float THuncert_ZH8 =  sqrt( (0.4153*3.1/100.)*(0.4153*3.1/100.) + (0.4153*2.5/100.)*(0.4153*2.5/100.) )* scale_;
// float THuncert_ttH8 = sqrt( (0.1293*9.3/100.)*(0.1293*9.3/100.) + (0.1293*8.1/100.)*(0.1293*8.1/100.) )* scale_;
chanETheo[k_Hgg8] = 0.001;
/*
chanETheo[k_Hgg8] =  sqrt( THuncert_ggH8*THuncert_ggH8
						 + THuncert_VBF8*THuncert_VBF8 
						 + THuncert_WH8*THuncert_WH8
						 + THuncert_ZH8*THuncert_ZH8 
						 + THuncert_ttH8*THuncert_ttH8
						 );
*/
//ggH8 125.0	 19.27	 +7.2%	 -7.8%	 +7.5%	 -6.9%
//VBF8 125.0	 1.578	 +0.2%	 -0.2%	 +2.6%	 -2.8%
//WH8  125.0	 0.7046	 +1.0%	 -1.0%	 +2.3%	 -2.3%
//ZH8  125.0	 0.4153	 +3.1%	 -3.1%	 +2.5%	 -2.5%
//ttH8 125.0	 0.1293	 +3.8	 -9.3	 +8.1	 -8.1
chanSigma[k_Hgg8]  =  0.55 * chanTheo[k_Hgg8];
chanEStat[k_Hgg8]  =  0.29 * chanTheo[k_Hgg8];
chanESyst[k_Hgg8] = 0.;
chanETot[k_Hgg8] = sqrt(
					   chanEStat[k_Hgg8]*chanEStat[k_Hgg8]
					   +
					   chanESyst[k_Hgg8]*chanESyst[k_Hgg8]
					   );

scale_ = 1.0;

//Diphoton old
// gamma gamma cross section
//chanMeasurement[k_gg] = "#gamma#gamma),   #scale[0.7]{E_{T}^{ #gammas} > 23,20 GeV}";
  chanMeasurement[k_gg] = "#gamma#gamma";
  chanLumi[k_gg] = "36 pb^{-1}";


  chanSigma[k_gg]  =  62.4 * scale_;
  chanEStat[k_gg]  =  3.6 * scale_;
  chanESyst[k_gg]  =  6.316 * scale_;
  chanETot[k_gg]   =  sqrt(
                           chanEStat[k_gg]*chanEStat[k_gg]
                           +
                           chanESyst[k_gg]*chanESyst[k_gg]
                            );
  chanTheo[k_gg] =  52.7 * scale_;
  chanETheo[k_gg] =  5.8 * scale_;
  // Exp error is +-3.6 +5.3-5.8 +-2.5
  // Theo error is +5.8-4.2 +-2.0 
  // Et > 23,20 and R>0.45, Isolation cone R<0.4 less than 5GeV
  // Use down exp errors and up theory error since result is up

//   scale_ = (1./W_br_lnu);

//   chanSigma[k_Wg]  =  56.3 * scale_; 
//   chanEStat[k_Wg]  =  5.0 * scale_;
//   chanESyst[k_Wg]  =  5.504 * scale_;
//   chanETot[k_Wg]   =  sqrt( 
// 			   chanEStat[k_Wg]*chanEStat[k_Wg]
// 			   +
// 			   chanESyst[k_Wg]*chanESyst[k_Wg]
// 			    );
//   chanTheo[k_Wg] =  49.4 * scale_;
//   chanETheo[k_Wg] =  3.8 * scale_;


// Top results
// ttbar
// ttbar 7 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-13-004/index.html
// https://arxiv.org/abs/1603.02303, J. High Energy Phys. 08 (2016) 029


  chanMeasurement[k_tt] = "tt";
  chanLumi[k_tt] = "5 fb^{-1}";
  chanCadi[k_tt] = "TOP-13-004";
  chanPreprint[k_tt] = "1603.02303";
  chanPublication[k_tt] = "JHEP 08 (2016) 029";


  chanSigma[k_tt]  =   173.6 * scale_; 
  chanEStatp[k_tt]  =   2.1 * scale_;
chanESystp[k_tt]  =   sqrt(4.5*4.5+3.8*3.8) * scale_;
  chanETotp[k_tt]   =  sqrt( 
			   chanEStatp[k_tt]*chanEStatp[k_tt]
			   +
			   chanESystp[k_tt]*chanESystp[k_tt]
			    );

  chanEStatm[k_tt]  =   2.1 * scale_;
  chanESystm[k_tt]  =    sqrt(4.0*5.0 + 3.8*3.8) * scale_;
  chanETotm[k_tt]   =  sqrt( 
			   chanEStatm[k_tt]*chanEStatm[k_tt]
			   +
			   chanESystm[k_tt]*chanESystm[k_tt]
			    );
  chanEStat[k_tt] = (chanEStatp[k_tt] +chanEStatm[k_tt])/2.0;
  chanESyst[k_tt] = (chanESystp[k_tt] +chanESystm[k_tt])/2.0;
  chanETot[k_tt] = (chanETotp[k_tt] +chanETotm[k_tt])/2.0;
 


  chanTheo[k_tt] =   177.3 * scale_;
  chanETheop[k_tt] =  sqrt(4.7*4.7 + 9.0*9.0) * scale_;
  chanETheom[k_tt] =  sqrt(6.0*6.0 + 9.0*9.0) * scale_;
  chanETheo[k_tt] = (chanETheop[k_tt] +chanETheom[k_tt])/2.0;

// ttbar 8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-13-004/index.html
// https://arxiv.org/abs/1603.02303, J. High Energy Phys. 08 (2016) 029

  chanMeasurement[k_tt8] = "tt";
  chanLumi[k_tt8] = "19.7 fb^{-1}";
  chanCadi[k_tt8] = "TOP-13-004";
  chanPreprint[k_tt8] = "1603.02303";
  chanPublication[k_tt8] = "JHEP 08 (2016) 029";


  chanSigma[k_tt8]  =   244.9 * scale_; 
  chanEStatp[k_tt8]  =   1.4 * scale_;
chanESystp[k_tt8]  =   sqrt(6.3*6.3 + 6.4*6.4) * scale_;
  chanETotp[k_tt8]   =  sqrt( 
			   chanEStatp[k_tt8]*chanEStatp[k_tt8]
			   +
			   chanESystp[k_tt8]*chanESystp[k_tt8]
			    );

  chanEStatm[k_tt8]  =   1.4 * scale_;
chanESystm[k_tt8]  =   sqrt(5.5*5.5 + 6.4*6.4) * scale_;
  chanETotm[k_tt8]   =  sqrt( 
			   chanEStatm[k_tt8]*chanEStatm[k_tt8]
			   +
			   chanESystm[k_tt8]*chanESystm[k_tt8]
			    );
  chanEStat[k_tt8] = (chanEStatp[k_tt8] +chanEStatm[k_tt8])/2.0;
  chanESyst[k_tt8] = (chanESystp[k_tt8] +chanESystm[k_tt8])/2.0;
  chanETot[k_tt8] = (chanETotp[k_tt8] +chanETotm[k_tt8])/2.0;
 


  chanTheo[k_tt8] =   252.9 * scale_;
chanETheop[k_tt8] =  sqrt(6.4*6.4 + 11.7*11.7) * scale_;
chanETheom[k_tt8] = sqrt(8.6*8.6 + 11.7*11.7) * scale_;
  chanETheo[k_tt8] = (chanETheop[k_tt8] +chanETheom[k_tt8])/2.0;

// ttbar 13 TeV
//http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-16-005/index.html
// https://arxiv.org/abs/1611.04040, Submitted to Eur. Phys. J. C
// Replace with http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-16-006/index.html !!!!!!!!!!
// Replace with
// TOP-20-001
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-20-001/index.html
// https://arxiv.org/abs/2108.02803 Accepted by Phys. Rev. D


  if (use13TeV) chanMeasurement[k_tt13] = "tt";
  if (big13TeV) chanMeasurement[k_tt13]    =  "#splitline{   tt}{13Tev}";
  chanLumi[k_tt13] = "137 fb^{-1}";
  chanCadi[k_tt13] = "TOP-20-001";
  chanPreprint[k_tt13] = "2108.02803";
  chanPublication[k_tt13] = "Accepted by PRD";


  chanSigma[k_tt13]  =   791.0 * scale_; 
  chanEStatp[k_tt13]  =   0.56 * scale_;
chanESystp[k_tt13]  =   sqrt(21.1*21.1 + 13.9*13.8) * scale_;
  chanETotp[k_tt13]   =  sqrt( 
			   chanEStatp[k_tt13]*chanEStatp[k_tt13]
			   +
			   chanESystp[k_tt13]*chanESystp[k_tt13]
			    );

  chanEStatm[k_tt13]  =   0.56 * scale_;
  chanESystm[k_tt13]  =    sqrt(21.1*21.1 + 13.8*13.8) * scale_;
  chanETotm[k_tt13]   =  sqrt( 
			   chanEStatm[k_tt13]*chanEStatm[k_tt13]
			   +
			   chanESystm[k_tt13]*chanESystm[k_tt13]
			    );
  chanEStat[k_tt13] = (chanEStatp[k_tt13] +chanEStatm[k_tt13])/2.0;
  chanESyst[k_tt13] = (chanESystp[k_tt13] +chanESystm[k_tt13])/2.0;
  chanETot[k_tt13] = (chanETotp[k_tt13] +chanETotm[k_tt13])/2.0;
 


  chanTheo[k_tt13] =   832.0 * scale_;
chanETheop[k_tt13] =  40.0 * scale_;
  chanETheom[k_tt13] = 46.0 * scale_;
  chanETheo[k_tt13] = (chanETheop[k_tt13] +chanETheom[k_tt13])/2.0;
// top++2.0


// top with jets
// https://arxiv.org/abs/1208.2671
// JHEP 11 (2012) 067
// Remove because there are no publically avaliable nubmers
// !!!!!????? to be replaced http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-12-018/index.html\
// Eur. Phys. J. C 74 (2014) 3014
// tt + 1 jet
  chanMeasurement[k_tt1jet] = "1j";
if (exportExeFormat) chanMeasurement[k_tt1jet] = "ttj";
  chanLumi[k_tt1jet] = "2.3 fb^{-1}";
  chanCadi[k_tt1jet] = "TOP-11-005";
  chanPreprint[k_tt1jet] = "1208.2671";
  chanPublication[k_tt1jet] = "JHEP 11 (2012) 067";


  chanSigma[k_tt1jet]  =   44.2 * scale_; 
  chanEStatp[k_tt1jet]  =   3.68 * scale_;
  chanESystp[k_tt1jet]  =   0.0 * scale_;
  chanETotp[k_tt1jet]   =  sqrt( 
			   chanEStatp[k_tt1jet]*chanEStatp[k_tt1jet]
			   +
			   chanESystp[k_tt1jet]*chanESystp[k_tt1jet]
			    );

  chanEStatm[k_tt1jet]  =   3.68 * scale_;
  chanESystm[k_tt1jet]  =   0.0 * scale_;
  chanETotm[k_tt1jet]   =  sqrt( 
			   chanEStatm[k_tt1jet]*chanEStatm[k_tt1jet]
			   +
			   chanESystm[k_tt1jet]*chanESystm[k_tt1jet]
			    );
  chanEStat[k_tt1jet] = (chanEStatp[k_tt1jet] +chanEStatm[k_tt1jet])/2.0;
  chanESyst[k_tt1jet] = (chanESystp[k_tt1jet] +chanESystm[k_tt1jet])/2.0;
  chanETot[k_tt1jet] = (chanETotp[k_tt1jet] +chanETotm[k_tt1jet])/2.0;
 


  chanTheo[k_tt1jet] =   50.2 * scale_;
  chanETheop[k_tt1jet] =  3.5 * scale_;
  chanETheom[k_tt1jet] =  3.5 * scale_;
  chanETheo[k_tt1jet] = (chanETheop[k_tt1jet] +chanETheom[k_tt1jet])/2.0;

// tt + 2 jets
  chanMeasurement[k_tt2jet] = "2j";
if (exportExeFormat) chanMeasurement[k_tt2jet] = "tt2j";
  chanLumi[k_tt2jet] = "2.3 fb^{-1}";
  chanCadi[k_tt2jet] = "TOP-11-005";
  chanPreprint[k_tt2jet] = "1208.2671";
  chanPublication[k_tt2jet] = "JHEP 11 (2012) 067";

  chanSigma[k_tt2jet]  =   15.5 * scale_; 
  chanEStatp[k_tt2jet]  =   1.58 * scale_;
  chanESystp[k_tt2jet]  =   0.0 * scale_;
  chanETotp[k_tt2jet]   =  sqrt( 
			   chanEStatp[k_tt2jet]*chanEStatp[k_tt2jet]
			   +
			   chanESystp[k_tt2jet]*chanESystp[k_tt2jet]
			    );

  chanEStatm[k_tt2jet]  =   1.58 * scale_;
  chanESystm[k_tt2jet]  =   0.0 * scale_;
  chanETotm[k_tt2jet]   =  sqrt( 
			   chanEStatm[k_tt2jet]*chanEStatm[k_tt2jet]
			   +
			   chanESystm[k_tt2jet]*chanESystm[k_tt2jet]
			    );
  chanEStat[k_tt2jet] = (chanEStatp[k_tt2jet] +chanEStatm[k_tt2jet])/2.0;
  chanESyst[k_tt2jet] = (chanESystp[k_tt2jet] +chanESystm[k_tt2jet])/2.0;
  chanETot[k_tt2jet] = (chanETotp[k_tt2jet] +chanETotm[k_tt2jet])/2.0;
 


  chanTheo[k_tt2jet] =   16.8 * scale_;
  chanETheop[k_tt2jet] =  3.6 * scale_;
  chanETheom[k_tt2jet] =  3.6 * scale_;
  chanETheo[k_tt2jet] = (chanETheop[k_tt2jet] +chanETheom[k_tt2jet])/2.0;

// tt + 3 jets
  chanMeasurement[k_tt3jet] = "3j";
if (exportExeFormat) chanMeasurement[k_tt3jet] = "tt3j";
  chanLumi[k_tt3jet] = "2.3 fb^{-1}";
  chanCadi[k_tt3jet] = "TOP-11-005";
  chanPreprint[k_tt3jet] = "1208.2671";
  chanPublication[k_tt3jet] = "JHEP 11 (2012) 067";

  chanSigma[k_tt3jet]  =   4.04 * scale_; 
  chanEStatp[k_tt3jet]  =   0.99 * scale_;
  chanESystp[k_tt3jet]  =   0.0 * scale_;
  chanETotp[k_tt3jet]   =  sqrt( 
			   chanEStatp[k_tt3jet]*chanEStatp[k_tt3jet]
			   +
			   chanESystp[k_tt3jet]*chanESystp[k_tt3jet]
			    );

  chanEStatm[k_tt3jet]  =   0.99 * scale_;
  chanESystm[k_tt3jet]  =   0.0 * scale_;
  chanETotm[k_tt3jet]   =  sqrt( 
			   chanEStatm[k_tt3jet]*chanEStatm[k_tt3jet]
			   +
			   chanESystm[k_tt3jet]*chanESystm[k_tt3jet]
			    );
  chanEStat[k_tt3jet] = (chanEStatp[k_tt3jet] +chanEStatm[k_tt3jet])/2.0;
  chanESyst[k_tt3jet] = (chanESystp[k_tt3jet] +chanESystm[k_tt3jet])/2.0;
  chanETot[k_tt3jet] = (chanETotp[k_tt3jet] +chanETotm[k_tt3jet])/2.0;
 


  chanTheo[k_tt3jet] =   4.9 * scale_;
  chanETheop[k_tt3jet] =  1.3 * scale_;
  chanETheom[k_tt3jet] =  1.3 * scale_;
  chanETheo[k_tt3jet] = (chanETheop[k_tt3jet] +chanETheom[k_tt3jet])/2.0;

// top with jets 8 TeV
// CMS-PAS-TOP-12-007, http://cds.cern.ch/record/1462235
// tt + 1 jets 8 TeV
// Also removed, no publically avilable numbers

  chanMeasurement[k_tt1jet8] = "1j";
if (exportExeFormat) chanMeasurement[k_tt1jet8] = "ttj";
  chanLumi[k_tt1jet8] = "2.4 fb^{-1}";
  chanCadi[k_tt1jet8] = "TOP-12-007";
  chanPreprint[k_tt1jet8] = "1208.2671";
  chanPublication[k_tt1jet8] = "JHEP 11 (2012) 067";

  chanSigma[k_tt1jet8]  =   66.1 * scale_; 
  chanEStatp[k_tt1jet8]  =   5.74 * scale_;
  chanESystp[k_tt1jet8]  =   0.0 * scale_;
  chanETotp[k_tt1jet8]   =  sqrt( 
			   chanEStatp[k_tt1jet8]*chanEStatp[k_tt1jet8]
			   +
			   chanESystp[k_tt1jet8]*chanESystp[k_tt1jet8]
			    );

  chanEStatm[k_tt1jet8]  =   5.74 * scale_;
  chanESystm[k_tt1jet8]  =   0.0 * scale_;
  chanETotm[k_tt1jet8]   =  sqrt( 
			   chanEStatm[k_tt1jet8]*chanEStatm[k_tt1jet8]
			   +
			   chanESystm[k_tt1jet8]*chanESystm[k_tt1jet8]
			    );
  chanEStat[k_tt1jet8] = (chanEStatp[k_tt1jet8] +chanEStatm[k_tt1jet8])/2.0;
  chanESyst[k_tt1jet8] = (chanESystp[k_tt1jet8] +chanESystm[k_tt1jet8])/2.0;
  chanETot[k_tt1jet8] = (chanETotp[k_tt1jet8] +chanETotm[k_tt1jet8])/2.0;
 


  chanTheo[k_tt1jet8] =   72.5 * scale_;
  chanETheop[k_tt1jet8] =  5.2 * scale_;
  chanETheom[k_tt1jet8] =  5.2 * scale_;
  chanETheo[k_tt1jet8] = (chanETheop[k_tt1jet8] +chanETheom[k_tt1jet8])/2.0;

// tt + 2 jets 8 TeV
  chanMeasurement[k_tt2jet8] = "2j";
if (exportExeFormat) chanMeasurement[k_tt2jet8] = "tt2j";
  chanLumi[k_tt2jet8] = "2.4 fb^{-1}";

  chanSigma[k_tt2jet8]  =   22.7 * scale_; 
  chanEStatp[k_tt2jet8]  =   2.50 * scale_;
  chanESystp[k_tt2jet8]  =   0.0 * scale_;
  chanETotp[k_tt2jet8]   =  sqrt( 
			   chanEStatp[k_tt2jet8]*chanEStatp[k_tt2jet8]
			   +
			   chanESystp[k_tt2jet8]*chanESystp[k_tt2jet8]
			    );

  chanEStatm[k_tt2jet8]  =   2.50 * scale_;
  chanESystm[k_tt2jet8]  =   0.0 * scale_;
  chanETotm[k_tt2jet8]   =  sqrt( 
			   chanEStatm[k_tt2jet8]*chanEStatm[k_tt2jet8]
			   +
			   chanESystm[k_tt2jet8]*chanESystm[k_tt2jet8]
			    );
  chanEStat[k_tt2jet8] = (chanEStatp[k_tt2jet8] +chanEStatm[k_tt2jet8])/2.0;
  chanESyst[k_tt2jet8] = (chanESystp[k_tt2jet8] +chanESystm[k_tt2jet8])/2.0;
  chanETot[k_tt2jet8] = (chanETotp[k_tt2jet8] +chanETotm[k_tt2jet8])/2.0;
 


  chanTheo[k_tt2jet8] =   26.0 * scale_;
  chanETheop[k_tt2jet8] =  4.4 * scale_;
  chanETheom[k_tt2jet8] =  4.4 * scale_;
  chanETheo[k_tt2jet8] = (chanETheop[k_tt2jet8] +chanETheom[k_tt2jet8])/2.0;

// tt + 3 jets 8 TeV
  chanMeasurement[k_tt3jet8] = "3j";
if (exportExeFormat) chanMeasurement[k_tt3jet8] = "tt3j";
  chanLumi[k_tt3jet8] = "2.4 fb^{-1}";

  chanSigma[k_tt3jet8]  =   6.36 * scale_; 
  chanEStatp[k_tt3jet8]  =   1.05 * scale_;
  chanESystp[k_tt3jet8]  =   0.0 * scale_;
  chanETotp[k_tt3jet8]   =  sqrt( 
			   chanEStatp[k_tt3jet8]*chanEStatp[k_tt3jet8]
			   +
			   chanESystp[k_tt3jet8]*chanESystp[k_tt3jet8]
			    );

  chanEStatm[k_tt3jet8]  =   1.05 * scale_;
  chanESystm[k_tt3jet8]  =   0.0 * scale_;
  chanETotm[k_tt3jet8]   =  sqrt( 
			   chanEStatm[k_tt3jet8]*chanEStatm[k_tt3jet8]
			   +
			   chanESystm[k_tt3jet8]*chanESystm[k_tt3jet8]
			    );
  chanEStat[k_tt3jet8] = (chanEStatp[k_tt3jet8] +chanEStatm[k_tt3jet8])/2.0;
  chanESyst[k_tt3jet8] = (chanESystp[k_tt3jet8] +chanESystm[k_tt3jet8])/2.0;
  chanETot[k_tt3jet8] = (chanETotp[k_tt3jet8] +chanETotm[k_tt3jet8])/2.0;
 


  chanTheo[k_tt3jet8] =   7.7 * scale_;
  chanETheop[k_tt3jet8] =  2.0 * scale_;
  chanETheom[k_tt3jet8] =  2.0 * scale_;
  chanETheo[k_tt3jet8] = (chanETheop[k_tt3jet8] +chanETheom[k_tt3jet8])/2.0;

// ttbar + jets 13 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-16-008/index.html
// https://arxiv.org/abs/1610.04191 PRD 95 092001 (2017)
// Requested thoery numbers from otto.heinz.hindrichs@cern.ch

// 0 jet
  chanMeasurement[k_tt0jet13] = "01j";
if (exportExeFormat) chanMeasurement[k_tt0jet13] = "tt0j";
  chanLumi[k_tt0jet13] = "2.3 fb^{-1}";
  chanCadi[k_tt0jet13] = "TOP-16-008";
  chanPreprint[k_tt0jet13] = "1610.04191";
  chanPublication[k_tt0jet13] = "PRD 95 092001 (2017)";

  chanSigma[k_tt0jet13]  =   97 * scale_; 
  chanEStatp[k_tt0jet13]  =   2 * scale_;
  chanESystp[k_tt0jet13]  =   7 * scale_;
  chanETotp[k_tt0jet13]   =  sqrt( 
			   chanEStatp[k_tt0jet13]*chanEStatp[k_tt0jet13]
			   +
			   chanESystp[k_tt0jet13]*chanESystp[k_tt0jet13]
			    );

  chanEStatm[k_tt0jet13]  =   2 * scale_;
  chanESystm[k_tt0jet13]  =   7 * scale_;
  chanETotm[k_tt0jet13]   =  sqrt( 
			   chanEStatm[k_tt0jet13]*chanEStatm[k_tt0jet13]
			   +
			   chanESystm[k_tt0jet13]*chanESystm[k_tt0jet13]
			    );
  chanEStat[k_tt0jet13] = (chanEStatp[k_tt0jet13] +chanEStatm[k_tt0jet13])/2.0;
  chanESyst[k_tt0jet13] = (chanESystp[k_tt0jet13] +chanESystm[k_tt0jet13])/2.0;
  chanETot[k_tt0jet13] = (chanETotp[k_tt0jet13] +chanETotm[k_tt0jet13])/2.0;
 

// Extracted from plot
  chanTheo[k_tt0jet13] =   100.0 * scale_;
  chanETheop[k_tt0jet13] =  9.0 * scale_;
  chanETheom[k_tt0jet13] =  9.0 * scale_;
  chanETheo[k_tt0jet13] = (chanETheop[k_tt0jet13] +chanETheom[k_tt0jet13])/2.0;



  chanMeasurement[k_tt1jet13] = "1j";
if (exportExeFormat) chanMeasurement[k_tt1jet13] = "ttj";
  chanLumi[k_tt1jet13] = "2.3 fb^{-1}";
  chanCadi[k_tt1jet13] = "TOP-16-008";
  chanPreprint[k_tt1jet13] = "1610.04191";
  chanPublication[k_tt1jet13] = "PRD 95 092001 (2017)";

  chanSigma[k_tt1jet13]  =   77 * scale_; 
  chanEStatp[k_tt1jet13]  =   2 * scale_;
  chanESystp[k_tt1jet13]  =   11 * scale_;
  chanETotp[k_tt1jet13]   =  sqrt( 
			   chanEStatp[k_tt1jet13]*chanEStatp[k_tt1jet13]
			   +
			   chanESystp[k_tt1jet13]*chanESystp[k_tt1jet13]
			    );

  chanEStatm[k_tt1jet13]  =   2 * scale_;
  chanESystm[k_tt1jet13]  =   11 * scale_;
  chanETotm[k_tt1jet13]   =  sqrt( 
			   chanEStatm[k_tt1jet13]*chanEStatm[k_tt1jet13]
			   +
			   chanESystm[k_tt1jet13]*chanESystm[k_tt1jet13]
			    );
  chanEStat[k_tt1jet13] = (chanEStatp[k_tt1jet13] +chanEStatm[k_tt1jet13])/2.0;
  chanESyst[k_tt1jet13] = (chanESystp[k_tt1jet13] +chanESystm[k_tt1jet13])/2.0;
  chanETot[k_tt1jet13] = (chanETotp[k_tt1jet13] +chanETotm[k_tt1jet13])/2.0;
 


  chanTheo[k_tt1jet13] =   72.96 * scale_;
  chanETheop[k_tt1jet13] =  8.63 * scale_;
  chanETheom[k_tt1jet13] =  8.63 * scale_;
  chanETheo[k_tt1jet13] = (chanETheop[k_tt1jet13] +chanETheom[k_tt1jet13])/2.0;

// tt + 2 jets 13 TeV
  chanMeasurement[k_tt2jet13] = "2j";
if (exportExeFormat) chanMeasurement[k_tt2jet13] = "tt2j";
  chanLumi[k_tt2jet13] = "2.3 fb^{-1}";
  chanCadi[k_tt2jet13] = "TOP-16-008";
  chanPreprint[k_tt2jet13] = "1610.04191";
  chanPublication[k_tt2jet13] = "PRD 95 092001 (2017)";

  chanSigma[k_tt2jet13]  =   36.0 * scale_; 
  chanEStatp[k_tt2jet13]  =   1.0 * scale_;
  chanESystp[k_tt2jet13]  =   6.0 * scale_;
  chanETotp[k_tt2jet13]   =  sqrt( 
			   chanEStatp[k_tt2jet13]*chanEStatp[k_tt2jet13]
			   +
			   chanESystp[k_tt2jet13]*chanESystp[k_tt2jet13]
			    );

  chanEStatm[k_tt2jet13]  =   1.0 * scale_;
  chanESystm[k_tt2jet13]  =   6.0 * scale_;
  chanETotm[k_tt2jet13]   =  sqrt( 
			   chanEStatm[k_tt2jet13]*chanEStatm[k_tt2jet13]
			   +
			   chanESystm[k_tt2jet13]*chanESystm[k_tt2jet13]
			    );
  chanEStat[k_tt2jet13] = (chanEStatp[k_tt2jet13] +chanEStatm[k_tt2jet13])/2.0;
  chanESyst[k_tt2jet13] = (chanESystp[k_tt2jet13] +chanESystm[k_tt2jet13])/2.0;
  chanETot[k_tt2jet13] = (chanETotp[k_tt2jet13] +chanETotm[k_tt2jet13])/2.0;
 


  chanTheo[k_tt2jet13] =   36.93 * scale_;
  chanETheop[k_tt2jet13] =  4.9 * scale_;
  chanETheom[k_tt2jet13] =  4.9 * scale_;
  chanETheo[k_tt2jet13] = (chanETheop[k_tt2jet13] +chanETheom[k_tt2jet13])/2.0;

// tt + 3 jets 13 TeV
  chanMeasurement[k_tt3jet13] = "3j";
if (exportExeFormat) chanMeasurement[k_tt3jet13] = "tt3j";
  chanLumi[k_tt3jet13] = "2.3 fb^{-1}";
  chanCadi[k_tt3jet13] = "TOP-16-008";
  chanPreprint[k_tt3jet13] = "1610.04191";
  chanPublication[k_tt3jet13] = "PRD 95 092001 (2017)";

  chanSigma[k_tt3jet13]  =   12.7 * scale_; 
  chanEStatp[k_tt3jet13]  =   0.6 * scale_;
  chanESystp[k_tt3jet13]  =   3.1 * scale_;
  chanETotp[k_tt3jet13]   =  sqrt( 
			   chanEStatp[k_tt3jet13]*chanEStatp[k_tt3jet13]
			   +
			   chanESystp[k_tt3jet13]*chanESystp[k_tt3jet13]
			    );

  chanEStatm[k_tt3jet13]  =   0.6 * scale_;
  chanESystm[k_tt3jet13]  =   3.1 * scale_;
  chanETotm[k_tt3jet13]   =  sqrt( 
			   chanEStatm[k_tt3jet13]*chanEStatm[k_tt3jet13]
			   +
			   chanESystm[k_tt3jet13]*chanESystm[k_tt3jet13]
			    );
  chanEStat[k_tt3jet13] = (chanEStatp[k_tt3jet13] +chanEStatm[k_tt3jet13])/2.0;
  chanESyst[k_tt3jet13] = (chanESystp[k_tt3jet13] +chanESystm[k_tt3jet13])/2.0;
  chanETot[k_tt3jet13] = (chanETotp[k_tt3jet13] +chanETotm[k_tt3jet13])/2.0;
 


  chanTheo[k_tt3jet13] =   15.17 * scale_;
  chanETheop[k_tt3jet13] =  2.49 * scale_;
  chanETheom[k_tt3jet13] =  2.49 * scale_;
  chanETheo[k_tt3jet13] = (chanETheop[k_tt3jet13] +chanETheom[k_tt3jet13])/2.0;

// tt + 4 jets 13 TeV
  chanMeasurement[k_tt4jet13] = "4j";
if (exportExeFormat) chanMeasurement[k_tt4jet13] = "tt4j";
  chanLumi[k_tt4jet13] = "2.3 fb^{-1}";
  chanCadi[k_tt4jet13] = "TOP-16-008";
  chanPreprint[k_tt4jet13] = "1610.04191";
  chanPublication[k_tt4jet13] = "PRD 95 092001 (2017)";

  chanSigma[k_tt4jet13]  =   5.9 * scale_; 
  chanEStatp[k_tt4jet13]  =   0.2 * scale_;
  chanESystp[k_tt4jet13]  =   2.1 * scale_;
  chanETotp[k_tt4jet13]   =  sqrt( 
			   chanEStatp[k_tt4jet13]*chanEStatp[k_tt4jet13]
			   +
			   chanESystp[k_tt4jet13]*chanESystp[k_tt4jet13]
			    );

  chanEStatm[k_tt4jet13]  =   0.2 * scale_;
  chanESystm[k_tt4jet13]  =   2.1 * scale_;
  chanETotm[k_tt4jet13]   =  sqrt( 
			   chanEStatm[k_tt4jet13]*chanEStatm[k_tt4jet13]
			   +
			   chanESystm[k_tt4jet13]*chanESystm[k_tt4jet13]
			    );
  chanEStat[k_tt4jet13] = (chanEStatp[k_tt4jet13] +chanEStatm[k_tt4jet13])/2.0;
  chanESyst[k_tt4jet13] = (chanESystp[k_tt4jet13] +chanESystm[k_tt4jet13])/2.0;
  chanETot[k_tt4jet13] = (chanETotp[k_tt4jet13] +chanETotm[k_tt4jet13])/2.0;
 


  chanTheo[k_tt4jet13] =   8.06 * scale_;
  chanETheop[k_tt4jet13] =  1.97 * scale_;
  chanETheom[k_tt4jet13] =  1.97 * scale_;
  chanETheo[k_tt4jet13] = (chanETheop[k_tt4jet13] +chanETheom[k_tt4jet13])/2.0;


// tt + 2 b jets 13 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-16-010/index.html
// https://arxiv.org/abs/1705.10141 Phys. Lett. B 776 (2018) 355
// superceeded by
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-18-011/index.html
// https://arxiv.org/abs/1909.05306 Submitted to PLB
// Final version has better systematic uncerainty

// Replaced with
// https://arxiv.org/abs/2012.09225 Phys. Lett. B. 820 (2021) 136565
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-20-003

// tt 2L   don't include light jet result since a different measurement done in tt + jets analysis

// tt 2c

  chanMeasurement[k_tt2cjet13] = "2c";
  if (exportExeFormat) chanMeasurement[k_tt2cjet13] = "tt2c";
  chanLumi[k_tt2cjet13] = "41.5 fb^{-1}";
  chanCadi[k_tt2cjet13] = "TOP-20-003";
  chanPreprint[k_tt2cjet13] = "2012.09225";
  chanPublication[k_tt2cjet13] = "PLB 820 (2021) 136565";

  chanSigma[k_tt2cjet13]  =   8.0 * scale_; 
  chanEStatp[k_tt2cjet13]  =   1.1 * scale_;
  chanESystp[k_tt2cjet13]  =   1.3 * scale_;
  chanETotp[k_tt2cjet13]   =  sqrt( 
			   chanEStatp[k_tt2cjet13]*chanEStatp[k_tt2cjet13]
			   +
			   chanESystp[k_tt2cjet13]*chanESystp[k_tt2cjet13]
			    );

  chanEStatm[k_tt2cjet13]  =   1.1 * scale_;
  chanESystm[k_tt2cjet13]  =   1.3 * scale_;
  chanETotm[k_tt2cjet13]   =  sqrt( 
			   chanEStatm[k_tt2cjet13]*chanEStatm[k_tt2cjet13]
			   +
			   chanESystm[k_tt2cjet13]*chanESystm[k_tt2cjet13]
			    );
  chanEStat[k_tt2cjet13] = (chanEStatp[k_tt2cjet13] +chanEStatm[k_tt2cjet13])/2.0;
  chanESyst[k_tt2cjet13] = (chanESystp[k_tt2cjet13] +chanESystm[k_tt2cjet13])/2.0;
  chanETot[k_tt2cjet13] = (chanETotp[k_tt2cjet13] +chanETotm[k_tt2cjet13])/2.0;
 

// Madgraph prediction, though very close to Powheg
  chanTheo[k_tt2cjet13] =   8.9 * scale_;
  chanETheop[k_tt2cjet13] =  1.5 * scale_;
  chanETheom[k_tt2cjet13] =  1.5 * scale_;
  chanETheo[k_tt2cjet13] = (chanETheop[k_tt2cjet13] +chanETheom[k_tt2cjet13])/2.0;

// tt2b

  chanMeasurement[k_tt2bjet13] = "2b";
  if (exportExeFormat) chanMeasurement[k_tt2bjet13] = "tt2b";
  chanLumi[k_tt2bjet13] = "35.9 fb^{-1}";
  chanCadi[k_tt2bjet13] = "TOP-20-003";
  chanPreprint[k_tt2bjet13] = "2012.09225";
  chanPublication[k_tt2bjet13] = "PLB 820 (2021) 136565";

chanSigma[k_tt2bjet13]  =   4.09 * scale_; 
  chanEStatp[k_tt2bjet13]  =   0.34 * scale_;
  chanESystp[k_tt2bjet13]  =   0.55 * scale_;
  chanETotp[k_tt2bjet13]   =  sqrt( 
			   chanEStatp[k_tt2bjet13]*chanEStatp[k_tt2bjet13]
			   +
			   chanESystp[k_tt2bjet13]*chanESystp[k_tt2bjet13]
			    );

  chanEStatm[k_tt2bjet13]  =   0.34 * scale_;
  chanESystm[k_tt2bjet13]  =   0.55 * scale_;
  chanETotm[k_tt2bjet13]   =  sqrt( 
			   chanEStatm[k_tt2bjet13]*chanEStatm[k_tt2bjet13]
			   +
			   chanESystm[k_tt2bjet13]*chanESystm[k_tt2bjet13]
			    );
  chanEStat[k_tt2bjet13] = (chanEStatp[k_tt2bjet13] +chanEStatm[k_tt2bjet13])/2.0;
  chanESyst[k_tt2bjet13] = (chanESystp[k_tt2bjet13] +chanESystm[k_tt2bjet13])/2.0;
  chanETot[k_tt2bjet13] = (chanETotp[k_tt2bjet13] +chanETotm[k_tt2bjet13])/2.0;
 

// Madgraph prediction, though very close to Powheg
  chanTheo[k_tt2bjet13] =   3.39 * scale_;
  chanETheop[k_tt2bjet13] =  0.66 * scale_;
  chanETheom[k_tt2bjet13] =  0.66 * scale_;
  chanETheo[k_tt2bjet13] = (chanETheop[k_tt2bjet13] +chanETheom[k_tt2bjet13])/2.0;


// single top t chan only
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-11-021/index.html
// https://arxiv.org/abs/1209.4533, JHEP 12 (2012) 035
  chanLumi[k_t] = "";
  chanMeasurement[k_t] = "t_{t-ch}";
  if (exportExeFormat) chanMeasurement[k_t] = "t$_{t-ch}$";
  chanLumi[k_t] = "1.6 fb^{-1}";
  chanCadi[k_t] = "TOP-11-021";
  chanPreprint[k_t] = "1209.4533";
  chanPublication[k_t] = "JHEP 12 (2012) 035";

  chanSigma[k_t]  =   67.2 * scale_; 
  chanEStatp[k_t]  =   3.7 * scale_;
chanESystp[k_t]  =   sqrt(3.0*3.0+3.5*3.5+1.5*1.5) * scale_;
  chanETotp[k_t]   =  6.1 * scale_;

  chanEStatm[k_t]  =   3.7 * scale_;
  chanESystm[k_t]  =   sqrt(3.0*3.0+3.5*3.5+1.5*1.5) * scale_;
  chanETotm[k_t]   =  6.1 * scale_;
  chanEStat[k_t] = (chanEStatp[k_t] +chanEStatm[k_t])/2.0;
  chanESyst[k_t] = (chanESystp[k_t] +chanESystm[k_t])/2.0;
  chanETot[k_t] = (chanETotp[k_t] +chanETotm[k_t])/2.0;
 


  chanTheo[k_t] =   65.9 * scale_;
  chanETheop[k_t] =  2.4 * scale_;
  chanETheom[k_t] =  1.9 * scale_;
  chanETheo[k_t] = (chanETheop[k_t] +chanETheom[k_t])/2.0;

// single top CMS-TOP-12-038
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-12-038/index.html
// http://arxiv.org/abs/1403.7366, J. High Energy Phys. 06 (2014) 090

  chanMeasurement[k_t8] = "t_{t-ch}";
  if (exportExeFormat) chanMeasurement[k_t8] = "t$_{t-ch}$";
  chanLumi[k_t8] = "5 fb^{-1}";
  chanCadi[k_t8] = "TOP-12-038";
  chanPreprint[k_t8] = "1403.7366";
  chanPublication[k_t8] = "JHEP 06 (2014) 090";

  chanSigma[k_t8]  =   83.6 * scale_; 
  chanEStatp[k_t8]  =   2.3 * scale_;
  chanESystp[k_t8]  =   7.4 * scale_;
  chanETotp[k_t8]   =  sqrt( 
			   chanEStatp[k_t8]*chanEStatp[k_t8]
			   +
			   chanESystp[k_t8]*chanESystp[k_t8]
			    );

  chanEStatm[k_t8]  =   2.3 * scale_;
  chanESystm[k_t8]  =   7.4 * scale_;
  chanETotm[k_t8]   =  sqrt( 
			   chanEStatm[k_t8]*chanEStatm[k_t8]
			   +
			   chanESystm[k_t8]*chanESystm[k_t8]
			    );
  chanEStat[k_t8] = (chanEStatp[k_t8] +chanEStatm[k_t8])/2.0;
  chanESyst[k_t8] = (chanESystp[k_t8] +chanESystm[k_t8])/2.0;
  chanETot[k_t8] = (chanETotp[k_t8] +chanETotm[k_t8])/2.0;
 


  chanTheo[k_t8] =   87.2 * scale_;
chanETheop[k_t8] =  sqrt(2.8*2.8 + 2.0*2.0) * scale_;
chanETheom[k_t8] =  sqrt(1.0*1.0 + 2.2*2.2) * scale_;
  chanETheo[k_t8] = (chanETheop[k_t8] +chanETheom[k_t8])/2.0;


// single top
  // chanMeasurement[k_t8] = "t_{t-ch}";
  // chanLumi[k_t8] = "";

  // chanSigma[k_t8]  =   80.1 * scale_; 
  // chanEStatp[k_t8]  =   13.0 * scale_;
  // chanESystp[k_t8]  =   0.0 * scale_;
  // chanETotp[k_t8]   =  sqrt( 
  // 			   chanEStatp[k_t8]*chanEStatp[k_t8]
  // 			   +
  // 			   chanESystp[k_t8]*chanESystp[k_t8]
  // 			    );

  // chanEStatm[k_t8]  =   13.0 * scale_;
  // chanESystm[k_t8]  =   0.0 * scale_;
  // chanETotm[k_t8]   =  sqrt( 
  // 			   chanEStatm[k_t8]*chanEStatm[k_t8]
  // 			   +
  // 			   chanESystm[k_t8]*chanESystm[k_t8]
  // 			    );
  // chanEStat[k_t8] = (chanEStatp[k_t8] +chanEStatm[k_t8])/2.0;
  // chanESyst[k_t8] = (chanESystp[k_t8] +chanESystm[k_t8])/2.0;
  // chanETot[k_t8] = (chanETotp[k_t8] +chanETotm[k_t8])/2.0;
 


  // chanTheo[k_t8] =   87.2 * scale_;
  // chanETheop[k_t8] =  3.2 * scale_;
  // chanETheom[k_t8] =  2.4 * scale_;
  // chanETheo[k_t8] = (chanETheop[k_t8] +chanETheom[k_t8])/2.0;


//http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-16-003/index.html
// https://arxiv.org/abs/1610.00678, Phys. Lett. B 72 (2017) 752
  if (use13TeV) chanMeasurement[k_t13] = "t_{t-ch}";
  if (exportExeFormat) chanMeasurement[k_t13] = "t$_{t-ch}$";
  if (big13TeV) chanMeasurement[k_t13]    =  "#splitline{  t_{t-ch}}{13Tev}";
  chanLumi[k_t13] = "2.3 fb^{-1}";
  chanCadi[k_t13] = "TOP-16-003";
  chanPreprint[k_t13] = "1610.00678";
  chanPublication[k_t13] = "PLB 72 (2017) 752";



  chanSigma[k_t13]  =   232 * scale_; 
  chanEStatp[k_t13]  =   13 * scale_;
chanESystp[k_t13]  =   sqrt(12.0*12.0+26*26+6.2*6) * scale_;
  chanETotp[k_t13]   =  sqrt( 
			   chanEStatp[k_t13]*chanEStatp[k_t13]
			   +
			   chanESystp[k_t13]*chanESystp[k_t13]
			    );

  chanEStatm[k_t13]  =   13 * scale_;
  chanESystm[k_t13]  =   sqrt(12*12+26*26+6*6) * scale_;
  chanETotm[k_t13]   =  sqrt( 
			   chanEStatm[k_t13]*chanEStatm[k_t13]
			   +
			   chanESystm[k_t13]*chanESystm[k_t13]
			    );
  chanEStat[k_t13] = (chanEStatp[k_t13] +chanEStatm[k_t13])/2.0;
  chanESyst[k_t13] = (chanESystp[k_t13] +chanESystm[k_t13])/2.0;
  chanETot[k_t13] = (chanETotp[k_t13] +chanETotm[k_t13])/2.0;
 


  chanTheo[k_t13] =   217.0 * scale_;
chanETheop[k_t13] =  sqrt(6.6*6.6 + 6.2*6.2) * scale_;
chanETheom[k_t13] =  sqrt(4.6*4.6 +6.2*6.2) * scale_;
  chanETheo[k_t13] = (chanETheop[k_t13] +chanETheom[k_t13])/2.0;



// single top s chan only, 7 TeV and 8 TeV
// https://cds.cern.ch/record/1633190/ CMS-PAS-TOP-13-009
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-13-009/index.html
// http://arxiv.org/abs/1603.02555 J. High Energy Phys. 09 (2016) 027. 

  chanLumi[k_tschan] = "5.1 fb^{-1}";
  chanMeasurement[k_tschan] = "t_{s-ch}";
  if (exportExeFormat) chanMeasurement[k_tschan] = "t$_{s-ch}$";
  chanCadi[k_tschan] = "TOP-13-009";
  chanPreprint[k_tschan] = "1603.02555";
  chanPublication[k_tschan] = "JHEP 09 (2016) 027";

  chanSigma[k_tschan]  =  -31.4; 
  chanEStatp[k_tschan]  =   0.0 * scale_;
 chanESystp[k_tschan]  =    0.0 * scale_;
  chanETotp[k_tschan]   =  sqrt( 
			   chanEStatp[k_tschan]*chanEStatp[k_tschan]
			   +
			   chanESystp[k_tschan]*chanESystp[k_tschan]
			    );

  chanEStatm[k_tschan]  =   0.0 * scale_;
  chanESystm[k_tschan]  =   0.0 * scale_;
  chanETotm[k_tschan]   =  sqrt( 
			   chanEStatm[k_tschan]*chanEStatm[k_tschan]
			   +
			   chanESystm[k_tschan]*chanESystm[k_tschan]
			    );
  chanEStat[k_tschan] = (chanEStatp[k_tschan] +chanEStatm[k_tschan])/2.0;
  chanESyst[k_tschan] = (chanESystp[k_tschan] +chanESystm[k_tschan])/2.0;
  chanETot[k_tschan] = (chanETotp[k_tschan] +chanETotm[k_tschan])/2.0;
 


  chanTheo[k_tschan] =   4.56 * scale_;
  chanETheop[k_tschan] =  sqrt(0.07*0.07 + 0.17*0.17) * scale_;
  chanETheom[k_tschan] =  sqrt(0.07*0.07 + 0.17*0.17) * scale_;
  chanETheo[k_tschan] = (chanETheop[k_tschan] +chanETheom[k_tschan])/2.0;



  chanLumi[k_tschan8] = "19.7 fb^{-1}";
  chanMeasurement[k_tschan8] = "t_{s-ch}";
  if (exportExeFormat) chanMeasurement[k_tschan8] = "t$_{s-ch}$";
  chanCadi[k_tschan8] = "TOP-13-009";
  chanPreprint[k_tschan8] = "1603.02555";
  chanPublication[k_tschan8] = "JHEP 09 (2016) 027";



  chanSigma[k_tschan8]  =  13.4;
  chanEStatp[k_tschan8]  =   7.3 * scale_;
  chanESystp[k_tschan8]  =   7.3 * scale_;
  chanETotp[k_tschan8]   =  sqrt(
                           chanEStatp[k_tschan8]*chanEStatp[k_tschan8]
                           +
                           chanESystp[k_tschan8]*chanESystp[k_tschan8]
                            );

  chanEStatm[k_tschan8]  =   0.0 * scale_;
  chanESystm[k_tschan8]  =   0.0 * scale_;
  chanETotm[k_tschan8]   =  sqrt(
                           chanEStatm[k_tschan8]*chanEStatm[k_tschan8]
                           +
                           chanESystm[k_tschan8]*chanESystm[k_tschan8]
                            );
  chanEStat[k_tschan8] = (chanEStatp[k_tschan8] +chanEStatm[k_tschan8])/2.0;
  chanESyst[k_tschan8] = (chanESystp[k_tschan8] +chanESystm[k_tschan8])/2.0;
  chanETot[k_tschan8] = (chanETotp[k_tschan8] +chanETotm[k_tschan8])/2.0;



  chanTheo[k_tschan8] =   5.55 * scale_;
  chanETheop[k_tschan8] =  sqrt(0.08*0.08 + 0.21*0.21) * scale_;
  chanETheom[k_tschan8] =  sqrt(0.08*0.08 + 0.21*0.21) * scale_;
  chanETheo[k_tschan8] = (chanETheop[k_tschan8] +chanETheom[k_tschan8])/2.0;



// tW
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-11-022/index.html
// https://arxiv.org/abs/1209.3489, Phys. Rev. Lett. 110 (2013) 022003
  chanMeasurement[k_tW] = "tW";
  chanLumi[k_tW] = "4.9 fb^{-1}";
  chanCadi[k_tW] = "TOP-11-022";
  chanPreprint[k_tW] = "1209.3489";
  chanPublication[k_tW] = "PRL 110 (2013) 022003";

  chanSigma[k_tW]  =   16.0 * scale_; 
  chanEStatp[k_tW]  =   5.0 * scale_;
  chanESystp[k_tW]  =   0.0 * scale_;
  chanETotp[k_tW]   =  sqrt( 
			   chanEStatp[k_tW]*chanEStatp[k_tW]
			   +
			   chanESystp[k_tW]*chanESystp[k_tW]
			    );

  chanEStatm[k_tW]  =   4.0 * scale_;
  chanESystm[k_tW]  =   0.0 * scale_;
  chanETotm[k_tW]   =  sqrt( 
			   chanEStatm[k_tW]*chanEStatm[k_tW]
			   +
			   chanESystm[k_tW]*chanESystm[k_tW]
			    );
  chanEStat[k_tW] = (chanEStatp[k_tW] +chanEStatm[k_tW])/2.0;
  chanESyst[k_tW] = (chanESystp[k_tW] +chanESystm[k_tW])/2.0;
  chanETot[k_tW] = (chanETotp[k_tW] +chanETotm[k_tW])/2.0;
 


  chanTheo[k_tW] =   15.6 * scale_;
  chanETheop[k_tW] =  sqrt(0.4*0.4 + 1.0*1.0) * scale_;
  chanETheom[k_tW] = sqrt(0.4*0.4 + 1.2*1.2)  * scale_;
  chanETheo[k_tW] = (chanETheop[k_tW] +chanETheom[k_tW])/2.0;

// tW 8 TeV 
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-12-040/index.html
// https://arxiv.org/abs/1401.2942,  	Phys. Rev. Lett. 112 (2014) 231802

  chanMeasurement[k_tW8] = "tW";
  chanLumi[k_tW8] = "19.7 fb^{-1}";
  chanCadi[k_tW8] = "TOP-12-040";
  chanPreprint[k_tW8] = "1401.2942";
  chanPublication[k_tW8] = "PRL 112 (2014) 231802";

  chanSigma[k_tW8]  =   23.4 * scale_; 
  chanEStatp[k_tW8]  =   5.4 * scale_;
  chanESystp[k_tW8]  =   0.0 * scale_;
  chanETotp[k_tW8]   =  sqrt( 
			   chanEStatp[k_tW8]*chanEStatp[k_tW8]
			   +
			   chanESystp[k_tW8]*chanESystp[k_tW8]
			    );

  chanEStatm[k_tW8]  =   5.4 * scale_;
  chanESystm[k_tW8]  =   0.0 * scale_;
  chanETotm[k_tW8]   =  sqrt( 
			   chanEStatm[k_tW8]*chanEStatm[k_tW8]
			   +
			   chanESystm[k_tW8]*chanESystm[k_tW8]
			    );
  chanEStat[k_tW8] = (chanEStatp[k_tW8] +chanEStatm[k_tW8])/2.0;
  chanESyst[k_tW8] = (chanESystp[k_tW8] +chanESystm[k_tW8])/2.0;
  chanETot[k_tW8] = (chanETotp[k_tW8] +chanETotm[k_tW8])/2.0;
 


  chanTheo[k_tW8] =   22.2 * scale_;
  chanETheop[k_tW8] =  1.5 * scale_;
  chanETheom[k_tW8] =  1.5 * scale_;
  chanETheo[k_tW8] = (chanETheop[k_tW8] +chanETheom[k_tW8])/2.0;

// tW 13 TeV
// https://arxiv.org/abs/1805.07399 JHEP 10 (2018) 117
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-17-018/
// better than TOP-20-002 leptons
// note replaced with, systematic uncerainty far worse in new analysis
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-21-010/index.html

  chanMeasurement[k_tW13] = "tW";
  chanLumi[k_tW13] = "35.9 fb^{-1}";
  chanCadi[k_tW13] = "TOP-17-018";
  chanPreprint[k_tW13] = "1805.07399";
  chanPublication[k_tW13] = "JHEP 10 (2018) 117";

  chanSigma[k_tW13]  =   63.1 * scale_; 
  chanEStatp[k_tW13]  =   1.8 * scale_;
chanESystp[k_tW13]  =   sqrt(6.4*6.4 + 2.1*2.1) * scale_;
  chanETotp[k_tW13]   =  sqrt( 
			   chanEStatp[k_tW13]*chanEStatp[k_tW13]
			   +
			   chanESystp[k_tW13]*chanESystp[k_tW13]
			    );

  chanEStatm[k_tW13]  =   1.8 * scale_;
  chanESystm[k_tW13]  =   sqrt(6.4*6.4 + 2.1*2.1)  * scale_;
  chanETotm[k_tW13]   =  sqrt( 
			   chanEStatm[k_tW13]*chanEStatm[k_tW13]
			   +
			   chanESystm[k_tW13]*chanESystm[k_tW13]
			    );
  chanEStat[k_tW13] = (chanEStatp[k_tW13] +chanEStatm[k_tW13])/2.0;
  chanESyst[k_tW13] = (chanESystp[k_tW13] +chanESystm[k_tW13])/2.0;
  chanETot[k_tW13] = (chanETotp[k_tW13] +chanETotm[k_tW13])/2.0;
 


  chanTheo[k_tW13] =   71.7 * scale_;
  chanETheop[k_tW13] =  sqrt(1.8*1.8 + 3.4*3.4) * scale_;
  chanETheom[k_tW13] = sqrt(1.8*1.8 + 3.4*3.4) * scale_;
  chanETheo[k_tW13] = (chanETheop[k_tW13] +chanETheom[k_tW13])/2.0;



// ttg8amma
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-14-008/
// https://arxiv.org/abs/1706.08128 JHEP 10 (2017) 006



  chanMeasurement[k_ttg8] = "tt#gamma";
  if (exportExeFormat) chanMeasurement[k_ttg8] = "tt$\\gamma$";
  chanLumi[k_ttg8] = "19.7 fb^{-1}";
  chanCadi[k_ttg8] = "TOP-14-008";
  chanPreprint[k_ttg8] = "1706.08128";
  chanPublication[k_ttg8] = "JHEP 10 (2017) 006";


scale_ = 3.0/(0.438);

chanSigma[k_ttg8]  =   0.515 * scale_; 
  chanEStatp[k_ttg8]  =   0.108 * scale_;
  chanESystp[k_ttg8]  =   0.0 * scale_;
  chanETotp[k_ttg8]   =  sqrt( 
			   chanEStatp[k_ttg8]*chanEStatp[k_ttg8]
			   +
			   chanESystp[k_ttg8]*chanESystp[k_ttg8]
			    );

  chanEStatm[k_ttg8]  =   0.108 * scale_;
  chanESystm[k_ttg8]  =   0.0 * scale_;
  chanETotm[k_ttg8]   =  sqrt( 
			   chanEStatm[k_ttg8]*chanEStatm[k_ttg8]
			   +
			   chanESystm[k_ttg8]*chanESystm[k_ttg8]
			    );
  chanEStat[k_ttg8] = (chanEStatp[k_ttg8] +chanEStatm[k_ttg8])/2.0;
  chanESyst[k_ttg8] = (chanESystp[k_ttg8] +chanESystm[k_ttg8])/2.0;
  chanETot[k_ttg8] = (chanETotp[k_ttg8] +chanETotm[k_ttg8])/2.0;
 


  chanTheo[k_ttg8] =   0.592 * scale_;
  chanETheop[k_ttg8] =  sqrt(0.071*0.071 + 0.030*0.030) * scale_;
  chanETheom[k_ttg8] =  sqrt(0.071*0.071 + 0.030*0.030) * scale_;
  chanETheo[k_ttg8] = (chanETheop[k_ttg8] +chanETheom[k_ttg8])/2.0;

	      scale_ = 1.0;


// ttgamma 13 TeV
// TOP-18-010
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-18-010/index.html
// https://arxiv.org/abs/2107.01508 Submitted to JHEP.
// ttg Replace with TOP-21-004
// https://cds.cern.ch/record/2781609?ln=en
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-21-004/index.html
// Now https://arxiv.org/abs/2201.07301

scale_ = 3.0/(0.438);

  chanMeasurement[k_ttg13] = "tt#gamma";
  if (exportExeFormat) chanMeasurement[k_ttg13] = "tt$\\gamma$";
  chanLumi[k_ttg13] = "138 fb^{-1}";
  chanCadi[k_ttg13] = "TOP-21-004";
  chanPreprint[k_ttg13] = "2201.07301";
  chanPublication[k_ttg13] = "Submitted to JHEP";


chanSigma[k_ttg13]  =   0.1735 * scale_; 
  chanEStatp[k_ttg13]  =   0.0025 * scale_;
chanESystp[k_ttg13]  =     0.0063 * scale_;
  chanETotp[k_ttg13]   =  sqrt( 
			   chanEStatp[k_ttg13]*chanEStatp[k_ttg13]
			   +
			   chanESystp[k_ttg13]*chanESystp[k_ttg13]
			    );

  chanEStatm[k_ttg13]  =   0.0025 * scale_;
  chanESystm[k_ttg13]  =   0.0063 * scale_;
  chanETotm[k_ttg13]   =  sqrt( 
			   chanEStatm[k_ttg13]*chanEStatm[k_ttg13]
			   +
			   chanESystm[k_ttg13]*chanESystm[k_ttg13]
			    );
  chanEStat[k_ttg13] = (chanEStatp[k_ttg13] +chanEStatm[k_ttg13])/2.0;
  chanESyst[k_ttg13] = (chanESystp[k_ttg13] +chanESystm[k_ttg13])/2.0;
  chanETot[k_ttg13] = (chanETotp[k_ttg13] +chanETotm[k_ttg13])/2.0;
 


  chanTheo[k_ttg13] =   0.153 * scale_;
  chanETheop[k_ttg13] =  0.027 * scale_;
  chanETheom[k_ttg13] =  0.027 * scale_;
  chanETheo[k_ttg13] = (chanETheop[k_ttg13] +chanETheom[k_ttg13])/2.0;

	      scale_ = 1.0;



// ttW8, W TOP 14 021
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-14-021/index.html
// https://arxiv.org/abs/1510.01131, JHEP 01 (2016) 096
  chanMeasurement[k_ttW8] = "ttW";
  chanLumi[k_ttW8] = "19.5 fb^{-1}";
  chanCadi[k_ttW8] = "TOP-14-021";
  chanPreprint[k_ttW8] = "1510.01131";
  chanPublication[k_ttW8] = "JHEP 01 (2016) 096";


  chanSigma[k_ttW8]  =   0.382 * scale_; 
  chanEStatp[k_ttW8]  =   0.117 * scale_;
  chanESystp[k_ttW8]  =   0.0 * scale_;
  chanETotp[k_ttW8]   =  sqrt( 
			   chanEStatp[k_ttW8]*chanEStatp[k_ttW8]
			   +
			   chanESystp[k_ttW8]*chanESystp[k_ttW8]
			    );

  chanEStatm[k_ttW8]  =   0.102 * scale_;
  chanESystm[k_ttW8]  =   0.0 * scale_;
  chanETotm[k_ttW8]   =  sqrt( 
			   chanEStatm[k_ttW8]*chanEStatm[k_ttW8]
			   +
			   chanESystm[k_ttW8]*chanESystm[k_ttW8]
			    );
  chanEStat[k_ttW8] = (chanEStatp[k_ttW8] +chanEStatm[k_ttW8])/2.0;
  chanESyst[k_ttW8] = (chanESystp[k_ttW8] +chanESystm[k_ttW8])/2.0;
  chanETot[k_ttW8] = (chanETotp[k_ttW8] +chanETotm[k_ttW8])/2.0;
 


  chanTheo[k_ttW8] =   0.203 * scale_;
  chanETheop[k_ttW8] =  0.021 * scale_;
  chanETheom[k_ttW8] =  0.023 * scale_;
  chanETheo[k_ttW8] = (chanETheop[k_ttW8] +chanETheom[k_ttW8])/2.0;


// ttZ, Z only
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-12-014/index.html
// https://arxiv.org/abs/1303.3239, Phys. Rev. Lett. 110 (2013) 172002
  chanMeasurement[k_ttZ] = "ttZ";
  chanLumi[k_ttZ] = "5 fb^{-1}";
  chanCadi[k_ttZ] = "TOP-12-014";
  chanPreprint[k_ttZ] = "1303.3239";
  chanPublication[k_ttZ] = "PRL 110 (2013) 172002";

  chanSigma[k_ttZ]  =   0.28 * scale_; 
  chanEStatp[k_ttZ]  =   0.14 * scale_;
  chanESystp[k_ttZ]  =   0.06 * scale_;
  chanETotp[k_ttZ]   =  sqrt( 
			   chanEStatp[k_ttZ]*chanEStatp[k_ttZ]
			   +
			   chanESystp[k_ttZ]*chanESystp[k_ttZ]
			    );

  chanEStatm[k_ttZ]  =   0.11 * scale_;
  chanESystm[k_ttZ]  =   0.03 * scale_;
  chanETotm[k_ttZ]   =  sqrt( 
			   chanEStatm[k_ttZ]*chanEStatm[k_ttZ]
			   +
			   chanESystm[k_ttZ]*chanESystm[k_ttZ]
			    );
  chanEStat[k_ttZ] = (chanEStatp[k_ttZ] +chanEStatm[k_ttZ])/2.0;
  chanESyst[k_ttZ] = (chanESystp[k_ttZ] +chanESystm[k_ttZ])/2.0;
  chanETot[k_ttZ] = (chanETotp[k_ttZ] +chanETotm[k_ttZ])/2.0;
 


  chanTheo[k_ttZ] =   0.137 * scale_;
  chanETheop[k_ttZ] =  0.012 * scale_;
  chanETheom[k_ttZ] =  0.016 * scale_;
  chanETheo[k_ttZ] = (chanETheop[k_ttZ] +chanETheom[k_ttZ])/2.0;

// ttZ CMS TOP 14 021
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-14-021/index.html
// https://arxiv.org/abs/1510.01131, JHEP 01 (2016) 096
  chanMeasurement[k_ttZ8] = "ttZ";
  chanLumi[k_ttZ8] = "19.8 fb^{-1}";
  chanCadi[k_ttZ8] = "TOP-14-021";
  chanPreprint[k_ttZ8] = "1510.01131";
  chanPublication[k_ttZ8] = "JHEP 01 (2016) 096";


  chanSigma[k_ttZ8]  =   0.242 * scale_; 
  chanEStatp[k_ttZ8]  =   0.065 * scale_;
  chanESystp[k_ttZ8]  =   0.00 * scale_;
  chanETotp[k_ttZ8]   =  sqrt( 
			   chanEStatp[k_ttZ8]*chanEStatp[k_ttZ8]
			   +
			   chanESystp[k_ttZ8]*chanESystp[k_ttZ8]
			    );

  chanEStatm[k_ttZ8]  =   0.055 * scale_;
  chanESystm[k_ttZ8]  =   0.0 * scale_;
  chanETotm[k_ttZ8]   =  sqrt( 
			   chanEStatm[k_ttZ8]*chanEStatm[k_ttZ8]
			   +
			   chanESystm[k_ttZ8]*chanESystm[k_ttZ8]
			    );
  chanEStat[k_ttZ8] = (chanEStatp[k_ttZ8] +chanEStatm[k_ttZ8])/2.0;
  chanESyst[k_ttZ8] = (chanESystp[k_ttZ8] +chanESystm[k_ttZ8])/2.0;
  chanETot[k_ttZ8] = (chanETotp[k_ttZ8] +chanETotm[k_ttZ8])/2.0;
 


  chanTheo[k_ttZ8] =   0.206 * scale_;
  chanETheop[k_ttZ8] = 0.019 * scale_;
  chanETheom[k_ttZ8] =  0.024 * scale_;
  chanETheo[k_ttZ8] = (chanETheop[k_ttZ8] +chanETheom[k_ttZ8])/2.0;


// ttW 13 TeV (ttZ taken from below
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-17-005/index.html
// https://arxiv.org/abs/1711.02547  JHEP 08 (2018) 011
// replaced with TOP-21-011
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-21-011/index.html
// https://cds.cern.ch/record/2804479

  chanMeasurement[k_ttW13] = "ttW";
  chanLumi[k_ttW13] = "138 fb^{-1}";
  chanCadi[k_ttW13] = "TOP-21-011";
  chanPreprint[k_ttW13] = "https://cds.cern.ch/record/2804479";
  chanPublication[k_ttW13] = "";


  chanSigma[k_ttW13]  =   0.868 * scale_; 
  chanEStatp[k_ttW13]  =   0.040 * scale_;
  chanESystp[k_ttW13]  =   0.052 * scale_;
  chanETotp[k_ttW13]   =  sqrt( 
			   chanEStatp[k_ttW13]*chanEStatp[k_ttW13]
			   +
			   chanESystp[k_ttW13]*chanESystp[k_ttW13]
			    );

  chanEStatm[k_ttW13]  =   0.040 * scale_;
  chanESystm[k_ttW13]  =   0.050 * scale_;
  chanETotm[k_ttW13]   =  sqrt( 
			   chanEStatm[k_ttW13]*chanEStatm[k_ttW13]
			   +
			   chanESystm[k_ttW13]*chanESystm[k_ttW13]
			    );
  chanEStat[k_ttW13] = (chanEStatp[k_ttW13] +chanEStatm[k_ttW13])/2.0;
  chanESyst[k_ttW13] = (chanESystp[k_ttW13] +chanESystm[k_ttW13])/2.0;
  chanETot[k_ttW13] = (chanETotp[k_ttW13] +chanETotm[k_ttW13])/2.0;
 


  chanTheo[k_ttW13] =   0.592 * scale_;
chanETheop[k_ttW13] = sqrt(0.155*0.155+0.012*0.012) * scale_;
chanETheom[k_ttW13] = sqrt(0.096*0.096+0.012*0.012) * scale_;
  chanETheo[k_ttW13] = (chanETheop[k_ttW13] +chanETheom[k_ttW13])/2.0;


// ttZ at 13 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-18-009/
// https://arxiv.org/abs/1907.11270
// JHEP 03 (2020) 056

  chanMeasurement[k_ttZ13] = "ttZ";
  chanLumi[k_ttZ13] = "77.5 fb^{-1}";
  chanCadi[k_ttZ13] = "TOP-18-009";
  chanPreprint[k_ttZ13] = "1907.11270";
  chanPublication[k_ttZ13] = "JHEP 03 (2020) 056";


  chanSigma[k_ttZ13]  =   0.95 * scale_; 
  chanEStatp[k_ttZ13]  =   0.05 * scale_;
  chanESystp[k_ttZ13]  =   0.06 * scale_;
  chanETotp[k_ttZ13]   =  sqrt( 
			   chanEStatp[k_ttZ13]*chanEStatp[k_ttZ13]
			   +
			   chanESystp[k_ttZ13]*chanESystp[k_ttZ13]
			    );

  chanEStatm[k_ttZ13]  =   0.05 * scale_;
  chanESystm[k_ttZ13]  =   0.06 * scale_;
  chanETotm[k_ttZ13]   =  sqrt( 
			   chanEStatm[k_ttZ13]*chanEStatm[k_ttZ13]
			   +
			   chanESystm[k_ttZ13]*chanESystm[k_ttZ13]
			    );
  chanEStat[k_ttZ13] = (chanEStatp[k_ttZ13] +chanEStatm[k_ttZ13])/2.0;
  chanESyst[k_ttZ13] = (chanESystp[k_ttZ13] +chanESystm[k_ttZ13])/2.0;
  chanETot[k_ttZ13] = (chanETotp[k_ttZ13] +chanETotm[k_ttZ13])/2.0;
 



  chanTheo[k_ttZ13] =   0.86 * scale_;
  chanETheop[k_ttZ13] = sqrt(0.07*0.07+0.03*0.03) * scale_;
  chanETheom[k_ttZ13] =  sqrt(0.08*0.08+0.03*0.03) * scale_;
  chanETheo[k_ttZ13] = (chanETheop[k_ttZ13] +chanETheom[k_ttZ13])/2.0;




// tZq CMS TOP 12 039
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-12-039/index.html
// https://arxiv.org/abs/1702.01404, submitted to JHEP
// Account for BF

  //scale_ = scale_/(4.0*Z0_br_ll*W_br_lnu);
  scale_ = 236.8/8.18;
  chanMeasurement[k_tZq8] = "tZq";
  chanLumi[k_tZq8] = "19.7 fb^{-1}";
  chanCadi[k_tZq8] = "TOP-12-039";
  chanPreprint[k_tZq8] = "1702.01404";
  chanPublication[k_tZq8] = "JHEP 07 (2017) 003";


  chanSigma[k_tZq8]  =   0.010 * scale_; 
  chanEStatp[k_tZq8]  =   0.008 * scale_;
  chanESystp[k_tZq8]  =   0.00 * scale_;
  chanETotp[k_tZq8]   =  sqrt( 
			   chanEStatp[k_tZq8]*chanEStatp[k_tZq8]
			   +
			   chanESystp[k_tZq8]*chanESystp[k_tZq8]
			    );

  chanEStatm[k_tZq8]  =   0.007 * scale_;
  chanESystm[k_tZq8]  =   0.0 * scale_;
  chanETotm[k_tZq8]   =  sqrt( 
			   chanEStatm[k_tZq8]*chanEStatm[k_tZq8]
			   +
			   chanESystm[k_tZq8]*chanESystm[k_tZq8]
			    );
  chanEStat[k_tZq8] = (chanEStatp[k_tZq8] +chanEStatm[k_tZq8])/2.0;
  chanESyst[k_tZq8] = (chanESystp[k_tZq8] +chanESystm[k_tZq8])/2.0;
  chanETot[k_tZq8] = (chanETotp[k_tZq8] +chanETotm[k_tZq8])/2.0;
 
  scale_ = 1.0; 

  chanTheo[k_tZq8] =   0.236 * scale_;
  chanETheop[k_tZq8] = sqrt(0.011*0.011 + 0.011*0.011) * scale_;
  chanETheom[k_tZq8] = sqrt(0.004*0.004 + 0.011*0.011)  * scale_;
  chanETheo[k_tZq8] = (chanETheop[k_tZq8] +chanETheom[k_tZq8])/2.0;

  scale_ = 1.0;


// tZq at 13 TeV
// https://arxiv.org/abs/1712.02825 submitted to PLB
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-16-020/
// replaced with
// https://arxiv.org/abs/1812.05900 Phys. Rev. Lett. 122, 132003 (2019)
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-18-008/
// replaced with
// https://arxiv.org/abs/2111.02860 Submitted to JHEP.
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-20-010/


scale_ = scale_/(3.0*Z0_br_ll);

  chanMeasurement[k_tZq13] = "tZq";
  chanLumi[k_tZq13] = "138 fb^{-1}";
  chanCadi[k_tZq13] = "TOP-20-010";
  chanPreprint[k_tZq13] = "2111.02860";
  chanPublication[k_tZq13] = "Submitted to JHEP";


  chanSigma[k_tZq13]  =   0.0879 * scale_; 
  chanEStatp[k_tZq13]  =   0.0075 * scale_;
  chanESystp[k_tZq13]  =   0.0073 * scale_;
  chanETotp[k_tZq13]   =  sqrt( 
			   chanEStatp[k_tZq13]*chanEStatp[k_tZq13]
			   +
			   chanESystp[k_tZq13]*chanESystp[k_tZq13]
			    );

  chanEStatm[k_tZq13]  =   0.0073 * scale_;
  chanESystm[k_tZq13]  =   0.0060 * scale_;
  chanETotm[k_tZq13]   =  sqrt( 
			   chanEStatm[k_tZq13]*chanEStatm[k_tZq13]
			   +
			   chanESystm[k_tZq13]*chanESystm[k_tZq13]
			    );
  chanEStat[k_tZq13] = (chanEStatp[k_tZq13] +chanEStatm[k_tZq13])/2.0;
  chanESyst[k_tZq13] = (chanESystp[k_tZq13] +chanESystm[k_tZq13])/2.0;
  chanETot[k_tZq13] = (chanETotp[k_tZq13] +chanETotm[k_tZq13])/2.0;
 

  chanTheo[k_tZq13] =   0.0942 * scale_;
  chanETheop[k_tZq13] = sqrt(0.0019*0.0019 + 0.0025*0.0025) * scale_;
  chanETheom[k_tZq13] = sqrt(0.0018*0.0018 + 0.0025*0.0025)  * scale_;
  chanETheo[k_tZq13] = (chanETheop[k_tZq13] +chanETheom[k_tZq13])/2.0;

  scale_ = 1.0;


// tg CMS TOP 17 016
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-17-016/index.html
// https://arxiv.org/abs/1808.02913
// Phys. Rev. Lett. 121, 221802 (2018)

// Scale by branching ratio?

scale_ = 1/W_br_lnu;

  chanMeasurement[k_tg13] = "t#gamma";
  if (exportExeFormat) chanMeasurement[k_tg13] = "t$\\gamma$";
  chanLumi[k_tg13] = "35.9 fb^{-1}";
  chanCadi[k_tg13] = "TOP-17-016";
  chanPreprint[k_tg13] = "1808.02913";
  chanPublication[k_tg13] = "PRL 121 221802 (2018)";


  chanSigma[k_tg13]  =   0.115 * scale_; 
  chanEStatp[k_tg13]  =   0.017 * scale_;
  chanESystp[k_tg13]  =   0.030 * scale_;
  chanETotp[k_tg13]   =  sqrt( 
			   chanEStatp[k_tg13]*chanEStatp[k_tg13]
			   +
			   chanESystp[k_tg13]*chanESystp[k_tg13]
			    );

  chanEStatm[k_tg13]  =   0.017 * scale_;
  chanESystm[k_tg13]  =   0.030 * scale_;
  chanETotm[k_tg13]   =  sqrt( 
			   chanEStatm[k_tg13]*chanEStatm[k_tg13]
			   +
			   chanESystm[k_tg13]*chanESystm[k_tg13]
			    );
  chanEStat[k_tg13] = (chanEStatp[k_tg13] +chanEStatm[k_tg13])/2.0;
  chanESyst[k_tg13] = (chanESystp[k_tg13] +chanESystm[k_tg13])/2.0;
  chanETot[k_tg13] = (chanETotp[k_tg13] +chanETotm[k_tg13])/2.0;
 


  chanTheo[k_tg13] =   0.081 * scale_;
  chanETheop[k_tg13] = 0.004 * scale_;
  chanETheom[k_tg13] =  0.004 * scale_;
  chanETheo[k_tg13] = (chanETheop[k_tg13] +chanETheom[k_tg13])/2.0;


scale_ = 1.0;

// tttt CMS TOP at 8 TeV
//
// https://arxiv.org/abs/1409.7339, JHEP 11 (2014) 154


  chanMeasurement[k_tttt8] = "tttt";
  chanLumi[k_tttt8] = "19.6 fb^{-1}";
  chanCadi[k_tttt8] = "TOP-13-012";
  chanPreprint[k_tttt8] = "1409.7339";
  chanPublication[k_tttt8] = "JHEP 11 (2014) 154";


  chanSigma[k_tttt8]  =   -0.032 * scale_; 
  chanEStatp[k_tttt8]  =   0.00 * scale_;
  chanESystp[k_tttt8]  =   0.00 * scale_;
  chanETotp[k_tttt8]   =  sqrt( 
			   chanEStatp[k_tttt8]*chanEStatp[k_tttt8]
			   +
			   chanESystp[k_tttt8]*chanESystp[k_tttt8]
			    );

  chanEStatm[k_tttt8]  =   0.00 * scale_;
  chanESystm[k_tttt8]  =   0.0 * scale_;
  chanETotm[k_tttt8]   =  sqrt( 
			   chanEStatm[k_tttt8]*chanEStatm[k_tttt8]
			   +
			   chanESystm[k_tttt8]*chanESystm[k_tttt8]
			    );
  chanEStat[k_tttt8] = (chanEStatp[k_tttt8] +chanEStatm[k_tttt8])/2.0;
  chanESyst[k_tttt8] = (chanESystp[k_tttt8] +chanESystm[k_tttt8])/2.0;
  chanETot[k_tttt8] = (chanETotp[k_tttt8] +chanETotm[k_tttt8])/2.0;
 


  chanTheo[k_tttt8] =   (0.0013) * scale_;
  chanETheop[k_tttt8] =  chanTheo[k_tttt8] * 0.3 * scale_;
  chanETheom[k_tttt8] =  chanTheo[k_tttt8] * 0.3 * scale_;
  chanETheo[k_tttt8] = (chanETheop[k_tttt8] +chanETheom[k_tttt8])/2.0;

 


// tttt CMS TOP 17 009 at 13 TeV
// https://arxiv.org/abs/1710.10614 Eur. Phys. J. C 78 (2018) 140
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-17-009/
// Combined with
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-17-019/index.html
// replaced with TOP-18-003
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-18-003/index.html
// https://arxiv.org/abs/1908.06463
// Eur. Phys. J. C 80 (2020) 75


  chanMeasurement[k_tttt13] = "tttt";
  chanLumi[k_tttt13] = "137 fb^{-1}";
  chanCadi[k_tttt13] = "TOP-18-003";
  chanPreprint[k_tttt13] = "1908.06463";
  chanPublication[k_tttt13] = "EPJC 80 (2020) 75";


//chanSigma[k_tttt13]  =   0.013 * scale_; 
  chanSigma[k_tttt13]  =   0.0126 * scale_; 
//  chanEStatp[k_tttt13]  =   0.011 * scale_;
  chanEStatp[k_tttt13]  =   0.0058 * scale_;
  chanESystp[k_tttt13]  =   0.00 * scale_;
  chanETotp[k_tttt13]   =  sqrt( 
			   chanEStatp[k_tttt13]*chanEStatp[k_tttt13]
			   +
			   chanESystp[k_tttt13]*chanESystp[k_tttt13]
			    );

//chanEStatm[k_tttt13]  =   0.009 * scale_;
  chanEStatm[k_tttt13]  =   0.0052 * scale_;
  chanESystm[k_tttt13]  =   0.0 * scale_;
  chanETotm[k_tttt13]   =  sqrt( 
			   chanEStatm[k_tttt13]*chanEStatm[k_tttt13]
			   +
			   chanESystm[k_tttt13]*chanESystm[k_tttt13]
			    );
  chanEStat[k_tttt13] = (chanEStatp[k_tttt13] +chanEStatm[k_tttt13])/2.0;
  chanESyst[k_tttt13] = (chanESystp[k_tttt13] +chanESystm[k_tttt13])/2.0;
  chanETot[k_tttt13] = (chanETotp[k_tttt13] +chanETotm[k_tttt13])/2.0;
 


chanTheo[k_tttt13] =   (0.0120) * scale_;
  chanETheop[k_tttt13] =  0.0022* scale_;
  chanETheom[k_tttt13] =  0.0025 * scale_;
  chanETheo[k_tttt13] = (chanETheop[k_tttt13] +chanETheom[k_tttt13])/2.0;

  scale_ = 1.0;





// diboson results

// Wgamma
// CMS-EWK-11-009
// https://arxiv.org/abs/1308.6832 Phys. Rev. D 89 (2014) 092005

//chanMeasurement[k_Wg] = "W#gamma), #scale[0.7]{E_{T}^{ #gamma} > 15}";
  chanMeasurement[k_Wg] = "W#gamma";
  if (exportExeFormat) chanMeasurement[k_Wg] = "W$\\gamma$";
  if (version==5) chanMeasurement[k_Wg] = "W#gamma, #scale[0.70]{(NLO th.)}";
  chanLumi[k_Wg] = "5.0 fb^{-1}";
  chanCadi[k_Wg] = "EWK-11-009";
  chanPreprint[k_Wg] = "1308.6832";
  chanPublication[k_Wg] = "PRD 89 (2014) 092005";



  scale_ = (1./W_br_lnu);

  chanSigma[k_Wg]  =  37.0 * scale_; 
  chanEStat[k_Wg]  =  0.8 * scale_;
  chanESyst[k_Wg]  =  4.079 * scale_;
  chanETot[k_Wg]   =  sqrt( 
			   chanEStat[k_Wg]*chanEStat[k_Wg]
			   +
			   chanESyst[k_Wg]*chanESyst[k_Wg]
			    );
  chanTheo[k_Wg] =  31.81 * scale_;
  chanETheo[k_Wg] =  1.8 * scale_;

  scale_ = 1.;


// Wg
// https://arxiv.org/abs/2102.02283 Phys. Rev. Lett. 126, 252002 (2021)
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-19-002

// Wgamma
  chanMeasurement[k_Wg13] = "W#gamma";
  if (exportExeFormat) chanMeasurement[k_Wg13] = "W$\\gamma$";
  if (version==5) chanMeasurement[k_Wg13] = "W#gamma, #scale[0.70]{(NLO th.)}";
  chanLumi[k_Wg13] = "137 fb^{-1}";
  chanCadi[k_Wg13] = "SMP-19-002";
  chanPreprint[k_Wg13] = "2102.02283";
  chanPublication[k_Wg13] = "PRL 126 252002 (2021)";

  scale_ = (1./W_br_lnu);

  chanSigma[k_Wg13]  =  15.58 * scale_; 
  chanEStat[k_Wg13]  =  0.05 * scale_;
chanESyst[k_Wg13]  =  sqrt(0.73*0.73+0.15*0.15) * scale_;
  chanETot[k_Wg13]   =  sqrt( 
			   chanEStat[k_Wg13]*chanEStat[k_Wg13]
			   +
			   chanESyst[k_Wg13]*chanESyst[k_Wg13]
			    );
  chanTheo[k_Wg13] =  15.4 * scale_;
chanETheo[k_Wg13] =  sqrt(1.2*1.2+0.1*0.1) * scale_;
// scale pdf from Madgraph NLO

  scale_ = 1.;


// Wg + 2jet 13 TeV
// SMP-19-008
// https://arxiv.org/abs/2008.10521 Phys. Lett. B 811 (2020) 135988
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-19-008/
// updated to
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-21-011/index.html
// 2jet



  scale_ = scale_/1000.0;

  chanMeasurement[k_Wg2jet13] = "#splitline{W#gamma}{2j}";;
  if (exportExeFormat) chanMeasurement[k_Wg2jet13] = "W$\\gamma$2j";
  chanLumi[k_Wg2jet13]= "138 fb^{-1}";
  chanCadi[k_Wg2jet13] = "SMP-20-011";
  chanPreprint[k_Wg2jet13] = "https://cds.cern.ch/record/2809554";
  chanPublication[k_Wg2jet13] = "";


  chanSigma[k_Wg2jet13]  =  90.0 * scale_; 
  chanEStatp[k_Wg2jet13]  =   1.6 * scale_;
  chanEStatm[k_Wg2jet13]  =   1.6 * scale_;
  chanEStat[k_Wg2jet13]  = ( chanEStatp[k_Wg2jet13] + chanEStatm[k_Wg2jet13])/2.0;

  chanESystp[k_Wg2jet13]  =    sqrt(2.0*2.0+ 10.0*10.0) * scale_;
  chanESystm[k_Wg2jet13]  =    sqrt(1.8*1.8+ 10.0*10.0) * scale_;
  chanESyst[k_Wg2jet13]  = ( chanESystp[k_Wg2jet13] + chanESystm[k_Wg2jet13])/2.0;

  chanETotp[k_Wg2jet13]   =  sqrt( 
			   chanEStatp[k_Wg2jet13]*chanEStatp[k_Wg2jet13]
			   +
			   chanESystp[k_Wg2jet13]*chanESystp[k_Wg2jet13]
			    );
  chanETotm[k_Wg2jet13]   =  sqrt( 
			   chanEStatm[k_Wg2jet13]*chanEStatm[k_Wg2jet13]
			   +
			   chanESystm[k_Wg2jet13]*chanESystm[k_Wg2jet13]
			    );


  chanETot[k_Wg2jet13]   =  sqrt( 
			   chanEStat[k_Wg2jet13]*chanEStat[k_Wg2jet13]
			   +
			   chanESyst[k_Wg2jet13]*chanESyst[k_Wg2jet13]
			    );

// Theory
  chanTheo[k_Wg2jet13] =   90.0/0.98 * scale_;
  chanETheop[k_Wg2jet13] =  10.0 * scale_;
  chanETheom[k_Wg2jet13] =  10.0 * scale_;
  chanETheo[k_Wg2jet13 ] =  (chanETheop[k_Wg2jet13]+chanETheom[k_Wg2jet13])/2.0;

  scale_ = 1.0;



// Zg
//  chanMeasurement[k_Zg] = "Z#gamma),  #scale[0.7]{E_{T}^{ #gamma} > 15}";
  chanMeasurement[k_Zg] = "Z#gamma";
  if (exportExeFormat) chanMeasurement[k_Zg] = "Z$\\gamma$";
  if (version==5) chanMeasurement[k_Zg] = "Z#gamma, #scale[0.70]{(NLO th.)}";
  chanLumi[k_Zg] = "5.0 fb^{-1}";
  chanCadi[k_Zg] = "EWK-11-009";
  chanPreprint[k_Zg] = "1308.6832";
  chanPublication[k_Zg] = "PRD 89 (2014) 092005";


  scale_ = (1./Z0_br_ll);

  chanSigma[k_Zg]  =  5.33 * scale_; 
  chanEStat[k_Zg]  =  0.08 * scale_;
  chanESyst[k_Zg]  =  0.2773 * scale_;
  chanETot[k_Zg]   =  sqrt( 
			   chanEStat[k_Zg]*chanEStat[k_Zg]
			   +
			   chanESyst[k_Zg]*chanESyst[k_Zg]
			    );
  chanTheo[k_Zg] =  5.45 * scale_;
  chanETheo[k_Zg] = 0.27 * scale_;
  // Et > 15 R>0.7

  scale_ = 1.;

// Zg 8 TeV
// SMP-13-014
// https://arxiv.org/abs/1502.05664 JHEP 04 (2015) 164

chanMeasurement[k_Zg8] = "Z#gamma";
  if (exportExeFormat) chanMeasurement[k_Zg8] = "Z$\\gamma$";
  if (version==5) chanMeasurement[k_Zg8] = "Z#gamma, #scale[0.70]{(NLO th.)}";
  chanLumi[k_Zg8] = "19.5 fb^{-1}";
  chanCadi[k_Zg8] = "SMP-13-014";
  chanPreprint[k_Zg8] = "1502.05664";
  chanPublication[k_Zg8] = "JHEP 04 (2015) 164";


  scale_ = ((6.4500/2100.0)/Z0_br_ll);

  chanSigma[k_Zg8]  =  2063.0 * scale_; 
  chanEStat[k_Zg8]  =  19.0 * scale_;
chanESyst[k_Zg8]  =  sqrt(98.0*98.0 + 54.0*54.0) * scale_;
  chanETot[k_Zg8]   =  sqrt( 
			   chanEStat[k_Zg8]*chanEStat[k_Zg8]
			   +
			   chanESyst[k_Zg8]*chanESyst[k_Zg8]
			    );
  chanTheo[k_Zg8] =  2100.0 * scale_;
  chanETheo[k_Zg8] = 120.0 * scale_;
  // Et > 15 R>0.7

  scale_ = 1.;

// Zg 13 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-16-004/index.html
// in nunull

//   chanMeasurement[k_Zg13] = "Z#gamma";

//   chanLumi[k_Zg13] = "2.3 fb^{-1}";
// scale_ = 1/Z0_br_nunu;
//   chanSigma[k_Zg13]  =  66.5 * scale_; 
//   chanEStat[k_Zg13]  =  13.6 * scale_;
// chanESyst[k_Zg13]  =  sqrt(14.3*14.3 + 2.2*2.2) * scale_;
//   chanETot[k_Zg13]   =  sqrt( 
// 			   chanEStat[k_Zg13]*chanEStat[k_Zg13]
// 			   +
// 			   chanESyst[k_Zg13]*chanESyst[k_Zg13]
// 			    );
//   chanTheo[k_Zg13] =  65.5 * scale_;
//   chanETheo[k_Zg13] = 3.3 * scale_;
//   // NNLO

//   scale_ = 1.;

// Zg + 2jet 13 TeV
// SMP-20-016
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-20-016/index.html
// https://arxiv.org/abs/2106.11082 Phys. Rev. D 104, 072001 (2021)

  scale_ = scale_/1000.0;

  chanMeasurement[k_Zg2jet13] = "#splitline{Z#gamma}{2j}";;
  if (exportExeFormat) chanMeasurement[k_Zg2jet13] = "Z$\\gamma$2j";
  chanLumi[k_Zg2jet13]= "137 fb^{-1}";
  chanCadi[k_Zg2jet13] = "SMP-20-016";
  chanPreprint[k_Zg2jet13] = "2106.11082";
  chanPublication[k_Zg2jet13] = "PRD 104 072001 (2021)";

  chanSigma[k_Zg2jet13]  =  14.7 * scale_; 
  chanEStatp[k_Zg2jet13]  =   0.80 * scale_;
  chanEStatm[k_Zg2jet13]  =   0.80 * scale_;
  chanEStat[k_Zg2jet13]  = ( chanEStatp[k_Zg2jet13] + chanEStatm[k_Zg2jet13])/2.0;

  chanESystp[k_Zg2jet13]  =    1.26* scale_;
  chanESystm[k_Zg2jet13]  =    1.26* scale_;
  chanESyst[k_Zg2jet13]  = ( chanESystp[k_Zg2jet13] + chanESystm[k_Zg2jet13])/2.0;

  chanETotp[k_Zg2jet13]   =  sqrt( 
			   chanEStatp[k_Zg2jet13]*chanEStatp[k_Zg2jet13]
			   +
			   chanESystp[k_Zg2jet13]*chanESystp[k_Zg2jet13]
			    );
  chanETotm[k_Zg2jet13]   =  sqrt( 
			   chanEStatm[k_Zg2jet13]*chanEStatm[k_Zg2jet13]
			   +
			   chanESystm[k_Zg2jet13]*chanESystm[k_Zg2jet13]
			    );


  chanETot[k_Zg2jet13]   =  sqrt( 
			   chanEStat[k_Zg2jet13]*chanEStat[k_Zg2jet13]
			   +
			   chanESyst[k_Zg2jet13]*chanESyst[k_Zg2jet13]
			    );

// Theory
  chanTheo[k_Zg2jet13] =   13.3 * scale_;
  chanETheop[k_Zg2jet13] =  1.72 * scale_;
  chanETheom[k_Zg2jet13] =  0.10 * scale_;
  chanETheo[k_Zg2jet13 ] =  (chanETheop[k_Zg2jet13]+chanETheom[k_Zg2jet13])/2.0;

  scale_ = 1.0;



// WV
  chanMeasurement[k_WV] = "WW+WZ";
  chanLumi[k_WV] = "4.9 fb^{-1}";
  chanCadi[k_WV] = "SMP-12-015";
  chanPreprint[k_WV] = "1210.7544";
  chanPublication[k_WV] = "EPJC 73 (2013) 2283";



  chanSigma[k_WV]  =  68.9 * scale_; 
  chanEStat[k_WV]  =   8.7 * scale_;
  chanESyst[k_WV]  =   9.815 * scale_;
  chanETot[k_WV]   =  sqrt( 
			   chanEStat[k_WV]*chanEStat[k_WV]
			   +
			   chanESyst[k_WV]*chanESyst[k_WV]
			    );
  chanTheo[k_WV] =  65.6 * scale_;
  chanETheo[k_WV] =  2.2 * scale_;
// Update to NNLO
//
  chanTheo[k_WV] =  68.22 * scale_;
  chanETheo[k_WV] = 1.292 * scale_;
// sqrt(49.04*0.0195*49.04*0.0195 +19.18*0.0175*19.18*0.0175)= 1.013
// or fully correlated: 49.04*0.0195 +19.18*0.0175 = 1.292

// WW production
// SMP-12-005
// https://arxiv.org/abs/1306.1126 Eur. Phys. J. C 73 (2013) 2610

  chanMeasurement[k_WW] = "WW";
  //if (version == 5 )chanMeasurement[k_WW]= "WW, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_WW]= "4.9 fb^{-1}";
  chanCadi[k_WW] = "SMP-12-005";
  chanPreprint[k_WW] = "1306.1126";
  chanPublication[k_WW] = "EPJC 73 (2013) 2610";

  chanSigma[k_WW]  =  52.4 * scale_; 
  chanEStat[k_WW]  =   2.0 * scale_;
  chanESyst[k_WW]  =   4.657 * scale_;
  chanETot[k_WW]   =  sqrt( 
			   chanEStat[k_WW]*chanEStat[k_WW]
			   +
			   chanESyst[k_WW]*chanESyst[k_WW]
			    );
  chanTheo[k_WW] =  49.04 * scale_;
  chanETheo[k_WW] =  chanTheo[k_WW] * 0.0195 * scale_;
// +2.2% - 1.8%

// // WW 8 TeV
//   chanMeasurement[k_WW8]= "WW";
//   chanLumi[k_WW8]= "3.5 fb^{-1}";

//   chanSigma[k_WW8]  =  69.9 * scale_; 
//   chanEStat[k_WW8]  =   2.8 * scale_;
//   chanESyst[k_WW8]  =   6.401 * scale_;
//   chanETot[k_WW8]   =  sqrt( 
// 			   chanEStat[k_WW8]*chanEStat[k_WW8]
// 			   +
// 			   chanESyst[k_WW8]*chanESyst[k_WW8]
// 			    );
//   chanTheo[k_WW8] =  57.3 * scale_;
//   chanETheo[k_WW8] =  2.4 * scale_;
// // theo +2.4-1.6
// // use upper error since cross section is up


// WW 8 TeV 
// SMP-14-016
// https://arxiv.org/abs/1507.03268 Eur. Phys. J. C 76 (2016) 401

  chanMeasurement[k_WW8]= "WW";
  //if (version == 5 )chanMeasurement[k_WW8]= "WW, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_WW8]= "19.4 fb^{-1}";
  chanCadi[k_WW8] = "SMP-14-016";
  chanPreprint[k_WW8] = "1507.03268";
  chanPublication[k_WW8] = "EPJC 76 (2016) 401";



  chanSigma[k_WW8]  =  60.1 * scale_; 
  chanEStat[k_WW8]  =   0.9 * scale_;
chanESyst[k_WW8]  =   sqrt(3.2*3.2 + 3.1*3.1 + 1.6*1.6) * scale_;
  chanETot[k_WW8]   =  sqrt( 
			   chanEStat[k_WW8]*chanEStat[k_WW8]
			   +
			   chanESyst[k_WW8]*chanESyst[k_WW8]
			    );
  chanTheo[k_WW8] =  59.84 * scale_;
  chanETheo[k_WW8] =  chanTheo[k_WW8] * 0.0205  * scale_;
// theo +2.2% - 1.9%

//WW 13 TeV 
//updated to SMP-18-004
//http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-18-004/index.html
//https://arxiv.org/abs/2009.00119 Phys. Rev. D 102, 092001 (2020)

  chanMeasurement[k_WW13]= "WW";
  //if (version == 5 )chanMeasurement[k_WW13]= "WW, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_WW13]= "35.9 fb^{-1}";
  chanCadi[k_WW13] = "SMP-18-004";
  chanPreprint[k_WW13] = "2009.00119";
  chanPublication[k_WW13] = "PRD 102 092001 (2020)";


//  chanSigma[k_WW13]  =  115.3 * scale_; 
//  chanEStat[k_WW13]  =   5.8 * scale_;
//  chanESyst[k_WW13]  =   sqrt(5.7*5.7 + 6.4*6.4 + 3.6*3.6) * scale_;
  chanSigma[k_WW13]  =  117.6 * scale_; 
  chanEStat[k_WW13]  =   1.4 * scale_;
  chanESyst[k_WW13]  =   sqrt(5.5*5.5 + 1.9*1.9 + 3.2*3.2) * scale_;
  chanETot[k_WW13]   =  sqrt( 
			   chanEStat[k_WW13]*chanEStat[k_WW13]
			   +
			   chanESyst[k_WW13]*chanESyst[k_WW13]
			    );
//  chanTheo[k_WW13] =  120.3 * scale_;
  chanTheo[k_WW13] =  118.8 * scale_;
  chanETheo[k_WW13] =  3.6 * scale_;
  chanETheop[k_WW13] =  3.6 * scale_;
  chanETheom[k_WW13] =  3.6 * scale_;

chanMeasurement[k_WW13]= "WW";
  //if (version == 5 )chanMeasurement[k_WW13]= "WW, #scale[0.70]{(NNLO th.)}";

// WW 13 TeV
// Fiducial WW cross section
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-18-004/index.html
chanMeasurement[k_WW13fid]= "WW";
chanLumi[k_WW13fid]= "35.9 fb^{-1}";
  chanCadi[k_WW13fid] = "SMP-18-004";
  chanPreprint[k_WW13fid] = "2009.00119";
  chanPublication[k_WW13fid] = "PRD 102 092001 (2020)";


  chanSigma[k_WW13fid]  =  1.529 * scale_; 
  chanEStat[k_WW13fid]  =   0.020 * scale_;
  chanESyst[k_WW13fid]  =   sqrt(0.069*0.069 + 0.028*0.028 + 0.041*0.041) * scale_;
  chanETot[k_WW13fid]   =  sqrt( 
			   chanEStat[k_WW13fid]*chanEStat[k_WW13fid]
			   +
			   chanESyst[k_WW13fid]*chanESyst[k_WW13fid]
			    );
  chanTheo[k_WW13fid] =  1.531 * scale_;
  chanETheo[k_WW13fid] =  0.043 * scale_;


// WZ 7 TeV (and 8 TeV)
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-014/index.html
// https://arxiv.org/abs/1609.05721 Eur. Phys. J. C 77 (2017) 236


  chanMeasurement[k_WZ] = "WZ";
  //if (version == 5 )chanMeasurement[k_WZ]= "WZ, #scale[0.70]{(NNLO th.)}";  
  chanLumi[k_WZ] = "4.9 fb^{-1}";
  chanCadi[k_WZ] = "SMP-14-014";
  chanPreprint[k_WZ] = "1609.05721";
  chanPublication[k_WZ] = "EPJC 77 (2017) 236";

// 1.1 fb-1 version
//  chanSigma[k_WZ]  =  17.0 * scale_; 
//  chanEStat[k_WZ]  =   2.4 * scale_;
//  chanESyst[k_WZ]  =   1.487 * scale_;

  chanSigma[k_WZ]  =  20.14 * scale_; 
  chanEStat[k_WZ]  =   1.32 * scale_;
chanESyst[k_WZ]  =   sqrt(1.13*1.13 + 0.44*0.44) * scale_;
  chanETot[k_WZ]   =  sqrt( 
			   chanEStat[k_WZ]*chanEStat[k_WZ]
			   +
			   chanESyst[k_WZ]*chanESyst[k_WZ]
			    );
//  chanTheo[k_WZ] =  17.8 * scale_;
//  chanETheo[k_WZ] =  0.6 * scale_;
// Should be NNLO
chanTheo[k_WZ] =  19.18 * scale_;
  chanETheop[k_WZ] =  0.017 * 19.18 * scale_;
  chanETheom[k_WZ] =  0.018 * 19.18 * scale_;
  chanETheo[k_WZ]   = (chanETheop[k_WZ]+chanETheom[k_WZ])/2.0;  


// WZ 8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-014/index.html
// https://arxiv.org/abs/1609.05721 EPJC 77 (2017) 236"


chanMeasurement[k_WZ8] = "WZ";
  //if (version == 5 )chanMeasurement[k_WZ8]= "WZ, #scale[0.70]{(NNLO th.)}";  
  chanLumi[k_WZ8] = "19.6 fb^{-1}";
  chanCadi[k_WZ8] = "SMP-14-014";
  chanPreprint[k_WZ8] = "1609.05721";
  chanPublication[k_WZ8] = "EPJC 77 (2017) 236";

  chanSigma[k_WZ8]  =  24.09 * scale_; 
  chanEStat[k_WZ8]  =   0.87 * scale_;
chanESyst[k_WZ8]  =   sqrt(1.62*1.62 + 0.63*0.63) * scale_;
  chanETot[k_WZ8]   =  sqrt( 
			   chanEStat[k_WZ]*chanEStat[k_WZ]
			   +
			   chanESyst[k_WZ]*chanESyst[k_WZ]
			    );
//  chanTheo[k_WZ8] =  21.91 * scale_;
//  chanETheo[k_WZ8] =  1.025 * scale_;
  chanTheo[k_WZ8] =  23.68 * scale_;
  chanETheop[k_WZ8] =  0.018 * 23.68 * scale_;
  chanETheom[k_WZ8] =  0.018 * 23.38 * scale_;
  chanETheo[k_WZ8]   = (chanETheop[k_WZ8]+chanETheom[k_WZ8])/2.0;  


// WZ+jets  8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-014/index.html
// https://arxiv.org/abs/1609.05721 Submitted to EPJC  77 (2017) 236

// 0 jet

scale_ = scale_* W_br_lnu * Z0_br_ll; 

  chanMeasurement[k_WZ0jet8] = "#splitline{WZ}{=0j}";
  if (exportExeFormat) chanMeasurement[k_WZ0jet8] = "WZ0j";
  chanLumi[k_WZ0jet8]= "19.6 fb^{-1}";
  chanCadi[k_WZ0jet8] = "SMP-14-014";
  chanPreprint[k_WZ0jet8] = "1609.05721";
  chanPublication[k_WZ0jet8] = "EPJC 77 (2017) 236";

  chanSigma[k_WZ0jet8]  =  16.15 * scale_; 
  chanEStatp[k_WZ0jet8]  =   1.95 * scale_;
  chanEStatm[k_WZ0jet8]  =   1.95 * scale_;
  chanEStat[k_WZ0jet8]  = ( chanEStatp[k_WZ0jet8] + chanEStatm[k_WZ0jet8])/2.0;

  chanESystp[k_WZ0jet8]  =    sqrt( 0.88*0.88+0.42*0.42)* scale_;
  chanESystm[k_WZ0jet8]  =    sqrt( 0.88*0.88+0.42*0.42 )* scale_;
  chanESyst[k_WZ0jet8]  = ( chanESystp[k_WZ0jet8] + chanESystm[k_WZ0jet8])/2.0;

  chanETotp[k_WZ0jet8]   =  sqrt( 
			   chanEStatp[k_WZ0jet8]*chanEStatp[k_WZ0jet8]
			   +
			   chanESystp[k_WZ0jet8]*chanESystp[k_WZ0jet8]
			    );
  chanETotm[k_WZ0jet8]   =  sqrt( 
			   chanEStatm[k_WZ0jet8]*chanEStatm[k_WZ0jet8]
			   +
			   chanESystm[k_WZ0jet8]*chanESystm[k_WZ0jet8]
			    );


  chanETot[k_WZ0jet8]   =  sqrt( 
			   chanEStat[k_WZ0jet8]*chanEStat[k_WZ0jet8]
			   +
			   chanESyst[k_WZ0jet8]*chanESyst[k_WZ0jet8]
			    );

// Theory
  chanTheo[k_WZ0jet8] =   14.5497 * scale_;
  chanETheop[k_WZ0jet8] =  0.005 * scale_;
  chanETheom[k_WZ0jet8] =  0.005 * scale_;
  chanETheo[k_WZ0jet8 ] =  (chanETheop[k_WZ1jet8]+chanETheom[k_WZ1jet8])/2.0;


// 1jet
  chanMeasurement[k_WZ1jet8] = "=1j";
  if (exportExeFormat) chanMeasurement[k_WZ1jet8] = "WZj";
  chanLumi[k_WZ1jet8]= "19.6 fb^{-1}";
  chanCadi[k_WZ1jet8] = "SMP-14-014";
  chanPreprint[k_WZ1jet8] = "1609.05721";
  chanPublication[k_WZ1jet8] = "EPJC 77 (2017) 236";

  chanSigma[k_WZ1jet8]  =  5.27 * scale_; 
  chanEStatp[k_WZ1jet8]  =   1.11 * scale_;
  chanEStatm[k_WZ1jet8]  =   1.11 * scale_;
  chanEStat[k_WZ1jet8]  = ( chanEStatp[k_WZ1jet8] + chanEStatm[k_WZ1jet8])/2.0;

  chanESystp[k_WZ1jet8]  =    sqrt( 0.52*0.52+0.14*0.14)* scale_;
  chanESystm[k_WZ1jet8]  =    sqrt( 0.52*0.52+0.14*0.14 )* scale_;
  chanESyst[k_WZ1jet8]  = ( chanESystp[k_WZ1jet8] + chanESystm[k_WZ1jet8])/2.0;

  chanETotp[k_WZ1jet8]   =  sqrt( 
			   chanEStatp[k_WZ1jet8]*chanEStatp[k_WZ1jet8]
			   +
			   chanESystp[k_WZ1jet8]*chanESystp[k_WZ1jet8]
			    );
  chanETotm[k_WZ1jet8]   =  sqrt( 
			   chanEStatm[k_WZ1jet8]*chanEStatm[k_WZ1jet8]
			   +
			   chanESystm[k_WZ1jet8]*chanESystm[k_WZ1jet8]
			    );


  chanETot[k_WZ1jet8]   =  sqrt( 
			   chanEStat[k_WZ1jet8]*chanEStat[k_WZ1jet8]
			   +
			   chanESyst[k_WZ1jet8]*chanESyst[k_WZ1jet8]
			    );

// Theory
  chanTheo[k_WZ1jet8] =   6.151 * scale_;
  chanETheop[k_WZ1jet8] =  0.03 * scale_;
  chanETheom[k_WZ1jet8] =  0.03 * scale_;
  chanETheo[k_WZ1jet8 ] =  (chanETheop[k_WZ1jet8]+chanETheom[k_WZ1jet8])/2.0;


// 2jet
  chanMeasurement[k_WZ2jet8] = "=2j";
  if (exportExeFormat) chanMeasurement[k_WZ2jet8] = "WZ2j";
  chanLumi[k_WZ2jet8]= "19.6 fb^{-1}";
  chanCadi[k_WZ2jet8] = "SMP-14-014";
  chanPreprint[k_WZ2jet8] = "1609.05721";
  chanPublication[k_WZ2jet8] = "EPJC 77 (2017) 236";

  chanSigma[k_WZ2jet8]  =  2.11 * scale_; 
  chanEStatp[k_WZ2jet8]  =   0.69 * scale_;
  chanEStatm[k_WZ2jet8]  =   0.69 * scale_;
  chanEStat[k_WZ2jet8]  = ( chanEStatp[k_WZ2jet8] + chanEStatm[k_WZ2jet8])/2.0;

  chanESystp[k_WZ2jet8]  =    sqrt( 0.27*0.27+0.05*0.05)* scale_;
  chanESystm[k_WZ2jet8]  =    sqrt( 0.27*0.27+0.05*0.05 )* scale_;
  chanESyst[k_WZ2jet8]  = ( chanESystp[k_WZ2jet8] + chanESystm[k_WZ2jet8])/2.0;

  chanETotp[k_WZ2jet8]   =  sqrt( 
			   chanEStatp[k_WZ2jet8]*chanEStatp[k_WZ2jet8]
			   +
			   chanESystp[k_WZ2jet8]*chanESystp[k_WZ2jet8]
			    );
  chanETotm[k_WZ2jet8]   =  sqrt( 
			   chanEStatm[k_WZ2jet8]*chanEStatm[k_WZ2jet8]
			   +
			   chanESystm[k_WZ2jet8]*chanESystm[k_WZ2jet8]
			    );


  chanETot[k_WZ2jet8]   =  sqrt( 
			   chanEStat[k_WZ2jet8]*chanEStat[k_WZ2jet8]
			   +
			   chanESyst[k_WZ2jet8]*chanESyst[k_WZ2jet8]
			    );

// Theory
chanTheo[k_WZ2jet8] =   0.929306 * scale_;
  chanETheop[k_WZ2jet8] =  0.01 * scale_;
  chanETheom[k_WZ2jet8] =  0.01 * scale_;
  chanETheo[k_WZ2jet8 ] =  (chanETheop[k_WZ2jet8]+chanETheom[k_WZ2jet8])/2.0;

// 3jet
  chanMeasurement[k_WZ3jet8] = "#geq3j";
  if (exportExeFormat) chanMeasurement[k_WZ3jet8] = "WZ3j";
  chanLumi[k_WZ3jet8]= "19.6 fb^{-1}";
  chanCadi[k_WZ3jet8] = "SMP-14-014";
  chanPreprint[k_WZ3jet8] = "1609.05721";
  chanPublication[k_WZ3jet8] = "EPJC 77 (2017) 236";

  chanSigma[k_WZ3jet8]  =  0.196 * scale_; 
  chanEStatp[k_WZ3jet8]  =   0.227 * scale_;
  chanEStatm[k_WZ3jet8]  =   0.227 * scale_;
  chanEStat[k_WZ3jet8]  = ( chanEStatp[k_WZ3jet8] + chanEStatm[k_WZ3jet8])/2.0;

  chanESystp[k_WZ3jet8]  =    sqrt( 0.102*0.102+0.005*0.005)* scale_;
  chanESystm[k_WZ3jet8]  =    sqrt( 0.102*0.102+0.005*0.005 )* scale_;
  chanESyst[k_WZ3jet8]  = ( chanESystp[k_WZ3jet8] + chanESystm[k_WZ3jet8])/2.0;

  chanETotp[k_WZ3jet8]   =  sqrt( 
			   chanEStatp[k_WZ3jet8]*chanEStatp[k_WZ3jet8]
			   +
			   chanESystp[k_WZ3jet8]*chanESystp[k_WZ3jet8]
			    );
  chanETotm[k_WZ3jet8]   =  sqrt( 
			   chanEStatm[k_WZ3jet8]*chanEStatm[k_WZ3jet8]
			   +
			   chanESystm[k_WZ3jet8]*chanESystm[k_WZ3jet8]
			    );


  chanETot[k_WZ3jet8]   =  sqrt( 
			   chanEStat[k_WZ3jet8]*chanEStat[k_WZ3jet8]
			   +
			   chanESyst[k_WZ3jet8]*chanESyst[k_WZ3jet8]
			    );

// Theory
  chanTheo[k_WZ3jet8] =   0.0333349 * scale_;
  chanETheop[k_WZ3jet8] =  0.001 * scale_;
  chanETheom[k_WZ3jet8] =  0.001 * scale_;
  chanETheo[k_WZ3jet8 ] =  (chanETheop[k_WZ3jet8]+chanETheom[k_WZ3jet8])/2.0;


scale_ = 1.0;

// WZ 13 TeV
// published https://arxiv.org/abs/1607.06943 Submitted to Phys. Lett. B
// CMS SMP-18-002
//  http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-18-002/index.html
// https://cds.cern.ch/record/2628761
// Replace with
// SMP-20-014 WZ
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-20-014/index.html
// https://arxiv.org/abs/2110.11231


  if (use13TeV) chanMeasurement[k_WZ13] = "WZ";
  //if (version == 5 && use13TeV)chanMeasurement[k_WZ13]= "WZ, #scale[0.70]{(NNLO th.)}";  
  if (big13TeV) chanMeasurement[k_WZ13]    =  "#splitline{  WZ}{13Tev}";
  chanLumi[k_WZ13] = "137 fb^{-1}";
  chanCadi[k_WZ13] = "SMP-20-014";
  chanPreprint[k_WZ13] = "2110.11231";
  chanPublication[k_WZ13] = "Submitted to JHEP";


  chanSigma[k_WZ13]  =  50.6 * scale_; 
  chanEStatp[k_WZ13]  =   0.8 * scale_;
  chanEStatm[k_WZ13]  =   0.8 * scale_;
chanEStat[k_WZ13]  = ( chanEStatp[k_WZ13] + chanEStatm[k_WZ13])/2.0;


  chanESystp[k_WZ13]  =    sqrt( 2.3*2.3+1.1*1.1+0.5*0.5)* scale_;
  chanESystm[k_WZ13]  =    sqrt( 2.3*2.3+1.1*1.1+0.5*0.5)* scale_;
  chanESyst[k_WZ13]  = ( chanESystp[k_WZ13] + chanESystm[k_WZ13])/2.0;
 

  chanETot[k_WZ13]   =  sqrt( 
			   chanEStat[k_WZ13]*chanEStat[k_WZ13]
			   +
			   chanESyst[k_WZ13]*chanESyst[k_WZ13]
			    );

  chanTheo[k_WZ13] =  50.07 * scale_;
chanETheop[k_WZ13] =  1.1 * scale_;
chanETheom[k_WZ13] =  1.0 * scale_;
  chanETheo[k_WZ13]   = (chanETheop[k_WZ13]+chanETheom[k_WZ13])/2.0;  
// Matrix NLLO + NLO EWK



// WZ 13 TeV fiducial
  if (use13TeV) chanMeasurement[k_WZ13fid] = "WZ";
  //if (version == 5 && use13TeV)chanMeasurement[k_WZ13fid]= "WZ, #scale[0.70]{(NNLO th.)}";  
  if (big13TeV) chanMeasurement[k_WZ13fid]    =  "#splitline{  WZ}{13Tev}";
  chanLumi[k_WZ13fid] = "137 fb^{-1}";
  chanCadi[k_WZ13fid] = "SMP-20-014";
  chanPreprint[k_WZ13fid] = "2110.11231";
  chanPublication[k_WZ13fid] = "Submitted to JHEP";


  chanSigma[k_WZ13fid]  =  0.2989 * scale_; 
  chanEStatp[k_WZ13fid]  =   0.0048 * scale_;
  chanEStatm[k_WZ13fid]  =   0.0048 * scale_;
chanEStat[k_WZ13fid]  = ( chanEStatp[k_WZ13fid] + chanEStatm[k_WZ13fid])/2.0;


  chanESystp[k_WZ13fid]  =    sqrt( 0.0077*0.0077+0.0054*0.0054 + 0.0027*0.0027)* scale_;
  chanESystm[k_WZ13fid]  =    sqrt(0.0077*0.0077+0.0054*0.0054 + 0.0027*0.0027)* scale_;
  chanESyst[k_WZ13fid]  = ( chanESystp[k_WZ13fid] + chanESystm[k_WZ13fid])/2.0;
 

  chanETot[k_WZ13fid]   =  sqrt( 
			   chanEStat[k_WZ13fid]*chanEStat[k_WZ13fid]
			   +
			   chanESyst[k_WZ13fid]*chanESyst[k_WZ13fid]
			    );
  chanTheo[k_WZ13fid] =  0.2981* scale_;
  chanETheop[k_WZ13fid] =  0.0069;
  chanETheom[k_WZ13fid] =  0.0063;
  chanETheo[k_WZ13fid]   = (chanETheop[k_WZ13fid]+chanETheom[k_WZ13fid])/2.0;  
// Matrix NLLO + NLO EWK

// ZZ SMP-12-007
// https://arxiv.org/abs/1211.4890 JHEP 01 (2013) 063


  chanMeasurement[k_ZZ] = "ZZ";
  //if (version == 5 )  chanMeasurement[k_ZZ] = "ZZ, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_ZZ] = "4.9 fb^{-1}";
  chanCadi[k_ZZ] = "SMP-12-007";
  chanPreprint[k_ZZ] = "1211.4890";
  chanPublication[k_ZZ] = "JHEP 01 (2013) 063";



  chanSigma[k_ZZ]  =   6.24 * scale_; 
  chanEStat[k_ZZ]  =   0.86 * scale_;
  chanESyst[k_ZZ]  =   0.4332 * scale_;
  chanETot[k_ZZ]   =  sqrt( 
			   chanEStat[k_ZZ]*chanEStat[k_ZZ]
			   +
			   chanESyst[k_ZZ]*chanESyst[k_ZZ]
			    );
  
// new NNLO number
  chanTheo[k_ZZ] =   6.46 * scale_;
  chanETheo[k_ZZ] =  0.0265 * 6.46 * scale_;
// +3.0% -2.3% 
//  chanTheo[k_ZZ] =   6.3 * scale_;
//  chanETheo[k_ZZ] =  0.4 * scale_;
// exp +0.86-0.80, +0.41-0.32, +-0.14
// symetric seems good


// 5.3 fb-1 result  
//chanSigma[k_ZZ8]  =   8.4 * scale_; 
//  chanEStat[k_ZZ8]  =   1.0 * scale_;
//  chanESyst[k_ZZ8]  =   0.8062 * scale_;


// ZZ 8 TeV CMS-SMP-13-005,
// http://arxiv.org/abs/1406.0113 Phys. Lett. B 740 (2015) 250
  chanMeasurement[k_ZZ8] = "ZZ";
  //if (version == 5 )    chanMeasurement[k_ZZ8] = "ZZ, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_ZZ8]= "19.6 fb^{-1}";
  chanCadi[k_ZZ8] = "SMP-13-005";
  chanPreprint[k_ZZ8] = "1406.0113";
  chanPublication[k_ZZ8] = "PLB 740 (2015) 250";


  chanSigma[k_ZZ8]  =   7.7 * scale_; 
  chanEStat[k_ZZ8]  =   0.5 * scale_;
  chanESyst[k_ZZ8]  =   0.6344 * scale_;
  chanETot[k_ZZ8]   =  sqrt( 
			   chanEStat[k_ZZ8]*chanEStat[k_ZZ8]
			   +
			   chanESyst[k_ZZ8]*chanESyst[k_ZZ8]
			     );

// New NNLO theory
  chanTheo[k_ZZ8] =   7.96 * scale_;
  chanETheo[k_ZZ8] =  0.028 * 7.96 * scale_;
// +3.2 - 2.4
//  chanTheo[k_ZZ8] =   7.7 * scale_;
//  chanETheo[k_ZZ8] =  0.6 * scale_;

// ZZ 13 TeV
// https://arxiv.org/abs/1709.08601 Eur. Phys. J. C 78 (2018) 165
// http://cms-results.web.cern.ch/cms-results/public-results/publicationsSMP-16-017/
// Updated to 137 fb-1
// CMS-SMP-19-001
// https://arxiv.org/abs/2009.01186 Eur. Phys. J. C 81 (2021) 200


  if (use13TeV) chanMeasurement[k_ZZ13] = "ZZ";
  //if (version == 5 && use13TeV)chanMeasurement[k_ZZ13]= "ZZ";  
  if (big13TeV) chanMeasurement[k_ZZ13]    =  "#splitline{  ZZ}{13Tev}";
  chanCadi[k_ZZ13] = "SMP-19-001";
  chanPreprint[k_ZZ13] = "2009.01186";
  chanPublication[k_ZZ13] = "EPJC 81 (2021) 200";


  chanLumi[k_ZZ13] = "137 fb^{-1}";



chanSigma[k_ZZ13]  =  17.2 * scale_; 
  chanEStatp[k_ZZ13]  =   0.3 * scale_;
  chanEStatm[k_ZZ13]  =   0.3 * scale_;
  chanEStat[k_ZZ13]  = ( chanEStatp[k_ZZ13] + chanEStatm[k_ZZ13])/2.0;


  chanESystp[k_ZZ13]  =    sqrt( 0.5*0.5 + 0.4*0.4 + 0.3*0.3)* scale_;
  chanESystm[k_ZZ13]  =    sqrt( 0.5*0.5 + 0.4*0.4 + 0.3*0.3)* scale_;
  chanESyst[k_ZZ13]  = ( chanESystp[k_ZZ13] + chanESystm[k_ZZ13])/2.0;

  chanETot[k_ZZ13]   =  sqrt( 
			   chanEStat[k_ZZ13]*chanEStat[k_ZZ13]
			   +
			   chanESyst[k_ZZ13]*chanESyst[k_ZZ13]
			    );




// New NNLO Number
chanTheo[k_ZZ13] =  16.5 * scale_;
chanETheop[k_ZZ13] =  sqrt(0.6*0.6)* scale_;
chanETheom[k_ZZ13] =  sqrt(0.5*0.5)* scale_;
  chanETheo[k_ZZ13]   = (chanETheop[k_ZZ13]+chanETheom[k_ZZ13])/2.0;  

  scale_ = 1.;


// ZZ 13 TeV fiducial
  if (use13TeV) chanMeasurement[k_ZZ13fid] = "ZZ";
if (big13TeV) chanMeasurement[k_ZZ13fid]    =  "#splitline{  ZZ}{13Tev}";
  chanLumi[k_ZZ13fid] = "137 fb^{-1}";

  chanSigma[k_ZZ13fid]  =  0.0401 * scale_; 
  chanEStatp[k_ZZ13fid]  =   0.0007 * scale_;
  chanEStatm[k_ZZ13fid]  =   0.0007 * scale_;
  chanEStat[k_ZZ13fid]  = ( chanEStatp[k_ZZ13fid] + chanEStatm[k_ZZ13fid])/2.0;


  chanESystp[k_ZZ13fid]  =    sqrt( 0.0011*0.0011 + 0.0007*0.0007)* scale_;
  chanESystm[k_ZZ13fid]  =    sqrt( 0.0011*0.0011 + 0.0007*0.0007)* scale_;
  chanESyst[k_ZZ13fid]  = ( chanESystp[k_ZZ13fid] + chanESystm[k_ZZ13fid])/2.0;
 

  chanETot[k_ZZ13fid]   =  sqrt( 
			   chanEStat[k_ZZ13fid]*chanEStat[k_ZZ13fid]
			   +
			   chanESyst[k_ZZ13fid]*chanESyst[k_ZZ13fid]
			    );


chanTheo[k_ZZ13fid] =  0.0393   * scale_;
  chanETheop[k_ZZ13fid] =  0.0008 * scale_;
  chanETheom[k_ZZ13fid] =  0.0007 * scale_;
  chanETheo[k_ZZ13fid] = (chanETheop[k_ZZ13fid]+chanETheom[k_ZZ13fid])/2.0;  



// ZZ+jets  8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-17-005/index.html
// https://arxiv.org/abs/1806.11073 PLB 789 (2019) 19
// 0 jet

  chanMeasurement[k_ZZ0jet8] = "#splitline{ZZ}{=0j}";
  if (exportExeFormat) chanMeasurement[k_ZZ0jet8] = "ZZ0j";
  chanLumi[k_ZZ0jet8]= "19.7 fb^{-1}";
  chanCadi[k_ZZ0jet8] = "SMP-17-005";
  chanPreprint[k_ZZ0jet8] = "1806.11073";
  chanPublication[k_ZZ0jet8] = "PLB 789 (2019) 19";

  chanSigma[k_ZZ0jet8]  =  0.0163 * scale_; 
  chanEStatp[k_ZZ0jet8]  =   0.0012 * scale_;
  chanEStatm[k_ZZ0jet8]  =   0.0012 * scale_;
  chanEStat[k_ZZ0jet8]  = ( chanEStatp[k_ZZ0jet8] + chanEStatm[k_ZZ0jet8])/2.0;

  chanESystp[k_ZZ0jet8]  =    sqrt( 0.001*0.001+0.0004*0.0004)* scale_;
  chanESystm[k_ZZ0jet8]  =    sqrt( 0.0009*0.0009+0.0004*0.0004 )* scale_;
  chanESyst[k_ZZ0jet8]  = ( chanESystp[k_ZZ0jet8] + chanESystm[k_ZZ0jet8])/2.0;
 
  chanETot[k_ZZ0jet8]   =  sqrt( 
			   chanEStat[k_ZZ0jet8]*chanEStat[k_ZZ0jet8]
			   +
			   chanESyst[k_ZZ0jet8]*chanESyst[k_ZZ0jet8]
			    );

// Theory
  chanTheo[k_ZZ0jet8] =   0.0132 * scale_;
  chanETheop[k_ZZ0jet8] =  0.0009 * scale_;
  chanETheom[k_ZZ0jet8] =  0.0007 * scale_;
  chanETheo[k_ZZ0jet8 ] =  (chanETheop[k_ZZ0jet8]+chanETheom[k_ZZ0jet8])/2.0;


// 1jet
  chanMeasurement[k_ZZ1jet8] = "=1j";
  if (exportExeFormat) chanMeasurement[k_ZZ1jet8] = "ZZj";
  chanLumi[k_ZZ1jet8]= "19.7 fb^{-1}";
  chanCadi[k_ZZ1jet8] = "SMP-17-005";
  chanPreprint[k_ZZ1jet8] = "1806.11073";
  chanPublication[k_ZZ1jet8] = "PLB 789 (2019) 19";

  chanSigma[k_ZZ1jet8]  =  0.0032 * scale_; 
  chanEStatp[k_ZZ1jet8]  =   0.0006 * scale_;
  chanEStatm[k_ZZ1jet8]  =   0.0006 * scale_;
  chanEStat[k_ZZ1jet8]  = ( chanEStatp[k_ZZ1jet8] + chanEStatm[k_ZZ1jet8])/2.0;

  chanESystp[k_ZZ1jet8]  =    sqrt( 0.0003*0.0003+0.0001*0.0001)* scale_;
  chanESystm[k_ZZ1jet8]  =    sqrt( 0.0003*0.0003+0.0001*0.0001 )* scale_;
  chanESyst[k_ZZ1jet8]  = ( chanESystp[k_ZZ1jet8] + chanESystm[k_ZZ1jet8])/2.0;
 
  chanETot[k_ZZ1jet8]   =  sqrt( 
			   chanEStat[k_ZZ1jet8]*chanEStat[k_ZZ1jet8]
			   +
			   chanESyst[k_ZZ1jet8]*chanESyst[k_ZZ1jet8]
			    );

// Theory
  chanTheo[k_ZZ1jet8] =   0.0040 * scale_;
  chanETheop[k_ZZ1jet8] =  0.0005 * scale_;
  chanETheom[k_ZZ1jet8] =  0.0003 * scale_;
  chanETheo[k_ZZ1jet8 ] =  (chanETheop[k_ZZ1jet8]+chanETheom[k_ZZ1jet8])/2.0;


// 2jet
  chanMeasurement[k_ZZ2jet8] = "=2j";
  if (exportExeFormat) chanMeasurement[k_ZZ2jet8] = "ZZ2j";
  chanLumi[k_ZZ2jet8]= "19.7 fb^{-1}";
  chanCadi[k_ZZ2jet8] = "SMP-17-005";
  chanPreprint[k_ZZ2jet8] = "1806.11073";
  chanPublication[k_ZZ2jet8] = "PLB 789 (2019) 19";

  chanSigma[k_ZZ2jet8]  =  0.0008 * scale_; 
  chanEStatp[k_ZZ2jet8]  =   0.0003 * scale_;
  chanEStatm[k_ZZ2jet8]  =   0.0003 * scale_;
  chanEStat[k_ZZ2jet8]  = ( chanEStatp[k_ZZ2jet8] + chanEStatm[k_ZZ2jet8])/2.0;

  chanESystp[k_ZZ2jet8]  =    sqrt( 0.0001*0.0001)* scale_;
  chanESystm[k_ZZ2jet8]  =    sqrt( 0.0001*0.0001)* scale_;
  chanESyst[k_ZZ2jet8]  = ( chanESystp[k_ZZ2jet8] + chanESystm[k_ZZ2jet8])/2.0;
 
  chanETot[k_ZZ2jet8]   =  sqrt( 
			   chanEStat[k_ZZ2jet8]*chanEStat[k_ZZ2jet8]
			   +
			   chanESyst[k_ZZ2jet8]*chanESyst[k_ZZ2jet8]
			    );

// Theory
  chanTheo[k_ZZ2jet8] =   0.0012 * scale_;
  chanETheop[k_ZZ2jet8] =  0.0002 * scale_;
  chanETheom[k_ZZ2jet8] =  0.0001 * scale_;
  chanETheo[k_ZZ2jet8 ] =  (chanETheop[k_ZZ2jet8]+chanETheom[k_ZZ2jet8])/2.0;

// 3jet
  chanMeasurement[k_ZZ3jet8] = "#geq3j";
  if (exportExeFormat) chanMeasurement[k_ZZ3jet8] = "ZZ3j";
  chanLumi[k_ZZ3jet8]= "19.7 fb^{-1}";
  chanCadi[k_ZZ3jet8] = "SMP-17-005";
  chanPreprint[k_ZZ3jet8] = "1806.11073";
  chanPublication[k_ZZ3jet8] = "PLB 789 (2019) 19";

  chanSigma[k_ZZ3jet8]  =  0.00014 * scale_; 
  chanEStatp[k_ZZ3jet8]  =   0.0001 * scale_;
  chanEStatm[k_ZZ3jet8]  =   0.0001 * scale_;
  chanEStat[k_ZZ3jet8]  = ( chanEStatp[k_ZZ3jet8] + chanEStatm[k_ZZ3jet8])/2.0;

  chanESystp[k_ZZ3jet8]  =    0.00001* scale_;
  chanESystm[k_ZZ3jet8]  =    0.00001* scale_;
  chanESyst[k_ZZ3jet8]  = ( chanESystp[k_ZZ3jet8] + chanESystm[k_ZZ3jet8])/2.0;
 
  chanETot[k_ZZ3jet8]   =  sqrt( 
			   chanEStat[k_ZZ3jet8]*chanEStat[k_ZZ3jet8]
			   +
			   chanESyst[k_ZZ3jet8]*chanESyst[k_ZZ3jet8]
			    );

// Theory
  chanTheo[k_ZZ3jet8] =   0.0003 * scale_;
  chanETheop[k_ZZ3jet8] =  0.0001 * scale_;
  chanETheom[k_ZZ3jet8] =  0.0001 * scale_;
  chanETheo[k_ZZ3jet8 ] =  (chanETheop[k_ZZ3jet8]+chanETheom[k_ZZ3jet8])/2.0;



// ZZ+jets  13 TeV
// 0 jet

  chanMeasurement[k_ZZ0jet13] = "#splitline{ZZ}{=0j}";
  if (exportExeFormat) chanMeasurement[k_ZZ0jet13] = "ZZ0j";
  chanLumi[k_ZZ0jet13]= "35.9 fb^{-1}";
  chanCadi[k_ZZ0jet13] = "SMP-17-005";
  chanPreprint[k_ZZ0jet13] = "1806.11073";
  chanPublication[k_ZZ0jet13] = "PLB 789 (2019) 19";

  chanSigma[k_ZZ0jet13]  =  0.0283 * scale_; 
  chanEStatp[k_ZZ0jet13]  =   0.0013 * scale_;
  chanEStatm[k_ZZ0jet13]  =   0.0013 * scale_;
  chanEStat[k_ZZ0jet13]  = ( chanEStatp[k_ZZ0jet13] + chanEStatm[k_ZZ0jet13])/2.0;

  chanESystp[k_ZZ0jet13]  =    sqrt( 0.0017*0.0017+0.0007*0.0007)* scale_;
  chanESystm[k_ZZ0jet13]  =    sqrt( 0.0016*0.0016+0.0007*0.0007 )* scale_;
  chanESyst[k_ZZ0jet13]  = ( chanESystp[k_ZZ0jet13] + chanESystm[k_ZZ0jet13])/2.0;
 
  chanETot[k_ZZ0jet13]   =  sqrt( 
			   chanEStat[k_ZZ0jet13]*chanEStat[k_ZZ0jet13]
			   +
			   chanESyst[k_ZZ0jet13]*chanESyst[k_ZZ0jet13]
			    );

// Theory
  chanTheo[k_ZZ0jet13] =   0.0236 * scale_;
  chanETheop[k_ZZ0jet13] =  0.0008 * scale_;
  chanETheom[k_ZZ0jet13] =  0.0009 * scale_;
  chanETheo[k_ZZ0jet13 ] =  (chanETheop[k_ZZ1jet13]+chanETheom[k_ZZ1jet13])/2.0;


// 1jet
  chanMeasurement[k_ZZ1jet13] = "=1j";
  if (exportExeFormat) chanMeasurement[k_ZZ1jet13] = "ZZj";
  chanLumi[k_ZZ1jet13]= "35.9 fb^{-1}";
  chanCadi[k_ZZ1jet13] = "SMP-17-005";
  chanPreprint[k_ZZ1jet13] = "1806.11073";
  chanPublication[k_ZZ1jet13] = "PLB 789 (2019) 19";

  chanSigma[k_ZZ1jet13]  =  0.0081 * scale_; 
  chanEStatp[k_ZZ1jet13]  =   0.0008 * scale_;
  chanEStatm[k_ZZ1jet13]  =   0.0008 * scale_;
  chanEStat[k_ZZ1jet13]  = ( chanEStatp[k_ZZ1jet13] + chanEStatm[k_ZZ1jet13])/2.0;

  chanESystp[k_ZZ1jet13]  =    sqrt( 0.0008*0.0008+0.0002*0.0002)* scale_;
  chanESystm[k_ZZ1jet13]  =    sqrt( 0.0008*0.0008+0.0002*0.0002 )* scale_;
  chanESyst[k_ZZ1jet13]  = ( chanESystp[k_ZZ1jet13] + chanESystm[k_ZZ1jet13])/2.0;
 
  chanETot[k_ZZ1jet13]   =  sqrt( 
			   chanEStat[k_ZZ1jet13]*chanEStat[k_ZZ1jet13]
			   +
			   chanESyst[k_ZZ1jet13]*chanESyst[k_ZZ1jet13]
			    );

// Theory
  chanTheo[k_ZZ1jet13] =   0.0097 * scale_;
  chanETheop[k_ZZ1jet13] =  0.0004 * scale_;
  chanETheom[k_ZZ1jet13] =  0.0004 * scale_;
  chanETheo[k_ZZ1jet13 ] =  (chanETheop[k_ZZ1jet13]+chanETheom[k_ZZ1jet13])/2.0;


// 2jet
  chanMeasurement[k_ZZ2jet13] = "=2j";
  if (exportExeFormat) chanMeasurement[k_ZZ2jet13] = "ZZ2j";
  chanLumi[k_ZZ2jet13]= "35.9 fb^{-1}";
  chanCadi[k_ZZ2jet13] = "SMP-17-005";
  chanPreprint[k_ZZ2jet13] = "1806.11073";
  chanPublication[k_ZZ2jet13] = "PLB 789 (2019) 19";

  chanSigma[k_ZZ2jet13]  =  0.0030 * scale_; 
  chanEStatp[k_ZZ2jet13]  =   0.0005 * scale_;
  chanEStatm[k_ZZ2jet13]  =   0.0005 * scale_;
  chanEStat[k_ZZ2jet13]  = ( chanEStatp[k_ZZ2jet13] + chanEStatm[k_ZZ2jet13])/2.0;

  chanESystp[k_ZZ2jet13]  =    sqrt( 0.0003*0.0003+0.0001*0.0001)* scale_;
  chanESystm[k_ZZ2jet13]  =    sqrt( 0.0004*0.0004+0.0001*0.0001 )* scale_;
  chanESyst[k_ZZ2jet13]  = ( chanESystp[k_ZZ2jet13] + chanESystm[k_ZZ2jet13])/2.0;


  chanETotp[k_ZZ2jet13]   =  sqrt( 
			   chanEStatp[k_ZZ2jet13]*chanEStatp[k_ZZ2jet13]
			   +
			   chanESystp[k_ZZ2jet13]*chanESystp[k_ZZ2jet13]
			    );
  chanETotm[k_ZZ2jet13]   =  sqrt( 
			   chanEStatm[k_ZZ2jet13]*chanEStatm[k_ZZ2jet13]
			   +
			   chanESystm[k_ZZ2jet13]*chanESystm[k_ZZ2jet13]
			    );


  chanETot[k_ZZ2jet13]   =  sqrt( 
			   chanEStat[k_ZZ2jet13]*chanEStat[k_ZZ2jet13]
			   +
			   chanESyst[k_ZZ2jet13]*chanESyst[k_ZZ2jet13]
			    );

// Theory
  chanTheo[k_ZZ2jet13] =   0.0040 * scale_;
  chanETheop[k_ZZ2jet13] =  0.0003 * scale_;
  chanETheom[k_ZZ2jet13] =  0.0002 * scale_;
  chanETheo[k_ZZ2jet13 ] =  (chanETheop[k_ZZ2jet13]+chanETheom[k_ZZ2jet13])/2.0;

// 3jet
  chanMeasurement[k_ZZ3jet13] = "#geq3j";
  if (exportExeFormat) chanMeasurement[k_ZZ3jet13] = "ZZ3j";
  chanLumi[k_ZZ3jet13]= "35.9 fb^{-1}";
  chanCadi[k_ZZ3jet13] = "SMP-17-005";
  chanPreprint[k_ZZ3jet13] = "1806.11073";
  chanPublication[k_ZZ3jet13] = "PLB 789 (2019) 19";

  chanSigma[k_ZZ3jet13]  =  0.0013 * scale_; 
  chanEStatp[k_ZZ3jet13]  =   0.0004 * scale_;
  chanEStatm[k_ZZ3jet13]  =   0.0004 * scale_;
  chanEStat[k_ZZ3jet13]  = ( chanEStatp[k_ZZ3jet13] + chanEStatm[k_ZZ3jet13])/2.0;

  chanESystp[k_ZZ3jet13]  =    sqrt( 0.0003*0.0003)* scale_;
  chanESystm[k_ZZ3jet13]  =    sqrt( 0.0002*0.0002)* scale_;
  chanESyst[k_ZZ3jet13]  = ( chanESystp[k_ZZ3jet13] + chanESystm[k_ZZ3jet13])/2.0;

  chanETotp[k_ZZ3jet13]   =  sqrt( 
			   chanEStatp[k_ZZ3jet13]*chanEStatp[k_ZZ3jet13]
			   +
			   chanESystp[k_ZZ3jet13]*chanESystp[k_ZZ3jet13]
			    );
  chanETotm[k_ZZ3jet13]   =  sqrt( 
			   chanEStatm[k_ZZ3jet13]*chanEStatm[k_ZZ3jet13]
			   +
			   chanESystm[k_ZZ3jet13]*chanESystm[k_ZZ3jet13]
			    );


  chanETot[k_ZZ3jet13]   =  sqrt( 
			   chanEStat[k_ZZ3jet13]*chanEStat[k_ZZ3jet13]
			   +
			   chanESyst[k_ZZ3jet13]*chanESyst[k_ZZ3jet13]
			    );

// Theory
  chanTheo[k_ZZ3jet13] =   0.0017 * scale_;
  chanETheop[k_ZZ3jet13] =  0.0001 * scale_;
  chanETheom[k_ZZ3jet13] =  0.0001 * scale_;
  chanETheo[k_ZZ3jet13 ] =  (chanETheop[k_ZZ3jet13]+chanETheom[k_ZZ3jet13])/2.0;





// H->ZZ
  chanMeasurement[k_HZZ] = "H#rightarrowZZ";
  chanLumi[k_HZZ]= "25 fb^{-1}";
float ZZsigBR_ = ((15.32+1.211)*5.1+(19.52+1.559)*19.6) * (1/(5.1+19.6)) * 0.0264;

//  chanSigma[k_HZZ]  =   -2.5 * ZZsigBR_; // limite
//  chanEStat[k_HZZ]  =   0;
//  chanESyst[k_HZZ]  =   0;
 
  chanSigma[k_HZZ]  =   0.91 * ZZsigBR_;
  chanEStat[k_HZZ]  =   0.27 * ZZsigBR_;
  chanESyst[k_HZZ]  =   0;

  chanETot[k_HZZ]   =  sqrt(
                           chanEStat[k_HZZ]*chanEStat[k_HZZ]
                           +
                           chanESyst[k_HZZ]*chanESyst[k_HZZ]
                            );
  chanTheo [k_HZZ]  =   ZZsigBR_;
  chanETheo[k_HZZ]  =   ZZsigBR_ * 0.20;


  scale_ = 1.;


// EWK Zg SMP-14-018
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-018/index.html
// https://arxiv.org/abs/1702.03025 Phys. Lett. B 770 (2017) 380


  scale_=1/1000.0;

  chanMeasurement[k_EWKZg8] = "#scale[0.90]{#splitline{EW}{qqZ#gamma}}";
  if (exportExeFormat) chanMeasurement[k_EWKZg8] = "EW qqZ$\\gamma$";
  if (ratioPlot) chanMeasurement[k_EWKZg8]     = "qqZ#gamma";
  chanLumi[k_EWKZg8] = "19.7 fb^{-1}";
  chanCadi[k_EWKZg8] = "SMP-14-018";
  chanPreprint[k_EWKZg8] = "1702.03025";
  chanPublication[k_EWKZg8] = "PLB 770 (2017) 380";


  chanSigma[k_EWKZg8]  =  1.86 * scale_; 
  chanEStatp[k_EWKZg8]  =   0.89 * scale_;
  chanEStatm[k_EWKZg8]  =   0.75 * scale_;
  chanEStat[k_EWKZg8]  = ( chanEStatp[k_EWKZg8] + chanEStatm[k_EWKZg8])/2.0;

  chanESystp[k_EWKZg8]  =    sqrt( 0.41*0.41+0.5*0.5)* scale_;
  chanESystm[k_EWKZg8]  =    sqrt( 0.27*0.27+0.5*0.5)* scale_;
  chanESyst[k_EWKZg8]  = ( chanESystp[k_EWKZg8] + chanESystm[k_EWKZg8])/2.0;

  chanETotp[k_EWKZg8]   =  sqrt( 
			   chanEStatp[k_EWKZg8]*chanEStatp[k_EWKZg8]
			   +
			   chanESystp[k_EWKZg8]*chanESystp[k_EWKZg8]
			    );
  chanETotm[k_EWKZg8]   =  sqrt( 
			   chanEStatm[k_EWKZg8]*chanEStatm[k_EWKZg8]
			   +
			   chanESystm[k_EWKZg8]*chanESystm[k_EWKZg8]
			    );

  chanETot[k_EWKZg8]   =  sqrt( 
			   chanEStat[k_EWKZg8]*chanEStat[k_EWKZg8]
			   +
			   chanESyst[k_EWKZg8]*chanESyst[k_EWKZg8]
			    );
  chanTheo[k_EWKZg8] =  1.26 * scale_;
chanETheo[k_EWKZg8] =  sqrt(0.11*0.11 + 0.05*0.05) * scale_;

  scale_ = 1.;

// EWK Zg PAS-SMP-18-007
// Replace with
//
// SMP-20-016
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-20-016/index.html
// https://arxiv.org/abs/2106.11082 Phys. Rev. D 104, 072001 (2021)

  scale_=1/1000.0;

  chanMeasurement[k_EWKZg13] = "#scale[0.90]{#splitline{EW}{qqZ#gamma}}";
  if (exportExeFormat) chanMeasurement[k_EWKZg13] = "EW qqZ$\\gamma$";
  if (ratioPlot) chanMeasurement[k_EWKZg13]     = "qqZ#gamma";
  chanLumi[k_EWKZg13] = "137 fb^{-1}";
  chanCadi[k_EWKZg13] = "SMP-20-016";
  chanPreprint[k_EWKZg13] = "2106.11082";
  chanPublication[k_EWKZg13] = "PRD 104 072001 (2021)";


  chanSigma[k_EWKZg13]  =  5.21 * scale_; 
  chanEStatp[k_EWKZg13]  =   0.52 * scale_;
  chanEStatm[k_EWKZg13]  =   0.52 * scale_;
  chanEStat[k_EWKZg13]  = ( chanEStatp[k_EWKZg13] + chanEStatm[k_EWKZg13])/2.0;

  chanESystp[k_EWKZg13]  =    0.56 * scale_;
  chanESystm[k_EWKZg13]  =    0.56* scale_;
  chanESyst[k_EWKZg13]  = ( chanESystp[k_EWKZg13] + chanESystm[k_EWKZg13])/2.0;


  chanETot[k_EWKZg13]   =  sqrt( 
			   chanEStat[k_EWKZg13]*chanEStat[k_EWKZg13]
			   +
			   chanESyst[k_EWKZg13]*chanESyst[k_EWKZg13]
			    );
  chanTheo[k_EWKZg13] =  4.34 * scale_;
chanETheo[k_EWKZg13] =  sqrt(0.26*0.26 + 0.06*0.06) * scale_;

  scale_ = 1.;



// EWK Wg 8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-011/index.html
// https://arxiv.org/abs/1612.09256, JHEP 06 (2017) 106

  scale_=1/1000.0;

  chanMeasurement[k_EWKWg8] = "#scale[0.9]{#splitline{EW}{qqW#gamma}}";
  if (exportExeFormat) chanMeasurement[k_EWKWg8] = "EW qqW$\\gamma$";
  if (ratioPlot) chanMeasurement[k_EWKWg8]     = "qqW#gamma";
  chanLumi[k_EWKWg8] = "19.7 fb^{-1}";
  chanCadi[k_EWKWg8] = "SMP-14-011";
  chanPreprint[k_EWKWg8] = "1612.09256";
  chanPublication[k_EWKWg8] = "JHEP 06 (2017) 106";


  chanSigma[k_EWKWg8]  =  10.8 * scale_; 
  chanEStatp[k_EWKWg8]  =   4.1 * scale_;
  chanEStatm[k_EWKWg8]  =   4.1 * scale_;
  chanEStat[k_EWKWg8]  = ( chanEStatp[k_EWKWg8] + chanEStatm[k_EWKWg8])/2.0;

  chanESystp[k_EWKWg8]  =    sqrt( 3.4*3.4+0.3*0.3)* scale_;
  chanESystm[k_EWKWg8]  =    sqrt( 3.4*3.4+0.3*0.3)* scale_;
  chanESyst[k_EWKWg8]  = ( chanESystp[k_EWKWg8] + chanESystm[k_EWKWg8])/2.0;


  chanETot[k_EWKWg8]   =  sqrt( 
			   chanEStat[k_EWKWg8]*chanEStat[k_EWKWg8]
			   +
			   chanESyst[k_EWKWg8]*chanESyst[k_EWKWg8]
			    );
  chanTheo[k_EWKWg8] =  6.1 * scale_;
chanETheo[k_EWKWg8] =  sqrt(1.2*1.2 + 0.2*0.2) * scale_;

  scale_ = 1.;



// EWK Wg 13 TeV
// updated to
//http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-19-008/
//https://arxiv.org/abs/2008.10521 Phys. Lett. B 811 (2020) 135988
// updated to
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-21-011/index.html

  scale_=1/1000.0;

  chanMeasurement[k_EWKWg13] = "#scale[0.9]{#splitline{EW}{qqW#gamma}}";
  if (exportExeFormat) chanMeasurement[k_EWKWg13] = "EW qqW$\\gamma$";
  if (ratioPlot) chanMeasurement[k_EWKWg13]     = "qqW#gamma";
  chanLumi[k_EWKWg13] = "138 fb^{-1}";
  chanCadi[k_EWKWg13] = "SMP-21-011";
  chanPreprint[k_EWKWg13] = "https://cds.cern.ch/record/2809554";
  chanPublication[k_EWKWg13] = "";


  chanSigma[k_EWKWg13]  =  19.2 * scale_; 
 chanEStatp[k_EWKWg13]  =   2.3 * scale_;
  chanEStatm[k_EWKWg13]  =   2.3 * scale_;
  chanEStat[k_EWKWg13]  = ( chanEStatp[k_EWKWg13] + chanEStatm[k_EWKWg13])/2.0;

  chanESystp[k_EWKWg13]  =    sqrt( 1.6*1.6+2.9*2.9)* scale_;
  chanESystm[k_EWKWg13]  =    sqrt( 1.4*1.4+2.8*2.8)* scale_;
  chanESyst[k_EWKWg13]  = ( chanESystp[k_EWKWg13] + chanESystm[k_EWKWg13])/2.0;


  chanETot[k_EWKWg13]   =  sqrt( 
			   chanEStat[k_EWKWg13]*chanEStat[k_EWKWg13]
			   +
			   chanESyst[k_EWKWg13]*chanESyst[k_EWKWg13]
			    );
  chanTheo[k_EWKWg13] =  0.776*0.028*1000.0 * scale_;
// No theory error is given
chanETheo[k_EWKWg13] =  sqrt(3.4*3.4) * scale_;

  scale_ = 1.;


// EWK WZ 13 TeV
// CMS PAS SMP-18-001
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-18-001/index.html
// https://cds.cern.ch/record/2629457
// replaced with SMP=19=012
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-19-012/index.html
// https://arxiv.org/abs/2005.01173 Phys. Lett. B 809 (2020) 135710


  scale_=1.0;

  chanMeasurement[k_EWKWZ13] = "#scale[0.90]{#splitline{EW}{qqWZ}}";
  if (exportExeFormat) chanMeasurement[k_EWKWZ13] = "EW qqWZ";
  if (ratioPlot) chanMeasurement[k_EWKWZ13]     = "qqWZ";
  chanLumi[k_EWKWZ13] = "137 fb^{-1}";
  chanCadi[k_EWKWZ13] = "SMP-19-012";
  chanPreprint[k_EWKWZ13] = "2005.01173";
  chanPublication[k_EWKWZ13] = "PLB 809 (2020) 135710";

//  chanTheo[k_EWKWZ13] =  1.25 * (1.0/1000.0)  * scale_;
//  chanETheo[k_EWKWZ13] =  sqrt(0.10*0.10 + 0.06*0.06) * (1.0/1000.0) * scale_;
  chanTheo[k_EWKWZ13] =  1.24 * (1.0/1000.0)  * scale_;
  chanETheo[k_EWKWZ13] =  sqrt(0.18*0.18) * (1.0/1000.0) * scale_;
// With NLO correcgtions


  // chanSigma[k_EWKWZ13]  =  0.82 *  chanTheo[k_EWKWZ13] * scale_; 
  // chanETotp[k_EWKWZ13]  =   0.51 * chanTheo[k_EWKWZ13] * scale_;
  // chanETotm[k_EWKWZ13]  =   0.43 * chanTheo[k_EWKWZ13] * scale_;
  // chanETot[k_EWKWZ13] = ( chanETotp[k_EWKWZ13] +  chanETotm[k_EWKWZ13])/2.0;

  // chanEStatp[k_EWKWZ13]  =   0.0 * scale_;
  // chanEStatm[k_EWKWZ13]  =   0.0 * scale_;
  // chanEStat[k_EWKWZ13]  = ( chanEStatp[k_EWKWZ13] + chanEStatm[k_EWKWZ13])/2.0;

  // chanESystp[k_EWKWZ13]  =    0.0 * scale_;
  // chanESystm[k_EWKWZ13]  =    0.0 * scale_;
  // chanESyst[k_EWKWZ13]  = ( chanESystp[k_EWKWZ13] + chanESystm[k_EWKWZ13])/2.0;

  chanSigma[k_EWKWZ13]  =  1.81 * (1.0/1000.0) * scale_; 
  chanETotp[k_EWKWZ13]  =   0.41 * (1.0/1000.0) * scale_;
  chanETotm[k_EWKWZ13]  =   0.41 * (1.0/1000.0) * scale_;
  chanETot[k_EWKWZ13] = ( chanETotp[k_EWKWZ13] +  chanETotm[k_EWKWZ13])/2.0;

  chanEStatp[k_EWKWZ13]  =   0.39 * (1.0/1000.0) * scale_;
  chanEStatm[k_EWKWZ13]  =   0.39 * (1.0/1000.0) * scale_;
  chanEStat[k_EWKWZ13]  = ( chanEStatp[k_EWKWZ13] + chanEStatm[k_EWKWZ13])/2.0;

  chanESystp[k_EWKWZ13]  =    0.14 * (1.0/1000.0) * scale_;
  chanESystm[k_EWKWZ13]  =    0.14 * (1.0/1000.0) * scale_;
  chanESyst[k_EWKWZ13]  = ( chanESystp[k_EWKWZ13] + chanESystm[k_EWKWZ13])/2.0;


  scale_ = 1.;



// EWK ZZ 13 TeV
// Updated to SMP-20-001
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-20-001/
// http://arxiv.org/abs/2008.07013 PLB 812 (2020) 135992


  scale_=1/1000.0;

  chanMeasurement[k_EWKZZ13] = "#scale[0.90]{#splitline{EW}{qqZZ}}";
  if (exportExeFormat) chanMeasurement[k_EWKZZ13] = "EW qqZZ";
  if (ratioPlot) chanMeasurement[k_EWKZZ13]     = "qqZZ";
  chanLumi[k_EWKZZ13] = "137 fb^{-1}";
  chanCadi[k_EWKZZ13] = "SMP-20-001";
  chanPreprint[k_EWKZZ13] = "2008.07013";
  chanPublication[k_EWKZZ13] = "PLB 812 (2020) 135992";

  chanSigma[k_EWKZZ13]  =  0.33 * scale_; 
  chanEStatp[k_EWKZZ13]  =   0.11 * scale_;
  chanEStatm[k_EWKZZ13]  =   0.10 * scale_;
  chanEStat[k_EWKZZ13]  = ( chanEStatp[k_EWKZZ13] + chanEStatm[k_EWKZZ13])/2.0;

  chanESystp[k_EWKZZ13]  =    0.04 * scale_;
  chanESystm[k_EWKZZ13]  =    0.03 * scale_;
  chanESyst[k_EWKZZ13]  = ( chanESystp[k_EWKZZ13] + chanESystm[k_EWKZZ13])/2.0;

  chanETotp[k_EWKZZ13]   =  sqrt( 
			   chanEStatp[k_EWKZZ13]*chanEStatp[k_EWKZZ13]
			   +
			   chanESystp[k_EWKZZ13]*chanESystp[k_EWKZZ13]
			    );
  chanETotm[k_EWKZZ13]   =  sqrt( 
			   chanEStatm[k_EWKZZ13]*chanEStatm[k_EWKZZ13]
			   +
			   chanESystm[k_EWKZZ13]*chanESystm[k_EWKZZ13]
			    );

  chanETot[k_EWKZZ13]   =  sqrt( 
			   chanEStat[k_EWKZZ13]*chanEStat[k_EWKZZ13]
			   +
			   chanESyst[k_EWKZZ13]*chanESyst[k_EWKZZ13]
			    );
  chanTheo[k_EWKZZ13] =  0.278 * scale_;
chanETheo[k_EWKZZ13] =  0.017 * scale_;

  scale_ = 1.;



// add +2jet results

// WVgamma SMP-13-009
// http://arxiv.org/abs/1404.4619 Phys. Rev. D 90, 032008 (2014)

  chanMeasurement[k_WVg] = "#scale[0.90]{WV#gamma}";
  if (exportExeFormat) chanMeasurement[k_WVg] = "WV$\\gamma$";
  chanLumi[k_WVg]= "19.3 fb^{-1}";
  chanCadi[k_WVg] = "SMP-13-009";
  chanPreprint[k_WVg] = "1404.4619";
  chanPublication[k_WVg] = "PRD 90 032008 (2014)";


  chanSigma[k_WVg]  =  -0.311 * scale_; 
  chanEStat[k_WVg]  =   0.0 * scale_;
  chanESyst[k_WVg]  =   0.0 * scale_;
  chanETot[k_WVg]   =  sqrt( 
			   chanEStat[k_WV]*chanEStat[k_WVg]
			   +
			   chanESyst[k_WV]*chanESyst[k_WVg]
			    );
  chanTheo[k_WVg] =  0.0916 * scale_;
  chanETheo[k_WVg] =  0.0217 * scale_;

 scale_ = 1.;


// VVV 13 SMP-19-014
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-19-014/index.html
// https://arxiv.org/abs/2006.11191 Phys. Rev. Lett. 125, 151802 (2020)

  scale_ = 0.001;
  chanMeasurement[k_VVV13] = "#scale[0.9]{VVV}";
  if (exportExeFormat) chanMeasurement[k_VVV13] = "VVV";
  chanLumi[k_VVV13] = "137 fb^{-1}";
  chanCadi[k_VVV13] = "SMP-19-014";
  chanPreprint[k_VVV13] = "2006.11191";
  chanPublication[k_VVV13] = "PRL 125 151802 (2020)";


  chanSigma[k_VVV13]  =  1010 * scale_; 
  chanEStatp[k_VVV13]  =   210 * scale_;
  chanEStatm[k_VVV13]  =   200 * scale_;
  chanEStat[k_VVV13]  = ( chanEStatp[k_VVV13] + chanEStatm[k_VVV13])/2.0;

  chanESystp[k_VVV13]  =    150* scale_;
  chanESystm[k_VVV13]  =    120* scale_;
  chanESyst[k_VVV13]  = ( chanESystp[k_VVV13] + chanESystm[k_VVV13])/2.0;

  chanETotp[k_VVV13]   =  sqrt( 
			   chanEStatp[k_VVV13]*chanEStatp[k_VVV13]
			   +
			   chanESystp[k_VVV13]*chanESystp[k_VVV13]
			    );
  chanETotm[k_VVV13]   =  sqrt( 
			   chanEStatm[k_VVV13]*chanEStatm[k_VVV13]
			   +
			   chanESystm[k_VVV13]*chanESystm[k_VVV13]
			    );

  chanETot[k_VVV13]   =  sqrt( 
			   chanEStat[k_VVV13]*chanEStat[k_VVV13]
			   +
			   chanESyst[k_VVV13]*chanESyst[k_VVV13]
			    );
  chanTheo[k_VVV13] =  (509.4+354.0+91.6+37.1) * scale_;
  chanETheop[k_VVV13] =  10 * scale_;
  chanETheom[k_VVV13] =  10 * scale_;
  chanETheo[k_VVV13]   =  (chanETheop[k_VVV13]+chanETheom[k_VVV13])/2.0;
// Includes NLO VVV and NNLO QCD + NLO EWK VH No uncertainty given.

  scale_ = 1.;




// WWW 13
// SMP 17 013
// fb scale
// https://arxiv.org/abs/1905.04246
// Phys. Rev. D 100, 012004 (2019)
// Updated to
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-19-014/index.html




// scale_ = 0.001;
//   chanMeasurement[k_WWW13] = "#scale[0.80]{WWW}";
//   chanLumi[k_WWW13] = "35.9 fb^{-1}";

//   chanSigma[k_WWW13]  =  17 * scale_; 
//   chanEStatp[k_WWW13]  =   32 * scale_;
//   chanEStatm[k_WWW13]  =   17 * scale_;
//    chanSigma[k_WWW13]  =  -780 * scale_; 
//  chanEStat[k_WWW13]  = ( chanEStatp[k_WWW13] + chanEStatm[k_WWW13])/2.0;


//   chanESystp[k_WWW13]  =    0.0* scale_;
//   chanESystm[k_WWW13]  =    0.0* scale_;
//   chanESyst[k_WWW13]  = ( chanESystp[k_WWW13] + chanESystm[k_WWW13])/2.0;




//   chanETot[k_WWW13]   =  sqrt( 
// 			   chanEStat[k_WWW13]*chanEStat[k_WWW13]
// 			   +
// 			   chanESyst[k_WWW13]*chanESyst[k_WWW13]
// 			    );
//   chanTheo[k_WWW13] =  509 * scale_;
//   chanETheop[k_WWW13] =  13 * scale_;
//   chanETheom[k_WWW13] =  13 * scale_;
// chanETheo[k_WWW13]   =  (chanETheop[k_WWW13]+chanETheom[k_WWW13])/2.0;


//   scale_ = 1.;

  scale_ = 0.001;
  chanMeasurement[k_WWW13] = "#scale[0.9]{WWW}";
  if (exportExeFormat) chanMeasurement[k_WWW13] = "WWW";
  chanLumi[k_WWW13] = "137 fb^{-1}";
  chanCadi[k_WWW13] = "SMP-19-014";
  chanPreprint[k_WWW13] = "2006.11191";
  chanPublication[k_WWW13] = "PRL 125 151802 (2020)";

  chanSigma[k_WWW13]  =  590 * scale_; 
  chanEStatp[k_WWW13]  =   160 * scale_;
  chanEStatm[k_WWW13]  =   150 * scale_;
  chanEStat[k_WWW13]  = ( chanEStatp[k_WWW13] + chanEStatm[k_WWW13])/2.0;

  chanESystp[k_WWW13]  =    160* scale_;
  chanESystm[k_WWW13]  =    130* scale_;
  chanESyst[k_WWW13]  = ( chanESystp[k_WWW13] + chanESystm[k_WWW13])/2.0;

  chanETotp[k_WWW13]   =  sqrt( 
			   chanEStatp[k_WWW13]*chanEStatp[k_WWW13]
			   +
			   chanESystp[k_WWW13]*chanESystp[k_WWW13]
			    );
  chanETotm[k_WWW13]   =  sqrt( 
			   chanEStatm[k_WWW13]*chanEStatm[k_WWW13]
			   +
			   chanESystm[k_WWW13]*chanESystm[k_WWW13]
			    );


  chanETot[k_WWW13]   =  sqrt( 
			   chanEStat[k_WWW13]*chanEStat[k_WWW13]
			   +
			   chanESyst[k_WWW13]*chanESyst[k_WWW13]
			    );
  chanTheo[k_WWW13] =  (509.4) * scale_;
  chanETheop[k_WWW13] =  10 * scale_;
  chanETheom[k_WWW13] =  10 * scale_;
  chanETheo[k_WWW13]   =  (chanETheop[k_WWW13]+chanETheom[k_WWW13])/2.0;
// Includes NLO WWW and NNLO QCD + NLO EWK WH No uncertainty given.

  scale_ = 1.;


// WWZ 13
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-19-014/index.html


  scale_ = 0.001;
  chanMeasurement[k_WWZ13] = "#scale[0.9]{WWZ}";
  if (exportExeFormat) chanMeasurement[k_WWZ13] = "WWZ";
  chanLumi[k_WWZ13] = "137 fb^{-1}";
  chanCadi[k_WWZ13] = "SMP-19-014";
  chanPreprint[k_WWZ13] = "2006.11191";
  chanPublication[k_WWZ13] = "PRL 125 151802 (2020)";

  chanSigma[k_WWZ13]  =  300 * scale_; 
  chanEStatp[k_WWZ13]  =   120 * scale_;
  chanEStatm[k_WWZ13]  =   100 * scale_;
  chanEStat[k_WWZ13]  = ( chanEStatp[k_WWZ13] + chanEStatm[k_WWZ13])/2.0;

  chanESystp[k_WWZ13]  =    50* scale_;
  chanESystm[k_WWZ13]  =    40* scale_;
  chanESyst[k_WWZ13]  = ( chanESystp[k_WWZ13] + chanESystm[k_WWZ13])/2.0;

  chanETotp[k_WWZ13]   =  sqrt( 
			   chanEStatp[k_WWZ13]*chanEStatp[k_WWZ13]
			   +
			   chanESystp[k_WWZ13]*chanESystp[k_WWZ13]
			    );
  chanETotm[k_WWZ13]   =  sqrt( 
			   chanEStatm[k_WWZ13]*chanEStatm[k_WWZ13]
			   +
			   chanESystm[k_WWZ13]*chanESystm[k_WWZ13]
			    );


  chanETot[k_WWZ13]   =  sqrt( 
			   chanEStat[k_WWZ13]*chanEStat[k_WWZ13]
			   +
			   chanESyst[k_WWZ13]*chanESyst[k_WWZ13]
			    );
  chanTheo[k_WWZ13] =  (354.0) * scale_;
  chanETheop[k_WWZ13] =  3.5 * scale_;
  chanETheom[k_WWZ13] =  3.5 * scale_;
  chanETheo[k_WWZ13]   =  (chanETheop[k_WWZ13]+chanETheom[k_WWZ13])/2.0;
// Includes NLO WWZ and NNLO QCD + NLO EWK ZH No uncertainty given.

  scale_ = 1.;

// WZZ 13
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-19-014/index.html


  scale_ = 0.001;
  chanMeasurement[k_WZZ13] = "#scale[0.9]{WZZ}";
  if (exportExeFormat) chanMeasurement[k_WZZ13] = "WZZ";
  chanLumi[k_WZZ13] = "137 fb^{-1}";
  chanCadi[k_WZZ13] = "SMP-19-014";
  chanPreprint[k_WZZ13] = "2006.11191";
  chanPublication[k_WZZ13] = "PRL 125 151802 (2020)";

  chanSigma[k_WZZ13]  =  200 * scale_; 
  chanEStatp[k_WZZ13]  =   160 * scale_;
  chanEStatm[k_WZZ13]  =   110 * scale_;
  chanEStat[k_WZZ13]  = ( chanEStatp[k_WZZ13] + chanEStatm[k_WZZ13])/2.0;

  chanESystp[k_WZZ13]  =    70* scale_;
  chanESystm[k_WZZ13]  =    20* scale_;
  chanESyst[k_WZZ13]  = ( chanESystp[k_WZZ13] + chanESystm[k_WZZ13])/2.0;


  chanETotp[k_WZZ13]   =  sqrt( 
			   chanEStatp[k_WZZ13]*chanEStatp[k_WZZ13]
			   +
			   chanESystp[k_WZZ13]*chanESystp[k_WZZ13]
			    );
  chanETotm[k_WZZ13]   =  sqrt( 
			   chanEStatm[k_WZZ13]*chanEStatm[k_WZZ13]
			   +
			   chanESystm[k_WZZ13]*chanESystm[k_WZZ13]
			    );


  chanETot[k_WZZ13]   =  sqrt( 
			   chanEStat[k_WZZ13]*chanEStat[k_WZZ13]
			   +
			   chanESyst[k_WZZ13]*chanESyst[k_WZZ13]
			    );
  chanTheo[k_WZZ13] =  (91.6) * scale_;
  chanETheop[k_WZZ13] =  0.92 * scale_;
  chanETheom[k_WZZ13] =  0.92 * scale_;
  chanETheo[k_WZZ13]   =  (chanETheop[k_WZZ13]+chanETheom[k_WZZ13])/2.0;
// Includes NLO WZZ and NNLO QCD + NLO EWK ZH No uncertainty given.

  scale_ = 1.;

// ZZZ 13
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-19-014/index.html


  scale_ = 0.001;
  chanMeasurement[k_ZZZ13] = "#scale[0.9]{ZZZ}";
  if (exportExeFormat) chanMeasurement[k_ZZZ13] = "ZZZ";
  chanLumi[k_ZZZ13] = "137 fb^{-1}";
  chanCadi[k_ZZZ13] = "SMP-19-014";
  chanPreprint[k_ZZZ13] = "2006.11191";
  chanPublication[k_ZZZ13] = "PRL 125 151802 (2020)";

  chanSigma[k_ZZZ13]  =  -200 * scale_; 
  chanEStatp[k_ZZZ13]  =   0 * scale_;
  chanEStatm[k_ZZZ13]  =   0 * scale_;
  chanEStat[k_ZZZ13]  = ( chanEStatp[k_ZZZ13] + chanEStatm[k_ZZZ13])/2.0;

  chanESystp[k_ZZZ13]  =    0* scale_;
  chanESystm[k_ZZZ13]  =    0* scale_;
  chanESyst[k_ZZZ13]  = ( chanESystp[k_ZZZ13] + chanESystm[k_ZZZ13])/2.0;


  chanETotp[k_ZZZ13]   =  sqrt( 
			   chanEStatp[k_ZZZ13]*chanEStatp[k_ZZZ13]
			   +
			   chanESystp[k_ZZZ13]*chanESystp[k_ZZZ13]
			    );
  chanETotm[k_ZZZ13]   =  sqrt( 
			   chanEStatm[k_ZZZ13]*chanEStatm[k_ZZZ13]
			   +
			   chanESystm[k_ZZZ13]*chanESystm[k_ZZZ13]
			    );


  chanETot[k_ZZZ13]   =  sqrt( 
			   chanEStat[k_ZZZ13]*chanEStat[k_ZZZ13]
			   +
			   chanESyst[k_ZZZ13]*chanESyst[k_ZZZ13]
			    );
  chanTheo[k_ZZZ13] =  (37.1) * scale_;
  chanETheop[k_ZZZ13] =  0.37 * scale_;
  chanETheom[k_ZZZ13] =  0.37 * scale_;
  chanETheo[k_ZZZ13]   =  (chanETheop[k_ZZZ13]+chanETheom[k_ZZZ13])/2.0;
// Includes NLO ZZZ and NNLO QCD + NLO EWK ZH No uncertainty given.

  scale_ = 1.;





// Wgg 8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-15-008/index.html
// https://arxiv.org/abs/1704.00366 HEP 10 (2017) 072 
// fb scale

scale_ = 0.001;
  chanMeasurement[k_Wgg8] = "#scale[0.9]{W#gamma#gamma}";
  if (exportExeFormat) chanMeasurement[k_Wgg8] = "W$\\gamma\\gamma$";
  chanLumi[k_Wgg8] = "19.4 fb^{-1}";
  chanCadi[k_Wgg8] = "SMP-15-008";
  chanPreprint[k_Wgg8] = "1704.00366";
  chanPublication[k_Wgg8] = "JHEP 10 (2017) 072";

  chanSigma[k_Wgg8]  =  4.9 * scale_; 
  chanEStatp[k_Wgg8]  =   1.4 * scale_;
  chanEStatm[k_Wgg8]  =   1.4 * scale_;
  chanEStat[k_Wgg8]  = ( chanEStatp[k_Wgg8] + chanEStatm[k_Wgg8])/2.0;


  chanESystp[k_Wgg8]  =    sqrt( 1.6*1.6+0.1*0.1)* scale_;
  chanESystm[k_Wgg8]  =    sqrt( 1.6*1.6+0.1*0.1)* scale_;
  chanESyst[k_Wgg8]  = ( chanESystp[k_Wgg8] + chanESystm[k_Wgg8])/2.0;




  chanETot[k_Wgg8]   =  sqrt( 
			   chanEStat[k_Wgg8]*chanEStat[k_Wgg8]
			   +
			   chanESyst[k_Wgg8]*chanESyst[k_Wgg8]
			    );
  chanTheo[k_Wgg8] =  4.76 * scale_;
  chanETheop[k_Wgg8] =  0.53 * scale_;
  chanETheom[k_Wgg8] =  0.53 * scale_;
chanETheo[k_Wgg8]   =  ( chanETheop[k_Wgg8]+ chanETheom[k_Wgg8])/2.0;


  scale_ = 1.;

// Wgg 13 TeV
// SMP-19-013 Wgg, Zgg
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-19-013/index.html
// https://arxiv.org/abs/2105.12780 JHEP 10 (2021) 174
// fb scale

scale_ = 0.001;
  chanMeasurement[k_Wgg13] = "#scale[0.9]{W#gamma#gamma}";
  if (exportExeFormat) chanMeasurement[k_Wgg13] = "W$\\gamma\\gamma$";
  chanLumi[k_Wgg13] = "19.4 fb^{-1}";
  chanCadi[k_Wgg13] = "SMP-19-013";
  chanPreprint[k_Wgg13] = "2105.12780";
  chanPublication[k_Wgg13] = "JHEP 10 (2021) 174";

  chanSigma[k_Wgg13]  =  13.63 * scale_; 
  chanEStatp[k_Wgg13]  =   1.93 * scale_;
  chanEStatm[k_Wgg13]  =   1.89 * scale_;
  chanEStat[k_Wgg13]  = ( chanEStatp[k_Wgg13] + chanEStatm[k_Wgg13])/2.0;


  chanESystp[k_Wgg13]  =    sqrt( 4.04*4.04+0.08*0.08)* scale_;
  chanESystm[k_Wgg13]  =    sqrt( 4.02*4.02+0.08*0.08)* scale_;
  chanESyst[k_Wgg13]  = ( chanESystp[k_Wgg13] + chanESystm[k_Wgg13])/2.0;

  chanETotp[k_Wgg13]   =  sqrt( 
			   chanEStatp[k_Wgg13]*chanEStatp[k_Wgg13]
			   +
			   chanESystp[k_Wgg13]*chanESystp[k_Wgg13]
			    );
  chanETotm[k_Wgg13]   =  sqrt( 
			   chanEStatm[k_Wgg13]*chanEStatm[k_Wgg13]
			   +
			   chanESystm[k_Wgg13]*chanESystm[k_Wgg13]
			    );



  chanETot[k_Wgg13]   =  sqrt( 
			   chanEStat[k_Wgg13]*chanEStat[k_Wgg13]
			   +
			   chanESyst[k_Wgg13]*chanESyst[k_Wgg13]
			    );
  chanTheo[k_Wgg13] =  18.7 * scale_;
  chanETheop[k_Wgg13] =  sqrt(0.03*0.03 + 0.12*0.12) * scale_;
  chanETheom[k_Wgg13] =  sqrt(0.03*0.03 + 0.12*0.12) * scale_;
  chanETheo[k_Wgg13]   =  ( chanETheop[k_Wgg13]+ chanETheom[k_Wgg13])/2.0;


  scale_ = 1.;


// Zgg 8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-15-008/index.html
// fb scale
scale_ = 0.001;
  chanMeasurement[k_Zgg8] = "#scale[0.9]{Z#gamma#gamma}";
  if (exportExeFormat) chanMeasurement[k_Zgg8] = "Z$\\gamma\\gamma$";
  chanLumi[k_Zgg8] = "19.4 fb^{-1}";
  chanCadi[k_Zgg8] = "SMP-15-008";
  chanPreprint[k_Zgg8] = "1704.00366";
  chanPublication[k_Zgg8] = "JHEP 10 (2017) 072";

  chanSigma[k_Zgg8]  =  12.7 * scale_; 
  chanEStatp[k_Zgg8]  =   1.4 * scale_;
  chanEStatm[k_Zgg8]  =   1.4 * scale_;
  chanEStat[k_Zgg8]  = ( chanEStatp[k_Zgg8] + chanEStatm[k_Zgg8])/2.0;


  chanESystp[k_Zgg8]  =    sqrt( 1.8*1.8+0.3*0.3)* scale_;
  chanESystm[k_Zgg8]  =    sqrt( 1.8*1.8+0.3*0.3)* scale_;
  chanESyst[k_Zgg8]  = ( chanESystp[k_Zgg8] + chanESystm[k_Zgg8])/2.0;




  chanETot[k_Zgg8]   =  sqrt( 
			   chanEStat[k_Zgg8]*chanEStat[k_Zgg8]
			   +
			   chanESyst[k_Zgg8]*chanESyst[k_Zgg8]
			    );
  chanTheo[k_Zgg8] =  12.95 * scale_;
  chanETheop[k_Zgg8] =  1.47 * scale_;
  chanETheom[k_Zgg8] =  1.47 * scale_;
chanETheo[k_Zgg8]   =  (chanETheop[k_Zgg8]+chanETheom[k_Zgg8])/2.0;


  scale_ = 1.;


// Zgg 13 TeV
// SMP-19-013 Wgg, Zgg
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-19-013/index.html
// fb scale
scale_ = 0.001;
  chanMeasurement[k_Zgg13] = "#scale[0.9]{Z#gamma#gamma}";
  if (exportExeFormat) chanMeasurement[k_Zgg13] = "Z$\\gamma\\gamma$";
  chanLumi[k_Zgg13] = "19.4 fb^{-1}";
  chanCadi[k_Zgg13] = "SMP-19-013";
  chanPreprint[k_Zgg13] = "2105.12780";
  chanPublication[k_Zgg13] = "JHEP 10 (2021) 174";

  chanSigma[k_Zgg13]  =  5.41 * scale_; 
  chanEStatp[k_Zgg13]  =   0.58 * scale_;
  chanEStatm[k_Zgg13]  =   0.55 * scale_;
  chanEStat[k_Zgg13]  = ( chanEStatp[k_Zgg13] + chanEStatm[k_Zgg13])/2.0;


  chanESystp[k_Zgg13]  =    sqrt( 0.64*0.64+0.06*0.06)* scale_;
  chanESystm[k_Zgg13]  =    sqrt( 0.70*0.70+0.06*0.06)* scale_;
  chanESyst[k_Zgg13]  = ( chanESystp[k_Zgg13] + chanESystm[k_Zgg13])/2.0;


  chanETotp[k_Zgg13]   =  sqrt( 
			   chanEStatp[k_Zgg13]*chanEStatp[k_Zgg13]
			   +
			   chanESystp[k_Zgg13]*chanESystp[k_Zgg13]
			    );
  chanETotm[k_Zgg13]   =  sqrt( 
			   chanEStatm[k_Zgg13]*chanEStatm[k_Zgg13]
			   +
			   chanESystm[k_Zgg13]*chanESystm[k_Zgg13]
			    );


  chanETot[k_Zgg13]   =  sqrt( 
			   chanEStat[k_Zgg13]*chanEStat[k_Zgg13]
			   +
			   chanESyst[k_Zgg13]*chanESyst[k_Zgg13]
			    );
  chanTheo[k_Zgg13] =  5.96 * scale_;
chanETheop[k_Zgg13] =  sqrt(0.01*0.01 + 0.060) * scale_;
  chanETheom[k_Zgg13] = sqrt(0.01*0.01 + 0.060)   * scale_;
chanETheo[k_Zgg13]   =  (chanETheop[k_Zgg13]+chanETheom[k_Zgg13])/2.0;


  scale_ = 1.;




// Exclusive gg -> WW production
// http://cms-results.web.cern.ch/cms-results/public-results/publications/FSQ-12-010/index.html,
// http://arxiv.org/abs/1305.5596  	JHEP 07 (2013) 116
  chanMeasurement[k_exWW] = "#scale[0.9]{#splitline{#gamma#gamma#rightarrow}{WW}}";
  if (exportExeFormat) chanMeasurement[k_exWW] = "ex. $\\gamma\\gamma\\rightarrow$WW";
  if (version == 6) chanMeasurement[k_exWW] = "#splitline{#gamma#gamma#rightarrow WW}{WW #rightarrow l#nul#nu}";
  chanLumi[k_exWW]= "5.05 fb^{-1}";
  chanCadi[k_exWW] = "FSQ-12-0101";
  chanPreprint[k_exWW] = "1305.5596";
  chanPublication[k_exWW] = "JHEP 07 (2013) 116";

//scale_ = 1.0/(W_br_lnu*W_br_lnu*2.0) ;
scale_ = 2.0;

  chanSigma[k_exWW]  =  -0.0106 * scale_; 
  chanEStat[k_exWW]  =   0.0106 * scale_;
  chanESyst[k_exWW]  =   0.0 * scale_;
  chanETot[k_exWW]   =  sqrt( 
			   chanEStat[k_exWW]*chanEStat[k_exWW]
			   +
			   chanESyst[k_exWW]*chanESyst[k_exWW]
			    );
  chanTheo[k_exWW] =  0.0040 * scale_;
  chanETheo[k_exWW] =  0.0007 * scale_;

 scale_ = 1.;


// Exclusive gg -> WW FSQ-13-008
// http://arxiv.org/abs/1604.04464, JHEP 08 (2016) 119

  chanMeasurement[k_exWW8] = "#scale[0.9]{#splitline{#gamma#gamma#rightarrow}{WW}}";
  if (exportExeFormat) chanMeasurement[k_exWW8] = "ex. $\\gamma\\gamma\\rightarrow$WW";
  if (version == 6) chanMeasurement[k_exWW8] = "#splitline{#gamma#gamma#rightarrow WW}{WW #rightarrow l#nul#nu}";
  if (ratioPlot) chanMeasurement[k_exWW8]     = "#gamma#gamma#rightarrowWW";
  chanLumi[k_exWW8]= "19.7 fb^{-1}";
  chanCadi[k_exWW8] = "FSQ-13-008";
  chanPreprint[k_exWW8] = "1604.04464";
  chanPublication[k_exWW8] = "JHEP 08 (2016) 119";


//scale_ = 1.0/(W_br_lnu*W_br_lnu*2.0) ;
scale_ = 2.0;

  chanSigma[k_exWW8]  =  0.0108 * scale_; 
  chanESyst[k_exWW8]  =   0.0046 * scale_;
  chanEStat[k_exWW8]  =   0.0 * scale_;
  chanETot[k_exWW8]   =  sqrt( 
			   chanEStat[k_exWW8]*chanEStat[k_exWW8]
			   +
			   chanESyst[k_exWW8]*chanESyst[k_exWW8]
			    );
  chanTheo[k_exWW8] =  0.0062 * scale_;
  chanETheo[k_exWW8] =  0.0005 * scale_;

// 11.9 + 5.6 - 4.5

 scale_ = 1.;


// EW WW SMP-20-013
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-20-013/
// https://arxiv.org/abs/2112.05259 Submitted to PLB
// 

  chanMeasurement[k_EWKWV13] = "#scale[0.9]{#splitline{ EW}{WV}}";
  if (exportExeFormat) chanMeasurement[k_EWKWV13] = "EW WV";
  if (version == 6) chanMeasurement[k_EWKWV13] = "#splitline{EWK WV}{WV #rightarrow l#nu qqbar}";
  if (ratioPlot) chanMeasurement[k_EWKWV13]     = "WV";
  chanLumi[k_EWKWV13]= "138 fb^{-1}";
  chanCadi[k_EWKWV13] = "SMP-20-013";
  chanPreprint[k_EWKWV13] = "2112.05259";
  chanPublication[k_EWKWV13] = "Submitted to PLB";


  chanTheo[k_EWKWV13]   =  2.23 * scale_;
  chanETheop[k_EWKWV13] =  sqrt(0.08*0.08+0.05*0.05) * scale_;
  chanETheom[k_EWKWV13] = sqrt(0.11*0.11+0.05*0.05)* scale_;
  chanETheo[k_EWKWV13] =  ((chanETheop[k_EWKWV13]+chanETheom[k_EWKWV13])/2.0) ;


  chanSigma[k_EWKWV13]  = 0.85 * chanTheo[k_EWKWV13]; 
  chanEStatp[k_EWKWV13] = 0.12 * chanTheo[k_EWKWV13]; 
  chanEStatm[k_EWKWV13] = 0.12 * chanTheo[k_EWKWV13]; 
  chanEStat[k_EWKWV13]  = 0.12 * chanTheo[k_EWKWV13]; 
  chanESystp[k_EWKWV13] = 0.19 * chanTheo[k_EWKWV13]; 
  chanESystm[k_EWKWV13] = 0.17 * chanTheo[k_EWKWV13]; 
  chanESyst[k_EWKWV13]  = 0.18 * chanTheo[k_EWKWV13]; 
  chanETotp[k_EWKWV13]  = sqrt(chanEStatp[k_EWKWV13]*chanEStatp[k_EWKWV13]+chanESystp[k_EWKWV13]*chanESystp[k_EWKWV13]);
  chanETotm[k_EWKWV13]  = sqrt(chanEStatm[k_EWKWV13]*chanEStatm[k_EWKWV13]+chanESystm[k_EWKWV13]*chanESystm[k_EWKWV13]);
chanETotm[k_EWKWV13]  = (chanETotp[k_EWKWV13]+chanETotm[k_EWKWV13])/2.0;


// EW WW SMP-21-001
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-21-001/index.html
// http://cds.cern.ch/record/2791336
// replaced with
// https://arxiv.org/abs/2205.05711 submitted to PLB

  chanMeasurement[k_EWKWW13] = "#scale[0.9]{#splitline{ EW}{osWW}}";
  if (exportExeFormat) chanMeasurement[k_EWKWW13] = "EW os WW";
  if (version == 6) chanMeasurement[k_EWKWW13] = "#splitline{EWK os WW}{WW #rightarrow l#nu l#nu}";
  if (ratioPlot) chanMeasurement[k_EWKWW13]     = "os WW";
  chanLumi[k_EWKWW13]= "138 fb^{-1}";
  chanCadi[k_EWKWW13] = "SMP-21-0011";
  chanPreprint[k_EWKWW13] = "2205.05711";
  chanPublication[k_EWKWW13] = "Submitted to PLB";


  chanSigma[k_EWKWW13]  =  0.0102 * scale_; 
  chanEStat[k_EWKWW13]  =  0.131*chanSigma[k_EWKWW13] * scale_;
  chanESyst[k_EWKWW13]  =  0.149*chanSigma[k_EWKWW13] * scale_;
  chanETot[k_EWKWW13]   =  0.0020 * scale_;
  chanTheo[k_EWKWW13] =  0.0091 * scale_;
  chanETheo[k_EWKWW13] = 0.0006 * scale_;


// SS WW SMP-13-015
// http://arxiv.org/abs/1410.6315 Phys. Rev. Lett. 114, 051801 (2015)
// 

  chanMeasurement[k_SSWW8] = "#scale[0.9]{#splitline{ EW}{ssWW}}";
  if (exportExeFormat) chanMeasurement[k_SSWW8] = "EW ss WW";
  if (version == 6) chanMeasurement[k_SSWW8] = "#splitline{EWK ss WW}{WW #rightarrow l#nu l#nu}";
  if (ratioPlot) chanMeasurement[k_SSWW8]     = "ss WW";
  chanLumi[k_SSWW8]= "19.4 fb^{-1}";
  chanCadi[k_SSWW8] = "SMP-13-015";
  chanPreprint[k_SSWW8] = "1410.6315";
  chanPublication[k_SSWW8] = "PRL 114 051801 (2015)";


//scale_ = 1.0/(W_br_lnu*W_br_lnu*2.0) ;

  chanSigma[k_SSWW8]  =  0.0040 * scale_; 
  chanEStat[k_SSWW8]  =   0.0022 * scale_;
  chanESyst[k_SSWW8]  =   0.00105 * scale_;
  chanETot[k_SSWW8]   =  sqrt( 
			   chanEStat[k_SSWW8]*chanEStat[k_SSWW8]
			   +
			   chanESyst[k_SSWW8]*chanESyst[k_SSWW8]
			    );
  chanTheo[k_SSWW8] =  0.0058 * scale_;
  chanETheo[k_SSWW8] =  0.0012 * scale_;

// 4.0 + 2.4 - 2.0 stat + 1.1 - 1.0 sys


  scale_ = 1.;

// SS WW 13 TeV
// SMP-17-004
// https://arxiv.org/abs/1709.05822 Phys. Rev. Lett. 120, 081801 (2018)
// replace with
//http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-19-012/index.html


  chanMeasurement[k_SSWW13] = "#scale[0.9]{#splitline{ EW}{ssWW}}";
  if (exportExeFormat) chanMeasurement[k_SSWW13] = "EW ss WW";
  if (version == 6) chanMeasurement[k_SSWW13] = "#splitline{EWK ss WW}{WW #rightarrow l#nu l#nu}";
  if (ratioPlot) chanMeasurement[k_SSWW13]     = "ss WW";
  chanLumi[k_SSWW13]= "137 fb^{-1}";
  chanCadi[k_SSWW13] = "SMP-17-004";
  chanPreprint[k_SSWW13] = "1709.05822";
  chanPublication[k_SSWW13] = "PRL 120 081801 (2018)";


//scale_ = 1.0/(W_br_lnu*W_br_lnu*2.0) ;



//  chanSigma[k_SSWW13]  =  0.00383 * scale_; 
//  chanEStat[k_SSWW13]  =   0.00066 * scale_;
//  chanESyst[k_SSWW13]  =   0.00035 * scale_;
  chanSigma[k_SSWW13]  =  0.00398 * scale_; 
  chanEStat[k_SSWW13]  =   0.00037 * scale_;
  chanESyst[k_SSWW13]  =   0.00025 * scale_;
  chanETot[k_SSWW13]   =  sqrt( 
			   chanEStat[k_SSWW13]*chanEStat[k_SSWW13]
			   +
			   chanESyst[k_SSWW13]*chanESyst[k_SSWW13]
			    );
//  chanTheo[k_SSWW13] =  0.00425 * scale_;
//  chanETheo[k_SSWW13] =  0.00027 * scale_;
  chanTheo[k_SSWW13] =  0.00331 * scale_;
  chanETheo[k_SSWW13] =  0.00047 * scale_;
// with NLO corrections




// Higgs results

// Higgs + jets at 13 TeV in H->gg
// HIG-17-015
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-17-015/index.html
// Replace with combination of H->gg and H->ZZ
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-17-028/index.html
// https://arxiv.org/abs/1812.06504 Submitted to Phys. Lett. B 792 (2019) 369
// H + 0j

scale_ = 1.0/1000.0;

chanMeasurement[k_H0jet13]  = "#splitline{H}{=0j}";
 if (exportExeFormat) chanMeasurement[k_H0jet13] = "H0j";
  chanLumi[k_H0jet13]  = "35.9 fb^{-1}";
  chanCadi[k_H0jet13] = "HIG-17-028";
  chanPreprint[k_H0jet13] = "1812.06504";
  chanPublication[k_H0jet13] = "PLB 792 (2019) 369";


  chanTheo[k_H0jet13] =   35.71 * scale_;
  chanETheop[k_H0jet13] =  0.06456 * chanTheo[k_H0jet13];
  chanETheom[k_H0jet13] =  0.06456 * chanTheo[k_H0jet13];
  chanETheo[k_H0jet13] = (chanETheop[k_H0jet13] +chanETheom[k_H0jet13])/2.0;


  chanSigma[k_H0jet13]  =   47.0 * scale_; 
  chanEStatp[k_H0jet13]  =   0.0;
  chanESystp[k_H0jet13]  =   0.0;
  chanETotp[k_H0jet13]   =  6.2 * scale_ ;
  chanEStatm[k_H0jet13]  =  0.0;
  chanESystm[k_H0jet13]  =  0.0;
  chanETotm[k_H0jet13]   =  6.4 * scale_;
 
  chanEStat[k_H0jet13] = (chanEStatp[k_H0jet13] +chanEStatm[k_H0jet13])/2.0;
  chanESyst[k_H0jet13] = (chanESystp[k_H0jet13] +chanESystm[k_H0jet13])/2.0;
  chanETot[k_H0jet13] = (chanETotp[k_H0jet13] +chanETotm[k_H0jet13])/2.0;

// H + 1j
chanMeasurement[k_H1jet13]  = "=1j";
 if (exportExeFormat) chanMeasurement[k_H1jet13] = "Hj";
  chanLumi[k_H1jet13]  = "35.9 fb^{-1}";
  chanCadi[k_H1jet13] = "HIG-17-028";
  chanPreprint[k_H1jet13] = "1812.06504";
  chanPublication[k_H1jet13] = "PLB 792 (2019) 369";

  chanTheo[k_H1jet13] =   14.03 * scale_;
  chanETheop[k_H1jet13] =  0.07756 * chanTheo[k_H1jet13];
  chanETheom[k_H1jet13] =  0.07756 * chanTheo[k_H1jet13];
  chanETheo[k_H1jet13] = (chanETheop[k_H1jet13] +chanETheom[k_H1jet13])/2.0;


  chanSigma[k_H1jet13]  =   11.0 * scale_; 
  chanEStatp[k_H1jet13]  =   0.0;
  chanESystp[k_H1jet13]  =   0.0;
  chanETotp[k_H1jet13]   =  3.7 * scale_ ;
  chanEStatm[k_H1jet13]  =  0.0;
  chanESystm[k_H1jet13]  =  0.0;
  chanETotm[k_H1jet13]   =  3.4 * scale_;
 
  chanEStat[k_H1jet13] = (chanEStatp[k_H1jet13] +chanEStatm[k_H1jet13])/2.0;
  chanESyst[k_H1jet13] = (chanESystp[k_H1jet13] +chanESystm[k_H1jet13])/2.0;
  chanETot[k_H1jet13] = (chanETotp[k_H1jet13] +chanETotm[k_H1jet13])/2.0;

// H + 2j
chanMeasurement[k_H2jet13]  = "=2j";
 if (exportExeFormat) chanMeasurement[k_H2jet13] = "H2j";

  chanLumi[k_H2jet13]  = "35.9 fb^{-1}";
  chanCadi[k_H2jet13] = "HIG-17-028";
  chanPreprint[k_H2jet13] = "1812.06504";
  chanPublication[k_H2jet13] = "PLB 792 (2019) 369";

  chanTheo[k_H2jet13] =   4.153 * scale_;
  chanETheop[k_H2jet13] =  0.1014 * chanTheo[k_H2jet13];
  chanETheom[k_H2jet13] =  0.1014 * chanTheo[k_H2jet13];
  chanETheo[k_H2jet13] = (chanETheop[k_H2jet13] +chanETheom[k_H2jet13])/2.0;


  chanSigma[k_H2jet13]  =   3.5 * scale_; 
  chanEStatp[k_H2jet13]  =   0.0;
  chanESystp[k_H2jet13]  =   0.0;
  chanETotp[k_H2jet13]   =  1.9 * scale_ ;
  chanEStatm[k_H2jet13]  =  0.0;
  chanESystm[k_H2jet13]  =  0.0;
  chanETotm[k_H2jet13]   =  1.7 * scale_;
 
  chanEStat[k_H2jet13] = (chanEStatp[k_H2jet13] +chanEStatm[k_H2jet13])/2.0;
  chanESyst[k_H2jet13] = (chanESystp[k_H2jet13] +chanESystm[k_H2jet13])/2.0;
  chanETot[k_H2jet13] = (chanETotp[k_H2jet13] +chanETotm[k_H2jet13])/2.0;


// H + 3j
  chanMeasurement[k_H3jet13]  = "=3j";
 if (exportExeFormat) chanMeasurement[k_H3jet13] = "H3j";
  chanLumi[k_H3jet13]  = "35.9 fb^{-1}";
  chanCadi[k_H3jet13] = "HIG-17-028";
  chanPreprint[k_H3jet13] = "1812.06504";
  chanPublication[k_H3jet13] = "PLB 792 (2019) 369";

  chanTheo[k_H3jet13] =   1.098 * scale_;
  chanETheop[k_H3jet13] =  0.1331 * chanTheo[k_H3jet13];
  chanETheom[k_H3jet13] =  0.1331 * chanTheo[k_H3jet13];
  chanETheo[k_H3jet13] = (chanETheop[k_H3jet13] +chanETheom[k_H3jet13])/2.0;


  chanSigma[k_H3jet13]  =   1.8 * scale_; 
  chanEStatp[k_H3jet13]  =   0.0;
  chanESystp[k_H3jet13]  =   0.0;
  chanETotp[k_H3jet13]   =  1.7 * scale_ ;
  chanEStatm[k_H3jet13]  =  0.0;
  chanESystm[k_H3jet13]  =  0.0;
  chanETotm[k_H3jet13]   =  1.5 * scale_;
 
  chanEStat[k_H3jet13] = (chanEStatp[k_H3jet13] +chanEStatm[k_H3jet13])/2.0;
  chanESyst[k_H3jet13] = (chanESystp[k_H3jet13] +chanESystm[k_H3jet13])/2.0;
  chanETot[k_H3jet13] = (chanETotp[k_H3jet13] +chanETotm[k_H3jet13])/2.0;


// H + 4j
chanMeasurement[k_H4jet13]  = ">=4j";
 if (exportExeFormat) chanMeasurement[k_H4jet13] = "H4j";
  chanLumi[k_H4jet13]  = "35.9 fb^{-1}";
  chanCadi[k_H4jet13] = "HIG-17-028";
  chanPreprint[k_H4jet13] = "1812.06504";
  chanPublication[k_H4jet13] = "PLB 792 (2019) 369";

  chanTheo[k_H4jet13] =   0.6357 * scale_;
  chanETheop[k_H4jet13] =  0.1117 * chanTheo[k_H4jet13];
  chanETheom[k_H4jet13] =  0.1117 * chanTheo[k_H4jet13];
  chanETheo[k_H4jet13] = (chanETheop[k_H4jet13] +chanETheom[k_H4jet13])/2.0;


  chanSigma[k_H4jet13]  =   1.2 * scale_; 
  chanEStatp[k_H4jet13]  =   0.0;
  chanESystp[k_H4jet13]  =   0.0;
  chanETotp[k_H4jet13]   =  0.83 * scale_ ;
  chanEStatm[k_H4jet13]  =  0.0;
  chanESystm[k_H4jet13]  =  0.0;
  chanETotm[k_H4jet13]   =  0.88 * scale_;
 
  chanEStat[k_H4jet13] = (chanEStatp[k_H4jet13] +chanEStatm[k_H4jet13])/2.0;
  chanESyst[k_H4jet13] = (chanESystp[k_H4jet13] +chanESystm[k_H4jet13])/2.0;
  chanETot[k_H4jet13] = (chanETotp[k_H4jet13] +chanETotm[k_H4jet13])/2.0;

scale_ = 1.0;

// !!!!! Add ggH with one b jets
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-17-025/index.html
// https://arxiv.org/abs/1807.03825

// Updated from http://cds.cern.ch/record/1728249, CMS PAS HIG 14 009

// gg -> H gluon fusion Higgs
  // chanMeasurement[k_ggH]  = "ggH";
  // chanLumi[k_ggH]  = "19.6 fb^{-1}";

  // chanSigma[k_ggH]  =   16.4 * scale_; 
  // chanEStatp[k_ggH]  =   3.7 * scale_;
  // chanESystp[k_ggH]  =   0.0 * scale_;
  // chanETotp[k_ggH]   =  sqrt( 
  // 			   chanEStatp[k_ggH]*chanEStatp[k_ggH]
  // 			   +
  // 			   chanESystp[k_ggH]*chanESystp[k_ggH]
  // 			    );

  // chanEStatm[k_ggH]  =   3.3 * scale_;
  // chanESystm[k_ggH]  =   0.0 * scale_;
  // chanETotm[k_ggH]   =  sqrt( 
  // 			   chanEStatm[k_ggH]*chanEStatm[k_ggH]
  // 			   +
  // 			   chanESystm[k_ggH]*chanESystm[k_ggH]
  // 			    );
  // chanEStat[k_ggH] = (chanEStatp[k_ggH] +chanEStatm[k_ggH])/2.0;
  // chanESyst[k_ggH] = (chanESystp[k_ggH] +chanESystm[k_ggH])/2.0;
  // chanETot[k_ggH] = (chanETotp[k_ggH] +chanETotm[k_ggH])/2.0;
 


  // chanTheo[k_ggH] =   19.3 * scale_;
  // chanETheop[k_ggH] =  2.01 * scale_;
  // chanETheom[k_ggH] =  2.01 * scale_;
  // chanETheo[k_ggH] = (chanETheop[k_ggH] +chanETheom[k_ggH])/2.0;
  // chanETheo[k_ggH] = 0.025 * chanSigma[k_ggH] * scale_;


// gg -> H gluon fusion Higgs 7 TeV, 7 and 8 TeV ggH, VH and VBF H results
// HIG-14-009 
// https://arxiv.org/abs/1412.8662 Eur. Phys. J. C 75 (2015) 212

  chanMeasurement[k_ggH]  = "ggH";
  chanLumi[k_ggH]  = "5.1 fb^{-1}";
  chanCadi[k_ggH] = "HIG-14-009";
  chanPreprint[k_ggH] = "1412.8662";
  chanPublication[k_ggH] = "EPJC 75 (2015) 212";

  chanTheo[k_ggH] =   15.13 * scale_;
  chanETheop[k_ggH] =  0.1040 * chanTheo[k_ggH];
  chanETheom[k_ggH] =  0.1055 * chanTheo[k_ggH];
  chanETheo[k_ggH] = (chanETheop[k_ggH] +chanETheom[k_ggH])/2.0;


  chanSigma[k_ggH]  =   1.03 * chanTheo[k_ggH]*scale_; 
  chanEStatp[k_ggH]  =   0.0;
  chanESystp[k_ggH]  =   0.0;
  chanETotp[k_ggH]   =  sqrt(0.37*0.37*chanTheo[k_ggH]*chanTheo[k_ggH] - chanETheop[k_ggH]*chanETheop[k_ggH] );
  chanETotp[k_ggH]   =  sqrt(0.37*0.37*chanTheo[k_ggH]*chanTheo[k_ggH]);

  chanEStatm[k_ggH]  =  0.0;
  chanESystm[k_ggH]  =  0.0;
  chanETotm[k_ggH]   = sqrt(0.33*0.33*chanTheo[k_ggH]*chanTheo[k_ggH] - chanETheom[k_ggH]*chanETheom[k_ggH] );
  chanETotm[k_ggH]   = sqrt(0.33*0.33*chanTheo[k_ggH]*chanTheo[k_ggH] );

  chanEStat[k_ggH] = (chanEStatp[k_ggH] +chanEStatm[k_ggH])/2.0;
  chanESyst[k_ggH] = (chanESystp[k_ggH] +chanESystm[k_ggH])/2.0;
  chanETot[k_ggH] = (chanETotp[k_ggH] +chanETotm[k_ggH])/2.0;
 
// gg -> H gluon fusion Higgs 8 TeV 
  chanMeasurement[k_ggH8]  = "ggH";
  chanLumi[k_ggH8]  = "19.5 fb^{-1}";
  chanCadi[k_ggH8] = "HIG-14-009";
  chanPreprint[k_ggH8] = "1412.8662";
  chanPublication[k_ggH8] = "EPJC 75 (2015) 212";

  chanTheo[k_ggH8] =   19.27 * scale_;
  chanETheop[k_ggH8] =  0.1040 * chanTheo[k_ggH8];
  chanETheom[k_ggH8] =  0.1041 * chanTheo[k_ggH8];
  chanETheo[k_ggH8] = (chanETheop[k_ggH8] +chanETheom[k_ggH8])/2.0;


  chanSigma[k_ggH8]  =   0.79 * chanTheo[k_ggH8] * scale_; 
  chanEStatp[k_ggH8]  =   0.0;
  chanESystp[k_ggH8]  =   0.0;
  chanETotp[k_ggH8]   =  sqrt(0.19*0.19*chanTheo[k_ggH8]*chanTheo[k_ggH8] - chanETheop[k_ggH8]*chanETheop[k_ggH8] );
  chanETotp[k_ggH8]   =  sqrt(0.19*0.19*chanTheo[k_ggH8]*chanTheo[k_ggH8] );


  chanEStatm[k_ggH8]  =  0.0;
  chanESystm[k_ggH8]  =  0.0;
  chanETotm[k_ggH8]   =  sqrt(0.17*0.17*chanTheo[k_ggH8]*chanTheo[k_ggH8] - chanETheom[k_ggH8]*chanETheom[k_ggH8] );
  chanETotm[k_ggH8]   =  sqrt(0.17*0.17*chanTheo[k_ggH8]*chanTheo[k_ggH8] );

  chanEStat[k_ggH8] = (chanEStatp[k_ggH8] +chanEStatm[k_ggH8])/2.0;
  chanESyst[k_ggH8] = (chanESystp[k_ggH8] +chanESystm[k_ggH8])/2.0;
  chanETot[k_ggH8] = (chanETotp[k_ggH8] +chanETotm[k_ggH8])/2.0;
 
// gg -> H gluon fusion Higgs 13 TeV
// from H->gg PAS
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-16-020/index.html
// from H->gg PAS with 35.9 fb-1
  chanMeasurement[k_ggHgg13]  = "ggH";
  chanLumi[k_ggHgg13]  = "12.9 fb^{-1}";
  chanLumi[k_ggHgg13]  = "35.9.9 fb^{-1}";

// cross section from https://arxiv.org/abs/1610.07922 N3NLO
  chanTheo[k_ggHgg13] =   48.58 * scale_;
chanETheop[k_ggHgg13] =  sqrt(4.6*4.6+3.9*3.9)*(chanTheo[k_ggHgg13]/100.0) * scale_;
chanETheom[k_ggHgg13] =  sqrt(6.7*6.7+3.9*3.8)*(chanTheo[k_ggHgg13]/100.0) * scale_;
  chanETheo[k_ggHgg13] = (chanETheop[k_ggHgg13] +chanETheom[k_ggHgg13])/2.0;


  chanSigma[k_ggHgg13]  =   0.77 * chanTheo[k_ggHgg13] * scale_; 
  chanSigma[k_ggHgg13]  =   1.11 * chanTheo[k_ggHgg13] * scale_; 
  chanEStatp[k_ggHgg13]  =   0.0;
  chanESystp[k_ggHgg13]  =   0.0;
  chanETotp[k_ggHgg13]   =  sqrt(0.19*0.19*chanTheo[k_ggHgg13]*chanTheo[k_ggHgg13] - chanETheop[k_ggHgg13]*chanETheop[k_ggHgg13] );
  chanETotp[k_ggHgg13]   =  sqrt(0.19*0.19*chanTheo[k_ggHgg13]*chanTheo[k_ggHgg13] );


  chanEStatm[k_ggHgg13]  =  0.0;
  chanESystm[k_ggHgg13]  =  0.0;
  chanETotm[k_ggHgg13]   =  sqrt(0.18*0.18*chanTheo[k_ggHgg13]*chanTheo[k_ggHgg13] - chanETheom[k_ggHgg13]*chanETheom[k_ggHgg13] );
  chanETotm[k_ggHgg13]   =  sqrt(0.18*0.18*chanTheo[k_ggHgg13]*chanTheo[k_ggHgg13] );

  chanEStat[k_ggHgg13] = (chanEStatp[k_ggHgg13] +chanEStatm[k_ggHgg13])/2.0;
  chanESyst[k_ggHgg13] = (chanESystp[k_ggHgg13] +chanESystm[k_ggHgg13])/2.0;
  chanETot[k_ggHgg13] = (chanETotp[k_ggHgg13] +chanETotm[k_ggHgg13])/2.0;
 

// gg -> H gluon fusion Higgs 13 TeV
// from 13 GeV Combiation paper HIG-17-031, also VH and VBFH
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-17-031/index.html
// https://arxiv.org/abs/1809.10733
// Submitted to EPJC
// Update to http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-19-005/index.html

  chanMeasurement[k_ggH13]  = "ggH";
  chanLumi[k_ggH13]  = "137 fb^{-1}";
  chanCadi[k_ggH13] = "HIG-19-005";
  chanPreprint[k_ggH13] = "https://cds.cern.ch/record/2706103";
  chanPublication[k_ggH13] = "";

// cross section from https://arxiv.org/abs/1610.07922 N3NLO
  chanTheo[k_ggH13] =   48.58 * scale_;
chanETheop[k_ggH13] =  sqrt(4.6*4.6+3.9*3.9)*(chanTheo[k_ggH13]/100.0) * scale_;
chanETheom[k_ggH13] =  sqrt(6.7*6.7+3.9*3.8)*(chanTheo[k_ggH13]/100.0) * scale_;
  chanETheo[k_ggH13] = (chanETheop[k_ggH13] +chanETheom[k_ggH13])/2.0;


  chanSigma[k_ggH13]  =   1.04 * chanTheo[k_ggH13]; 
  chanEStatp[k_ggH13]  =   0.05 * chanTheo[k_ggH13];
  chanESystp[k_ggH13]  =   0.08 * chanTheo[k_ggH13];
chanETotp[k_ggH13]   =   0.09 * chanTheo[k_ggH13];


  chanEStatm[k_ggH13]  =  0.05 * chanTheo[k_ggH13];
  chanESystm[k_ggH13]  =  0.07 * chanTheo[k_ggH13];
  chanETotm[k_ggH13]   =  0.09 * chanTheo[k_ggH13];;

  chanEStat[k_ggH13] = (chanEStatp[k_ggH13] +chanEStatm[k_ggH13])/2.0;
  chanESyst[k_ggH13] = (chanESystp[k_ggH13] +chanESystm[k_ggH13])/2.0;
  chanETot[k_ggH13] = (chanETotp[k_ggH13] +chanETotm[k_ggH13])/2.0;
 



// VBF H, vector boson fusion  Higgs 7 TeV
  // chanMeasurement[k_VBFH] = "#splitline{VBF}{qqH}";
  // chanLumi[k_VBFH] = "5.1 fb^{-1}";

  // chanSigma[k_VBFH]  =   1.74 * scale_; 
  // chanEStatp[k_VBFH]  =   0.58 * scale_;
  // chanESystp[k_VBFH]  =   0.0 * scale_;
  // chanETotp[k_VBFH]   =  sqrt( 
  // 			   chanEStatp[k_VBFH]*chanEStatp[k_VBFH]
  // 			   +
  // 			   chanESystp[k_VBFH]*chanESystp[k_VBFH]
  // 			    );

  // chanEStatm[k_VBFH]  =   0.55 * scale_;
  // chanESystm[k_VBFH]  =   0.0 * scale_;
  // chanETotm[k_VBFH]   =  sqrt( 
  // 			   chanEStatm[k_VBFH]*chanEStatm[k_VBFH]
  // 			   +
  // 			   chanESystm[k_VBFH]*chanESystm[k_VBFH]
  // 			    );
  // chanEStat[k_VBFH] = (chanEStatp[k_VBFH] +chanEStatm[k_VBFH])/2.0;
  // chanESyst[k_VBFH] = (chanESystp[k_VBFH] +chanESystm[k_VBFH])/2.0;
  // chanETot[k_VBFH] = (chanETotp[k_VBFH] +chanETotm[k_VBFH])/2.0;
 


  // chanTheo[k_VBFH] =   1.57 * scale_;
  // chanETheop[k_VBFH] =  0.041 * scale_;
  // chanETheom[k_VBFH] =  0.044 * scale_;
  // chanETheo[k_VBFH] = (chanETheop[k_VBFH] +chanETheom[k_VBFH])/2.0;
  // chanETheo[k_VBFH] = 0.025 *  chanSigma[k_VBFH]* scale_;

// VBF vector boson fusion Higgs 7 TeV 
  chanMeasurement[k_VBFH]  = "#scale[0.70]{#splitline{VBF}{qqH}}";
  if (exportExeFormat) chanMeasurement[k_VBFH] = "VBF qqH";
  if (version == 6) chanMeasurement[k_VBFH] = "qqH";
  chanLumi[k_VBFH]  = "5.1 fb^{-1}";
  chanCadi[k_VBFH] = "HIG-14-009";
  chanPreprint[k_VBFH] = "1412.8662";
  chanPublication[k_VBFH] = "EPJC 75 (2015) 212";

  chanTheo[k_VBFH] =   1.222 * scale_;
  chanETheop[k_VBFH] =  sqrt(0.0019*0.0019+0.021*0.021+0.004*0.004+0.022*0.022) * chanTheo[k_VBFH];
  chanETheom[k_VBFH] =  sqrt(0.0021*0.0021+0.021*0.021+0.004*0.004+0.022*0.022) * chanTheo[k_VBFH];
  chanETheo[k_VBFH] = (chanETheop[k_VBFH] +chanETheom[k_VBFH])/2.0;


  chanSigma[k_VBFH]  =   1.77 * chanTheo[k_VBFH] * scale_; 
  chanEStatp[k_VBFH]  =   0.0;
  chanESystp[k_VBFH]  =   0.0;
  chanETotp[k_VBFH]   =  sqrt(0.99*0.99*chanTheo[k_VBFH]*chanTheo[k_VBFH] - chanETheop[k_VBFH]*chanETheop[k_VBFH] );
  chanETotp[k_VBFH]   =  sqrt(0.99*0.99*chanTheo[k_VBFH]*chanTheo[k_VBFH] );

  chanEStatm[k_VBFH]  =  0.0;
  chanESystm[k_VBFH]  =  0.0;
  chanETotm[k_VBFH]   = sqrt(0.90*0.90*chanTheo[k_VBFH]*chanTheo[k_VBFH] - chanETheom[k_VBFH]*chanETheom[k_VBFH] );
  chanETotm[k_VBFH]   = sqrt(0.90*0.90*chanTheo[k_VBFH]*chanTheo[k_VBFH] );
 
  chanEStat[k_VBFH] = (chanEStatp[k_VBFH] +chanEStatm[k_VBFH])/2.0;
  chanESyst[k_VBFH] = (chanESystp[k_VBFH] +chanESystm[k_VBFH])/2.0;
  chanETot[k_VBFH] = (chanETotp[k_VBFH] +chanETotm[k_VBFH])/2.0;
 
// VBF vector boson fusion Higgs 8 TeV
  chanMeasurement[k_VBFH8]  = "#scale[0.70]{#splitline{VBF}{qqH}}";
  if (exportExeFormat) chanMeasurement[k_VBFH8] = "VBF qqH";
  if (version == 6) chanMeasurement[k_VBFH8] = "qqH";
  chanLumi[k_VBFH8]  = "19.5 fb^{-1}";
  chanCadi[k_VBFH8] = "HIG-14-009";
  chanPreprint[k_VBFH8] = "1412.8662";
  chanPublication[k_VBFH8] = "EPJC 75 (2015) 212";

  chanTheo[k_VBFH8] =   1.578 * scale_;
chanETheop[k_VBFH8] =  sqrt(0.0026*0.0026+0.021*0.021+0.004*0.004+0.022*0.022) * chanTheo[k_VBFH8];
chanETheom[k_VBFH8] = sqrt(0.0024*0.0024+0.021*0.021+0.004*0.004+0.022*0.022) * chanTheo[k_VBFH8];
  chanETheo[k_VBFH8] = (chanETheop[k_VBFH8] +chanETheom[k_VBFH8])/2.0;


  chanSigma[k_VBFH8]  =   1.02 * chanTheo[k_VBFH8] * scale_; 
  chanEStatp[k_VBFH8]  =   0.0;
  chanESystp[k_VBFH8]  =   0.0;
  chanETotp[k_VBFH8]   =  sqrt(0.39*0.39*chanTheo[k_VBFH8]*chanTheo[k_VBFH8] - chanETheop[k_VBFH8]*chanETheop[k_VBFH8] );
  chanETotp[k_VBFH8]   =  sqrt(0.39*0.39*chanTheo[k_VBFH8]*chanTheo[k_VBFH8] );



  chanEStatm[k_VBFH8]  =  0.0;
  chanESystm[k_VBFH8]  =  0.0;
  chanETotm[k_VBFH8]   =  sqrt(0.36*0.36*chanTheo[k_VBFH8]*chanTheo[k_VBFH8] - chanETheom[k_VBFH8]*chanETheom[k_VBFH8] );
  chanETotm[k_VBFH8]   =  sqrt(0.36*0.36*chanTheo[k_VBFH8]*chanTheo[k_VBFH8] );

  chanEStat[k_VBFH8] = (chanEStatp[k_VBFH8] +chanEStatm[k_VBFH8])/2.0;
  chanESyst[k_VBFH8] = (chanESystp[k_VBFH8] +chanESystm[k_VBFH8])/2.0;
  chanETot[k_VBFH8] = (chanETotp[k_VBFH8] +chanETotm[k_VBFH8])/2.0;
 
// VBF vector boson fusion Higgs 13 TeV
// from 13 GeV Combiation paper HIG-17-031
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-17-031/index.html
// https://arxiv.org/abs/1809.10733
// Submitted to EPJC
// Update to http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-19-005/index.html

  chanMeasurement[k_VBFH13]  = "#scale[0.70]{#splitline{VBF}{qqH}}";
  if (exportExeFormat) chanMeasurement[k_VBFH13] = "VBF qqH";
  chanLumi[k_VBFH13]  = "137 fb^{-1}";
  chanCadi[k_VBFH13] = "HIG-19-005";
  chanPreprint[k_VBFH13] = "https://cds.cern.ch/record/2706103";
  chanPublication[k_VBFH13] = "";

// cross section from https://arxiv.org/abs/1610.07922 NNLO+EW

  chanTheo[k_VBFH13] =   3.7817 * scale_;
chanETheop[k_VBFH13] =  sqrt(0.0043*0.0043+0.021*0.021+0.005*0.005+0.021*0.021) * chanTheo[k_VBFH13];
chanETheom[k_VBFH13] =  sqrt(0.0033*0.0033+0.021*0.021+0.005*0.005+0.021*0.021) * chanTheo[k_VBFH13];
  chanETheo[k_VBFH13] = (chanETheop[k_VBFH13] +chanETheom[k_VBFH13])/2.0;


  chanSigma[k_VBFH13]  =   0.75 * chanTheo[k_VBFH13]; 
  chanEStatp[k_VBFH13]  =   0.16 * chanTheo[k_VBFH13];
  chanESystp[k_VBFH13]  =   0.10 * chanTheo[k_VBFH13];
  chanETotp[k_VBFH13]   =  0.19 * chanTheo[k_VBFH13];


  chanEStatm[k_VBFH13]  =  0.15 * chanTheo[k_VBFH13];
  chanESystm[k_VBFH13]  =  0.08 * chanTheo[k_VBFH13];
  chanETotm[k_VBFH13]   =  0.19 * chanTheo[k_VBFH13];


  chanEStat[k_VBFH13] = (chanEStatp[k_VBFH13] +chanEStatm[k_VBFH13])/2.0;
  chanESyst[k_VBFH13] = (chanESystp[k_VBFH13] +chanESystm[k_VBFH13])/2.0;
  chanETot[k_VBFH13] = (chanETotp[k_VBFH13] +chanETotm[k_VBFH13])/2.0;
 



// VH, assocaited Higgs production with W or Z
  // chanMeasurement[k_VH]   = "VH";
  // chanLumi[k_VH]   = "19.6 fb^{-1}";


  // chanSigma[k_VH]  =   1.07 * scale_; 
  // chanEStatp[k_VH]  =   0.43 * scale_;
  // chanESystp[k_VH]  =   0.0 * scale_;
  // chanETotp[k_VH]   =  sqrt( 
  // 			   chanEStatp[k_VH]*chanEStatp[k_VH]
  // 			   +
  // 			   chanESystp[k_VH]*chanESystp[k_VH]
  // 			    );

  // chanEStatm[k_VH]  =   0.43 * scale_;
  // chanESystm[k_VH]  =   0.0 * scale_;
  // chanETotm[k_VH]   =  sqrt( 
  // 			   chanEStatm[k_VH]*chanEStatm[k_VH]
  // 			   +
  // 			   chanESystm[k_VH]*chanESystm[k_VH]
  // 			    );
  // chanEStat[k_VH] = (chanEStatp[k_VH] +chanEStatm[k_VH])/2.0;
  // chanESyst[k_VH] = (chanESystp[k_VH] +chanESystm[k_VH])/2.0;
  // chanETot[k_VH] = (chanETotp[k_VH] +chanETotm[k_VH])/2.0;
 


  // chanTheo[k_VH] =   1.07 * scale_;
  // chanETheop[k_VH] =  0.026 * scale_;
  // chanETheom[k_VH] =  0.026 * scale_;
  // chanETheo[k_VH] = (chanETheop[k_VH] +chanETheom[k_VH])/2.0;
  // chanETheo[k_VH] = 0.02 *  chanSigma[k_VH] * scale_;

// VH, assocaited Higgs production with W or Z 7 TeV 

 chanMeasurement[k_VH]  = "VH";
  chanLumi[k_VH]  = "5.1 fb^{-1}";
  chanCadi[k_VH] = "HIG-14-009";
  chanPreprint[k_VH] = "1412.8662";
  chanPublication[k_VH] = "EPJC 75 (2015) 212";

  chanTheo[k_VH] =   (0.5785+0.3351 )* scale_;
  chanETheop[k_VH] =  (0.5785*0.0275+0.3351*0.0396 );
  chanETheom[k_VH] = (0.5785*0.0275+0.3351*0.0396 );
  chanETheo[k_VH] = (chanETheop[k_VH] +chanETheom[k_VH])/2.0;

  chanSigma[k_VH]  =   -2.688 * chanTheo[k_VH] * scale_; 
  chanEStatp[k_VH]  =   0.0;
  chanESystp[k_VH]  =   0.0;
  chanETotp[k_VH]   =   0.0;


  chanEStatm[k_VH]  =  0.0;
  chanESystm[k_VH]  =  0.0;
  chanETotm[k_VH]   = 0.0 ;

  chanEStat[k_VH] = (chanEStatp[k_VH] +chanEStatm[k_VH])/2.0;
  chanESyst[k_VH] = (chanESystp[k_VH] +chanESystm[k_VH])/2.0;
  chanETot[k_VH] = (chanETotp[k_VH] +chanETotm[k_VH])/2.0;
 
// VH, assocaited Higgs production with W or Z 8 TeV
  chanMeasurement[k_VH8]  = "VH";
  chanLumi[k_VH8]  = "19.5 fb^{-1}";
  chanCadi[k_VH8] = "HIG-14-009";
  chanPreprint[k_VH8] = "1412.8662";
  chanPublication[k_VH8] = "EPJC 75 (2015) 212";

  chanTheo[k_VH8] =   (0.7046+0.4153 )* scale_;
  chanETheop[k_VH8] =  (0.7046*0.0251+0.4153*0.0398 );
  chanETheom[k_VH8] = (0.7046*0.0251+0.4153*0.0398 );
  chanETheo[k_VH8] = (chanETheop[k_VH8] +chanETheom[k_VH8])/2.0;

  chanSigma[k_VH8]  =   0.96 * chanTheo[k_VH8]; 
  chanEStatp[k_VH8]  =   0.0;
  chanESystp[k_VH8]  =   0.0;
  chanETotp[k_VH8]   =  sqrt(0.41*0.41*chanTheo[k_VH8]*chanTheo[k_VH8] - chanETheop[k_VH8]*chanETheop[k_VH8] );
  chanETotp[k_VH8]   =  sqrt(0.41*0.41*chanTheo[k_VH8]*chanTheo[k_VH8] );


  chanEStatm[k_VH8]  =  0.0;
  chanESystm[k_VH8]  =  0.0;
  chanETotm[k_VH8]   =  sqrt(0.39*0.39*chanTheo[k_VH8]*chanTheo[k_VH8] - chanETheom[k_VH8]*chanETheom[k_VH8] );
  chanETotm[k_VH8]   =  sqrt(0.39*0.39*chanTheo[k_VH8]*chanTheo[k_VH8] );

  chanEStat[k_VH8] = (chanEStatp[k_VH8] +chanEStatm[k_VH8])/2.0;
  chanESyst[k_VH8] = (chanESystp[k_VH8] +chanESystm[k_VH8])/2.0;
  chanETot[k_VH8] = (chanETotp[k_VH8] +chanETotm[k_VH8])/2.0;
 
// VH, assocaited Higgs production with W or Z 13 TeV
// From HIG-16-044
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-16-044/
// https://arxiv.org/abs/1709.07497

  chanMeasurement[k_VH13]  = "VH";
  chanLumi[k_VH13]  = "35 fb^{-1}";

  chanTheo[k_VH13] =   (1.373+0.8837 )* scale_;
chanETheop[k_VH13] =  sqrt(1.373*0.005*1.373*0.005 + 1.373*0.019*1.373*0.019)+sqrt(0.8837*0.038*0.8837*0.038 + 0.8837*0.016*0.8837*0.016);
  chanETheom[k_VH13] = sqrt(1.373*0.007*1.373*0.007 + 1.373*0.019*1.373*0.019)+sqrt(0.8831*0.038*0.8837*0.031 + 0.8837*0.016*0.8837*0.016);
  chanETheo[k_VH13] = (chanETheop[k_VH13] +chanETheom[k_VH13])/2.0;


chanSigma[k_VH13]  =   1.19 * chanTheo[k_VH13]; 
  chanEStatp[k_VH13]  =   0.21 * chanTheo[k_VH13];
  chanESystp[k_VH13]  =   0.34 * chanTheo[k_VH13];
chanETotp[k_VH13]   =  sqrt(chanEStatp[k_VH13]*chanEStatp[k_VH13] + chanESystp[k_VH13]*chanESystp[k_VH13])  ;


  chanEStatm[k_VH13]  =  0.20 * chanTheo[k_VH13];
  chanESystm[k_VH13]  =  0.32 * chanTheo[k_VH13];
  chanETotm[k_VH13]   =   sqrt(chanEStatm[k_VH13]*chanEStatm[k_VH13] + chanESystm[k_VH13]*chanESystm[k_VH13]);

  chanEStat[k_VH13] = (chanEStatp[k_VH13] +chanEStatm[k_VH13])/2.0;
  chanESyst[k_VH13] = (chanESystp[k_VH13] +chanESystm[k_VH13])/2.0;
  chanETot[k_VH13] = (chanETotp[k_VH13] +chanETotm[k_VH13])/2.0;




// WH
// WH Higgs 13 TeV 35.9
// from 13 GeV Combiation paper HIG-17-031
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-17-031/index.html
// https://arxiv.org/abs/1809.10733
// Submitted to EPJC
// Update to http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-19-005/index.html

  chanMeasurement[k_WH13]  = "WH";
  chanLumi[k_WH13]  = "137 fb^{-1}";
  chanCadi[k_WH13] = "HIG-19-005";
  chanPreprint[k_WH13] = "https://cds.cern.ch/record/2706103";
  chanPublication[k_WH13] = "";

  chanTheo[k_WH13] =   (1.373 )* scale_;
chanETheop[k_WH13] =  sqrt(1.373*0.005*1.373*0.005 + 1.373*0.019*1.373*0.019);
  chanETheom[k_WH13] = sqrt(1.373*0.007*1.373*0.007 + 1.373*0.019*1.373*0.019);
  chanETheo[k_WH13] = (chanETheop[k_WH13] +chanETheom[k_WH13])/2.0;


  chanSigma[k_WH13]  =   1.46 * chanTheo[k_WH13]; 
  chanEStatp[k_WH13]  =   0.29 * chanTheo[k_WH13];
  chanESystp[k_WH13]  =   0.22 * chanTheo[k_WH13];
chanETotp[k_WH13]   =    0.37 * chanTheo[k_WH13];


  chanEStatm[k_WH13]  =  0.28 * chanTheo[k_WH13];
  chanESystm[k_WH13]  =  0.21 * chanTheo[k_WH13];
  chanETotm[k_WH13]   =  0.35 * chanTheo[k_WH13];

  chanEStat[k_WH13] = (chanEStatp[k_WH13] +chanEStatm[k_WH13])/2.0;
  chanESyst[k_WH13] = (chanESystp[k_WH13] +chanESystm[k_WH13])/2.0;
  chanETot[k_WH13] = (chanETotp[k_WH13] +chanETotm[k_VH13])/2.0;


// ZH
// ZH Higgs 13 TeV 35.9
// from 13 GeV Combiation paper HIG-17-031
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-17-031/index.html
// https://arxiv.org/abs/1809.10733
// Submitted to EPJC
// Update to http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-19-005/index.html

  chanMeasurement[k_ZH13]  = "ZH";
  chanLumi[k_ZH13]  = "137 fb^{-1}";
  chanCadi[k_ZH13] = "HIG-19-005";
  chanPreprint[k_ZH13] = "https://cds.cern.ch/record/2706103";
  chanPublication[k_ZH13] = "";

  chanTheo[k_ZH13] =   (0.8837 )* scale_;
chanETheop[k_ZH13] =  sqrt(0.8837*0.038*0.8837*0.038 + 0.8837*0.016*0.8837*0.016);
  chanETheom[k_ZH13] = sqrt(0.8831*0.038*0.8837*0.031 + 0.8837*0.016*0.8837*0.016);
  chanETheo[k_ZH13] = (chanETheop[k_ZH13] +chanETheom[k_ZH13])/2.0;


chanSigma[k_ZH13]  =   0.98 * chanTheo[k_ZH13]; 
  chanEStatp[k_ZH13]  =   0.26 * chanTheo[k_ZH13];
  chanESystp[k_ZH13]  =   0.17 * chanTheo[k_ZH13];
chanETotp[k_ZH13]   =    0.31 * chanTheo[k_ZH13];


  chanEStatm[k_ZH13]  =  0.25 * chanTheo[k_ZH13];
  chanESystm[k_ZH13]  =  0.15 * chanTheo[k_ZH13];
  chanETotm[k_ZH13]   =  0.29 * chanTheo[k_ZH13];

  chanEStat[k_ZH13] = (chanEStatp[k_ZH13] +chanEStatm[k_ZH13])/2.0;
  chanESyst[k_ZH13] = (chanESystp[k_ZH13] +chanESystm[k_ZH13])/2.0;
  chanETot[k_ZH13] = (chanETotp[k_ZH13] +chanETotm[k_ZH13])/2.0;




// ttbar H, assocaited Higgs production with a ttbar
// Updated to new!!!!! http://arxiv.org/abs/1408.1682
  // chanMeasurement[k_ttH]  = "ttH";
  // chanLumi[k_ttH]  = "19.6 fb^{-1}";

  // chanSigma[k_ttH]  =   0.36 * scale_; 
  // chanEStatp[k_ttH]  =   0.13 * scale_;
  // chanESystp[k_ttH]  =   0.0 * scale_;
  // chanETotp[k_ttH]   =  sqrt( 
  // 			   chanEStatp[k_ttH]*chanEStatp[k_ttH]
  // 			   +
  // 			   chanESystp[k_ttH]*chanESystp[k_ttH]
  // 			    );

  // chanEStatm[k_ttH]  =   0.13 * scale_;
  // chanESystm[k_ttH]  =   0.0 * scale_;
  // chanETotm[k_ttH]   =  sqrt( 
  // 			   chanEStatm[k_ttH]*chanEStatm[k_ttH]
  // 			   +
  // 			   chanESystm[k_ttH]*chanESystm[k_ttH]
  // 			    );
  // chanEStat[k_ttH] = (chanEStatp[k_ttH] +chanEStatm[k_ttH])/2.0;
  // chanESyst[k_ttH] = (chanESystp[k_ttH] +chanESystm[k_ttH])/2.0;
  // chanETot[k_ttH] = (chanETotp[k_ttH] +chanETotm[k_ttH])/2.0;
 


  // chanTheo[k_ttH] =   0.1271 * scale_;
  // chanETheop[k_ttH] =  0.0114 * scale_;
  // chanETheom[k_ttH] =  0.0157 * scale_;
  // chanETheo[k_ttH] = (chanETheop[k_ttH] +chanETheom[k_ttH])/2.0;
  // chanETheo[k_ttH] = 0.01 *  chanSigma[k_ttH] * scale_;

// ttbar H, assocaited Higgs production with a ttbar 7 TeV
  chanMeasurement[k_ttH]  = "ttH";
  chanLumi[k_ttH]  = "5.1 fb^{-1}";
  chanCadi[k_ttH] = "HIG-14-009";
  chanPreprint[k_ttH] = "1412.8662";
  chanPublication[k_ttH] = "EPJC 75 (2015) 212";


  chanTheo[k_ttH] =   0.08632 * scale_;
  chanETheop[k_ttH] =  0.0895 * chanTheo[k_ttH];
  chanETheom[k_ttH] =  0.123 * chanTheo[k_ttH];
  chanETheo[k_ttH] = (chanETheop[k_ttH] +chanETheom[k_ttH])/2.0;


  chanSigma[k_ttH]  =   -2.19 * chanTheo[k_ttH] * scale_; 
  chanEStatp[k_ttH]  =   0.0;
  chanESystp[k_ttH]  =   0.0;
  chanETotp[k_ttH]   =  0.0;

  chanEStatm[k_ttH]  =  0.0;
  chanESystm[k_ttH]  =  0.0;
  chanETotm[k_ttH]   =  0.0;

  chanEStat[k_ttH] = (chanEStatp[k_ttH] +chanEStatm[k_ttH])/2.0;
  chanESyst[k_ttH] = (chanESystp[k_ttH] +chanESystm[k_ttH])/2.0;
  chanETot[k_ttH] = (chanETotp[k_ttH] +chanETotm[k_ttH])/2.0;
 
// ttbar H, assocaited Higgs production with a ttbar 8 TeV
  chanMeasurement[k_ttH8]  = "ttH";
  chanLumi[k_ttH8]  = "19.5 fb^{-1}";
  chanCadi[k_ttH8] = "HIG-14-009";
  chanPreprint[k_ttH8] = "1412.8662";
  chanPublication[k_ttH8] = "EPJC 75 (2015) 212";

  chanTheo[k_ttH8] =   0.1293 * scale_;
  chanETheop[k_ttH8] =  0.0899 * chanTheo[k_ttH];
  chanETheom[k_ttH8] =  0.125 * chanTheo[k_ttH];
  chanETheo[k_ttH8] = (chanETheop[k_ttH8] +chanETheom[k_ttH8])/2.0;


  chanSigma[k_ttH8]  =   3.27 * chanTheo[k_ttH8]; 
  chanEStatp[k_ttH8]  =  0.0;
  chanESystp[k_ttH8]  =  0.0;
  chanETotp[k_ttH8]   =  sqrt(1.20*1.20*chanTheo[k_ttH8]*chanTheo[k_ttH8] - chanETheop[k_ttH8]*chanETheop[k_ttH8] );
  chanETotp[k_ttH8]   =  sqrt(1.20*1.20*chanTheo[k_ttH8]*chanTheo[k_ttH8] );


  chanEStatm[k_ttH8]  =  0.0;
  chanESystm[k_ttH8]  =  0.0;
  chanETotm[k_ttH8]   =  sqrt(1.04*1.04*chanTheo[k_ttH8]*chanTheo[k_ttH8] - chanETheom[k_ttH8]*chanETheom[k_ttH8] );
  chanETotm[k_ttH8]   =  sqrt(1.04*1.04*chanTheo[k_ttH8]*chanTheo[k_ttH8] );

  chanEStat[k_ttH8] = (chanEStatp[k_ttH8] +chanEStatm[k_ttH8])/2.0;
  chanESyst[k_ttH8] = (chanESystp[k_ttH8] +chanESystm[k_ttH8])/2.0;
  chanETot[k_ttH8] = (chanETotp[k_ttH8] +chanETotm[k_ttH8])/2.0;
 
// ttbar H, assocaited Higgs production with a ttbar 13 TeV
// ttbar H 35.9 fb-1
// from 13 GeV Combiation paper HIG-17-031
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-17-031/index.html
// https://arxiv.org/abs/1809.10733
// Submitted to EPJC
// Update to http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-19-005/index.html


  chanMeasurement[k_ttH13]  = "ttH";
  chanLumi[k_ttH13]  = "137 fb^{-1}";
  chanCadi[k_ttH13] = "HIG-19-005";
  chanPreprint[k_ttH13] = "https://cds.cern.ch/record/2706103";
  chanPublication[k_ttH13] = "";

  chanTheo[k_ttH13] =   0.5071 * scale_;
chanETheop[k_ttH13] =  sqrt(0.058*0.058 + 0.036*0.036)*chanTheo[k_ttH13];
chanETheom[k_ttH13] =  sqrt(0.092*0.092 + 0.036*0.036)*chanTheo[k_ttH13];
  chanETheo[k_ttH13] = (chanETheop[k_ttH13] +chanETheom[k_ttH13])/2.0;


  chanSigma[k_ttH13]  =   1.14 * chanTheo[k_ttH13] * scale_;

  chanEStatp[k_ttH13]  =   0.13 * chanTheo[k_ttH13] * scale_;
chanESystp[k_ttH13]  =     0.17 * chanTheo[k_ttH13] * scale_;
  chanETotp[k_ttH13]   =  0.21 * chanTheo[k_ttH13] * scale_;

  chanEStatm[k_ttH13]  =  0.13 * chanTheo[k_ttH13] * scale_;
  chanESystm[k_ttH13]  =  0.15 * chanTheo[k_ttH13] * scale_;
  chanETotm[k_ttH13]   =  0.20 * chanTheo[k_ttH13] * scale_;

  chanEStat[k_ttH13] = (chanEStatp[k_ttH13] +chanEStatm[k_ttH13])/2.0;
  chanESyst[k_ttH13] = (chanESystp[k_ttH13] +chanESystm[k_ttH13])/2.0;
  chanETot[k_ttH13] = (chanETotp[k_ttH13] +chanETotm[k_ttH13])/2.0;

// HIG-17-016 tH in tHq and tHW
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-17-016/index.html
// Update to http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-18-009/index.html
// https://arxiv.org/abs/1811.09696 Phys. Rev. D 99 (2019) 092005

// Replace with
// https://arxiv.org/abs/2011.03652 Eur. Phys. J. C 81 (2021) 378
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-19-008



  chanMeasurement[k_tH13]  = "tH";
  chanLumi[k_tH13]  = "137 fb^{-1}";
  chanCadi[k_tH13] = "HIG-19-008";
  chanPreprint[k_tH13] = "2011.03652";
  chanPublication[k_tH13] = "EPJC 81 (2021) 378";

// new prediction
chanTheo[k_tH13] =   (0.0743+0.0152) * scale_;
chanETheop[k_tH13] =  0.025*chanTheo[k_tH13];
chanETheom[k_tH13] =  0.025*chanTheo[k_tH13];
  chanETheo[k_tH13] = (chanETheop[k_tH13] +chanETheom[k_tH13])/2.0;


chanSigma[k_tH13]  =   5.7 * chanTheo[k_tH13]; 

  chanEStatp[k_tH13]  =   2.7 * chanTheo[k_tH13] * scale_;
  chanESystp[k_tH13]  =   3.0 * chanTheo[k_tH13] * scale_;
chanETotp[k_tH13]   =  sqrt(chanEStatp[k_tH13]*chanEStatp[k_tH13] + chanESystp[k_tH13]*chanESystp[k_tH13] )* scale_;

  chanEStatm[k_tH13]  =   2.7 * chanTheo[k_tH13] * scale_;
  chanESystm[k_tH13]  =   3.0 * chanTheo[k_tH13] * scale_;
chanETotm[k_tH13]   =  sqrt(chanEStatm[k_tH13]*chanEStatm[k_tH13] + chanESystm[k_tH13]*chanESystm[k_tH13] )* scale_;
									       

  chanEStat[k_tH13] = (chanEStatp[k_tH13] +chanEStatm[k_tH13])/2.0;
  chanESyst[k_tH13] = (chanESystp[k_tH13] +chanESystm[k_tH13])/2.0;
  chanETot[k_tH13] = (chanETotp[k_tH13] +chanETotm[k_tH13])/2.0;







// HH production at 8 TeV in the bbtautau channel
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-15-013/index.html
// https://arxiv.org/pdf/1707.00350.pdf (Submitted to Phys. Rev. D)
//  limit from HH->bbtautau

chanMeasurement[k_HHbbtautau8]  = "#splitline{HH}{bb#tau#tau}"; // def "HH"
chanLumi[k_HHbbtautau8]  = "19.7 fb^{-1}"; // This analysis used 18.3 fb-1 though !!

chanTheo[k_HHbbtautau8]   =   10.16 * 0.001 * scale_; // Updated the cross-section, https://twiki.cern.ch/twiki/bin/view/LHCPhysics/LHCHXSWGHH
chanETheop[k_HHbbtautau8] =  0.77*0.001; // adding (in quad.) the Theo. (5%), PDF (3.1%), alpha_S (2.6%) and scale (+4.1%) unc.s together
chanETheom[k_HHbbtautau8] =  0.92*0.001; // adding (in quad.) the Theo. (5%), PDF (3.1%), alpha_S (2.6%) and scale (-5.7%) unc.s together
  chanETheo[k_HHbbtautau8] = (chanETheop[k_HHbbtautau8] +chanETheom[k_HHbbtautau8])/2.0;


  chanSigma[k_HHbbtautau8]   =   -53 * chanTheo[k_HHbbtautau8] * scale_; 
  chanEStatp[k_HHbbtautau8]  =   0.0;
  chanESystp[k_HHbbtautau8]  =   0.0;
  chanETotp[k_HHbbtautau8]   =  0.0;

  chanEStatm[k_HHbbtautau8]  =  0.0;
  chanESystm[k_HHbbtautau8]  =  0.0;
  chanETotm[k_HHbbtautau8]   =  0.0;

  chanEStat[k_HHbbtautau8] = (chanEStatp[k_HHbbtautau8] +chanEStatm[k_HHbbtautau8])/2.0;
  chanESyst[k_HHbbtautau8] = (chanESystp[k_HHbbtautau8] +chanESystm[k_HHbbtautau8])/2.0;
  chanETot[k_HHbbtautau8]  = (chanETotp[k_HHbbtautau8] +chanETotm[k_HHbbtautau8])/2.0;




// HH production at 8 TeV in the bbgammagamma channel
//http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-13-032/index.html
// https://arxiv.org/abs/1603.06896 Phys. Rev. D 94, 052012 (2016)
// limit from HH->ggbb 

chanMeasurement[k_HHbbgg8]  = "#splitline{HH}{bb#gamma#gamma}"; // def "HH"
  chanLumi[k_HHbbgg8]  = "19.7 fb^{-1}";

chanTheo[k_HHbbgg8]    =   10.16 * 0.001 * scale_; // Updated the cross-section, https://twiki.cern.ch/twiki/bin/view/LHCPhysics/LHCHXSWGHH
chanETheop[k_HHbbgg8]  =  0.77*0.001; // adding (in quad.) the Theo. (5%), PDF (3.1%), alpha_S (2.6%) and scale (+4.1%) unc.s together
chanETheom[k_HHbbgg8]  =  0.92*0.001; // adding (in quad.) the Theo. (5%), PDF (3.1%), alpha_S (2.6%) and scale (-5.7%) unc.s together
  chanETheo[k_HHbbgg8] = (chanETheop[k_HHbbgg8] +chanETheom[k_HHbbgg8])/2.0;

  chanSigma[k_HHbbgg8]  =   -74 * chanTheo[k_HHbbgg8] * scale_; 
  chanEStatp[k_HHbbgg8]  =   0.0;
  chanESystp[k_HHbbgg8]  =   0.0;
  chanETotp[k_HHbbgg8]   =  0.0;

  chanEStatm[k_HHbbgg8]  =  0.0;
  chanESystm[k_HHbbgg8]  =  0.0;
  chanETotm[k_HHbbgg8]   =  0.0;

  chanEStat[k_HHbbgg8] = (chanEStatp[k_HHbbgg8] +chanEStatm[k_HHbbgg8])/2.0;
  chanESyst[k_HHbbgg8] = (chanESystp[k_HHbbgg8] +chanESystm[k_HHbbgg8])/2.0;
  chanETot[k_HHbbgg8] = (chanETotp[k_HHbbgg8] +chanETotm[k_HHbbgg8])/2.0;

// HH production at 8 TeV in the combined bbtautau + bbgammagamma channels
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-15-013/index.html
// https://arxiv.org/pdf/1707.00350.pdf (Submitted to Phys. Rev. D)
// Best limit from Run-1 (HH->bbtautau + HH->bbgammagamma) combination

chanMeasurement[k_HHComb8]  = "HH "; // def "HH"
if (version == 9) chanMeasurement[k_HHComb8]  = "#splitline{HH}{Comb.}"; // def "HH"
chanLumi[k_HHComb8]  = "19.7 fb^{-1}"; // This analysis used 18.3 fb-1 though !!

chanTheo[k_HHComb8] =   10.16 * 0.001 * scale_; // Updated the cross-section, https://twiki.cern.ch/twiki/bin/view/LHCPhysics/LHCHXSWGHH
chanETheop[k_HHComb8] =  0.77*0.001; // adding (in quad.) the Theo. (5%), PDF (3.1%), alpha_S (2.6%) and scale (+4.1%) unc.s together
chanETheom[k_HHComb8] =  0.92*0.001; // adding (in quad.) the Theo. (5%), PDF (3.1%), alpha_S (2.6%) and scale (-5.7%) unc.s together
  chanETheo[k_HHComb8] = (chanETheop[k_HHComb8] +chanETheom[k_HHComb8])/2.0;


  chanSigma[k_HHComb8]   =   -43 * chanTheo[k_HHComb8] * scale_; 
  chanEStatp[k_HHComb8]  =   0.0;
  chanESystp[k_HHComb8]  =   0.0;
  chanETotp[k_HHComb8]   =   0.0;

  chanEStatm[k_HHComb8]  =  0.0;
  chanESystm[k_HHComb8]  =  0.0;
  chanETotm[k_HHComb8]   =  0.0;

  chanEStat[k_HHComb8] = (chanEStatp[k_HHComb8] +chanEStatm[k_HHComb8])/2.0;
  chanESyst[k_HHComb8] = (chanESystp[k_HHComb8] +chanESystm[k_HHComb8])/2.0;
  chanETot[k_HHComb8]  = (chanETotp[k_HHComb8] +chanETotm[k_HHComb8])/2.0;

// HH production at 13 TeV in the bbtautau channel
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-17-002/index.html
// https://arxiv.org/abs/1707.02909
// replace with
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-20-010/index.html
// https://cds.cern.ch/record/2803419

chanMeasurement[k_HHbbtautau13]  = "HH "; // def "HH"
if (version == 9) chanMeasurement[k_HHbbtautau13]  = "#splitline{HH}{bb#tau#tau}"; // def "HH"
  chanCadi[k_HHbbtautau13] = "HIG-20-010";
  chanPreprint[k_HHbbtautau13] = "https://cds.cern.ch/record/2803419";
  chanPublication[k_HHbbtautau13] = "";


if (version == 9) chanMeasurement[k_HHbbtautau13]  = "#splitline{HH}{bb#tau#tau}"; // def "HH"
  chanLumi[k_HHbbtautau13]  = "138 fb^{-1}";

  chanTheo[k_HHbbtautau13]   =  33.45 * 0.001 * scale_; // Updated to the latest theory cross-section, https://twiki.cern.ch/twiki/bin/view/LHCPhysics/LHCHXSWGHH
  chanETheop[k_HHbbtautau13] =  2.4*0.001; // adding (in quad.) the Theo. (5%), PDF (2.1%), alpha_S (2.3%) and scale (+4.3%) unc.s together
  chanETheom[k_HHbbtautau13] =  2.8*0.001; // adding (in quad.) the Theo. (5%), PDF (2.1%), alpha_S (2.3%) and scale (-6.0%) unc.s together
  chanETheo[k_HHbbtautau13]  = (chanETheop[k_HHbbtautau13] +chanETheom[k_HHbbtautau13])/2.0;

  chanSigma[k_HHbbtautau13]  =   - 30.0 * chanTheo[k_HHbbtautau13]; // FOR bbtautau (HIG-17-002)
  chanSigma[k_HHbbtautau13]  =   - 3.3 * chanTheo[k_HHbbtautau13]; // FOR bbtautau (HIG-20-010)

  chanEStatp[k_HHbbtautau13]  =  0.0;
  chanESystp[k_HHbbtautau13]  =  0.0;
  chanETotp[k_HHbbtautau13]   =  0.0;

  chanEStatm[k_HHbbtautau13]  =  0.0;
  chanESystm[k_HHbbtautau13]  =  0.0;
  chanETotm[k_HHbbtautau13]   =  0.0;

  chanEStat[k_HHbbtautau13] = (chanEStatp[k_HHbbtautau13] +chanEStatm[k_HHbbtautau13])/2.0;
  chanESyst[k_HHbbtautau13] = (chanESystp[k_HHbbtautau13] +chanESystm[k_HHbbtautau13])/2.0;
  chanETot[k_HHbbtautau13] = (chanETotp[k_HHbbtautau13] +chanETotm[k_HHbbtautau13])/2.0;


// HH production at 13 TeV in the bbgammagamma channel
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-16-032/index.html
// Best limit from HH->ggbb
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-17-008/index.html
// ggbb limit updated in
// https://arxiv.org/abs/1806.00408
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-17-008/ 
chanMeasurement[k_HHbbgg13]  = "HH"; // def "HH"
if (version == 9)chanMeasurement[k_HHbbgg13]  = "#splitline{HH}{bb#gamma#gamma}"; // def "HH"                                                                                                                         
chanLumi[k_HHbbgg13]  = "35.9 fb^{-1}";
chanTheo[k_HHbbgg13]   =  33.45 * 0.001 * scale_; // Updated to the latest theory cross-section, https://twiki.cern.ch/twiki/bin/view/LHCPhysics/LHCHXSWGHH                                  
chanETheop[k_HHbbgg13] =  2.4*0.001; // adding (in quad.) the Theo. (5%), PDF (2.1%), alpha_S (2.3%) and scale (+4.3%) unc.s together                                                              
chanETheom[k_HHbbgg13] =  2.8*0.001; // adding (in quad.) the Theo. (5%), PDF (2.1%), alpha_S (2.3%) and scale (-6.0%) unc.s together                                                              
chanETheo[k_HHbbgg13]  = (chanETheop[k_HHbbgg13] +chanETheom[k_HHbbgg13])/2.0;

chanSigma[k_HHbbgg13]  =   -19.2 * chanTheo[k_HHbbgg13] * scale_; // FOR bbgammagamma (HIG-16-032)

chanSigma[k_HHbbgg13]  =   -24 * chanTheo[k_HHbbgg13] * scale_; // FOR bbgammagamma (HIG-17-008)                                                              

chanEStatp[k_HHbbgg13]  =  0.0;
chanESystp[k_HHbbgg13]  =  0.0;
chanETotp[k_HHbbgg13]   =  0.0;

chanEStatm[k_HHbbgg13]  =  0.0;
chanESystm[k_HHbbgg13]  =  0.0;
chanETotm[k_HHbbgg13]   =  0.0;

chanEStat[k_HHbbgg13] = (chanEStatp[k_HHbbgg13] +chanEStatm[k_HHbbgg13])/2.0;
chanESyst[k_HHbbgg13] = (chanESystp[k_HHbbgg13] +chanESystm[k_HHbbgg13])/2.0;
chanETot[k_HHbbgg13] = (chanETotp[k_HHbbgg13] +chanETotm[k_HHbbgg13])/2.0;

// HH production at 13 TeV in the bbWW channel
//http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-17-006/index.html
  chanMeasurement[k_HHWWbb13]  = "#splitline{HH}{bbVV}"; // def "HH"
  chanLumi[k_HHWWbb13]  = "35.9 fb^{-1}";

  chanTheo[k_HHWWbb13]   = 33.45 * 0.001 * scale_; // Updated to the latest theory cross-section, https://twiki.cern.ch/twiki/bin/view/LHCPhysics/LHCHXSWGHH
  chanETheop[k_HHWWbb13] = 2.4*0.001; // adding (in quad.) the Theo. (5%), PDF (2.1%), alpha_S (2.3%) and scale (+4.3%) unc.s together
  chanETheom[k_HHWWbb13] = 2.8*0.001; // adding (in quad.) the Theo. (5%), PDF (2.1%), alpha_S (2.3%) and scale (-6.0%) unc.s together
  chanETheo[k_HHWWbb13]  = (chanETheop[k_HHWWbb13] +chanETheom[k_HHWWbb13])/2.0;

  chanSigma[k_HHWWbb13]  =   - 79.0 * chanTheo[k_HHWWbb13]; 

  chanEStatp[k_HHWWbb13]  =   0.0;
  chanESystp[k_HHWWbb13]  =   0.0;
  chanETotp[k_HHWWbb13]   =   0.0;

  chanEStatm[k_HHWWbb13]  =  0.0;
  chanESystm[k_HHWWbb13]  =  0.0;
  chanETotm[k_HHWWbb13]   =  0.0;

  chanEStat[k_HHWWbb13] = (chanEStatp[k_HHWWbb13] +chanEStatm[k_HHWWbb13])/2.0;
  chanESyst[k_HHWWbb13] = (chanESystp[k_HHWWbb13] +chanESystm[k_HHWWbb13])/2.0;
  chanETot[k_HHWWbb13]  = (chanETotp[k_HHWWbb13] +chanETotm[k_HHWWbb13])/2.0;

// HH production at 13 TeV in the Combination of channels
//
// https://arxiv.org/abs/1811.09689 Submitted to PRL.
// http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-17-030/

chanMeasurement[k_HHComb13]  = "HH"; // def "HH"
if (version == 9) chanMeasurement[k_HHComb13]  = "#splitline{HH}{Comb.}"; // def "HH"


chanLumi[k_HHComb13]  = "35.9 fb^{-1}";
chanTheo[k_HHComb13]   =  33.53 * 0.001 * scale_; // Updated to the latest theory cross-section, https://twiki.cern.ch/twiki/bin/view/LHCPhysics/LHCHXSWGHH                                  
chanETheop[k_HHComb13] =  sqrt(0.060*0.060 + 0.059*0.059)*chanTheo[k_HHComb13]; // adding (in quad.) the Theo. (5%), PDF (2.1%), alpha_S (2.3%) and scale (+4.3%) unc.s together                                                              
chanETheom[k_HHComb13] =  sqrt(0.043*0.043 + 0.059*0.059)*chanTheo[k_HHComb13]; // adding (in quad.) the Theo. (5%), PDF (2.1%), alpha_S (2.3%) and scale (-6.0%) unc.s together                                                              
chanETheo[k_HHComb13]  = (chanETheop[k_HHComb13] +chanETheom[k_HHComb13])/2.0;

//expected 12.8
chanSigma[k_HHComb13]  =   -22.2 * chanTheo[k_HHComb13] * scale_; // HH Comb (HIG-17-030)                                                              

chanEStatp[k_HHComb13]  =  0.0;
chanESystp[k_HHComb13]  =  0.0;
chanETotp[k_HHComb13]   =  0.0;

chanEStatm[k_HHComb13]  =  0.0;
chanESystm[k_HHComb13]  =  0.0;
chanETotm[k_HHComb13]   =  0.0;

chanEStat[k_HHComb13] = (chanEStatp[k_HHComb13] +chanEStatm[k_HHComb13])/2.0;
chanESyst[k_HHComb13] = (chanESystp[k_HHComb13] +chanESystm[k_HHComb13])/2.0;
chanETot[k_HHComb13] = (chanETotp[k_HHComb13] +chanETotm[k_HHComb13])/2.0;



// HH production at 13 TeV in the bbbb channel
//
//http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-20-005/index.html


chanMeasurement[k_HHbbbb13]  = "HH "; // def "HH"
if (version == 9) chanMeasurement[k_HHbbbb13]  = "#splitline{HH}{bbbb}"; // def "HH"
  chanCadi[k_HHbbbb13] = "HIG-20-005";
  chanPreprint[k_HHbbbb13] = "https://cds.cern.ch/record/2771912";
  chanPublication[k_HHbbbb13] = "";



chanLumi[k_HHbbbb13]  = "138 fb^{-1}";
chanTheo[k_HHbbbb13]   =  33.53 * 0.001 * scale_; // Updated to the latest theory cross-section, https://twiki.cern.ch/twiki/bin/view/LHCPhysics/LHCHXSWGHH                                  
chanETheop[k_HHbbbb13] =  sqrt(0.060*0.060 + 0.059*0.059)*chanTheo[k_HHbbbb13]; // adding (in quad.) the Theo. (5%), PDF (2.1%), alpha_S (2.3%) and scale (+4.3%) unc.s together                                                              
chanETheom[k_HHbbbb13] =  sqrt(0.043*0.043 + 0.059*0.059)*chanTheo[k_HHbbbb13]; // adding (in quad.) the Theo. (5%), PDF (2.1%), alpha_S (2.3%) and scale (-6.0%) unc.s together                                                              
chanETheo[k_HHbbbb13]  = (chanETheop[k_HHbbbb13] +chanETheom[k_HHbbbb13])/2.0;

//expected 12.8
chanSigma[k_HHbbbb13]  =   - 3.6 * chanTheo[k_HHbbbb13] * scale_;                                                              

chanEStatp[k_HHbbbb13]  =  0.0;
chanESystp[k_HHbbbb13]  =  0.0;
chanETotp[k_HHbbbb13]   =  0.0;

chanEStatm[k_HHbbbb13]  =  0.0;
chanESystm[k_HHbbbb13]  =  0.0;
chanETotm[k_HHbbbb13]   =  0.0;

chanEStat[k_HHbbbb13] = (chanEStatp[k_HHbbbb13] +chanEStatm[k_HHbbbb13])/2.0;
chanESyst[k_HHbbbb13] = (chanESystp[k_HHbbbb13] +chanESystm[k_HHbbbb13])/2.0;
chanETot[k_HHbbbb13] = (chanETotp[k_HHbbbb13] +chanETotm[k_HHbbbb13])/2.0;





     for( size_t ii=0; ii<k_nChan; ii++ )
	{
	  ostringstream stream1, stream2, stream3, stream4;
stream1.precision(2);
stream2.precision(2);
stream3.precision(2);
 stream1 << fixed;
 stream2 << fixed;
 stream3 << fixed;
stream1<< (chanSigma[ii]/chanTheo[ii]);    // for fixed point notation
stream2<<(chanEStat[ii]/chanTheo[ii]);    // for fixed point notation
stream3<<(chanESyst[ii]/chanTheo[ii]);    // for fixed point notation
chanResult[ii] = stream1.str() + " #pm " + stream2.str() +" #pm " + stream3.str();


   
	}

bool verbose_(true);
if( verbose_ )
  {
    for( size_t ii=0; ii<k_nChan; ii++ )
      {
	if (plotChan[ii]&&!exportExeFormat)
	  {
	    if (subChan[ii]== 1) nPlotBins++;
            nPlotChan++;
	    cout << chanMeasurement[ii] 
		 << " " << chanSigma[ii]
		 << " +/- " << chanEStat[ii] << "(stat)"
		 << " +/- " << chanESyst[ii] << "(syst)"
		 << " +/- " << chanETot[ii] << "(tot)"
		 << " ( " << chanETot[ii]/chanTheo[ii] << ", frac )"
		 << " TH="  << chanTheo[ii] 
		 << " +/- " << chanETheo[ii] 
		 << " ( " << chanETheo[ii]/chanTheo[ii] << ", frac )"
		 << endl;
	  }
      }

    if (exportExeFormat)
      {
	ostringstream stream1, stream2;
	stream1.precision(1);
	stream2.precision(1);
	stream1 << scientific;
	stream2 << scientific;

	
	fstream exeOutput;
        exeOutput.open ("../crossSectionSummaryBarCharts/CrossSectionBarChartInputTable.csv",fstream::out);
        exeOutput << "cadi,pub,paper,lumi,category,name,model,comment,finalstate,crossSection,eTotm,eTotp,eStatm,eStatp,eSystm,eSystp,theoryCrossSection,eTheorym,eTheoryp,flag" << endl;
	for( size_t ii=0; ii<k_nChan; ii++ )
	  {
	    if (plotChan[ii])
	      {
		if (chanLumi[ii]=="") chanLumi[ii] = "0.1 fb^{-1}";
                if (chanCadi[ii]=="") chanCadi[ii]="SMP-00-000";
		if (chanETheop[ii] == 0.0) chanETheop[ii] = chanETheo[ii];
		if (chanETheom[ii] == 0.0) chanETheom[ii] = chanETheo[ii];
                if (chanETotp[ii] == 0.0 || chanETotm[ii] == 0.0)
		  {
 		    chanETotp[ii] = chanETot[ii];
		    chanETotm[ii] = chanETot[ii];
		    
		  }
                if (chanEStatm[ii] == 0 || chanEStatp[ii] == 0)
		  {
		    chanEStatm[ii] = chanEStat[ii];
		    chanEStatp[ii] = chanEStat[ii];
		}
                if (chanESystm[ii] == 0 || chanESystp[ii] == 0)
		  {
		    chanESystm[ii] = chanESyst[ii];
		    chanESystp[ii] = chanESyst[ii];
		}
                if (chanEStatm[ii] == 0 && chanSigma[ii] > 0.0) {
		  cout << "Warning zero stat error for: " << chanMeasurement[ii] << endl;
		  chanEStatm[ii] = chanETotm[ii];
		  chanEStatp[ii] = chanETotp[ii];
		}
                if (chanSigma[ii] < 0.0)
		  {
                    chanSigma[ii] = -chanSigma[ii];
		    chanETotp[ii] = 0.0;
		    chanETotm[ii] = chanSigma[ii];
		    chanEStatp[ii] = 0.0;
		    chanEStatm[ii] = chanSigma[ii];
		    
		  }
                if ((!noJets)&&(chanMeasurement[ii]=="W"||chanMeasurement[ii]=="Z"))  chanFlag[ii] = 2; 
		stream1 << ((chanSigma[ii]-chanETotm[ii])*1000.0);
		chanLumi[ii].erase (chanLumi[ii].end()-8,chanLumi[ii].end());
		exeOutput << chanCadi[ii]
		          << "," << chanPreprint[ii]
		          << "," << chanPublication[ii]
                          << ","  << chanLumi[ii]
			  << "," << chanGroup[ii]
			  << "," << ii
			  << "," << chanMeasurement[ii]
			  << "," << chanEnergy[ii]
	   		  << ",," << chanSigma[ii]*1000.0
                          << "," << chanETotm[ii]*1000.0
			  << "," << chanETotp[ii]*1000.0
                          << "," << chanEStatm[ii]*1000.0
			  << "," << chanEStatp[ii]*1000.0
                          << "," << chanESystm[ii]*1000.0
			  << "," << chanESystp[ii]*1000.0
			  << "," << chanTheo[ii]*1000.0
                          << "," << chanETheom[ii]*1000.0
			  << "," << chanETheop[ii]*1000.
			  << "," << chanFlag[ii]
			  << endl;
	      }
	  }
	exeOutput.close();
        cout << "Finished output csv" << endl;
      }
  }
//if (exportExeFormat) return 1;
