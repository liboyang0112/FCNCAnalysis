#include "LatexChart.h"
#include "TFile.h"
#include "TH1D.h"
#include "common.h"
#include "fcnc_include.h"
using namespace std;

void setlimit(LatexChart *chart, TString filename, string row, string column){
	//printf("Limit File: %s\n", filename.Data());
	TFile thefile(filename);
	if(thefile.IsZombie()) return;
	TTree *thetree = (TTree*) thefile.Get("stats");
	float exp_upperlimit,exp_upperlimit_plus1,exp_upperlimit_minus1;
	//TBranch *b_exp_upperlimit,*b_exp_upperlimit_plus1,*b_exp_upperlimit_minus1;
	thetree->SetBranchAddress("exp_upperlimit",&exp_upperlimit);
	thetree->SetBranchAddress("exp_upperlimit_plus1",&exp_upperlimit_plus1);
	thetree->SetBranchAddress("exp_upperlimit_minus1",&exp_upperlimit_minus1);
	thetree->GetEntry(0);
	observable limit;
	limit.nominal = exp_upperlimit;
	limit.error = exp_upperlimit_plus1-exp_upperlimit;
	limit.errordown = exp_upperlimit-exp_upperlimit_minus1;
	//printf("chart->set(%f,%f,%f)\n", thehist->GetBinContent(2),thehist->GetBinContent(4)-thehist->GetBinContent(2),thehist->GetBinContent(2)-thehist->GetBinContent(5));
	chart->set(row,column,limit);
}

int main(int argc, char const *argv[])
{
	bool doComb = 1;
	bool doBlind = 1;
	bool statsOnly = 1;
	TString variable = "BDTG_test";
	auto sigsample = getSigSamples("tthML",0.2);
	vector<TString> channels = {"reg1l1tau1b2j_ss","reg1l1tau1b1j_ss","reg1l1tau1b2j_os","reg1l1tau1b3j_os","reg1l2tau1bnj_os"};
	vector<TString> channelstitle = {"$l\\tauhad$2j", "$l\\tauhad$1j", "STH $\\tlhad$", "TTH $\\tlhad$", "$l\\thadhad$"};
	string framework = argc>1? argv[1]:"";
	if(framework!="") doComb=0;
	LatexChart *chart = new LatexChart("limit");
	for (int isig = 0; isig < sigsample.size(); ++isig)
	{
		if(doComb && (sigsample[isig].name!="tcH" && sigsample[isig].name!="tuH")) continue;
		string samptitle=sigsample[isig].title.Data();
		if(samptitle.find("#")!=string::npos) samptitle = "$" + samptitle + "$";
		findAndReplaceAll(samptitle,"rightarrow","to ");
		findAndReplaceAll(samptitle,"#","\\");
		TString jobname = sigsample[isig].name;
		if(!doComb){
			for (int ichan = 0; ichan < channels.size(); ++ichan)
			{
				TString jobname = sigsample[isig].name + "/" + channels[ichan] + "_" + variable;
				setlimit(chart, jobname + "/Limits/asymptotics/myLimit_BLIND_CL95.root", samptitle, channelstitle[ichan].Data());
			}
			jobname = sigsample[isig].name + "/combined" + "_" + variable;
			setlimit(chart, jobname + "/Limits/asymptotics/myLimit"+ (doBlind?"_BLIND":"") + "_CL95.root", samptitle, "Combined");
		}else{
			setlimit(chart, jobname + "/Limits/asymptotics/myLimit"+ (doBlind?"_BLIND":"") + "_CL95.root", "Combined Limit", samptitle);
		}
	}
	chart->caption="The limits derived from leptonic channels.";
	chart->print(string(TABLE_DIR)+(doComb?"":"/" + framework) + "/limits"+(statsOnly?"_statsOnly":""));
	return 0;
}
