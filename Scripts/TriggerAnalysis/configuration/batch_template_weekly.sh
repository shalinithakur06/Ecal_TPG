#!/bin/bash

ps | grep `echo $$` | awk '{ print $4 }' 

export mypwd=`pwd`




cd %cmsswdir%

eval `scram runtime -sh`
if [ $X509_USER_PROXY!="" ]; then 
    export X509_USER_PROXY=`find %cmsswdir%/x509up_u*`
fi 
echo 
cd -
#cd \${lxbatchpwd}

echo "Starting CMSSW" 
cp %cmsswdir%/runTPG_weekly_%njob%.py .
cmsRun runTPG_weekly_%njob%.py  

cmsStage -f ECALTPGtree.root /store/caf/user/%username%/LaserVal/%runNb%/ECALTPGtree_%njob%.root


echo "LAST PWD" 'pwd'

