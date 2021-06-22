signal=(fcnc_prod_uh fcnc_prod_ch fcnc_ch fcnc_uh tuH tcH)
region=(reg1l1tau1b1j_ss reg1l1tau1b2j_ss reg1l1tau1b2j_os reg1l1tau1b3j_os reg1l2tau1bnj_os)



for sig in ${signal[@]}
do
	#echo "cp $sig/combined_BDT_test/Limits.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/StatOnly/$sig.pdf"
	#cp $sig/combined_BDTG_test/Limits.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/StatOnly/$sig.pdf
	for reg in ${region[@]}
	do
		echo "cp $sig/combined_BDTG_test/Plots/$reg.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/$reg.pdf"
		cp $sig/combined_BDTG_test/Plots/$reg.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/$reg.pdf
		echo "cp $sig/combined_BDTG_test/Plots/${reg}_postFit.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/${reg}_postFit.pdf"
		cp $sig/combined_BDTG_test/Plots/${reg}_postFit.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/${reg}_postFit.pdf
	done
done

cp tuH/combined_BDTG_test/RankingSysts_SigXsecOverSM.pdf $DestDir/Limit/tuH_Ranking.pdf
rm $DestDir/Limit/tuH_Pruning*.pdf
for files in `ls tuH/combined_BDTG_test | grep Pruning | grep pdf`
do
	cp tuH/combined_BDTG_test/$files $DestDir/Limit/tuH_$files
done
#cp tcH/combined_BDTG_test/RankingSysts_SigXsecOverSM.pdf $DestDir/Limit/tcH_Ranking.pdf

for sig in ${signalall[@]}
do
	cp $sig/combined_BDTG_test/NuisPar.pdf $DestDir/Limit/${sig}_NuisPar.pdf
	cp $sig/combined_BDTG_test/CorrMatrix.pdf $DestDir/Limit/${sig}_CorrMatrix.pdf
done

cp -r combined_BDTG_test/Systematics/ttbar* $DestDir/trexfitter/.
cp -r combined_BDTG_test/Systematics/TES_DETECTOR $DestDir/trexfitter/.
cp -r combined_BDTG_test/Systematics/scale $DestDir/trexfitter/
cp -r combined_BDTG_test/Systematics/FSR $DestDir/trexfitter/.
cp -r combined_BDTG_test/Systematics/ABCD_electron $DestDir/trexfitter/.

cp tuH/combined_BDTG_test/Tables/Yields*.tex $FCNC_DIR/FCNCTables/tthML/yield
