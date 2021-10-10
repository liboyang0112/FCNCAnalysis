#include "fcnc_include.h"
#include "processVariable.h"
using namespace std;
int main(int argc, char const *argv[])
{

	//if(argc!=5){
	//	printf("Please feed the file with variation list and the file with sample list, give the path of input files\n");
	//	exit(0);
	//}
	TString framework = "tthML";
	TString outputdir = "trexinputs";
	string variable=processVariable.Data();
	TString prefix = TString(PACKAGE_DIR) + "/config/trexfitter/";
	vector<TString> regions = readTovecString(prefix + framework + "/regionlist.txt");
	int scanPoints = 3;
	float interval = 1./(scanPoints+1);
//======================= read files ======================
	prefix = "./trexinputs/";
	for(auto region:regions){
		TFile *tuHfile = new TFile(prefix+variable+"/"+region+"/"+"tuH.root");
		TFile *tcHfile = new TFile(prefix+variable+"/"+region+"/"+"tcH.root");
		TList *tuHkeys = tuHfile->GetListOfKeys();
		int nHist = tuHkeys->GetSize();
		float tuHscale = 1;
		float tcHscale = 0;
		while(tuHscale>interval){
			tuHscale-=interval;
			tcHscale+=interval;
		    TFile *tqHfile = new TFile(prefix+variable+"/"+region+"/"+"tqH" + char('0' + (int)(tcHscale/interval)) + ".root","recreate");
			for(int i = 0; i < nHist ; i++){
				TKey* tuHkey = (TKey*) tuHkeys->At(i);
				TString histName = tuHkey->GetName();
				TH1D* tuHhist = (TH1D*)tuHkey->ReadObj();
				tuHhist->Scale(tuHscale);
				tuHhist->Add((TH1D*)tcHfile->Get(histName),tcHscale);
				tqHfile->cd();
				tuHhist->Write(histName);
			}
			tqHfile->Close();
			deletepointer(tqHfile);
			if(tuHscale == 0) break;
		}
	}
	return 0;
}
