#ifndef pandanano_PIsoTrack_h
#define pandanano_PIsoTrack_h

#include "Constants.h"
#include "BranchName.h"
#include "PParticle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PIsoTrack : public PParticle {
  public:
    struct datastore : public PParticle::datastore {
      datastore() : PParticle::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      Float_t* dxy{0};
      Float_t* dz{0};
      Float_t* pfRelIso03_all{0};
      Float_t* pfRelIso03_chg{0};
      Float_t* miniPFRelIso_all{0};
      Float_t* miniPFRelIso_chg{0};
      Int_t* pdgId{0};
      Bool_t* isHighPurityTrack{0};
      Bool_t* isPFcand{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PIsoTrack> array_type;
    typedef panda::Collection<PIsoTrack> collection_type;

    typedef PParticle base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PIsoTrack(char const* name = "");
    PIsoTrack(PIsoTrack const&);
    PIsoTrack(datastore&, UInt_t idx);
    ~PIsoTrack();
    PIsoTrack& operator=(PIsoTrack const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PIsoTrack::branchNames; }

    static TString typeName() { return "PIsoTrack"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Float_t& dxy;
    Float_t& dz;
    Float_t& pfRelIso03_all;
    Float_t& pfRelIso03_chg;
    Float_t& miniPFRelIso_all;
    Float_t& miniPFRelIso_chg;
    Int_t& pdgId;
    Bool_t& isHighPurityTrack;
    Bool_t& isPFcand;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PIsoTrack(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PIsoTrack> PIsoTrackArray;
  typedef panda::Collection<PIsoTrack> PIsoTrackCollection;
  typedef panda::Ref<PIsoTrack> PIsoTrackRef;
  typedef panda::RefVector<PIsoTrack> PIsoTrackRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PIsoTrack>::branchNames;
}

#endif

