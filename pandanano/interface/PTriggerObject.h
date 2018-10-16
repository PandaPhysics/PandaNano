#ifndef pandanano_PTriggerObject_h
#define pandanano_PTriggerObject_h

#include "Constants.h"
#include "BranchName.h"
#include "PParticle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PTriggerObject : public PParticle {
  public:
    struct datastore : public PParticle::datastore {
      datastore() : PParticle::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      Float_t* l1pt{0};
      Float_t* l1pt_2{0};
      Float_t* l2pt{0};
      Int_t* id{0};
      Int_t* l1iso{0};
      Int_t* l1charge{0};
      Int_t* filterBits{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PTriggerObject> array_type;
    typedef panda::Collection<PTriggerObject> collection_type;

    typedef PParticle base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PTriggerObject(char const* name = "");
    PTriggerObject(PTriggerObject const&);
    PTriggerObject(datastore&, UInt_t idx);
    ~PTriggerObject();
    PTriggerObject& operator=(PTriggerObject const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PTriggerObject::branchNames; }

    static TString typeName() { return "PTriggerObject"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Float_t& l1pt;
    Float_t& l1pt_2;
    Float_t& l2pt;
    Int_t& id;
    Int_t& l1iso;
    Int_t& l1charge;
    Int_t& filterBits;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PTriggerObject(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PTriggerObject> PTriggerObjectArray;
  typedef panda::Collection<PTriggerObject> PTriggerObjectCollection;
  typedef panda::Ref<PTriggerObject> PTriggerObjectRef;
  typedef panda::RefVector<PTriggerObject> PTriggerObjectRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PTriggerObject>::branchNames;
}

#endif

