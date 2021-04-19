#include "fcnc_include.h"
using namespace std;
int main(int argc, char const *argv[])
{

	//if(argc!=5){
	//	printf("Please feed the file with variation list and the file with sample list, give the path of input files\n");
	//	exit(0);
	//}
	TString framework = "tthML";
	TString outputdir = "trexinputs";
	string variable="BDTG_test";
	TString fakefilename[5]={"b_fake","other_fake","w_jet_fake","doublefake","lep_fake"};
	TString prefix = TString(PACKAGE_DIR) + "/config/trexfitter/";
	vector<TString> regions = readTovecString(prefix + framework + "/regionlist.txt");
//======================= read files ======================
	prefix = "./trexinputs/";
	for(auto region:regions){
		if(framework == "tthML") for (int i = 0; i < 5; ++i)
		{
			TFile *fakefile = new TFile(prefix+variable+"/"+region+"/"+fakefilename[i]+".root","update");
			TH1D *fakeNOMINAL = (TH1D*) fakefile->Get("NOMINAL");
			TH1D *fakePHHW = (TH1D*) fakefile->Get("ttbarsys_PHHW");
			TH1D *fakeaMCPy = (TH1D*) fakefile->Get("ttbarsys_aMCPy");
			TH1D *fakePHPyStar = (TH1D*) fakefile->Get("ttbarsys_PHPyStar");
			if(!fakeaMCPy) {
					printf("ttbarsys_aMCPy not found in file %s.\n", fakefile[i]->GetName());
					continue;
			}
			TH1D *ME = (TH1D*) fakeaMCPy ->Clone("ME");
			ME->Add(fakePHPyStar,-1);
			ME->Add(fakeNOMINAL);
			fakefile->cd();
			fakePHHW->Write("PS",TObject::kWriteDelete);
			ME->Write("ME",TObject::kWriteDelete);
			fakefile->Close();
			deletepointer(fakefile);

		}
		TFile *ttbarfile = new TFile(prefix+variable+"/"+region+"/ttbar.root","update");
		TFile *decaysignalfile[2], *mergedsignalfile[2];
		decaysignalfile[0] = new TFile(prefix+variable+"/"+region+"/fcnc_ch.root","update");
		decaysignalfile[1] = new TFile(prefix+variable+"/"+region+"/fcnc_uh.root","update");
		mergedsignalfile[0] =new TFile (prefix+variable+"/"+region+"/tcH.root","update");
		mergedsignalfile[1] =new TFile (prefix+variable+"/"+region+"/tuH.root","update");
		TH1D *ttbarNOMINAL = (TH1D*) ttbarfile->Get("NOMINAL");
		TH1D *ttbarPHHW = (TH1D*) ttbarfile->Get("ttbarsys_PHHW");
		TH1D *ttbaraMCPy = (TH1D*) ttbarfile->Get("ttbarsys_aMCPy");
		TH1D *ttbarPHPyStar = (TH1D*) ttbarfile->Get("ttbarsys_PHPyStar");
		if(!ttbaraMCPy) {
			printf("Histogram %s in File %s is not found.\n",ttbarfile->GetName(),"ttbarsys_aMCPy");
			exit(0);
		}
		TH1D *diffME = (TH1D*) ttbaraMCPy ->Clone("diffME");
		diffME->Add(ttbarPHPyStar,-1);
		diffME->SetDirectory(0);
		double ttbaryield = ttbarNOMINAL->Integral();
		double scalePS = ttbarPHHW->Integral()/ttbaryield;
		double scaleME = diffME->Integral()/ttbaryield;
		if(scaleME > 0.5) scaleME = 0.1;
		if(scaleME < -0.5) scaleME = -0.1;
		if(scalePS > 1.5) scalePS = 1.1;
		if(scalePS < 0.5) scalePS = 0.9; 
		for(int i = 0; i<2 ; i++){
			TH1D *decayNOMINAL = (TH1D*) decaysignalfile[i]->Get("NOMINAL");
			TH1D *mergedNOMINAL = (TH1D*) mergedsignalfile[i]->Get("NOMINAL");
			TH1D *decayME = (TH1D*) decayNOMINAL->Clone("decayME");
			TH1D *decayPS = (TH1D*) decayNOMINAL->Clone("decayPS");
			decayME->Scale(1+scaleME);
			decayPS->Scale(scalePS);
			decaysignalfile[i]->cd();
			decayPS->Write("PS",TObject::kWriteDelete);
			decayME->Write("ME",TObject::kWriteDelete);
			decaysignalfile[i]->Close();
			deletepointer(decaysignalfile[i]);
			TH1D *mergedME = (TH1D*) mergedNOMINAL->Clone("mergedME");
			TH1D *mergedPS = (TH1D*) mergedNOMINAL->Clone("mergedPS");
			mergedME->Add(decayME,scaleME);
			mergedPS->Add(decayPS,scalePS-1);
			mergedsignalfile[i]->cd();
			mergedME->Write("ME",TObject::kWriteDelete);
			mergedPS->Write("PS",TObject::kWriteDelete);
			mergedsignalfile[i]->Close();
			deletepointer(mergedsignalfile[i]);
		}
		TH1D *ttbarME = (TH1D*)ttbarNOMINAL->Clone("ttbarME");
		ttbarME->Add(diffME);
		deletepointer(diffME);
		ttbarfile->cd();
		ttbarPHHW->Write("PS",TObject::kWriteDelete);
		ttbarME->Write("ME",TObject::kWriteDelete);
		ttbarfile->Close();
		deletepointer(ttbarfile);
	}
}
