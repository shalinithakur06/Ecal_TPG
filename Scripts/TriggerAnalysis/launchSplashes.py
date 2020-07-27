#!/bin/env python

from os import popen

#lumilist=['292901:90','292901:98', '292901:103']

#first round of splashes 2018
#Beam 1, Event 1: run 313133, evt 3125, LS 126
#Beam 1, Event 2: run 313133, evt 3298, LS 130
#Beam 1, Event 3: run 313133, evt 3493, LS 137
#Beam 1, Event 4: run 313134, evt 517, LS 20
#Beam 2, Event 1: run 313134, evt 768488, LS 120
#Beam 2, Event 2: run 313134, evt 1044543, LS 125

#second round of splashes
#Beam 1, Event 1: Run 313574, Event 3469, LS 143
#Beam 1, Event 2: Run 313574, Event 3779, LS 157
#
#Beam 2, Event 1: Run 313574, Event 4584, LS 189
#Beam 2, Event 2: Run 313574, Event 4937, LS 204
#Beam 2, Event 8: Run 313574, Event 5325, LS 218
###         beam1            beam2            beam2           beam1
#lumilist=['293591:208-293591:230','293591:244-293591:261','293591:283-293591:300','293591:309-293591:337', '293591:409-293591:430',
#   '293591:369-293591:395' 
#]


#lumilist=['313133:126-313134:20','313133:130-313134:120','313133:137-313134:125']
#lumilist=['313133:126', '313134:20','313133:130', '313134:120','313133:137','313134:125']
lumilist=['313574:143','313574:157','313574:189','313574:204','313574:218']
for lumi in lumilist:
    run = lumi[:lumi.find(':')]
    myls = lumi[lumi.rfind(':')+1:]
    #print run, myls
    sh="""#!/bin/bash
       export WDIR='/afs/cern.ch/user/s/sdutt/work/TPGAnalysis/New/CMSSW_10_0_4/src/EcalTPGAnalysis/Scripts/TriggerAnalysis'
       cd $WDIR
       eval `scramv1 runtime -sh`
       cd -
       cp  $WDIR/runTPG_splash17.py .
       cmsRun runTPG_splash17.py """+lumi+""" 
       cp ECALTPGtree.root /afs/cern.ch/user/s/sdutt/work/TPGAnalysis/New/CMSSW_10_0_4/src/EcalTPGAnalysis/Scripts/ECALTPGtree_LS"""+myls+"""_"""+run+""".root
    """
    sh_file = open("log_and_results/splash-"+lumi.replace(':', '_LS')+".sh","w")
    sh_file.write(sh)
    sh_file.close()
   
    popen("cd log_and_results/ ; chmod a+x splash-"+lumi.replace(':', '_LS')+".sh" )
    popen("cd log_and_results/ ; bsub -q 1nh splash-"+lumi.replace(':', '_LS')+".sh" )
     
