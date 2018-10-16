#ifndef pandanano_PFatJet_h
#define pandanano_PFatJet_h

#include "Constants.h"
#include "BranchName.h"
#include "PSubstructuredJet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PFatJet : public PSubstructuredJet {
  public:
    struct datastore : public PSubstructuredJet::datastore {
      datastore() : PSubstructuredJet::datastore() {}
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
      /* PSubstructuredJet
      Float_t* n2b1{0};
      Float_t* n3b1{0};
      Float_t* tau1{0};
      Float_t* tau2{0};
      Float_t* tau3{0};
      Float_t* tau4{0};
      */
      Float_t* area{0};
      Float_t* btagHbb{0};
      Float_t* msoftdrop{0};
      Float_t* rawFactor{0};
      Int_t* jetId{0};
      Int_t* subJetIdx1{0};
      Int_t* subJetIdx2{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PFatJet> array_type;
    typedef panda::Collection<PFatJet> collection_type;

    typedef PSubstructuredJet base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PFatJet(char const* name = "");
    PFatJet(PFatJet const&);
    PFatJet(datastore&, UInt_t idx);
    ~PFatJet();
    PFatJet& operator=(PFatJet const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PFatJet::branchNames; }

    static TString typeName() { return "PFatJet"; }

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
    /* PSubstructuredJet
    Float_t& n2b1;
    Float_t& n3b1;
    Float_t& tau1;
    Float_t& tau2;
    Float_t& tau3;
    Float_t& tau4;
    */
    Float_t& area;
    Float_t& btagHbb;
    Float_t& msoftdrop;
    Float_t& rawFactor;
    Int_t& jetId;
    Int_t& subJetIdx1;
    Int_t& subJetIdx2;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PFatJet(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PFatJet> PFatJetArray;
  typedef panda::Collection<PFatJet> PFatJetCollection;
  typedef panda::Ref<PFatJet> PFatJetRef;
  typedef panda::RefVector<PFatJet> PFatJetRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PFatJet>::branchNames;
}

#endif

