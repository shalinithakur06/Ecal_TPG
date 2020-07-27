from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.workArea = '2019_TPG_crab_projects_MC_RelValNuGun'
config.General.requestName = 'RelValNuGun_GEN-SIM-DIGI-RAW'
config.General.transferOutputs = True
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ecalTPGAnalysis_MC_2019_RelValNuGun.py' 
config.JobType.allowUndistributedCMSSW = True

config.JobType.maxMemoryMB = 2500
#config.JobType.maxJobRuntimeMin = 600
config.JobType.outputFiles = ['ECALTPGtree.root']
#config.JobType.scriptExe = 'myscript.sh' #this is for testing
config.Data.inputDataset = '/RelValNuGun/CMSSW_10_3_0-PU25ns_103X_upgrade2018_realistic_v7_resub-v1/GEN-SIM-DIGI-RAW'
config.Data.inputDBS = 'global'
#config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'

#config.JobType.allowUndistributedCMSSW = True
#config.Data.runRange = '324293'
#===== RUNNING OVER ALL RUNS ==========
#config.Data.splitting = 'LumiBased'
config.Data.splitting = 'Automatic'
#config.Data.splitting = 'EventBased'
#config.Data.splitting = 'EventAwareLumiBased'
#config.Data.splitting = 'FileBased'
#config.Data.unitsPerJob = 1 
#config.Data.useParent = True
#=====================================
#config.Data.splitting = 'EventBased'
#config.Data.unitsPerJob = 10 
#NJOBS = 1
config.Data.publication = False


config.Data.outLFNDirBase = '/store/user/pbarria/TPG/2019_DataMC_Comparison/RelValNuGun_GEN-SIM-DIGI-RAW_slc7'
#config.Data.ignoreLocality = True                 
                                                                                                                                                      
config.section_("Site")
#config.Site.blacklist = ['T1_US_FNAL,T2_US_MIT,T2_US_Vanderbilt,T2_US_Nebraska,T2_US_Florida,T2_US_Wisconsin,T2_US_Purdue,T2_US_UCSD,T2_US_Caltech']
config.Site.storageSite = 'T2_CH_CERN'

#config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
