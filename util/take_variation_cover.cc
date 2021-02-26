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
	vector<TString> samples = readTovecString(prefix + framework + "/samplelist.txt");
	vector<TString> regions = readTovecString(prefix + framework + "/regionlist.txt");
	vector<TString> variations = readTovecString(prefix + variationlistfile.c_str());
	vector<TString> varup;  //varup[ibin]
	vector<TString> vardown; //vardown[ibin]
	varup.push_back("");
	vardown.push_back("");
	map<TString,TH1D*> stacked_histograms;
	map<TString,map<TString,TH1D*>> histograms;
	std::vector<TString> noVariation;
//======================= read files ======================
	for(auto region:regions){
	string inputfilestr = variationlistfile;
	findAndReplaceAll(inputfilestr,".txt","/"+variable+"/"+region.Data());
	for(auto sample: samples){
		TFile* inputfile = new TFile(inputfilestr + "/" + sample+".root");
		for(auto variation: variations){
			TH1D* tmphist = (TH1D*)inputfile->Get(variation);
			if(!tmphist) {
				noVariation.push_back(sample);
				break;
			}
			histograms[sample][variation] = (TH1D*)tmphist->Clone(sample+"_"+variation);
			histograms[sample][variation]->SetDirectory(0);
			if(stacked_histograms.find(variation) == stacked_histograms.end()) {
				stacked_histograms[variation] = (TH1D*)tmphist->Clone("stacked_" + variation);
				stacked_histograms[variation]->SetDirectory(0);
			}
			else stacked_histograms[variation]->Add(tmphist);
		}
		deletepointer(inputfile);
	}

//======================= find cover ======================
	TH1D *templatehist = (TH1D*)histograms[samples[0]][variations[0]]->Clone("template");
	templatehist->SetDirectory(0);
	int nbins = templatehist->GetNbinsX();

	for (int i = 1; i <= nbins; ++i)
	{
		float cover_hi = NAN;
		float cover_low = NAN;
		varup.push_back("");
		vardown.push_back("");
		for(auto variation: variations){
			auto iter = stacked_histograms.find(variation.Data());
			if(iter == stacked_histograms.end()) {
				printf("variation not found %s\n", variation.Data());
				continue;
			}
			float content = stacked_histograms.at(variation)->GetBinContent(i);
			if(cover_hi != cover_hi || cover_hi<content) {
				cover_hi = content;
				varup[i] = variation;
			}
			if(cover_low != cover_low || cover_low > content) {
				cover_low = content;
				vardown[i] = variation;
			}
		}
	}

	for(auto x : stacked_histograms) deletepointer(x.second);
	stacked_histograms.clear();  //histograms[variation]
//======================= save cover ======================
	string outputfilestr = variationlistfile;
	findAndReplaceAll(outputfilestr,"_trexinputs.txt","");
	for(auto sample: samples){
		if(find(noVariation.begin(),noVariation.end(),sample) != noVariation.end()) continue;
		TString outfilename = outputdir+"/" + variable.c_str() + "/" +region+"/" + sample + ".root";
		printf("outputfile name: %s\n", outfilename.Data());
		TFile outputfile(outfilename,"update");
		for (int i = 1; i <= nbins; ++i){
			templatehist->SetBinContent(i,histograms[sample][varup[i]]->GetBinContent(i));
			templatehist->SetBinError(i,histograms[sample][varup[i]]->GetBinError(i));
		}
		outputfile.cd();
		printf("hist name: %s\n", (outputfilestr+"_up").c_str());
		templatehist->Write((outputfilestr+"_up").c_str(),TObject::kWriteDelete);
		for (int i = 1; i <= nbins; ++i){
			templatehist->SetBinContent(i,histograms.at(sample).at(vardown[i])->GetBinContent(i));
			templatehist->SetBinError(i,histograms[sample][vardown[i]]->GetBinError(i));
		}
		printf("hist name: %s\n", (outputfilestr+"_down").c_str());
		templatehist->Write((outputfilestr+"_down").c_str(),TObject::kWriteDelete);
	}
	for(auto x:histograms){
		for(auto y:x.second)
			deletepointer(y.second);
		x.second.clear();
	}
	histograms.clear();

	deletepointer(templatehist);
	}
	return 0;
}