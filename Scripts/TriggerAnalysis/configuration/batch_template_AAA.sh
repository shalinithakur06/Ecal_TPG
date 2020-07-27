#!/bin/bash

ps | grep `echo $$` | awk '{ print $4 }' 

export mypwd=`pwd`

myusername="$USER"
UserNameInit="s"



cd %cmsswdir%

#export SCRAM_ARCH slc5_amd64_gcc434
#source /afs/cern.ch/cms/LCG/LCG-2/UI/cms_ui_env.sh
eval `scram runtime -sh`
if [ $X509_USER_PROXY!="" ]; then 
    export X509_USER_PROXY=`find %cmsswdir%/x509up_u*`
fi 
echo 
cd -
#cd \${lxbatchpwd}
outputdir="/eos/user/${UserNameInit}/${myusername}/TPG/AllEvents"

echo "Starting CMSSW" 
cp %cmsswdir%/runTPG_cfg_%njob%.py .
cmsRun runTPG_cfg_%njob%.py  >& /dev/null

#mv ECALTPGtree.root %cmsswdir%/results/ECALTPGtree_%njob%.ro
echo "${outputdir}/%runNb%"
mkdir -p ${outputdir}/%runNb%
cp  ECALTPGtree.root ${outputdir}/%runNb%/ECALTPGtree_%njob%.root
#cp  ECALTPGtree.root /afs/cern.ch/user/s/sdutt/work/TPGAnalysis/CMSSW_9_4_0_pre3/src/ECALTPGtree_%njob%.root


echo "LAST PWD" 'pwd'

