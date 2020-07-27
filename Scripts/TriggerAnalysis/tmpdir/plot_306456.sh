
cd  /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/
eval `scramv1 runtime -sh`;
cd -;
echo ""
echo "TPGTreeReader running on all triggers..."
echo ""
echo 
echo " /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/bin/slc7_amd64_gcc700/TPGTreeReader -SLMinEvt  -SLMaxEvt  -SLMinOrb  -SLMaxOrb  -SLMaxTime  -SLMinTime   -d /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/Scripts/TriggerAnalysis/ -i ECALTPGtree_306456.root -o newhistoTPG_306456_eg30.root -l1bx 39,62  -g /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/TPGPlotting/plots/endcapGeometry.txt -EG 30 "

/afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/bin/slc7_amd64_gcc700/TPGTreeReader -SLMinEvt  -SLMaxEvt  -SLMinOrb  -SLMaxOrb  -SLMaxTime  -SLMinTime   -d /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/Scripts/TriggerAnalysis/ -i ECALTPGtree_306456.root -o newhistoTPG_306456_eg30.root  -l1bx 39,40,41,42,43,44,45,46,48,50,52  -g /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/TPGPlotting/plots/endcapGeometry.txt -EG 30 
cp -f newhistoTPG_306456_eg30.root /eos/user/s/sthakur/newhistoTPG_306456_eg30.root
mv newhistoTPG_306456_eg30.root /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/TPGPlotting/plots/.
echo ""
echo "TPGTreeReader running on Ecal triggers..."
/afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/bin/slc7_amd64_gcc700/TPGTreeReader -SLMinEvt  -SLMaxEvt  -SLMinOrb  -SLMaxOrb  -SLMaxTime  -SLMinTime  -d /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/Scripts/TriggerAnalysis/ -i ECALTPGtree_306456.root -o newhistoTPG_Ecal_306456_eg30.root -l1 39,40,41,42,43,44,45,46,48,50,52   -l1bx 39,40,41,42,43,44,45,46,48,50,52 -g /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/TPGPlotting/plots/endcapGeometry.txt -EG 30 
cp -f newhistoTPG_Ecal_306456_eg30.root /eos/user/s/sthakur/newhistoTPG_Ecal_306456_eg30.root
mv newhistoTPG_Ecal_306456_eg30.root /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/TPGPlotting/plots/.


echo ""
echo "Now producing plots..."
echo 'cd /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/TPGPlotting/plots'
echo 'in the TPGdirectory'
echo './makeTPGPlots.sh -r 306456 -l /eos/user/s/sthakur -p /eos/user/s/sthakur -e 30 -z _eg30'
cd /afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/TPGPlotting/plots
./makeTPGPlots.sh -r 306456 -l /eos/user/s/sthakur -p /eos/user/s/sthakur -e 30 -z _eg30
