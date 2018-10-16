#ifndef pandanano_PGenTau_h
#define pandanano_PGenTau_h

#include "Constants.h"
#include "BranchName.h"
#include "PParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PGenTau : public PParticleM {
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
      Int_t* genPartIdxMother{0};
      Int_t* status{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PGenTau> array_type;
    typedef panda::Collection<PGenTau> collection_type;

    typedef PParticleM base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PGenTau(char const* name = "");
    PGenTau(PGenTau const&);
    PGenTau(datastore&, UInt_t idx);
    ~PGenTau();
    PGenTau& operator=(PGenTau const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PGenTau::branchNames; }

    static TString typeName() { return "PGenTau"; }

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
    Int_t& genPartIdxMother;
    Int_t& status;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PGenTau(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PGenTau> PGenTauArray;
  typedef panda::Collection<PGenTau> PGenTauCollection;
  typedef panda::Ref<PGenTau> PGenTauRef;
  typedef panda::RefVector<PGenTau> PGenTauRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PGenTau>::branchNames;
}

#endif

