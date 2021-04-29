signalall=(fcnc_prod_uh fcnc_prod_ch fcnc_ch fcnc_uh tuH tcH)
signal=(tuH tcH)
region=(reg1l1tau1b1j_ss reg1l1tau1b2j_ss reg1l1tau1b2j_os reg1l1tau1b3j_os reg1l2tau1bnj_os)

for sig in ${signal[@]}
do
	#echo "cp $sig/combined_BDT_test/Limits.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/StatOnly/$sig.pdf"
	#cp $sig/combined_BDTG_test/Limits.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/StatOnly/$sig.pdf
	for reg in ${region[@]}
	do
		echo "cp $sig/combined_BDTG_test/Plots/$reg.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/${sig}_$reg.pdf"
		cp $sig/combined_BDTG_test/Plots/$reg.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/${sig}_$reg.pdf
		echo "cp $sig/combined_BDTG_test/Plots/${reg}_postFit.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/${sig}_${reg}_postFit.pdf"
		cp $sig/combined_BDTG_test/Plots/${reg}_postFit.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/${sig}_${reg}_postFit.pdf
	done
done

cp tuH/combined_BDTG_test/RankingSysts_SigXsecOverSM.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/tuH_Ranking.pdf
cp tuH/combined_BDTG_test/Pruning.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/tuH_Pruning.pdf
#cp tcH/combined_BDTG_test/RankingSysts_SigXsecOverSM.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/tcH_Ranking.pdf

for sig in ${signalall[@]}
do
	cp $sig/combined_BDTG_test/NuisPar.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/${sig}_NuisPar.pdf
	cp $sig/combined_BDTG_test/CorrMatrix.pdf $FCNC_DIR/FCNCFigures/tthML/Limit/${sig}_CorrMatrix.pdf
done
