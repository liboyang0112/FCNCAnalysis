regions=("reg1l1tau1b1j_ss" "reg1l1tau1b2j_ss" "reg1l1tau1b3j_os" "reg1l1tau1b2j_os" "reg1l2tau1bnj_os" "combined")
regiontitle=("t_{l}#tau_{had}-1j" "t_{l}#tau_{had}2j" "t_{h}#tau_{lep}#tau_{had}-3j" "t_{h}#tau_{lep}#tau_{had}-2j" "t_{l}#tau_{had}#tau_{had}" "Combined")
variable="BDTG_test"
variabletitle="BDT Discriminant"
log="FALSE"

cp $ttH_fakes_DIR/config/trexfitter/tthML/myFit.config tthML.config
cp $ttH_fakes_DIR/config/trexfitter/tthML/combine.config .
cat $ttH_fakes_DIR/config/trexfitter/tthML/fake_sys.config >> tthML.config
cat $ttH_fakes_DIR/config/trexfitter/tthML/Instrumental_sys.config >> tthML.config
cat $ttH_fakes_DIR/config/trexfitter/common.config >> tthML.config
cat $ttH_fakes_DIR/config/trexfitter/btag.config >> tthML.config
if [[ $variable =~ 'BDTG' ]] ; then
	bin="Binning: -1,-0.4,0.1,0.3,0.5,0.65,0.75,0.85,1"
	log="TRUE"
fi
rebin=1
mkdir -p config
for i in {0..2}
do
	mkdir -p config/${regions[i]}
	echo "ReplacementFile:tthML.config
XXXjobname:${regions[i]}_$variable
XXXoutdir:\".\"
XXXvariable:$variable
XXXxaxis:$variabletitle
XXXlog:$log
XXXrebin:$rebin
XXXBinning:$bin
XXXregion:${regions[i]}
XXXregopt:${regions[i]}
XXXlabel:\"${regiontitle[i]}\"
XXXhistoPathSuff:\"/${regions[i]}\";" > config/${regions[i]}/$variable.config
done

	mkdir -p config/combined
	echo "ReplacementFile:tthML.config
XXXjobname:combined_$variable
XXXoutdir:\".\"
XXXvariable:$variable
XXXxaxis:$variabletitle
XXXlog:$log
XXXrebin:$rebin
XXXBinning:$bin
XXXregion:\"${regions[0]}\";\"${regions[1]}\";\"${regions[2]}\";\"${regions[3]}\";\"${regions[4]}\"
XXXregopt:\"${regions[0]}\",\"${regions[1]}\",\"${regions[2]}\",\"${regions[3]}\",\"${regions[4]}\"
XXXlabel:\"${regiontitle[0]}\";\"${regiontitle[1]}\";\"${regiontitle[2]}\";\"${regiontitle[3]}\";\"${regiontitle[4]}\"
XXXhistoPathSuff:\"${regions[0]}_vetobtagwp70_highmet\";\"${regions[1]}_vetobtagwp70_highmet\";\"${regions[2]}_vetobtagwp70_highmet\";\"${regions[3]}_vetobtagwp70_highmet\";\"${regions[4]}\"" > config/combined/$variable.config

