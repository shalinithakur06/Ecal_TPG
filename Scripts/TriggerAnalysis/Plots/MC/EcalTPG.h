//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Sep 28 19:13:04 2019 by ROOT version 6.12/07
// from TTree EcalTPGAnalysis/EcalTPGAnalysis
// found on file: SingleNeutrino_1-4000.root
//////////////////////////////////////////////////////////

#ifndef EcalTPG_h
#define EcalTPG_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class EcalTPG {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         puTrue;
   UInt_t          ngoodVtx;
   UInt_t          nVtx;
   UInt_t          runNb;
   ULong64_t       evtNb;
   Int_t           bxNb;
   Int_t           bxGT;
   ULong64_t       orbitNb;
   Int_t           lumiBlock;
   Double_t        timeStamp;
   UInt_t          nbOfActiveTriggers;
   Int_t           activeTriggers[160];   //[nbOfActiveTriggers]
   UInt_t          nbOfActiveTechTriggers;
   Int_t           activeTechTriggers[1];   //[nbOfActiveTechTriggers]
   Int_t           activeTriggersBX[160];
   Int_t           nbOfTowers;
   Int_t           ieta[1040];   //[nbOfTowers]
   Int_t           iphi[1040];   //[nbOfTowers]
   Int_t           nbOfXtals[1040];   //[nbOfTowers]
   Int_t           rawTPData[1040];   //[nbOfTowers]
   Int_t           rawTPEmul1[1040];   //[nbOfTowers]
   Int_t           rawTPEmul2[1040];   //[nbOfTowers]
   Int_t           rawTPEmul3[1040];   //[nbOfTowers]
   Int_t           rawTPEmul4[1040];   //[nbOfTowers]
   Int_t           rawTPEmul5[1040];   //[nbOfTowers]
   Int_t           crystNb[1040];   //[nbOfTowers]
   Float_t         eRec[1040];   //[nbOfTowers]
   Int_t           ttFlag[1040];   //[nbOfTowers]
   Int_t           sevlv[1040];   //[nbOfTowers]
   Int_t           spike[1040];   //[nbOfTowers]
   Int_t           rawTPEmulsFGVB1[1040];   //[nbOfTowers]
   Int_t           rawTPEmulsFGVB2[1040];   //[nbOfTowers]
   Int_t           rawTPEmulsFGVB3[1040];   //[nbOfTowers]
   Int_t           rawTPEmulsFGVB4[1040];   //[nbOfTowers]
   Int_t           rawTPEmulsFGVB5[1040];   //[nbOfTowers]
   Int_t           rawTPEmulttFlag1[1040];   //[nbOfTowers]
   Int_t           rawTPEmulttFlag2[1040];   //[nbOfTowers]
   Int_t           rawTPEmulttFlag3[1040];   //[nbOfTowers]
   Int_t           rawTPEmulttFlag4[1040];   //[nbOfTowers]
   Int_t           rawTPEmulttFlag5[1040];   //[nbOfTowers]
   Int_t           nTT_1ADC;
   Int_t           nTT_2ADC;
   Int_t           nTT_3ADC;
   Int_t           nTT_4ADC;
   Int_t           nTTemu_1ADC;
   Int_t           nTTemu_2ADC;
   Int_t           nTTemu_3ADC;
   Int_t           nTTemu_4ADC;
   UInt_t          nbOfL1IsoCands;
   Int_t           L1IsoIeta[1];   //[nbOfL1IsoCands]
   Int_t           L1IsoIphi[1];   //[nbOfL1IsoCands]
   Int_t           L1IsoRank[1];   //[nbOfL1IsoCands]
   UInt_t          nbOfL1NonisoCands;
   Int_t           L1NonisoIeta[10];   //[nbOfL1NonisoCands]
   Int_t           L1NonisoIphi[10];   //[nbOfL1NonisoCands]
   Int_t           L1NonisoRank[10];   //[nbOfL1NonisoCands]
   UInt_t          nMaskedRCT;
   Int_t           iMaskedRCTeta[1];   //[nMaskedRCT]
   Int_t           iMaskedRCTcrate[1];   //[nMaskedRCT]
   Int_t           iMaskedRCTphi[1];   //[nMaskedRCT]
   UInt_t          nbOfL1preIsoCands;
   Int_t           L1preIsoIeta[1];   //[nbOfL1preIsoCands]
   Int_t           L1preIsoIphi[1];   //[nbOfL1preIsoCands]
   Int_t           L1preIsoRank[1];   //[nbOfL1preIsoCands]
   UInt_t          nbOfL1preNonisoCands;
   Int_t           L1preNonisoIeta[1];   //[nbOfL1preNonisoCands]
   Int_t           L1preNonisoIphi[1];   //[nbOfL1preNonisoCands]
   Int_t           L1preNonisoRank[1];   //[nbOfL1preNonisoCands]
   UInt_t          nbOfL1postIsoCands;
   Int_t           L1postIsoIeta[1];   //[nbOfL1postIsoCands]
   Int_t           L1postIsoIphi[1];   //[nbOfL1postIsoCands]
   Int_t           L1postIsoRank[1];   //[nbOfL1postIsoCands]
   UInt_t          nbOfL1postNonisoCands;
   Int_t           L1postNonisoIeta[1];   //[nbOfL1postNonisoCands]
   Int_t           L1postNonisoIphi[1];   //[nbOfL1postNonisoCands]
   Int_t           L1postNonisoRank[1];   //[nbOfL1postNonisoCands]
   Int_t           trig_tower_adc[1040];   //[nbOfTowers]
   Int_t           trig_tower_sFGVB[1040];   //[nbOfTowers]

   // List of branches
   TBranch        *b_puTrue;   //!
   TBranch        *b_ngoodVtx;   //!
   TBranch        *b_nVtx;   //!
   TBranch        *b_runNb;   //!
   TBranch        *b_evtNb;   //!
   TBranch        *b_bxNb;   //!
   TBranch        *b_bxGT;   //!
   TBranch        *b_orbitNb;   //!
   TBranch        *b_lumiBlock;   //!
   TBranch        *b_timeStamp;   //!
   TBranch        *b_nbOfActiveTriggers;   //!
   TBranch        *b_activeTriggers;   //!
   TBranch        *b_nbOfActiveTechTriggers;   //!
   TBranch        *b_activeTechTriggers;   //!
   TBranch        *b_activeTriggersBX;   //!
   TBranch        *b_nbOfTowers;   //!
   TBranch        *b_ieta;   //!
   TBranch        *b_iphi;   //!
   TBranch        *b_nbOfXtals;   //!
   TBranch        *b_rawTPData;   //!
   TBranch        *b_rawTPEmul1;   //!
   TBranch        *b_rawTPEmul2;   //!
   TBranch        *b_rawTPEmul3;   //!
   TBranch        *b_rawTPEmul4;   //!
   TBranch        *b_rawTPEmul5;   //!
   TBranch        *b_crystNb;   //!
   TBranch        *b_eRec;   //!
   TBranch        *b_ttFlag;   //!
   TBranch        *b_sevlv;   //!
   TBranch        *b_spike;   //!
   TBranch        *b_rawTPEmulsFGVB1;   //!
   TBranch        *b_rawTPEmulsFGVB2;   //!
   TBranch        *b_rawTPEmulsFGVB3;   //!
   TBranch        *b_rawTPEmulsFGVB4;   //!
   TBranch        *b_rawTPEmulsFGVB5;   //!
   TBranch        *b_rawTPEmulttFlag1;   //!
   TBranch        *b_rawTPEmulttFlag2;   //!
   TBranch        *b_rawTPEmulttFlag3;   //!
   TBranch        *b_rawTPEmulttFlag4;   //!
   TBranch        *b_rawTPEmulttFlag5;   //!
   TBranch        *b_nTT_1ADC;   //!
   TBranch        *b_nTT_2ADC;   //!
   TBranch        *b_nTT_3ADC;   //!
   TBranch        *b_nTT_4ADC;   //!
   TBranch        *b_nTTemu_1ADC;   //!
   TBranch        *b_nTTemu_2ADC;   //!
   TBranch        *b_nTTemu_3ADC;   //!
   TBranch        *b_nTTemu_4ADC;   //!
   TBranch        *b_nbOfL1IsoCands;   //!
   TBranch        *b_L1IsoIeta;   //!
   TBranch        *b_L1IsoIphi;   //!
   TBranch        *b_L1IsoRank;   //!
   TBranch        *b_nbOfL1NonisoCands;   //!
   TBranch        *b_L1NonisoIeta;   //!
   TBranch        *b_L1NonisoIphi;   //!
   TBranch        *b_L1NonisoRank;   //!
   TBranch        *b_nMaskedRCT;   //!
   TBranch        *b_iMaskedRCTeta;   //!
   TBranch        *b_iMaskedRCTcrate;   //!
   TBranch        *b_iMaskedRCTphi;   //!
   TBranch        *b_nbOfL1preIsoCands;   //!
   TBranch        *b_L1preIsoIeta;   //!
   TBranch        *b_L1preIsoIphi;   //!
   TBranch        *b_L1preIsoRank;   //!
   TBranch        *b_nbOfL1preNonisoCands;   //!
   TBranch        *b_L1preNonisoIeta;   //!
   TBranch        *b_L1preNonisoIphi;   //!
   TBranch        *b_L1preNonisoRank;   //!
   TBranch        *b_nbOfL1postIsoCands;   //!
   TBranch        *b_L1postIsoIeta;   //!
   TBranch        *b_L1postIsoIphi;   //!
   TBranch        *b_L1postIsoRank;   //!
   TBranch        *b_nbOfL1postNonisoCands;   //!
   TBranch        *b_L1postNonisoIeta;   //!
   TBranch        *b_L1postNonisoIphi;   //!
   TBranch        *b_L1postNonisoRank;   //!
   TBranch        *b_trig_tower_adc;   //!
   TBranch        *b_trig_tower_sFGVB;   //!

   EcalTPG(TTree *tree=0);
   virtual ~EcalTPG();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef EcalTPG_cxx
EcalTPG::EcalTPG(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("SingleNeutrino_1-4000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("SingleNeutrino_1-4000.root");
      }
      f->GetObject("EcalTPGAnalysis",tree);

   }
   Init(tree);
}

EcalTPG::~EcalTPG()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t EcalTPG::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t EcalTPG::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void EcalTPG::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("puTrue", &puTrue, &b_puTrue);
   fChain->SetBranchAddress("ngoodVtx", &ngoodVtx, &b_ngoodVtx);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
   fChain->SetBranchAddress("runNb", &runNb, &b_runNb);
   fChain->SetBranchAddress("evtNb", &evtNb, &b_evtNb);
   fChain->SetBranchAddress("bxNb", &bxNb, &b_bxNb);
   fChain->SetBranchAddress("bxGT", &bxGT, &b_bxGT);
   fChain->SetBranchAddress("orbitNb", &orbitNb, &b_orbitNb);
   fChain->SetBranchAddress("lumiBlock", &lumiBlock, &b_lumiBlock);
   fChain->SetBranchAddress("timeStamp", &timeStamp, &b_timeStamp);
   fChain->SetBranchAddress("nbOfActiveTriggers", &nbOfActiveTriggers, &b_nbOfActiveTriggers);
   fChain->SetBranchAddress("activeTriggers", activeTriggers, &b_activeTriggers);
   fChain->SetBranchAddress("nbOfActiveTechTriggers", &nbOfActiveTechTriggers, &b_nbOfActiveTechTriggers);
   fChain->SetBranchAddress("activeTechTriggers", &activeTechTriggers, &b_activeTechTriggers);
   fChain->SetBranchAddress("activeTriggersBX", activeTriggersBX, &b_activeTriggersBX);
   fChain->SetBranchAddress("nbOfTowers", &nbOfTowers, &b_nbOfTowers);
   fChain->SetBranchAddress("ieta", ieta, &b_ieta);
   fChain->SetBranchAddress("iphi", iphi, &b_iphi);
   fChain->SetBranchAddress("nbOfXtals", nbOfXtals, &b_nbOfXtals);
   fChain->SetBranchAddress("rawTPData", rawTPData, &b_rawTPData);
   fChain->SetBranchAddress("rawTPEmul1", rawTPEmul1, &b_rawTPEmul1);
   fChain->SetBranchAddress("rawTPEmul2", rawTPEmul2, &b_rawTPEmul2);
   fChain->SetBranchAddress("rawTPEmul3", rawTPEmul3, &b_rawTPEmul3);
   fChain->SetBranchAddress("rawTPEmul4", rawTPEmul4, &b_rawTPEmul4);
   fChain->SetBranchAddress("rawTPEmul5", rawTPEmul5, &b_rawTPEmul5);
   fChain->SetBranchAddress("crystNb", crystNb, &b_crystNb);
   fChain->SetBranchAddress("eRec", eRec, &b_eRec);
   fChain->SetBranchAddress("ttFlag", ttFlag, &b_ttFlag);
   fChain->SetBranchAddress("sevlv", sevlv, &b_sevlv);
   fChain->SetBranchAddress("spike", spike, &b_spike);
   fChain->SetBranchAddress("rawTPEmulsFGVB1", rawTPEmulsFGVB1, &b_rawTPEmulsFGVB1);
   fChain->SetBranchAddress("rawTPEmulsFGVB2", rawTPEmulsFGVB2, &b_rawTPEmulsFGVB2);
   fChain->SetBranchAddress("rawTPEmulsFGVB3", rawTPEmulsFGVB3, &b_rawTPEmulsFGVB3);
   fChain->SetBranchAddress("rawTPEmulsFGVB4", rawTPEmulsFGVB4, &b_rawTPEmulsFGVB4);
   fChain->SetBranchAddress("rawTPEmulsFGVB5", rawTPEmulsFGVB5, &b_rawTPEmulsFGVB5);
   fChain->SetBranchAddress("rawTPEmulttFlag1", rawTPEmulttFlag1, &b_rawTPEmulttFlag1);
   fChain->SetBranchAddress("rawTPEmulttFlag2", rawTPEmulttFlag2, &b_rawTPEmulttFlag2);
   fChain->SetBranchAddress("rawTPEmulttFlag3", rawTPEmulttFlag3, &b_rawTPEmulttFlag3);
   fChain->SetBranchAddress("rawTPEmulttFlag4", rawTPEmulttFlag4, &b_rawTPEmulttFlag4);
   fChain->SetBranchAddress("rawTPEmulttFlag5", rawTPEmulttFlag5, &b_rawTPEmulttFlag5);
   fChain->SetBranchAddress("nTT_1ADC", &nTT_1ADC, &b_nTT_1ADC);
   fChain->SetBranchAddress("nTT_2ADC", &nTT_2ADC, &b_nTT_2ADC);
   fChain->SetBranchAddress("nTT_3ADC", &nTT_3ADC, &b_nTT_3ADC);
   fChain->SetBranchAddress("nTT_4ADC", &nTT_4ADC, &b_nTT_4ADC);
   fChain->SetBranchAddress("nTTemu_1ADC", &nTTemu_1ADC, &b_nTTemu_1ADC);
   fChain->SetBranchAddress("nTTemu_2ADC", &nTTemu_2ADC, &b_nTTemu_2ADC);
   fChain->SetBranchAddress("nTTemu_3ADC", &nTTemu_3ADC, &b_nTTemu_3ADC);
   fChain->SetBranchAddress("nTTemu_4ADC", &nTTemu_4ADC, &b_nTTemu_4ADC);
   fChain->SetBranchAddress("nbOfL1IsoCands", &nbOfL1IsoCands, &b_nbOfL1IsoCands);
   fChain->SetBranchAddress("L1IsoIeta", &L1IsoIeta, &b_L1IsoIeta);
   fChain->SetBranchAddress("L1IsoIphi", &L1IsoIphi, &b_L1IsoIphi);
   fChain->SetBranchAddress("L1IsoRank", &L1IsoRank, &b_L1IsoRank);
   fChain->SetBranchAddress("nbOfL1NonisoCands", &nbOfL1NonisoCands, &b_nbOfL1NonisoCands);
   fChain->SetBranchAddress("L1NonisoIeta", L1NonisoIeta, &b_L1NonisoIeta);
   fChain->SetBranchAddress("L1NonisoIphi", L1NonisoIphi, &b_L1NonisoIphi);
   fChain->SetBranchAddress("L1NonisoRank", L1NonisoRank, &b_L1NonisoRank);
   fChain->SetBranchAddress("nMaskedRCT", &nMaskedRCT, &b_nMaskedRCT);
   fChain->SetBranchAddress("iMaskedRCTeta", &iMaskedRCTeta, &b_iMaskedRCTeta);
   fChain->SetBranchAddress("iMaskedRCTcrate", &iMaskedRCTcrate, &b_iMaskedRCTcrate);
   fChain->SetBranchAddress("iMaskedRCTphi", &iMaskedRCTphi, &b_iMaskedRCTphi);
   fChain->SetBranchAddress("nbOfL1preIsoCands", &nbOfL1preIsoCands, &b_nbOfL1preIsoCands);
   fChain->SetBranchAddress("L1preIsoIeta", &L1preIsoIeta, &b_L1preIsoIeta);
   fChain->SetBranchAddress("L1preIsoIphi", &L1preIsoIphi, &b_L1preIsoIphi);
   fChain->SetBranchAddress("L1preIsoRank", &L1preIsoRank, &b_L1preIsoRank);
   fChain->SetBranchAddress("nbOfL1preNonisoCands", &nbOfL1preNonisoCands, &b_nbOfL1preNonisoCands);
   fChain->SetBranchAddress("L1preNonisoIeta", &L1preNonisoIeta, &b_L1preNonisoIeta);
   fChain->SetBranchAddress("L1preNonisoIphi", &L1preNonisoIphi, &b_L1preNonisoIphi);
   fChain->SetBranchAddress("L1preNonisoRank", &L1preNonisoRank, &b_L1preNonisoRank);
   fChain->SetBranchAddress("nbOfL1postIsoCands", &nbOfL1postIsoCands, &b_nbOfL1postIsoCands);
   fChain->SetBranchAddress("L1postIsoIeta", &L1postIsoIeta, &b_L1postIsoIeta);
   fChain->SetBranchAddress("L1postIsoIphi", &L1postIsoIphi, &b_L1postIsoIphi);
   fChain->SetBranchAddress("L1postIsoRank", &L1postIsoRank, &b_L1postIsoRank);
   fChain->SetBranchAddress("nbOfL1postNonisoCands", &nbOfL1postNonisoCands, &b_nbOfL1postNonisoCands);
   fChain->SetBranchAddress("L1postNonisoIeta", &L1postNonisoIeta, &b_L1postNonisoIeta);
   fChain->SetBranchAddress("L1postNonisoIphi", &L1postNonisoIphi, &b_L1postNonisoIphi);
   fChain->SetBranchAddress("L1postNonisoRank", &L1postNonisoRank, &b_L1postNonisoRank);
   fChain->SetBranchAddress("trig_tower_adc", trig_tower_adc, &b_trig_tower_adc);
   fChain->SetBranchAddress("trig_tower_sFGVB", trig_tower_sFGVB, &b_trig_tower_sFGVB);
   Notify();
}

Bool_t EcalTPG::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void EcalTPG::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t EcalTPG::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef EcalTPG_cxx
