#include "LatexChart.h"
#include "TFile.h"
#include "TH1D.h"
#include "common.h"
#include "fcnc_include.h"
using namespace std;
int main(int argc, char const *argv[])
{
	std::map<string, string> regionTitles;

	string framework = argv[1];
	if(framework == "tthML"){
		regionTitles["reg1l2tau1bnj_os"] = "t_l\\thadhad";
		regionTitles["reg1l1tau1b1j_ss"] = "t_l\\tauhad-1j";
		regionTitles["reg1l1tau1b2j_os"] = "t_h\\tlhad-2j";
		regionTitles["reg1l1tau1b2j_ss"] = "t_l\\tauhad-2j";
		regionTitles["reg1l1tau1b3j_os"] = "t_h\\tlhad-3j";
    }else{
		regionTitles["reg2mtau1b2jos"] = "t_h\\thadhad-2j";
		regionTitles["reg2mtau1b3jos"] = "t_h\\thadhad-3j";
	}
	LatexChart chart("BDTOptimResult");
	ifstream inputfile(argv[1]);
	char inputline[200];
	while(!inputfile.eof()){
		inputfile.getline(inputline,200);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		int ncut,ntree;
		char channel[200];
		sscanf(inputline,"%s %d %d", channel, &ncut, &ntree);
		chart.set(regionTitles[channel],"NCuts", (float)ncut);
		chart.set(regionTitles[channel],"NTrees", (float)ntree);
	}
	chart.print(string(TABLE_DIR) + "/BDT/" + framework + "_OptimResult");
	return 0;
}

