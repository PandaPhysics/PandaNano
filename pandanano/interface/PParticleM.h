#ifndef pandanano_PParticleM_h
#define pandanano_PParticleM_h

#include "Constants.h"
#include "BranchName.h"
#include "PParticle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PParticleM : public PParticle {
  public:
    struct datastore : public PParticle::datastore {
      datastore() : PParticle::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      Float_t* mass{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PParticleM> array_type;
    typedef panda::Collection<PParticleM> collection_type;

    typedef PParticle base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PParticleM(char const* name = "");
    PParticleM(PParticleM const&);
    PParticleM(datastore&, UInt_t idx);
    ~PParticleM();
    PParticleM& operator=(PParticleM const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PParticleM::branchNames; }

    static TString typeName() { return "PParticleM"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    double e() const override { double momentum(p()); return std::sqrt(momentum * momentum + mass * mass); }
    void setPtEtaPhiM(double _pt, double _eta, double _phi, double _mass) override;
    void setXYZE(double px, double py, double pz, double e) override;

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Float_t& mass;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PParticleM(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PParticleM> PParticleMArray;
  typedef panda::Collection<PParticleM> PParticleMCollection;
  typedef panda::Ref<PParticleM> PParticleMRef;
  typedef panda::RefVector<PParticleM> PParticleMRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PParticleM>::branchNames;
}

#endif

