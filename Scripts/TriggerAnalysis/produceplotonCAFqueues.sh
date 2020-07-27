#!/bin/bash

cd /afs/cern.ch/user/t/taroni/scratch0/stage2integration/CMSSW_8_0_3_patch1/src/EcalTPGAnalysis/Scripts/TriggerAnalysis/

eval `scramv1 runtime -sh`

./makeTrigPrimPlots.sh -r 262897 -a _269244_IOV

exit
