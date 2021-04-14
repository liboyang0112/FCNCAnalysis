#include "fcnc_include.h"
using namespace std;
int main(int argc, char const *argv[])
{

	//if(argc!=5){
	//	printf("Please feed the file with variation list and the file with sample list, give the path of input files\n");
	//	exit(0);
	//}
	TString framework = "tthML";
	string variationlistfile = argv[1];
	TString outputdir = "trexinputs";
	string variable="BDTG_test";
	TString prefix = TString(PACKAGE_DIR) + "/config/trexfitter/";
	vector<TString> regions = readTovecString(prefix + framework + "/regionlist.txt");
//======================= read files ======================
	for(auto region:regions){
		TFile *ttbarfile = new TFile(prefix+variable+"/"+region+"/ttbar.root","update");
		TFile *decaysignalfile[2], *mergedsignalfile[2];
		decaysignalfile[0] = new TFile(prefix+variable+"/"+region+"/fcnc_ch.root","update");
		decaysignalfile[1] = new TFile(prefix+variable+"/"+region+"/fcnc_uh.root","update");
		mergedsignalfile[0] =new TFile (prefix+variable+"/"+region+"/tch.root","update");
		mergedsignalfile[1] =new TFile (prefix+variable+"/"+region+"/tuh.root","update");
		TH1D *ttbarNOMINAL = (TH1D*) ttbarfile->Get("NOMINAL");
		TH1D *ttbarPHHW = (TH1D*) ttbarfile->Get("ttbarsys_PHHW");
		TH1D *ttbaraMCPy = (TH1D*) ttbarfile->Get("ttbarsys_aMCPy");
		TH1D *ttbarPHPyStar = (TH1D*) ttbarfile->Get("ttbarsys_PHPyStar");
		TH1D *diffME = (TH1D*) ttbaraMCPy ->Clone("diffME");
		diffME->Add(ttbarPHPyStar,-1);
		double ttbaryield = ttbarNOMINAL->Integral();
		double scalePS = ttbarPHHW->Integral()/ttbaryield;
		for(int i = 0; i<2 ; i++){
			TH1D *decayNOMINAL = (TH1D*) decaysignalfile[i]->Get("NOMINAL");
			TH1D *mergedNOMINAL = (TH1D*) mergedsignalfile[i]->Get("NOMINAL");
			TH1D *decayME = (TH1D*) decayNOMINAL->Clone("decayME");
			TH1D *decayPS = (TH1D*) decayNOMINAL->Clone("decayPS");
			decayME->Scale(1+diffME->Integral()/ttbaryield);
			decayPS->Scale(scalePS);
			decaysignalfile[i]->cd();
			decayPS->Write("PS",TObject::kWriteDelete);
			decayME->Write("ME",TObject::kWriteDelete);
			decaysignalfile[i]->Close();
			deletepointer(decaysignalfile[i]);
			TH1D *mergedME = (TH1D*) mergedNOMINAL->Clone("mergedME");
			TH1D *mergedPS = (TH1D*) mergedNOMINAL->Clone("mergedPS");
			mergedME->Add(decayME,diffME->Integral()/ttbaryield);
			mergedPS->Add(decayPS,scalePS-1);
			mergedsignalfile[i]->cd();
			mergedME->Write("ME",TObject::kWriteDelete);
			mergedPS->Write("PS",TObject::kWriteDelete);
			mergedsignalfile[i]->Close();
			deletepointer(mergedsignalfile[i]);
		}
		TH1D *ttbarME = (TH1D*)ttbarNOMINAL->Clone("ttbarME");
		ttbarME->Add(diffME);
		ttbarfile->cd();
		ttbarPHHW->Write("PS",TObject::kWriteDelete);
		ttbarME->Write("ME",TObject::kWriteDelete);
		ttbarfile->Close();
		deletepointer(ttbarfile);
	}
}