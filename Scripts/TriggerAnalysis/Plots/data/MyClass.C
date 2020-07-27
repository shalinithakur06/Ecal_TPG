#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void MyClass::Loop()
{
   if (fChain == 0) return;
   TFile *f = new TFile("finalplot_data.root", "RECREATE");
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   //Loop over number of events (nentries) 
   TH1F *hnVtx = new TH1F("nVtx", "nVtx distribution", 50, 0, 100);
   TH1F *hieta = new TH1F("hieta", "#eta distribution", 15, -30, 30);
   TH1F *hiphi = new TH1F("hiphi", "#phi distribution", 35, 0, 70);
   TH1F *hnTT_1ADC = new TH1F("hnTT_1ADC", "nTT_1ADC distribution", 150, 0, 300);
   TH1F *hnTT_2ADC = new TH1F("hnTT_2ADC", "nTT_2ADC distribution", 150, 0, 300);
   TH1F *hnTT_3ADC = new TH1F("hnTT_3ADC", "nTT_3ADC distribution", 150, 0, 300);
   TH1F *hnTT_4ADC = new TH1F("hnTT_4ADC", "nTT_4ADC distribution", 150, 0, 300);
   TH1F *hnTTemu_1ADC = new TH1F("hnTTemu_1ADC", "nTTemu_1ADC distribution", 150, 0, 300);
   TH1F *hnTTemu_2ADC = new TH1F("hnTTemu_2ADC", "nTTemu_2ADC distribution", 150, 0, 300);
   TH1F *hnTTemu_3ADC = new TH1F("hnTTemu_3ADC", "nTTemu_3ADC distribution", 150, 0, 300);
   TH1F *hnTTemu_4ADC = new TH1F("hnTTemu_4ADC", "nTTemu_4ADC distribution", 150, 0, 300);
   TH2F *hetavsphi = new TH2F("hetavsphi", "ieta vs iphi", 15, -30, 30, 35, 0, 70);
   TH2F *hetavsnTT_1ADC = new TH2F("hetavsnTT_1ADC", "ieta vs nTT_1ADC", 15, -30, 30, 150, 0, 300);
    
   TH2F *hnVtxvsnTT_1ADC = new TH2F("hnVtxvsnTT_1ADC", "nVtx vs nTT_1ADC", 100, 0, 100, 200, -100, 100);
   TH2F *hnVtxvsnTT_2ADC = new TH2F("hnVtxvsnTT_2ADC", "nVtx vs nTT_2ADC", 100, 0, 100, 200, -100, 100);
   TH2F *hnVtxnsnTT_3ADC = new TH2F("hnVtxnsnTT_3ADC", "nVtx vs nTT_3ADC", 100, 0, 100, 200, -100, 100);
   TH2F *hnVtxvsnTT_4ADC = new TH2F("hnVtxvsnTT_4ADC", "nVtx vs nTT_4ADC", 100, 0, 100, 200, -100, 100);
 
   TH2F *hnVtxvsnTTemu_1ADC = new TH2F("hnVtxvsnTTemu_1ADC", "nVtx vs nTTemu_1ADC", 100, 0, 100, 200, -100, 100);
   TH2F *hnVtxvsnTTemu_2ADC = new TH2F("hnVtxvsnTTemu_2ADC", "nVtx vs nTTemu_2ADC", 100, 0, 100, 200, -100, 100);
   TH2F *hnVtxvsnTTemu_3ADC= new TH2F("hnVtxvsnTTemu_3ADC", "nVtx vs nTTemu_3ADC", 100, 0, 100, 200, -100, 100);
   TH2F *hnVtxvsnTTemu_4ADC = new TH2F("hnVtxvsnTTemu_4ADC", "nVtx vs nTTemu_4ADC", 100, 0, 100, 200, -100, 100);

   //for (Long64_t jentry=0; jentry<nentries;jentry++) {
      //Long64_t ientry = LoadTree(jentry);
      //if (ientry < 0) break;
      //nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   for (Long64_t nentry=0; nentry<nentries; nentry++) {
     if(nentry%100==0)cout<<"Event number = "<< nentry<<endl;
     fChain->GetEntry(nentry);
     hnVtx->Fill(nVtx);
     hnTT_1ADC->Fill(nTT_1ADC);
     hnTT_2ADC->Fill(nTT_2ADC);
     hnTT_3ADC->Fill(nTT_3ADC);
     hnTT_4ADC->Fill(nTT_4ADC);
     hnTTemu_1ADC->Fill(nTTemu_1ADC);
     hnTTemu_2ADC->Fill(nTTemu_2ADC);
     hnTTemu_3ADC->Fill(nTTemu_3ADC);
     hnTTemu_4ADC->Fill(nTTemu_4ADC);
 
     hnVtxvsnTT_1ADC->Fill(nVtx, nTT_1ADC);
     hnVtxvsnTT_2ADC->Fill(nVtx, nTT_2ADC);
     hnVtxnsnTT_3ADC->Fill(nVtx, nTT_3ADC);
     hnVtxvsnTT_4ADC->Fill(nVtx, nTT_4ADC);
 
     hnVtxvsnTTemu_1ADC->Fill(nVtx, nTTemu_1ADC);
     hnVtxvsnTTemu_2ADC->Fill(nVtx, nTTemu_2ADC);
     hnVtxvsnTTemu_3ADC->Fill(nVtx, nTTemu_3ADC);
     hnVtxvsnTTemu_4ADC->Fill(nVtx, nTTemu_4ADC);
 
     for(int i=0; i<(sizeof(ieta)/sizeof(*ieta)); i++){
       hetavsphi->Fill(ieta[i],iphi[i]);
       hetavsnTT_1ADC->Fill(ieta[i],nTT_1ADC);
       hieta->Fill(ieta[i]);
       hiphi->Fill(iphi[i]);
       //cout << "ieta =" << ieta[i] << endl;   
       //cout << "iphi =" << iphi[i] << endl;   
   }
}
f->Write();
f->Close();
}
