// standard versions 0 with verticle stacking of QCD results ,1 without verticle stacking, 2 QCD EWK only, 3 QCD rad only

enum { k_W=0,  k_W8, k_W13, k_W8n, k_W1jet, k_W2jet, k_W3jet, k_W4jet,  k_W1jetn, k_W1jet8n, k_W1jet13, k_W2jetn, k_W2jet8n, k_W2jet13, k_W3jetn, k_W3jet8n, k_W3jet13, k_W4jetn, k_W4jet8n, k_W4jet13, k_W5jetn, k_W5jet8n, k_W5jet13, k_W6jetn, k_W6jet8n, k_W7jet8n, k_W1cjet, k_W2bjet, k_W2bjet8, k_Z,  k_Z8,  k_Z13, k_Z1jet, k_Z2jet, k_Z3jet, k_Z4jet, k_Z1jetn, k_Z1jet8, k_Z1jet13, k_Z2jetn,  k_Z2jet8, k_Z2jet13, k_Z3jetn, k_Z3jet8, k_Z3jet13, k_Z4jetn,  k_Z4jet8, k_Z4jet13, k_Z5jetn, k_Z5jet8, k_Z6jetn, k_Z6jet8, k_Z7jet8, k_Z1cjet8, k_Z1bjet,k_Z1bjet8, k_Z2bjet, k_Z2bjet8, k_Wp, k_Wm, k_gg, k_ggnew, k_Wg, k_Zg, k_Zg8, k_WV, k_WW, k_WW8, k_WW13, k_WW1jet, k_WZ, k_WZ8, k_WZ0jet8, k_WZ1jet8, k_WZ2jet8, k_WZ3jet8, k_WZ13, k_WZ13fid,  k_ZZ, k_ZZ8,  k_ZZ13,  k_ZZ13fid, k_ZZ0jet13, k_ZZ1jet13, k_ZZ2jet13, k_ZZ3jet13, k_VBFW8, k_VBFZ, k_VBFZ8, k_VBFZ13, k_exWW,  k_exWW8,  k_EWKWg8, k_SSWW8, k_SSWW13, k_EWKZg8, k_EWKZZ13, k_WVg,k_Zgg8, k_Wgg8,  k_tt,  k_tt8, k_tt13, k_tt1jet, k_tt1jet8,  k_tt1jet13, k_tt2jet, k_tt2jet8, k_tt2jet13, k_tt3jet, k_tt3jet8,  k_tt3jet13, k_tt4jet13,  k_t, k_t8, k_t13, k_tW, k_tW8, k_tschan, k_tschan8, k_ttg8,  k_tZq8, k_ttW8, k_ttW13, k_ttZ, k_ttZ8, k_ttZ13, k_tttt8, k_tttt13, k_H0jet13, k_H1jet13, k_H2jet13, k_H3jet13, k_H4jet13, k_HZZ,  k_H1jet, k_ggH, k_ggH8, k_ggHgg13, k_VBFH, k_VBFH8, k_VBFHgg13, k_VBFHtt13, k_VH, k_VH8, k_VH13, k_ttH, k_ttH8, k_ttH13, k_HH8, k_HH13, k_incj, k_incg, k_gj, k_Hgg, k_Hgg8, k_nChan };




// Notes
// 7 and 8 TeV measurements are grouped if the ChanMeasurement short name is the same for both
// To add +jets measurements under the main measurement you need to set subChan to a number greater than 1.

bool big13TeV = false;
bool use13TeV = true;
bool ratioPlot = true;

  float nPlotBins = 0;
  int nPlotChan = 0;
  vector<bool> plotChan( k_nChan, false );
  vector<int>  subChan(k_nChan, 1);
  vector<int>  energy(k_nChan, 8);
  vector<string> 
    chanMeasurement( k_nChan ),
    chanResult (     k_nChan ),
    chanLumi   (     k_nChan );
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

if (version==0||version==1) {

  plotChan[k_W] = true;
  plotChan[k_W8] = true;
  if (use13TeV) plotChan[k_W13] = true;
  if (use13TeV) plotChan[k_Z13] = true;

  plotChan[k_Wp] = false;
  plotChan[k_Wm] = false;
  plotChan[k_W1jet] = true;
  plotChan[k_W2jet] = true;
  plotChan[k_W3jet] = true;
  plotChan[k_W4jet] = true;

  plotChan[k_Z] = true;
  plotChan[k_Z8] = true;
  plotChan[k_Z1jet] = true;
  plotChan[k_Z2jet] = true;
  plotChan[k_Z3jet] = true;
  plotChan[k_Z4jet] = true;



  plotChan[k_gg]=false;
  plotChan[k_Wg]=true;
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
  plotChan[k_Wgg8]=true;
  plotChan[k_Zgg8]=true;

  plotChan[k_exWW]=true;
  plotChan[k_exWW8]=true;

  plotChan[k_SSWW8]=true;
  plotChan[k_SSWW13]=true;
  plotChan[k_EWKWg8]=true;
  plotChan[k_EWKZg8]=true;
  plotChan[k_EWKZZ13]=true;

  


  plotChan[k_VBFZ]=true;
  plotChan[k_VBFZ8]=true;
  plotChan[k_VBFZ13]=true;
  plotChan[k_VBFW8]=true;

  
  plotChan[k_tt]=true;
  plotChan[k_tt8]=true;
  if (use13TeV) plotChan[k_tt13]=true;
  plotChan[k_tt1jet] = true;
  plotChan[k_tt2jet] = true;
  plotChan[k_tt3jet] = true;
  plotChan[k_tt1jet8] = true;
  plotChan[k_tt2jet8] = true;
  plotChan[k_tt3jet8] = true;
  plotChan[k_tt1jet13] = true;
  plotChan[k_tt2jet13] = true;
  plotChan[k_tt3jet13] = true;
  plotChan[k_tt4jet13] = true;


  

  
  plotChan[k_t]=true;
  plotChan[k_t8]=true;
  if (use13TeV) plotChan[k_t13]=true;
  plotChan[k_tschan]=true;
  plotChan[k_tschan8]=true;
  plotChan[k_tW]=true;
  plotChan[k_tW8]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_ttW8]=true;
  plotChan[k_ttZ]=true;
  plotChan[k_ttZ8]=true;
  if (use13TeV)  plotChan[k_ttZ13]=true;
  if (use13TeV)  plotChan[k_ttW13]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_tZq8]=true;
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
  plotChan[k_ttH8]=true;
  plotChan[k_ttH13]=true;
  plotChan[k_HH8]=true;
  plotChan[k_HH13]=true;

  
  plotChan[k_ggHgg13]=true;

  plotChan[k_VBFHgg13]=false;
  plotChan[k_VBFHtt13]=true;

  
  plotChan[k_HZZ]=false;

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
  plotChan[k_Wgg8]=true;
  plotChan[k_Zgg8]=true;

  plotChan[k_exWW]=true;
  plotChan[k_exWW8]=true;

  plotChan[k_SSWW8]=true;
  plotChan[k_SSWW13]=true;
  plotChan[k_EWKWg8]=true;
  plotChan[k_EWKZg8]=true;
  plotChan[k_EWKZZ13]=true;


  plotChan[k_VBFZ]=true;
  plotChan[k_VBFZ8]=true;
  plotChan[k_VBFZ13]=true;
  plotChan[k_VBFW8]=true;

  plotChan[k_tt]=true;
  plotChan[k_tt8]=true;
  if (use13TeV) plotChan[k_tt13]=true;
  //plotChan[k_tt1jet] = true;
  //plotChan[k_tt2jet] = true;
  //plotChan[k_tt3jet] = true;
  //plotChan[k_tt1jet8] = true;
  //plotChan[k_tt2jet8] = true;
  //plotChan[k_tt3jet8] = true;
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
  plotChan[k_ttg8]=true;
  plotChan[k_ttW8]=true;
  plotChan[k_ttZ]=true;
  plotChan[k_ttZ8]=true;
  if (use13TeV)  plotChan[k_ttZ13]=true;
  if (use13TeV)  plotChan[k_ttW13]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_tZq8]=true;
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
  plotChan[k_ttH8]=true;
  plotChan[k_ttH13]=true;
  plotChan[k_HH8]=true;
  plotChan[k_HH13]=true;


  plotChan[k_ggHgg13]=true;

  plotChan[k_VBFHgg13]=false;
  plotChan[k_VBFHtt13]=true;


  plotChan[k_HZZ]=false;

 }

if (version==3) {

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
  plotChan[k_W7jet8n] = true;

  plotChan[k_W1jet13] = true;
  plotChan[k_W2jet13] = true;
  plotChan[k_W3jet13] = true;
  plotChan[k_W4jet13] = true;
  plotChan[k_W5jet13] = true;

  
  plotChan[k_W1cjet] = true;
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
  //plotChan[k_Z5jet13] = false;
  //plotChan[k_Z6jet13] = false;

  
  plotChan[k_Z1cjet8] = true;

  plotChan[k_Z1bjet] = true;
  plotChan[k_Z2bjet] = true;
  plotChan[k_Z1bjet8] = true;
  plotChan[k_Z2bjet8] = true;

  plotChan[k_WZ0jet8] = true;
  plotChan[k_WZ1jet8] = true;
  plotChan[k_WZ2jet8] = true;
  plotChan[k_WZ3jet8] = true;

  
  plotChan[k_ZZ0jet13] = true;
  plotChan[k_ZZ1jet13] = true;
  plotChan[k_ZZ2jet13] = true;
  plotChan[k_ZZ3jet13] = true;


  
  plotChan[k_gg]=false;
  plotChan[k_Wg]=false;
  plotChan[k_Zg]=false;
  plotChan[k_Zg8]=false;
  plotChan[k_WV]=false;
  plotChan[k_WW]=false;
  plotChan[k_WW8]=false;
  plotChan[k_WW13]=false;
  plotChan[k_WZ]=false;
  plotChan[k_WZ8]=false;
  if (use13TeV) plotChan[k_WZ13]=false;
  plotChan[k_ZZ]=false;
  plotChan[k_ZZ8]=false;
  if (use13TeV) plotChan[k_ZZ13]=false;


  plotChan[k_tt]=true;
  plotChan[k_tt8]=true;
  if (use13TeV) plotChan[k_tt13]=true;
  plotChan[k_tt1jet] = true;
  plotChan[k_tt2jet] = true;
  plotChan[k_tt3jet] = true;
  plotChan[k_tt1jet8] = true;
  plotChan[k_tt2jet8] = true;
  plotChan[k_tt3jet8] = true;
  plotChan[k_tt1jet13] = true;
  plotChan[k_tt2jet13] = true;
  plotChan[k_tt3jet13] = true;
  plotChan[k_tt4jet13] = true;


  plotChan[k_H0jet13] = true;
  plotChan[k_H1jet13] = true;
  plotChan[k_H2jet13] = true;
  plotChan[k_H3jet13] = true;
  plotChan[k_H4jet13] = true;
 
 
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




  subChan[k_tt1jet] = 10;
  subChan[k_tt2jet] = 10;
  subChan[k_tt3jet] = 10;
 
  subChan[k_tt1jet8] = 10;
  subChan[k_tt2jet8] = 10;
  subChan[k_tt3jet8] = 10;

  subChan[k_tt1jet13] = 10;
  subChan[k_tt2jet13] = 10;
  subChan[k_tt3jet13] = 10;
  subChan[k_tt4jet13] = 10;

  
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
  plotChan[k_tt1jet] = true;
  plotChan[k_tt2jet] = true;
  plotChan[k_tt3jet] = true;
  plotChan[k_tt1jet8] = true;
  plotChan[k_tt2jet8] = true;
  plotChan[k_tt3jet8] = true;
  plotChan[k_tt1jet13] = true;
  plotChan[k_tt2jet13] = true;
  plotChan[k_tt3jet13] = true;
  plotChan[k_tt4jet13] = true;
 
  plotChan[k_t]=true;
  plotChan[k_t8]=true;
  if (use13TeV) plotChan[k_t13]=true;
  plotChan[k_tschan]=true;
  plotChan[k_tschan8]=true;
  plotChan[k_tW]=true;
  plotChan[k_tW8]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_ttW8]=true;
  plotChan[k_ttZ]=true;
  plotChan[k_ttZ8]=true;
  if (use13TeV)  plotChan[k_ttZ13]=true;
  if (use13TeV)  plotChan[k_ttW13]=true;
  plotChan[k_ttg8]=true;
  plotChan[k_tZq8]=true;
  plotChan[k_tttt8]=true;
  if (use13TeV)  plotChan[k_tttt13]=true;
  
  plotChan[k_ttH]=true;
  plotChan[k_ttH8]=true;
  plotChan[k_ttH13]=true;


 }



// Ratio plot for dibosons
if (version==5) {

  plotChan[k_ggnew]=true;
  plotChan[k_Wg]=true;
  plotChan[k_Zg]=true;
  plotChan[k_Zg8]=true;
  plotChan[k_WV]=true;
  plotChan[k_WW]=true;
  plotChan[k_WW8]=true;
  plotChan[k_WW13]=true;
  plotChan[k_WZ]=true;
  plotChan[k_WZ8]=true;
  plotChan[k_WZ13fid]=true;
  if (use13TeV) plotChan[k_WZ13]=false;
  plotChan[k_ZZ]=true;
  plotChan[k_ZZ8]=true;
  plotChan[k_ZZ13fid]=true;
  if (use13TeV) plotChan[k_ZZ13]=false;



  
 }

// EWK scattering measurements
if (version==6) {

  plotChan[k_VBFW8]=true;
  plotChan[k_VBFZ]=true;
  plotChan[k_VBFZ8]=true;
  plotChan[k_VBFZ13]=true;
  plotChan[k_exWW]=true;
  plotChan[k_exWW8]=true;
  plotChan[k_SSWW8]=true;
  plotChan[k_SSWW13]=true;
  plotChan[k_EWKWg8]=true;
  plotChan[k_EWKZg8]=true;
  plotChan[k_EWKZZ13]=true;

  //plotChan[k_Wgg8]=true;
  //plotChan[k_Zgg8]=true;


}

// EWK scattering measurements
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

// W 8 TeV PRL 18.2 pb http://arxiv.org/abs/arXiv:1402.0923
  chanMeasurement[k_W8]    = "W";
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
// https://arxiv.org/abs/1610.04222 submitted to PRD !!!!! update theor errors
// Errors from private communication Apichart Hortiangtham <apichart.hortiangtham@cern.ch>
// Blackhat, 1-4, aMC@NLO 5,6

// new W + jet8ns 1 jet8ns  8 TeV


  chanMeasurement[k_W1jet8n] = "#geq1j";
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

// W + 1 jet, 13 TeV

  chanMeasurement[k_W1jet13] = "#geq1j";
  scale_ = 1.0;

  chanSigma[k_W1jet13]  = 1174.586 * scale_;
  chanETot[k_W1jet13]   =   92.98112 * scale_;

  chanTheo[k_W1jet13]  =  1143.682  * scale_;
  chanETheo[k_W1jet13] =  70.91719  * scale_;


// W + 2 jet, 13 TeV

  chanMeasurement[k_W2jet13] = "#geq2j";
  scale_ = 1.0;

  chanSigma[k_W2jet13]  = 272.9656 * scale_;
  chanETot[k_W2jet13]   = 27.02376 * scale_;

  chanTheo[k_W2jet13]  =  252.5099 * scale_;
  chanETheo[k_W2jet13] =  22.48097 * scale_;

// W + 3 jet, 13 TeV

  chanMeasurement[k_W3jet13] = "#geq3j";
  scale_ = 1.0;

  chanSigma[k_W3jet13]  = 60.01153 * scale_;
  chanETot[k_W3jet13]   = 8.597333 * scale_;

  chanTheo[k_W3jet13]  =  52.98282 * scale_;
  chanETheo[k_W3jet13] =  6.257502 * scale_;

// W + 4 jet, 13 TeV

  chanMeasurement[k_W4jet13] = "#geq4j";
  scale_ = 1.0;

  chanSigma[k_W4jet13]  = 14.43908 * scale_;
  chanETot[k_W4jet13]   = 3.05119 * scale_;

  chanTheo[k_W4jet13]  =  10.49583 * scale_;
  chanETheo[k_W4jet13] =  1.254644 * scale_;

// W + 5 jet, 13 TeV

  chanMeasurement[k_W5jet13] = "#geq5j";
  scale_ = 1.0;

  chanSigma[k_W5jet13]  =  3.544719 * scale_;
  chanETot[k_W5jet13]   =  1.129439 * scale_;

  chanTheo[k_W5jet13]  =   2.181414 * scale_;
  chanETheo[k_W5jet13] =   0.3425573 * scale_;




// W + 1 c jet 7  TeV
// From http://arxiv.org/abs/1310.1138 JHEP 02 (2014) 013
  chanMeasurement[k_W1cjet] = "1c";

  chanSigma[k_W1cjet]  = 107.7 * scale_;
  chanEStat[k_W1cjet]  = 3.3 * scale_;
  chanESyst[k_W1cjet]   = 6.9 * scale_;
  chanETot[k_W1cjet]  =  sqrt( chanESyst[k_W1cjet]*chanESyst[k_W1cjet] 
			       + 
			       chanEStat[k_W1cjet]*chanEStat[k_W1cjet]
			       );
  chanTheo[k_W1cjet]  = 109.9 * scale_;
chanETheo[k_W1cjet] = 6.4 * scale_;

// W + 2 b jet 7  TeV
// From http://arxiv.org/abs/1312.6608 submitted to PLB
  chanMeasurement[k_W2bjet] = "2b";

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
// From http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-14-020/index.html
  chanMeasurement[k_W2bjet8] = "2b";

  chanSigma[k_W2bjet8]  = 0.69 * scale_;
  chanEStat[k_W2bjet8]  = 0.02 * scale_;
chanESyst[k_W2bjet8]   = sqrt(0.11*0.11 + 0.07*0.07 + 0.02*0.02) * scale_;
  chanETot[k_W2bjet8]  =  sqrt( chanESyst[k_W2bjet8]*chanESyst[k_W2bjet8] 
			       + 
			       chanEStat[k_W2bjet8]*chanEStat[k_W2bjet8]
			       );
  chanTheo[k_W2bjet8]  = 0.51 * scale_;
chanETheo[k_W2bjet8] = sqrt(0.02*0.02 + 0.06*0.06) * scale_;




// Z + jets 1 jet new!!!!! update reference to http://arxiv.org/abs/1408.3104
// As an estimate NLO uncerainties from http://arxiv.org/abs/1108.2229v2 are used

  chanMeasurement[k_Z1jet] = "#geq1j";
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
    // Private communication from Fengwangdong Zhang <fengwdz@gmail.com>, Philippe Gras <philippe.gras@cern.ch>

// 1 jet exclusive
  chanMeasurement[k_Z1jet13] = "#geq1j";

  chanSigma[k_Z1jet13]  = 98.1 * scale_;
  chanEStat[k_Z1jet13]  =   0.0 * chanSigma[k_Z1jet13] * scale_;
  chanETot[k_Z1jet13]   =   6.7 * scale_;
  chanESyst[k_Z1jet13]  =  sqrt( chanETot[k_Z1jet13]*chanETot[k_Z1jet13] 
			       - 
			       chanEStat[k_Z1jet13]*chanEStat[k_Z1jet13]
			       );
  chanTheo[k_Z1jet13]  = 105.5 * scale_;
  chanETheo[k_Z1jet13] =  0.5* scale_;

// 2 jet exclusive
  chanMeasurement[k_Z2jet13] = "#geq2j";
  scale_ = 1.0;

  chanSigma[k_Z2jet13]  = 21.8 * scale_;
  chanEStat[k_Z2jet13]  =   0.0 * chanSigma[k_Z2jet13] * scale_;
  chanETot[k_Z2jet13]   =   2.0  * scale_;
  chanESyst[k_Z2jet13]  =  sqrt( chanETot[k_Z2jet13]*chanETot[k_Z2jet13] 
			       - 
			       chanEStat[k_Z2jet13]*chanEStat[k_Z2jet13]
			       );
  chanTheo[k_Z2jet13]  = 23.9 * scale_;
  chanETheo[k_Z2jet13] =  0.3* scale_;



// 3 jet exclusive
  chanMeasurement[k_Z3jet13] = "#geq3j";
  scale_ = 1.0;

  chanSigma[k_Z3jet13]  = 4.58 * scale_;
  chanEStat[k_Z3jet13]  =   0.0 * chanSigma[k_Z3jet13] * scale_;
  chanETot[k_Z3jet13]   =   0.60 * scale_;
  chanESyst[k_Z3jet13]  =  sqrt( chanETot[k_Z3jet13]*chanETot[k_Z3jet13] 
			       - 
			       chanEStat[k_Z3jet13]*chanEStat[k_Z3jet13]
			       );
  chanTheo[k_Z3jet13]  = 5.04 * scale_;
  chanETheo[k_Z3jet13] =  0.11* scale_;

// 4 jet exclusive
  chanMeasurement[k_Z4jet13] = "#geq4j";
  scale_ = 1.0;

  chanSigma[k_Z4jet13]  = 1.00 * scale_;
  chanEStat[k_Z4jet13]  =   0.0 * chanSigma[k_Z4jet13] * scale_;
  chanETot[k_Z4jet13]   =   0.16  * scale_;
  chanESyst[k_Z4jet13]  =  sqrt( chanETot[k_Z4jet13]*chanETot[k_Z4jet13] 
			       - 
			       chanEStat[k_Z4jet13]*chanEStat[k_Z4jet13]
			       );
  chanTheo[k_Z4jet13]  = 0.99 * scale_;
  chanETheo[k_Z4jet13] =  0.05* scale_;


// inclusize result without theoretical uncerainties    
// 1 jet inclusize
  chanMeasurement[k_Z1jet13] = "#geq1j";

  chanSigma[k_Z1jet13]  = 126 * scale_;
  chanEStat[k_Z1jet13]  =   0.0 * chanSigma[k_Z1jet13] * scale_;
  chanETot[k_Z1jet13]   =   0.055 * chanSigma[k_Z1jet13] * scale_;
  chanESyst[k_Z1jet13]  =  sqrt( chanETot[k_Z1jet13]*chanETot[k_Z1jet13] 
			       - 
			       chanEStat[k_Z1jet13]*chanEStat[k_Z1jet13]
			       );
  chanTheo[k_Z1jet13]  = 126. * scale_;
  chanETheo[k_Z1jet13] =  0.5* scale_;
 

// 2 jet inclusize
  chanMeasurement[k_Z2jet13] = "#geq2j";
  scale_ = 1.0;

  chanSigma[k_Z2jet13]  = 27.7 * scale_;
  chanEStat[k_Z2jet13]  =   0.0 * chanSigma[k_Z2jet13] * scale_;
  chanETot[k_Z2jet13]   =   0.076 * chanSigma[k_Z2jet13] * scale_;
  chanESyst[k_Z2jet13]  =  sqrt( chanETot[k_Z2jet13]*chanETot[k_Z2jet13] 
			       - 
			       chanEStat[k_Z2jet13]*chanEStat[k_Z2jet13]
			       );
  chanTheo[k_Z2jet13]  = 27.7 * scale_;
  chanETheo[k_Z2jet13] =  0.3 * scale_;



// 3 jet inclusize
  chanMeasurement[k_Z3jet13] = "#geq3j";
  scale_ = 1.0;

  chanSigma[k_Z3jet13]  = 5.91 * scale_;
  chanEStat[k_Z3jet13]  =   0.0 * chanSigma[k_Z3jet13] * scale_;
  chanETot[k_Z3jet13]   =   0.10 * chanSigma[k_Z3jet13] * scale_;
  chanESyst[k_Z3jet13]  =  sqrt( chanETot[k_Z3jet13]*chanETot[k_Z3jet13] 
			       - 
			       chanEStat[k_Z3jet13]*chanEStat[k_Z3jet13]
			       );
  chanTheo[k_Z3jet13]  = 5.91 * scale_;
  chanETheo[k_Z3jet13] =  0.11* scale_;

// 4 jet inclusize
  chanMeasurement[k_Z4jet13] = "#geq4j";
  scale_ = 1.0;

  chanSigma[k_Z4jet13]  = 1.34 * scale_;
  chanEStat[k_Z4jet13]  =   0.0 * chanSigma[k_Z4jet13] * scale_;
  chanETot[k_Z4jet13]   =   0.13 * chanSigma[k_Z4jet13] * scale_;
  chanESyst[k_Z4jet13]  =  sqrt( chanETot[k_Z4jet13]*chanETot[k_Z4jet13] 
			       - 
			       chanEStat[k_Z4jet13]*chanEStat[k_Z4jet13]
			       );
  chanTheo[k_Z4jet13]  = 1.34 * scale_;
  chanETheo[k_Z4jet13] =  0.05* scale_;

// // 5 jet inclusize, not yet public
//   chanMeasurement[k_Z5jet13] = "#geq5j";
//   scale_ = 1.0;

//   chanSigma[k_Z5jet13]  = 0.334 * scale_;
//   chanEStat[k_Z5jet13]  =   0.0 * chanSigma[k_Z5jet13] * scale_;
//   chanETot[k_Z5jet13]   =   0.20 * chanSigma[k_Z5jet13] * scale_;
//   chanESyst[k_Z5jet13]  =  sqrt( chanETot[k_Z5jet13]*chanETot[k_Z5jet13] 
// 			       - 
// 			       chanEStat[k_Z5jet13]*chanEStat[k_Z5jet13]
// 			       );
//   chanTheo[k_Z5jet13]  = 0.334 * scale_;
//   chanETheo[k_Z5jet13] =  0.01* scale_;

// // 6 jet inclusize
//   chanMeasurement[k_Z6jet13] = "#geq6j";
//   scale_ = 1.0;

//   chanSigma[k_Z6jet13]  = 0.0733 * scale_;
//   chanEStat[k_Z6jet13]  =   0.0 * chanSigma[k_Z6jet13] * scale_;
//   chanETot[k_Z6jet13]   =   0.40 * chanSigma[k_Z6jet13] * scale_;
//   chanESyst[k_Z6jet13]  =  sqrt( chanETot[k_Z6jet13]*chanETot[k_Z6jet13] 
// 			       - 
// 			       chanEStat[k_Z6jet13]*chanEStat[k_Z6jet13]
// 			       );
//   chanTheo[k_Z6jet13]  = 0.0733 * scale_;
//   chanETheo[k_Z6jet13] =  0.0025* scale_;

// Z + 2 c jet 8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-15-009/index.html
// https://cds.cern.ch/record/2202823
  chanMeasurement[k_Z1cjet8] = "1c";

chanSigma[k_Z1cjet8]  = 8.6 * scale_;
  chanEStat[k_Z1cjet8]  =   0.5 * scale_;
  chanESyst[k_Z1cjet8]   =  0.7 * scale_;
  chanETot[k_Z1cjet8]  =  sqrt( chanESyst[k_Z1cjet8]*chanESyst[k_Z1cjet8] 
			       + 
			       chanEStat[k_Z1cjet8]*chanEStat[k_Z1cjet8]
			       );
  chanTheo[k_Z1cjet8]  = 9.47 * scale_;
chanETheo[k_Z1cjet8] = sqrt(0.15*0.015 + 0.50*0.50) * scale_;
// PDF + scale

// new Z + 1 b jet  7  TeV
// From http://arxiv.org/abs/1402.1521, submitted to JHEP
  chanMeasurement[k_Z1bjet] = "#geq1b";

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
// From  http://arxiv.org/abs/1611.06507 Submitted to Eur. Phys. J. C 
  chanMeasurement[k_Z1bjet8] = "#geq1b";

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

// a MC@NL0 5 flavor


scale_ = 1.;

// VBF Z production, EWK Z produciton to ll
// http://cms-results.web.cern.ch/cms-results/public-results/publications/FSQ-12-019/index.html
// https://arxiv.org/abs/1305.7389  	JHEP 10 (2013) 101
 chanMeasurement[k_VBFZ]     = "#splitline{EW}{qqZ}";
if (version == 6) chanMeasurement[k_VBFZ]     = "#splitline{EWK qq(Z)}{(Z) #rightarrow ll}";
if (ratioPlot) chanMeasurement[k_VBFZ]     = "qqZ";

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
 chanMeasurement[k_VBFZ8]     = "#splitline{EW}{qqZ}";
if (version == 6) chanMeasurement[k_VBFZ8]     = "#splitline{EWK qq(Z)}{(Z) #rightarrow ll}";
if (ratioPlot) chanMeasurement[k_VBFZ8]     = "qqZ";

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
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-16-018/index.html


 chanMeasurement[k_VBFZ13]     = "#splitline{EW}{qqZ}";
if (version == 6) chanMeasurement[k_VBFZ13]     = "#splitline{EWK qq(Z)}{(Z) #rightarrow ll}";
if (ratioPlot) chanMeasurement[k_VBFZ13]     = "qqZ";


  chanSigma[k_VBFZ13]  =   0.552 * scale_; 
  chanEStatp[k_VBFZ13]  =   0.019 * scale_;
  chanESystp[k_VBFZ13]  =   0.055 * scale_;
  chanETotp[k_VBFZ13]   =  sqrt( 
			   chanEStatp[k_VBFZ13]*chanEStatp[k_VBFZ13]
			   +
			   chanESystp[k_VBFZ13]*chanESystp[k_VBFZ13]
			    );

  chanEStatm[k_VBFZ13]  =   0.019 * scale_;
  chanESystm[k_VBFZ13]  =   0.055 * scale_;
  chanETotm[k_VBFZ13]   =  sqrt( 
			   chanEStatm[k_VBFZ13]*chanEStatm[k_VBFZ13]
			   +
			   chanESystm[k_VBFZ13]*chanESystm[k_VBFZ13]
			    );
  chanEStat[k_VBFZ13] = (chanEStatp[k_VBFZ13] +chanEStatm[k_VBFZ13])/2.0;
  chanESyst[k_VBFZ13] = (chanESystp[k_VBFZ13] +chanESystm[k_VBFZ13])/2.0;
  chanETot[k_VBFZ13] = (chanETotp[k_VBFZ13] +chanETotm[k_VBFZ13])/2.0;
 


  chanTheo[k_VBFZ13] =   0.543 * scale_;
  chanETheop[k_VBFZ13] =  0.024 * scale_;
  chanETheom[k_VBFZ13] =  0.024 * scale_;
  chanETheo[k_VBFZ13] = (chanETheop[k_VBFZ13] +chanETheom[k_VBFZ13])/2.0;



// EWK W 8 TeV 19.3 fb-1
//  new!!!!!
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-13-012/index.html
// https://arxiv.org/abs/1607.06975  	JHEP 11 (2016) 147

 chanMeasurement[k_VBFW8]     = "#splitline{EW}{qqW}";
if (version == 6) chanMeasurement[k_VBFW8]     = "#splitline{EWK qqW}{W #rightarrow l#nu}";
if (ratioPlot) chanMeasurement[k_VBFW8]     = "qqW";


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
  chanLumi[k_tt] = "";

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
  chanLumi[k_tt8] = "";

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

  if (use13TeV) chanMeasurement[k_tt13] = "tt";
if (big13TeV) chanMeasurement[k_tt13]    =  "#splitline{   tt}{13Tev}";
  chanLumi[k_tt13] = "";

  chanSigma[k_tt13]  =   792.0 * scale_; 
  chanEStatp[k_tt13]  =   8.0 * scale_;
chanESystp[k_tt13]  =   sqrt(37.0*37.0 + 21.0*21.0) * scale_;
  chanETotp[k_tt13]   =  sqrt( 
			   chanEStatp[k_tt13]*chanEStatp[k_tt13]
			   +
			   chanESystp[k_tt13]*chanESystp[k_tt13]
			    );

  chanEStatm[k_tt13]  =   8.0 * scale_;
  chanESystm[k_tt13]  =    sqrt(38.0*38.0 + 21.0*21.0) * scale_;
  chanETotm[k_tt13]   =  sqrt( 
			   chanEStatm[k_tt13]*chanEStatm[k_tt13]
			   +
			   chanESystm[k_tt13]*chanESystm[k_tt13]
			    );
  chanEStat[k_tt13] = (chanEStatp[k_tt13] +chanEStatm[k_tt13])/2.0;
  chanESyst[k_tt13] = (chanESystp[k_tt13] +chanESystm[k_tt13])/2.0;
  chanETot[k_tt13] = (chanETotp[k_tt13] +chanETotm[k_tt13])/2.0;
 


  chanTheo[k_tt13] =   832.0 * scale_;
chanETheop[k_tt13] =  sqrt(20.0*20.0 + 35.0*35.0) * scale_;
  chanETheom[k_tt13] = sqrt(29.0*29.0 + 35.0*35.0) * scale_;
  chanETheo[k_tt13] = (chanETheop[k_tt13] +chanETheom[k_tt13])/2.0;


// top with jets
// https://arxiv.org/abs/1208.2671
// JHEP 11 (2012) 067
// !!!!!????? to be replaced http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-12-018/index.html\
// Eur. Phys. J. C 74 (2014) 3014
// No publically avaliable nubmers

// tt + 1 jet
  chanMeasurement[k_tt1jet] = "1j";

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

  chanMeasurement[k_tt1jet8] = "1j";

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
// New results in http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-16-007/index.html
// https://arxiv.org/abs/1610.04191 Submitted to Phys. Rev. D
// Requested thoery numbers from otto.heinz.hindrichs@cern.ch


  chanMeasurement[k_tt1jet13] = "1j";

  chanSigma[k_tt1jet13]  =   74 * scale_; 
  chanEStatp[k_tt1jet13]  =   2 * scale_;
  chanESystp[k_tt1jet13]  =   10 * scale_;
  chanETotp[k_tt1jet13]   =  sqrt( 
			   chanEStatp[k_tt1jet13]*chanEStatp[k_tt1jet13]
			   +
			   chanESystp[k_tt1jet13]*chanESystp[k_tt1jet13]
			    );

  chanEStatm[k_tt1jet13]  =   2 * scale_;
  chanESystm[k_tt1jet13]  =   10 * scale_;
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

  chanSigma[k_tt2jet13]  =   35.1 * scale_; 
  chanEStatp[k_tt2jet13]  =   1.0 * scale_;
  chanESystp[k_tt2jet13]  =   5.7 * scale_;
  chanETotp[k_tt2jet13]   =  sqrt( 
			   chanEStatp[k_tt2jet13]*chanEStatp[k_tt2jet13]
			   +
			   chanESystp[k_tt2jet13]*chanESystp[k_tt2jet13]
			    );

  chanEStatm[k_tt2jet13]  =   1.0 * scale_;
  chanESystm[k_tt2jet13]  =   5.7 * scale_;
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

  chanSigma[k_tt3jet13]  =   12.3 * scale_; 
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

  chanSigma[k_tt4jet13]  =   5.8 * scale_; 
  chanEStatp[k_tt4jet13]  =   0.2 * scale_;
  chanESystp[k_tt4jet13]  =   2.0 * scale_;
  chanETotp[k_tt4jet13]   =  sqrt( 
			   chanEStatp[k_tt4jet13]*chanEStatp[k_tt4jet13]
			   +
			   chanESystp[k_tt4jet13]*chanESystp[k_tt4jet13]
			    );

  chanEStatm[k_tt4jet13]  =   0.2 * scale_;
  chanESystm[k_tt4jet13]  =   2.0 * scale_;
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


// single top t chan only
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-11-021/index.html
// https://arxiv.org/abs/1209.4533, JHEP 12 (2012) 035
  chanLumi[k_t] = "";
  chanMeasurement[k_t] = "t_{t-ch}";

  chanSigma[k_t]  =   67.2 * scale_; 
  chanEStatp[k_t]  =   6.1 * scale_;
  chanESystp[k_t]  =   0.0 * scale_;
  chanETotp[k_t]   =  sqrt( 
			   chanEStatp[k_t]*chanEStatp[k_t]
			   +
			   chanESystp[k_t]*chanESystp[k_t]
			    );

  chanEStatm[k_t]  =   6.1 * scale_;
  chanESystm[k_t]  =   0.0 * scale_;
  chanETotm[k_t]   =  sqrt( 
			   chanEStatm[k_t]*chanEStatm[k_t]
			   +
			   chanESystm[k_t]*chanESystm[k_t]
			    );
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
  chanLumi[k_t8] = "";

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
// https://arxiv.org/abs/1610.00678, Submitted to Phys. Lett. B
  if (use13TeV) chanMeasurement[k_t13] = "t_{t-ch}";
if (big13TeV) chanMeasurement[k_t13]    =  "#splitline{  t_{t-ch}}{13Tev}";
  chanLumi[k_t13] = "";

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



// single top s chan only, 8 TeV
// https://cds.cern.ch/record/1633190/ CMS-PAS-TOP-13-009
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-13-009/index.html
// http://arxiv.org/abs/1603.02555 J. High Energy Phys. 09 (2016) 027. 

  chanLumi[k_tschan] = "";
  chanMeasurement[k_tschan] = "t_{s-ch}";

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



  chanLumi[k_tschan8] = "";
  chanMeasurement[k_tschan8] = "t_{s-ch}";

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
  chanLumi[k_tW] = "";

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
  chanLumi[k_tW8] = "";

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



// ttg8amma, CMS TOP-13-011
// Replace with TOP-14-008, http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-14-008/index.html ?????

  chanMeasurement[k_ttg8] = "tt#gamma";
  chanLumi[k_ttg8] = "";

  chanSigma[k_ttg8]  =   2.4 * scale_; 
  chanEStatp[k_ttg8]  =   0.6 * scale_;
  chanESystp[k_ttg8]  =   0.0 * scale_;
  chanETotp[k_ttg8]   =  sqrt( 
			   chanEStatp[k_ttg8]*chanEStatp[k_ttg8]
			   +
			   chanESystp[k_ttg8]*chanESystp[k_ttg8]
			    );

  chanEStatm[k_ttg8]  =   0.6 * scale_;
  chanESystm[k_ttg8]  =   0.0 * scale_;
  chanETotm[k_ttg8]   =  sqrt( 
			   chanEStatm[k_ttg8]*chanEStatm[k_ttg8]
			   +
			   chanESystm[k_ttg8]*chanESystm[k_ttg8]
			    );
  chanEStat[k_ttg8] = (chanEStatp[k_ttg8] +chanEStatm[k_ttg8])/2.0;
  chanESyst[k_ttg8] = (chanESystp[k_ttg8] +chanESystm[k_ttg8])/2.0;
  chanETot[k_ttg8] = (chanETotp[k_ttg8] +chanETotm[k_ttg8])/2.0;
 


  chanTheo[k_ttg8] =   1.8 * scale_;
  chanETheop[k_ttg8] =  0.5 * scale_;
  chanETheom[k_ttg8] =  0.5 * scale_;
  chanETheo[k_ttg8] = (chanETheop[k_ttg8] +chanETheom[k_ttg8])/2.0;





// ttW8, W only CMS PAS TOP 14 021
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-14-021/index.html
// https://arxiv.org/abs/1510.01131, JHEP 01 (2016) 096
  chanMeasurement[k_ttW8] = "ttW";
  chanLumi[k_ttW8] = "";

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
  chanLumi[k_ttZ] = "";

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
   chanLumi[k_ttZ8] = "";


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


// ttZ 13 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-16-017/index.html
// Update to: 

chanMeasurement[k_ttW13] = "ttW";
   chanLumi[k_ttW13] = "12.9";


  chanSigma[k_ttW13]  =   0.98 * scale_; 
  chanEStatp[k_ttW13]  =   0.23 * scale_;
  chanESystp[k_ttW13]  =   0.22 * scale_;
  chanETotp[k_ttW13]   =  sqrt( 
			   chanEStatp[k_ttW13]*chanEStatp[k_ttW13]
			   +
			   chanESystp[k_ttW13]*chanESystp[k_ttW13]
			    );

  chanEStatm[k_ttW13]  =   0.22 * scale_;
  chanESystm[k_ttW13]  =   0.18 * scale_;
  chanETotm[k_ttW13]   =  sqrt( 
			   chanEStatm[k_ttW13]*chanEStatm[k_ttW13]
			   +
			   chanESystm[k_ttW13]*chanESystm[k_ttW13]
			    );
  chanEStat[k_ttW13] = (chanEStatp[k_ttW13] +chanEStatm[k_ttW13])/2.0;
  chanESyst[k_ttW13] = (chanESystp[k_ttW13] +chanESystm[k_ttW13])/2.0;
  chanETot[k_ttW13] = (chanETotp[k_ttW13] +chanETotm[k_ttW13])/2.0;
 
chanMeasurement[k_ttW13] = "ttW";
   chanLumi[k_ttW13] = "36";


  chanSigma[k_ttW13]  =   0.80 * scale_; 
  chanEStatp[k_ttW13]  =   0.12 * scale_;
  chanESystp[k_ttW13]  =   0.13 * scale_;
  chanETotp[k_ttW13]   =  sqrt( 
			   chanEStatp[k_ttW13]*chanEStatp[k_ttW13]
			   +
			   chanESystp[k_ttW13]*chanESystp[k_ttW13]
			    );

  chanEStatm[k_ttW13]  =   0.11 * scale_;
  chanESystm[k_ttW13]  =   0.12 * scale_;
  chanETotm[k_ttW13]   =  sqrt( 
			   chanEStatm[k_ttW13]*chanEStatm[k_ttW13]
			   +
			   chanESystm[k_ttW13]*chanESystm[k_ttW13]
			    );
  chanEStat[k_ttW13] = (chanEStatp[k_ttW13] +chanEStatm[k_ttW13])/2.0;
  chanESyst[k_ttW13] = (chanESystp[k_ttW13] +chanESystm[k_ttW13])/2.0;
  chanETot[k_ttW13] = (chanETotp[k_ttW13] +chanETotm[k_ttW13])/2.0;
 


  chanTheo[k_ttW13] =   0.611 * scale_;
  chanETheop[k_ttW13] = 0.055 * scale_;
  chanETheom[k_ttW13] =  0.055 * scale_;
  chanETheo[k_ttW13] = (chanETheop[k_ttW13] +chanETheom[k_ttW13])/2.0;
// took uncerainty from paper  
  chanETheo[k_ttW13] =  0.055 * scale_;

  chanTheo[k_ttW13] =   0.601 * scale_;
chanETheop[k_ttW13] = sqrt(0.056*0.056+0.009*0.009+ 0.011*0.011) * scale_;
chanETheom[k_ttW13] =  sqrt(0.051*0.051+0.009*0.009+ 0.011*0.011) * scale_;
  chanETheo[k_ttW13] = (chanETheop[k_ttW13] +chanETheom[k_ttW13])/2.0;




// ttZ 13 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-16-017/index.html

chanMeasurement[k_ttZ13] = "ttZ";
   chanLumi[k_ttZ13] = "12.9";


  chanSigma[k_ttZ13]  =   0.70 * scale_; 
  chanEStatp[k_ttZ13]  =   0.16 * scale_;
  chanESystp[k_ttZ13]  =   0.14 * scale_;
  chanETotp[k_ttZ13]   =  sqrt( 
			   chanEStatp[k_ttZ13]*chanEStatp[k_ttZ13]
			   +
			   chanESystp[k_ttZ13]*chanESystp[k_ttZ13]
			    );

  chanEStatm[k_ttZ13]  =   0.15 * scale_;
  chanESystm[k_ttZ13]  =   0.12 * scale_;
  chanETotm[k_ttZ13]   =  sqrt( 
			   chanEStatm[k_ttZ13]*chanEStatm[k_ttZ13]
			   +
			   chanESystm[k_ttZ13]*chanESystm[k_ttZ13]
			    );
  chanEStat[k_ttZ13] = (chanEStatp[k_ttZ13] +chanEStatm[k_ttZ13])/2.0;
  chanESyst[k_ttZ13] = (chanESystp[k_ttZ13] +chanESystm[k_ttZ13])/2.0;
  chanETot[k_ttZ13] = (chanETotp[k_ttZ13] +chanETotm[k_ttZ13])/2.0;
 
chanMeasurement[k_ttZ13] = "ttZ";
   chanLumi[k_ttZ13] = "36";


  chanSigma[k_ttZ13]  =   1.00 * scale_; 
  chanEStatp[k_ttZ13]  =   0.09 * scale_;
  chanESystp[k_ttZ13]  =   0.12 * scale_;
  chanETotp[k_ttZ13]   =  sqrt( 
			   chanEStatp[k_ttZ13]*chanEStatp[k_ttZ13]
			   +
			   chanESystp[k_ttZ13]*chanESystp[k_ttZ13]
			    );

  chanEStatm[k_ttZ13]  =   0.08 * scale_;
  chanESystm[k_ttZ13]  =   0.10 * scale_;
  chanETotm[k_ttZ13]   =  sqrt( 
			   chanEStatm[k_ttZ13]*chanEStatm[k_ttZ13]
			   +
			   chanESystm[k_ttZ13]*chanESystm[k_ttZ13]
			    );
  chanEStat[k_ttZ13] = (chanEStatp[k_ttZ13] +chanEStatm[k_ttZ13])/2.0;
  chanESyst[k_ttZ13] = (chanESystp[k_ttZ13] +chanESystm[k_ttZ13])/2.0;
  chanETot[k_ttZ13] = (chanETotp[k_ttZ13] +chanETotm[k_ttZ13])/2.0;
 


  chanTheo[k_ttZ13] =   0.783 * scale_;
  chanETheop[k_ttZ13] = 0.086 * scale_;
  chanETheom[k_ttZ13] =  0.086 * scale_;
  chanETheo[k_ttZ13] = (chanETheop[k_ttZ13] +chanETheom[k_ttZ13])/2.0;
// took uncerainty from paper
chanETheo[k_ttZ13] = 0.086 * scale_;


  chanTheo[k_ttZ13] =   0.839 * scale_;
  chanETheop[k_ttZ13] = sqrt(0.080*0.080+0.025*0.025+ 0.025*0.025) * scale_;
  chanETheom[k_ttZ13] =  sqrt(0.092*0.092+0.025*0.025+ 0.025*0.025) * scale_;
  chanETheo[k_ttZ13] = (chanETheop[k_ttZ13] +chanETheom[k_ttZ13])/2.0;




// tZq CMS TOP 12 039
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-12-039/index.html
// https://arxiv.org/abs/1702.01404, submitted to JHEP
// Account for BF

  //scale_ = scale_/(4.0*Z0_br_ll*W_br_lnu);
  scale_ = 236.8/8.18;
  chanMeasurement[k_tZq8] = "tZq";
  chanLumi[k_tZq8] = "";


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


// tttt CMS TOP at 8 TeV
//
// https://arxiv.org/abs/1409.7339, JHEP 11 (2014) 154

  chanMeasurement[k_tttt8] = "tttt";
  chanLumi[k_tttt8] = "";


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

 


// tttt CMS TOP 16 016 at 13 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-16-016/index.html
// https://arxiv.org/abs/1702.06164, submitted to PLB

  chanMeasurement[k_tttt13] = "tttt";
  chanLumi[k_tttt13] = "";


  chanSigma[k_tttt13]  =   -0.069 * scale_; 
  chanEStatp[k_tttt13]  =   0.00 * scale_;
  chanESystp[k_tttt13]  =   0.00 * scale_;
  chanETotp[k_tttt13]   =  sqrt( 
			   chanEStatp[k_tttt13]*chanEStatp[k_tttt13]
			   +
			   chanESystp[k_tttt13]*chanESystp[k_tttt13]
			    );

  chanEStatm[k_tttt13]  =   0.00 * scale_;
  chanESystm[k_tttt13]  =   0.0 * scale_;
  chanETotm[k_tttt13]   =  sqrt( 
			   chanEStatm[k_tttt13]*chanEStatm[k_tttt13]
			   +
			   chanESystm[k_tttt13]*chanESystm[k_tttt13]
			    );
  chanEStat[k_tttt13] = (chanEStatp[k_tttt13] +chanEStatm[k_tttt13])/2.0;
  chanESyst[k_tttt13] = (chanESystp[k_tttt13] +chanESystm[k_tttt13])/2.0;
  chanETot[k_tttt13] = (chanETotp[k_tttt13] +chanETotm[k_tttt13])/2.0;
 


chanTheo[k_tttt13] =   (0.0092) * scale_;
  chanETheop[k_tttt13] =  0.0029* scale_;
  chanETheom[k_tttt13] =  0.0024 * scale_;
  chanETheo[k_tttt13] = (chanETheop[k_tttt13] +chanETheom[k_tttt13])/2.0;

  scale_ = 1.0;





// diboson results

// Wgamma
//chanMeasurement[k_Wg] = "W#gamma), #scale[0.7]{E_{T}^{ #gamma} > 15}";
  chanMeasurement[k_Wg] = "W#gamma";
  if (version==5) chanMeasurement[k_Wg] = "W#gamma, #scale[0.70]{(NLO th.)}";
  chanLumi[k_Wg] = "5.0 fb^{-1}";
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

// Zg
//  chanMeasurement[k_Zg] = "Z#gamma),  #scale[0.7]{E_{T}^{ #gamma} > 15}";
  chanMeasurement[k_Zg] = "Z#gamma";
  if (version==5) chanMeasurement[k_Zg] = "Z#gamma, #scale[0.70]{(NLO th.)}";
  chanLumi[k_Zg] = "5.0 fb^{-1}";
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
// new!!!!! CMS-PAS-SMP-13-014
//  chanMeasurement[k_Zg8] = "Z#gamma),  #scale[0.7]{E_{T}^{ #gamma} > 15}";
  chanMeasurement[k_Zg8] = "Z#gamma";
  if (version==5) chanMeasurement[k_Zg8] = "Z#gamma, #scale[0.70]{(NLO th.)}";

  chanLumi[k_Zg8] = "19.5 fb^{-1}";
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



// WV
  chanMeasurement[k_WV] = "WW+WZ";
  chanLumi[k_WV] = "4.9 fb^{-1}";

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
  chanMeasurement[k_WW] = "WW";
  //if (version == 5 )chanMeasurement[k_WW]= "WW, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_WW]= "4.9 fb^{-1}";

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

// New WW 8 TeV 



  chanMeasurement[k_WW8]= "WW";
  //if (version == 5 )chanMeasurement[k_WW8]= "WW, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_WW8]= "19.4 fb^{-1}";

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
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-16-006/index.html
  chanMeasurement[k_WW13]= "WW";
  //if (version == 5 )chanMeasurement[k_WW13]= "WW, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_WW13]= "2.3 fb^{-1}";

  chanSigma[k_WW13]  =  115.3 * scale_; 
  chanEStat[k_WW13]  =   5.8 * scale_;
chanESyst[k_WW13]  =   sqrt(5.7*5.7 + 6.4*6.4 + 3.6*3.6) * scale_;
  chanETot[k_WW13]   =  sqrt( 
			   chanEStat[k_WW13]*chanEStat[k_WW13]
			   +
			   chanESyst[k_WW13]*chanESyst[k_WW13]
			    );
  chanTheo[k_WW13] =  120.3 * scale_;
  chanETheo[k_WW13] =  3.6 * scale_;
// theo +1.3 -1.1



// WZ 7 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-014/index.html
// https://arxiv.org/abs/1609.05721 Submitted to EPJC


  chanMeasurement[k_WZ] = "WZ";
  //if (version == 5 )chanMeasurement[k_WZ]= "WZ, #scale[0.70]{(NNLO th.)}";  
  chanLumi[k_WZ] = "4.9 fb^{-1}";

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
// https://arxiv.org/abs/1609.05721 Submitted to EPJC


chanMeasurement[k_WZ8] = "WZ";
  //if (version == 5 )chanMeasurement[k_WZ8]= "WZ, #scale[0.70]{(NNLO th.)}";  
  chanLumi[k_WZ8] = "19.6 fb^{-1}";

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
// https://arxiv.org/abs/1609.05721 Submitted to EPJC

// 0 jet

scale_ = scale_* W_br_lnu * Z0_br_ll; 

chanMeasurement[k_WZ0jet8] = "#splitline{WZ}{=0j}";
  chanLumi[k_WZ0jet8]= "19.6 fb^{-1}";

  chanSigma[k_WZ0jet8]  =  16.15 * scale_; 
  chanEStatp[k_WZ0jet8]  =   1.95 * scale_;
  chanEStatm[k_WZ0jet8]  =   1.95 * scale_;
  chanEStat[k_WZ0jet8]  = ( chanEStatp[k_WZ0jet8] + chanEStatm[k_WZ0jet8])/2.0;

  chanESystp[k_WZ0jet8]  =    sqrt( 0.88*0.88+0.42*0.42)* scale_;
  chanESystm[k_WZ0jet8]  =    sqrt( 0.88*0.88+0.42*0.42 )* scale_;
  chanESyst[k_WZ0jet8]  = ( chanESystp[k_WZ0jet8] + chanESystm[k_WZ0jet8])/2.0;
 
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
  chanLumi[k_WZ1jet8]= "19.6 fb^{-1}";

  chanSigma[k_WZ1jet8]  =  5.27 * scale_; 
  chanEStatp[k_WZ1jet8]  =   1.11 * scale_;
  chanEStatm[k_WZ1jet8]  =   1.11 * scale_;
  chanEStat[k_WZ1jet8]  = ( chanEStatp[k_WZ1jet8] + chanEStatm[k_WZ1jet8])/2.0;

  chanESystp[k_WZ1jet8]  =    sqrt( 0.52*0.52+0.14*0.14)* scale_;
  chanESystm[k_WZ1jet8]  =    sqrt( 0.52*0.52+0.14*0.14 )* scale_;
  chanESyst[k_WZ1jet8]  = ( chanESystp[k_WZ1jet8] + chanESystm[k_WZ1jet8])/2.0;
 
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
  chanLumi[k_WZ2jet8]= "19.6 fb^{-1}";

  chanSigma[k_WZ2jet8]  =  2.11 * scale_; 
  chanEStatp[k_WZ2jet8]  =   0.69 * scale_;
  chanEStatm[k_WZ2jet8]  =   0.69 * scale_;
  chanEStat[k_WZ2jet8]  = ( chanEStatp[k_WZ2jet8] + chanEStatm[k_WZ2jet8])/2.0;

  chanESystp[k_WZ2jet8]  =    sqrt( 0.27*0.27+0.05*0.05)* scale_;
  chanESystm[k_WZ2jet8]  =    sqrt( 0.27*0.27+0.05*0.05 )* scale_;
  chanESyst[k_WZ2jet8]  = ( chanESystp[k_WZ2jet8] + chanESystm[k_WZ2jet8])/2.0;
 
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
  chanLumi[k_WZ3jet8]= "19.6 fb^{-1}";

  chanSigma[k_WZ3jet8]  =  0.196 * scale_; 
  chanEStatp[k_WZ3jet8]  =   0.227 * scale_;
  chanEStatm[k_WZ3jet8]  =   0.227 * scale_;
  chanEStat[k_WZ3jet8]  = ( chanEStatp[k_WZ3jet8] + chanEStatm[k_WZ3jet8])/2.0;

  chanESystp[k_WZ3jet8]  =    sqrt( 0.102*0.102+0.005*0.005)* scale_;
  chanESystm[k_WZ3jet8]  =    sqrt( 0.102*0.102+0.005*0.005 )* scale_;
  chanESyst[k_WZ3jet8]  = ( chanESystp[k_WZ3jet8] + chanESystm[k_WZ3jet8])/2.0;
 
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
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-16-002/index.html
// https://arxiv.org/abs/1607.06943 Submitted to Phys. Lett. B

  if (use13TeV) chanMeasurement[k_WZ13] = "WZ";
  //if (version == 5 && use13TeV)chanMeasurement[k_WZ13]= "WZ, #scale[0.70]{(NNLO th.)}";  
if (big13TeV) chanMeasurement[k_WZ13]    =  "#splitline{  WZ}{13Tev}";
  chanLumi[k_WZ13] = "2.3 fb^{-1}";

  chanSigma[k_WZ13]  =  39.9 * scale_; 
  chanEStatp[k_WZ13]  =   3.2 * scale_;
  chanEStatm[k_WZ13]  =   3.2 * scale_;
chanEStat[k_WZ13]  = ( chanEStatp[k_WZ13] + chanEStatm[k_WZ13])/2.0;


  chanESystp[k_WZ13]  =    sqrt( 2.9*2.9+0.4*0.4+1.3*1.3)* scale_;
  chanESystm[k_WZ13]  =    sqrt( 3.1*3.1+0.4*0.4+1.3*1.3)* scale_;
  chanESyst[k_WZ13]  = ( chanESystp[k_WZ13] + chanESystm[k_WZ13])/2.0;
 

  chanETot[k_WZ13]   =  sqrt( 
			   chanEStat[k_WZ13]*chanEStat[k_WZ13]
			   +
			   chanESyst[k_WZ13]*chanESyst[k_WZ13]
			    );

//  chanTheo[k_WZ13] =  42.6 * scale_;
//  chanETheo[k_WZ13] =  1.2 * scale_;
// +1.6-0.8
  chanTheo[k_WZ13] =  50.0 * scale_;
chanETheop[k_WZ13] =  sqrt(1.1*1.1) * scale_;
chanETheom[k_WZ13] =  sqrt(1.0*1.0)  * scale_;
  chanETheo[k_WZ13]   = (chanETheop[k_WZ13]+chanETheom[k_WZ13])/2.0;  



// WZ 13 TeV fiducial
  if (use13TeV) chanMeasurement[k_WZ13fid] = "WZ";
  //if (version == 5 && use13TeV)chanMeasurement[k_WZ13fid]= "WZ, #scale[0.70]{(NNLO th.)}";  
  if (big13TeV) chanMeasurement[k_WZ13fid]    =  "#splitline{  WZ}{13Tev}";
  chanLumi[k_WZ13fid] = "2.3 fb^{-1}";

  chanSigma[k_WZ13fid]  =  0.258 * scale_; 
  chanEStatp[k_WZ13fid]  =   0.021 * scale_;
  chanEStatm[k_WZ13fid]  =   0.021 * scale_;
chanEStat[k_WZ13fid]  = ( chanEStatp[k_WZ13fid] + chanEStatm[k_WZ13fid])/2.0;


  chanESystp[k_WZ13fid]  =    sqrt( 0.019*0.019+0.008*0.008)* scale_;
  chanESystm[k_WZ13fid]  =    sqrt( 0.020*0.020+0.008*0.008 )* scale_;
  chanESyst[k_WZ13fid]  = ( chanESystp[k_WZ13fid] + chanESystm[k_WZ13fid])/2.0;
 

  chanETot[k_WZ13fid]   =  sqrt( 
			   chanEStat[k_WZ13fid]*chanEStat[k_WZ13fid]
			   +
			   chanESyst[k_WZ13fid]*chanESyst[k_WZ13fid]
			    );
  chanTheo[k_WZ13fid] =  50.0 * (0.258/39.9)* scale_;
  chanETheop[k_WZ13fid] =  sqrt(1.1*1.1) * (0.258/39.9) * scale_;
  chanETheom[k_WZ13fid] =  sqrt(1.0*1.0) * (0.258/39.9) * scale_;
  chanETheo[k_WZ13fid]   = (chanETheop[k_WZ13fid]+chanETheom[k_WZ13fid])/2.0;  


// ZZ
  chanMeasurement[k_ZZ] = "ZZ";
  //if (version == 5 )  chanMeasurement[k_ZZ] = "ZZ, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_ZZ] = "4.9 fb^{-1}";

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


// ZZ 8 TeV
// Update refernce to http://arxiv.org/abs/1406.0113 !!!!!new
  chanMeasurement[k_ZZ8] = "ZZ";
  //if (version == 5 )    chanMeasurement[k_ZZ8] = "ZZ, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_ZZ8]= "19.6 fb^{-1}";

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
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-16-001/index.html
// https://arxiv.org/abs/1607.08834 Phys. Lett. B 763 (2016) 280
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-16-017/index.html

  if (use13TeV) chanMeasurement[k_ZZ13] = "ZZ";
  //if (version == 5 && use13TeV)chanMeasurement[k_ZZ13]= "ZZ";  
  if (big13TeV) chanMeasurement[k_ZZ13]    =  "#splitline{  ZZ}{13Tev}";
  chanLumi[k_ZZ13] = "2.6 fb^{-1}";

  chanSigma[k_ZZ13]  =  14.6 * scale_; 
  chanEStatp[k_ZZ13]  =   1.9 * scale_;
  chanEStatm[k_ZZ13]  =   1.8 * scale_;
  chanEStat[k_ZZ13]  = ( chanEStatp[k_ZZ13] + chanEStatm[k_ZZ13])/2.0;


  chanESystp[k_ZZ13]  =    sqrt( 0.5*0.5+0.2*0.2+0.4*0.4)* scale_;
  chanESystm[k_ZZ13]  =    sqrt( 0.3*0.3+0.2*0.2+0.4*0.4)* scale_;
  chanESyst[k_ZZ13]  = ( chanESystp[k_ZZ13] + chanESystm[k_ZZ13])/2.0;

  chanETot[k_ZZ13]   =  sqrt( 
			   chanEStat[k_ZZ13]*chanEStat[k_ZZ13]
			   +
			   chanESyst[k_ZZ13]*chanESyst[k_ZZ13]
			    );

  chanLumi[k_ZZ13] = "35.9 fb^{-1}";


chanSigma[k_ZZ13]  =  17.8 * scale_; 
  chanEStatp[k_ZZ13]  =   0.6 * scale_;
  chanEStatm[k_ZZ13]  =   0.6 * scale_;
  chanEStat[k_ZZ13]  = ( chanEStatp[k_ZZ13] + chanEStatm[k_ZZ13])/2.0;


  chanESystp[k_ZZ13]  =    sqrt( 0.7*0.7+0.4*0.4+0.5*0.5)* scale_;
  chanESystm[k_ZZ13]  =    sqrt( 0.6*0.6+0.4*0.4+0.5*0.5)* scale_;
  chanESyst[k_ZZ13]  = ( chanESystp[k_ZZ13] + chanESystm[k_ZZ13])/2.0;

  chanETot[k_ZZ13]   =  sqrt( 
			   chanEStat[k_ZZ13]*chanEStat[k_ZZ13]
			   +
			   chanESyst[k_ZZ13]*chanESyst[k_ZZ13]
			    );



// New NNLO Number (check)
//chanTheo[k_ZZ13] =  16.5 * scale_;
//chanETheop[k_ZZ13] =  0.034 * 16.5 * scale_;
//chanETheom[k_ZZ13] =  0.027 * 16.5 * scale_;
chanTheo[k_ZZ13] =  16.2 * scale_;
chanETheop[k_ZZ13] =  sqrt(0.6*0.6)* scale_;
chanETheom[k_ZZ13] =  sqrt(0.4*0.4)* scale_;
  chanETheo[k_ZZ13]   = (chanETheop[k_ZZ13]+chanETheom[k_ZZ13])/2.0;  

  scale_ = 1.;


// ZZ 13 TeV fiducial
  if (use13TeV) chanMeasurement[k_ZZ13fid] = "ZZ";
if (big13TeV) chanMeasurement[k_ZZ13fid]    =  "#splitline{  ZZ}{13Tev}";
  chanLumi[k_ZZ13fid] = "2.6 fb^{-1}";

  chanSigma[k_ZZ13fid]  =  0.0348 * scale_; 
  chanEStatp[k_ZZ13fid]  =   0.0046 * scale_;
  chanEStatm[k_ZZ13fid]  =   0.0042 * scale_;
  chanEStat[k_ZZ13fid]  = ( chanEStatp[k_ZZ13fid] + chanEStatm[k_ZZ13fid])/2.0;


  chanESystp[k_ZZ13fid]  =    sqrt( 0.0012*0.0012+0.0009*0.0009)* scale_;
  chanESystm[k_ZZ13fid]  =    sqrt( 0.0008*0.0008+0.0009*0.0009 )* scale_;
  chanESyst[k_ZZ13fid]  = ( chanESystp[k_ZZ13fid] + chanESystm[k_ZZ13fid])/2.0;
 

  chanETot[k_ZZ13fid]   =  sqrt( 
			   chanEStat[k_ZZ13fid]*chanEStat[k_ZZ13fid]
			   +
			   chanESyst[k_ZZ13fid]*chanESyst[k_ZZ13fid]
			    );
chanTheo[k_ZZ13fid] =  16.2 * (0.0348/14.6)   * scale_;
  chanETheop[k_ZZ13fid] =  0.6 *  (0.0348/14.6) * scale_;
  chanETheom[k_ZZ13fid] =  0.4 *  (0.0348/14.6) * scale_;
  chanETheo[k_ZZ13fid] = (chanETheop[k_ZZ13fid]+chanETheom[k_ZZ13fid])/2.0;  
// fixed scale 16.18
// +1.6-0.8, needs NNLO update

  chanLumi[k_ZZ13fid] = "35.9 fb^{-1}";

  chanSigma[k_ZZ13fid]  =  0.0422 * scale_; 
  chanEStatp[k_ZZ13fid]  =   0.0014 * scale_;
  chanEStatm[k_ZZ13fid]  =   0.0014 * scale_;
  chanEStat[k_ZZ13fid]  = ( chanEStatp[k_ZZ13fid] + chanEStatm[k_ZZ13fid])/2.0;


  chanESystp[k_ZZ13fid]  =    sqrt( 0.0016*0.0016+0.0011*0.0011)* scale_;
  chanESystm[k_ZZ13fid]  =    sqrt( 0.0015*0.0015+0.0011*0.0011 )* scale_;
  chanESyst[k_ZZ13fid]  = ( chanESystp[k_ZZ13fid] + chanESystm[k_ZZ13fid])/2.0;
 

  chanETot[k_ZZ13fid]   =  sqrt( 
			   chanEStat[k_ZZ13fid]*chanEStat[k_ZZ13fid]
			   +
			   chanESyst[k_ZZ13fid]*chanESyst[k_ZZ13fid]
			    );
chanTheo[k_ZZ13fid] =  16.2 * (0.0422/17.8)   * scale_;
  chanETheop[k_ZZ13fid] =  0.6 *  (0.0422/17.8) * scale_;
  chanETheom[k_ZZ13fid] =  0.4 *  (0.0422/17.8) * scale_;
  chanETheo[k_ZZ13fid] = (chanETheop[k_ZZ13fid]+chanETheom[k_ZZ13fid])/2.0;  


// ZZ+jets  13 TeV
// 0 jet

  chanMeasurement[k_ZZ0jet13] = "#splitline{ZZ}{=0j}";
  chanLumi[k_ZZ0jet13]= "35.9 fb^{-1}";

  chanSigma[k_ZZ0jet13]  =  0.0281 * scale_; 
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
  chanETheop[k_ZZ0jet13] =  0.008 * scale_;
  chanETheom[k_ZZ0jet13] =  0.009 * scale_;
  chanETheo[k_ZZ0jet13 ] =  (chanETheop[k_ZZ1jet13]+chanETheom[k_ZZ1jet13])/2.0;


// 1jet
  chanMeasurement[k_ZZ1jet13] = "=1j";
  chanLumi[k_ZZ1jet13]= "35.9 fb^{-1}";

  chanSigma[k_ZZ1jet13]  =  0.0080 * scale_; 
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
  chanLumi[k_ZZ2jet13]= "35.9 fb^{-1}";

  chanSigma[k_ZZ2jet13]  =  0.0030 * scale_; 
  chanEStatp[k_ZZ2jet13]  =   0.0005 * scale_;
  chanEStatm[k_ZZ2jet13]  =   0.0005 * scale_;
  chanEStat[k_ZZ2jet13]  = ( chanEStatp[k_ZZ2jet13] + chanEStatm[k_ZZ2jet13])/2.0;

  chanESystp[k_ZZ2jet13]  =    sqrt( 0.0003*0.0003+0.0001*0.0001)* scale_;
  chanESystm[k_ZZ2jet13]  =    sqrt( 0.0004*0.0004+0.0001*0.0001 )* scale_;
  chanESyst[k_ZZ2jet13]  = ( chanESystp[k_ZZ2jet13] + chanESystm[k_ZZ2jet13])/2.0;
 
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
  chanLumi[k_ZZ3jet13]= "35.9 fb^{-1}";

  chanSigma[k_ZZ3jet13]  =  0.0013 * scale_; 
  chanEStatp[k_ZZ3jet13]  =   0.0004 * scale_;
  chanEStatm[k_ZZ3jet13]  =   0.0004 * scale_;
  chanEStat[k_ZZ3jet13]  = ( chanEStatp[k_ZZ3jet13] + chanEStatm[k_ZZ3jet13])/2.0;

  chanESystp[k_ZZ3jet13]  =    sqrt( 0.0003*0.0003+0.0000*0.0000)* scale_;
  chanESystm[k_ZZ3jet13]  =    sqrt( 0.0002*0.0002+0.0000*0.0000 )* scale_;
  chanESyst[k_ZZ3jet13]  = ( chanESystp[k_ZZ3jet13] + chanESystm[k_ZZ3jet13])/2.0;
 
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


// EWK Zg http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-14-018/index.html

  scale_=1/1000.0;

  chanMeasurement[k_EWKZg8] = "#splitline{EW}{Z#gammajj}";
if (ratioPlot) chanMeasurement[k_EWKZg8]     = "Z#gammajj";

  chanLumi[k_EWKZg8] = "19.7 fb^{-1}";

  chanSigma[k_EWKZg8]  =  1.86 * scale_; 
  chanEStatp[k_EWKZg8]  =   0.89 * scale_;
  chanEStatm[k_EWKZg8]  =   0.75 * scale_;
  chanEStat[k_EWKZg8]  = ( chanEStatp[k_EWKZg8] + chanEStatm[k_EWKZg8])/2.0;

  chanESystp[k_EWKZg8]  =    sqrt( 0.41*0.41+0.5*0.5)* scale_;
  chanESystm[k_EWKZg8]  =    sqrt( 0.27*0.27+0.5*0.5)* scale_;
  chanESyst[k_EWKZg8]  = ( chanESyst[k_EWKZg8] + chanESyst[k_EWKZg8])/2.0;


  chanETot[k_EWKZg8]   =  sqrt( 
			   chanEStat[k_EWKZg8]*chanEStat[k_EWKZg8]
			   +
			   chanESyst[k_EWKZg8]*chanESyst[k_EWKZg8]
			    );
  chanTheo[k_EWKZg8] =  1.26 * scale_;
chanETheo[k_EWKZg8] =  sqrt(0.11*0.11 + 0.05*0.05) * scale_;

  scale_ = 1.;

// EWK Wg 
// http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-011/index.html
// https://arxiv.org/abs/1612.09256, submitted to JHEP

  scale_=1/1000.0;

  chanMeasurement[k_EWKWg8] = "#splitline{EW}{W#gammajj}";
if (ratioPlot) chanMeasurement[k_EWKWg8]     = "W#gammajj";


  chanLumi[k_EWKWg8] = "19.7 fb^{-1}";

  chanSigma[k_EWKWg8]  =  10.8 * scale_; 
  chanEStatp[k_EWKWg8]  =   4.1 * scale_;
  chanEStatm[k_EWKWg8]  =   4.1 * scale_;
  chanEStat[k_EWKWg8]  = ( chanEStatp[k_EWKWg8] + chanEStatm[k_EWKWg8])/2.0;

  chanESystp[k_EWKWg8]  =    sqrt( 3.4*3.4+0.3*0.3)* scale_;
  chanESystm[k_EWKWg8]  =    sqrt( 3.4*3.4+0.3*0.3)* scale_;
  chanESyst[k_EWKWg8]  = ( chanESyst[k_EWKWg8] + chanESyst[k_EWKWg8])/2.0;


  chanETot[k_EWKWg8]   =  sqrt( 
			   chanEStat[k_EWKWg8]*chanEStat[k_EWKWg8]
			   +
			   chanESyst[k_EWKWg8]*chanESyst[k_EWKWg8]
			    );
  chanTheo[k_EWKWg8] =  6.1 * scale_;
chanETheo[k_EWKWg8] =  sqrt(1.2*1.2 + 0.2*0.2) * scale_;

  scale_ = 1.;

// EWK ZZ 13 TeV
// 


  scale_=1/1000.0;

  chanMeasurement[k_EWKZZ13] = "#splitline{EW}{ZZjj}";
  if (ratioPlot) chanMeasurement[k_EWKZZ13]     = "ZZjj";

  chanLumi[k_EWKZZ13] = "35.9 fb^{-1}";

  chanSigma[k_EWKZZ13]  =  0.40 * scale_; 
  chanEStatp[k_EWKZZ13]  =   0.21 * scale_;
  chanEStatm[k_EWKZZ13]  =   0.16 * scale_;
  chanEStat[k_EWKZZ13]  = ( chanEStatp[k_EWKZZ13] + chanEStatm[k_EWKZZ13])/2.0;

  chanESystp[k_EWKZZ13]  =    sqrt( 0.13*0.13)* scale_;
  chanESystm[k_EWKZZ13]  =    sqrt( 0.09*0.09)* scale_;
  chanESyst[k_EWKZZ13]  = ( chanESyst[k_EWKZZ13] + chanESyst[k_EWKZZ13])/2.0;


  chanETot[k_EWKZZ13]   =  sqrt( 
			   chanEStat[k_EWKZZ13]*chanEStat[k_EWKZZ13]
			   +
			   chanESyst[k_EWKZZ13]*chanESyst[k_EWKZZ13]
			    );
  chanTheo[k_EWKZZ13] =  0.29 * scale_;
chanETheo[k_EWKZZ13] =  sqrt(0.015*0.015) * scale_;

  scale_ = 1.;



// add +2jet results

// WVgamma
// !!!!! replace with reference http://arxiv.org/abs/1404.4619
  chanMeasurement[k_WVg] = "WV#gamma";
  chanLumi[k_WVg]= "19.3 fb^{-1}";

  chanSigma[k_WVg]  =  -0.311 * scale_; 
  chanEStat[k_WVg]  =   0.311 * scale_;
  chanESyst[k_WVg]  =   0.0 * scale_;
  chanETot[k_WVg]   =  sqrt( 
			   chanEStat[k_WV]*chanEStat[k_WVg]
			   +
			   chanESyst[k_WV]*chanESyst[k_WVg]
			    );
  chanTheo[k_WVg] =  0.0916 * scale_;
  chanETheo[k_WVg] =  0.0217 * scale_;

 scale_ = 1.;


// Wgg 8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-15-008/index.html
// fb scale
scale_ = 0.001;
  chanMeasurement[k_Wgg8] = "W#gamma#gamma";
  chanLumi[k_Wgg8] = "19.4 fb^{-1}";

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

// Zgg 8 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-15-008/index.html
// fb scale
scale_ = 0.001;
  chanMeasurement[k_Zgg8] = "Z#gamma#gamma";
  chanLumi[k_Zgg8] = "19.4 fb^{-1}";

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



// Exclusive gg -> WW production
// http://cms-results.web.cern.ch/cms-results/public-results/publications/FSQ-12-010/index.html,
// http://arxiv.org/abs/1305.5596  	JHEP 07 (2013) 116
  chanMeasurement[k_exWW] = "#splitline{#gamma#gamma#rightarrow}{WW}";
if (version == 6) chanMeasurement[k_exWW] = "#splitline{#gamma#gamma#rightarrow WW}{WW #rightarrow l#nul#nu}";


chanLumi[k_exWW]= "5.05 fb^{-1}";
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

  chanMeasurement[k_exWW8] = "#splitline{#gamma#gamma#rightarrow}{WW}";
if (version == 6) chanMeasurement[k_exWW8] = "#splitline{#gamma#gamma#rightarrow WW}{WW #rightarrow l#nul#nu}";
if (ratioPlot) chanMeasurement[k_exWW8]     = "ss WW";

chanLumi[k_exWW8]= "19.7 fb^{-1}";
//scale_ = 1.0/(W_br_lnu*W_br_lnu*2.0) ;
scale_ = 2.0;

  chanSigma[k_exWW8]  =  0.0108 * scale_; 
  chanEStat[k_exWW8]  =   0.0046 * scale_;
  chanESyst[k_exWW8]  =   0.0 * scale_;
  chanETot[k_exWW8]   =  sqrt( 
			   chanEStat[k_exWW8]*chanEStat[k_exWW8]
			   +
			   chanESyst[k_exWW8]*chanESyst[k_exWW8]
			    );
  chanTheo[k_exWW8] =  0.0062 * scale_;
  chanETheo[k_exWW8] =  0.0005 * scale_;

// 11.9 + 5.6 - 4.5

 scale_ = 1.;

// SS WW http://arxiv.org/abs/1410.6315 Phys. Rev. Lett. 114, 051801 (2015)

  chanMeasurement[k_SSWW8] = "#splitline{ EW}{ssWW}";
if (version == 6) chanMeasurement[k_SSWW8] = "#splitline{EWK ss WW}{WW #rightarrow l#nu l#nu}";
if (ratioPlot) chanMeasurement[k_SSWW8]     = "ss WW";


chanLumi[k_SSWW8]= "19.4 fb^{-1}";
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
//

  chanMeasurement[k_SSWW13] = "#splitline{ EW}{ssWW}";
if (version == 6) chanMeasurement[k_SSWW13] = "#splitline{EWK ss WW}{WW #rightarrow l#nu l#nu}";
if (ratioPlot) chanMeasurement[k_SSWW13]     = "ss WW";

  chanLumi[k_SSWW13]= "35.9 fb^{-1}";
//scale_ = 1.0/(W_br_lnu*W_br_lnu*2.0) ;

  chanSigma[k_SSWW13]  =  0.00383 * scale_; 
  chanEStat[k_SSWW13]  =   0.00066 * scale_;
  chanESyst[k_SSWW13]  =   0.00035 * scale_;
  chanETot[k_SSWW13]   =  sqrt( 
			   chanEStat[k_SSWW13]*chanEStat[k_SSWW13]
			   +
			   chanESyst[k_SSWW13]*chanESyst[k_SSWW13]
			    );
  chanTheo[k_SSWW13] =  0.00425 * scale_;
  chanETheo[k_SSWW13] =  0.00021 * scale_;





// Higgs results

// Higgs + jets at 13 TeV in H->gg
// HIG-17-015
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-17-015/index.html



// H + 0j

scale_ = 1.0/1000.0;

chanMeasurement[k_H0jet13]  = "#splitline{H}{=0j}";
  chanLumi[k_H0jet13]  = "35.9 fb^{-1}";

  chanTheo[k_H0jet13] =   43.50 * scale_;
  chanETheop[k_H0jet13] =  8.66 * scale_;
  chanETheom[k_H0jet13] =  8.66 * scale_;
  chanETheo[k_H0jet13] = (chanETheop[k_H0jet13] +chanETheom[k_H0jet13])/2.0;


  chanSigma[k_H0jet13]  =   67.52 * scale_; 
  chanEStatp[k_H0jet13]  =   0.0;
  chanESystp[k_H0jet13]  =   0.0;
  chanETotp[k_H0jet13]   =  11.51 * scale_ ;
  chanEStatm[k_H0jet13]  =  0.0;
  chanESystm[k_H0jet13]  =  0.0;
  chanETotm[k_H0jet13]   =  10.92 * scale_;
 
  chanEStat[k_H0jet13] = (chanEStatp[k_H0jet13] +chanEStatm[k_H0jet13])/2.0;
  chanESyst[k_H0jet13] = (chanESystp[k_H0jet13] +chanESystm[k_H0jet13])/2.0;
  chanETot[k_H0jet13] = (chanETotp[k_H0jet13] +chanETotm[k_H0jet13])/2.0;

// H + 1j
chanMeasurement[k_H1jet13]  = "=1j";
  chanLumi[k_H1jet13]  = "35.9 fb^{-1}";

  chanTheo[k_H1jet13] =   17.70 * scale_;
  chanETheop[k_H1jet13] =  2.88 * scale_;
  chanETheom[k_H1jet13] =  2.88 * scale_;
  chanETheo[k_H1jet13] = (chanETheop[k_H1jet13] +chanETheom[k_H1jet13])/2.0;


  chanSigma[k_H1jet13]  =   14.04 * scale_; 
  chanEStatp[k_H1jet13]  =   0.0;
  chanESystp[k_H1jet13]  =   0.0;
  chanETotp[k_H1jet13]   =  6.61 * scale_ ;
  chanEStatm[k_H1jet13]  =  0.0;
  chanESystm[k_H1jet13]  =  0.0;
  chanETotm[k_H1jet13]   =  6.37 * scale_;
 
  chanEStat[k_H1jet13] = (chanEStatp[k_H1jet13] +chanEStatm[k_H1jet13])/2.0;
  chanESyst[k_H1jet13] = (chanESystp[k_H1jet13] +chanESystm[k_H1jet13])/2.0;
  chanETot[k_H1jet13] = (chanETotp[k_H1jet13] +chanETotm[k_H1jet13])/2.0;

// H + 2j
chanMeasurement[k_H2jet13]  = "=2j";
  chanLumi[k_H2jet13]  = "35.9 fb^{-1}";

  chanTheo[k_H2jet13] =   5.74 * scale_;
  chanETheop[k_H2jet13] =  0.97 * scale_;
  chanETheom[k_H2jet13] =  0.97 * scale_;
  chanETheo[k_H2jet13] = (chanETheop[k_H2jet13] +chanETheom[k_H2jet13])/2.0;


  chanSigma[k_H2jet13]  =   0.83 * scale_; 
  chanEStatp[k_H2jet13]  =   0.0;
  chanESystp[k_H2jet13]  =   0.0;
  chanETotp[k_H2jet13]   =  3.60 * scale_ ;
  chanEStatm[k_H2jet13]  =  0.0;
  chanESystm[k_H2jet13]  =  0.0;
  chanETotm[k_H2jet13]   =  3.45 * scale_;
 
  chanEStat[k_H2jet13] = (chanEStatp[k_H2jet13] +chanEStatm[k_H2jet13])/2.0;
  chanESyst[k_H2jet13] = (chanESystp[k_H2jet13] +chanESystm[k_H2jet13])/2.0;
  chanETot[k_H2jet13] = (chanETotp[k_H2jet13] +chanETotm[k_H2jet13])/2.0;


// H + 3j
chanMeasurement[k_H3jet13]  = "=3j";
  chanLumi[k_H3jet13]  = "35.9 fb^{-1}";

  chanTheo[k_H3jet13] =   1.66 * scale_;
  chanETheop[k_H3jet13] =  0.19 * scale_;
  chanETheom[k_H3jet13] =  0.19 * scale_;
  chanETheo[k_H3jet13] = (chanETheop[k_H3jet13] +chanETheom[k_H3jet13])/2.0;


  chanSigma[k_H3jet13]  =   3.25 * scale_; 
  chanEStatp[k_H3jet13]  =   0.0;
  chanESystp[k_H3jet13]  =   0.0;
  chanETotp[k_H3jet13]   =  2.53 * scale_ ;
  chanEStatm[k_H3jet13]  =  0.0;
  chanESystm[k_H3jet13]  =  0.0;
  chanETotm[k_H3jet13]   =  2.16 * scale_;
 
  chanEStat[k_H3jet13] = (chanEStatp[k_H3jet13] +chanEStatm[k_H3jet13])/2.0;
  chanESyst[k_H3jet13] = (chanESystp[k_H3jet13] +chanESystm[k_H3jet13])/2.0;
  chanETot[k_H3jet13] = (chanETotp[k_H3jet13] +chanETotm[k_H3jet13])/2.0;


// H + 4j
chanMeasurement[k_H4jet13]  = ">=4j";
  chanLumi[k_H4jet13]  = "35.9 fb^{-1}";

  chanTheo[k_H4jet13] =   0.0093 * scale_;
  chanETheop[k_H4jet13] =  0.0016 * scale_;
  chanETheom[k_H4jet13] =  0.0016 * scale_;
  chanETheo[k_H4jet13] = (chanETheop[k_H4jet13] +chanETheom[k_H4jet13])/2.0;


  chanSigma[k_H4jet13]  =   0.0179 * scale_; 
  chanEStatp[k_H4jet13]  =   0.0;
  chanESystp[k_H4jet13]  =   0.0;
  chanETotp[k_H4jet13]   =  0.0116 * scale_ ;
  chanEStatm[k_H4jet13]  =  0.0;
  chanESystm[k_H4jet13]  =  0.0;
  chanETotm[k_H4jet13]   =  0.0114 * scale_;
 
  chanEStat[k_H4jet13] = (chanEStatp[k_H4jet13] +chanEStatm[k_H4jet13])/2.0;
  chanESyst[k_H4jet13] = (chanESystp[k_H4jet13] +chanESystm[k_H4jet13])/2.0;
  chanETot[k_H4jet13] = (chanETotp[k_H4jet13] +chanETotm[k_H4jet13])/2.0;

scale_ = 1.0;



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


// gg -> H gluon fusion Higgs 7 TeV 
  chanMeasurement[k_ggH]  = "ggH";
  chanLumi[k_ggH]  = "5.1 fb^{-1}";

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
  chanMeasurement[k_VBFH]  = "#splitline{VBF}{qqH}";
  chanLumi[k_VBFH]  = "5.1 fb^{-1}";

  chanTheo[k_VBFH] =   1.222 * scale_;
  chanETheop[k_VBFH] =  0.0252 * chanTheo[k_VBFH];
  chanETheom[k_VBFH] =  0.0212 * chanTheo[k_VBFH];
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
  chanMeasurement[k_VBFH8]  = "#splitline{VBF}{qqH}";
  chanLumi[k_VBFH8]  = "19.5 fb^{-1}";

  chanTheo[k_VBFH8] =   1.578 * scale_;
  chanETheop[k_VBFH8] =  0.0261 * chanTheo[k_VBFH8];
  chanETheom[k_VBFH8] =  0.0281 * chanTheo[k_VBFH8];
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
// from H->gg PAS
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-16-020/index.html
// from H->gg PAS 35.9fb-1 result did not improve


  chanMeasurement[k_VBFHgg13]  = "#splitline{VBF}{qqH}";
  chanLumi[k_VBFHgg13]  = "12.9 fb^{-1}";

// cross section from https://arxiv.org/abs/1610.07922 NNLO+EW

  chanTheo[k_VBFHgg13] =   3.7817 * scale_;
  chanETheop[k_VBFHgg13] =  0.0043 * chanTheo[k_VBFHgg13];
  chanETheom[k_VBFHgg13] =  0.0033 * chanTheo[k_VBFHgg13];
  chanETheo[k_VBFHgg13] = (chanETheop[k_VBFHgg13] +chanETheom[k_VBFHgg13])/2.0;


  chanSigma[k_VBFHgg13]  =   1.61 * chanTheo[k_VBFHgg13] * scale_; 
  chanEStatp[k_VBFHgg13]  =   0.0;
  chanESystp[k_VBFHgg13]  =   0.0;
  chanETotp[k_VBFHgg13]   =  sqrt(0.9*0.9*chanTheo[k_VBFHgg13]*chanTheo[k_VBFHgg13] - chanETheop[k_VBFHgg13]*chanETheop[k_VBFHgg13] );
  chanETotp[k_VBFHgg13]   =  sqrt(0.9*0.9*chanTheo[k_VBFHgg13]*chanTheo[k_VBFHgg13] );


  chanEStatm[k_VBFHgg13]  =  0.0;
  chanESystm[k_VBFHgg13]  =  0.0;
  chanETotm[k_VBFHgg13]   =  sqrt(0.8*0.8*chanTheo[k_VBFHgg13]*chanTheo[k_VBFHgg13] - chanETheom[k_VBFHgg13]*chanETheom[k_VBFHgg13] );
  chanETotm[k_VBFHgg13]   =  sqrt(0.8*0.8*chanTheo[k_VBFHgg13]*chanTheo[k_VBFHgg13] );

  chanEStat[k_VBFHgg13] = (chanEStatp[k_VBFHgg13] +chanEStatm[k_VBFHgg13])/2.0;
  chanESyst[k_VBFHgg13] = (chanESystp[k_VBFHgg13] +chanESystm[k_VBFHgg13])/2.0;
  chanETot[k_VBFHgg13] = (chanETotp[k_VBFHgg13] +chanETotm[k_VBFHgg13])/2.0;
 
// VBF vector boson fusion Higgs 13 TeV 35.9
// from H->tautua PAS
// HIG-16-43
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-16-043/index.html

 
  chanMeasurement[k_VBFHtt13]  = "#splitline{VBF}{qqH}";
  chanLumi[k_VBFHtt13]  = "35.9 fb^{-1}";

// cross section from https://arxiv.org/abs/1610.07922 NNLO+EW

  chanTheo[k_VBFHtt13] =   3.7817 * scale_;
  chanETheop[k_VBFHtt13] =  0.0043 * chanTheo[k_VBFHtt13];
  chanETheom[k_VBFHtt13] =  0.0033 * chanTheo[k_VBFHtt13];
  chanETheo[k_VBFHtt13] = (chanETheop[k_VBFHtt13] +chanETheom[k_VBFHtt13])/2.0;


  chanSigma[k_VBFHtt13]  =   1.16 * chanTheo[k_VBFHtt13] * scale_; 
  chanEStatp[k_VBFHtt13]  =   0.0;
  chanESystp[k_VBFHtt13]  =   0.0;
  chanETotp[k_VBFHtt13]   =  sqrt(0.42*0.42*chanTheo[k_VBFHtt13]*chanTheo[k_VBFHtt13] - chanETheop[k_VBFHtt13]*chanETheop[k_VBFHtt13] );
  chanETotp[k_VBFHtt13]   =  sqrt(0.42*0.42*chanTheo[k_VBFHtt13]*chanTheo[k_VBFHtt13] );


  chanEStatm[k_VBFHtt13]  =  0.0;
  chanESystm[k_VBFHtt13]  =  0.0;
  chanETotm[k_VBFHtt13]   =  sqrt(0.41*0.41*chanTheo[k_VBFHtt13]*chanTheo[k_VBFHtt13] - chanETheom[k_VBFHtt13]*chanETheom[k_VBFHtt13] );
  chanETotm[k_VBFHtt13]   =  sqrt(0.41*0.41*chanTheo[k_VBFHtt13]*chanTheo[k_VBFHtt13] );

  chanEStat[k_VBFHtt13] = (chanEStatp[k_VBFHtt13] +chanEStatm[k_VBFHtt13])/2.0;
  chanESyst[k_VBFHtt13] = (chanESystp[k_VBFHtt13] +chanESystm[k_VBFHtt13])/2.0;
  chanETot[k_VBFHtt13] = (chanETotp[k_VBFHtt13] +chanETotm[k_VBFHtt13])/2.0;
 



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
// From HIG-16-040

  chanMeasurement[k_VH13]  = "VH";
  chanLumi[k_VH13]  = "35.9 fb^{-1}";
// Need new xs numbers

  chanTheo[k_VH13] =   (1.373+0.8837 )* scale_;
chanETheop[k_VH13] =  sqrt(1.373*0.005*1.373*0.005 + 1.373*0.019*1.373*0.019)+sqrt(0.8837*0.038*0.8837*0.038 + 0.8837*0.016*0.8837*0.016);
  chanETheom[k_VH13] = sqrt(1.373*0.007*1.373*0.007 + 1.373*0.019*1.373*0.019)+sqrt(0.8831*0.038*0.8837*0.031 + 0.8837*0.016*0.8837*0.016);
  chanETheo[k_VH13] = (chanETheop[k_VH13] +chanETheom[k_VH13])/2.0;

  chanSigma[k_VH13]  =   2.29 * chanTheo[k_VH13]; 
  chanEStatp[k_VH13]  =   0.0;
  chanESystp[k_VH13]  =   0.0;
  chanETotp[k_VH13]   =  1.1 * chanTheo[k_VH13];


  chanEStatm[k_VH13]  =  0.0;
  chanESystm[k_VH13]  =  0.0;
  chanETotm[k_VH13]   =  0.9 * chanTheo[k_VH13];

  chanEStat[k_VH13] = (chanEStatp[k_VH13] +chanEStatm[k_VH13])/2.0;
  chanESyst[k_VH13] = (chanESystp[k_VH13] +chanESystm[k_VH13])/2.0;
  chanETot[k_VH13] = (chanETotp[k_VH13] +chanETotm[k_VH13])/2.0;




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
// https://twiki.cern.ch/twiki/bin/view/CMSPublic/TTHCombMoriond2016
// Replaced with ttH, H->bb at with 12.9 fb-1 which is better
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-16-038/index.html
// replace with 22 which has better sensativity
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-16-022/index.html
// replaced with multilepton which has better sensativity
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-17-004/index.html
  chanMeasurement[k_ttH13]  = "ttH";
  chanLumi[k_ttH13]  = "35.9 fb^{-1}";

  chanTheo[k_ttH13] =   0.5071 * scale_;
chanETheop[k_ttH13] =  sqrt(0.058*0.058 + 0.036*0.036)*chanTheo[k_ttH13];
chanETheom[k_ttH13] =  sqrt(0.092*0.092 + 0.036*0.036)*chanTheo[k_ttH13];
  chanETheo[k_ttH13] = (chanETheop[k_ttH13] +chanETheom[k_ttH13])/2.0;


  chanSigma[k_ttH13]  =   -1.5 * chanTheo[k_ttH13] * scale_; 
// Conveners prefer multilepon result
  chanSigma[k_ttH13]  =   -3.4 * chanTheo[k_ttH13] * scale_;
// Update to new multilepton result
  chanSigma[k_ttH13]  =   1.5 * chanTheo[k_ttH13] * scale_;

  chanEStatp[k_ttH13]  =   0.5 * chanTheo[k_ttH13] * scale_;
  chanESystp[k_ttH13]  =   0.0;
  chanETotp[k_ttH13]   =  0.5 * chanTheo[k_ttH13] * scale_;

  chanEStatm[k_ttH13]  =  0.5 * chanTheo[k_ttH13] * scale_;
  chanESystm[k_ttH13]  =  0.0;
  chanETotm[k_ttH13]   =  0.5 * chanTheo[k_ttH13] * scale_;

  chanEStat[k_ttH13] = (chanEStatp[k_ttH13] +chanEStatm[k_ttH13])/2.0;
  chanESyst[k_ttH13] = (chanESystp[k_ttH13] +chanESystm[k_ttH13])/2.0;
  chanETot[k_ttH13] = (chanETotp[k_ttH13] +chanETotm[k_ttH13])/2.0;

// HH production at 8 TeV
//http://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-13-032/index.html
// https://arxiv.org/abs/1603.06896 Phys. Rev. D 94, 052012 (2016)
// Best limit from hh->ggbb 

  


  chanMeasurement[k_HH8]  = "HH";
  chanLumi[k_HH8]  = "19.7 fb^{-1}";

chanTheo[k_HH8] =   10.0 * 0.001 * scale_;
chanETheop[k_HH8] =  1.4*0.001;
chanETheom[k_HH8] =  1.4*0.001;
  chanETheo[k_HH8] = (chanETheop[k_HH8] +chanETheom[k_HH8])/2.0;


  chanSigma[k_HH8]  =   -74 * chanTheo[k_HH8] * scale_; 
  chanEStatp[k_HH8]  =   0.0;
  chanESystp[k_HH8]  =   0.0;
  chanETotp[k_HH8]   =  0.0;

  chanEStatm[k_HH8]  =  0.0;
  chanESystm[k_HH8]  =  0.0;
  chanETotm[k_HH8]   =  0.0;

  chanEStat[k_HH8] = (chanEStatp[k_HH8] +chanEStatm[k_HH8])/2.0;
  chanESyst[k_HH8] = (chanESystp[k_HH8] +chanESystm[k_HH8])/2.0;
  chanETot[k_HH8] = (chanETotp[k_HH8] +chanETotm[k_HH8])/2.0;

// HH production at 13 TeV
//http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-16-032/index.html
// Best limit from H->ggbb  
// Replace with HIG-17-002.  Best limit from bbtt
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/HIG-17-002/index.html

  chanMeasurement[k_HH13]  = "HH";
  chanLumi[k_HH13]  = "35.9 fb^{-1}";

  chanTheo[k_HH13] =   35.49 * 0.001 * scale_;
  chanETheop[k_HH13] =  sqrt(4.3*4.3 + 2.1*2.1 + 2.3*2.3) * 0.001 * scale_;
  chanETheom[k_HH13] = sqrt(6.0*6.0 + 2.1*2.1 + 2.3*2.3) * 0.001 * scale_ ;
  chanETheo[k_HH13] = (chanETheop[k_HH13] +chanETheom[k_HH13])/2.0;


  chanSigma[k_HH13]  =   -7.90 * 0.001 * (1.0/0.00262) * scale_; 
  chanSigma[k_HH13]  =   - 28.0 * chanTheo[k_HH13]; 

  chanEStatp[k_HH13]  =   0.0;
  chanESystp[k_HH13]  =   0.0;
  chanETotp[k_HH13]   =  0.0;

  chanEStatm[k_HH13]  =  0.0;
  chanESystm[k_HH13]  =  0.0;
  chanETotm[k_HH13]   =  0.0;

  chanEStat[k_HH13] = (chanEStatp[k_HH13] +chanEStatm[k_HH13])/2.0;
  chanESyst[k_HH13] = (chanESystp[k_HH13] +chanESystm[k_HH13])/2.0;
  chanETot[k_HH13] = (chanETotp[k_HH13] +chanETotm[k_HH13])/2.0;




     for( size_t ii=0; ii<k_nChan; ii++ )
	{
ostringstream stream1, stream2, stream3;
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
	if (plotChan[ii])
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
  }
