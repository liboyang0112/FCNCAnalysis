for files in `ls combined_BDTG_test/Systematics`
do
	NPname=${files///}
	echo "
#!/bin/bash
date
. ~/setupMe.sh
cd $PWD
trex-fitter r config/combined/BDTG_test.config Ranking=${NPname}:Signal=tuH:Job=tuH/combined_BDTG_test
date" > $NPname.sh
	chmod +x $NPname.sh
	hep_sub -o $NPname.out -e $NPname.err $NPname.sh
done
