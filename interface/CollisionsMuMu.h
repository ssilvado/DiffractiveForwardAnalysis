#ifndef DiffractiveForwardAnalysis_CollisionsMuMu
#define DiffractiveForwardAnalysis_CollisionsMuMu

// user include files
#include <FWCore/Framework/interface/Frameworkfwd.h>
#include <FWCore/Framework/interface/EDAnalyzer.h>
#include <FWCore/Framework/interface/EDFilter.h>
#include <FWCore/ParameterSet/interface/ParameterSet.h>
#include <FWCore/ParameterSet/interface/ConfigurationDescriptions.h>  
#include <FWCore/ParameterSet/interface/ParameterSetDescription.h> 
#include <FWCore/ParameterSet/interface/ParameterDescriptionNode.h>  
#include <FWCore/Framework/interface/Event.h>
#include "FWCore/ParameterSet/interface/InputTag.h"

#include "DataFormats/Common/interface/TriggerResults.h" 
#include "FWCore/Framework/interface/TriggerNames.h" 

#include "DiffractiveForwardAnalysis/GammaGammaLeptonLepton/interface/AcceptanceTableHelper.h"

#include <TFile.h>
#include <TH1D.h>
#include <TTree.h>

class CollisionsMuMu : public edm::EDAnalyzer {
 public:
  explicit CollisionsMuMu(const edm::ParameterSet&);
  ~CollisionsMuMu();

  static void fillDescriptions(edm::ConfigurationDescriptions & descriptions);   
  
 private:
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  
  // ----------member data ---------------------------
  
  edm::InputTag recTrackLabel;
  edm::InputTag theGLBMuonLabel;
  edm::InputTag thePixelGsfELabel;
  edm::InputTag theJetLabel;
  edm::InputTag theMetLabel;
  edm::InputTag thePhotonLabel;
  edm::InputTag theCaloTowLabel;

  double mudptmax;
  double mudphimin;
  double drisocalo; 

  std::string rootfilename;

  TFile *thefile;
  TTree *thetree;

  int nMuonCand;
  int MUONMAX;// used to set maximum of arrays
  double MuonCand_px[4];
  double MuonCand_py[4];
  double MuonCand_pz[4];
  double MuonCand_p[4];
  double MuonCand_eta[4];
  double MuonCand_pt[4];
  double MuonCand_phi[4];
  double MuonCand_e[4];
  double MuonCandTrack_p[100];
  int MuonCand_charge[4];
  int MuonCand_tmlsloosemuonid[4];
  int MuonCand_tm2dloosemuid[4];
  int MuonCand_arbmuid[4];
  int MuonCand_isglobal[4];
  int MuonCand_istracker[4];
  int MuonCand_isstandalone[4];
  double MuonCand_ecalisor3[4]; 
  double MuonCand_hcalisor3[4]; 
  double MuonCand_trkisor3[4]; 
  double MuonCand_ecalisor5[4];  
  double MuonCand_hcalisor5[4];  
  double MuonCand_trkisor5[4]; 
  double MuonCand_vtxx[4];
  double MuonCand_vtxy[4]; 
  double MuonCand_vtxz[4]; 

  double MuonCand_trkpt[4];
  double MuonCand_trketa[4]; 
  double MuonCand_trkphi[4]; 
  double MuonCand_samuonpt[4]; 
  double MuonCand_samuoneta[4]; 
  double MuonCand_samuonphi[4]; 
  double MuonCand_timein[4];
  double MuonCand_timeout[4];
  double MuonCand_timeouterr[4];
  double MuonCand_timeinerr[4];

  double MuMu_mass;
  double MuMu_dphi;
  double MuMu_vtxx;
  double MuMu_vtxy;
  double MuMu_vtxz;
  double MuMu_vtxchi2dof;
  int MuMu_vtxisvalid;

  int MuMu_extratracks1mm;
  int MuMu_extratracks2mm;
  int MuMu_extratracks3mm;
  int MuMu_extratracks4mm;
  int MuMu_extratracks5mm;
  int MuMu_extratracks1cm;
  int MuMu_extratracks2cm;
  int MuMu_extratracks5cm;
  int MuMu_extratracks10cm;

  int nJetCand;
  int JETMAX;// used to set maximum of arrays
  double JetCand_px[30];
  double JetCand_py[30];
  double JetCand_pz[30];
  double JetCand_e[30];
  double JetCand_eta[30];
  double JetCand_phi[30];
  double HighestJet_e;
  double HighestJet_eta;
  double HighestJet_phi;
  double SumJet_e;

  int nPFlowCand;

  int HitInZDC; 
  int HitInCastor; 

  double Etmiss;

  int nCaloCand;
  int CALOMAX;
  int nExtraCaloTowersE1, nExtraCaloTowersE2, nExtraCaloTowersE3, nExtraCaloTowersE4, nExtraCaloTowersE5, nExtraCaloTowersE6, nExtraCaloTowersE7, nExtraCaloTowersE8, nExtraCaloTowersE9; 
  int nExtraCaloTowersEt0pt1, nExtraCaloTowersEt0pt2, nExtraCaloTowersEt0pt5, nExtraCaloTowersEt1, nExtraCaloTowersEt2, nExtraCaloTowersEt3, nExtraCaloTowersEt4; 
  int nExtraCaloTowersE0hf, nExtraCaloTowersE1hf, nExtraCaloTowersE2hf, nExtraCaloTowersE3hf, nExtraCaloTowersE4hf, nExtraCaloTowersE5hf;
  int nExtraCaloTowersE1he, nExtraCaloTowersE2he, nExtraCaloTowersE3he, nExtraCaloTowersE4he, nExtraCaloTowersE5he;
  int nExtraCaloTowersE2hb, nExtraCaloTowersE3hb, nExtraCaloTowersE4hb, nExtraCaloTowersE5hb;
  double CaloTower_e[5000];
  double CaloTower_emE[5000];
  double CaloTower_hadE[5000];
  double CaloTower_outE[5000];
  double CaloTower_et[5000];
  double CaloTower_eta[5000];
  double CaloTower_phi[5000];
  double CaloTower_dr[5000];

  int CaloTower_ID[5000];
  double CaloTower_x[5000];
  double CaloTower_y[5000];
  double CaloTower_z[5000];
  double CaloTower_t[5000];


  int CaloTower_badhcalcells[5000];
  int CaloTower_problemhcalcells[5000];
  int CaloTower_badecalcells[5000];
  int CaloTower_problemecalcells[5000];
  double HighestCaloTower_e;
  double HighestCaloTower_eta;
  double HighestCaloTower_phi;
  double HighestCaloTower_dr;
  double HighestEtCaloTower_et;
  double HighestEtCaloTower_eta;
  double HighestEtCaloTower_phi;
  double HighestEtCaloTower_dr;
  double SumCalo_e;

  int nTrackCand;
  int nExtraTrackCand;
  int TRACKMAX;
  double TrackCand_px[100];
  double TrackCand_py[100];
  double TrackCand_pz[100];
  double TrackCand_p[100];
  double TrackCand_eta[100];
  double TrackCand_pt[100];
  double TrackCand_phi[100];
  double TrackCand_vtxdxyz[100];
  int TrackCand_charge[100];
  double ClosestExtraTrack_vtxdxyz;

  int nVertexCand;
  double VertexCand_x[10];
  double VertexCand_y[10];
  double VertexCand_z[10];

  double evweight;
  
  int HLT2MuonNonIso;
  int HLT1MuonPrescalePt3;

  edm::TriggerNames trigNames ;
};
#endif