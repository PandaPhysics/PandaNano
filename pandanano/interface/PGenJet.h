#ifndef pandanano_PGenJet_h
#define pandanano_PGenJet_h

#include "Constants.h"
#include "BranchName.h"
#include "PParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PGenJet : public PParticleM {
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
      Int_t* partonFlavour{0};
      UChar_t* hadronFlavour{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PGenJet> array_type;
    typedef panda::Collection<PGenJet> collection_type;

    typedef PParticleM base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PGenJet(char const* name = "");
    PGenJet(PGenJet const&);
    PGenJet(datastore&, UInt_t idx);
    ~PGenJet();
    PGenJet& operator=(PGenJet const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PGenJet::branchNames; }

    static TString typeName() { return "PGenJet"; }

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
    Int_t& partonFlavour;
    UChar_t& hadronFlavour;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PGenJet(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PGenJet> PGenJetArray;
  typedef panda::Collection<PGenJet> PGenJetCollection;
  typedef panda::Ref<PGenJet> PGenJetRef;
  typedef panda::RefVector<PGenJet> PGenJetRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PGenJet>::branchNames;
}

#endif

