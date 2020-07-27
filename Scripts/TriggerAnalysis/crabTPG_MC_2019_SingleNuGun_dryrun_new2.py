from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.workArea = '2019_TPG_crab_projects_MC_SingleNuGun_files1001-2001_bugfixed'
config.General.requestName = 'SingleNeutrinoGun_GEN-SIM-DIGI-RAW_1001-2001_bugfixed'
config.General.transferOutputs = True
config.General.transferLogs = True # False before

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ecalTPGAnalysis_MC_2019_dryrun.py' 
config.JobType.allowUndistributedCMSSW = True

config.JobType.outputFiles = ['ECALTPGtree.root']
#config.JobType.scriptExe = 'myscript.sh' #this is for testing

#config.Data.userInputFiles = open('file_SingleNeutrino_1001-2001.txt').readlines()
config.Data.inputDataset = '/SingleNeutrinoGun/RunIIAutumn18DR-102X_upgrade2018_realistic_v15_ext1-v2/GEN-SIM-DIGI-RAW'
config.Data.inputDBS = 'global'


#===== RUNNING OVER ALL RUNS ==========
#config.Data.runRange = '324293'
config.JobType.maxMemoryMB = 2500
#config.JobType.maxJobRuntimeMin = 160 #minutes for running job (1315 is max value)

#--------AUTOMATIC--------------------
#config.Data.splitting = 'Automatic'
#config.Data.unitsPerJob = 600 #number of file per job (Filebased) or number of jobs (EventAware)
#config.Data.totalUnits = 1000 #number of events (EventAware) or total files (FileBased)
#config.Data.useParent = True
#--------EVENTBASED-------------------
#config.Data.splitting = 'EventBased'
#config.Data.unitsPerJob = 600 #number of file per job (Filebased) or number of jobs (EventAware)
#config.Data.totalUnits = 1000 #number of events (EventAware) or total files (FileBased)
#NJOBS = 1
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
#config.Data.useParent = True
#--------LUMIBASED--------------------
#config.Data.splitting = 'LumiBased'
#config.Data.unitsPerJob = 600 #number of file per job (Filebased) or number of jobs (EventAware)
#config.Data.totalUnits = 1000 #number of events (EventAware) or total files (FileBased)
#NJOBS = 1
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
#config.Data.useParent = True
#--------EVENTAWARELUMIBASED----------
#config.Data.splitting = 'EventAwareLumiBased'
#config.Data.unitsPerJob = 600 #number of file per job (Filebased) or number of jobs (EventAware)
#config.Data.totalUnits = 1000 #number of events (EventAware) or total files (FileBased)
#NJOBS = 1
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
#config.Data.useParent = True
#--------FILEBASED--------------------
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 3 #number of file per job (Filebased) 
config.Data.totalUnits = 90 #number of total files (FileBased)
#NJOBS = 1
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
#config.Data.useParent = True
#=====================================
#config.Data.splitting = 'EventBased'
#config.Data.unitsPerJob = 10 
#NJOBS = 1
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS

config.Data.publication = False


config.Data.outLFNDirBase = '/store/user/pbarria/TPG/2019_DataMC_Comparison/SingleNeutrinoGun_GEN-SIM-DIGI-RAW_slc7_files_1001-2001'
#config.Data.ignoreLocality = True                 
                                                                                                                                                      
config.section_("Site")
#config.Site.blacklist = ['T1_FR_CCIN2P3']
#config.Site.whitelist = ['T2_EE_Estonia']
config.Site.storageSite = 'T2_CH_CERN'

#config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
