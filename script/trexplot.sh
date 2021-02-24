variable=BDTG_test
signals=("tcH" "tuH" "fcnc_ch" "fcnc_uh" "fcnc_prod_ch" "fcnc_prod_uh")
regions=("reg1l1tau1b1j_ss" "reg1l1tau1b2j_ss" "reg1l1tau1b3j_os" "reg1l1tau1b2j_os" "reg1l2tau1bnj_os" "combined")
usecombJO=0
runfit(){
	sig=$1
	for reg in ${regions[@]}
	do
		mkdir -p $sig/${reg}_$variable
	done
	mkdir -p $sig/combined
	for reg in ${regions[@]}
	do
		trex-fitter w config/$reg/$variable.config "Signal=$sig"
	done
	trex-fitter mw combine.config "Signal=$sig"
	trex-fitter mf combine.config "Signal=$sig"
	trex-fitter ml combine.config "Signal=$sig"
	for reg in ${regions[@]}
	do
		rm -rf $sig/${reg}_$variable/RooStats
		mv ${reg}_$variable/RooStats $sig/${reg}_$variable/.
	done
	rm -rf $sig/combined
	mv combined $sig/.
	for reg in ${regions[@]}
	do
		trex-fitter f config/$reg/$variable.config "Signal=$sig:Job=$sig/${reg}_$variable"
		trex-fitter l config/$reg/$variable.config "Signal=$sig:Job=$sig/${reg}_$variable"
	done
}

runfitcomb(){
	sig=$1
	for reg in ${regions[@]}
	do
		mkdir -p $sig/${reg}_$variable
		rm $sig/${reg}_$variable/Histograms
		ln -s $PWD/combined_$variable/Histograms $sig/${reg}_$variable/Histograms
		if [[ $reg =~ "combined" ]] ; then
			trex-fitter wfdpl config/combined/$variable.config "Signal=$sig:Job=$sig/${reg}_$variable" > $sig/${reg}_$variable/runlog 2>&1 &
			#trex-fitter wfdp config/combined/$variable.config "Signal=$sig:Job=$sig/${reg}_$variable"
		else
			trex-fitter wfl config/combined/$variable.config "Signal=$sig:Regions=$reg:Job=$sig/${reg}_$variable" > $sig/${reg}_$variable/runlog 2>&1 &
		fi
	done
}

if (( $# >= 1 )) ; then
	if ((usecombJO==1)) ; then
		for reg in ${regions[@]}
		do
			trex-fitter h config/$reg/$variable.config
		done
		runfit $1
	else
		trex-fitter h config/combined/$variable.config
		runfitcomb $1
	fi
else
	if ((usecombJO==1)) ; then
		for reg in ${regions[@]}
		do
			trex-fitter h config/$reg/$variable.config
		done
		for sig in "${signals[@]}"
		do
			runfit $sig
		done
	else
		trex-fitter h config/combined/$variable.config
		for sig in "${signals[@]}"
		do
			runfitcomb $sig
		done
	fi
fi
