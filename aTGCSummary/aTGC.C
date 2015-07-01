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
#include "TGraphAsymmErrors.h"
#include "TMarker.h"
#include "TLine.h"
#include "TBox.h"

using namespace std;

// titles and axis, marker size, etc.
float markerSize = 1.0;
float titleOffsetX = 0.7;
float titleOffsetY = 1.1;
float titleSizeX = 0.015;
float titleSizeY = 0.05;
float labelSizeX = 0.04;
float labelOffsetX = 0.004;
float labelOffsetY = 0.004;
float labelSizeY = 0.045;
int ndivx = 506;
int ndivy = 506;
float aspR = 1.4; 

// plot type
  bool _natgcz;
  bool _natgcg;


// texts
size_t ntxt = 1;
string currentName;
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

int version = 0;
bool plotVJets = false;
// version 0 standard log plot
// version 1 depreciated - should delete
// version 2 ratio


class DataPoint
{
public: 

  DataPoint( float atgcc, float atgcm, float atgcp,
	     float ypos, float dy, int type) 
    : _atgcc(atgcc), _atgcm(atgcm), _atgcp(atgcp),
      _ypos(ypos), _dy(dy), _type(type)
  {
  }

  virtual ~DataPoint() 
  {
  }

  void draw()
  {
  
   
    if( _atgcc>-999.0 )
      {
    
	if (_type==1) 
	  {
	    _theoColor = kBlue;
            _expLineColor = kRed;
	    _expCircleColor = kRed;
	    _expFillColor = kWhite;
	  } else if (_type == 2)
	  {
            _expLineColor = kBlack;
 	    _theoColor = kBlue;
	    _expCircleColor = kRed;
	    _expFillColor = kRed;
	  } else if (_type == 3)
	  {
            _expLineColor = 209;
	    _theoColor = kBlue;
	    _expCircleColor = 209;
	    _expFillColor = kWhite;
	  } else if (_type == 4)
	  {
            _expLineColor = 209;
 	    _theoColor = kBlue;
	    _expCircleColor = 209;
	    _expFillColor = kWhite;
	  } else if (_type == 5)
	  {
            _expLineColor = kBlue;
	    _theoColor = kBlue;
	    _expCircleColor = kBlue;
	    _expFillColor = kBlue;
	  } else
	  {
            _expLineColor = kRed;
	    _theoColor = kBlue;
	    _expCircleColor = kRed;
	    _expFillColor = kWhite;
	  } 
 
	TGraphAsymmErrors _dataExpPoint(1);
	_dataExpPoint.SetPoint(1, _atgcc, _ypos );
	_dataExpPoint.SetPointError( 1, (_atgcc-_atgcm),(_atgcp-_atgcc), 0, 0 );
	_dataExpPoint.SetLineWidth(1);
	_dataExpPoint.SetLineColor(_expLineColor);
	_dataExpPoint.SetMarkerSize(0);
	_dataExpPoint.DrawClone("e");	

	if (_type != 2 && _type != 1 && _type != 3)
	  {
 	TMarker _dataPoint( _atgcc, _ypos, kFullCircle );
 	_dataPoint.SetMarkerSize(markerSize);
	_dataPoint.SetMarkerColor(_expFillColor);
	_dataPoint.DrawClone();
	_dataPoint.SetMarkerStyle(kOpenCircle);
 	_dataPoint.SetMarkerColor(_expCircleColor);
	_dataPoint.DrawClone();
	  }	

      }
     else
      {
	float dy_ = 1/2.0;
        int exps = 0;

        _atgcc=_atgcm;
  
	if (_type&2){

	TGraphErrors _dataTotPoint(1);
	_dataTotPoint.SetPoint(1, _ypos, _atgcc-dy_*exps );
	_dataTotPoint.SetPointError( 1, _atgcp/2, 0 );
	_dataTotPoint.SetLineWidth(1);
	_dataTotPoint.SetLineColor(kBlack);
	_dataTotPoint.SetMarkerSize(0);
	_dataTotPoint.DrawClone("e");	


 	//TMarker _dataPoint( _ypos, _atgcc-dy_*exps, kFullCircle );
 	//_dataPoint.SetMarkerSize(markerSize);
	//_dataPoint.SetMarkerColor(kRed);
	//_dataPoint.DrawClone();
	//_dataPoint.SetMarkerStyle(kOpenCircle);
 	//_dataPoint.SetMarkerColor(kRed);
	//_dataPoint.DrawClone();

	txt[ntxt] = "ATLAS Limits";
	txtSize[ntxt] = 0.03;
	txtX[ntxt] = _ypos - 0.65;
	txtY[ntxt] = _atgcc-dy_*exps;
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;

        exps++;
	} 


	if (_type&1){

	TGraphErrors _dataTotPointCMS(1);
	_dataTotPointCMS.SetPoint(1, _ypos, _atgcc-dy_*exps );
	_dataTotPointCMS.SetPointError( 1, _atgcp/2, 0 );
	_dataTotPointCMS.SetLineWidth(1);
	_dataTotPointCMS.SetLineColor(kRed);
	_dataTotPointCMS.SetMarkerSize(0);
	_dataTotPointCMS.DrawClone("e");	

        //TMarker _dataPointCMS( _ypos, _atgcc-dy_*exps, kFullCircle );
        //_dataPointCMS.SetMarkerSize(markerSize);
        //_dataPointCMS.SetMarkerColor(kWhite);
        //_dataPointCMS.DrawClone();
        //_dataPointCMS.SetMarkerStyle(kOpenCircle);
        //_dataPointCMS.SetMarkerColor(kRed);
        //_dataPointCMS.DrawClone();

	txt[ntxt] = "CMS Prel. Limits";
	txtSize[ntxt] = 0.03;
	txtX[ntxt] = _ypos - 0.65;
	txtY[ntxt] = _atgcc-dy_*exps;
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;

	exps++;

	}

	if (_type&4){


	TGraphErrors _dataTotPointCDF(1);
	_dataTotPointCDF.SetPoint(1, _ypos, _atgcc-dy_*exps );
	_dataTotPointCDF.SetPointError( 1, _atgcp/2, 0 );
	_dataTotPointCDF.SetLineWidth(1);
	_dataTotPointCDF.SetLineColor(209);
	_dataTotPointCDF.SetMarkerSize(0);
	_dataTotPointCDF.DrawClone("e");	

//       TMarker _dataPointCDF( _ypos, _atgcc-dy_*exps, kFullCircle );
//         _dataPointCDF.SetMarkerSize(markerSize);
//         _dataPointCDF.SetMarkerColor(kBlack);
//         _dataPointCDF.DrawClone();
//         _dataPointCDF.SetMarkerStyle(kOpenCircle);
//         _dataPointCDF.SetMarkerColor(kBlack);
//         _dataPointCDF.DrawClone();
 
	txt[ntxt] = "CDF Limit";
	txtSize[ntxt] = 0.03;
	txtX[ntxt] = _ypos - 0.65;
	txtY[ntxt] = _atgcc-dy_*exps;
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;

	exps++;

	}

	if (_type&8){


	TGraphErrors _dataTotPointD0(1);
	_dataTotPointD0.SetPoint(1, _ypos, _atgcc-dy_*exps );
	_dataTotPointD0.SetPointError( 1, _atgcp/2, 0 );
	_dataTotPointD0.SetLineWidth(1);
	_dataTotPointD0.SetLineColor(209);
	_dataTotPointD0.SetMarkerSize(0);
	_dataTotPointD0.DrawClone("e");	

        TMarker _dataPointD0( _ypos, _atgcc-dy_*exps, kFullCircle );
        _dataPointD0.SetMarkerSize(markerSize);
        _dataPointD0.SetMarkerColor(kWhite);
        _dataPointD0.DrawClone();
        _dataPointD0.SetMarkerStyle(kOpenCircle);
        _dataPointD0.SetMarkerColor(209);
        _dataPointD0.DrawClone();

	txt[ntxt] = "D0 Limit";
	txtSize[ntxt] = 0.03;
	txtX[ntxt] = _ypos - 0.65;
	txtY[ntxt] = _atgcc-dy_*exps;
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;

	exps++;

	}

	if (_type&16){


 	TGraphErrors _dataTotPointLEP(1);
	_dataTotPointLEP.SetPoint(1, _ypos, _atgcc-dy_*exps );
	_dataTotPointLEP.SetPointError( 1, _atgcp/2, 0 );
	_dataTotPointLEP.SetLineWidth(1);
	_dataTotPointLEP.SetLineColor(kBlack);
	_dataTotPointLEP.SetMarkerSize(0);
	_dataTotPointLEP.DrawClone("e");	

        TMarker _dataPointLEP( _ypos, _atgcc-dy_*exps, kFullCircle );
        _dataPointLEP.SetMarkerSize(markerSize);
        _dataPointLEP.SetMarkerColor(kBlue);
        _dataPointLEP.DrawClone();
        _dataPointLEP.SetMarkerStyle(kOpenCircle);
        _dataPointLEP.SetMarkerColor(kBlue);
        _dataPointLEP.DrawClone();

	txt[ntxt] = "LEP Limit";
	txtSize[ntxt] = 0.03;
	txtX[ntxt] = _ypos - 0.65;
	txtY[ntxt] = _atgcc-dy_*exps;
 	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;

	exps++;
	}


	//     draw_bin_grid( -0.73, 1.93, _atgcc-3.8*dy_ , _atgcc-3.8*dy_,
	//              kGray+2, 1 );
 

 
    //   draw_bin_grid( -0.73, 1.93, _atgcc-25.8*dy_ , _atgcc-25.8*dy_,
    //                 kGray+2, 1 );












 



      }
  }

private:
  float _atgcc;
  float _atgcm;
  float _atgcp;
  float _ypos;
  float _dy;
  int _theoColor;
  int _expLineColor;
  int _expFillColor;
  int _expCircleColor;
  int _type;
};

TCanvas*
aTGC(float ymin=-2.0, float ymax=900000 )
{

#include "data.C"

  if (version ==2) ymax = 4;


  _natgcz = natgcz;
  _natgcg = natgcg;
  text_init();

  gStyle->SetEndErrorSize(5);
  gStyle->SetHatchesLineWidth(1);
  gStyle->SetHatchesSpacing(0.8);

  vector<string> cutName;
    
  int chanColor = kBlue;
  int type = 7;
 
  float shift_ = 2.;
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

	if (chanName[ii]!=currentName)
	  {


	    vline_.push_back( nPlotChan - (nBin_) +1.5*(DY_)+0.55  );
	    vmin_.push_back( -0.73 );
	    vmax_.push_back( 1.93 );
	    vstyle_.push_back(1);

	    txt[ntxt] = chanName[ii];
	    txtSize[ntxt] = size_+0.02;
	    txtX[ntxt] = -0.65;
	    txtY[ntxt] = nPlotChan - (nBin_) +1.0*DY_;
	    txtAlign[ntxt] = 12;
	    txtFont[ntxt] = 42;
	    ntxt++;


	  }


	currentName = chanName[ii];

	txt[ntxt] = chanMeasurement[ii];
	txtSize[ntxt] = size_;
	txtX[ntxt] = 0.50;
	txtY[ntxt] = nPlotChan - (nBin_) +1.55*DY_;
	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;

	txt[ntxt] = chanResult[ii];
	txtSize[ntxt] = size_;
	txtX[ntxt] = 1.15;
	txtY[ntxt] = nPlotChan - (nBin_) +1.52*DY_;
	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;

	txt[ntxt] = chanLumi[ii];
	txtSize[ntxt] = size_;
	txtX[ntxt] = 1.65;
	txtY[ntxt] = nPlotChan - (nBin_) +1.55*DY_;
	txtAlign[ntxt] = 12;
	txtFont[ntxt] = 42;
	ntxt++;


	nBin_+=DY_;
      }
    }


	    vline_.push_back( +1.1  );
	    vmin_.push_back( -0.73 );
	    vmax_.push_back( 1.93 );
	    vstyle_.push_back(1);





 
  float xw_ = 1200;
  float yw_ = xw_/aspR;
 
  // the canvas
  TCanvas* c_=new TCanvas("aTGC","atgc",300,300,xw_,yw_);
  c_->SetLeftMargin( 40./xw_ );
  c_->SetRightMargin( 40./xw_ );
  c_->SetTopMargin(  40./yw_ );
  c_->SetBottomMargin( 80./yw_ ); 
  c_->SetFillColor(0);
  c_->SetTickx(1);
  c_->SetTicky(1);
  c_->SetFrameFillStyle(0);
  c_->SetFrameLineWidth(2);
  c_->SetFrameBorderMode(0);

  TH1F* h_= new TH1F( "bidon", "bidon", 30, -1.0, 3);
  TAxis* ax_ = h_->GetXaxis();
  TAxis* ay_ = h_->GetYaxis();
  
  ax_->SetTitle("aTGC Limits @95% C.L.");
  ax_->SetNdivisions(ndivx);
  ax_->SetTitleOffset(titleOffsetX);
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
  h_->GetYaxis()->SetRangeUser(0.5,nBin_+2.5);
  h_->GetXaxis()->SetRangeUser(-0.7,1.9);
  h_->Draw("hist][");
  

  type = 0;
    for( size_t ii=0; ii<channel_.size(); ii++ )
    {
     size_t iChan = channel_[ii];
     if (chanExp[iChan]=="CMS")   type = type|1;
     if (chanExp[iChan]=="ATLAS") type = type|2;
     if (chanExp[iChan]=="CDF")   type = type|4;
     if (chanExp[iChan]=="D0")   type = type|8;
     if (chanExp[iChan]=="LEP")   type = type|16;



    }

    float yy_ = nBin_+2.0;
    float xx_ = 1.8;
    float dyx_ = 1.2;
    DataPoint p_( -1000.0, yy_, 0.1,
		  xx_, dyx_, type ) ;
    p_.draw();



  for( size_t ii=0; ii<channel_.size(); ii++ )
    {
      size_t iChan = channel_[ii];
      float xx_ = nBin_-ypos_[ii];
      float dyy_ = dy_[ii];
      type = 1;
      if (chanExp[iChan]=="ATLAS") type= 2;
     if (chanExp[iChan]=="CDF") type= 3;
       if (chanExp[iChan]=="D0") type= 4;
    if (chanExp[iChan]=="LEP") type= 5;

      DataPoint p_( chanaTGCC[iChan], chanaTGCM[iChan], chanaTGCP[iChan],
		    xx_, dyy_ , type) ;
      p_.draw();
    }
  
  for( size_t ii=0; ii<vline_.size(); ii++ )
    {
      draw_bin_grid( vmin_[ii], vmax_[ii], vline_[ii], vline_[ii],
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

  ntxt = 2;

  txt[0] = "";
  txtSize[0] = 0.055;
  txtX[0] = 0.95;
  txtY[0] = 0.95;
  txtAlign[0] = 31;
  txtNDC[0]=true;
  txtFont[0] = 42;

  txt[1] = "Mar 2015";
  txtSize[1] = 0.03;
  txtX[1] = 0.14;
  txtY[1] = 0.97;
  txtAlign[1] = 31;
  txtNDC[1]=true;
  txtFont[1] = 42;
 
  if (_natgcz||_natgcg) {
  txt[ntxt] = "x10^{-1}";
  txtSize[ntxt] = 0.04;
  txtX[ntxt] = 0.95;
  txtY[ntxt] = 0.055;
  txtAlign[ntxt] = 31;
  txtNDC[ntxt]=true;
  txtFont[ntxt] = 42;
  ntxt++;
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

