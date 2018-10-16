#ifndef pandanano_PJet_h
#define pandanano_PJet_h

#include "Constants.h"
#include "BranchName.h"
#include "PRecoJet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PJet : public PRecoJet {
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
      Float_t* area{0};
      Float_t* btagDeepC{0};
      Float_t* btagDeepFlavB{0};
      Float_t* chEmEF{0};
      Float_t* chHEF{0};
      Float_t* muEF{0};
      Float_t* neEmEF{0};
      Float_t* neHEF{0};
      Float_t* qgl{0};
      Float_t* rawFactor{0};
      Float_t* bRegCorr{0};
      Float_t* bRegRes{0};
      Int_t* electronIdx1{0};
      Int_t* electronIdx2{0};
      Int_t* jetId{0};
      Int_t* muonIdx1{0};
      Int_t* muonIdx2{0};
      Int_t* nConstituents{0};
      Int_t* nElectrons{0};
      Int_t* nMuons{0};
      Int_t* puId{0};
      Int_t* genJetIdx{0};
      Int_t* hadronFlavour{0};
      Int_t* partonFlavour{0};
      UChar_t* cleanmask{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PJet> array_type;
    typedef panda::Collection<PJet> collection_type;

    typedef PRecoJet base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PJet(char const* name = "");
    PJet(PJet const&);
    PJet(datastore&, UInt_t idx);
    ~PJet();
    PJet& operator=(PJet const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PJet::branchNames; }

    static TString typeName() { return "PJet"; }

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
    Float_t& area;
    Float_t& btagDeepC;
    Float_t& btagDeepFlavB;
    Float_t& chEmEF;
    Float_t& chHEF;
    Float_t& muEF;
    Float_t& neEmEF;
    Float_t& neHEF;
    Float_t& qgl;
    Float_t& rawFactor;
    Float_t& bRegCorr;
    Float_t& bRegRes;
    Int_t& electronIdx1;
    Int_t& electronIdx2;
    Int_t& jetId;
    Int_t& muonIdx1;
    Int_t& muonIdx2;
    Int_t& nConstituents;
    Int_t& nElectrons;
    Int_t& nMuons;
    Int_t& puId;
    Int_t& genJetIdx;
    Int_t& hadronFlavour;
    Int_t& partonFlavour;
    UChar_t& cleanmask;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PJet(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PJet> PJetArray;
  typedef panda::Collection<PJet> PJetCollection;
  typedef panda::Ref<PJet> PJetRef;
  typedef panda::RefVector<PJet> PJetRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PJet>::branchNames;
}

#endif

