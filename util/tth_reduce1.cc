#include "tthmltree.h"
#include <thread>
int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printf("please input reduce scheme, sample.txt, sysname\nFor example: >$tth_reduce2_run fcnc_prod_chd.txt nominal");
	}

	bool doplot = 0;
	TString prefix1;
	TString prefix = PACKAGE_DIR;
	ifstream fn(argv[1]);
	if(!fn) {
	  fprintf(stderr,"Error: can't open file: %s\n",argv[1]);
	  return 1;
	}
	thread th1(PrintTime, 5);
	th1.detach();
	char inputline[100];

	tthmltree *analysis = new tthmltree();
	analysis->nominaltree = 1;
	analysis->fcnc_regions.push_back("reg1l1tau1b2j_os");
	analysis->fcnc_regions.push_back("reg1l1tau1b3j_os");
	analysis->fcnc_regions.push_back("reg1l1tau2b2j_os");
	analysis->fcnc_regions.push_back("reg1l1tau2b3j_os");
	analysis->fcnc_regions.push_back("reg1l1tau1b2j_ss");
	analysis->fcnc_regions.push_back("reg1l1tau1b3j_ss");
	analysis->fcnc_regions.push_back("reg1l1tau2b2j_ss");
	analysis->fcnc_regions.push_back("reg1l1tau2b3j_ss");
	analysis->fcnc_regions.push_back("reg1l2tau1bnj_os");
	analysis->fcnc_regions.push_back("reg1l2tau1bnj_ss");
	analysis->fcnc_regions.push_back("reg1l2tau2bnj_os");
	analysis->fcnc_regions.push_back("reg1l2tau2bnj_ss");
	analysis->fake_regions.push_back("reg1e1mu1tau2b");
	analysis->fake_regions.push_back("reg1l1tau2b1j_os");
	analysis->fake_regions.push_back("reg1l1tau2b1j_ss");
	analysis->fake_regions.push_back("reg1l1tau2b_os");
	analysis->fake_regions.push_back("reg1l1tau2b_ss");
	analysis->fake_regions.push_back("reg1e1mu1tau1b");
	analysis->fake_regions_notau.push_back("reg1e1mu2bnj");
	analysis->fake_regions_notau.push_back("reg1l2b2j");
	analysis->fake_regions_notau.push_back("reg1e1mu2b");

	analysis->SystematicsName = argv[2];
	analysis->reduce = 1;
	analysis->debug = 0;
	analysis->dumptruth = 0;
        analysis->writetree = 1;
	fn.getline(inputline,200);
	char filename[100];
	char cate[100];
	char title[100];
	int version;
	sscanf(inputline,"%d %s %s %s",&version,filename,cate,title);
	prefix1 ="/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21SkimV";
	prefix1 += char('0'+ version);
	prefix1 += "/MytthAnaSkim_";
	printf("reading list: %s as %s with name %s\n", (prefix + "/datafiles/tthML/" + filename + ".txt").Data(), cate, title);
	ifstream list(prefix + "/datafiles/tthML/" + filename + ".txt");
	analysis->version = version;
//	analysis->init_hist(cate);
	analysis->init_sample(cate, title);
	while(!list.eof()){
		list.getline(inputline,200);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		printf("reading Root file: %s\n", (prefix1 + inputline).Data());
		TFile inputfile(prefix1 + inputline);
		analysis->Loop( (TTree*)inputfile.Get(argv[2]), cate);
		inputfile.Close();
	}
	analysis->finalise_sample();
	return 0;
}
