#ifndef pandanano_PElectron_h
#define pandanano_PElectron_h

#include "Constants.h"
#include "BranchName.h"
#include "PLepton.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PElectron : public PLepton {
  public:
    struct datastore : public PLepton::datastore {
      datastore() : PLepton::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PParticleM
      Float_t* mass{0};
      */
      /* PRecoParticle
      Int_t* charge{0};
      Int_t* jetIdx{0};
      Int_t* pdgId{0};
      Int_t* genPartIdx{0};
      UChar_t* genPartFlav{0};
      UChar_t* cleanmask{0};
      */
      /* PLepton
      Float_t* dxy{0};
      Float_t* dxyErr{0};
      Float_t* dz{0};
      Float_t* dzErr{0};
      Float_t* ip3d{0};
      Float_t* miniPFRelIso_all{0};
      Float_t* miniPFRelIso_chg{0};
      Int_t* tightCharge{0};
      Bool_t* isPFcand{0};
      */
      Float_t* deltaEtaSC{0};
      Float_t* dr03EcalRecHitSumEt{0};
      Float_t* dr03HcalDepth1TowerSumEt{0};
      Float_t* dr03TkSumPt{0};
      Float_t* eInvMinusPInv{0};
      Float_t* energyErr{0};
      Float_t* hoe{0};
      Float_t* pfRelIso03_all{0};
      Float_t* pfRelIso03_chg{0};
      Float_t* r9{0};
      Float_t* sieie{0};
      Float_t* sip3d{0};
      Float_t* mvaTTH{0};
      Int_t* cutBased{0};
      Int_t* cutBased_Fall17_V1{0};
      Int_t* photonIdx{0};
      Int_t* vidNestedWPBitmap{0};
      Bool_t* convVeto{0};
      Bool_t* cutBased_HEEP{0};
      UChar_t* lostHits{0};
      Float_t* mvaFall17V1Iso{0};
      Float_t* mvaFall17V1noIso{0};
      Float_t* mvaFall17V2Iso{0};
      Float_t* mvaFall17V2noIso{0};
      Bool_t* mvaFall17V1Iso_WP80{0};
      Bool_t* mvaFall17V1Iso_WP90{0};
      Bool_t* mvaFall17V1Iso_WPL{0};
      Bool_t* mvaFall17V1noIso_WP80{0};
      Bool_t* mvaFall17V1noIso_WP90{0};
      Bool_t* mvaFall17V1noIso_WPL{0};
      Bool_t* mvaFall17V2Iso_WP80{0};
      Bool_t* mvaFall17V2Iso_WP90{0};
      Bool_t* mvaFall17V2Iso_WPL{0};
      Bool_t* mvaFall17V2noIso_WP80{0};
      Bool_t* mvaFall17V2noIso_WP90{0};
      Bool_t* mvaFall17V2noIso_WPL{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PElectron> array_type;
    typedef panda::Collection<PElectron> collection_type;

    typedef PLepton base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PElectron(char const* name = "");
    PElectron(PElectron const&);
    PElectron(datastore&, UInt_t idx);
    ~PElectron();
    PElectron& operator=(PElectron const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PElectron::branchNames; }

    static TString typeName() { return "PElectron"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PParticleM
    Float_t& mass;
    */
    /* PRecoParticle
    Int_t& charge;
    Int_t& jetIdx;
    Int_t& pdgId;
    Int_t& genPartIdx;
    UChar_t& genPartFlav;
    UChar_t& cleanmask;
    */
    /* PLepton
    Float_t& dxy;
    Float_t& dxyErr;
    Float_t& dz;
    Float_t& dzErr;
    Float_t& ip3d;
    Float_t& miniPFRelIso_all;
    Float_t& miniPFRelIso_chg;
    Int_t& tightCharge;
    Bool_t& isPFcand;
    */
    Float_t& deltaEtaSC;
    Float_t& dr03EcalRecHitSumEt;
    Float_t& dr03HcalDepth1TowerSumEt;
    Float_t& dr03TkSumPt;
    Float_t& eInvMinusPInv;
    Float_t& energyErr;
    Float_t& hoe;
    Float_t& pfRelIso03_all;
    Float_t& pfRelIso03_chg;
    Float_t& r9;
    Float_t& sieie;
    Float_t& sip3d;
    Float_t& mvaTTH;
    Int_t& cutBased;
    Int_t& cutBased_Fall17_V1;
    Int_t& photonIdx;
    Int_t& vidNestedWPBitmap;
    Bool_t& convVeto;
    Bool_t& cutBased_HEEP;
    UChar_t& lostHits;
    Float_t& mvaFall17V1Iso;
    Float_t& mvaFall17V1noIso;
    Float_t& mvaFall17V2Iso;
    Float_t& mvaFall17V2noIso;
    Bool_t& mvaFall17V1Iso_WP80;
    Bool_t& mvaFall17V1Iso_WP90;
    Bool_t& mvaFall17V1Iso_WPL;
    Bool_t& mvaFall17V1noIso_WP80;
    Bool_t& mvaFall17V1noIso_WP90;
    Bool_t& mvaFall17V1noIso_WPL;
    Bool_t& mvaFall17V2Iso_WP80;
    Bool_t& mvaFall17V2Iso_WP90;
    Bool_t& mvaFall17V2Iso_WPL;
    Bool_t& mvaFall17V2noIso_WP80;
    Bool_t& mvaFall17V2noIso_WP90;
    Bool_t& mvaFall17V2noIso_WPL;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PElectron(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PElectron> PElectronArray;
  typedef panda::Collection<PElectron> PElectronCollection;
  typedef panda::Ref<PElectron> PElectronRef;
  typedef panda::RefVector<PElectron> PElectronRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PElectron>::branchNames;
}

#endif

