#ifndef pandanano_PGenParticle_h
#define pandanano_PGenParticle_h

#include "Constants.h"
#include "BranchName.h"
#include "PTruthParticle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PGenParticle : public PTruthParticle {
  public:
    struct datastore : public PTruthParticle::datastore {
      datastore() : PTruthParticle::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PParticleM
      Float_t* mass{0};
      */
      /* PTruthParticle
      Int_t* pdgId{0};
      */
      Int_t* genPartIdxMother{0};
      Int_t* status{0};
      Int_t* statusFlags{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PGenParticle> array_type;
    typedef panda::Collection<PGenParticle> collection_type;

    typedef PTruthParticle base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PGenParticle(char const* name = "");
    PGenParticle(PGenParticle const&);
    PGenParticle(datastore&, UInt_t idx);
    ~PGenParticle();
    PGenParticle& operator=(PGenParticle const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PGenParticle::branchNames; }

    static TString typeName() { return "PGenParticle"; }

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
    /* PTruthParticle
    Int_t& pdgId;
    */
    Int_t& genPartIdxMother;
    Int_t& status;
    Int_t& statusFlags;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PGenParticle(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PGenParticle> PGenParticleArray;
  typedef panda::Collection<PGenParticle> PGenParticleCollection;
  typedef panda::Ref<PGenParticle> PGenParticleRef;
  typedef panda::RefVector<PGenParticle> PGenParticleRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PGenParticle>::branchNames;
}

#endif

