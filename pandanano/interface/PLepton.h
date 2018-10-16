#ifndef pandanano_PLepton_h
#define pandanano_PLepton_h

#include "Constants.h"
#include "BranchName.h"
#include "PRecoParticle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PLepton : public PRecoParticle {
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
      Float_t* dxy{0};
      Float_t* dxyErr{0};
      Float_t* dz{0};
      Float_t* dzErr{0};
      Float_t* ip3d{0};
      Float_t* miniPFRelIso_all{0};
      Float_t* miniPFRelIso_chg{0};
      Int_t* tightCharge{0};
      Bool_t* isPFcand{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PLepton> array_type;
    typedef panda::Collection<PLepton> collection_type;

    typedef PRecoParticle base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PLepton(char const* name = "");
    PLepton(PLepton const&);
    PLepton(datastore&, UInt_t idx);
    ~PLepton();
    PLepton& operator=(PLepton const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PLepton::branchNames; }

    static TString typeName() { return "PLepton"; }

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
    Float_t& dxy;
    Float_t& dxyErr;
    Float_t& dz;
    Float_t& dzErr;
    Float_t& ip3d;
    Float_t& miniPFRelIso_all;
    Float_t& miniPFRelIso_chg;
    Int_t& tightCharge;
    Bool_t& isPFcand;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PLepton(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PLepton> PLeptonArray;
  typedef panda::Collection<PLepton> PLeptonCollection;
  typedef panda::Ref<PLepton> PLeptonRef;
  typedef panda::RefVector<PLepton> PLeptonRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PLepton>::branchNames;
}

#endif

