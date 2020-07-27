import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras
#caz process = cms.Process("TPGANALYSIS",eras.Run2_2016)
process = cms.Process("TPGANALYSIS",eras.Run2_2018)
#process = cms.Process("TPGANALYSIS",eras.Run2_2017)

process.load("SimCalorimetry.EcalTrigPrimProducers.ecalTriggerPrimitiveDigis_readDBOffline_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

#for Data
##for run 306456
process.GlobalTag.globaltag = '103X_dataRun2_Prompt_v3'
##for run 324293
####process.GlobalTag.globaltag = '102X_dataRun2_Prompt_v4'

#for MC
#process.GlobalTag.globaltag =  '103X_upgrade2018_realistic_v7'
#process.GlobalTag.globaltag =  '102X_mcRun2_asymptotic_v3'
#caz process.load('Configuration.Geometry.GeometryExtended2016Reco_cff') 
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')

process.GlobalTag.toGet = cms.VPSet(
    cms.PSet(record = cms.string("EcalTPGLinearizationConstRcd"),
             # tag = cms.string("EcalTPGLinearizationConst_IOV_285555_beginning_at_1"),
#             tag = cms.string("%EcalTPGLinearizationConst%"),
#	     connect =cms.string('%sqlite%')
             #connect =cms.string('frontier://FrontierPrep/CMS_CONDITIONS')
             ),
    cms.PSet(record = cms.string("EcalTPGPedestalsRcd"), 
             #tag = cms.string("EcalTPGPedestals_282736_beginning_at_1"), 
#             tag = cms.string("%EcalTPGPedestals%"), 
	     #connect =cms.string('sqlite:////afs/cern.ch/work/e/ecaltrg/TPLasVal_8026/src/CondTools/Ecal/test/EcalTPG_282736_moved_to_1.db')
#	     connect =cms.string('%sqlite%')
             #connect =cms.string('frontier://FrontierPrep/CMS_CONDITIONS')
             )
    )
    


#process.load('Configuration.Geometry.GeometryExtended2016Reco_cff')

# ECAL Unpacker
process.load("EventFilter.EcalRawToDigi.EcalUnpackerMapping_cfi")
process.load("EventFilter.EcalRawToDigi.EcalUnpackerData_cfi")

# ECAL TPG Producer
#caz process.load("Geometry.EcalMapping.EcalMapping_cfi")
#caz process.load("Geometry.EcalMapping.EcalMappingRecord_cfi")
#caz process.load("Geometry.CaloEventSetup.CaloGeometry_cfi")
#caz process.load("Geometry.CaloEventSetup.EcalTrigTowerConstituents_cfi")

process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')

process.load('L1Trigger.Configuration.L1TReco_cff')

process.load('Configuration.EventContent.EventContent_cff')


process.raw2digi_step = cms.Path(process.RawToDigi)
process.endjob_step = cms.EndPath(process.endOfProcess)

# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step)

from L1Trigger.Configuration.customiseReEmul import L1TReEmulFromRAW
#,L1TEventSetupForHF1x1TPs  this last one is not in the release

#call to customisation function L1TReEmulFromRAW imported from L1Trigger.Configuration.customiseReEmul
#process = L1TReEmulFromRAW(process)
from EventFilter.L1TRawToDigi.caloStage2Digis_cfi import caloStage2Digis
process.rawCaloStage2Digis = caloStage2Digis.clone()
process.rawCaloStage2Digis.InputLabel = cms.InputTag('rawDataCollector')

#####process.ecalEBunpacker.InputLabel = cms.InputTag("rawDataCollector") 


process.ecalTriggerPrimitiveDigis = cms.EDProducer("EcalTrigPrimProducer",
   InstanceEB = cms.string('ebDigis'),
   InstanceEE = cms.string('eeDigis'),
   Label = cms.string('ecalDigis'),
   BarrelOnly = cms.bool(False),
   Famos = cms.bool(False),
   TcpOutput = cms.bool(False),
   Debug = cms.bool(False),
   binOfMaximum = cms.int32(6), ## optional from release 200 on, from 1-10

)

#test HLT
process.load('HLTrigger.HLTfilters.hltHighLevel_cfi')
process.hltHighLevel.HLTPaths = cms.vstring("HLT_ZeroBias_v*") #ZeroBias
#process.hltHighLevel.HLTPaths = cms.vstring("HLT_DoubleEle*") #EGamma

# ECAL rechits and co
process.load("Configuration/StandardSequences/Reconstruction_cff")
import RecoLocalCalo.EcalRecProducers.ecalGlobalUncalibRecHit_cfi
process.ecalUncalibHit = RecoLocalCalo.EcalRecProducers.ecalGlobalUncalibRecHit_cfi.ecalGlobalUncalibRecHit.clone()
process.load("RecoLocalCalo.EcalRecProducers.ecalRecHit_cfi")
process.load("Geometry.CaloEventSetup.CaloTopology_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalDetIdToBeRecovered_cfi")
process.ecalRecHit.EBuncalibRecHitCollection = 'ecalUncalibHit:EcalUncalibRecHitsEB'
process.ecalRecHit.EEuncalibRecHitCollection = 'ecalUncalibHit:EcalUncalibRecHitsEE'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1) #-1 for all events
)

#process.options = cms.untracked.PSet(
#SkipEvent = cms.untracked.vstring('ProductNotFound')
#)

#process.source.duplicateCheckMode = cms.untracked.string('noDuplicateCheck') 

process.source = cms.Source("PoolSource",
duplicateCheckMode = cms.untracked.string('noDuplicateCheck'),

fileNames = (cms.untracked.vstring(
#####'/store/data/Run2018D/ZeroBias/RAW/v1/000/324/293/00000/E31A9E89-00D9-7A4C-9088-58C090F383C2.root',
#####'root://cms-xrd-global.cern.ch//store/data/Run2018D/ZeroBias/RAW/v1/000/324/293/00000/FD46D557-0639-1C4A-96AF-DBCC34866D4B.root',
######'root://xrootd-cms.infn.it//store/data/Run2018D/ZeroBias/RAW/v1/000/324/293/00000/FD46D557-0639-1C4A-96AF-DBCC34866D4B.root',
######'root://cms-xrd-global.cern.ch:1094//store/data/Run2018D/ZeroBias/RAW/v1/000/324/293/00000/FF77A6D4-B024-2149-942A-2F21AC34683E.root',
##for run 306456
####'/store/data/Run2017F/ZeroBias/RAW/v1/000/306/456/00000/0EA47DF7-6FC5-E711-B10B-02163E01A3E3.root',
'/store/data/Run2017F/ZeroBias/RAW/v1/000/306/456/00000/FEE7ED43-66C5-E711-B2CE-02163E01A243.root',
####'/store/data/Run2017F/ZeroBias/AOD/09Aug2019_UL2017-v1/260001/F9D4C1A6-8D47-574B-BB0C-396B896D554C.root',
####' /store/data/Run2017F/ZeroBias/MINIAOD/17Nov2017-v1/610000/EC34BAEF-1FE5-E711-81E6-002590DE38C8.root',
#'/store/data/Run2017F/ZeroBias/AOD/17Nov2017-v1/610000/68C86A35-0BE5-E711-BEFC-3417EBE6FFFD.root',
### run 320065
####'/store/data/Run2018C/ZeroBias/RAW/v1/000/320/040/00000/B68D3A69-D78D-E811-940C-FA163E7172EE.root',
###run 305040
####'/store/data/Run2017F/ZeroBias/RAW/v1/000/306/462/00000/98634CE2-20C6-E711-A2BE-02163E0134C4.root',
#####'/store/data/Run2017F/ZeroBias/RAW/v1/000/306/459/00000/F6D60CC0-DEC5-E711-A170-02163E01A455.root',
#'/store/relval/CMSSW_10_3_0/RelValZEE_13/GEN-SIM-DIGI-RECO/PUpmx25ns_103X_mc2017_realistic_v1_FastSim-v1/10000/FEC46A98-54EF-8347-931C-76B10B71CBD2.root',
#'/store/relval/CMSSW_10_3_0/RelValNuGun/GEN-SIM-DIGI-RAW/PU25ns_103X_upgrade2018_realistic_v7-v1/10000/F14CFEBB-F16B-964A-9787-9E474784B8FA.root',
#'/store/relval/CMSSW_10_2_1/RelValZEE_13/GEN-SIM-RECO/PU25ns_102X_upgrade2018_realistic_v9_gcc7-v1/10000/C6D16605-7D94-E811-95F9-0CC47A4D769E.root',
#'/store/relval/CMSSW_10_3_0_pre4/RelValZEE_13/GEN-SIM-RECO/PU25ns_103X_upgrade2018_realistic_v4-v1/20000/0262AE0B-673E-7C41-B2C2-034B63256541.root',
#'/store/relval/CMSSW_10_3_0/RelValZEE_13/GEN-SIM-DIGI-RECO/PUpmx25ns_103X_mc2017_realistic_v1_FastSim-v1/10000/*.root',
))
#,

#----SECONDARY FILES---------------------
#secondaryFileNames = (cms.untracked.vstring(
#'/store/relval/CMSSW_10_2_1/RelValZEE_13/GEN-SIM-DIGI-RAW/PU25ns_102X_upgrade2018_realistic_v9_gcc7-v1/10000/94D4E1B7-6094-E811-82D4-0CC47A4C8E16.root',
#))
#----------------------------------------
#duplicateCheckMode = cms.untracked.string("noDuplicateCheck")
)

process.tpAnalyzer = cms.EDAnalyzer("EcalTPGAnalyzer",
   isMC  = cms.bool(False),
   isRECO  = cms.bool(False),
   PVCollection = cms.InputTag("offlinePrimaryVertices"),
   pileupCollection = cms.InputTag("addPileupInfo"),
#   PVCollection = cms.InputTag("offlineSlimmedPrimaryVertices"),
   TPCollection = cms.InputTag("ecalDigis","EcalTriggerPrimitives"),
   TPEmulatorCollection =  cms.InputTag("ecalTriggerPrimitiveDigis",""),
   DigiCollectionEB = cms.InputTag("ecalDigis","ebDigis"),
   DigiCollectionEE = cms.InputTag("ecalDigis","eeDigis"),
   GTRecordCollection = cms.string('gtDigis'),
   EcalRecHitCollectionEB = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
   EcalRecHitCollectionEE = cms.InputTag("ecalRecHit","EcalRecHitsEE"),
   uncalibratedRecHitCollectionEB = cms.InputTag("ecalMaxSampleUncalibRecHit","EcalUncalibRecHitsEB"),
   uncalibratedRecHitCollectionEE = cms.InputTag("ecalMaxSampleUncalibRecHit","EcalUncalibRecHitsEE"),
   l1extraIsol=cms.InputTag("l1extraParticles","Isolated"), 
   l1extraNonIsol= cms.InputTag("l1extraParticles","NonIsolated"), 
   Print = cms.bool(False),
   L1Print = cms.bool(False),
   ReadTriggerPrimitives = cms.bool(True),
   UseEndCap = cms.bool(True),
   keepOnlyTowersAboveZero = cms.bool(True),
   skipWritingEndcapDigi = cms.bool(True)
)

process.load("RecoLocalCalo.EcalRecProducers.ecalRecHit_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalGlobalUncalibRecHit_cfi")
process.load("Geometry.CaloEventSetup.CaloTopology_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalDetIdToBeRecovered_cfi")
process.ecalRecHit.EBuncalibRecHitCollection = 'ecalUncalibHit:EcalUncalibRecHitsEB'
process.ecalRecHit.EEuncalibRecHitCollection = 'ecalUncalibHit:EcalUncalibRecHitsEE'

process.p = cms.Path(
   #process.rawCaloStage2Digis*
   process.L1Reco*  #commented for GEN-SIM-DIGI-RECO
   #process.reconstruction_step = cms.Path(process.reconstruction)
   process.ecalTriggerPrimitiveDigis*
   process.ecalUncalibHit*
   process.ecalDetIdToBeRecovered*
   process.ecalRecHit*
   process.reconstruction*   #commented for GEN-SIM-DIGI-RECO
   process.tpAnalyzer
)


process.schedule.append(process.p)

#process.MessageLogger = cms.Service("MessageLogger"
#   ,cout = cms.untracked.PSet(threshold = cms.untracked.string('ERROR')),
#   destinations = cms.untracked.vstring('cout')

#)
