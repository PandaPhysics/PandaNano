#ifndef pandanano_PTau_h
#define pandanano_PTau_h

#include "Constants.h"
#include "BranchName.h"
#include "PRecoParticle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PTau : public PRecoParticle {
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
      Float_t* chargedIso{0};
      Float_t* dxy{0};
      Float_t* dz{0};
      Float_t* leadTkDeltaEta{0};
      Float_t* leadTkDeltaPhi{0};
      Float_t* leadTkPtOverTauPt{0};
      Float_t* neutralIso{0};
      Float_t* photonsOutsideSignalCone{0};
      Float_t* puCorr{0};
      Float_t* rawAntiEle{0};
      Float_t* rawIso{0};
      Float_t* rawIsodR03{0};
      Int_t* decayMode{0};
      Int_t* rawAntiEleCat{0};
      UChar_t* idAntiEle{0};
      UChar_t* idAntiMu{0};
      Bool_t* idDecayMode{0};
      Bool_t* idDecayModeNewDMs{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PTau> array_type;
    typedef panda::Collection<PTau> collection_type;

    typedef PRecoParticle base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PTau(char const* name = "");
    PTau(PTau const&);
    PTau(datastore&, UInt_t idx);
    ~PTau();
    PTau& operator=(PTau const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PTau::branchNames; }

    static TString typeName() { return "PTau"; }

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
    Float_t& chargedIso;
    Float_t& dxy;
    Float_t& dz;
    Float_t& leadTkDeltaEta;
    Float_t& leadTkDeltaPhi;
    Float_t& leadTkPtOverTauPt;
    Float_t& neutralIso;
    Float_t& photonsOutsideSignalCone;
    Float_t& puCorr;
    Float_t& rawAntiEle;
    Float_t& rawIso;
    Float_t& rawIsodR03;
    Int_t& decayMode;
    Int_t& rawAntiEleCat;
    UChar_t& idAntiEle;
    UChar_t& idAntiMu;
    Bool_t& idDecayMode;
    Bool_t& idDecayModeNewDMs;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PTau(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PTau> PTauArray;
  typedef panda::Collection<PTau> PTauCollection;
  typedef panda::Ref<PTau> PTauRef;
  typedef panda::RefVector<PTau> PTauRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PTau>::branchNames;
}

#endif

