enum {  k_atlas_wg_dkg=0, k_cms_wg_dkg,   k_cms_ww_dkg, k_atlas_wv_dkg, k_cms_wv_dkg, k_d0_vv_dkg, k_lep_ww_dkg, k_atlas_wg_lg, k_cms_wg_lg, k_cms_ww_lg, k_atlas_wv_lg, k_cms_wv_lg, k_d0_vv_lg, k_lep_ww_lg, k_atlas_ww_dkz, k_atlas_wv_dkz, k_cms_wv_dkz,  k_lep_ww_dkz, k_atlas_ww_dk, k_d0_vv_dk, k_atlas_ww_lz, k_cms_ww_lz, k_atlas_wz_lz, k_atlas_wv_lz, k_cms_wv_lz, k_d0_vv_lz,  k_lep_ww_lz, k_atlas_ww_dgz, k_cms_ww_dgz, k_atlas_wz_dgz, k_atlas_wv_dgz, k_d0_vv_dgz, k_lep_ww_dgz, k_atlas_zg_h3g,  k_cms_zg_h3g, k_cms_zg8_h3g, k_cdf_zg_h3g, k_atlas_zg_h3z, k_cms_zg_h3z, k_cms_zg8_h3z, k_cdf_zg_h3z, k_atlas_zg_h4g,  k_cms_zg_h4g, k_cms_zg8_h4g, k_atlas_zg_h4z,   k_cms_zg_h4z, k_cms_zg8_h4z, k_atlas_zz_f4g, k_cms_zz_f4g, k_cms_zz2_f4g, k_cms_zzc_f4g, k_atlas_zz_f4z, k_cms_zz_f4z,  k_cms_zz2_f4z, k_cms_zzc_f4z, k_atlas_zz_f5g, k_cms_zz_f5g,  k_cms_zz2_f5g, k_cms_zzc_f5g, k_atlas_zz_f5z, k_cms_zz_f5z, k_cms_zz2_f5z, k_cms_zzc_f5z,  k_nChan };



  int nPlotChan = 0;
  vector<bool> plotChan( k_nChan, false );
  vector<string> 
    chanName(        k_nChan ),
    chanMeasurement( k_nChan ),
    chanResult (     k_nChan ),
    chanLumi   (     k_nChan ),
    chanExp    (     k_nChan );
  vector<float> 
    chanaTGCC( k_nChan,0 ), 
    chanaTGCP( k_nChan,0 ),
    chanaTGCM( k_nChan,0 );


  float scale_;
 bool catgcg = false;
 bool catgcz = false;
 bool natgcg = false;
bool natgcz = true;

  
  scale_ = (1);

if (catgcg) {

  // http://arxiv.org/abs/1302.1283 summitted to PRD

  chanName[k_atlas_wg_dkg]            = "#Delta#kappa_{#gamma}";
  chanMeasurement[k_atlas_wg_dkg]     = "W#gamma";
  chanLumi[k_atlas_wg_dkg]            = "4.6 fb^{-1}";
  chanExp[k_atlas_wg_dkg]            = "ATLAS";
  chanaTGCC[k_atlas_wg_dkg]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_wg_dkg]  = -0.41 * scale_; 
  chanaTGCP[k_atlas_wg_dkg]  = +0.46 * scale_; 
  plotChan[k_atlas_wg_dkg] = true;


// ATLAS http://arxiv.org/abs/1205.2531 Phys.Lett. B717 (2012) 49-69
// superseeded
//   chanName[k_atlas_wg_dkg]            = "#Delta#kappa_{#gamma}";
//   chanMeasurement[k_atlas_wg_dkg]     = "W#gamma";
//   chanLumi[k_atlas_wg_dkg]            = "1.0 fb^{-1}";
//   chanExp[k_atlas_wg_dkg]            = "ATLAS";
//   chanaTGCC[k_atlas_wg_dkg]  = 0.0   * scale_; 
//   chanaTGCM[k_atlas_wg_dkg]  = -0.33 * scale_; 
//   chanaTGCP[k_atlas_wg_dkg]  = +0.37 * scale_; 
//   plotChan[k_atlas_wg_dkg] = true;


// CMS Prel EWK-11-009 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsEWK11009

  chanName[k_cms_wg_dkg]            = "#Delta#kappa_{#gamma}";
  chanMeasurement[k_cms_wg_dkg]     = "W#gamma";
  chanLumi[k_cms_wg_dkg]            = "5.0 fb^{-1}";
  chanExp[k_cms_wg_dkg]            = "CMS";
  chanaTGCC[k_cms_wg_dkg]  = 0.0   * scale_; 
  chanaTGCM[k_cms_wg_dkg]  = -0.38 * scale_; 
  chanaTGCP[k_cms_wg_dkg]  = +0.29 * scale_; 
  plotChan[k_cms_wg_dkg] = true; 


  // CMS https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP12005

  chanName[k_cms_ww_dkg]            = "#Delta#kappa_{#gamma}";
  chanMeasurement[k_cms_ww_dkg]     = "WW";
  chanLumi[k_cms_ww_dkg]            = "4.9 fb^{-1}";
  chanExp[k_cms_ww_dkg]            = "CMS";
  chanaTGCC[k_cms_ww_dkg]  = 0.0   * scale_; 
  chanaTGCM[k_cms_ww_dkg]  = -0.21 * scale_; 
  chanaTGCP[k_cms_ww_dkg]  = +0.22 * scale_; 
  plotChan[k_cms_ww_dkg] = true; 

// Atlas http://arxiv.org/abs/1410.7238 submited to JHEP

  chanName[k_atlas_wv_dkg]            = "#Delta#kappa_{#gamma}";
  chanMeasurement[k_atlas_wv_dkg]     = "WV";
  chanLumi[k_atlas_wv_dkg]            = "4.6 fb^{-1}";
  chanExp[k_atlas_wv_dkg]            = "ATLAS";
  chanaTGCC[k_atlas_wv_dkg]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_wv_dkg]  = -0.21 * scale_; 
  chanaTGCP[k_atlas_wv_dkg]  = +0.22 * scale_; 
  plotChan[k_atlas_wv_dkg] = true;


// CMS http://arxiv.org/abs/1210.7544 Sub to Eur. Phys. J. C

  chanName[k_cms_wv_dkg]            = "#Delta#kappa_{#gamma}";
  chanMeasurement[k_cms_wv_dkg]     = "WV";
  chanLumi[k_cms_wv_dkg]            = "5.0 fb^{-1}";
  chanExp[k_cms_wv_dkg]            = "CMS";
  chanaTGCC[k_cms_wv_dkg]  = 0.0   * scale_; 
  chanaTGCM[k_cms_wv_dkg]  = -0.11 * scale_; 
  chanaTGCP[k_cms_wv_dkg]  = +0.14 * scale_; 
  plotChan[k_cms_wv_dkg] = true;

// D0 http://arxiv.org/abs/1208.5458 Phys.Lett. B718 (2012) 451-459

  chanName[k_d0_vv_dkg]            = "#Delta#kappa_{#gamma}";
  chanMeasurement[k_d0_vv_dkg]     = "D0 Combination";
  chanLumi[k_d0_vv_dkg]            = "8.6 fb^{-1}";
  chanExp[k_d0_vv_dkg]            = "D0";
  chanaTGCC[k_d0_vv_dkg]  = 0.048   * scale_; 
  chanaTGCM[k_d0_vv_dkg]  = -0.158 * scale_; 
  chanaTGCP[k_d0_vv_dkg]  = +0.255 * scale_; 
  plotChan[k_d0_vv_dkg] = true;


  // Shown in WW, WZ plot
//   chanName[k_d0_vv_dk]            = "#Delta#kappa_{#gamma}";
//   chanMeasurement[k_d0_vv_dk]     = "D0 Comb (EC #Delta#kappa)";
//   chanLumi[k_d0_vv_dk]            = "8.6 fb^{-1}";
//   chanExp[k_d0_vv_dk]            = "D0";
//   chanaTGCC[k_d0_vv_dk]  = 0.037   * scale_; 
//   chanaTGCM[k_d0_vv_dk]  = -0.049 * scale_; 
//   chanaTGCP[k_d0_vv_dk]  = +0.124 * scale_; 
//   plotChan[k_d0_vv_dk] = true;

// D0 http://arxiv.org/abs/0907.4952 Submitted to Phys. Lett. B 
// Includes D0 http://arxiv.org/abs/0907.4398 Phys. Rev. D80 053012, 2009
// Exceeded

//   chanName[k_d0_wgwv_dkg]            = "#Delta#kappa_{#gamma}";
//   chanMeasurement[k_d0_wgwv_dkg]     = "W#gamma,WV";
//   chanLumi[k_d0_wgwv_dkg]            = "1.0 fb^{-1}";
//   chanExp[k_d0_wgwv_dkg]            = "D0";
//   chanaTGCC[k_d0_wgwv_dkg]  = 0.07   * scale_; 
//   chanaTGCM[k_d0_wgwv_dkg]  = -0.29 * scale_; 
//   chanaTGCP[k_d0_wgwv_dkg]  = +0.38 * scale_; 

//   chanName[k_d0_wgwv_dk]            = "#Delta#kappa_{#gamma}";
//   chanMeasurement[k_d0_wgwv_dk]     = "W#gamma,WV (EC #Delta#kappa)";
//   chanLumi[k_d0_wgwv_dk]            = "1.0 fb^{-1}";
//   chanExp[k_d0_wgwv_dk]            = "D0";
//   chanaTGCC[k_d0_wgwv_dk]  = 0.0   * scale_; 
//   chanaTGCM[k_d0_wgwv_dk]  = -0.11 * scale_; 
//   chanaTGCP[k_d0_wgwv_dk]  = +0.18 * scale_; 

// D0 http://arxiv.org/abs/1109.4432 Phys. Rev. Lett. 107, 241803 (2011)
// Exceeded

//  chanName[k_d0_wg_dkg]            = "#Delta#kappa_{#gamma}";
//   chanMeasurement[k_d0_wg_dkg]     = "W#gamma";
//   chanLumi[k_d0_wg_dkg]            = "4.2 fb^{-1}";
//   chanExp[k_d0_wg_dkg]            = "D0";
//   chanaTGCC[k_d0_wg_dkg]  = 0.0   * scale_; 
//   chanaTGCM[k_d0_wg_dkg]  = -0.4 * scale_; 
//   chanaTGCP[k_d0_wg_dkg]  = +0.4 * scale_; 


// LEP hep-ex/0212036 and hep-ex/0307056  hep-ex/0612034, http://arxiv.org/abs/1302.3415



  chanName[k_lep_ww_dkg]            = "#Delta#kappa_{#gamma}";
  chanMeasurement[k_lep_ww_dkg]     = "LEP Combination";
  chanLumi[k_lep_ww_dkg]            = "0.7 fb^{-1}";
  chanExp[k_lep_ww_dkg]            = "LEP";
  chanaTGCC[k_lep_ww_dkg]  = -0.018   * scale_; 
  chanaTGCM[k_lep_ww_dkg]  = -0.099 * scale_; 
  chanaTGCP[k_lep_ww_dkg]  = +0.066 * scale_; 
  plotChan[k_lep_ww_dkg] = true;

// ATLAS http://arxiv.org/abs/1302.1283 submitted to PRD

 chanName[k_atlas_wg_lg]            = "#lambda_{#gamma}";
  chanMeasurement[k_atlas_wg_lg]     = "W#gamma";
  chanLumi[k_atlas_wg_lg]            = "4.6 fb^{-1}";
  chanExp[k_atlas_wg_lg]            = "ATLAS";
  chanaTGCC[k_atlas_wg_lg]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_wg_lg]  = -0.065 * scale_; 
  chanaTGCP[k_atlas_wg_lg]  = +0.061 * scale_; 
  plotChan[k_atlas_wg_lg] = true;


// ATLAS http://arxiv.org/abs/1205.2531 Phys.Lett. B717 (2012) 49-69
// superceeded

//  chanName[k_atlas_wg_lg]            = "#lambda_{#gamma}";
//   chanMeasurement[k_atlas_wg_lg]     = "W#gamma";
//   chanLumi[k_atlas_wg_lg]            = "1.0 fb^{-1}";
//   chanExp[k_atlas_wg_lg]            = "ATLAS";
//   chanaTGCC[k_atlas_wg_lg]  = 0.0   * scale_; 
//   chanaTGCM[k_atlas_wg_lg]  = -0.060 * scale_; 
//   chanaTGCP[k_atlas_wg_lg]  = +0.060 * scale_; 
//   plotChan[k_atlas_wg_lg] = true;

// CMS Prel EWK-11-009 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsEWK11009

 chanName[k_cms_wg_lg]            = "#lambda_{#gamma}";
  chanMeasurement[k_cms_wg_lg]     = "W#gamma";
  chanLumi[k_cms_wg_lg]            = "5.0 fb^{-1}";
  chanExp[k_cms_wg_lg]            = "CMS";
  chanaTGCC[k_cms_wg_lg]  = 0.0   * scale_; 
  chanaTGCM[k_cms_wg_lg]  = -0.050 * scale_; 
  chanaTGCP[k_cms_wg_lg]  = +0.037 * scale_; 
  plotChan[k_cms_wg_lg] = true;

  // CMS https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP12005

 chanName[k_cms_ww_lg]            = "#lambda_{#gamma}";
  chanMeasurement[k_cms_ww_lg]     = "WW";
  chanLumi[k_cms_ww_lg]            = "4.9 fb^{-1}";
  chanExp[k_cms_ww_lg]            = "CMS";
  chanaTGCC[k_cms_ww_lg]  = 0.0   * scale_; 
  chanaTGCM[k_cms_ww_lg]  = -0.048 * scale_; 
  chanaTGCP[k_cms_ww_lg]  = +0.048 * scale_; 
  plotChan[k_cms_ww_lg] = true;


 // Atlas http://arxiv.org/abs/1410.7238 submitted to JHEP


  chanName[k_atlas_wv_lg]            = "#lambda_{#gamma}";
  chanMeasurement[k_atlas_wv_lg]     = "WV";
  chanLumi[k_atlas_wv_lg]            = "4.6 fb^{-1}";
  chanExp[k_atlas_wv_lg]            = "ATLAS";
  chanaTGCC[k_atlas_wv_lg]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_wv_lg]  = -0.039 * scale_; 
  chanaTGCP[k_atlas_wv_lg]  = +0.040 * scale_; 
  plotChan[k_atlas_wv_lg] = true;

// CMS http://arxiv.org/abs/1210.7544 Sub to Eur. Phys. J. C


  chanName[k_cms_wv_lg]            = "#lambda_{#gamma}";
  chanMeasurement[k_cms_wv_lg]     = "WV";
  chanLumi[k_cms_wv_lg]            = "5.0 fb^{-1}";
  chanExp[k_cms_wv_lg]            = "CMS";
  chanaTGCC[k_cms_wv_lg]  = 0.0   * scale_; 
  chanaTGCM[k_cms_wv_lg]  = -0.038 * scale_; 
  chanaTGCP[k_cms_wv_lg]  = +0.030 * scale_; 
  plotChan[k_cms_wv_lg] = true;

// D0 http://arxiv.org/abs/1208.5458 Phys.Lett. B718 (2012) 451-459

  chanName[k_d0_vv_lg]            = "#lambda_{#gamma}";
  chanMeasurement[k_d0_vv_lg]     = "D0 Combination";
  chanLumi[k_d0_vv_lg]            = "8.6 fb^{-1}";
  chanExp[k_d0_vv_lg]            = "D0";
  chanaTGCC[k_d0_vv_lg]  = 0.007   * scale_; 
  chanaTGCM[k_d0_vv_lg]  = -0.036 * scale_; 
  chanaTGCP[k_d0_vv_lg]  = +0.044 * scale_; 
  plotChan[k_d0_vv_lg] = true;


// Note equal coupling result 0.008 -0.039 +0.042


// D0 http://arxiv.org/abs/1109.4432 Phys. Rev. Lett. 107, 241803 (2011)
// Exceeded

//   chanName[k_d0_wg_lg]            = "#lambda_{#gamma}";
//   chanMeasurement[k_d0_wg_lg]     = "W#gamma";
//   chanLumi[k_d0_wg_lg]            = "4.2 fb^{-1}";
//   chanExp[k_d0_wg_lg]            = "D0";
//   chanaTGCC[k_d0_wg_lg]  = 0.0   * scale_; 
//   chanaTGCM[k_d0_wg_lg]  = -0.08 * scale_; 
//   chanaTGCP[k_d0_wg_lg]  = +0.07 * scale_; 





// D0 http://arxiv.org/abs/0907.4952 Submitted to Phys. Lett. B 
// Includes // Includes D0 http://arxiv.org/abs/0907.4398 Phys. Rev. D80 053012, 2009
// Exceeded

//   chanName[k_d0_wgwv_l]            = "#lambda_{#gamma}";
//   chanMeasurement[k_d0_wgwv_l]     = "W#gamma,WV (EC #lambda)";
//   chanLumi[k_d0_wgwv_l]            = "1.0 fb^{-1}";
//   chanExp[k_d0_wgwv_l]            = "D0";
//   chanaTGCC[k_d0_wgwv_l]  = 0.0   * scale_; 
//   chanaTGCM[k_d0_wgwv_l]  = -0.08 * scale_; 
//   chanaTGCP[k_d0_wgwv_l]  = +0.08 * scale_; 

// LEP hep-ex/0212036 and hep-ex/0307056 and hep-ex/062034, http://arxiv.org/abs/1302.3415


  chanName[k_lep_ww_lg]            = "#lambda_{#gamma}";
  chanMeasurement[k_lep_ww_lg]     = "LEP Combination";
  chanLumi[k_lep_ww_lg]            = "0.7 fb^{-1}";
  chanExp[k_lep_ww_lg]            = "LEP";
  chanaTGCC[k_lep_ww_lg]  = -0.022   * scale_; 
  chanaTGCM[k_lep_ww_lg]  = -0.059 * scale_; 
  chanaTGCP[k_lep_ww_lg]  = +0.017 * scale_; 
  plotChan[k_lep_ww_lg] = true;
 
 }

if (catgcz)
  {

// ATLAS http://arxiv.org/abs/1210.2979 submitted to Phys. Rev. D

  chanName[k_atlas_ww_dkz]            = "#Delta#kappa_{Z}";
  chanMeasurement[k_atlas_ww_dkz]     = "WW";
  chanLumi[k_atlas_ww_dkz]            = "4.6 fb^{-1}";
  chanExp[k_atlas_ww_dkz]            = "ATLAS";
  chanaTGCC[k_atlas_ww_dkz]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_ww_dkz]  = -0.043 * scale_; 
  chanaTGCP[k_atlas_ww_dkz]  = +0.043 * scale_; 
  plotChan[k_atlas_ww_dkz] = true;



  // ATALS http://arxiv.org/abs/1208.1390 Eur.Phys.J. C72 (2012) 2173
  // Not competative

//   chanName[k_atlas_wz_dkz]            = "#Delta#kappa_{Z}";
//   chanMeasurement[k_atlas_wz_dkz]     = "WZ";
//   chanLumi[k_atlas_wz_dkz]            = "4.6 fb^{-1}";
//   chanExp[k_atlas_wz_dkz]            = "ATLAS";
//   chanaTGCC[k_atlas_wz_dkz]  = 0.0   * scale_; 
//   chanaTGCM[k_atlas_wz_dkz]  = -0.37 * scale_; 
//   chanaTGCP[k_atlas_wz_dkz]  = +0.57 * scale_; 
//   plotChan[k_atlas_wz_dkz] = true;


// Atlas http://arxiv.org/abs/1410.7238 submitted to JHEP

  chanName[k_atlas_wv_dkz]            = "#Delta#kappa_{Z}";
  chanMeasurement[k_atlas_wv_dkz]     = "WV";
  chanLumi[k_atlas_wv_dkz]            = "4.6 fb^{-1}";
  chanExp[k_atlas_wv_dkz]            = "ATLAS";
  chanaTGCC[k_atlas_wv_dkz]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_wv_dkz]  = -0.090 * scale_; 
  chanaTGCP[k_atlas_wv_dkz]  = +0.105 * scale_; 
  plotChan[k_atlas_wv_dkz] = true;


// CMS http://arxiv.org/abs/1210.7544 Sub to Eur. Phys. J. C

  chanName[k_cms_wv_dkz]            = "#Delta#kappa_{Z}";
  chanMeasurement[k_cms_wv_dkz]     = "WV";
  chanLumi[k_cms_wv_dkz]            = "5.0 fb^{-1}";
  chanExp[k_cms_wv_dkz]            = "CMS";
  chanaTGCC[k_cms_wv_dkz]  = 0.0   * scale_; 
  chanaTGCM[k_cms_wv_dkz]  = -0.043 * scale_; 
  chanaTGCP[k_cms_wv_dkz]  = +0.033 * scale_; 
  plotChan[k_cms_wv_dkz] = true;

// LEP  hep-ex/0212036 and hep-ex/0307056, http://arxiv.org/abs/1302.3415

  chanName[k_lep_ww_dkz]            = "#Delta#kappa_{Z}";
  chanMeasurement[k_lep_ww_dkz]     = "LEP Combination";
  chanLumi[k_lep_ww_dkz]            = "0.7 fb^{-1}";
  chanExp[k_lep_ww_dkz]            = "LEP";
  chanaTGCC[k_lep_ww_dkz]  = -0.011   * scale_; 
  chanaTGCM[k_lep_ww_dkz]  = -0.074 * scale_; 
  chanaTGCP[k_lep_ww_dkz]  = +0.051 * scale_; 
  plotChan[k_lep_ww_dkz] = true;



// ATLAS http://arxiv.org/abs/1210.2979 submitted to Phys. Rev. D

//   chanName[k_atlas_ww_dk]            = "#Delta#kappa_{Z}";
//   chanMeasurement[k_atlas_ww_dk]     = "WW (EC #Delta#kappa)";
//   chanLumi[k_atlas_ww_dk]            = "4.6 fb^{-1}";
//   chanExp[k_atlas_ww_dk]            = "ATLAS";
//   chanaTGCC[k_atlas_ww_dk]  = 0.0   * scale_; 
//   chanaTGCM[k_atlas_ww_dk]  = -0.061 * scale_; 
//   chanaTGCP[k_atlas_ww_dk]  = +0.083 * scale_; 
//   plotChan[k_atlas_ww_dk] = true;





  // ATALS CDF WZ not competative, CDF WW not competative


// D0 http://arxiv.org/abs/1208.5458 Phys.Lett. B718 (2012) 451-459

//   chanName[k_d0_vv_dk]            = "#Delta#kappa_{Z}";
//   chanMeasurement[k_d0_vv_dk]     = "D0 Comb (EC #Delta#kappa)";
//   chanLumi[k_d0_vv_dk]            = "8.6 fb^{-1}";
//   chanExp[k_d0_vv_dk]            = "D0";
//   chanaTGCC[k_d0_vv_dk]  = 0.037   * scale_; 
//   chanaTGCM[k_d0_vv_dk]  = -0.049 * scale_; 
//   chanaTGCP[k_d0_vv_dk]  = +0.124 * scale_; 
//   plotChan[k_d0_vv_dk] = true;





// ATLAS http://arxiv.org/abs/1210.2979 submitted to Phys. Rev. D

 chanName[k_atlas_ww_lz]            = "#lambda_{Z}";
  chanMeasurement[k_atlas_ww_lz]     = "WW";
  chanLumi[k_atlas_ww_lz]            = "4.6 fb^{-1}";
  chanExp[k_atlas_ww_lz]            = "ATLAS";
  chanaTGCC[k_atlas_ww_lz]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_ww_lz]  = -0.062 * scale_; 
  chanaTGCP[k_atlas_ww_lz]  = +0.059 * scale_; 
  plotChan[k_atlas_ww_lz] = true;


  // CMS https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP12005

 chanName[k_cms_ww_lz]            = "#lambda_{Z}";
  chanMeasurement[k_cms_ww_lz]     = "WW";
  chanLumi[k_cms_ww_lz]            = "4.9 fb^{-1}";
  chanExp[k_cms_ww_lz]            = "CMS";
  chanaTGCC[k_cms_ww_lz]  = 0.0   * scale_; 
  chanaTGCM[k_cms_ww_lz]  = -0.048 * scale_; 
  chanaTGCP[k_cms_ww_lz]  = +0.048 * scale_; 
  plotChan[k_cms_ww_lz] = true;



  // ATALS http://arxiv.org/abs/1208.1390 Eur.Phys.J. C72 (2012) 2173

 chanName[k_atlas_wz_lz]            = "#lambda_{Z}";
  chanMeasurement[k_atlas_wz_lz]     = "WZ";
  chanLumi[k_atlas_wz_lz]            = "4.6 fb^{-1}";
  chanExp[k_atlas_wz_lz]            = "ATLAS";
  chanaTGCC[k_atlas_wz_lz]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_wz_lz]  = -0.046 * scale_; 
  chanaTGCP[k_atlas_wz_lz]  = +0.047 * scale_; 
  plotChan[k_atlas_wz_lz] = true;

  // CDF  http://arxiv.org/abs/0912.4500 Phys.Rev.Lett. 104 (2010) 201801
 // CDF WZ better than WW

//  chanName[k_cdf_ww_lz]            = "#lambda_{Z}";
//   chanMeasurement[k_cdf_ww_lz]     = "WW";
//   chanLumi[k_cdf_ww_lz]            = "3.6 fb^{-1}";
//   chanExp[k_cdf_ww_lz]            = "CDF";
//   chanaTGCC[k_cdf_ww_lz]  = 0.0   * scale_; 
//   chanaTGCM[k_cdf_ww_lz]  = -0.14 * scale_; 
//   chanaTGCP[k_cdf_ww_lz]  = +0.15 * scale_; 
//   plotChan[k_cdf_ww_lz] = true;


  // CDF http://arxiv.org/abs/1202.6629 Phys.Rev. D86 (2012) 031104
  // almost competative

//  chanName[k_cdf_wz_lz]            = "#lambda_{Z}";
//   chanMeasurement[k_cdf_wz_lz]     = "WZ";
//   chanLumi[k_cdf_wz_lz]            = "7.1 fb^{-1}";
//   chanExp[k_cdf_wz_lz]            = "CDF";
//   chanaTGCC[k_cdf_wz_lz]  = 0.0   * scale_; 
//   chanaTGCM[k_cdf_wz_lz]  = -0.09 * scale_; 
//   chanaTGCP[k_cdf_wz_lz]  = +0.11 * scale_; 
//   plotChan[k_cdf_wz_lz] = true;


// Atlas http://arxiv.org/abs/1410.7238 submitted to JHEP


  chanName[k_atlas_wv_lz]            = "#lambda_{Z}";
  chanMeasurement[k_atlas_wv_lz]     = "WV";
  chanLumi[k_atlas_wv_lz]            = "4.6 fb^{-1}";
  chanExp[k_atlas_wv_lz]            = "ATLAS";
  chanaTGCC[k_atlas_wv_lz]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_wv_lz]  = -0.039 * scale_; 
  chanaTGCP[k_atlas_wv_lz]  = +0.040 * scale_; 
  plotChan[k_atlas_wv_lz] = true;



// CMS http://arxiv.org/abs/1210.7544 Sub to Eur. Phys. J. C


  chanName[k_cms_wv_lz]            = "#lambda_{Z}";
  chanMeasurement[k_cms_wv_lz]     = "WV";
  chanLumi[k_cms_wv_lz]            = "5.0 fb^{-1}";
  chanExp[k_cms_wv_lz]            = "CMS";
  chanaTGCC[k_cms_wv_lz]  = 0.0   * scale_; 
  chanaTGCM[k_cms_wv_lz]  = -0.038 * scale_; 
  chanaTGCP[k_cms_wv_lz]  = +0.030 * scale_; 
  plotChan[k_cms_wv_lz] = true;




// D0 http://arxiv.org/abs/1208.5458 Phys.Lett. B718 (2012) 451-459

  chanName[k_d0_vv_lz]            = "#lambda_{Z}";
  chanMeasurement[k_d0_vv_lz]     = "D0 Combination";
  chanLumi[k_d0_vv_lz]            = "8.6 fb^{-1}";
  chanExp[k_d0_vv_lz]            = "D0";
  chanaTGCC[k_d0_vv_lz]  = 0.007   * scale_; 
  chanaTGCM[k_d0_vv_lz]  = -0.036 * scale_; 
  chanaTGCP[k_d0_vv_lz]  = +0.044 * scale_; 
  plotChan[k_d0_vv_lz] = true;


// LEP  hep-ex/0212036 and hep-ex/0307056,  http://arxiv.org/abs/1302.3415

  chanName[k_lep_ww_lz]            = "#lambda_{Z}";
  chanMeasurement[k_lep_ww_lz]     = "LEP Combination";
  chanLumi[k_lep_ww_lz]            = "0.7 fb^{-1}";
  chanExp[k_lep_ww_lz]            = "LEP";
  chanaTGCC[k_lep_ww_lz]  = -0.022   * scale_; 
  chanaTGCM[k_lep_ww_lz]  = -0.059 * scale_; 
  chanaTGCP[k_lep_ww_lz]  = +0.017 * scale_; 
  plotChan[k_lep_ww_lz] = true;




// ATLAS http://arxiv.org/abs/1210.2979 submitted to Phys. Rev. D

  chanName[k_atlas_ww_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_atlas_ww_dgz]     = "WW";
  chanLumi[k_atlas_ww_dgz]            = "4.6 fb^{-1}";
  chanExp[k_atlas_ww_dgz]            = "ATLAS";
  chanaTGCC[k_atlas_ww_dgz]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_ww_dgz]  = -0.039 * scale_; 
  chanaTGCP[k_atlas_ww_dgz]  = +0.052 * scale_; 
  plotChan[k_atlas_ww_dgz] = true;

  // https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP12005

  chanName[k_cms_ww_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_cms_ww_dgz]     = "WW";
  chanLumi[k_cms_ww_dgz]            = "4.9 fb^{-1}";
  chanExp[k_cms_ww_dgz]            = "CMS";
  chanaTGCC[k_cms_ww_dgz]  = 0.0   * scale_; 
  chanaTGCM[k_cms_ww_dgz]  = -0.095 * scale_; 
  chanaTGCP[k_cms_ww_dgz]  = +0.095 * scale_; 
  plotChan[k_cms_ww_dgz] = true;



  // ATALS http://arxiv.org/abs/1208.1390 Eur.Phys.J. C72 (2012) 2173

  chanName[k_atlas_wz_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_atlas_wz_dgz]     = "WZ";
  chanLumi[k_atlas_wz_dgz]            = "4.6 fb^{-1}";
  chanExp[k_atlas_wz_dgz]            = "ATLAS";
  chanaTGCC[k_atlas_wz_dgz]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_wz_dgz]  = -0.057 * scale_; 
  chanaTGCP[k_atlas_wz_dgz]  = +0.093 * scale_; 
  plotChan[k_atlas_wz_dgz] = true;

// Atlas http://arxiv.org/abs/1410.7238 submitted to JHEP


  chanName[k_atlas_wv_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_atlas_wv_dgz]     = "WV";
  chanLumi[k_atlas_wv_dgz]            = "4.6 fb^{-1}";
  chanExp[k_atlas_wv_dgz]            = "ATLAS";
  chanaTGCC[k_atlas_wv_dgz]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_wv_dgz]  = -0.055 * scale_; 
  chanaTGCP[k_atlas_wv_dgz]  = +0.071 * scale_; 
  plotChan[k_atlas_wv_dgz] = true;




  // CDF  http://arxiv.org/abs/0912.4500 Phys.Rev.Lett. 104 (2010) 201801
 // CDF WZ better than WW

//  chanName[k_cdf_ww_dgz]            = "#Deltag^{Z}_{1}";
//   chanMeasurement[k_cdf_ww_dgz]     = "WW";
//   chanLumi[k_cdf_ww_dgz]            = "3.6 fb^{-1}";
//   chanExp[k_cdf_ww_dgz]            = "CDF";
//   chanaTGCC[k_cdf_ww_dgz]  = 0.0   * scale_; 
//   chanaTGCM[k_cdf_ww_dgz]  = -0.22 * scale_; 
//   chanaTGCP[k_cdf_ww_dgz]  = +0.30 * scale_; 
//   plotChan[k_cdf_ww_dgz] = true;


  // CDF http://arxiv.org/abs/1202.6629 Phys.Rev. D86 (2012) 031104
  // almost competative

//   chanName[k_cdf_wz_dgz]            = "#Deltag^{Z}_{1}";
//   chanMeasurement[k_cdf_wz_dgz]     = "WZ";
//   chanLumi[k_cdf_wz_dgz]            = "7.1 fb^{-1}";
//   chanExp[k_cdf_wz_dgz]            = "CDF";
//   chanaTGCC[k_cdf_wz_dgz]  = 0.0   * scale_; 
//   chanaTGCM[k_cdf_wz_dgz]  = -0.08 * scale_; 
//   chanaTGCP[k_cdf_wz_dgz]  = +0.20 * scale_; 
//   plotChan[k_cdf_wz_dgz] = true;



// D0 http://arxiv.org/abs/1208.5458 Phys.Lett. B718 (2012) 451-459

  chanName[k_d0_vv_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_d0_vv_dgz]     = "D0 Combination";
  chanLumi[k_d0_vv_dgz]            = "8.6 fb^{-1}";
  chanExp[k_d0_vv_dgz]            = "D0";
  chanaTGCC[k_d0_vv_dgz]  = 0.022   * scale_; 
  chanaTGCM[k_d0_vv_dgz]  = -0.034 * scale_; 
  chanaTGCP[k_d0_vv_dgz]  = +0.084 * scale_; 
  plotChan[k_d0_vv_dgz] = true;

// LEP  hep-ex/0212036 and hep-ex/0307056 http://arxiv.org/abs/1302.3415

  chanName[k_lep_ww_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_lep_ww_dgz]     = "LEP Combination";
  chanLumi[k_lep_ww_dgz]            = "0.7 fb^{-1}";
  chanExp[k_lep_ww_dgz]            = "LEP";
  chanaTGCC[k_lep_ww_dgz]  = -0.016   * scale_; 
  chanaTGCM[k_lep_ww_dgz]  = -0.054 * scale_; 
  chanaTGCP[k_lep_ww_dgz]  = +0.021 * scale_; 
  plotChan[k_lep_ww_dgz] = true;
  }


if (natgcg)
  {

  // h3 parameters times 10-1  
  // http://arxiv.org/abs/1302.1283 submitted to PRD


  chanName[k_atlas_zg_h3g]            = "h^{#gamma}_{3}";
  chanMeasurement[k_atlas_zg_h3g]     = "Z#gamma";
  chanLumi[k_atlas_zg_h3g]            = "4.6 fb^{-1}";
  chanExp[k_atlas_zg_h3g]            = "ATLAS";
  chanaTGCC[k_atlas_zg_h3g]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_zg_h3g]  = -0.15 * scale_; 
  chanaTGCP[k_atlas_zg_h3g]  = +0.16 * scale_; 
  plotChan[k_atlas_zg_h3g] = true;


  // ATLAS http://arxiv.org/abs/1205.2531 Phys.Lett. B717 (2012) 49-69
  // subperceeded

//   chanName[k_atlas_zg_h3g]            = "h^{#gamma}_{3}";
//   chanMeasurement[k_atlas_zg_h3g]     = "Z#gamma";
//   chanLumi[k_atlas_zg_h3g]            = "1.0 fb^{-1}";
//   chanExp[k_atlas_zg_h3g]            = "ATLAS";
//   chanaTGCC[k_atlas_zg_h3g]  = 0.0   * scale_; 
//   chanaTGCM[k_atlas_zg_h3g]  = -0.28 * scale_; 
//   chanaTGCP[k_atlas_zg_h3g]  = +0.27 * scale_; 
//   plotChan[k_atlas_zg_h3g] = true;

// CMS Prel EWK-11-009 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsEWK11009
// CMS Prel SMP-12-020 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP12020
// http://arxiv.org/abs/1309.1117 HEP 10 (2013) 164

  chanName[k_cms_zg_h3g]            = "h^{#gamma}_{3}";
  chanMeasurement[k_cms_zg_h3g]     = "Z#gamma";
  chanLumi[k_cms_zg_h3g]            = "5.0 fb^{-1}";
  chanExp[k_cms_zg_h3g]            = "CMS";
  chanaTGCC[k_cms_zg_h3g]  = 0.0   * scale_; 
  //  chanaTGCM[k_cms_zg_h3g]  = -0.10 * scale_; 
  //  chanaTGCP[k_cms_zg_h3g]  = +0.10 * scale_; 
  chanaTGCM[k_cms_zg_h3g]  = -0.029 * scale_; 
  chanaTGCP[k_cms_zg_h3g]  = +0.029 * scale_; 
  plotChan[k_cms_zg_h3g] = true;

// CMS Prel SMP-13-014 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP13014
// http://arxiv.org/abs/1502.05664

  chanName[k_cms_zg8_h3g]            = "h^{#gamma}_{3}";
  chanMeasurement[k_cms_zg8_h3g]     = "Z#gamma";
  chanLumi[k_cms_zg8_h3g]            = "19.5 fb^{-1}";
  chanExp[k_cms_zg8_h3g]            = "CMS";
  chanaTGCC[k_cms_zg8_h3g]  = 0.0   * scale_; 
  //  chanaTGCM[k_cms_zg_h3g]  = -0.10 * scale_; 
  //  chanaTGCP[k_cms_zg_h3g]  = +0.10 * scale_; 
  chanaTGCM[k_cms_zg8_h3g]  = -0.046 * scale_; 
  chanaTGCP[k_cms_zg8_h3g]  = +0.046 * scale_; 
  plotChan[k_cms_zg8_h3g] = true;


  // CDF http://arxiv.org/abs/1103.2990 Phys.Rev.Lett.107:051802,2011

  chanName[k_cdf_zg_h3g]            = "h^{#gamma}_{3}";
  chanMeasurement[k_cdf_zg_h3g]     = "Z#gamma";
  chanLumi[k_cdf_zg_h3g]            = "5.1 fb^{-1}";
  chanExp[k_cdf_zg_h3g]            = "CDF";
  chanaTGCC[k_cdf_zg_h3g]  = 0.0   * scale_; 
  chanaTGCM[k_cdf_zg_h3g]  = -0.22 * scale_; 
  chanaTGCP[k_cdf_zg_h3g]  = +0.20 * scale_; 
  plotChan[k_cdf_zg_h3g] = true;

  // D0 http://arxiv.org/abs/1111.3684 Phys. Rev. D 85, 052001 (2012)
  // Not competative


//   chanName[k_d0_zg_h3g]            = "h^{#gamma}_{3}";
//   chanMeasurement[k_d0_zg_h3g]     = "Z#gamma";
//   chanLumi[k_d0_zg_h3g]            = "7.2 fb^{-1}";
//   chanExp[k_d0_zg_h3g]            = "D0";
//   chanaTGCC[k_d0_zg_h3g]  = 0.0   * scale_; 
//   chanaTGCM[k_d0_zg_h3g]  = -0.29 * scale_; 
//   chanaTGCP[k_d0_zg_h3g]  = +0.29 * scale_; 
//   plotChan[k_d0_zg_h3g] = true;

  // LEP not competative -0.049  -0.008 


  // http://arxiv.org/abs/1302.1283 submitted to PRD
  chanName[k_atlas_zg_h3z]            = "h^{Z}_{3}";
  chanMeasurement[k_atlas_zg_h3z]     = "Z#gamma";
  chanLumi[k_atlas_zg_h3z]            = "4.6 fb^{-1}";
  chanExp[k_atlas_zg_h3z]            = "ATLAS";
  chanaTGCC[k_atlas_zg_h3z]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_zg_h3z]  = -0.13 * scale_; 
  chanaTGCP[k_atlas_zg_h3z]  = +0.14 * scale_; 
  plotChan[k_atlas_zg_h3z] = true;
 


  // ATLAS http://arxiv.org/abs/1205.2531 Phys.Lett. B717 (2012) 49-69
  // subperseeded   

//   chanName[k_atlas_zg_h3z]            = "h^{Z}_{3}";
//   chanMeasurement[k_atlas_zg_h3z]     = "Z#gamma";
//   chanLumi[k_atlas_zg_h3z]            = "1.0 fb^{-1}";
//   chanExp[k_atlas_zg_h3z]            = "ATLAS";
//   chanaTGCC[k_atlas_zg_h3z]  = 0.0   * scale_; 
//   chanaTGCM[k_atlas_zg_h3z]  = -0.22 * scale_; 
//   chanaTGCP[k_atlas_zg_h3z]  = +0.26 * scale_; 
//   plotChan[k_atlas_zg_h3z] = true;

// CMS Prel EWK-11-009 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsEWK11009
// CMS Prel SMP-12-020 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP12020
// http://arxiv.org/abs/1309.1117 HEP 10 (2013) 164


  chanName[k_cms_zg_h3z]            = "h^{Z}_{3}";
  chanMeasurement[k_cms_zg_h3z]     = "Z#gamma";
  chanLumi[k_cms_zg_h3z]            = "5.0 fb^{-1}";
  chanExp[k_cms_zg_h3z]            = "CMS";
  chanaTGCC[k_cms_zg_h3z]  = 0.0   * scale_; 
  //chanaTGCM[k_cms_zg_h3z]  = -0.086 * scale_; 
  //chanaTGCP[k_cms_zg_h3z]  = +0.084 * scale_; 
  chanaTGCM[k_cms_zg_h3z]  = -0.027 * scale_; 
  chanaTGCP[k_cms_zg_h3z]  = +0.027 * scale_; 
  plotChan[k_cms_zg_h3z] = true;


// CMS Prel SMP-13-014 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP13014
// http://arxiv.org/abs/1502.05664

  chanName[k_cms_zg8_h3z]            = "h^{Z}_{3}";
  chanMeasurement[k_cms_zg8_h3z]     = "Z#gamma";
  chanLumi[k_cms_zg8_h3z]            = "19.5 fb^{-1}";
  chanExp[k_cms_zg8_h3z]            = "CMS";
  chanaTGCC[k_cms_zg8_h3z]  = 0.0   * scale_; 
  //chanaTGCM[k_cms_zg_h3z]  = -0.086 * scale_; 
  //chanaTGCP[k_cms_zg_h3z]  = +0.084 * scale_; 
  chanaTGCM[k_cms_zg8_h3z]  = -0.038 * scale_; 
  chanaTGCP[k_cms_zg8_h3z]  = +0.037 * scale_; 
  plotChan[k_cms_zg8_h3z] = true;


  // CDF http://arxiv.org/abs/1103.2990 Phys.Rev.Lett.107:051802,2011

  chanName[k_cdf_zg_h3z]            = "h^{Z}_{3}";
  chanMeasurement[k_cdf_zg_h3z]     = "Z#gamma";
  chanLumi[k_cdf_zg_h3z]            = "5.1 fb^{-1}";
  chanExp[k_cdf_zg_h3z]            = "CDF";
  chanaTGCC[k_cdf_zg_h3z]  = 0.0   * scale_; 
  chanaTGCM[k_cdf_zg_h3z]  = -0.20 * scale_; 
  chanaTGCP[k_cdf_zg_h3z]  = +0.21 * scale_; 
  plotChan[k_cdf_zg_h3z] = true;

  // D0 http://arxiv.org/abs/1111.3684 Phys. Rev. D 85, 052001 (2012)
  // not competative

//   chanName[k_d0_zg_h3z]            = "h^{Z}_{3}";
//   chanMeasurement[k_d0_zg_h3z]     = "Z#gamma";
//   chanLumi[k_d0_zg_h3z]            = "7.2 fb^{-1}";
//   chanExp[k_d0_zg_h3z]            = "D0";
//   chanaTGCC[k_d0_zg_h3z]  = 0.0   * scale_; 
//   chanaTGCM[k_d0_zg_h3z]  = -0.26 * scale_; 
//   chanaTGCP[k_d0_zg_h3z]  = +0.26 * scale_; 
//   plotChan[k_d0_zg_h3z] = true;

  // LEP not competative -020 0.07



  // h4 parameters times 10-3

  // ATLAS http://arxiv.org/abs/1302.1283 submitted to PRD
  chanName[k_atlas_zg_h4g]            = "h^{#gamma}_{4}x100";
  chanMeasurement[k_atlas_zg_h4g]     = "Z#gamma";
  chanLumi[k_atlas_zg_h4g]            = "4.6 fb^{-1}";
  chanExp[k_atlas_zg_h4g]            = "ATLAS";
  chanaTGCC[k_atlas_zg_h4g]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_zg_h4g]  = -0.094 * scale_; 
  chanaTGCP[k_atlas_zg_h4g]  = +0.092 * scale_; 
  plotChan[k_atlas_zg_h4g] = true;



  // ATLAS http://arxiv.org/abs/1205.2531 Phys.Lett. B717 (2012) 49-69
  // superseeded

//   chanName[k_atlas_zg_h4g]            = "h^{#gamma}_{4}x100";
//   chanMeasurement[k_atlas_zg_h4g]     = "Z#gamma";
//   chanLumi[k_atlas_zg_h4g]            = "1.0 fb^{-1}";
//   chanExp[k_atlas_zg_h4g]            = "ATLAS";
//   chanaTGCC[k_atlas_zg_h4g]  = 0.0   * scale_; 
//   chanaTGCM[k_atlas_zg_h4g]  = -0.21 * scale_; 
//   chanaTGCP[k_atlas_zg_h4g]  = +0.21 * scale_; 
//   plotChan[k_atlas_zg_h4g] = true;


// CMS Prel EWK-11-009 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsEWK11009
// CMS Prel SMP-12-020 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP12020
// http://arxiv.org/abs/1309.1117 HEP 10 (2013) 164


  chanName[k_cms_zg_h4g]            = "h^{#gamma}_{4}x100";
  chanMeasurement[k_cms_zg_h4g]     = "Z#gamma";
  chanLumi[k_cms_zg_h4g]            = "5.0 fb^{-1}";
  chanExp[k_cms_zg_h4g]            = "CMS";
  chanaTGCC[k_cms_zg_h4g]  = 0.0   * scale_; 
  //chanaTGCM[k_cms_zg_h4g]  = -0.088 * scale_; 
  //chanaTGCP[k_cms_zg_h4g]  = +0.088 * scale_; 
  chanaTGCM[k_cms_zg_h4g]  = -0.015 * scale_; 
  chanaTGCP[k_cms_zg_h4g]  = +0.015 * scale_; 
  plotChan[k_cms_zg_h4g] = true;

// CMS Prel SMP-13-014 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP13014
// http://arxiv.org/abs/1502.05664

  chanName[k_cms_zg8_h4g]            = "h^{#gamma}_{4}x100";
  chanMeasurement[k_cms_zg8_h4g]     = "Z#gamma";
  chanLumi[k_cms_zg8_h4g]            = "19.5 fb^{-1}";
  chanExp[k_cms_zg8_h4g]            = "CMS";
  chanaTGCC[k_cms_zg8_h4g]  = 0.0   * scale_; 
  //chanaTGCM[k_cms_zg_h4g]  = -0.088 * scale_; 
  //chanaTGCP[k_cms_zg_h4g]  = +0.088 * scale_; 
  chanaTGCM[k_cms_zg8_h4g]  = -0.036 * scale_; 
  chanaTGCP[k_cms_zg8_h4g]  = +0.035 * scale_; 
  plotChan[k_cms_zg8_h4g] = true;


  // CDF http://arxiv.org/abs/1103.2990 Phys.Rev.Lett.107:051802,2011
  // not competative

//   chanName[k_cdf_zg_h4g]            = "h^{#gamma}_{4}x100";
//   chanMeasurement[k_cdf_zg_h4g]     = "Z#gamma";
//   chanLumi[k_cdf_zg_h4g]            = "5.1 fb^{-1}";
//   chanExp[k_cdf_zg_h4g]            = "CDF";
//   chanaTGCC[k_cdf_zg_h4g]  = 0.0   * scale_; 
//   chanaTGCM[k_cdf_zg_h4g]  = -0.8 * scale_; 
//   chanaTGCP[k_cdf_zg_h4g]  = +0.8 * scale_; 
//   plotChan[k_cdf_zg_h4g] = true;

  // D0 http://arxiv.org/abs/1111.3684 Phys. Rev. D 85, 052001 (2012)
  // realy not competative

  // LEP not competative -0.002  -0.034 



  // ATLAS http://arxiv.org/abs/1302.1283 submitted to PRD

  chanName[k_atlas_zg_h4z]            = "h^{Z}_{4}x100";
  chanMeasurement[k_atlas_zg_h4z]     = "Z#gamma";
  chanLumi[k_atlas_zg_h4z]            = "4.6 fb^{-1}";
  chanExp[k_atlas_zg_h4z]            = "ATLAS";
  chanaTGCC[k_atlas_zg_h4z]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_zg_h4z]  = -0.087 * scale_; 
  chanaTGCP[k_atlas_zg_h4z]  = +0.087 * scale_; 
  plotChan[k_atlas_zg_h4z] = true;
 

 // ATLAS http://arxiv.org/abs/1205.2531 Phys.Lett. B717 (2012) 49-69
  // superceeded

//   chanName[k_atlas_zg_h4z]            = "h^{Z}_{4}x100";
//   chanMeasurement[k_atlas_zg_h4z]     = "Z#gamma";
//   chanLumi[k_atlas_zg_h4z]            = "1.0 fb^{-1}";
//   chanExp[k_atlas_zg_h4z]            = "ATLAS";
//   chanaTGCC[k_atlas_zg_h4z]  = 0.0   * scale_; 
//   chanaTGCM[k_atlas_zg_h4z]  = -0.22 * scale_; 
//   chanaTGCP[k_atlas_zg_h4z]  = +0.21 * scale_; 
//   plotChan[k_atlas_zg_h4z] = true;

// CMS Prel EWK-11-009 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsEWK11009
// CMS Prel SMP-12-020 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP12020
// http://arxiv.org/abs/1309.1117 HEP 10 (2013) 164

  chanName[k_cms_zg_h4z]            = "h^{Z}_{4}x100";
  chanMeasurement[k_cms_zg_h4z]     = "Z#gamma";
  chanLumi[k_cms_zg_h4z]            = "5.0 fb^{-1}";
  chanExp[k_cms_zg_h4z]            = "CMS";
  chanaTGCC[k_cms_zg_h4z]  = 0.0   * scale_; 
  //  chanaTGCM[k_cms_zg_h4z]  = -0.080 * scale_; 
  //  chanaTGCP[k_cms_zg_h4z]  = +0.079 * scale_; 
  chanaTGCM[k_cms_zg_h4z]  = -0.013 * scale_; 
  chanaTGCP[k_cms_zg_h4z]  = +0.013 * scale_; 
  plotChan[k_cms_zg_h4z] = true;

// CMS Prel SMP-13-014 https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP13014
// http://arxiv.org/abs/1502.05664

  chanName[k_cms_zg8_h4z]            = "h^{Z}_{4}x100";
  chanMeasurement[k_cms_zg8_h4z]     = "Z#gamma";
  chanLumi[k_cms_zg8_h4z]            = "19.5 fb^{-1}";
  chanExp[k_cms_zg8_h4z]            = "CMS";
  chanaTGCC[k_cms_zg8_h4z]  = 0.0   * scale_; 
  //  chanaTGCM[k_cms_zg_h4z]  = -0.080 * scale_; 
  //  chanaTGCP[k_cms_zg_h4z]  = +0.079 * scale_; 
  chanaTGCM[k_cms_zg8_h4z]  = -0.031 * scale_; 
  chanaTGCP[k_cms_zg8_h4z]  = +0.030 * scale_; 
  plotChan[k_cms_zg8_h4z] = true;



  // CDF http://arxiv.org/abs/1103.2990 Phys.Rev.Lett.107:051802,2011
  // not competative

//   chanName[k_cdf_zg_h4z]            = "h^{Z}_{4}x100";
//   chanMeasurement[k_cdf_zg_h4z]     = "Z#gamma";
//   chanLumi[k_cdf_zg_h4z]            = "5.` fb^{-1}";
//   chanExp[k_cdf_zg_h4z]            = "CDF";
//   chanaTGCC[k_cdf_zg_h4z]  = 0.0   * scale_; 
//   chanaTGCM[k_cdf_zg_h4z]  = -0.9 * scale_; 
//   chanaTGCP[k_cdf_zg_h4z]  = +0.9 * scale_; 
//   plotChan[k_cdf_zg_h4z] = true;


  // D0 http://arxiv.org/abs/1111.3684 Phys. Rev. D 85, 052001 (2012)
  // realy not competative

  // LEP not competative -0.05  -0.12 


  }

if (natgcz)
  {

  // f3 parameters times 10-1  
  // ATLAS http://arxiv.org/abs/1211.6096 submitted to jhep
  //http://arxiv.org/abs/1211.6096 submitted to jhep


  chanName[k_atlas_zz_f4g]            = "f^{#gamma}_{4}";
  chanMeasurement[k_atlas_zz_f4g]     = "ZZ";
  chanLumi[k_atlas_zz_f4g]            = "4.6 fb^{-1}";
  chanExp[k_atlas_zz_f4g]            = "ATLAS";
  chanaTGCC[k_atlas_zz_f4g]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_zz_f4g]  = -0.15 * scale_; 
  chanaTGCP[k_atlas_zz_f4g]  = +0.15 * scale_; 
  plotChan[k_atlas_zz_f4g] = true;


// CMS http://arxiv.org/abs/1211.4890 submitted to JHEP

//   chanName[k_cms_zz_f4g]            = "f^{#gamma}_{4}";
//   chanMeasurement[k_cms_zz_f4g]     = "ZZ";
//   chanLumi[k_cms_zz_f4g]            = "5.0 fb^{-1}";
//   chanExp[k_cms_zz_f4g]            = "CMS";
//   chanaTGCC[k_cms_zz_f4g]  = 0.0   * scale_; 
//   chanaTGCM[k_cms_zz_f4g]  = -0.13 * scale_; 
//   chanaTGCP[k_cms_zz_f4g]  = +0.15 * scale_; 
//   plotChan[k_cms_zz_f4g] = true;


// CMS preliminary http://arxiv.org/abs/1406.0113 Phys. Lett. B 740 (2015) 250

  chanName[k_cms_zz_f4g]            = "f^{#gamma}_{4}";
  chanMeasurement[k_cms_zz_f4g]     = "ZZ";
  chanLumi[k_cms_zz_f4g]            = "19.6 fb^{-1}";
  chanExp[k_cms_zz_f4g]            = "CMS";
  chanaTGCC[k_cms_zz_f4g]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zz_f4g]  = -0.05 * scale_; 
  chanaTGCP[k_cms_zz_f4g]  = +0.05 * scale_; 
  plotChan[k_cms_zz_f4g] = true;


// CMS preliminary PAS SMP-013-016

  chanName[k_cms_zz2_f4g]            = "f^{#gamma}_{4}";
  chanMeasurement[k_cms_zz2_f4g]     = "ZZ (2l2#nu)";
  chanLumi[k_cms_zz2_f4g]            = "24.7 fb^{-1}";
  chanExp[k_cms_zz2_f4g]            = "CMS";
  chanaTGCC[k_cms_zz2_f4g]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zz2_f4g]  = -0.036 * scale_; 
  chanaTGCP[k_cms_zz2_f4g]  = +0.032 * scale_; 
  plotChan[k_cms_zz2_f4g] = true;

// CMS

  chanName[k_cms_zzc_f4g]            = "f^{#gamma}_{4}";
  chanMeasurement[k_cms_zzc_f4g]     = "ZZ (comb)";
  chanLumi[k_cms_zzc_f4g]            = "24.7 fb^{-1}";
  chanExp[k_cms_zzc_f4g]            = "CMS";
  chanaTGCC[k_cms_zzc_f4g]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zzc_f4g]  = -0.030 * scale_; 
  chanaTGCP[k_cms_zzc_f4g]  = +0.026 * scale_; 
  plotChan[k_cms_zzc_f4g] = true;



  // CDF,D0, LEP not competative

 
  //http://arxiv.org/abs/1211.6096 submitted to jhep
  

  chanName[k_atlas_zz_f4z]            = "f^{Z}_{4}";
  chanMeasurement[k_atlas_zz_f4z]     = "ZZ";
  chanLumi[k_atlas_zz_f4z]            = "4.6 fb^{-1}";
  chanExp[k_atlas_zz_f4z]            = "ATLAS";
  chanaTGCC[k_atlas_zz_f4z]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_zz_f4z]  = -0.13 * scale_; 
  chanaTGCP[k_atlas_zz_f4z]  = +0.13 * scale_; 
  plotChan[k_atlas_zz_f4z] = true;

// CMS http://arxiv.org/abs/1211.4890 submitted to JHEP

//   chanName[k_cms_zz_f4z]            = "f^{Z}_{4}";
//   chanMeasurement[k_cms_zz_f4z]     = "ZZ";
//   chanLumi[k_cms_zz_f4z]            = "5.0 fb^{-1}";
//   chanExp[k_cms_zz_f4z]            = "CMS";
//   chanaTGCC[k_cms_zz_f4z]  = 0.0   * scale_; 
//   chanaTGCM[k_cms_zz_f4z]  = -0.11 * scale_; 
//   chanaTGCP[k_cms_zz_f4z]  = +0.12 * scale_; 
//   plotChan[k_cms_zz_f4z] = true;

// http://arxiv.org/abs/1406.0113 Phys. Lett. B 740 (2015) 250

  chanName[k_cms_zz_f4z]            = "f^{Z}_{4}";
  chanMeasurement[k_cms_zz_f4z]     = "ZZ";
  chanLumi[k_cms_zz_f4z]            = "19.6 fb^{-1}";
  chanExp[k_cms_zz_f4z]            = "CMS";
  chanaTGCC[k_cms_zz_f4z]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zz_f4z]  = -0.04 * scale_; 
  chanaTGCP[k_cms_zz_f4z]  = +0.04 * scale_; 
  plotChan[k_cms_zz_f4z] = true;

// CMS preliminary PAS SMP-012-016

  chanName[k_cms_zz2_f4z]            = "f^{Z}_{4}";
  chanMeasurement[k_cms_zz2_f4z]     = "ZZ (2l2#nu)";
  chanLumi[k_cms_zz2_f4z]            = "24.7 fb^{-1}";
  chanExp[k_cms_zz2_f4z]            = "CMS";
  chanaTGCC[k_cms_zz2_f4z]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zz2_f4z]  = -0.027 * scale_; 
  chanaTGCP[k_cms_zz2_f4z]  = +0.032 * scale_; 
  plotChan[k_cms_zz2_f4z] = true;

// CMS preliminary PAS SMP-013-016

  chanName[k_cms_zzc_f4z]            = "f^{Z}_{4}";
  chanMeasurement[k_cms_zzc_f4z]     = "ZZ (comb)";
  chanLumi[k_cms_zzc_f4z]            = "24.7 fb^{-1}";
  chanExp[k_cms_zzc_f4z]            = "CMS";
  chanaTGCC[k_cms_zzc_f4z]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zzc_f4z]  = -0.021 * scale_; 
  chanaTGCP[k_cms_zzc_f4z]  = +0.026 * scale_; 
  plotChan[k_cms_zzc_f4z] = true;



  // CDF, D0 LEP not competative



  // f5 parameters times 10-1
  //http://arxiv.org/abs/1211.6096 submitted to jhep


  chanName[k_atlas_zz_f5g]            = "f^{#gamma}_{5}";
  chanMeasurement[k_atlas_zz_f5g]     = "ZZ";
  chanLumi[k_atlas_zz_f5g]            = "4.6 fb^{-1}";
  chanExp[k_atlas_zz_f5g]            = "ATLAS";
  chanaTGCC[k_atlas_zz_f5g]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_zz_f5g]  = -0.16 * scale_; 
  chanaTGCP[k_atlas_zz_f5g]  = +0.15 * scale_; 
  plotChan[k_atlas_zz_f5g] = true;


// CMS http://arxiv.org/abs/1211.4890 submitted to JHEP

//   chanName[k_cms_zz_f5g]            = "f^{#gamma}_{5}";
//   chanMeasurement[k_cms_zz_f5g]     = "ZZ";
//   chanLumi[k_cms_zz_f5g]            = "5.0 fb^{-1}";
//   chanExp[k_cms_zz_f5g]            = "CMS";
//   chanaTGCC[k_cms_zz_f5g]  = 0.0   * scale_; 
//   chanaTGCM[k_cms_zz_f5g]  = -0.14 * scale_; 
//   chanaTGCP[k_cms_zz_f5g]  = +0.14 * scale_; 
//   plotChan[k_cms_zz_f5g] = true;

//CMS  http://arxiv.org/abs/1406.0113 Phys. Lett. B 740 (2015) 250

  chanName[k_cms_zz_f5g]            = "f^{#gamma}_{5}";
  chanMeasurement[k_cms_zz_f5g]     = "ZZ";
  chanLumi[k_cms_zz_f5g]            = "19.6 fb^{-1}";
  chanExp[k_cms_zz_f5g]            = "CMS";
  chanaTGCC[k_cms_zz_f5g]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zz_f5g]  = -0.05 * scale_; 
  chanaTGCP[k_cms_zz_f5g]  = +0.05 * scale_; 
  plotChan[k_cms_zz_f5g] = true;

// CMS 

  chanName[k_cms_zz2_f5g]            = "f^{#gamma}_{5}";
  chanMeasurement[k_cms_zz2_f5g]     = "ZZ(2l2#nu)";
  chanLumi[k_cms_zz2_f5g]            = "24.7 fb^{-1}";
  chanExp[k_cms_zz2_f5g]            = "CMS";
  chanaTGCC[k_cms_zz2_f5g]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zz2_f5g]  = -0.033 * scale_; 
  chanaTGCP[k_cms_zz2_f5g]  = +0.036 * scale_; 
  plotChan[k_cms_zz2_f5g] = true;

// CMS

  chanName[k_cms_zzc_f5g]            = "f^{#gamma}_{5}";
  chanMeasurement[k_cms_zzc_f5g]     = "ZZ(comb)";
  chanLumi[k_cms_zzc_f5g]            = "24.7 fb^{-1}";
  chanExp[k_cms_zzc_f5g]            = "CMS";
  chanaTGCC[k_cms_zzc_f5g]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zzc_f5g]  = -0.026 * scale_; 
  chanaTGCP[k_cms_zzc_f5g]  = +0.027 * scale_; 
  plotChan[k_cms_zzc_f5g] = true;


  // CDF, D0, LEP not competative



  //http://arxiv.org/abs/1211.6096 submitted to jhep


  chanName[k_atlas_zz_f5z]            = "f^{Z}_{5}";
  chanMeasurement[k_atlas_zz_f5z]     = "ZZ";
  chanLumi[k_atlas_zz_f5z]            = "4.6 fb^{-1}";
  chanExp[k_atlas_zz_f5z]            = "ATLAS";
  chanaTGCC[k_atlas_zz_f5z]  = 0.0   * scale_; 
  chanaTGCM[k_atlas_zz_f5z]  = -0.13 * scale_; 
  chanaTGCP[k_atlas_zz_f5z]  = +0.13 * scale_; 
  plotChan[k_atlas_zz_f5z] = true;

// CMS http://arxiv.org/abs/1211.4890 submitted to JHEP

  
//   chanName[k_cms_zz_f5z]            = "f^{Z}_{5}";
//   chanMeasurement[k_cms_zz_f5z]     = "ZZ";
//   chanLumi[k_cms_zz_f5z]            = "5.0 fb^{-1}";
//   chanExp[k_cms_zz_f5z]            = "CMS";
//   chanaTGCC[k_cms_zz_f5z]  = 0.0   * scale_; 
//   chanaTGCM[k_cms_zz_f5z]  = -0.12 * scale_; 
//   chanaTGCP[k_cms_zz_f5z]  = +0.12 * scale_; 
//   plotChan[k_cms_zz_f5z] = true;

// CMS http://arxiv.org/abs/1406.0113 Phys. Lett. B 740 (2015) 250

  chanName[k_cms_zz_f5z]            = "f^{Z}_{5}";
  chanMeasurement[k_cms_zz_f5z]     = "ZZ";
  chanLumi[k_cms_zz_f5z]            = "19.6 fb^{-1}";
  chanExp[k_cms_zz_f5z]            = "CMS";
  chanaTGCC[k_cms_zz_f5z]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zz_f5z]  = -0.04 * scale_; 
  chanaTGCP[k_cms_zz_f5z]  = +0.04 * scale_; 
  plotChan[k_cms_zz_f5z] = true;

// CMS 

  chanName[k_cms_zz2_f5z]            = "f^{Z}_{5}";
  chanMeasurement[k_cms_zz2_f5z]     = "ZZ (2l2#nu)";
  chanLumi[k_cms_zz2_f5z]            = "24.7 fb^{-1}";
  chanExp[k_cms_zz2_f5z]            = "CMS";
  chanaTGCC[k_cms_zz2_f5z]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zz2_f5z]  = -0.029 * scale_; 
  chanaTGCP[k_cms_zz2_f5z]  = +0.030 * scale_; 
  plotChan[k_cms_zz2_f5z] = true;

// CMS 

  chanName[k_cms_zzc_f5z]            = "f^{Z}_{5}";
  chanMeasurement[k_cms_zzc_f5z]     = "ZZ (comb)";
  chanLumi[k_cms_zzc_f5z]            = "24.7 fb^{-1}";
  chanExp[k_cms_zzc_f5z]            = "CMS";
  chanaTGCC[k_cms_zzc_f5z]  = 0.0   * scale_; 
  chanaTGCM[k_cms_zzc_f5z]  = -0.022 * scale_; 
  chanaTGCP[k_cms_zzc_f5z]  = +0.023 * scale_; 
  plotChan[k_cms_zzc_f5z] = true;


  // CDF, D0, LEP not competative -0.05  -0.12 


  }






for( size_t ii=0; ii<k_nChan; ii++ )
  {
    if (plotChan[ii]) nPlotChan++;
  }





     for( size_t ii=0; ii<k_nChan; ii++ )
	{
ostringstream stream1, stream2, stream3;
stream1.precision(3);
stream2.precision(3);
stream3.precision(3);
 stream1 << fixed;
 stream2 << fixed;
 stream3 << fixed;
 if (catgcz || catgcg) {
stream1<< (chanaTGCC[ii]);    // for fixed point notation
stream2<<(chanaTGCM[ii]);    // for fixed point notation
stream3<<(chanaTGCP[ii]);    // for fixed point notation
chanResult[ii] = stream2.str() + " - " + stream3.str();
 } else {
stream1<< (chanaTGCC[ii]*0.1);    // for fixed point notation
 stream2<<(chanaTGCM[ii]*0.1);    // for fixed point notation
stream3<<(chanaTGCP[ii]*0.1);    // for fixed point notation
chanResult[ii] = stream2.str() + " - " + stream3.str();


 }

	}

  bool verbose_(true);
  if( verbose_ )
    {
      for( size_t ii=0; ii<k_nChan; ii++ )
	{
	  cout << chanName[ii]
               << chanMeasurement[ii] 
	       << " " << chanaTGCC[ii]
	       << " : " << chanaTGCM[ii]
	       << " -- " << chanaTGCP[ii]
	       << endl;
	}
    }
