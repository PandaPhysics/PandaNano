#ifndef pandanano_PMuon_h
#define pandanano_PMuon_h

#include "Constants.h"
#include "BranchName.h"
#include "PLepton.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PMuon : public PLepton {
  public:
    struct datastore : public PLepton::datastore {
      datastore() : PLepton::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PParticleM
      Float_t* mass{0};
      */
      /* PRecoParticle
      Int_t* charge{0};
      Int_t* jetIdx{0};
      Int_t* pdgId{0};
      Int_t* genPartIdx{0};
      UChar_t* genPartFlav{0};
      UChar_t* cleanmask{0};
      */
      /* PLepton
      Float_t* dxy{0};
      Float_t* dxyErr{0};
      Float_t* dz{0};
      Float_t* dzErr{0};
      Float_t* ip3d{0};
      Float_t* miniPFRelIso_all{0};
      Float_t* miniPFRelIso_chg{0};
      Int_t* tightCharge{0};
      Bool_t* isPFcand{0};
      */
      Float_t* pfRelIso03_all{0};
      Float_t* pfRelIso03_chg{0};
      Float_t* pfRelIso04_all{0};
      Float_t* ptErr{0};
      Float_t* segmentComp{0};
      Float_t* sip3d{0};
      Float_t* mvaTTH{0};
      Int_t* nStations{0};
      Int_t* nTrackerLayers{0};
      UChar_t* highPtId{0};
      Bool_t* mediumId{0};
      Bool_t* softId{0};
      Bool_t* tightId{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PMuon> array_type;
    typedef panda::Collection<PMuon> collection_type;

    typedef PLepton base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PMuon(char const* name = "");
    PMuon(PMuon const&);
    PMuon(datastore&, UInt_t idx);
    ~PMuon();
    PMuon& operator=(PMuon const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PMuon::branchNames; }

    static TString typeName() { return "PMuon"; }

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
    /* PRecoParticle
    Int_t& charge;
    Int_t& jetIdx;
    Int_t& pdgId;
    Int_t& genPartIdx;
    UChar_t& genPartFlav;
    UChar_t& cleanmask;
    */
    /* PLepton
    Float_t& dxy;
    Float_t& dxyErr;
    Float_t& dz;
    Float_t& dzErr;
    Float_t& ip3d;
    Float_t& miniPFRelIso_all;
    Float_t& miniPFRelIso_chg;
    Int_t& tightCharge;
    Bool_t& isPFcand;
    */
    Float_t& pfRelIso03_all;
    Float_t& pfRelIso03_chg;
    Float_t& pfRelIso04_all;
    Float_t& ptErr;
    Float_t& segmentComp;
    Float_t& sip3d;
    Float_t& mvaTTH;
    Int_t& nStations;
    Int_t& nTrackerLayers;
    UChar_t& highPtId;
    Bool_t& mediumId;
    Bool_t& softId;
    Bool_t& tightId;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PMuon(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PMuon> PMuonArray;
  typedef panda::Collection<PMuon> PMuonCollection;
  typedef panda::Ref<PMuon> PMuonRef;
  typedef panda::RefVector<PMuon> PMuonRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PMuon>::branchNames;
}

#endif

