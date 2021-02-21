#include "LatexChart.h"
#include "TFile.h"
#include "TH1D.h"
#include "common.h"
#include "fcnc_include.h"
using namespace std;
int main(int argc, char const *argv[])
{
	std::map<string, string> regionTitles;
	regionTitles["lep2tau2j"] = "l\\thadhad 2j";
	regionTitles["lep2tau3j"] = "l\\thadhad 3j";
	regionTitles["lephad2j"] = "STH \\tlhad";
	regionTitles["lephad3j"] = "TTH \\tlhad 3j";
	regionTitles["lephad3j"] = "TTH \\tlhad 4j";
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
		char channel[200];
		switch(iline%4) {
			case 0:
			sscanf(inputline,"%s", cchannel);
			channel=cchannel;
			if(channel.find("odd")) {
				isodd=1;
				findAndReplaceAll(channel,"odd");
			}
			else {
				isodd=0;
				findAndReplaceAll(channel,"even");
			}
			break;
			case 1:
			sscanf(inputline,"%d", rate);
			chart[isodd].set(regionTitles[channel],"神经网络重建效率", rate*50);
			break;
			case 2:
			sscanf(inputline,"%d", rate);
			chart[isodd].set(regionTitles[channel],"$\\Delta R$重建效率", rate*50);
			break;
			case 3:
			sscanf(inputline,"%d", rate);
			chart[isodd].set(regionTitles[channel],"同时正确重建效率", rate*50);
			break;
		}
		iline++;
	}
	chart.print(string(TABLE_DIR) + "/BDT/" + framework + "_OptimResult");
	return 0;
}

