rm tmp
for files in `ls $ttH_fakes_DIR/config/tensorflow/`
do
	echo $files >> tmp
	testJetFinder.py $ttH_fakes_DIR/config/tensorflow/$files >> tmp
done

print_JetFinder_run tmp
rm tmp