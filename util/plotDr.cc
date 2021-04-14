#include "TLine.h"
#include "AtlasStyle.h"
#include "AtlasLabels.h"
#include "fcnc_include.h"
int main(){
	std::vector<TString> filename = {
		"FCNCDr.root",
		"lep2tau2jevenFCNCDr.root",
		"lep2tau2joddFCNCDr.root",
		"lep2tau3jevenFCNCDr.root",
		"lep2tau3joddFCNCDr.root",
		"lephad2jevenFCNCDr.root",
		"lephad2joddFCNCDr.root",
		"lephad3jevenFCNCDr.root",
		"lephad3joddFCNCDr.root",
		"lephad4jevenFCNCDr.root",
		"lephad4joddFCNCDr.root",
	};
	SetAtlasStyle();
	TCanvas c1("","",1000,1000);
	c1.SetMargin(0.08,0.12,0.08,0.05);
	//c1.SetLeftMargin(0.1);
	TLine line(0,0,6,6);
	line.SetLineWidth(3);
	line.SetLineColor(kRed);
	for(auto name : filename){
		TFile file(name);
		TH2D *hist = (TH2D*)file.Get("hist");
		hist->GetXaxis()->SetTitle("#Delta R(FCNC-jet,#tau#tau)");
		hist->GetYaxis()->SetTitle("#Delta R(Other jet,#tau#tau)");
		hist->GetZaxis()->SetRangeUser(0.000001,hist->GetMaximum());
		c1.cd();
		hist->Draw("COLZ");
		line.Draw("same");
		c1.SaveAs(name+".pdf");
	}
}