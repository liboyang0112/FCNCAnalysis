#include "LatexChart.h"
#include "TFile.h"
#include "TH1D.h"
#include "common.h"
#include "fcnc_include.h"
using namespace std;
int main(int argc, char const *argv[])
{
	std::map<string, string> regionTitles;
	regionTitles["config_lep2tau2j"] = "t_{l}\\thadhad 2j";
	regionTitles["config_lep2tau3j"] = "t_{l}\\thadhad 3j";
	regionTitles["config_lephad2j"] = "t_{h}\\tlhad-2j";
	regionTitles["config_lephad3j"] = "t_{h}\\tlhad-3j 3j";
	regionTitles["config_lephad4j"] = "t_{h}\\tlhad-3j 4j";
	LatexChart chart[2];
	ifstream inputfile(argv[1]);
	char inputline[200];
	int iline = 0;
	char cchannel[200];
	string channel;
	bool isodd;
	while(!inputfile.eof()){
		inputfile.getline(inputline,200);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		float rate;
		switch(iline%4) {
			case 0:
			channel = inputline;
			if(channel.find("odd") != string::npos) {
				isodd=1;
				findAndReplaceAll(channel,"odd","");
			}
			else {
				isodd=0;
				findAndReplaceAll(channel,"even","");
			}
			break;
			case 1:
			sscanf(inputline,"%f", &rate);
			chart[isodd].set(regionTitles[channel],"神经网络重建效率", rate*50);
			break;
			case 2:
			sscanf(inputline,"%f", &rate);
			chart[isodd].set(regionTitles[channel],"$\\Delta R$重建效率", rate*50);
			break;
			case 3:
			sscanf(inputline,"%f", &rate);
			chart[isodd].set(regionTitles[channel],"同时正确重建效率", rate*50);
			break;
		}
		iline++;
	}
	gSystem->mkdir(TString(TABLE_DIR) + "/TF");
	chart[0].add(&chart[1]);
	chart[0].print(string(TABLE_DIR) + "/TF/Compare");
	return 0;
}

