

// standard versions 0 with verticle stacking of QCD results ,1 without verticle stacking, 2 QCD EWK only, 3 QCD rad only

enum { k_W=0,  k_W8, k_W13, k_W1jet, k_W2jet, k_W3jet, k_W4jet,  k_W1jetn, k_W2jetn, k_W3jetn, k_W4jetn, k_W5jetn, k_W6jetn, k_W1cjet, k_W2bjet, k_Z,  k_Z8,  k_Z13, k_Z1jet, k_Z2jet, k_Z3jet, k_Z4jet, k_Z1jetn, k_Z1jet8,k_Z2jetn,  k_Z2jet8,k_Z3jetn, k_Z3jet8, k_Z4jetn,  k_Z4jet8, k_Z5jet8, k_Z6jet8, k_Z7jet8, k_Z1bjet, k_Z2bjet, k_Wp, k_Wm, k_gg, k_ggnew, k_Wg, k_Zg, k_Zg8, k_WV, k_WW, k_WW8, k_WW1jet, k_WZ, k_WZ8, k_WZ13, k_WZ13fid,  k_ZZ, k_ZZ8,  k_ZZ13,  k_VBFW8, k_VBFZ, k_VBFZ8, k_exWW,  k_exWW8,  k_EWKWg8, k_SSWW8, k_EWKZg8, k_WVg,k_Zgg8, k_Wgg8,  k_tt,  k_tt8, k_tt13, k_tt1jet, k_tt1jet8, k_tt2jet, k_tt2jet8, k_tt3jet, k_tt3jet8, k_t, k_t8, k_t13, k_tW, k_tW8, k_tschan, k_tschan8, k_ttg, k_ttW8, k_ttZ, k_ttZ8, k_ttZ13, k_HZZ,  k_ggH, k_ggH8, k_VBFH, k_VBFH8, k_VH, k_VH8,  k_ttH, k_ttH8, k_incj, k_incg, k_gj, k_Hgg, k_Hgg8, k_nChan };




// Notes
// 7 and 8 TeV measurements are grouped if the ChanMeasurement short name is the same for both
// To add +jets measurements under the main measurement you need to set subChan to a number greater than 1.

bool big13TeV = false;
bool use13TeV = true;

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
  plotChan[k_WV]=false;
  plotChan[k_WW]=true;
  plotChan[k_WW8]=true;
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
  plotChan[k_EWKWg8]=true;
  plotChan[k_EWKZg8]=true;

  


  plotChan[k_VBFZ]=true;
  plotChan[k_VBFZ8]=true;
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

  plotChan[k_t]=true;
  plotChan[k_t8]=true;
  if (use13TeV) plotChan[k_t13]=true;
  plotChan[k_tschan]=true;
  plotChan[k_tschan8]=true;
  plotChan[k_tW]=true;
  plotChan[k_tW8]=true;
  plotChan[k_ttg]=true;
  plotChan[k_ttW8]=true;
  plotChan[k_ttZ]=true;
  plotChan[k_ttZ8]=true;
  if (use13TeV)  plotChan[k_ttZ13]=true;
  plotChan[k_ttg]=true;



  plotChan[k_ggH]=true;
  plotChan[k_VBFH]=true;
  plotChan[k_VH]=true;
  plotChan[k_ttH]=true;
  plotChan[k_ggH8]=true;
  plotChan[k_VBFH8]=true;
  plotChan[k_VH8]=true;
  plotChan[k_ttH8]=true;

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
  plotChan[k_WV]=false;
  plotChan[k_WW]=true;
  plotChan[k_WW8]=true;
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
  plotChan[k_EWKWg8]=true;
  plotChan[k_EWKZg8]=true;


  plotChan[k_VBFZ]=true;
  plotChan[k_VBFZ8]=true;
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

  plotChan[k_t]=true;
  plotChan[k_t8]=true;
  if (use13TeV) plotChan[k_t13]=true;
  plotChan[k_tschan]=true;
  plotChan[k_tschan8]=true;
  plotChan[k_tW]=true;
  plotChan[k_tW8]=true;
  plotChan[k_ttg]=true;
  plotChan[k_ttW8]=true;
  plotChan[k_ttZ]=true;
  plotChan[k_ttZ8]=true;
  if (use13TeV)  plotChan[k_ttZ13]=true;
  plotChan[k_ttg]=true;

  plotChan[k_ggH]=true;
  plotChan[k_VBFH]=true;
  plotChan[k_VH]=true;
  plotChan[k_ttH]=true;
  plotChan[k_ggH8]=true;
  plotChan[k_VBFH8]=true;
  plotChan[k_VH8]=true;
  plotChan[k_ttH8]=true;

  plotChan[k_HZZ]=false;

 }

if (version==3) {

  plotChan[k_W] = true;
  plotChan[k_W8] = true;
  if (use13TeV) plotChan[k_W13] = true;
  if (use13TeV) plotChan[k_Z13] = true;

  plotChan[k_Wp] = false;
  plotChan[k_Wm] = false;
  plotChan[k_W1jetn] = true;
  plotChan[k_W2jetn] = true;
  plotChan[k_W3jetn] = true;
  plotChan[k_W4jetn] = true;
  plotChan[k_W5jetn] = true;
  plotChan[k_W6jetn] = true;

  plotChan[k_W1cjet] = true;
  plotChan[k_W2bjet] = true;


  plotChan[k_Z] = true;
  plotChan[k_Z8] = true;
  plotChan[k_Z1jetn] = true;
  plotChan[k_Z2jetn] = true;
  plotChan[k_Z3jetn] = true;
  plotChan[k_Z4jetn] = true;
 
  plotChan[k_Z1jet8] = true;
  plotChan[k_Z2jet8] = true;
  plotChan[k_Z3jet8] = true;
  plotChan[k_Z4jet8] = true;
  plotChan[k_Z5jet8] = true;
  plotChan[k_Z6jet8] = true;
  plotChan[k_Z7jet8] = true;



  plotChan[k_Z1bjet] = true;
  plotChan[k_Z2bjet] = true;


  plotChan[k_gg]=false;
  plotChan[k_Wg]=false;
  plotChan[k_Zg]=false;
  plotChan[k_Zg8]=false;
  plotChan[k_WV]=false;
  plotChan[k_WW]=false;
  plotChan[k_WW8]=false;
  plotChan[k_WZ]=false;
  plotChan[k_WZ8]=false;
  if (use13TeV) plotChan[k_WZ13]=false;
  plotChan[k_ZZ]=false;
  plotChan[k_ZZ8]=false;
  if (use13TeV) plotChan[k_ZZ13]=false;

  plotChan[k_WVg]=false;
  plotChan[k_Wgg8]=false;
  plotChan[k_Zgg8]=false;


  plotChan[k_exWW]=false;
  plotChan[k_exWW8]=false;

  plotChan[k_SSWW8]=true;
  plotChan[k_EWKWg8]=true;
  plotChan[k_EWKZg8]=true;

  
  plotChan[k_VBFZ]=false;
  plotChan[k_VBFZ8]=false;
  plotChan[k_VBFW8]=false;

  plotChan[k_tt]=true;
  plotChan[k_tt8]=true;
  if (use13TeV) plotChan[k_tt13]=true;
  plotChan[k_tt1jet] = true;
  plotChan[k_tt2jet] = true;
  plotChan[k_tt3jet] = true;
  plotChan[k_tt1jet8] = true;
  plotChan[k_tt2jet8] = true;
  plotChan[k_tt3jet8] = true;

  plotChan[k_t]=false;
  plotChan[k_t8]=false;
  if (use13TeV) plotChan[k_t13]=true;
  plotChan[k_tschan]=false;
  plotChan[k_tschan8]=false;
  plotChan[k_tW]=false;
  plotChan[k_tW8]=false;
  plotChan[k_ttg]=true;
  plotChan[k_ttW8]=true;
  plotChan[k_ttZ]=false;
  plotChan[k_ttZ8]=false;
  if (use13TeV)  plotChan[k_ttZ13]=true;

  plotChan[k_ggH]=false;
  plotChan[k_VBFH]=false;
  plotChan[k_VH]=false;
  plotChan[k_ttH]=false;
  plotChan[k_ggH8]=true;
  plotChan[k_VBFH8]=true;
  plotChan[k_VH8]=true;
  plotChan[k_ttH8]=true;

  plotChan[k_HZZ]=false;

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




  subChan[k_tt1jet] = 6;
  subChan[k_tt2jet] = 6;
  subChan[k_tt3jet] = 6;
 
  subChan[k_tt1jet8] = 6;
  subChan[k_tt2jet8] = 6;
  subChan[k_tt3jet8] = 6;
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

// Ratio plot for dibosons
if (version==5) {

  plotChan[k_ggnew]=true;
  plotChan[k_Wg]=true;
  plotChan[k_Zg]=true;
  plotChan[k_Zg8]=true;
  plotChan[k_WV]=true;
  plotChan[k_WW]=true;
  plotChan[k_WW8]=true;
  plotChan[k_WZ]=true;
  plotChan[k_WZ8]=true;
  if (use13TeV) plotChan[k_WZ13]=true;
  if (use13TeV) plotChan[k_WZ13fid]=true;
  plotChan[k_ZZ]=true;
  plotChan[k_ZZ8]=true;
 if (use13TeV)  plotChan[k_ZZ13]=true;

 }

// EWK scattering measurements
if (version==6) {

  plotChan[k_VBFW8]=true;
  plotChan[k_VBFZ]=true;
  plotChan[k_VBFZ8]=true;
  plotChan[k_exWW]=true;
  plotChan[k_exWW8]=true;
  plotChan[k_SSWW8]=true;
  plotChan[k_EWKWg8]=true;
  plotChan[k_EWKZg8]=true;
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
// https://cds.cern.ch/record/1664744, CMS-PAS-SMP-12-023, number from AN 2012 331

  chanMeasurement[k_W1jetn] = "#geq1j";
  scale_ = 1.0;

  chanSigma[k_W1jetn]  = 480.0 * scale_;
  chanEStat[k_W1jetn]  =   19.0 * scale_;
  chanETot[k_W1jetn]   =   19.0 * scale_;
  chanESyst[k_W1jetn]  =  sqrt( chanETot[k_W1jetn]*chanETot[k_W1jetn] 
			       - 
			       chanEStat[k_W1jetn]*chanEStat[k_W1jetn]
			       );
chanTheo[k_W1jetn]  = 473.0 * scale_;
chanETheo[k_W1jetn] =  sqrt(29.0*29.0 )* scale_;
// + 1.8 - 2.1, +1.7 - 1.9

// new W + jetns 2 jetns  TeV
  chanMeasurement[k_W2jetn] = "#geq2j";

  chanSigma[k_W2jetn]  = 95.6 * scale_;
  chanEStat[k_W2jetn]  =  8.1 * scale_;
  chanETot[k_W2jetn]   =  8.1 * scale_;
  chanESyst[k_W2jetn]  =  sqrt( chanETot[k_W2jetn]*chanETot[k_W2jetn] 
			       - 
			       chanEStat[k_W2jetn]*chanEStat[k_W2jetn]
			       );
chanTheo[k_W2jetn]  = 94.6 * scale_;
chanETheo[k_W2jetn] = sqrt(6.65*6.65) * scale_;
// +2.1 - 1.5, _0.5 -0.6

// new W + jetns 3 jetn  TeV
  chanMeasurement[k_W3jetn] = "#geq3j";

  chanSigma[k_W3jetn]  = 16.6 * scale_;
  chanEStat[k_W3jetn]  =   2.15 * scale_;
  chanETot[k_W3jetn]   =  2.15 * scale_;
  chanESyst[k_W3jetn]  =  sqrt( chanETot[k_W3jetn]*chanETot[k_W3jetn] 
			       - 
			       chanEStat[k_W3jetn]*chanEStat[k_W3jetn]
			       );
chanTheo[k_W3jetn]  = 16.9 * scale_;
chanETheo[k_W3jetn] = sqrt(1.6*1.6) * scale_;
// +0.7 - 0.5, +0.1 - 0.2

// new W + jetns 4 jetn  TeV
  chanMeasurement[k_W4jetn] = "#geq4j";

  chanSigma[k_W4jetn]  = 2.93 * scale_;
  chanEStat[k_W4jetn]  =   0.445 * scale_;
  chanETot[k_W4jetn]   =  0.445 * scale_;
  chanESyst[k_W4jetn]  =  sqrt( chanETot[k_W4jetn]*chanETot[k_W4jetn] 
			       - 
			       chanEStat[k_W4jetn]*chanEStat[k_W4jetn]
			       );
 chanTheo[k_W4jetn]  = 2.60 * scale_;
chanETheo[k_W4jetn] = sqrt( 0.32*0.32) * scale_;
// +0.15 - 0.14, +0.03 - 0.03

// new W + jetns 5 jetn  TeV
  chanMeasurement[k_W5jetn] = "#geq5j";

  chanSigma[k_W5jetn]  = 0.451 * scale_;
  chanEStat[k_W5jetn]  =   0.102 * scale_;
  chanETot[k_W5jetn]   =  0.102 * scale_;
  chanESyst[k_W5jetn]  =  sqrt( chanETot[k_W5jetn]*chanETot[k_W5jetn] 
			       - 
			       chanEStat[k_W5jetn]*chanEStat[k_W5jetn]
			       );
  chanTheo[k_W5jetn]  = 0.546 * scale_;
chanETheo[k_W5jetn] = sqrt( 0.017*0.017) * scale_;
// +0.15 - 0.14, +0.03 - 0.03

// new W + jetns 6 jetn  TeV
  chanMeasurement[k_W6jetn] = "#geq6j";

  chanSigma[k_W6jetn]  = 0.068 * scale_;
  chanEStat[k_W6jetn]  =   0.0195 * scale_;
  chanETot[k_W6jetn]   =  0.0195 * scale_;
  chanESyst[k_W6jetn]  =  sqrt( chanETot[k_W6jetn]*chanETot[k_W6jetn] 
			       - 
			       chanEStat[k_W6jetn]*chanEStat[k_W6jetn]
			       );
  chanTheo[k_W6jetn]  = 0.0867 * scale_;
chanETheo[k_W6jetn] = sqrt( 0.002*0.002) * scale_;
// +0.15 - 0.14, +0.03 - 0.03

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
// Number from private communication with fabio.cossutti@cern.ch

  chanMeasurement[k_Z1jetn] = "#geq1j";
  scale_ = 1.0;

  chanSigma[k_Z1jetn]  = 61.3 * scale_;
  chanEStat[k_Z1jetn]  =   2.8 * scale_;
  chanETot[k_Z1jetn]   =   2.8 * scale_;
  chanESyst[k_Z1jetn]  =  sqrt( chanETot[k_Z1jetn]*chanETot[k_Z1jetn] 
			       - 
			       chanEStat[k_Z1jetn]*chanEStat[k_Z1jetn]
			       );
  chanTheo[k_Z1jetn]  = 63.5 * scale_;
  chanETheo[k_Z1jetn] =  sqrt(1.95*1.95 +1.8*1.8 )* scale_;
// + 1.8 - 2.1, +1.7 - 1.9

// new Z + jetns 2 jetns  TeV
  chanMeasurement[k_Z2jetn] = "#geq2j";

  chanSigma[k_Z2jetn]  = 12.9 * scale_;
  chanEStat[k_Z2jetn]  =  1.5 * scale_;
  chanETot[k_Z2jetn]   =  1.5 * scale_;
  chanESyst[k_Z2jetn]  =  sqrt( chanETot[k_Z2jetn]*chanETot[k_Z2jetn] 
			       - 
			       chanEStat[k_Z2jetn]*chanEStat[k_Z2jetn]
			       );
  chanTheo[k_Z2jetn]  = 11.5 * scale_;
chanETheo[k_Z2jetn] = sqrt(1.8*1.8 + 0.55*0.55) * scale_;
// +2.1 - 1.5, _0.5 -0.6

// new Z + jetns 3 jetn  TeV
  chanMeasurement[k_Z3jetn] = "#geq3j";

  chanSigma[k_Z3jetn]  = 2.5 * scale_;
  chanEStat[k_Z3jetn]  =   0.4 * scale_;
  chanETot[k_Z3jetn]   =  0.4 * scale_;
  chanESyst[k_Z3jetn]  =  sqrt( chanETot[k_Z3jetn]*chanETot[k_Z3jetn] 
			       - 
			       chanEStat[k_Z3jetn]*chanEStat[k_Z3jetn]
			       );
  chanTheo[k_Z3jetn]  = 2.1 * scale_;
chanETheo[k_Z3jetn] = sqrt(0.6*0.6 + 0.15*0.15) * scale_;
// +0.7 - 0.5, +0.1 - 0.2

// new Z + jetns 4 jetn  TeV
  chanMeasurement[k_Z4jetn] = "#geq4j";

  chanSigma[k_Z4jetn]  = 0.48 * scale_;
  chanEStat[k_Z4jetn]  =   0.08 * scale_;
  chanETot[k_Z4jetn]   =  0.08 * scale_;
  chanESyst[k_Z4jetn]  =  sqrt( chanETot[k_Z4jetn]*chanETot[k_Z4jetn] 
			       - 
			       chanEStat[k_Z4jetn]*chanEStat[k_Z4jetn]
			       );
  chanTheo[k_Z4jetn]  = 0.36 * scale_;
chanETheo[k_Z4jetn] = sqrt( 0.145*0.145 + 0.03*0.03) * scale_;
// +0.15 - 0.14, +0.03 - 0.03


// !!!!! include 8 TeV Z + jets.  Need numbers
// CMS PAS 13 007

// 1 jet exclusive
  chanMeasurement[k_Z1jet8] = "#geq1j";

  chanSigma[k_Z1jet8]  = 59.7 * scale_;
  chanEStat[k_Z1jet8]  =   0.0011 * chanSigma[k_Z1jet8] * scale_;
  chanETot[k_Z1jet8]   =   0.055 * chanSigma[k_Z1jet8] * scale_;
  chanESyst[k_Z1jet8]  =  sqrt( chanETot[k_Z1jet8]*chanETot[k_Z1jet8] 
			       - 
			       chanEStat[k_Z1jet8]*chanEStat[k_Z1jet8]
			       );
  chanTheo[k_Z1jet8]  = 59.7 * scale_;
  chanETheo[k_Z1jet8] =  sqrt(1.0 )* scale_;

// 2 jet exclusive
  chanMeasurement[k_Z2jet8] = "#geq2j";
  scale_ = 1.0;

  chanSigma[k_Z2jet8]  = 12.51 * scale_;
  chanEStat[k_Z2jet8]  =   0.0024 * chanSigma[k_Z2jet8] * scale_;
  chanETot[k_Z2jet8]   =   0.069 * chanSigma[k_Z2jet8] * scale_;
  chanESyst[k_Z2jet8]  =  sqrt( chanETot[k_Z2jet8]*chanETot[k_Z2jet8] 
			       - 
			       chanEStat[k_Z2jet8]*chanEStat[k_Z2jet8]
			       );
  chanTheo[k_Z2jet8]  = 12.51 * scale_;
  chanETheo[k_Z2jet8] =  sqrt(0.2 )* scale_;



// 3 jet exclusive
  chanMeasurement[k_Z3jet8] = "#geq3j";
  scale_ = 1.0;

  chanSigma[k_Z3jet8]  = 2.43 * scale_;
  chanEStat[k_Z3jet8]  =   0.0058 * chanSigma[k_Z3jet8] * scale_;
  chanETot[k_Z3jet8]   =   0.090 * chanSigma[k_Z3jet8] * scale_;
  chanESyst[k_Z3jet8]  =  sqrt( chanETot[k_Z3jet8]*chanETot[k_Z3jet8] 
			       - 
			       chanEStat[k_Z3jet8]*chanEStat[k_Z3jet8]
			       );
  chanTheo[k_Z3jet8]  = 2.43 * scale_;
  chanETheo[k_Z3jet8] =  sqrt(0.05 )* scale_;

// 4 jet exclusive
  chanMeasurement[k_Z4jet8] = "#geq4j";
  scale_ = 1.0;

  chanSigma[k_Z4jet8]  = 0.463 * scale_;
  chanEStat[k_Z4jet8]  =   0.013 * chanSigma[k_Z4jet8] * scale_;
  chanETot[k_Z4jet8]   =   0.011 * chanSigma[k_Z4jet8] * scale_;
  chanESyst[k_Z4jet8]  =  sqrt( chanETot[k_Z4jet8]*chanETot[k_Z4jet8] 
			       - 
			       chanEStat[k_Z4jet8]*chanEStat[k_Z4jet8]
			       );
  chanTheo[k_Z4jet8]  = 0.463 * scale_;
  chanETheo[k_Z4jet8] =  sqrt(0.01 )* scale_;

// 5 jet exclusive
  chanMeasurement[k_Z5jet8] = "#geq5j";
  scale_ = 1.0;

  chanSigma[k_Z5jet8]  = 0.088 * scale_;
  chanEStat[k_Z5jet8]  =   0.030 * chanSigma[k_Z5jet8] * scale_;
  chanETot[k_Z5jet8]   =   0.015 * chanSigma[k_Z5jet8] * scale_;
  chanESyst[k_Z5jet8]  =  sqrt( chanETot[k_Z5jet8]*chanETot[k_Z5jet8] 
			       - 
			       chanEStat[k_Z5jet8]*chanEStat[k_Z5jet8]
			       );
  chanTheo[k_Z5jet8]  = 0.088 * scale_;
  chanETheo[k_Z5jet8] =  sqrt(0.002 )* scale_;

// 6 jet exclusive
  chanMeasurement[k_Z6jet8] = "#geq6j";
  scale_ = 1.0;

  chanSigma[k_Z6jet8]  = 0.0143 * scale_;
  chanEStat[k_Z6jet8]  =   0.0075 * chanSigma[k_Z6jet8] * scale_;
  chanETot[k_Z6jet8]   =   0.021 * chanSigma[k_Z6jet8] * scale_;
  chanESyst[k_Z6jet8]  =  sqrt( chanETot[k_Z6jet8]*chanETot[k_Z6jet8] 
			       - 
			       chanEStat[k_Z6jet8]*chanEStat[k_Z6jet8]
			       );
  chanTheo[k_Z6jet8]  = 0.0143 * scale_;
  chanETheo[k_Z6jet8] =  sqrt(0.0005 )* scale_;

// 7 jet exclusive
  chanMeasurement[k_Z7jet8] = "#geq7j";
  scale_ = 1.0;

  chanSigma[k_Z7jet8]  = 0.00234 * scale_;
  chanEStat[k_Z7jet8]  =   0.019 * chanSigma[k_Z7jet8] * scale_;
  chanETot[k_Z7jet8]   =   0.027 * chanSigma[k_Z7jet8] * scale_;
  chanESyst[k_Z7jet8]  =  sqrt( chanETot[k_Z7jet8]*chanETot[k_Z7jet8] 
			       - 
			       chanEStat[k_Z7jet8]*chanEStat[k_Z7jet8]
			       );
  chanTheo[k_Z7jet8]  = 0.00234 * scale_;
  chanETheo[k_Z7jet8] =  sqrt(0.0001 )* scale_;




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



scale_ = 1.;

// VBF Z production, EWK Z produciton to ll
 chanMeasurement[k_VBFZ]     = "#splitline{EW}{qqZ}";
if (version == 6) chanMeasurement[k_VBFZ]     = "#splitline{EWK qq(Z)}{(Z) #rightarrow ll}";

  chanSigma[k_VBFZ]  =   0.154 * scale_; 
  chanEStatp[k_VBFZ]  =   0.024 * scale_;
  chanESystp[k_VBFZ]  =   0.0534 * scale_;
  chanETotp[k_VBFZ]   =  sqrt( 
			   chanEStatp[k_VBFZ]*chanEStatp[k_VBFZ]
			   +
			   chanESystp[k_VBFZ]*chanESystp[k_VBFZ]
			    );

  chanEStatm[k_VBFZ]  =   0.024 * scale_;
  chanESystm[k_VBFZ]  =   0.0534 * scale_;
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
// http://arxiv.org/abs/1410.3153 new!!!!!
 chanMeasurement[k_VBFZ8]     = "#splitline{EW}{qqZ}";
if (version == 6) chanMeasurement[k_VBFZ8]     = "#splitline{EWK qq(Z)}{(Z) #rightarrow ll}";

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



// EWK W 8 TeV 19.3 fb-1
//  new!!!!!
 chanMeasurement[k_VBFW8]     = "#splitline{EW}{qqW}";
if (version == 6) chanMeasurement[k_VBFW8]     = "#splitline{EWK qqW}{W #rightarrow l#nu}";
  chanSigma[k_VBFW8]  =   0.42 * scale_; 
  chanEStatp[k_VBFW8]  =   0.04 * scale_;
  chanESystp[k_VBFW8]  =   0.091 * scale_;
  chanETotp[k_VBFW8]   =  sqrt( 
			   chanEStatp[k_VBFW8]*chanEStatp[k_VBFW8]
			   +
			   chanESystp[k_VBFW8]*chanESystp[k_VBFW8]
			    );

  chanEStatm[k_VBFW8]  =   0.04 * scale_;
  chanESystm[k_VBFW8]  =   0.091 * scale_;
  chanETotm[k_VBFW8]   =  sqrt( 
			   chanEStatm[k_VBFW8]*chanEStatm[k_VBFW8]
			   +
			   chanESystm[k_VBFW8]*chanESystm[k_VBFW8]
			    );
  chanEStat[k_VBFW8] = (chanEStatp[k_VBFW8] +chanEStatm[k_VBFW8])/2.0;
  chanESyst[k_VBFW8] = (chanESystp[k_VBFW8] +chanESystm[k_VBFW8])/2.0;
  chanETot[k_VBFW8] = (chanETotp[k_VBFW8] +chanETotm[k_VBFW8])/2.0;
 


  chanTheo[k_VBFW8] =   0.50 * scale_;
  chanETheop[k_VBFW8] =  0.028 * scale_;
  chanETheom[k_VBFW8] =  0.028 * scale_;
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
chanMeasurement[k_ggnew]     = "#gamma#gamma, #scale[0.70]{(NNLO th.)}";
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

  chanMeasurement[k_tt] = "tt";
  chanLumi[k_tt] = "";

  chanSigma[k_tt]  =   161.9 * scale_; 
  chanEStatp[k_tt]  =   6.7 * scale_;
  chanESystp[k_tt]  =   0.0 * scale_;
  chanETotp[k_tt]   =  sqrt( 
			   chanEStatp[k_tt]*chanEStatp[k_tt]
			   +
			   chanESystp[k_tt]*chanESystp[k_tt]
			    );

  chanEStatm[k_tt]  =   6.7 * scale_;
  chanESystm[k_tt]  =   0.0 * scale_;
  chanETotm[k_tt]   =  sqrt( 
			   chanEStatm[k_tt]*chanEStatm[k_tt]
			   +
			   chanESystm[k_tt]*chanESystm[k_tt]
			    );
  chanEStat[k_tt] = (chanEStatp[k_tt] +chanEStatm[k_tt])/2.0;
  chanESyst[k_tt] = (chanESystp[k_tt] +chanESystm[k_tt])/2.0;
  chanETot[k_tt] = (chanETotp[k_tt] +chanETotm[k_tt])/2.0;
 


  chanTheo[k_tt] =   172.0 * scale_;
  chanETheop[k_tt] =  6.6 * scale_;
  chanETheom[k_tt] =  7.41 * scale_;
  chanETheo[k_tt] = (chanETheop[k_tt] +chanETheom[k_tt])/2.0;

// ttbar 8 TeV
// !!!!!????? to be replaced http://cds.cern.ch/record/1640470 
  chanMeasurement[k_tt8] = "tt";
  chanLumi[k_tt8] = "";

  chanSigma[k_tt8]  =   227.0 * scale_; 
  chanEStatp[k_tt8]  =   15.1 * scale_;
  chanESystp[k_tt8]  =   0.0 * scale_;
  chanETotp[k_tt8]   =  sqrt( 
			   chanEStatp[k_tt8]*chanEStatp[k_tt8]
			   +
			   chanESystp[k_tt8]*chanESystp[k_tt8]
			    );

  chanEStatm[k_tt8]  =   15.1 * scale_;
  chanESystm[k_tt8]  =   0.0 * scale_;
  chanETotm[k_tt8]   =  sqrt( 
			   chanEStatm[k_tt8]*chanEStatm[k_tt8]
			   +
			   chanESystm[k_tt8]*chanESystm[k_tt8]
			    );
  chanEStat[k_tt8] = (chanEStatp[k_tt8] +chanEStatm[k_tt8])/2.0;
  chanESyst[k_tt8] = (chanESystp[k_tt8] +chanESystm[k_tt8])/2.0;
  chanETot[k_tt8] = (chanETotp[k_tt8] +chanETotm[k_tt8])/2.0;
 


  chanTheo[k_tt8] =   245.8 * scale_;
  chanETheop[k_tt8] =  9.0 * scale_;
  chanETheom[k_tt8] =  10.3 * scale_;
  chanETheo[k_tt8] = (chanETheop[k_tt8] +chanETheom[k_tt8])/2.0;

// ttbar 13 TeV
// !!!!! http://arxiv.org/abs/1510.05302 ????? to be replaced with prel results?
  if (use13TeV) chanMeasurement[k_tt13] = "tt";
if (big13TeV) chanMeasurement[k_tt13]    =  "#splitline{   tt}{13Tev}";
  chanLumi[k_tt13] = "";

  chanSigma[k_tt13]  =   769.0 * scale_; 
  chanEStatp[k_tt13]  =   55.0 * scale_;
chanESystp[k_tt13]  =   sqrt(60.0*60.0 + 92.0*92.0) * scale_;
  chanETotp[k_tt13]   =  sqrt( 
			   chanEStatp[k_tt13]*chanEStatp[k_tt13]
			   +
			   chanESystp[k_tt13]*chanESystp[k_tt13]
			    );

  chanEStatm[k_tt13]  =   55.0 * scale_;
  chanESystm[k_tt13]  =    sqrt(60.0*60.0 + 92.0*92.0) * scale_;
  chanETotm[k_tt13]   =  sqrt( 
			   chanEStatm[k_tt13]*chanEStatm[k_tt13]
			   +
			   chanESystm[k_tt13]*chanESystm[k_tt13]
			    );
  chanEStat[k_tt13] = (chanEStatp[k_tt13] +chanEStatm[k_tt13])/2.0;
  chanESyst[k_tt13] = (chanESystp[k_tt13] +chanESystm[k_tt13])/2.0;
  chanETot[k_tt13] = (chanETotp[k_tt13] +chanETotm[k_tt13])/2.0;
 


  chanTheo[k_tt13] =   832.0 * scale_;
chanETheop[k_tt13] =  sqrt(20.0*20.0+35.0*35.0) * scale_;
  chanETheom[k_tt13] = sqrt(29.0*29.0+35.0*35.0) * scale_;
  chanETheo[k_tt13] = (chanETheop[k_tt13] +chanETheom[k_tt13])/2.0;


// top with jets
// !!!!!????? to be replaced http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-12-018/index.html


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



// single top t chan only
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

// single top CMS-TOP-12-038 http://arxiv.org/abs/1403.7366
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


// single top http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-15-004/index.html
  if (use13TeV) chanMeasurement[k_t13] = "t_{t-ch}";
if (big13TeV) chanMeasurement[k_t13]    =  "#splitline{  t_{t-ch}}{13Tev}";
  chanLumi[k_t13] = "";

  chanSigma[k_t13]  =   274. * scale_; 
  chanEStatp[k_t13]  =   98. * scale_;
chanESystp[k_t13]  =   sqrt(52.*52.+33.*33.) * scale_;
  chanETotp[k_t13]   =  sqrt( 
			   chanEStatp[k_t13]*chanEStatp[k_t13]
			   +
			   chanESystp[k_t13]*chanESystp[k_t13]
			    );

  chanEStatm[k_t13]  =   98. * scale_;
  chanESystm[k_t13]  =   sqrt(52.*52.+33.*33.) * scale_;
  chanETotm[k_t13]   =  sqrt( 
			   chanEStatm[k_t13]*chanEStatm[k_t13]
			   +
			   chanESystm[k_t13]*chanESystm[k_t13]
			    );
  chanEStat[k_t13] = (chanEStatp[k_t13] +chanEStatm[k_t13])/2.0;
  chanESyst[k_t13] = (chanESystp[k_t13] +chanESystm[k_t13])/2.0;
  chanETot[k_t13] = (chanETotp[k_t13] +chanETotm[k_t13])/2.0;
 


  chanTheo[k_t13] =   214.5 * scale_;
chanETheop[k_t13] =  sqrt(0.7*0.7 + 0.3*0.3) * scale_;
chanETheom[k_t13] =  sqrt(0.6*0.6 +0.6*0.6) * scale_;
  chanETheo[k_t13] = (chanETheop[k_t13] +chanETheom[k_t13])/2.0;



// single top s chan only, 8 TeV
// https://cds.cern.ch/record/1633190/ CMS-PAS-TOP-13-009
// http://cms-results.web.cern.ch/cms-results/public-results/publications/TOP-13-009/index.html
// http://arxiv.org/abs/1603.02555 Submitted to J. High Energy Phys. 

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
  chanETheop[k_tW] =  1.3 * scale_;
  chanETheom[k_tW] =  1.3 * scale_;
  chanETheo[k_tW] = (chanETheop[k_tW] +chanETheom[k_tW])/2.0;

// tW 8 TeV CMS-TOP-12-040 http://arxiv.org/abs/1401.2942 Sub to PRL
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



// ttgamma, CMS TOP-13-011
  chanMeasurement[k_ttg] = "tt#gamma";
  chanLumi[k_ttg] = "";

  chanSigma[k_ttg]  =   2.4 * scale_; 
  chanEStatp[k_ttg]  =   0.6 * scale_;
  chanESystp[k_ttg]  =   0.0 * scale_;
  chanETotp[k_ttg]   =  sqrt( 
			   chanEStatp[k_ttg]*chanEStatp[k_ttg]
			   +
			   chanESystp[k_ttg]*chanESystp[k_ttg]
			    );

  chanEStatm[k_ttg]  =   0.6 * scale_;
  chanESystm[k_ttg]  =   0.0 * scale_;
  chanETotm[k_ttg]   =  sqrt( 
			   chanEStatm[k_ttg]*chanEStatm[k_ttg]
			   +
			   chanESystm[k_ttg]*chanESystm[k_ttg]
			    );
  chanEStat[k_ttg] = (chanEStatp[k_ttg] +chanEStatm[k_ttg])/2.0;
  chanESyst[k_ttg] = (chanESystp[k_ttg] +chanESystm[k_ttg])/2.0;
  chanETot[k_ttg] = (chanETotp[k_ttg] +chanETotm[k_ttg])/2.0;
 


  chanTheo[k_ttg] =   1.8 * scale_;
  chanETheop[k_ttg] =  0.5 * scale_;
  chanETheom[k_ttg] =  0.5 * scale_;
  chanETheo[k_ttg] = (chanETheop[k_ttg] +chanETheom[k_ttg])/2.0;





// ttW8, W only CMS PAS TOP 14 021
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

// ttZ
// http://arxiv.org/abs/1406.7830 
chanMeasurement[k_ttZ8] = "ttZ";
   chanLumi[k_ttZ8] = "";


  chanSigma[k_ttZ8]  =   0.200 * scale_; 
  chanEStatp[k_ttZ8]  =   0.08 * scale_;
  chanESystp[k_ttZ8]  =   0.04 * scale_;
  chanETotp[k_ttZ8]   =  sqrt( 
			   chanEStatp[k_ttZ8]*chanEStatp[k_ttZ8]
			   +
			   chanESystp[k_ttZ8]*chanESystp[k_ttZ8]
			    );

  chanEStatm[k_ttZ8]  =   0.070 * scale_;
  chanESystm[k_ttZ8]  =   0.030 * scale_;
  chanETotm[k_ttZ8]   =  sqrt( 
			   chanEStatm[k_ttZ8]*chanEStatm[k_ttZ8]
			   +
			   chanESystm[k_ttZ8]*chanESystm[k_ttZ8]
			    );
  chanEStat[k_ttZ8] = (chanEStatp[k_ttZ8] +chanEStatm[k_ttZ8])/2.0;
  chanESyst[k_ttZ8] = (chanESystp[k_ttZ8] +chanESystm[k_ttZ8])/2.0;
  chanETot[k_ttZ8] = (chanETotp[k_ttZ8] +chanETotm[k_ttZ8])/2.0;
 


  chanTheo[k_ttZ8] =   0.197 * scale_;
  chanETheop[k_ttZ8] = 0.022 * scale_;
  chanETheom[k_ttZ8] =  0.025 * scale_;
  chanETheo[k_ttZ8] = (chanETheop[k_ttZ8] +chanETheom[k_ttZ8])/2.0;


// ttZ !!!!! new CMS PAS 14 021 
chanMeasurement[k_ttZ8] = "ttZ";
   chanLumi[k_ttZ8] = "";


  chanSigma[k_ttZ8]  =   0.257 * scale_; 
  chanEStatp[k_ttZ8]  =   0.065 * scale_;
  chanESystp[k_ttZ8]  =   0.0 * scale_;
  chanETotp[k_ttZ8]   =  sqrt( 
			   chanEStatp[k_ttZ8]*chanEStatp[k_ttZ8]
			   +
			   chanESystp[k_ttZ8]*chanESystp[k_ttZ8]
			    );

  chanEStatm[k_ttZ8]  =   0.052 * scale_;
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
  chanETheop[k_ttZ8] = 0.022 * scale_;
  chanETheom[k_ttZ8] =  0.025 * scale_;
  chanETheo[k_ttZ8] = (chanETheop[k_ttZ8] +chanETheom[k_ttZ8])/2.0;


// ttZ 13 TeV
// http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/TOP-16-009/index.html
chanMeasurement[k_ttZ13] = "ttZ";
   chanLumi[k_ttZ13] = "2.7";


  chanSigma[k_ttZ13]  =   1.065 * scale_; 
  chanEStatp[k_ttZ13]  =   0.352 * scale_;
  chanESystp[k_ttZ13]  =   0.313 * scale_;
  chanETotp[k_ttZ13]   =  sqrt( 
			   chanEStatp[k_ttZ13]*chanEStatp[k_ttZ13]
			   +
			   chanESystp[k_ttZ13]*chanESystp[k_ttZ13]
			    );

  chanEStatm[k_ttZ13]  =   0.168 * scale_;
  chanESystm[k_ttZ13]  =   0.142 * scale_;
  chanETotm[k_ttZ13]   =  sqrt( 
			   chanEStatm[k_ttZ13]*chanEStatm[k_ttZ13]
			   +
			   chanESystm[k_ttZ13]*chanESystm[k_ttZ13]
			    );
  chanEStat[k_ttZ13] = (chanEStatp[k_ttZ13] +chanEStatm[k_ttZ13])/2.0;
  chanESyst[k_ttZ13] = (chanESystp[k_ttZ13] +chanESystm[k_ttZ13])/2.0;
  chanETot[k_ttZ13] = (chanETotp[k_ttZ13] +chanETotm[k_ttZ13])/2.0;
 


  chanTheo[k_ttZ13] =   0.839 * scale_;
chanETheop[k_ttZ13] = sqrt(0.080*0.080+0.025*0.025+0.025*0.025) * scale_;
  chanETheom[k_ttZ13] =  sqrt(0.092*0.092+0.025*0.025+0.025*0.025) * scale_;
  chanETheo[k_ttZ13] = (chanETheop[k_ttZ13] +chanETheom[k_ttZ13])/2.0;




// diboson results

// Wgamma
//chanMeasurement[k_Wg] = "W#gamma), #scale[0.7]{E_{T}^{ #gamma} > 15}";
  chanMeasurement[k_Wg] = "W#gamma";
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

// WW production
  chanMeasurement[k_WW] = "WW";
  chanLumi[k_WW]= "4.9 fb^{-1}";

  chanSigma[k_WW]  =  52.4 * scale_; 
  chanEStat[k_WW]  =   2.0 * scale_;
  chanESyst[k_WW]  =   4.657 * scale_;
  chanETot[k_WW]   =  sqrt( 
			   chanEStat[k_WW]*chanEStat[k_WW]
			   +
			   chanESyst[k_WW]*chanESyst[k_WW]
			    );
  chanTheo[k_WW] =  47.0 * scale_;
  chanETheo[k_WW] =  2.0 * scale_;

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
  if (version == 5 )chanMeasurement[k_WW8]= "WW, #scale[0.70]{(NNLO th.)}";
  chanLumi[k_WW8]= "19.4 fb^{-1}";

  chanSigma[k_WW8]  =  60.1 * scale_; 
  chanEStat[k_WW8]  =   0.9 * scale_;
chanESyst[k_WW8]  =   sqrt(3.2*3.2 + 3.1*3.1 + 1.6*1.6) * scale_;
  chanETot[k_WW8]   =  sqrt( 
			   chanEStat[k_WW8]*chanEStat[k_WW8]
			   +
			   chanESyst[k_WW8]*chanESyst[k_WW8]
			    );
  chanTheo[k_WW8] =  59.8 * scale_;
  chanETheo[k_WW8] =  1.2 * scale_;
// theo +1.3 -1.1



// WZ
  chanMeasurement[k_WZ] = "WZ";
  chanLumi[k_WZ] = "4.9 fb^{-1}";

// 1.1 fb-1 version
//  chanSigma[k_WZ]  =  17.0 * scale_; 
//  chanEStat[k_WZ]  =   2.4 * scale_;
//  chanESyst[k_WZ]  =   1.487 * scale_;

  chanSigma[k_WZ]  =  20.76 * scale_; 
  chanEStat[k_WZ]  =   1.32 * scale_;
  chanESyst[k_WZ]  =   1.2200 * scale_;
  chanETot[k_WZ]   =  sqrt( 
			   chanEStat[k_WZ]*chanEStat[k_WZ]
			   +
			   chanESyst[k_WZ]*chanESyst[k_WZ]
			    );
  chanTheo[k_WZ] =  17.8 * scale_;
  chanETheo[k_WZ] =  0.6 * scale_;

// WZ 8 TeV
  chanMeasurement[k_WZ8] = "WZ";
  chanLumi[k_WZ8] = "19.6 fb^{-1}";

  chanSigma[k_WZ8]  =  24.61 * scale_; 
  chanEStat[k_WZ8]  =   0.76 * scale_;
  chanESyst[k_WZ8]  =   1.5631 * scale_;
  chanETot[k_WZ8]   =  sqrt( 
			   chanEStat[k_WZ]*chanEStat[k_WZ]
			   +
			   chanESyst[k_WZ]*chanESyst[k_WZ]
			    );
  chanTheo[k_WZ8] =  21.91 * scale_;
  chanETheo[k_WZ8] =  1.025 * scale_;

// WZ 13 TeV
  if (use13TeV) chanMeasurement[k_WZ13] = "WZ";
if (big13TeV) chanMeasurement[k_WZ13]    =  "#splitline{  WZ}{13Tev}";
  chanLumi[k_WZ13] = "2.3 fb^{-1}";

  chanSigma[k_WZ13]  =  40.9 * scale_; 
  chanEStatp[k_WZ13]  =   3.4 * scale_;
  chanEStatm[k_WZ13]  =   3.4 * scale_;
chanEStat[k_WZ13]  = ( chanEStatp[k_WZ13] + chanEStatm[k_WZ13])/2.0;


  chanESystp[k_WZ13]  =    sqrt( 3.1*3.1+0.4*0.4+1.3*1.3)* scale_;
  chanESystm[k_WZ13]  =    sqrt( 3.3*3.3+0.4*0.4+1.3*1.3)* scale_;
  chanESyst[k_WZ13]  = ( chanESystp[k_WZ13] + chanESystm[k_WZ13])/2.0;
 

  chanETot[k_WZ13]   =  sqrt( 
			   chanEStat[k_WZ13]*chanEStat[k_WZ13]
			   +
			   chanESyst[k_WZ13]*chanESyst[k_WZ13]
			    );
  chanTheo[k_WZ13] =  42.6 * scale_;
  chanETheo[k_WZ13] =  1.2 * scale_;
// +1.6-0.8

// WZ 13 TeV fiducial
  if (use13TeV) chanMeasurement[k_WZ13fid] = "WZ";
if (big13TeV) chanMeasurement[k_WZ13fid]    =  "#splitline{  WZ}{13Tev}";
  chanLumi[k_WZ13fid] = "2.3 fb^{-1}";

  chanSigma[k_WZ13fid]  =  0.265 * scale_; 
  chanEStatp[k_WZ13fid]  =   0.022 * scale_;
  chanEStatm[k_WZ13fid]  =   0.022 * scale_;
chanEStat[k_WZ13fid]  = ( chanEStatp[k_WZ13fid] + chanEStatm[k_WZ13fid])/2.0;


  chanESystp[k_WZ13fid]  =    sqrt( 0.020*0.020+0.009*0.009)* scale_;
  chanESystm[k_WZ13fid]  =    sqrt( 0.022*0.022+0.009*0.009 )* scale_;
  chanESyst[k_WZ13fid]  = ( chanESystp[k_WZ13fid] + chanESystm[k_WZ13fid])/2.0;
 

  chanETot[k_WZ13fid]   =  sqrt( 
			   chanEStat[k_WZ13fid]*chanEStat[k_WZ13fid]
			   +
			   chanESyst[k_WZ13fid]*chanESyst[k_WZ13fid]
			    );
  chanTheo[k_WZ13fid] =  0.274 * scale_;
  chanETheo[k_WZ13fid] =  0.0105 * scale_;
// +1.6-0.8

// ZZ
  chanMeasurement[k_ZZ] = "ZZ";
  chanLumi[k_ZZ] = "4.9 fb^{-1}";

  chanSigma[k_ZZ]  =   6.24 * scale_; 
  chanEStat[k_ZZ]  =   0.86 * scale_;
  chanESyst[k_ZZ]  =   0.4332 * scale_;
  chanETot[k_ZZ]   =  sqrt( 
			   chanEStat[k_ZZ]*chanEStat[k_ZZ]
			   +
			   chanESyst[k_ZZ]*chanESyst[k_ZZ]
			    );
  chanTheo[k_ZZ] =   6.3 * scale_;
  chanETheo[k_ZZ] =  0.4 * scale_;
// exp +0.86-0.80, +0.41-0.32, +-0.14
// symetric seems good


// 5.3 fb-1 result  
//chanSigma[k_ZZ8]  =   8.4 * scale_; 
//  chanEStat[k_ZZ8]  =   1.0 * scale_;
//  chanESyst[k_ZZ8]  =   0.8062 * scale_;


// ZZ 8 TeV
// Update refernce to http://arxiv.org/abs/1406.0113 !!!!!new
  chanMeasurement[k_ZZ8] = "ZZ";
  chanLumi[k_ZZ8]= "19.6 fb^{-1}";

  chanSigma[k_ZZ8]  =   7.7 * scale_; 
  chanEStat[k_ZZ8]  =   0.5 * scale_;
  chanESyst[k_ZZ8]  =   0.6344 * scale_;
  chanETot[k_ZZ8]   =  sqrt( 
			   chanEStat[k_ZZ8]*chanEStat[k_ZZ8]
			   +
			   chanESyst[k_ZZ8]*chanESyst[k_ZZ8]
			    );
  chanTheo[k_ZZ8] =   7.7 * scale_;
  chanETheo[k_ZZ8] =  0.6 * scale_;

// ZZ 13 TeV
  if (use13TeV) chanMeasurement[k_ZZ13] = "ZZ";
if (big13TeV) chanMeasurement[k_ZZ13]    =  "#splitline{  ZZ}{13Tev}";
  chanLumi[k_ZZ13] = "1.34 fb^{-1}";

  chanSigma[k_ZZ13]  =  16.7 * scale_; 
  chanEStatp[k_ZZ13]  =   2.9 * scale_;
  chanEStatm[k_ZZ13]  =   2.6 * scale_;
  chanEStat[k_ZZ13]  = ( chanEStatp[k_ZZ13] + chanEStatm[k_ZZ13])/2.0;


  chanESystp[k_ZZ13]  =    sqrt( 0.7*0.7+0.3*0.3+0.8*0.8)* scale_;
  chanESystm[k_ZZ13]  =    sqrt( 0.5*0.5+0.3*0.3+0.8*0.8)* scale_;
  chanESyst[k_ZZ13]  = ( chanESystp[k_ZZ13] + chanESystm[k_ZZ13])/2.0;




  chanETot[k_ZZ13]   =  sqrt( 
			   chanEStat[k_ZZ13]*chanEStat[k_ZZ13]
			   +
			   chanESyst[k_ZZ13]*chanESyst[k_ZZ13]
			    );
  chanTheo[k_ZZ13] =  16.7 * scale_;
  chanETheop[k_ZZ13] =  0.7 * scale_;
  chanETheom[k_ZZ13] =  0.5 * scale_;
  chanETheo[k_ZZ13]   =  sqrt( 
			   chanETheop[k_ZZ13]*chanETheop[k_ZZ13]
			   +
			   chanETheom[k_ZZ13]*chanETheom[k_ZZ13]
			    );

  scale_ = 1.;

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

// EWK Wg http://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-14-011/index.html

  scale_=1/1000.0;

  chanMeasurement[k_EWKWg8] = "#splitline{EW}{W#gammajj}";

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

  chanSigma[k_Wgg8]  =  6.0 * scale_; 
  chanEStatp[k_Wgg8]  =   1.8 * scale_;
  chanEStatm[k_Wgg8]  =   1.8 * scale_;
  chanEStat[k_Wgg8]  = ( chanEStatp[k_Wgg8] + chanEStatm[k_Wgg8])/2.0;


  chanESystp[k_Wgg8]  =    sqrt( 2.3*2.3+0.2*0.2)* scale_;
  chanESystm[k_Wgg8]  =    sqrt( 2.3*2.3+0.2*0.2)* scale_;
  chanESyst[k_Wgg8]  = ( chanESystp[k_Wgg8] + chanESystm[k_Wgg8])/2.0;




  chanETot[k_Wgg8]   =  sqrt( 
			   chanEStat[k_Wgg8]*chanEStat[k_Wgg8]
			   +
			   chanESyst[k_Wgg8]*chanESyst[k_Wgg8]
			    );
  chanTheo[k_Wgg8] =  4.76 * scale_;
  chanETheop[k_Wgg8] =  0.53 * scale_;
  chanETheom[k_Wgg8] =  0.53 * scale_;
  chanETheo[k_Wgg8]   =  sqrt( 
			   chanETheop[k_Wgg8]*chanETheop[k_Wgg8]
			   +
			   chanETheom[k_Wgg8]*chanETheom[k_Wgg8]
			    );

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
  chanETheo[k_Zgg8]   =  sqrt( 
			   chanETheop[k_Zgg8]*chanETheop[k_Zgg8]
			   +
			   chanETheom[k_Zgg8]*chanETheom[k_Zgg8]
			    );

  scale_ = 1.;



// Exclusive gg -> WW production
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

  chanMeasurement[k_exWW8] = "#splitline{#gamma#gamma#rightarrow}{WW}";
if (version == 6) chanMeasurement[k_exWW8] = "#splitline{#gamma#gamma#rightarrow WW}{WW #rightarrow l#nul#nu}";
  chanLumi[k_exWW8]= "19.7 fb^{-1}";
//scale_ = 1.0/(W_br_lnu*W_br_lnu*2.0) ;
scale_ = 2.0;

  chanSigma[k_exWW8]  =  0.0123 * scale_; 
  chanEStat[k_exWW8]  =   0.00495 * scale_;
  chanESyst[k_exWW8]  =   0.0 * scale_;
  chanETot[k_exWW8]   =  sqrt( 
			   chanEStat[k_exWW8]*chanEStat[k_exWW8]
			   +
			   chanESyst[k_exWW8]*chanESyst[k_exWW8]
			    );
  chanTheo[k_exWW8] =  0.0069 * scale_;
  chanETheo[k_exWW8] =  0.0006 * scale_;

// 12.3 -4.4 - +5.5

 scale_ = 1.;

// SS WW http://arxiv.org/abs/1410.6315

  chanMeasurement[k_SSWW8] = "#splitline{ EW}{ssWW}";
if (version == 6) chanMeasurement[k_SSWW8] = "#splitline{EWK ss WW}{WW #rightarrow l#nu l#nu}";
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




// Higgs results

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


  chanSigma[k_ttH]  =   -5.359 * chanTheo[k_ttH] * scale_; 
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
