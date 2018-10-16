#ifndef pandanano_Events_h
#define pandanano_Events_h

#include "Constants.h"
#include "BranchName.h"
#include "../../Framework/interface/TreeEntry.h"
#include "PGenInfo.h"
#include "PLHEInfo.h"
#include "PTruthParticle.h"
#include "PBTagWeight.h"
#include "PElectron.h"
#include "PFatJet.h"
#include "PGenJet.h"
#include "PGenParticle.h"
#include "PParticleM.h"
#include "PGenTau.h"
#include "PLHEWeight.h"
#include "PIsoTrack.h"
#include "PJet.h"
#include "PMuon.h"
#include "PPhoton.h"
#include "PPileupInfo.h"
#include "PRecoMET.h"
#include "PMET.h"
#include "PParticle.h"
#include "PSubstructuredJet.h"
#include "PTau.h"
#include "PTriggerObject.h"
#include "PVertex.h"
#include "PPrimaryVertex.h"
#include "PEventFilter.h"

namespace pandanano {

  class Events : public panda::TreeEntry {
  public:
    Events();
    Events(Events const&);
    ~Events();
    Events& operator=(Events const&);

    panda::utils::BranchList const& getBranchNames() const override { return Events::branchNames; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    PGenInfo Generator = PGenInfo("Generator");
    PLHEInfo LHE = PLHEInfo("LHE");
    PTruthParticleCollection LHEPart = PTruthParticleCollection("LHEPart");
    PBTagWeight btagWeight = PBTagWeight("btagWeight");
    PElectronCollection Electron = PElectronCollection("Electron");
    PFatJetCollection FatJet = PFatJetCollection("FatJet");
    PGenJetCollection GenJet = PGenJetCollection("GenJet");
    PGenJetCollection GenJetAK8 = PGenJetCollection("GenJetAK8");
    PGenParticleCollection GenPart = PGenParticleCollection("GenPart");
    PParticleMCollection SubGenJetAK8 = PParticleMCollection("SubGenJetAK8");
    PGenTauCollection GenVisTau = PGenTauCollection("GenVisTau");
    PLHEWeight LHEWeight = PLHEWeight("LHEWeight");
    PIsoTrackCollection IsoTrack = PIsoTrackCollection("IsoTrack");
    PJetCollection Jet = PJetCollection("Jet");
    PMuonCollection Muon = PMuonCollection("Muon");
    PPhotonCollection Photon = PPhotonCollection("Photon");
    PPileupInfo Pileup = PPileupInfo("Pileup");
    PRecoMET MET = PRecoMET("MET");
    PMET PuppiMET = PMET("PuppiMET");
    PMET CaloMET = PMET("CaloMET");
    PMET TkMET = PMET("TkMET");
    PMET RawMET = PMET("RawMET");
    PMET GenMET = PMET("GenMET");
    PTruthParticleCollection GenDressedLepton = PTruthParticleCollection("GenDressedLepton");
    PParticleCollection SoftActivityJet = PParticleCollection("SoftActivityJet");
    PSubstructuredJetCollection SubJet = PSubstructuredJetCollection("SubJet");
    PTauCollection Tau = PTauCollection("Tau");
    PTriggerObjectCollection TrigObj = PTriggerObjectCollection("TrigObj");
    PVertexCollection OtherPV = PVertexCollection("OtherPV");
    PPrimaryVertex PV = PPrimaryVertex("PV");
    PEventFilter Flag = PEventFilter("Flag");

    UInt_t run{};
    UInt_t luminosityBlock{};
    ULong64_t event{};
    Float_t genWeight{};
    UInt_t nLHEPdfWeight{};
    Float_t LHEPdfWeight{};
    UInt_t nLHEScaleWeight{};
    Float_t LHEScaleWeight{};
    UInt_t nPSWeight{};
    Float_t PSWeight{};
    Float_t fixedGridRhoFastjetAll{};
    Float_t fixedGridRhoFastjetCentralCalo{};
    Float_t fixedGridRhoFastjetCentralNeutral{};
    Float_t SoftActivityJetHT{};
    Float_t SoftActivityJetHT10{};
    Float_t SoftActivityJetHT2{};
    Float_t SoftActivityJetHT5{};
    Int_t SoftActivityJetNjets10{};
    Int_t SoftActivityJetNjets2{};
    Int_t SoftActivityJetNjets5{};
    Int_t genTtbarId{};
    Bool_t L1simulation_step{};
    Bool_t HLTriggerFirstPath{};
    Bool_t L1Reco_step{};

    static pandanano::BranchList const branchNames;

  protected:
    void doSetStatus_(TTree&, panda::utils::BranchList const&) override;
    void doSetAddress_(TTree&, panda::utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, panda::utils::BranchList const&) override;
    void doGetEntry_(TTree&) override;
    void doInit_() override;
    void doUnlink_(TTree&) override;

  public:
    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

#endif

