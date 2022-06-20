#include "ROOT/RDataFrame.hxx"
#include "TString.h"
#include "TFile.h"
#include "TH2D.h"
#include "TMath.h"

#include "ROOT/RVec.hxx"

using namespace ROOT::VecOps;
using rvec_f = const RVec<float> &;

// 2016APV TriggerSF
TFile*f_2016APV=TFile::Open("data/TriggerSF/TriggerSF_2016apvUL.root");
TH2D*h1_ee_2016APV=(TH2D*)f_2016APV->Get("h2D_SF_ee_SF_l1pteta");
TH2D*h2_ee_2016APV=(TH2D*)f_2016APV->Get("h2D_SF_ee_SF_l2pteta");
TH2D*h1_mm_2016APV=(TH2D*)f_2016APV->Get("h2D_SF_mumu_SF_l1pteta");
TH2D*h2_mm_2016APV=(TH2D*)f_2016APV->Get("h2D_SF_mumu_SF_l2pteta");
TH2D*h1_em_2016APV=(TH2D*)f_2016APV->Get("h2D_SF_emu_SF_l1pteta");
TH2D*h2_em_2016APV=(TH2D*)f_2016APV->Get("h2D_SF_emu_SF_l2pteta");

// 2016postAPV TriggerSF
TFile*f_2016postAPV=TFile::Open("data/TriggerSF/TriggerSF_2016postapvUL.root");
TH2D*h1_ee_2016postAPV=(TH2D*)f_2016postAPV->Get("h2D_SF_ee_SF_l1pteta");
TH2D*h2_ee_2016postAPV=(TH2D*)f_2016postAPV->Get("h2D_SF_ee_SF_l2pteta");
TH2D*h1_mm_2016postAPV=(TH2D*)f_2016postAPV->Get("h2D_SF_mumu_SF_l1pteta");
TH2D*h2_mm_2016postAPV=(TH2D*)f_2016postAPV->Get("h2D_SF_mumu_SF_l2pteta");
TH2D*h1_em_2016postAPV=(TH2D*)f_2016postAPV->Get("h2D_SF_emu_SF_l1pteta");
TH2D*h2_em_2016postAPV=(TH2D*)f_2016postAPV->Get("h2D_SF_emu_SF_l2pteta");

// 2017 TriggerSF
TFile*f=TFile::Open("data/TriggerSF/TriggerSF_2017UL.root");
TH2D*h1_ee=(TH2D*)f->Get("h2D_SF_ee_SF_l1pteta");
TH2D*h2_ee=(TH2D*)f->Get("h2D_SF_ee_SF_l2pteta");
TH2D*h1_mm=(TH2D*)f->Get("h2D_SF_mumu_SF_l1pteta");
TH2D*h2_mm=(TH2D*)f->Get("h2D_SF_mumu_SF_l2pteta");
TH2D*h1_em=(TH2D*)f->Get("h2D_SF_emu_SF_l1pteta");
TH2D*h2_em=(TH2D*)f->Get("h2D_SF_emu_SF_l2pteta");

// 2018 TriggerSF
TFile*f_2018=TFile::Open("data/TriggerSF/TriggerSF_2018UL.root");
TH2D*h1_ee_2018=(TH2D*)f_2018->Get("h2D_SF_ee_SF_l1pteta");
TH2D*h2_ee_2018=(TH2D*)f_2018->Get("h2D_SF_ee_SF_l2pteta");
TH2D*h1_mm_2018=(TH2D*)f_2018->Get("h2D_SF_mumu_SF_l1pteta");
TH2D*h2_mm_2018=(TH2D*)f_2018->Get("h2D_SF_mumu_SF_l2pteta");
TH2D*h1_em_2018=(TH2D*)f_2018->Get("h2D_SF_emu_SF_l1pteta");
TH2D*h2_em_2018=(TH2D*)f_2018->Get("h2D_SF_emu_SF_l2pteta");

// 2016APV Fakerare
TFile*f_m_2016APV=TFile::Open("data/fr_data_mu_2016APV.root"); 
TFile*f_e_2016APV=TFile::Open("data/fr_data_ele_2016APV.root");
TH2D*h_m_2016APV=(TH2D*)f_m_2016APV->Get("fakerate");
TH2D*h_e_2016APV=(TH2D*)f_e_2016APV->Get("fakerate");

// 2016postAPV Fakerare
TFile*f_m_2016postAPV=TFile::Open("data/fr_data_mu_2016postAPV.root"); 
TFile*f_e_2016postAPV=TFile::Open("data/fr_data_ele_2016postAPV.root");
TH2D*h_m_2016postAPV=(TH2D*)f_m_2016postAPV->Get("fakerate");
TH2D*h_e_2016postAPV=(TH2D*)f_e_2016postAPV->Get("fakerate");

// 2017 Fakerare
TFile*f_m=TFile::Open("fr_data_mu_2017.root"); 
TFile*f_e=TFile::Open("fr_data_ele_2017.root"); 
TH2D*h_m=(TH2D*)f_m->Get("fakerate");
TH2D*h_e=(TH2D*)f_e->Get("fakerate");

// 2018 Fakerare
TFile*f_m_2018=TFile::Open("data/fr_data_mu_2018.root"); 
TFile*f_e_2018=TFile::Open("data/fr_data_ele_2018.root");
TH2D*h_m_2018=(TH2D*)f_m_2018->Get("fakerate");
TH2D*h_e_2018=(TH2D*)f_e_2018->Get("fakerate");


float trigger_sf_ee_2016postAPV(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_ee_2016postAPV->GetBinContent(h1_ee_2016postAPV->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_ee_2016postAPV->GetBinContent(h2_ee_2016postAPV->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_ee_2016APV(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_ee_2016APV->GetBinContent(h1_ee_2016APV->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_ee_2016APV->GetBinContent(h2_ee_2016APV->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_ee_2017(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_ee->GetBinContent(h1_ee->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_ee->GetBinContent(h2_ee->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_ee_2018(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_ee_2018->GetBinContent(h1_ee_2018->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_ee_2018->GetBinContent(h2_ee_2018->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_mm_2016APV(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_mm_2016APV->GetBinContent(h1_mm_2016APV->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_mm_2016APV->GetBinContent(h2_mm_2016APV->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_mm_2016postAPV(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_mm_2016postAPV->GetBinContent(h1_mm_2016postAPV->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_mm_2016postAPV->GetBinContent(h2_mm_2016postAPV->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_mm_2017(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_mm->GetBinContent(h1_mm->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_mm->GetBinContent(h2_mm->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_mm_2018(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_mm_2018->GetBinContent(h1_mm_2018->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_mm_2018->GetBinContent(h2_mm_2018->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_em_2016APV(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_em_2016APV->GetBinContent(h1_em_2016APV->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_em_2016APV->GetBinContent(h2_em_2016APV->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_em_2016postAPV(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_em_2016postAPV->GetBinContent(h1_em_2016postAPV->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_em_2016postAPV->GetBinContent(h2_em_2016postAPV->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_em_2017(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_em->GetBinContent(h1_em->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_em->GetBinContent(h2_em->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float trigger_sf_em_2018(float l1_pt, float l2_pt, float l1_eta, float l2_eta){
	if(l1_pt>200) l1_pt=199;
	if(l2_pt>200) l2_pt=199;
	float sf_l1=h1_em_2018->GetBinContent(h1_em_2018->FindBin(l1_pt,fabs(l1_eta)));
	float sf_l2=h2_em_2018->GetBinContent(h2_em_2018->FindBin(l2_pt,fabs(l2_eta)));
	return sf_l1*sf_l2;
}

float fakelepweight_ee_2017(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_e->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_e->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_e->GetNbinsX()) BinX = h_e->GetNbinsX();
                if (BinY > h_e->GetNbinsY()) BinY = h_e->GetNbinsY();
                fakerate1=h_e->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_e->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_e->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_e->GetNbinsX()) BinX = h_e->GetNbinsX();
                if (BinY > h_e->GetNbinsY()) BinY = h_e->GetNbinsY();
                fakerate1=h_e->GetBinContent(BinX, BinY);
            }
	    if(isData){
              w_temp=fakerate1/(1-fakerate1);
            }else{
              w_temp=-1*fakerate1/(1-fakerate1);
            }
	    
        }
        if(ttc_0P2F){
            BinX = h_e->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_e->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_e->GetNbinsX()) BinX = h_e->GetNbinsX();
            if (BinY > h_e->GetNbinsY()) BinY = h_e->GetNbinsY();
            fakerate1=h_e->GetBinContent(BinX, BinY);

            BinX = h_e->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_e->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_e->GetNbinsX()) BinX = h_e->GetNbinsX();
            if (BinY > h_e->GetNbinsY()) BinY = h_e->GetNbinsY();
            fakerate2=h_e->GetBinContent(BinX, BinY);
	    if(isData){
              w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }else{
              w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }
        }
        return w_temp;
}

float fakelepweight_ee_2018(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_e_2018->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_e_2018->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_e_2018->GetNbinsX()) BinX = h_e_2018->GetNbinsX();
                if (BinY > h_e_2018->GetNbinsY()) BinY = h_e_2018->GetNbinsY();
                fakerate1=h_e_2018->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_e_2018->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_e_2018->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_e_2018->GetNbinsX()) BinX = h_e_2018->GetNbinsX();
                if (BinY > h_e_2018->GetNbinsY()) BinY = h_e_2018->GetNbinsY();
                fakerate1=h_e_2018->GetBinContent(BinX, BinY);
            }
	    if(isData){
              w_temp=fakerate1/(1-fakerate1);
            }else{
              w_temp=-1*fakerate1/(1-fakerate1);
            }
	    
        }
        if(ttc_0P2F){
            BinX = h_e_2018->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_e_2018->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_e_2018->GetNbinsX()) BinX = h_e_2018->GetNbinsX();
            if (BinY > h_e_2018->GetNbinsY()) BinY = h_e_2018->GetNbinsY();
            fakerate1=h_e_2018->GetBinContent(BinX, BinY);

            BinX = h_e_2018->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_e_2018->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_e_2018->GetNbinsX()) BinX = h_e_2018->GetNbinsX();
            if (BinY > h_e_2018->GetNbinsY()) BinY = h_e_2018->GetNbinsY();
            fakerate2=h_e_2018->GetBinContent(BinX, BinY);
	    if(isData){
              w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }else{
              w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }
        }
        return w_temp;
}

float fakelepweight_em_2016APV(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_m_2016APV->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_m_2016APV->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_m_2016APV->GetNbinsX()) BinX = h_m_2016APV->GetNbinsX();
                if (BinY > h_m_2016APV->GetNbinsY()) BinY = h_m_2016APV->GetNbinsY();
                fakerate1=h_m_2016APV->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_e_2016APV->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_e_2016APV->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_e_2016APV->GetNbinsX()) BinX = h_e_2016APV->GetNbinsX();
                if (BinY > h_e_2016APV->GetNbinsY()) BinY = h_e_2016APV->GetNbinsY();
                fakerate1=h_e_2016APV->GetBinContent(BinX, BinY);
            }
	    if(isData){
              w_temp=fakerate1/(1-fakerate1);
            }else{
              w_temp=-1*fakerate1/(1-fakerate1);
            }

        }
        if(ttc_0P2F){
            BinX = h_m_2016APV->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_m_2016APV->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_m_2016APV->GetNbinsX()) BinX = h_m_2016APV->GetNbinsX();
            if (BinY > h_m_2016APV->GetNbinsY()) BinY = h_m_2016APV->GetNbinsY();
            fakerate1=h_m_2016APV->GetBinContent(BinX, BinY);

            BinX = h_e_2016APV->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_e_2016APV->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_e_2016APV->GetNbinsX()) BinX = h_e_2016APV->GetNbinsX();
            if (BinY > h_e_2016APV->GetNbinsY()) BinY = h_e_2016APV->GetNbinsY();
            fakerate2=h_e_2016APV->GetBinContent(BinX, BinY);
	    if(isData){
              w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }else{
              w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }

        }
        return w_temp;
}

float fakelepweight_em_2016postAPV(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_m_2016postAPV->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_m_2016postAPV->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_m_2016postAPV->GetNbinsX()) BinX = h_m_2016postAPV->GetNbinsX();
                if (BinY > h_m_2016postAPV->GetNbinsY()) BinY = h_m_2016postAPV->GetNbinsY();
                fakerate1=h_m_2016postAPV->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_e_2016postAPV->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_e_2016postAPV->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_e_2016postAPV->GetNbinsX()) BinX = h_e_2016postAPV->GetNbinsX();
                if (BinY > h_e_2016postAPV->GetNbinsY()) BinY = h_e_2016postAPV->GetNbinsY();
                fakerate1=h_e_2016postAPV->GetBinContent(BinX, BinY);
            }
	    if(isData){
              w_temp=fakerate1/(1-fakerate1);
            }else{
              w_temp=-1*fakerate1/(1-fakerate1);
            }

        }
        if(ttc_0P2F){
            BinX = h_m_2016postAPV->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_m_2016postAPV->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_m_2016postAPV->GetNbinsX()) BinX = h_m_2016postAPV->GetNbinsX();
            if (BinY > h_m_2016postAPV->GetNbinsY()) BinY = h_m_2016postAPV->GetNbinsY();
            fakerate1=h_m_2016postAPV->GetBinContent(BinX, BinY);

            BinX = h_e_2016postAPV->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_e_2016postAPV->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_e_2016postAPV->GetNbinsX()) BinX = h_e_2016postAPV->GetNbinsX();
            if (BinY > h_e_2016postAPV->GetNbinsY()) BinY = h_e_2016postAPV->GetNbinsY();
            fakerate2=h_e_2016postAPV->GetBinContent(BinX, BinY);
	    if(isData){
              w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }else{
              w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }

        }
        return w_temp;
}


float fakelepweight_em_2017(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_m->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_m->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_m->GetNbinsX()) BinX = h_m->GetNbinsX();
                if (BinY > h_m->GetNbinsY()) BinY = h_m->GetNbinsY();
                fakerate1=h_m->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_e->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_e->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_e->GetNbinsX()) BinX = h_e->GetNbinsX();
                if (BinY > h_e->GetNbinsY()) BinY = h_e->GetNbinsY();
                fakerate1=h_e->GetBinContent(BinX, BinY);
            }
	    if(isData){
              w_temp=fakerate1/(1-fakerate1);
            }else{
              w_temp=-1*fakerate1/(1-fakerate1);
            }

        }
        if(ttc_0P2F){
            BinX = h_m->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_m->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_m->GetNbinsX()) BinX = h_m->GetNbinsX();
            if (BinY > h_m->GetNbinsY()) BinY = h_m->GetNbinsY();
            fakerate1=h_m->GetBinContent(BinX, BinY);

            BinX = h_e->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_e->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_e->GetNbinsX()) BinX = h_e->GetNbinsX();
            if (BinY > h_e->GetNbinsY()) BinY = h_e->GetNbinsY();
            fakerate2=h_e->GetBinContent(BinX, BinY);
	    if(isData){
              w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }else{
              w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }

        }
        return w_temp;
}

float fakelepweight_em_2018(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_m_2018->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_m_2018->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_m_2018->GetNbinsX()) BinX = h_m_2018->GetNbinsX();
                if (BinY > h_m_2018->GetNbinsY()) BinY = h_m_2018->GetNbinsY();
                fakerate1=h_m_2018->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_e_2018->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_e_2018->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_e_2018->GetNbinsX()) BinX = h_e_2018->GetNbinsX();
                if (BinY > h_e_2018->GetNbinsY()) BinY = h_e_2018->GetNbinsY();
                fakerate1=h_e_2018->GetBinContent(BinX, BinY);
            }
	    if(isData){
              w_temp=fakerate1/(1-fakerate1);
            }else{
              w_temp=-1*fakerate1/(1-fakerate1);
            }

        }
        if(ttc_0P2F){
            BinX = h_m_2018->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_m_2018->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_m_2018->GetNbinsX()) BinX = h_m_2018->GetNbinsX();
            if (BinY > h_m_2018->GetNbinsY()) BinY = h_m_2018->GetNbinsY();
            fakerate1=h_m_2018->GetBinContent(BinX, BinY);

            BinX = h_e_2018->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_e_2018->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_e_2018->GetNbinsX()) BinX = h_e_2018->GetNbinsX();
            if (BinY > h_e_2018->GetNbinsY()) BinY = h_e_2018->GetNbinsY();
            fakerate2=h_e_2018->GetBinContent(BinX, BinY);
	    if(isData){
              w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }else{
              w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }

        }
        return w_temp;
}

float fakelepweight_mm_2016APV(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_m_2016APV->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_m_2016APV->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_m_2016APV->GetNbinsX()) BinX = h_m_2016APV->GetNbinsX();
                if (BinY > h_m_2016APV->GetNbinsY()) BinY = h_m_2016APV->GetNbinsY();
                fakerate1=h_m_2016APV->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_m_2016APV->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_m_2016APV->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_m_2016APV->GetNbinsX()) BinX = h_m_2016APV->GetNbinsX();
                if (BinY > h_m_2016APV->GetNbinsY()) BinY = h_m_2016APV->GetNbinsY();
                fakerate1=h_m_2016APV->GetBinContent(BinX, BinY);
            }
	    if(isData){
              w_temp=fakerate1/(1-fakerate1);
            }else{
              w_temp=-1*fakerate1/(1-fakerate1);
            }
        }
        if(ttc_0P2F){
            BinX = h_m_2016APV->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_m_2016APV->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_m_2016APV->GetNbinsX()) BinX = h_m_2016APV->GetNbinsX();
            if (BinY > h_m_2016APV->GetNbinsY()) BinY = h_m_2016APV->GetNbinsY();
            fakerate1=h_m_2016APV->GetBinContent(BinX, BinY);

            BinX = h_m_2016APV->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_m_2016APV->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_m_2016APV->GetNbinsX()) BinX = h_m_2016APV->GetNbinsX();
            if (BinY > h_m_2016APV->GetNbinsY()) BinY = h_m_2016APV->GetNbinsY();
            fakerate2=h_m_2016APV->GetBinContent(BinX, BinY);
	    if(isData){
              w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }else{
              w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }
        }
        return w_temp;
}

float fakelepweight_mm_2016postAPV(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_m_2016postAPV->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_m_2016postAPV->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_m_2016postAPV->GetNbinsX()) BinX = h_m_2016postAPV->GetNbinsX();
                if (BinY > h_m_2016postAPV->GetNbinsY()) BinY = h_m_2016postAPV->GetNbinsY();
                fakerate1=h_m_2016postAPV->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_m_2016postAPV->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_m_2016postAPV->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_m_2016postAPV->GetNbinsX()) BinX = h_m_2016postAPV->GetNbinsX();
                if (BinY > h_m_2016postAPV->GetNbinsY()) BinY = h_m_2016postAPV->GetNbinsY();
                fakerate1=h_m_2016postAPV->GetBinContent(BinX, BinY);
            }
	    if(isData){
              w_temp=fakerate1/(1-fakerate1);
            }else{
              w_temp=-1*fakerate1/(1-fakerate1);
            }
        }
        if(ttc_0P2F){
            BinX = h_m_2016postAPV->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_m_2016postAPV->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_m_2016postAPV->GetNbinsX()) BinX = h_m_2016postAPV->GetNbinsX();
            if (BinY > h_m_2016postAPV->GetNbinsY()) BinY = h_m_2016postAPV->GetNbinsY();
            fakerate1=h_m_2016postAPV->GetBinContent(BinX, BinY);

            BinX = h_m_2016postAPV->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_m_2016postAPV->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_m_2016postAPV->GetNbinsX()) BinX = h_m_2016postAPV->GetNbinsX();
            if (BinY > h_m_2016postAPV->GetNbinsY()) BinY = h_m_2016postAPV->GetNbinsY();
            fakerate2=h_m_2016postAPV->GetBinContent(BinX, BinY);
	    if(isData){
              w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }else{
              w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }
        }
        return w_temp;
}

float fakelepweight_mm_2017(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_m->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_m->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_m->GetNbinsX()) BinX = h_m->GetNbinsX();
                if (BinY > h_m->GetNbinsY()) BinY = h_m->GetNbinsY();
                fakerate1=h_m->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_m->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_m->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_m->GetNbinsX()) BinX = h_m->GetNbinsX();
                if (BinY > h_m->GetNbinsY()) BinY = h_m->GetNbinsY();
                fakerate1=h_m->GetBinContent(BinX, BinY);
            }
	    if(isData){
              w_temp=fakerate1/(1-fakerate1);
            }else{
              w_temp=-1*fakerate1/(1-fakerate1);
            }
        }
        if(ttc_0P2F){
            BinX = h_m->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_m->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_m->GetNbinsX()) BinX = h_m->GetNbinsX();
            if (BinY > h_m->GetNbinsY()) BinY = h_m->GetNbinsY();
            fakerate1=h_m->GetBinContent(BinX, BinY);

            BinX = h_m->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_m->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_m->GetNbinsX()) BinX = h_m->GetNbinsX();
            if (BinY > h_m->GetNbinsY()) BinY = h_m->GetNbinsY();
            fakerate2=h_m->GetBinContent(BinX, BinY);
	    if(isData){
              w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }else{
              w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }
        }
        return w_temp;
}

float fakelepweight_mm_2018(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_m_2018->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_m_2018->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_m_2018->GetNbinsX()) BinX = h_m_2018->GetNbinsX();
                if (BinY > h_m_2018->GetNbinsY()) BinY = h_m_2018->GetNbinsY();
                fakerate1=h_m_2018->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_m_2018->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_m_2018->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_m_2018->GetNbinsX()) BinX = h_m_2018->GetNbinsX();
                if (BinY > h_m_2018->GetNbinsY()) BinY = h_m_2018->GetNbinsY();
                fakerate1=h_m_2018->GetBinContent(BinX, BinY);
            }
	    if(isData){
              w_temp=fakerate1/(1-fakerate1);
            }else{
              w_temp=-1*fakerate1/(1-fakerate1);
            }
        }
        if(ttc_0P2F){
            BinX = h_m_2018->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_m_2018->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_m_2018->GetNbinsX()) BinX = h_m_2018->GetNbinsX();
            if (BinY > h_m_2018->GetNbinsY()) BinY = h_m_2018->GetNbinsY();
            fakerate1=h_m_2018->GetBinContent(BinX, BinY);

            BinX = h_m_2018->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_m_2018->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_m_2018->GetNbinsX()) BinX = h_m_2018->GetNbinsX();
            if (BinY > h_m_2018->GetNbinsY()) BinY = h_m_2018->GetNbinsY();
            fakerate2=h_m_2018->GetBinContent(BinX, BinY);
	    if(isData){
              w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }else{
              w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
            }
        }
        return w_temp;
}

float fakelepweight_ee_2016APV(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
	//std::cout << "isData" << isData << std::endl;
	//return w_temp;
	//bool myBool = Convert.ToBoolean(sample);
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_e_2016APV->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_e_2016APV->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_e_2016APV->GetNbinsX()) BinX = h_e_2016APV->GetNbinsX();
                if (BinY > h_e_2016APV->GetNbinsY()) BinY = h_e_2016APV->GetNbinsY();
                fakerate1=h_e_2016APV->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_e_2016APV->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_e_2016APV->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_e_2016APV->GetNbinsX()) BinX = h_e_2016APV->GetNbinsX();
                if (BinY > h_e_2016APV->GetNbinsY()) BinY = h_e_2016APV->GetNbinsY();
                fakerate1=h_e_2016APV->GetBinContent(BinX, BinY);
            }
	    if(isData){
	      w_temp=fakerate1/(1-fakerate1);
	    }else{
	      w_temp=-1*fakerate1/(1-fakerate1);
	    }
        }
        if(ttc_0P2F){
            BinX = h_e_2016APV->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_e_2016APV->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_e_2016APV->GetNbinsX()) BinX = h_e_2016APV->GetNbinsX();
            if (BinY > h_e_2016APV->GetNbinsY()) BinY = h_e_2016APV->GetNbinsY();
            fakerate1=h_e_2016APV->GetBinContent(BinX, BinY);

            BinX = h_e_2016APV->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_e_2016APV->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_e_2016APV->GetNbinsX()) BinX = h_e_2016APV->GetNbinsX();
            if (BinY > h_e_2016APV->GetNbinsY()) BinY = h_e_2016APV->GetNbinsY();
            fakerate2=h_e_2016APV->GetBinContent(BinX, BinY);
	    if(isData){
	      w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
	    }else{
	      w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
	    }
        }
        return w_temp;

}


float fakelepweight_ee_2016postAPV(bool ttc_1P1F, bool ttc_0P2F, bool ttc_lep1_faketag, float l1_pt, float l1_eta, float l2_pt, float l2_eta, bool isData){
        float w_temp=1.0;
        float fakerate1=1.0;
        float fakerate2=1.0;
        int BinX = 0;
	//std::cout << "isData" << isData << std::endl;
	//return w_temp;
	//bool myBool = Convert.ToBoolean(sample);
        int BinY = 0;
        if(ttc_1P1F){
            if(ttc_lep1_faketag){
                BinX = h_e_2016postAPV->GetXaxis()->FindBin(fabs(l1_eta));
                BinY = h_e_2016postAPV->GetYaxis()->FindBin(l1_pt);
                if (BinX > h_e_2016postAPV->GetNbinsX()) BinX = h_e_2016postAPV->GetNbinsX();
                if (BinY > h_e_2016postAPV->GetNbinsY()) BinY = h_e_2016postAPV->GetNbinsY();
                fakerate1=h_e_2016postAPV->GetBinContent(BinX, BinY);
            }
            else {
                BinX = h_e_2016postAPV->GetXaxis()->FindBin(fabs(l2_eta));
                BinY = h_e_2016postAPV->GetYaxis()->FindBin(l2_pt);
                if (BinX > h_e_2016postAPV->GetNbinsX()) BinX = h_e_2016postAPV->GetNbinsX();
                if (BinY > h_e_2016postAPV->GetNbinsY()) BinY = h_e_2016postAPV->GetNbinsY();
                fakerate1=h_e_2016postAPV->GetBinContent(BinX, BinY);
            }
	    if(isData){
	      w_temp=fakerate1/(1-fakerate1);
	    }else{
	      w_temp=-1*fakerate1/(1-fakerate1);
	    }
        }
        if(ttc_0P2F){
            BinX = h_e_2016postAPV->GetXaxis()->FindBin(fabs(l1_eta));
            BinY = h_e_2016postAPV->GetYaxis()->FindBin(l1_pt);
            if (BinX > h_e_2016postAPV->GetNbinsX()) BinX = h_e_2016postAPV->GetNbinsX();
            if (BinY > h_e_2016postAPV->GetNbinsY()) BinY = h_e_2016postAPV->GetNbinsY();
            fakerate1=h_e_2016postAPV->GetBinContent(BinX, BinY);

            BinX = h_e_2016postAPV->GetXaxis()->FindBin(fabs(l2_eta));
            BinY = h_e_2016postAPV->GetYaxis()->FindBin(l2_pt);
            if (BinX > h_e_2016postAPV->GetNbinsX()) BinX = h_e_2016postAPV->GetNbinsX();
            if (BinY > h_e_2016postAPV->GetNbinsY()) BinY = h_e_2016postAPV->GetNbinsY();
            fakerate2=h_e_2016postAPV->GetBinContent(BinX, BinY);
	    if(isData){
	      w_temp=-1.0*fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
	    }else{
	      w_temp=fakerate1*fakerate2/((1-fakerate1)*(1-fakerate2));
	    }
        }
        return w_temp;

}

