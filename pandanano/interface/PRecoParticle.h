#ifndef pandanano_PRecoParticle_h
#define pandanano_PRecoParticle_h

#include "Constants.h"
#include "BranchName.h"
#include "PParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PRecoParticle : public PParticleM {
  public:
    struct datastore : public PParticleM::datastore {
      datastore() : PParticleM::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PParticleM
      Float_t* mass{0};
      */
      Int_t* charge{0};
      Int_t* jetIdx{0};
      Int_t* pdgId{0};
      Int_t* genPartIdx{0};
      UChar_t* genPartFlav{0};
      UChar_t* cleanmask{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PRecoParticle> array_type;
    typedef panda::Collection<PRecoParticle> collection_type;

    typedef PParticleM base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PRecoParticle(char const* name = "");
    PRecoParticle(PRecoParticle const&);
    PRecoParticle(datastore&, UInt_t idx);
    ~PRecoParticle();
    PRecoParticle& operator=(PRecoParticle const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PRecoParticle::branchNames; }

    static TString typeName() { return "PRecoParticle"; }

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
    Int_t& charge;
    Int_t& jetIdx;
    Int_t& pdgId;
    Int_t& genPartIdx;
    UChar_t& genPartFlav;
    UChar_t& cleanmask;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PRecoParticle(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PRecoParticle> PRecoParticleArray;
  typedef panda::Collection<PRecoParticle> PRecoParticleCollection;
  typedef panda::Ref<PRecoParticle> PRecoParticleRef;
  typedef panda::RefVector<PRecoParticle> PRecoParticleRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PRecoParticle>::branchNames;
}

#endif

