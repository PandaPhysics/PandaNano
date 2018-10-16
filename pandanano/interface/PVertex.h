#ifndef pandanano_PVertex_h
#define pandanano_PVertex_h

#include "Constants.h"
#include "BranchName.h"
#include "../../Framework/interface/Element.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PVertex : public panda::Element {
  public:
    struct datastore : public panda::Element::datastore {
      datastore() : panda::Element::datastore() {}
      ~datastore() { deallocate(); }

      Float_t* z{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PVertex> array_type;
    typedef panda::Collection<PVertex> collection_type;

    typedef panda::Element base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PVertex(char const* name = "");
    PVertex(PVertex const&);
    PVertex(datastore&, UInt_t idx);
    ~PVertex();
    PVertex& operator=(PVertex const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PVertex::branchNames; }

    static TString typeName() { return "PVertex"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    Float_t& z;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PVertex(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PVertex> PVertexArray;
  typedef panda::Collection<PVertex> PVertexCollection;
  typedef panda::Ref<PVertex> PVertexRef;
  typedef panda::RefVector<PVertex> PVertexRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PVertex>::branchNames;
}

#endif

