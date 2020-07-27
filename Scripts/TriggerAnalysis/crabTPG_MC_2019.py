from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.workArea = '2019_TPG_crab_projects_MC'
config.General.requestName = 'SingleNeutrinoGun_GEN-SIM-DIGI-RAW_19Aug19'
config.General.transferOutputs = True
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ecalTPGAnalysis_MC_2019.py' 
config.JobType.allowUndistributedCMSSW = True

config.JobType.maxMemoryMB = 2000
#config.JobType.maxJobRuntimeMin = 600
config.JobType.outputFiles = ['ECALTPGtree.root']
config.Data.userInputFiles = open('SingleNeutrino.txt').readlines()
###config.Data.inputDataset = '/SingleNeutrinoGun/RunIIAutumn18DR-102X_upgrade2018_realistic_v15_ext1-v2/GEN-SIM-DIGI-RAW'
config.Data.inputDBS = 'global'
#config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'

#config.JobType.allowUndistributedCMSSW = True
#config.Data.runRange = '324293'
#===== RUNNING OVER ALL RUNS ==========
##config.Data.splitting = 'LumiBased'
##config.Data.splitting = 'Automatic'
##config.Data.splitting = 'EventBased'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1 
#config.Data.useParent = True
#=====================================
###config.Data.splitting = 'EventAwareLumiBased'
###config.Data.unitsPerJob = 10 
NJOBS = 10
config.Data.publication = False

config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.ignoreLocality = True                 
                                                                                                                                                      
config.section_("Site")
config.Site.blacklist = ['T1_FR_CCIN2P3']
config.Site.whitelist = ['T2_EE_Estonia']
#config.Site.blacklist = ['T1_US_FNAL,T2_US_MIT,T2_US_Vanderbilt,T2_US_Nebraska,T2_US_Florida,T2_US_Wisconsin,T2_US_Purdue,T2_US_UCSD,T2_US_Caltech']
config.Site.storageSite = 'T2_IN_TIFR'

