#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>



#include "TStyle.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TLatex.h"
#include "TFrame.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TMarker.h"
#include "TLine.h"
#include "TBox.h"

using namespace std;

// titles and axis, marker size, etc.
float markerSize = 1.5;
float titleOffsetX = 0.8;
float titleOffsetY = 1.1;
float titleSizeX = 0.045;
float titleSizeY = 0.06;
float labelSizeX = 0.03;
float labelOffsetX = 0.005;
float labelOffsetY = 0.005;
float labelSizeY = 0.04;
int ndivx = 506;
int ndivy = 506;
float aspR = 1.4; 


// texts
size_t ntxt = 1;
vector<string> txt(100);
vector<float>  txtSize(100);
vector<float>  txtX(100);
vector<float>  txtY(100);
vector<int>    txtNDC(100);
vector<int>    txtAlign(100);
vector<int>    txtFont(100);
vector<int>    txtColor(100);
void text_init(bool PaperVersion);
void text_reset();
void text_write();

// drawings
void draw_bin_grid( float xmin, float xmax, float ymin, float ymax, 
		    int iCol=kGray+2, int iStyle=kDotted );
// constants
const float W_br_lnu    = 10.800e-02;
const float Z0_br_ll    =  3.366e-02;
const float Z0_br_nunu    =  20.00-02;


int version = 0;
bool plotVJets = false;
// version 0 standard log plot
// version 1 depreciated - should delete
// version 2 ratio


class DataPoint
{
public: 

  DataPoint( float sigma, float e_stat, float e_tot, 
	     float sigma_theo, float e_theo,
	     float ypos, float dy, int type) 
    : _sigma(sigma), _e_stat(e_stat), _e_tot(e_tot),
      _sigma_theo(sigma_theo), _e_theo(e_theo),
      _ypos(ypos), _dy(dy), _type(type)
  {
  }

  virtual ~DataPoint() 
  {
  }

  void draw()
  {
    if (_type==13) 
       {
	_theoColor = kBlue;
        _expCircleColor = kBlack;
        _expFillColor = kBlack;
        _expMarkerType = kFullCircle;
       } else if (_type == 8)    {
	_theoColor = kBlue;
        _expCircleColor = kRed;
        _expFillColor = kRed;
        _expMarkerType = kFullTriangleUp;
      } else if (_type == 7)
      {
	_theoColor = kBlue;
        _expCircleColor = kBlack;
         _expFillColor = kWhite;
	 _expMarkerType = kOpenCircle;

      } else if (_type == 5)
      {
	_theoColor = kBlue;
        _expCircleColor = kRed;
         _expFillColor = kWhite;
	 _expMarkerType = kOpenTriangleUp;

      } else
      {
	_theoColor = kBlue;
        _expFillColor = kWhite;
      }
   
   
    if( _sigma>0 )
      {
    


	//TBox _theoBox(_xpos-_dx/2.,(_sigma_theo-_e_theo) , _xpos+_dx/2., (_sigma_theo+_e_theo));
  TBox _theoBox((_sigma_theo-_e_theo),_ypos-_dy/2.5, (_sigma_theo+_e_theo), _ypos+_dy/2.5);
  _theoBox.SetFillStyle(1001);
  _theoBox.SetFillColor( kOrange );
  _theoBox.DrawClone();
	



	TGraphErrors _dataTotPoint(1);
	_dataTotPoint.SetPoint(1, _sigma, _ypos );
	//_dataTotPoint.SetPointError( 1, _e_tot+_e_theo, 0 );
	_dataTotPoint.SetPointError( 1, _e_tot, 0 );
	_dataTotPoint.SetLineWidth(1);
	_dataTotPoint.SetLineColor(kBlack);
	_dataTotPoint.SetMarkerSize(0);
	_dataTotPoint.DrawClone("e");	

	TGraphErrors _dataExpPoint(1);
	_dataExpPoint.SetPoint(1, _sigma, _ypos );
	//_dataExpPoint.SetPointError( 1, _e_tot, 0 );
	_dataExpPoint.SetPointError( 1, _e_stat, 0 );
	_dataExpPoint.SetLineWidth(1);
	_dataExpPoint.SetLineColor(kRed);
	_dataExpPoint.SetMarkerSize(0);
	_dataExpPoint.DrawClone("e");	

 

	TMarker _dataPoint( _sigma, _ypos, kFullCircle );
 	_dataPoint.SetMarkerSize(markerSize);
	_dataPoint.SetMarkerStyle(_expMarkerType);
	_dataPoint.SetMarkerColor(_expFillColor);
	_dataPoint.DrawClone();
 	_dataPoint.SetMarkerColor(_expCircleColor);
	_dataPoint.DrawClone();
	
      }
    else if( _sigma<0 )
      {

	TGraphErrors _theoPoint(1);
	_theoPoint.SetMarkerSize(0);
	_theoPoint.SetLineColor(kBlue);
	_theoPoint.SetLineWidth(2);
	_theoPoint.SetPoint(1, _ypos, _sigma_theo );
	_theoPoint.SetPointError( 1, _dy/2., 0 );
	_theoPoint.DrawClone("ez");

 	TBox _limit(_ypos-_dy/5.,-_sigma, _ypos+_dy/5., -1.5*_sigma);
 	_limit.SetFillStyle(3354);
 	_limit.SetFillColor( kRed );
	_limit.DrawClone();

 	TGraphErrors _dataTotPoint(1);
 	_dataTotPoint.SetPoint(1, _ypos, -_sigma );
 	_dataTotPoint.SetPointError( 1, _dy/4., 0 );
 	_dataTotPoint.SetLineWidth(2);
 	_dataTotPoint.SetLineColor(kRed);
 	_dataTotPoint.SetMarkerSize(0);	
	_dataTotPoint.DrawClone("ez");

      }
    else
      {
	float dy_ = 1/2.5;




        if (version ==5)  _e_tot =  _e_tot/2.0;
        if (version ==6)  _e_tot =  _e_tot/2.0;

	if (version==5||version==10){

	TGraphErrors _dataTotPoint5Th(1);
	_dataTotPoint5Th.SetPoint(1, _ypos*0.345, _sigma_theo-1 );
	_dataTotPoint5Th.SetPointError( 1, _e_tot, 0 );
	_dataTotPoint5Th.SetLineWidth(1);
	_dataTotPoint5Th.SetLineColor(kBlack);
	_dataTotPoint5Th.SetMarkerSize(0);
	_dataTotPoint5Th.DrawClone("e");	

	TGraphErrors _dataTotPoint5(1);
	_dataTotPoint5.SetPoint(1, _ypos*0.345, _sigma_theo-1 );
	_dataTotPoint5.SetPointError( 1, _e_tot/2, 0 );
	_dataTotPoint5.SetLineWidth(1);
	_dataTotPoint5.SetLineColor(kRed);
	_dataTotPoint5.SetMarkerSize(0);
	_dataTotPoint5.DrawClone("e");	


 	TMarker _dataPoint5( _ypos*0.345, _sigma_theo-1, kFullCircle );
 	_dataPoint5.SetMarkerSize(markerSize);
	_dataPoint5.SetMarkerStyle(kOpenTriangleUp);
	_dataPoint5.SetMarkerColor(kRed);
	_dataPoint5.DrawClone();
	_dataPoint5.SetMarkerStyle(kOpenTriangleUp);
 	_dataPoint5.SetMarkerColor(kRed);
	_dataPoint5.DrawClone();





	}

	TGraphErrors _dataTotPointTh(1);
	_dataTotPointTh.SetPoint(1, _ypos*0.45, _sigma_theo-1 );
	_dataTotPointTh.SetPointError( 1.0, _e_tot, 0 );
	_dataTotPointTh.SetLineWidth(1);
	_dataTotPointTh.SetLineColor(kBlack);
	_dataTotPointTh.SetMarkerSize(0);
	_dataTotPointTh.DrawClone("e");	

	TGraphErrors _dataTotPoint(1);
	_dataTotPoint.SetPoint(1, _ypos*.45, _sigma_theo-1 );
	_dataTotPoint.SetPointError( 1.0, _e_tot/2, 0 );
	_dataTotPoint.SetLineWidth(1);
	_dataTotPoint.SetLineColor(kRed);
	_dataTotPoint.SetMarkerSize(0);
	_dataTotPoint.DrawClone("e");	


 	TMarker _dataPoint( _ypos*.45, _sigma_theo-1, kFullCircle );
 	_dataPoint.SetMarkerSize(markerSize);
	_dataPoint.SetMarkerColor(kWhite);
	_dataPoint.DrawClone();
	_dataPoint.SetMarkerStyle(kOpenCircle);
 	_dataPoint.SetMarkerColor(kBlack);
	_dataPoint.DrawClone();
	

	TGraphErrors _dataTotPoint8Th(1);
	_dataTotPoint8Th.SetPoint(1, _ypos*0.555, _sigma_theo-1 );
	_dataTotPoint8Th.SetPointError( 1, _e_tot, 0 );
	_dataTotPoint8Th.SetLineWidth(1);
	_dataTotPoint8Th.SetLineColor(kBlack);
	_dataTotPoint8Th.SetMarkerSize(0);
	_dataTotPoint8Th.DrawClone("e");	

	TGraphErrors _dataTotPoint8(1);
	_dataTotPoint8.SetPoint(1, _ypos*0.555, _sigma_theo-1 );
	_dataTotPoint8.SetPointError( 1, _e_tot/2, 0 );
	_dataTotPoint8.SetLineWidth(1);
	_dataTotPoint8.SetLineColor(kRed);
	_dataTotPoint8.SetMarkerSize(0);
	_dataTotPoint8.DrawClone("e");	


 	TMarker _dataPoint8( _ypos*0.555, _sigma_theo-1, kFullCircle );
 	_dataPoint8.SetMarkerSize(markerSize);
	_dataPoint8.SetMarkerStyle(kFullTriangleUp);
 	_dataPoint8.SetMarkerColor(kRed);
	_dataPoint8.DrawClone();
	_dataPoint8.SetMarkerStyle(kFullTriangleUp);
 	_dataPoint8.SetMarkerColor(kRed);
	_dataPoint8.DrawClone();

	
	TGraphErrors _dataTotPoint13Th(1);
	_dataTotPoint13Th.SetPoint(1, _ypos*0.66, _sigma_theo-1 );
	_dataTotPoint13Th.SetPointError( 1, _e_tot, 0 );
	_dataTotPoint13Th.SetLineWidth(1);
	_dataTotPoint13Th.SetLineColor(kBlack);
	_dataTotPoint13Th.SetMarkerSize(0);
	_dataTotPoint13Th.DrawClone("e");	

	TGraphErrors _dataTotPoint13(1);
	_dataTotPoint13.SetPoint(1, _ypos*0.66, _sigma_theo-1 );
	_dataTotPoint13.SetPointError( 1, _e_tot/2, 0 );
	_dataTotPoint13.SetLineWidth(1);
	_dataTotPoint13.SetLineColor(kRed);
	_dataTotPoint13.SetMarkerSize(0);
	_dataTotPoint13.DrawClone("e");	


 	TMarker _dataPoint13( _ypos*0.66, _sigma_theo-1, kFullCircle );
 	_dataPoint13.SetMarkerSize(markerSize);
	_dataPoint13.SetMarkerColor(kBlack);
	_dataPoint13.DrawClone();
	_dataPoint13.SetMarkerStyle(kFullCircle);
 	_dataPoint13.SetMarkerColor(kBlack);
	_dataPoint13.DrawClone();


	
	txt[ntxt] = "7,        8,       13     TeV CMS measurements";
	if (version==5) txt[ntxt] = "5.02,       7,          8,         13     TeV CMS measurements";
	txtSize[ntxt] = 0.03;
	txtX[ntxt] = _ypos*0.52;
	if (version==5) txtX[ntxt] = _ypos*0.32;
	if (version==6) txtX[ntxt] = _ypos*0.442;
	if (version==7) txtX[ntxt] = _ypos*0.42;
	txtY[ntxt] = _sigma_theo;
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;

	txt[ntxt] = "inner unc. (stat), outer (+sys)";
	txtSize[ntxt] = 0.03;
	txtX[ntxt] = _ypos*0.52;
	if (version==5) txtX[ntxt] = _ypos*0.719;
	if (version==6) txtX[ntxt] = _ypos*0.721;
	if (version==7) txtX[ntxt] = _ypos*0.42;
	txtY[ntxt] = _sigma_theo -1;
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;



	/* txt[ntxt] = "8 TeV CMS measurement (stat,stat+sys) "; */
	/* txtSize[ntxt] = 0.03; */
	/* txtX[ntxt] = _ypos*0.62; */
	/* if (version==6) txtX[ntxt] = _ypos*0.42; */
	/* if (version==7) txtX[ntxt] = _ypos*0.42; */
	/* txtY[ntxt] = _sigma_theo -1; */
 	/* txtAlign[ntxt] = 12; */
	/* txtFont[ntxt] = 42; */
	/* ntxt++; */

	/* txt[ntxt] = "13 TeV CMS measurement (stat,stat+sys) "; */
	/* txtSize[ntxt] = 0.03; */
	/* txtX[ntxt] = _ypos*0.62; */
	/* if (version==6) txtX[ntxt] = _ypos*0.42; */
	/* if (version==7) txtX[ntxt] = _ypos*0.42; */
	/* txtY[ntxt] = _sigma_theo -2; */
 	/* txtAlign[ntxt] = 12; */
	/* txtFont[ntxt] = 42; */
	/* ntxt++; */

	txt[ntxt] = "stat      sys";
	txtSize[ntxt] = 0.03;
	txtX[ntxt] = _ypos*0.88;
	if (version==5) txtX[ntxt] = _ypos*0.92;
	if (version==6) txtX[ntxt] = _ypos*0.95;
	if (version==7) txtX[ntxt] = _ypos*0.73;
	txtY[ntxt] = _sigma_theo -2.4;
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;

	
       txt[ntxt] = "Theory";
        txtSize[ntxt] = 0.03;
        txtX[ntxt] = 1.0;
        if (version == 5) txtX[ntxt] = 0.5;
        if (version == 7) txtX[ntxt] = 0.25;
        txtY[ntxt] = _sigma_theo;
        txtAlign[ntxt] = 22;
        txtFont[ntxt] = 42;
        ntxt++;




	float theoLow = 0.95;
	float theoHigh = 1.05;
	if (version==5 ){
	theoLow = 0.45;
	theoHigh = 0.55;
	}

    TBox _theoBox(theoLow,_sigma_theo -0.8 - _dy/2.8, theoHigh, _sigma_theo -0.8 + _dy/2.8);
  _theoBox.SetFillStyle(1001);
  _theoBox.SetFillColor( kOrange );
  _theoBox.DrawClone();


	// TGraphErrors _theoPoint(1);
	// _theoPoint.SetMarkerSize(0);
	// _theoPoint.SetLineColor(kOrange);
	// _theoPoint.SetLineWidth(5);
	// _theoPoint.SetPoint(1, 1.0, _sigma_theo/2.0+1.0 );
	// _theoPoint.SetPointError( 1, 0.0, _sigma_theo/2.0 +0.5);
	// _theoPoint.DrawClone("ez");



      }
  }

private:
  float _sigma;
  float _e_stat;
  float _e_tot;
  float _sigma_theo;
  float _e_theo;
  float _ypos;
  float _dy;
  int _theoColor;
  int _expFillColor;
  int _expCircleColor;
  int _expMarkerType;
  int _type;
};

TCanvas*
SigmaR(float ymin=0.009, float ymax=900000 )
{

#include "data.C"
  plotChan[k_exWW] = false; 
  if (version==6)  nPlotChan =  nPlotChan-1;
  
  if (version ==2) ymax = 4;

  float xAxisMin = -0.25;
  float xAxisMax = 4.25;

  if (version == 6) xAxisMax = 4.9;
  if (version == 7) xAxisMax = 8.0;
  if (PaperVersion && version == 6) xAxisMin = -1.4;
  if (PaperVersion && version == 6) xAxisMax = 3.7;
  if (PaperVersion && version == 5) xAxisMin = -0.8;
  if (PaperVersion && version == 5) xAxisMax = 3.1;
 

  text_init(PaperVersion);

  gStyle->SetEndErrorSize(8);
  gStyle->SetHatchesLineWidth(1);
  gStyle->SetHatchesSpacing(0.8);

  vector<string> cutName;
    
  int chanColor = kBlue;
  int type = 7;
 
  float shift_ = 1.5;
  if (version ==2) shift_ = 1.5;
  float size_  = 0.04;

  vector<int> channel_;
  vector<float> ypos_;
  vector<float> dy_;
  vector<float> vline_;
  vector<float> vmin_;
  vector<float> vmax_;
  vector<int>   vstyle_;

  size_t nBin_ = 1;


  size_t DY_;
  DY_=1;

  for( size_t ii=0; ii<k_nChan; ii++ )
    {
      if (plotChan[ii]) {
      channel_.push_back(ii);
      ypos_.push_back(nBin_-0.5*DY_);
      dy_.push_back(DY_);


      // txt[ntxt] = "~~";
      // txtSize[ntxt] = size_;
      // txtX[ntxt] =  xAxisMin + (xAxisMax-xAxisMin)*0.016;
      // txtY[ntxt] = nPlotChan - (nBin_) +1.5*DY_;
      // txtAlign[ntxt] = 12;
      // txtFont[ntxt] = 42;
      // ntxt++;

      if (PaperVersion) {


      txt[ntxt] = chanMeasurement[ii];
      txtSize[ntxt] = size_*0.8;
      txtX[ntxt] =  xAxisMin - (xAxisMax-xAxisMin)*0.02;
      if (version == 5) txtX[ntxt] =  xAxisMin - (xAxisMax-xAxisMin)*0.02;
      if (version == 6) txtX[ntxt] =  xAxisMin - (xAxisMax-xAxisMin)*0.02;
      txtY[ntxt] = nPlotChan - (nBin_) +1.5*DY_;
      txtAlign[ntxt] = 12;
      txtFont[ntxt] = 42;
      ntxt++;
      

	
      txt[ntxt] = chanPublication[ii];
      //txt[ntxt] = "#splitline{"+chanLumi[ii]+"}{"+chanPublication[ii]+"}";
      //txt[ntxt] = chanMeasurement[ii]+"  "+chanPublication[ii];
      
      cout << txt[ntxt] << endl;
      txtSize[ntxt] = size_*0.7;
      txtX[ntxt] =  xAxisMin + (xAxisMax-xAxisMin)*(0.04);
      if (version==5) txtX[ntxt] =  xAxisMin + (xAxisMax-xAxisMin)*(0.04);
      if (version==6) txtX[ntxt] =  xAxisMin + (xAxisMax-xAxisMin)*(0.09);
      txtY[ntxt] = nPlotChan - (nBin_) +1.5*DY_;
      txtAlign[ntxt] = 12;
      txtFont[ntxt] = 42;
      txtColor[ntxt] = kBlack;
      ntxt++;



      } else {
      
      txt[ntxt] = "#splitline{https://arxiv.org/abs/" + chanPreprint[ii] +"}{https://arxiv.org/abs/" + chanPreprint[ii]+"}";
	if (chanPublication[ii]=="") txt[ntxt] = "#splitline{"+chanPreprint[ii]+"}{"+chanPreprint[ii]+"}";
      cout << txt[ntxt] << endl;
      txtSize[ntxt] = size_*0.4;
      txtX[ntxt] =  xAxisMin - (xAxisMax-xAxisMin)*(0.01);
      txtY[ntxt] = nPlotChan - (nBin_) +1.5*DY_;
      txtAlign[ntxt] = 12;
      txtFont[ntxt] = 42;
      //Int_t transWhite = GetColorTransparent(kWhite, 0.0);
      txtColor[ntxt] = kWhite;
      ntxt++;


      txt[ntxt] = chanMeasurement[ii];
      txtSize[ntxt] = size_;
      txtX[ntxt] =  xAxisMin - (xAxisMax-xAxisMin)*0.011;
      txtY[ntxt] = nPlotChan - (nBin_) +1.5*DY_;
      txtAlign[ntxt] = 12;
      txtFont[ntxt] = 42;
      ntxt++;
      }
      
      txt[ntxt] = chanResult[ii];
      txtSize[ntxt] = size_*0.8;
      txtX[ntxt] = xAxisMin + (xAxisMax-xAxisMin)*0.8;
      if (version == 5) txtX[ntxt] = xAxisMin + (xAxisMax-xAxisMin)*0.8;
      if (version == 6) txtX[ntxt] = xAxisMin + (xAxisMax-xAxisMin)*0.82;
      txtY[ntxt] = nPlotChan - (nBin_) +1.5*DY_;
      txtAlign[ntxt] = 12;
      txtFont[ntxt] = 42;
      ntxt++;


      if (!PaperVersion) {
      txt[ntxt] = chanLumi[ii];
      txtSize[ntxt] = size_;
      txtX[ntxt] =  xAxisMin + (xAxisMax-xAxisMin)*0.87;
      txtY[ntxt] = nPlotChan - (nBin_) +1.55*DY_;
      txtAlign[ntxt] = 12;
      txtFont[ntxt] = 42;
      ntxt++;
      }

      nBin_+=DY_;
      }
    }





 
  float xw_ = 1200;
  float yw_ = xw_/aspR;
 
  // the canvas
  TCanvas* c_=new TCanvas("SigmaR","sigma",300,300,xw_,yw_);
  c_->SetLeftMargin( 40./xw_ );
  c_->SetRightMargin( 40./xw_ );
  c_->SetTopMargin(  60./yw_ );
  c_->SetBottomMargin( 80./yw_ ); 
  c_->SetFillColor(0);
  c_->SetTickx(1);
  c_->SetTicky(1);
  c_->SetFrameFillStyle(0);
  c_->SetFrameLineWidth(2);
  c_->SetFrameBorderMode(0);

  TH1F* h_= new TH1F( "bidon", "bidon", 30, -2.0, 8.0);
  TAxis* ax_ = h_->GetXaxis();
  TAxis* ay_ = h_->GetYaxis();
  
  ax_->SetTitle("Production cross section ratio:   #sigma_{exp} / #sigma_{theo}");
  ax_->SetNdivisions(ndivx);
  ax_->SetTitleOffset(titleOffsetX);
  ax_->SetTitleSize(titleSizeX);
  ax_->SetLabelOffset(labelOffsetX);
  ax_->SetLabelSize(labelSizeX);

  ndivy = 0;
  ay_->SetTitle("");
  ay_->SetNdivisions(ndivy);
  ay_->SetTitleOffset(titleOffsetY);
  ay_->SetTitleSize(titleSizeY);
  ay_->SetLabelOffset(labelOffsetY);
  ay_->SetLabelSize(labelSizeY);
  
  // now plotting
  c_->Draw();
  c_->cd();


  //  ***** Dynamically set y axis
  //  ***** Invert y axis
  c_->SetLogy(false);
  h_->GetYaxis()->SetRangeUser(0.5,nBin_+3.5);
  h_->GetXaxis()->SetRangeUser(xAxisMin,xAxisMax);
  h_->Draw("hist][");
  

  //Convert cross sections to ratios
      for( size_t ii=0; ii<k_nChan; ii++ )
	{
          chanSigma[ii] = chanSigma[ii]/chanTheo[ii];
          chanETot[ii] = chanETot[ii]/chanTheo[ii];
          chanEStat[ii]= chanEStat[ii]/chanTheo[ii];
          chanETheo[ii]= chanETheo[ii]/chanTheo[ii];
          chanTheo[ii] = 1.0;
	}

  float yy_ = nBin_+2.5;
  float xx_ = xAxisMin + (xAxisMax-xAxisMin)*0.93;
  float dyx_ = 1.2;
  if (version == 6) float xx_ = xAxisMin + (xAxisMax-xAxisMin)*0.93;
  DataPoint p_( 0, 0, 0.2, 
		yy_, 0,
		xx_, dyx_, type ) ;
  p_.draw();



  for( size_t ii=0; ii<channel_.size(); ii++ )
    {
      size_t iChan = channel_[ii];
      float xx_ = nBin_-ypos_[ii];
      float dyy_ = dy_[ii];
      type = 7;
      if  (iChan  == k_W8) type = 8;
      if  (iChan  == k_Z8) type = 8;
      if  (iChan  == k_Wg13) type = 13;
      if  (iChan  == k_Zg8) type = 8;
      if  (iChan  == k_WW8) type = 8;
      if  (iChan  == k_WZ8) type = 8;
      if  (iChan  == k_ZZ8) type = 8;
      if  (iChan  == k_WW13fid) type = 13;
      if  (iChan  == k_WW13) type = 13;
      if  (iChan  == k_WZ13) type = 13;
      if  (iChan  == k_WZ13fid) type = 13;
      if  (iChan  == k_ZZ13) type = 13;
      if  (iChan  == k_ZZ13fid) type = 13;
      if  (iChan  == k_WW5) type = 5;
      if  (iChan  == k_WZ5) type = 5;
      if  (iChan  == k_ZZ5) type = 5;
 
      if  (iChan  == k_VBFZ8) type = 8;
     if  (iChan  == k_VBFW8) type = 8;
     if  (iChan  == k_VBFW13) type = 13;
      if  (iChan  == k_VBFZ13) type = 13;
      if  (iChan  == k_exWW8) type = 8;
      if  (iChan  == k_EWKWV13) type = 13;
      if  (iChan  == k_EWKWW13) type = 13;
      if  (iChan  == k_SSWW8) type = 8;
      if  (iChan  == k_SSWW13) type = 13;
      if  (iChan  == k_EWKWg8) type = 8;
      if  (iChan  == k_EWKWg13) type = 13;
      if  (iChan  == k_EWKZg8) type = 8;
      if  (iChan  == k_EWKZg13) type = 13;
      if  (iChan  == k_EWKWZ13) type = 13;
     if  (iChan  == k_EWKZZ13) type = 13;


  if  (iChan == k_VVV13) type = 13;
  if  (iChan == k_WWW13) type = 13;
  if  (iChan == k_WWZ13) type = 13;
  if  (iChan == k_WZZ13) type = 13;
  if  (iChan == k_ZZZ13) type = 13;
  if  (iChan == k_WVg) type = 8;
  if  (iChan == k_WWg13) type = 13;
  if  (iChan == k_Wgg8) type = 8;
  if  (iChan == k_Zgg8) type = 8;
  if  (iChan == k_Wgg13) type = 13;
  if  (iChan == k_Zgg13) type = 13;


       
      if (version ==2 && ( 
      (iChan  == k_W1jet) ||(iChan  == k_W2jet) || (iChan  == k_W3jet) ||(iChan  == k_W4jet) ||
      (iChan  == k_Z1jet) ||(iChan  == k_Z2jet) || (iChan  == k_Z3jet) ||(iChan  == k_Z4jet) )) type = 71;

      if (type != 71){
      DataPoint p_( chanSigma[iChan], chanEStat[iChan], chanETot[iChan], 
		    chanTheo[iChan], chanETheo[iChan],
		    xx_, dyy_ , type) ;
      p_.draw();
      }
    }
  
  for( size_t ii=0; ii<vline_.size(); ii++ )
    {
      draw_bin_grid( vline_[ii], vline_[ii], vmin_[ii]*ymin, ymax/vmax_[ii],
		     kGray+2, vstyle_[ii] );
    }

  c_->RedrawAxis();
  c_->GetFrame()->Draw();

  text_write();    

  return c_;
}

void draw_bin_grid( float xmin, float xmax, float ymin, float ymax, int iCol, int iStyle )
{
  TLine grid_;
  grid_.SetLineColor(iCol);
  grid_.SetLineStyle(iStyle);
  grid_.DrawLine(xmin,ymin,xmax,ymax);
}

void text_reset()
{
  for( size_t ii=0; ii<100; ii++ )
    {
      txt[ii]="";
      txtX[ii]=0.50;
      txtY[ii]=0.50;
      txtSize[ii]=0.050;
      txtAlign[ii]=11;
      txtFont[ii]=42;
      txtColor[ii]=kBlack;
      txtNDC[ii]=false;
    }
}

void text_init(bool PaperVersion)
{
  text_reset();

  ntxt = 5;

  txt[0] = "CMS Preliminary";
  if (PaperVersion) txt[0] = "CMS";
  txtSize[0] = 0.060;
  txtX[0] = 0.97;
  if (PaperVersion) txtX[0] = 0.96;
  txtY[0] = 0.945;
  txtAlign[0] = 31;
  txtNDC[0]=true;
  txtFont[0] = 42;

  if (version ==5) txt[1] = "Diboson measurements vs. NNLO theory";
  if (version ==6) txt[1] = "EW measurements vs. theory";
  if (version ==7) txt[1] = "CMS measurements";
  txtSize[1] = 0.04;
  txtX[1] = 0.04;
  txtY[1] = 0.95;
  txtAlign[1] = 11;
  txtNDC[1]=true;
  txtFont[1] = 42;

  if (PaperVersion) {

  if (version ==5) txt[3] = "(NLO W#gamma, Z#gamma 7 TeV)";
  txtSize[3] = 0.04;
  txtX[3] = 0.04;
  txtY[3] = 0.88;
  txtAlign[3] = 11;
  txtNDC[3]=true;
  txtFont[3] = 42;

  }

  
  if (!PaperVersion) {
  txt[2] = "Aug 2023";
  txtSize[2] = 0.03;
  txtX[2] = 0.18;
  txtY[2] = 0.965;
  txtAlign[2] = 31;
  txtNDC[2]=true;
  txtFont[2] = 42;

  txt[3] = "All results at:";
  txtSize[3] = 0.03;
  txtX[3] = 0.10;
  txtY[3] = 0.04;
  txtAlign[3] = 21;
  txtNDC[3]=true;
  txtFont[3] = 42;
  
  txt[4] = "http://cern.ch/go/pNj7";
  txtSize[4] = 0.03;
  txtX[4] = 0.10;
  txtY[4] = 0.012;
  txtAlign[4] = 21;
  txtNDC[4]=true;
  txtFont[4] = 42;
  txtColor[4]=kBlack;
  }

  
  // txt[4] = "CMS Summary Plots";
  // txtSize[4] = 0.03;
  // txtX[4] = 0.15;
  // txtY[4] = 0.012;
  // txtAlign[4] = 21;
  // txtNDC[4]=true;
  // txtFont[4] = 42;
  // txtColor[4]=kBlack;

  
  
}

void
text_write()
{  
  for( size_t ii=0; ii<ntxt; ii++ )
    { 
      TLatex latex;
      if( txtNDC[ii] ) latex.SetNDC();    
      latex.SetTextFont(txtFont[ii]);
      latex.SetTextSize(txtSize[ii]);    
      latex.SetTextColor(txtColor[ii]);    
      if (txtColor[ii] == kWhite) latex.SetTextColorAlpha(txtColor[ii],0.01);    
      latex.SetTextAlign(txtAlign[ii]); 
      latex.DrawLatex(txtX[ii],txtY[ii],txt[ii].c_str());
    }
}

