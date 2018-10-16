#ifndef pandanano_PSubstructuredJet_h
#define pandanano_PSubstructuredJet_h

#include "Constants.h"
#include "BranchName.h"
#include "PRecoJet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PSubstructuredJet : public PRecoJet {
  public:
    struct datastore : public PRecoJet::datastore {
      datastore() : PRecoJet::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PParticleM
      Float_t* mass{0};
      */
      /* PRecoJet
      Float_t* btagCMVA{0};
      Float_t* btagCSVV2{0};
      Float_t* btagDeepB{0};
      */
      Float_t* n2b1{0};
      Float_t* n3b1{0};
      Float_t* tau1{0};
      Float_t* tau2{0};
      Float_t* tau3{0};
      Float_t* tau4{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PSubstructuredJet> array_type;
    typedef panda::Collection<PSubstructuredJet> collection_type;

    typedef PRecoJet base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PSubstructuredJet(char const* name = "");
    PSubstructuredJet(PSubstructuredJet const&);
    PSubstructuredJet(datastore&, UInt_t idx);
    ~PSubstructuredJet();
    PSubstructuredJet& operator=(PSubstructuredJet const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PSubstructuredJet::branchNames; }

    static TString typeName() { return "PSubstructuredJet"; }

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
    /* PRecoJet
    Float_t& btagCMVA;
    Float_t& btagCSVV2;
    Float_t& btagDeepB;
    */
    Float_t& n2b1;
    Float_t& n3b1;
    Float_t& tau1;
    Float_t& tau2;
    Float_t& tau3;
    Float_t& tau4;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PSubstructuredJet(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PSubstructuredJet> PSubstructuredJetArray;
  typedef panda::Collection<PSubstructuredJet> PSubstructuredJetCollection;
  typedef panda::Ref<PSubstructuredJet> PSubstructuredJetRef;
  typedef panda::RefVector<PSubstructuredJet> PSubstructuredJetRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PSubstructuredJet>::branchNames;
}

#endif

