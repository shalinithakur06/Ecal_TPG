void FixLimits(){
  
  //TFile *_file0 = TFile::Open("root://eoscms.cern.ch//eos/cms/store/caf/user/taroni/TPG/ECALTPGtree_306456.root");
/*  TFile *_file0 = TFile::Open("/afs/cern.ch/work/s/sthakur/Ecal_TPG/New_area/CMSSW_10_3_1/src/EcalTPGAnalysis/Scripts/TriggerAnalysis//ECALTPGtree_306456.root");
  TTree * EcalTPGAnalysis= (TTree * ) _file0->Get("EcalTPGAnalysis");
  TH1F * h1, * h2, * h3; 
  int nevent = EcalTPGAnalysis->GetEntries();
  cout << nevent << endl;
  Double_t time;
  ULong64_t orbit;
  ULong64_t evt;
  EcalTPGAnalysis->SetBranchAddress("timeStamp", &time);
  EcalTPGAnalysis->SetBranchAddress("orbitNb", &orbit);
  EcalTPGAnalysis->SetBranchAddress("evtNb", &evt);
  

  EcalTPGAnalysis->Draw("timeStamp/60>>h1"); // use time in minutes
  EcalTPGAnalysis->Draw("orbitNb/1000000>>h2"); // Scale by 10^6
  EcalTPGAnalysis->Draw("evtNb/1000000>>h3"); // Scale by 10^6
 
  EcalTPGAnalysis->GetEntry(1); 
  double mintime, minorbit, minevt;
  mintime = time;
  minorbit = orbit; 
  minevt = evt; 

  EcalTPGAnalysis->GetEntry(nevent); 
  double maxtime, maxorbit, maxevt;

  maxtime =time; 
  maxorbit = orbit;
  maxevt = evt; 

  std::cout 
    << "setTimeMax " << maxtime
    << "\nsetTimeMin " << mintime
    << std::endl;

  std::cout 
    << "setOrbMax " << maxorbit
    << "\nsetOrbMin " << minorbit
    << std::endl;

  std::cout 
    << "setEvtMax " << maxevt
    << "\nsetEvtMin " << minevt
    << std::endl;
*/
/*
  std::cout 
    << "setTimeMax " << h1->GetXaxis()->GetXmax()
    << "\nsetTimeMin " << h1->GetXaxis()->GetXmin()
    << std::endl;

  std::cout 
    << "setOrbMax " << h2->GetXaxis()->GetXmax()
    << "\nsetOrbMin " << h2->GetXaxis()->GetXmin()
    << std::endl;

  std::cout 
    << "setEvtMax " << h3->GetXaxis()->GetXmax()
    << "\nsetEvtMin " << h3->GetXaxis()->GetXmin()
    << std::endl;
*/
}

