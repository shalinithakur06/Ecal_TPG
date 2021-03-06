from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'DataTP_ZeroBias_Run2018D_v1_RAW_Run324293_3OCT19'
config.General.workArea = 'DataTP_ZeroBias_Run2018D-v1_RAW_Run324293'
config.General.transferOutputs = True
config.General.transferLogs = False

#config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ecalTPGAnalysis_DATA_2019.py' 
config.JobType.allowUndistributedCMSSW=True

config.JobType.maxMemoryMB = 4000
config.JobType.outputFiles = ['ECALTPGtree.root']
config.Data.inputDataset = '/ZeroBias/Run2018D_v1/RAW'
config.Data.inputDBS = 'global'
config.Data.runRange = '324293'
#===== RUNNING OVER ALL RUNS ==========
####config.Data.splitting = 'LumiBased'
####config.Data.splitting = 'Automatic'
#config.Data.splitting = 'EventBased'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
#=====================================
#config.Data.splitting = 'EventBased'
#config.Data.unitsPerJob = 10 
#NJOBS = 1
config.Data.publication = False

config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
#config.Data.ignoreLocality = True                                                                                                                                                                       
config.section_("Site")
#config.Site.blacklist = ['T1_US_FNAL,T2_US_MIT,T2_US_Vanderbilt,T2_US_Nebraska,T2_US_Florida,T2_US_Wisconsin,T2_US_Purdue,T2_US_UCSD,T2_US_Caltech']
config.Site.storageSite = 'T2_IN_TIFR'

#duplicateCheckMode = cms.untracked.string("noDuplicateCheck")
#config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
