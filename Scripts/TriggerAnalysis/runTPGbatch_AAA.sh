#!/bin/bash

echo $#

if [[ "$#" < "4" || "$#" > "6" ]] ; then
  echo "runBatchFromCastor.sh: tool for running Batch Jobs for TPG analysis "
  echo "Usage:"
  echo "  ./runAll.sh [mode] [nevt] {filter}"
  echo "      [mode]   - local, lxbatch, grid"
  echo "      [runNb]   - run number"
  echo "      [dataset]   - run number"
  echo "      [nevt]   - number of events per run"
  echo ""
  echo "  Example: ./runTPGbatch.sh lxbatch 234610 Commissioning2016/MinimumBias/RAW/v1 GR_E_V43::All -1  "	 
  exit 1
fi
 

mode="$1"          # 1 run mode
runnb="$2"         # 2 run number
dataset="$3"       # 3 dataset name 
gtag="$4"          # 4 global tag
events="$5"        # number of events per files
eventsPerCastorFile=${events}
isMC="$6"
echo $isMC

#pathrunnb=`echo $runnb | sed 's,\([0-9][0-9][0-9]\)\([0-9][0-9][0-9]\),\1/\2,'`
pathrunnb=`echo $runnb | sed 's,\([0-9][0-9][0-9]\)\([0-9][0-9][0-9]\),\1/\2,'`



myusername="$USER"

echo "path runnumber " ${pathrunnb}
datasetpath=`echo ${dataset} | tr '/' '_'`
echo $datasetpath
mydasquery="dataset=${dataset} run=${runnb}"
if [ $isMC == 1 ]; then  mydasquery="dataset=${dataset}"
fi
echo $mydasquery
case "$mode" in "lxbatch" )
    # --- master mode ---
    # (this part is going on local machine)
   
    #queue="cmscaf1nd"   # LXBATCH jobs queue
    queue="1nh"
    batchdir="$(pwd)/log_and_results/${runnb}-${datasetpath}-batch"
    
    mkdir -p $batchdir
    mkdir -p $batchdir/logs
    mkdir -p $batchdir/results
    # prepare job submission directory
    UserNameInit="s"
    echo "Prepare the creation of directory"
#    /afs/cern.ch/project/eos/installation/0.3.84-aquamarine/bin/eos.select mkdir -p /eos/cms/store/caf/user/${myusername}/TPG/${runnb}_${datasetpath}
    #/afs/cern.ch/project/eos/installation/0.3.84-aquamarine/bin/eos.select mkdir -p /eos/cms/store/caf/user/${myusername}/TPG/${runnb}
    #/afs/cern.ch/project/eos/installation/0.3.15/bin/eos.select 
    echo "/eos/user/${UserNameInit}/${myusername}/TPG/${runnb}/temp"
    mkdir -p /eos/user/${UserNameInit}/${myusername}/TPG/${runnb}/temp
    echo "eos dir produced"
    retval=`voms-proxy-info &> /dev/null  ; echo $?`
    ppid=$PPID
    #echo "retval " $retval $ppid
    if [ $retval -ne 0 ]; then
	voms-proxy-init --voms cms 
    fi
    cp `find /tmp/x509up_u* -user ${myusername}` $batchdir/.
 
    echo "quering das: dasgoclient --query=\"file ${mydasquery}\" --limit=0"    
    for myfile in ` dasgoclient --query="file ${mydasquery}" --limit=0`
      do
	str=`expr match "${myfile}" '\(.......\)'`
	if [ "${str}" != "/store/" ] ; then continue
	fi
      s=$[$s+1]

      #cp -r configuration/configTPGtemplate_AAA.py $batchdir/runTPG_cfg_${s}.py
      cp ecalTPGAnalysisTEMPLATE_weekly.py $batchdir/runTPG_cfg_${s}.py
      cp -r configuration/batch_template_AAA.sh $batchdir/batch_job_${s}.sh
      #if [ ${isMC} == 1 ] ; then  cp -r configuration/configTPGtemplate_AAAonMC.py $batchdir/runTPG_cfg_${s}.py
      #fi
      cd $batchdir/
      echo $myfile
      sed -e "s,%globaltag%,$gtag,"        \
          -e "s,%numevents%,$eventsPerCastorFile,"        \
	  -e "s,%filename%,root://xrootd-cms.infn.it/${myfile},"      \
          -i runTPG_cfg_${s}.py

      sed -e "s,%cmsswdir%,$batchdir,"        \
          -e "s,%njob%,$s,"        \
	  -e "s,%runNb%,${runnb}," \
	  -e "s,%datasetPath%,${datasetpath}," \
	  -e "s,%username%,${myusername}," \
          -i batch_job_${s}.sh
      
      chmod a+x batch_job_${s}.sh

      bsub -q ${queue} batch_job_${s}.sh -o /dev/null -e /dev/null

      cd -
    done
       ;; 
    

esac
