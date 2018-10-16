#ifndef pandanano_PSecondaryVertex_h
#define pandanano_PSecondaryVertex_h

#include "Constants.h"
#include "BranchName.h"
#include "PParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PSecondaryVertex : public PParticleM {
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
      Float_t* dlen{0};
      Float_t* dlenSig{0};
      Float_t* pAngle{0};
      Float_t* chi2{0};
      Float_t* ndof{0};
      Float_t* x{0};
      Float_t* y{0};
      Float_t* z{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PSecondaryVertex> array_type;
    typedef panda::Collection<PSecondaryVertex> collection_type;

    typedef PParticleM base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PSecondaryVertex(char const* name = "");
    PSecondaryVertex(PSecondaryVertex const&);
    PSecondaryVertex(datastore&, UInt_t idx);
    ~PSecondaryVertex();
    PSecondaryVertex& operator=(PSecondaryVertex const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PSecondaryVertex::branchNames; }

    static TString typeName() { return "PSecondaryVertex"; }

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
    Float_t& dlen;
    Float_t& dlenSig;
    Float_t& pAngle;
    Float_t& chi2;
    Float_t& ndof;
    Float_t& x;
    Float_t& y;
    Float_t& z;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PSecondaryVertex(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PSecondaryVertex> PSecondaryVertexArray;
  typedef panda::Collection<PSecondaryVertex> PSecondaryVertexCollection;
  typedef panda::Ref<PSecondaryVertex> PSecondaryVertexRef;
  typedef panda::RefVector<PSecondaryVertex> PSecondaryVertexRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PSecondaryVertex>::branchNames;
}

#endif

