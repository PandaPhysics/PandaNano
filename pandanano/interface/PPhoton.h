#ifndef pandanano_PPhoton_h
#define pandanano_PPhoton_h

#include "Constants.h"
#include "BranchName.h"
#include "PRecoParticle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PPhoton : public PRecoParticle {
  public:
    struct datastore : public PRecoParticle::datastore {
      datastore() : PRecoParticle::datastore() {}
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
      Float_t* energyErr{0};
      Float_t* hoe{0};
      Float_t* mvaID{0};
      Float_t* pfRelIso03_all{0};
      Float_t* pfRelIso03_chg{0};
      Float_t* r9{0};
      Float_t* sieie{0};
      Int_t* cutBasedBitmap{0};
      Int_t* electronIdx{0};
      Int_t* vidNestedWPBitmap{0};
      Bool_t* electronVeto{0};
      Bool_t* isScEtaEB{0};
      Bool_t* isScEtaEE{0};
      Bool_t* mvaID_WP80{0};
      Bool_t* mvaID_WP90{0};
      Bool_t* pixelSeed{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PPhoton> array_type;
    typedef panda::Collection<PPhoton> collection_type;

    typedef PRecoParticle base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PPhoton(char const* name = "");
    PPhoton(PPhoton const&);
    PPhoton(datastore&, UInt_t idx);
    ~PPhoton();
    PPhoton& operator=(PPhoton const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PPhoton::branchNames; }

    static TString typeName() { return "PPhoton"; }

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
    Float_t& energyErr;
    Float_t& hoe;
    Float_t& mvaID;
    Float_t& pfRelIso03_all;
    Float_t& pfRelIso03_chg;
    Float_t& r9;
    Float_t& sieie;
    Int_t& cutBasedBitmap;
    Int_t& electronIdx;
    Int_t& vidNestedWPBitmap;
    Bool_t& electronVeto;
    Bool_t& isScEtaEB;
    Bool_t& isScEtaEE;
    Bool_t& mvaID_WP80;
    Bool_t& mvaID_WP90;
    Bool_t& pixelSeed;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PPhoton(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PPhoton> PPhotonArray;
  typedef panda::Collection<PPhoton> PPhotonCollection;
  typedef panda::Ref<PPhoton> PPhotonRef;
  typedef panda::RefVector<PPhoton> PPhotonRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PPhoton>::branchNames;
}

#endif

