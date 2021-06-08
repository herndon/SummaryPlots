#include <iostream>
#include <sstream>
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
float markerSize = 1.0;
float titleOffsetX = 1.0;
float titleOffsetY = 0.8;
float titleSizeX = 0.03;
float titleSizeY = 0.05;
float labelSizeX = 0.05;
float labelOffsetX = 0.006;
float labelOffsetY = 0.004;
float labelSizeY = 0.045;
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
void text_init();
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

class DataPoint
{
public: 

  DataPoint( float sigma, float e_stat, float e_tot, 
	     float sigma_theo, float e_theo,
	     float xpos, float dx, int type) 
    : _sigma(sigma), _e_stat(e_stat), _e_tot(e_tot),
      _sigma_theo(sigma_theo), _e_theo(e_theo),
      _xpos(xpos), _dx(dx), _type(type)
  {
  }

  virtual ~DataPoint() 
  {
  }

  void draw()
  {
    int _theoColorG= 15;
    int _expColor7 = kRed;
    int _expColor8 = kBlue;
    int	_expColor13 = 209;

    if (_type==8||_type==18) 
      {
	_theoColor = 209;
	_theoColor = _theoColorG;
        _expLineColor = _expColor8;
        _expFillColor = _expColor8;
      } else if (_type == 7)
      {
	_theoColor = kBlue;
	_theoColor = _theoColorG;
        _expLineColor = _expColor7;
        _expFillColor = _expColor7;
      }  else if (_type == 13)
      {
	//_theoColor = 221;
	_theoColor = kBlack;
	_theoColor = _theoColorG;
        _expLineColor = _expColor13;
        _expFillColor = _expColor13;
      } else
      {
      }
   
   
    if( _sigma>0 )
      {

 	TBox _theoBox(_xpos-_dx/2.,(_sigma_theo-_e_theo) , _xpos+_dx/2., (_sigma_theo+_e_theo));
 	_theoBox.SetFillStyle(1001);
 	_theoBox.SetFillColor( _theoColor );
	_theoBox.DrawClone();



// 	TGraphErrors _dataTotPoint(1);
// 	_dataTotPoint.SetPoint(1, _xpos, _sigma );
// 	_dataTotPoint.SetPointError( 1, 0, _e_tot+_e_theo );
// 	_dataTotPoint.SetLineWidth(1);
// 	_dataTotPoint.SetLineColor(kBlack);
// 	_dataTotPoint.SetMarkerSize(0);
// 	_dataTotPoint.DrawClone("e");	

	TGraphErrors _dataExpPoint(1);
	_dataExpPoint.SetPoint(1, _xpos, _sigma );
	_dataExpPoint.SetPointError( 1, 0,_e_tot );
	_dataExpPoint.SetLineWidth(1);
	_dataExpPoint.SetLineColor(_expLineColor);
	_dataExpPoint.SetMarkerSize(0);
	_dataExpPoint.DrawClone("e");	

 

	  TMarker _dataPoint( _xpos, _sigma, kOpenSquare );
	  _dataPoint.SetMarkerStyle(kOpenSquare);
	  _dataPoint.SetMarkerSize(markerSize);
	  _dataPoint.SetMarkerColor(_expLineColor);
	  _dataPoint.DrawClone();
	  _dataPoint.SetMarkerSize(markerSize*0.9);
	  _dataPoint.DrawClone();
	  _dataPoint.SetMarkerSize(markerSize*0.8);
	  _dataPoint.DrawClone();





// 	TGraphErrors _theoPoint(1);
// 	_theoPoint.SetMarkerSize(0);
// 	_theoPoint.SetLineColor(_theoColor);
// 	_theoPoint.SetLineWidth(2);
// 	_theoPoint.SetPoint(1, _xpos, _sigma_theo );
// 	_theoPoint.SetPointError( 1, _dx/2., 0 );
// 	_theoPoint.DrawClone("ez");


	
      }
    else if( _sigma<0 )
      {

// 	TGraphErrors _theoPoint(1);
// 	_theoPoint.SetMarkerSize(0);
// 	_theoPoint.SetLineColor(_theoColor);
// 	_theoPoint.SetLineWidth(2);
// 	_theoPoint.SetPoint(1, _xpos, _sigma_theo );
// 	_theoPoint.SetPointError( 1, _dx/2., _e_theo );
// 	_theoPoint.DrawClone("ez");


 	TBox _theoBox(_xpos-_dx/2.,(_sigma_theo-_e_theo) , _xpos+_dx/2., (_sigma_theo+_e_theo));
 	_theoBox.SetFillStyle(1001);
 	_theoBox.SetFillColor( _theoColor );
	_theoBox.DrawClone();


 	TBox _limit(_xpos-_dx/5.,-_sigma, _xpos+_dx/5., -1.5*_sigma);
 	_limit.SetFillStyle(3254);
 	if (_type==18) _limit.SetFillStyle(3244);
 	_limit.SetFillColor( _expLineColor );
	_limit.DrawClone();

 	TGraphErrors _dataTotPoint(1);
 	_dataTotPoint.SetPoint(1, _xpos, -_sigma );
 	_dataTotPoint.SetPointError( 1, _dx/3., 0 );
 	_dataTotPoint.SetLineWidth(2);
 	_dataTotPoint.SetLineColor(_expLineColor);
 	_dataTotPoint.SetMarkerSize(0);	
	_dataTotPoint.DrawClone("ez");


     }
    else
      {
	float dy_ = 1/2.0;
        if (version <= 2 || version == 6 || version == 7 || version == 6 ) _dx = _dx*2.0;

	if (version !=3 && version != 4 && version != 6 && version != 7) {
       
	  if (version != 9) {
	 TBox _limit(_xpos-_dx/3., _sigma_theo*0.9*dy_, 
		    _xpos+_dx/3., 1.5*_sigma_theo*0.9*dy_);
 	_limit.SetFillStyle(3254);
 	_limit.SetFillColor( kRed );
	_limit.DrawClone();

 	TGraphErrors _limitLine(1);
 	_limitLine.SetPoint(1, _xpos, _sigma_theo*0.9*dy_ );
 	_limitLine.SetPointError( 1, _dx/2., 0 );
 	_limitLine.SetLineWidth(2);
 	_limitLine.SetLineColor(kRed);
 	_limitLine.SetMarkerSize(0);	
	_limitLine.DrawClone("ez");
	 
	
  	TBox _limit8(_xpos + 1.5*_dx - _dx/3., _sigma_theo*0.9*dy_, 
		     _xpos + 1.5*_dx + _dx/3., 1.5*_sigma_theo*0.9*dy_);
 	_limit8.SetFillStyle(3254);
 	_limit8.SetFillColor( kBlue );
	_limit8.DrawClone();

	TGraphErrors _limitLine8(1);
 	_limitLine8.SetPoint(1, _xpos + 1.5*_dx , _sigma_theo*0.9*dy_ );
 	_limitLine8.SetPointError( 1, _dx/2., 0 );
 	_limitLine8.SetLineWidth(2);
 	_limitLine8.SetLineColor(kBlue);
 	_limitLine8.SetMarkerSize(0);	
	_limitLine8.DrawClone("ez");

  	TBox _limit13(_xpos + 3.0*_dx - _dx/3., _sigma_theo*0.9*dy_, 
		     _xpos + 3.0*_dx + _dx/3., 1.5*_sigma_theo*0.9*dy_);
 	_limit13.SetFillStyle(3254);
 	_limit13.SetFillColor(_expColor13 );
	_limit13.DrawClone();

	TGraphErrors _limitLine13(1);
 	_limitLine13.SetPoint(1, _xpos + 3.0*_dx , _sigma_theo*0.9*dy_ );
 	_limitLine13.SetPointError( 1, _dx/2., 0 );
 	_limitLine13.SetLineWidth(2);
 	_limitLine13.SetLineColor(_expColor13);
 	_limitLine13.SetMarkerSize(0);	
	_limitLine13.DrawClone("ez");
	  } else{

 	TBox _limit8(_xpos - _dx/3., _sigma_theo*0.9*dy_, 
		     _xpos + _dx/3., 1.5*_sigma_theo*0.9*dy_);
 	_limit8.SetFillStyle(3254);
 	_limit8.SetFillColor( kBlue );
	_limit8.DrawClone();

	TGraphErrors _limitLine8(1);
 	_limitLine8.SetPoint(1, _xpos , _sigma_theo*0.9*dy_ );
 	_limitLine8.SetPointError( 1, _dx/2., 0 );
 	_limitLine8.SetLineWidth(2);
 	_limitLine8.SetLineColor(kBlue);
 	_limitLine8.SetMarkerSize(0);	
	_limitLine8.DrawClone("ez");

  	TBox _limit13(_xpos + 1.5*_dx - _dx/3., _sigma_theo*0.9*dy_, 
		     _xpos + 1.5*_dx + _dx/3., 1.5*_sigma_theo*0.9*dy_);
 	_limit13.SetFillStyle(3254);
 	_limit13.SetFillColor(_expColor13 );
	_limit13.DrawClone();

	TGraphErrors _limitLine13(1);
 	_limitLine13.SetPoint(1, _xpos + 1.5*_dx , _sigma_theo*0.9*dy_ );
 	_limitLine13.SetPointError( 1, _dx/2., 0 );
 	_limitLine13.SetLineWidth(2);
 	_limitLine13.SetLineColor(_expColor13);
 	_limitLine13.SetMarkerSize(0);	
	_limitLine13.DrawClone("ez");


	  }

	    

	
	}

	//_sigma_theo = 5.169*1000.*1000.;
        _e_tot = _e_tot/1.5;

	if (version !=7 && version != 9) {
	TGraphErrors _dataTotPoint(1);
	_dataTotPoint.SetPoint(1, _xpos, _sigma_theo/(dy_*dy_*dy_) );
	_dataTotPoint.SetPointError( 1, 0, _e_tot/(dy_*dy_*dy_) );
	_dataTotPoint.SetLineWidth(1);
	_dataTotPoint.SetLineColor(_expColor7);
	_dataTotPoint.SetMarkerSize(0);
	_dataTotPoint.DrawClone("e");	

 	TMarker _dataPoint( _xpos, _sigma_theo/(dy_*dy_*dy_), kOpenSquare );
 	_dataPoint.SetMarkerSize(markerSize);
	_dataPoint.SetMarkerColor(_expColor7);
	_dataPoint.DrawClone();
       	_dataPoint.SetMarkerSize(markerSize*0.9);
	_dataPoint.DrawClone();
 	_dataPoint.SetMarkerSize(markerSize*0.8);
	_dataPoint.DrawClone();
 


	TGraphErrors _dataTotPoint8(1);
	_dataTotPoint8.SetPoint(1, _xpos, _sigma_theo/(dy_*dy_) );
	_dataTotPoint8.SetPointError( 1, 0, _e_tot/(dy_*dy_) );
	_dataTotPoint8.SetLineWidth(1);
	_dataTotPoint8.SetLineColor(_expColor8);
	_dataTotPoint8.SetMarkerSize(0);
	_dataTotPoint8.DrawClone("e");	

 	TMarker _dataPoint8( _xpos, _sigma_theo/(dy_*dy_), kOpenSquare );
 	_dataPoint8.SetMarkerSize(markerSize);
	_dataPoint8.SetMarkerColor(_expColor8);
	_dataPoint8.DrawClone();
 	_dataPoint8.SetMarkerSize(markerSize*0.9);
	_dataPoint8.DrawClone();
 	_dataPoint8.SetMarkerSize(markerSize*0.8);
	_dataPoint8.DrawClone();

	}

 if (version != 20 && version != 9) {
	TGraphErrors _dataTotPoint13(1);
	_dataTotPoint13.SetPoint(1, _xpos, _sigma_theo/(dy_) );
	_dataTotPoint13.SetPointError( 1, 0, _e_tot/(dy_) );
	_dataTotPoint13.SetLineWidth(1);
	_dataTotPoint13.SetLineColor(_expColor13);
	_dataTotPoint13.SetMarkerSize(0);
	_dataTotPoint13.DrawClone("e");	

 	TMarker _dataPoint13( _xpos, _sigma_theo/(dy_), kOpenSquare );
 	_dataPoint13.SetMarkerSize(markerSize);
	_dataPoint13.SetMarkerColor(_expColor13);
	_dataPoint13.DrawClone();
	_dataPoint13.SetMarkerSize(markerSize*0.9);
	_dataPoint13.DrawClone();
 	_dataPoint13.SetMarkerSize(markerSize*0.8);
	_dataPoint13.DrawClone();
 
}
	TGraphErrors _theoPoint13(1);
	_theoPoint13.SetMarkerSize(0);
	_theoPoint13.SetLineColor(_theoColorG);
	_theoPoint13.SetLineWidth(2);
	_theoPoint13.SetPoint(1, _xpos, _sigma_theo );
	_theoPoint13.SetPointError( 1, _dx/2., 0 );
	_theoPoint13.DrawClone("ez");



	if (version != 3 && version != 4 && version !=6 && version !=7) {
	txt[ntxt] = "CMS 95%CL limits at 7, 8 and 13 TeV";
	if (version == 9) txt[ntxt] = "CMS 95%CL limits at 8 and 13 TeV";
	txtSize[ntxt] = 0.025;
	txtX[ntxt] = _xpos + 4.0*_dx;
	txtY[ntxt] = _sigma_theo*dy_;
	if (version ==9) txtX[ntxt] = _xpos + 2.2*_dx;
	if (version ==9) txtY[ntxt] = _sigma_theo*dy_*1.1;
	if (version ==8) txtX[ntxt] = _xpos + 1.05*_dx;
	if (version ==8) txtY[ntxt] = _sigma_theo*dy_*0.5;
	if (version ==8) txtX[ntxt] = _xpos + 4.0*_dx;
	if (version ==8) txtY[ntxt] = _sigma_theo*dy_*1.1;

	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;
	}

  if (version !=7 && version != 9){
	//cout << "_sigma_theo="<<_sigma_theo << endl;
	txt[ntxt] = "7 TeV CMS measurement (L #leq 5.0 fb^{-1})";
	txtSize[ntxt] = 0.025;
	txtX[ntxt] = _xpos + _dx;
	txtY[ntxt] = _sigma_theo/(dy_*dy_*dy_);
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;


	txt[ntxt] = "8 TeV CMS measurement (L #leq 19.6 fb^{-1})";
	txtSize[ntxt] = 0.025;
	txtX[ntxt] = _xpos + _dx;
	txtY[ntxt] = _sigma_theo/(dy_*dy_);
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;
  }
if (version !=20 && version != 9){
	txt[ntxt] = "13 TeV CMS measurement (L #leq 137 fb^{-1})";
	txtSize[ntxt] = 0.025;
	txtX[ntxt] = _xpos + _dx;
	txtY[ntxt] = _sigma_theo/(dy_);
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;
}

	txt[ntxt] = "Theory prediction";
	txtSize[ntxt] = 0.025;
	txtX[ntxt] = _xpos + _dx;
	if (version ==9) txtX[ntxt] = _xpos + 2.2*_dx;
	txtY[ntxt] = _sigma_theo;
	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;

	ntxt++;

      }
  }


private:
  float _sigma;
  float _e_stat;
  float _e_tot;
  float _sigma_theo;
  float _e_theo;
  float _xpos;
  float _dx;
  int _theoColor;
  int _expFillColor;
  int _expLineColor;
  int _type;
};

TCanvas*
// version 0-2 ymin 0.0001, ymax 600000
// version 3  ymin 0.00003 ymax 30000, 
// version 4 ymin=0.005, float ymax=  50000000
// version 6 ymin 0.0001, ymax 50
// version 7 ymin 5.0, ymax 600000
// version 8 ymin 0.0003, ymax 3000
// version 9 ymin 0.001, ymax 1000
Sigma(float ymin=0.00001, float ymax=600000 )
{

#include "data.C"

  text_init();

  gStyle->SetEndErrorSize(5);
  gStyle->SetHatchesLineWidth(1);
  gStyle->SetHatchesSpacing(0.8);

  vector<string> cutName;
    
  int type = 7;
 
  float size_  = 0.02;

  vector<int> channel_;
  vector<float> xpos_;
  vector<float> dx_;
  vector<float> vline_;
  vector<float> vmin_;
  vector<float> vmax_;
  vector<int>   vstyle_;

  float nBin_ = 0;
  float DX_,stdDX_;  
  int nChan_ = 0;
  int nSubChan_ = 0;
  DX_=20;
  stdDX_=20;

  float ledgendY = 0.0;


  string prevChanMeasurement = "none";

  vline_.push_back( nBin_ );
  vmin_.push_back( 0. );
  vmax_.push_back( 1. );
  vstyle_.push_back(3);


      for( size_t ii=0; ii<k_nChan; ii++ )
	{
	  if (plotChan[ii]) {
            if (ledgendY == 0 && chanSigma[ii] != 0.0) {
	      ledgendY = chanSigma[ii];
	      if (ledgendY < 0.0) ledgendY = ledgendY*-1.0;
                ledgendY*=0.5; 
		// Sometimes the automation using the highest xsection channel doesn't work.  Should resolve
	     if (version == 6 ) ledgendY*=15.0;
             if (version == 8) ledgendY*=5.0;
	     if (version == 9 ) ledgendY*=1500.0;
	    }
	    DX_=stdDX_;

	    // Detect channels with 7, 8, 13 TeV Measurements
	    if (ii==0){
	      if (chanMeasurement[ii]==chanMeasurement[ii+1]) DX_ = stdDX_/2;
              if (chanMeasurement[ii]==chanMeasurement[ii+2])  DX_ = stdDX_/3;
             nSubChan_ = 0;
	    } else if (ii==(k_nChan-1)) {
	      if (chanMeasurement[ii]==chanMeasurement[ii-1]) {
		DX_ = stdDX_/2.0;
		nSubChan_ = 1;
              if (chanMeasurement[ii]==chanMeasurement[ii-2])  DX_ = stdDX_/3;
	      }
	    } else if (ii==1) {
	      if (chanMeasurement[ii]==chanMeasurement[ii-1]) DX_ = stdDX_/2;
	      nSubChan_ = 1;
 	      if (chanMeasurement[ii]==chanMeasurement[ii+1]) DX_ = stdDX_/3;
	    }  else if (ii==(k_nChan-1)) {
	      if (chanMeasurement[ii]==chanMeasurement[ii-1]) DX_ = stdDX_/2;
 	      if (chanMeasurement[ii]==chanMeasurement[ii+1]) DX_ = stdDX_/3;
	    } else if (chanMeasurement[ii]==chanMeasurement[ii-1]) {
	      DX_ = stdDX_/2.0;
              nSubChan_ = 1;
              if (chanMeasurement[ii]==chanMeasurement[ii-2]) { 
		nSubChan_ = 0;
 		DX_ = stdDX_/3;
	      }
              if (chanMeasurement[ii]==chanMeasurement[ii+1])  DX_ = stdDX_/3;
            }else if (chanMeasurement[ii]==chanMeasurement[ii+1]) {
	      DX_ = stdDX_/2.0;
              nSubChan_ = 0;
	      if (chanMeasurement[ii]==chanMeasurement[ii+2])  {
		DX_ = stdDX_/3;
                nSubChan_ = 0;
	      }
	    }
            if (ii==k_HHComb8){
		DX_ = stdDX_/2.0;
		nSubChan_ = 0;
	    }
            if (ii==k_HHbbgg13){
		DX_ = stdDX_/2.0;
		nSubChan_ = 1;
	    }
            if (version == 7||version==6||version==9){
              cout << chanMeasurement[ii] << " " << stdDX_ << " " << DX_ << " " << nSubChan_ << endl;
              nSubChan_ = 1;
	      DX_ = stdDX_;
	    }

            // handle the number of jets
            if (subChan[ii] > 2){
              DX_=stdDX_/subChan[ii];
	      if (chanMeasurement[ii].find("1j") < 100 && (ii!=k_tt1jet8)&& (ii!=k_tt1jet13)){
		nBin_-=stdDX_; 
	      }
	    } 

	    nBin_+=DX_/2.0;
	    nChan_++;


	    channel_.push_back(ii);
	    xpos_.push_back(nBin_);
	    dx_.push_back(DX_);
            if ((version<3&&ii==k_ggH)||(version==4&&ii==k_Hgg)){
	      txt[ntxt] = "Th. #Delta#sigma_{H} in exp. #Delta#sigma" ;
              txtSize[ntxt] = size_;
	      txtY[ntxt] = ymin*0.25;
	      txtX[ntxt] = nBin_-0.5*DX_;
              if (version==4&&ii==k_Hgg) txtX[ntxt] += 4;
	      txtAlign[ntxt] = 21;
	      txtAlign[ntxt] = 11;
	      txtFont[ntxt] = 42;
	      ntxt++;
	    }
            if ((version<3&&ii==k_VBFW8)||(version==4&&ii==k_VBFW8)){
	      txt[ntxt] = "EW,Z#gamma#gamma,W#gamma#gamma: fiducial with W#rightarrowl#nu, Z#rightarrowll, l=e,#mu" ;
              txtSize[ntxt] = 0.015;
	      txtY[ntxt] = ymin*0.25;
	      txtX[ntxt] = nBin_-0.0*DX_;
              if (version==4&&ii==k_VBFW8) txtX[ntxt] += 4;
	      txtAlign[ntxt] = 21;
	      txtAlign[ntxt] = 11;
	      txtFont[ntxt] = 42;
	      ntxt++;
	    }


	    if (version==3&&ii==k_Z){
	      txt[ntxt] = "Fiducial  W and Z #sigmas with W#rightarrowl#nu, Z#rightarrowll and kinematic selection" ;
             txtSize[ntxt] = size_;
	      txtY[ntxt] = ymin*0.24;
	      txtX[ntxt] = nBin_;
	      txtAlign[ntxt] = 21;
	      txtAlign[ntxt] = 11;
	      txtFont[ntxt] = 42;
	      ntxt++;
	    }

	    if (DX_==stdDX_ || ((DX_==(stdDX_/2)|| (DX_==(stdDX_/3))) && (nSubChan_==1))) {
	      txt[ntxt] = chanMeasurement[ii];
               txtSize[ntxt] = 0.015;
	      if (version==0) txtSize[ntxt] = 0.02;
	      //if (ii == k_SSWW8) txtSize[ntxt] = 0.0125;
	      if (version==4||version==8 || version == 9) txtSize[ntxt] = 0.025;
              txtY[ntxt] = ymin*0.5;
              if (version == 7)  txtY[ntxt] = ymin*0.75;
              if (version == 8)  txtY[ntxt] = ymin*0.65;
              if (version == 9)  txtY[ntxt] = ymin*0.55;
	      if (DX_==stdDX_) txtX[ntxt] = nBin_;
	      if (DX_==stdDX_/2) txtX[ntxt] = nBin_-0.5*DX_;
	      if (DX_==stdDX_/3) txtX[ntxt] = nBin_;
	      txtAlign[ntxt] = 21;
	      txtAlign[ntxt] = 21;
	      txtFont[ntxt] = 42;
              if (big13TeV&&(ii==k_W13 || ii== k_Z13 || ii==k_WZ13 || ii==k_ZZ13 ||ii==k_tt13||ii==k_t13) ) txtColor[ntxt]=kRed;
	      ntxt++;
	      if (DX_==stdDX_/2||DX_==stdDX_){
		vline_.push_back( nBin_+0.5*DX_);
		vmin_.push_back( 0 );
	      } else if (DX_==stdDX_/3){
		cout << "ii: " << ii << " k_tt: " << k_tt << endl;
		// if (ii == k_tt+1) vline_.push_back( nBin_+4.5*DX_);
		//if (ii != k_tt+1) vline_.push_back( nBin_+1.5*DX_);
		vline_.push_back( nBin_+1.5*DX_);
		vmin_.push_back( 0 );
	      }

	      if ((version==0 || version==2)&& nBin_ < 180 ) vmax_.push_back( 1. );
	      if ((version==0 || version==2)&& nBin_ > 180 ) vmax_.push_back( 200.0 );
	      if (version==1 && nBin_ < 280 ) vmax_.push_back( 1. );
	      if (version==1 && nBin_ > 280 ) vmax_.push_back( 200.0 );
	      if (version==3 && nBin_ < 200 ) vmax_.push_back( 1. );
	      if (version==3 && nBin_ > 200 ) vmax_.push_back( 30.0 );
	      if (version==4 && nBin_ < 30 ) vmax_.push_back( 1. );
	      if (version==4 && nBin_ > 30 ) vmax_.push_back( 200.0 );
	      if ((version==6)&& nBin_ < 80 ) vmax_.push_back( 1. );
	      if ((version==6)&& nBin_ > 80 ) vmax_.push_back( 40.0 );
	      if (version==7 && nBin_ < 50 ) vmax_.push_back( 1. );
	      if (version==7 && nBin_ > 50 ) vmax_.push_back( 200.0 );
	      if (version==8 && nBin_ < 170 ) vmax_.push_back( 1. );
	      if (version==8 && nBin_ > 170 ) vmax_.push_back( 100.0 );
	      if ((version==9)&& nBin_ < 40 ) vmax_.push_back( 1. );
	      if ((version==9)&& nBin_ > 40 ) vmax_.push_back( 40.0 );
	      vstyle_.push_back(3);
	    } 
	    if ( (version==0||version==8) && ii != k_tt1jet8  && ii != k_tt1jet13 && (chanMeasurement[ii] == "#geq1j" || chanMeasurement[ii] == "1j" )) {
	      if (chanMeasurement[ii] == "#geq1j") txt[ntxt] = "#geqn jet(s)";
	      if (chanMeasurement[ii] == "1j") txt[ntxt] = "=n jet(s)";
	      txtSize[ntxt] = size_;
	      if (chanMeasurement[ii] == "#geq1j") txtY[ntxt] = chanSigma[ii]*1.4;
	      if (chanMeasurement[ii] == "1j") txtY[ntxt] = chanSigma[ii]*2.2;
	      txtX[ntxt] = nBin_-3;
	      txtAlign[ntxt] = 11;
	      txtFont[ntxt] = 42;
	      ntxt++;
	    }
		if (version==4){
			
			if (ii==k_incj){
				txt[ntxt] = "p_{Tjet}>56 GeV";
				txtX[ntxt] = nBin_-5;
				txtY[ntxt] = chanSigma[ii]*0.1;
			}
			if (ii==k_incg){
				txt[ntxt] = "p_{T#gamma}>25 GeV";
				txtX[ntxt] = nBin_-5;
				txtY[ntxt] = chanSigma[ii]*0.1;
			}
			  if (ii==k_gj){
				  txt[ntxt] = "p_{T#gamma}>40 GeV, p_{Tj}>30 GeV";
				  txtX[ntxt] = nBin_-8;
				  txtY[ntxt] = chanSigma[ii]*0.1;
			  }
			  if (ii==k_gg){
				  txt[ntxt] = "p_{T#gamma}>23,20 GeV";
				  txtX[ntxt] = nBin_-5;
				  txtY[ntxt] = chanSigma[ii]*0.1;
			  }
			  if (ii==k_ggnew){
				  txt[ntxt] = "p_{T#gamma}>40,25 GeV";
				  txtX[ntxt] = nBin_-5; 
				  txtY[ntxt] = chanSigma[ii]*0.1;
			  }
			  txtSize[ntxt] = size_;
			  txtAlign[ntxt] = 11;
			  txtFont[ntxt] = 42;
			  ntxt++;
			  
		}

	    nBin_+=DX_/2.0;
  
	  }
	}





 
  float xw_ = 1800;
  float yw_ = xw_/aspR;
 
  // the canvas
  TCanvas* c_=new TCanvas("SigmaR","sigma",300,300,xw_,yw_);
  c_->SetLeftMargin( 150./xw_ );
  c_->SetRightMargin( 30./xw_ );
  c_->SetTopMargin(  75./yw_ );
  c_->SetBottomMargin( 95./yw_ ); 
  c_->SetFillColor(0);
  c_->SetTickx(0);
  c_->SetTicky(1);
  c_->SetFrameFillStyle(0);
  c_->SetFrameLineWidth(2);
  c_->SetFrameBorderMode(0);

  TH1F* h_= new TH1F( "bidon", "bidon", 1000, -20.0, 1000.0);
  TAxis* ax_ = h_->GetXaxis();
  TAxis* ay_ = h_->GetYaxis();
  
  ax_->SetTitle("");
  ndivx = nBin_/10;
  cout << ndivx << endl;
  ax_->SetNdivisions(ndivx,"N");
  ax_->SetTitleOffset(titleOffsetX);
  ax_->SetLabelOffset(labelOffsetX);
  ax_->SetLabelSize(0);
  ax_->SetTicks("-U");

  ay_->SetTitle("Production Cross Section,  #sigma [pb]");
  ay_->SetNdivisions(ndivy);
  ay_->SetTitleOffset(titleOffsetY);
  ay_->SetTitleSize(titleSizeY);
  ay_->SetLabelOffset(labelOffsetY);
  ay_->SetLabelSize(labelSizeY);

  
  // now plotting
  c_->Draw();
  c_->cd();


  //  ***** Dxnamically set y axix
  
  cout << "Setting axis " << nBin_ << endl;
  c_->SetLogy(true);
  h_->GetXaxis()->SetRangeUser(-stdDX_/2.0-2.0, nBin_+stdDX_/2.0+2.0);
  //if (version==3)  h_->GetXaxis()->SetRangeUser(-stdDX_/2.0-2.0, nBin_+stdDX_);
  if (version==4) h_->GetXaxis()->SetRangeUser(-stdDX_/8.0, nBin_+stdDX_/8.0);
  h_->GetYaxis()->SetRangeUser(ymin,ymax);
  h_->Draw("hist][");
  

  //Convert cross sections to ratios
  //for( size_t ii=0; ii<k_nChan; ii++ )
  //	{
  //      chanSigma[ii] = chanSigma[ii]/chanTheo[ii];
  //      chanETot[ii] = chanETot[ii]/chanTheo[ii];
  //      chanETheo[ii]= chanETheo[ii]/chanTheo[ii];
  //      chanTheo[ii] = 1.0;
  //}

  if (noTop && noHiggs) DX_=stdDX_/2;

  float yy_ = ledgendY/2.0; 
  if (version==3)  yy_*=2.0; 
  //if (version==4)
  float xx_ = nBin_-(0.48*nBin_);
  if (version == 7) xx_ = nBin_-(0.55*nBin_);
  if (version == 8) xx_ = nBin_-(0.45*nBin_);
  float dxx_ = DX_/2.0;
 if (version == 6 || version == 7) dxx_ = DX_/4.0;
 
  DataPoint p_( 0, 0, 0.3*yy_, 
		yy_, 0,
		xx_, dxx_, type ) ;
  p_.draw();





  for( size_t ii=0; ii<channel_.size(); ii++ )
    {
      size_t iChan = channel_[ii];
      xx_ = xpos_[ii];
      dxx_ = dx_[ii];
      type = 7;
      if  (iChan  == k_W8) type = 8;
      if  (iChan  == k_Z8) type = 8;
      if  (iChan  == k_VBFW8) type = 8;
      if  (iChan  == k_VBFW13) type = 13;
      if  (iChan  == k_VBFZ8) type = 8;
      if  (iChan  == k_VBFZ13) type = 13;
      if  (iChan  == k_Zg8) type = 8;
      if  (iChan  == k_Wg13) type = 13;
      if  (iChan  == k_WW8) type = 8;
      if  (iChan  == k_WZ8) type = 8;
      if  (iChan  == k_ZZ8) type = 8;
      if  (iChan  == k_ggH8) type = 8;
      if  (iChan  == k_VBFH8) type = 8;
      if  (iChan  == k_VH8) type = 8;
      if  (iChan  == k_VH13) type = 13;
      if  (iChan  == k_WH13) type = 13;
      if  (iChan  == k_ZH13) type = 13;
      if  (iChan  == k_ttH8) type = 8;
      if  (iChan  == k_WVg) type = 8;
      if  (iChan  == k_VVV13) type = 13;
      if  (iChan  == k_WWW13) type = 13;
      if  (iChan  == k_WWZ13) type = 13;
      if  (iChan  == k_WZZ13) type = 13;
      if  (iChan  == k_ZZZ13) type = 13;
      if  (iChan  == k_Wgg8) type = 8;
      if  (iChan  == k_Zgg8) type = 8;
      if  (iChan  == k_Wgg13) type = 13;
      if  (iChan  == k_Zgg13) type = 13;
      if  (iChan  == k_exWW8) type = 8;
      if  (iChan  == k_exWW8) type = 8;
      if  (iChan  == k_SSWW8) type = 8;
      if  (iChan  == k_SSWW13) type = 13;
      if  (iChan  == k_EWKWg8) type = 8;
      if  (iChan  == k_EWKWg13) type = 13;
      if  (iChan  == k_EWKZg8) type = 8;
      if  (iChan  == k_EWKZg13) type = 13;
      if  (iChan  == k_EWKZZ13) type = 13;
     if  (iChan  == k_EWKWZ13) type = 13;

      if  (iChan == k_tt8) type = 8;
      if  (iChan == k_tt1jet8) type = 8;
      if  (iChan == k_tt2jet8) type = 8;
      if  (iChan == k_tt3jet8) type = 8;
      if  (iChan == k_tt1jet13) type = 13;
      if  (iChan == k_tt2jet13) type = 13;
      if  (iChan == k_tt3jet13) type = 13;
      if  (iChan == k_tt4jet13) type = 13;
      if  (iChan == k_Z1jet8) type = 8;
      if  (iChan == k_Z2jet8) type = 8;
      if  (iChan == k_Z3jet8) type = 8;
      if  (iChan == k_Z4jet8) type = 8;
      if  (iChan == k_Z5jet8) type = 8;
      if  (iChan == k_Z6jet8) type = 8;
      if  (iChan == k_Z7jet8) type = 8;

      if  (iChan == k_tt2cjet13) type = 13;
      if  (iChan == k_tt2bjet13) type = 13;
 

      if  (iChan == k_Z1jet13) type = 13;
      if  (iChan == k_Z2jet13) type = 13;
      if  (iChan == k_Z3jet13) type = 13;
      if  (iChan == k_Z4jet13) type = 13;
      if  (iChan == k_Z5jet13) type = 13;
      if  (iChan == k_Z6jet13) type = 13;

     if  (iChan == k_Z1cjet8) type = 8;
     if  (iChan == k_Z1cjet13) type = 13;
     if  (iChan == k_Z1bjet8) type = 8;
     if  (iChan == k_Z2bjet8) type = 8;
      
      if  (iChan == k_W1jet8n) type = 8;
      if  (iChan == k_W2jet8n) type = 8;
      if  (iChan == k_W3jet8n) type = 8;
      if  (iChan == k_W4jet8n) type = 8;
      if  (iChan == k_W5jet8n) type = 8;
      if  (iChan == k_W6jet8n) type = 8;
      if  (iChan == k_W7jet8n) type = 8;

      if  (iChan == k_W1jet13) type = 13;
      if  (iChan == k_W2jet13) type = 13;
      if  (iChan == k_W3jet13) type = 13;
      if  (iChan == k_W4jet13) type = 13;
      if  (iChan == k_W5jet13) type = 13;
      if  (iChan == k_W6jet13) type = 13;

      
      if  (iChan == k_W1cjet8) type = 8;
      if  (iChan == k_W1cjet13) type = 13;
      if  (iChan == k_W2bjet8) type = 8;


       
      if  (iChan == k_tschan8) type = 8;
      if  (iChan == k_ttW8) type = 8;
      if  (iChan == k_ttZ8) type = 8;
      if  (iChan == k_ttg8) type = 8;
      if  (iChan == k_ttg13) type = 13;
      if  (iChan == k_tZq8) type = 8;
      if  (iChan == k_tZq13) type = 13;
      if  (iChan == k_tg13) type = 13;
      if  (iChan == k_tttt8) type = 8;
 
      
      if  (iChan == k_Hgg8) type = 8;
		
     if  (iChan == k_t8) type = 8;
      if  (iChan == k_tW8) type = 8;
     if  (iChan == k_tW13) type = 13;


      if  (iChan == k_tt13) type = 13;
      if  (iChan == k_ttZ13) type = 13;
      if  (iChan == k_ttW13) type = 13;
      if  (iChan == k_tttt13) type = 13;
      if  (iChan == k_W13) type = 13;
      if  (iChan == k_Z13) type = 13;
      if  (iChan == k_t13) type = 13;
      //if  (iChan == k_Zg13) type = 13;
      if  (iChan == k_WW13) type = 13;
      if  (iChan == k_WW13fid) type = 13;
      if  (iChan == k_WZ13) type = 13;
      if  (iChan == k_ZZ13) type = 13;

     if  (iChan == k_Wg2jet13) type = 13;
     if  (iChan == k_Zg2jet13) type = 13;

      
     if (iChan == k_WZ0jet8) type = 8;
     if  (iChan == k_WZ1jet8) type = 8;
     if  (iChan == k_WZ2jet8) type = 8;
     if  (iChan == k_WZ3jet8) type = 8;

     if (iChan == k_ZZ0jet8) type = 8;
     if  (iChan == k_ZZ1jet8) type = 8;
     if  (iChan == k_ZZ2jet8) type = 8;
     if  (iChan == k_ZZ3jet8) type = 8;
    if (iChan == k_ZZ0jet13) type = 13;
     if  (iChan == k_ZZ1jet13) type = 13;
     if  (iChan == k_ZZ2jet13) type = 13;
     if  (iChan == k_ZZ3jet13) type = 13;


      if  (iChan == k_ttH13) type = 13; 
      if  (iChan == k_tH13) type = 13; 
      if  (iChan  == k_ggHgg13) type = 13;
      if  (iChan  == k_ggH13) type = 13;
      if  (iChan  == k_VBFH13) type = 13;

      if (iChan == k_H0jet13 ) type = 13;
      if (iChan == k_H1jet13 ) type = 13;
      if (iChan == k_H2jet13 ) type = 13;
      if (iChan == k_H3jet13 ) type = 13;
      if (iChan == k_H4jet13 ) type = 13;
      

     if  (iChan == k_HHbbtautau8) type = 8; 
     if  (iChan  == k_HHbbgg8) type = 8;
     if  (iChan == k_HHComb8) type = 8; 
     if  (iChan == k_HHComb8&&version==9) type = 18; 
     if  (iChan == k_HHWWbb13) type = 13; 
     if  (iChan == k_HHbbgg13) type = 13; 
     if  (iChan == k_HHComb13) type = 13; 
      if  (iChan == k_HHbbtautau13) type = 13; 

      
      if (type != 71){
      DataPoint p2_( chanSigma[iChan], chanEStat[iChan], chanETot[iChan], 
		    chanTheo[iChan], chanETheo[iChan],
		    xx_, dxx_ , type) ;
      p2_.draw();
      }
    }
  
  for( size_t ii=0; ii<vline_.size(); ii++ )
    {
      //     cout << ii << " " << vmax_[ii] << endl;
      if (ii == vline_.size() -1 ) vmax_[ii] = 1.;
 
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

void text_init()
{
  text_reset();

  ntxt = 3;

  txt[0] = "CMS Preliminary";
  txtSize[0] = 0.055;
  txtX[0] = 0.94;
  txtY[0] = 0.95;
  txtAlign[0] = 31;
  txtNDC[0]=true;
  txtFont[0] = 42;

  txt[1] = "May 2021";
  txtSize[1] = 0.03;
  txtX[1] = 0.1;
  txtY[1] = 0.96;
  txtAlign[1] = 11;
  txtNDC[1]=true;
  txtFont[1] = 42;

  if (version != 6 && version != 9) {
  txt[2] = "All results at: http://cern.ch/go/pNj7";
  txtSize[2] = 0.025;
  txtX[2] = 0.07;
  if (version ==0||version==8) txtX[2] = 0.05;
  txtY[2] = 0.005;
  txtAlign[2] = 11;
  txtNDC[2]=true;
  txtFont[2] = 42;
  }

  
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
      latex.SetTextAlign(txtAlign[ii]); 
      latex.DrawLatex(txtX[ii],txtY[ii],txt[ii].c_str());
    }
}
