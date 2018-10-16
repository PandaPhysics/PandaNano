#ifndef pandanano_PParticle_h
#define pandanano_PParticle_h

#include "Constants.h"
#include "BranchName.h"
#include "../../Framework/interface/Element.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PParticle : public panda::Element {
  public:
    struct datastore : public panda::Element::datastore {
      datastore() : panda::Element::datastore() {}
      ~datastore() { deallocate(); }

      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, panda::utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, panda::utils::BranchList const& = {"*"}, BookAs = aCollection) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef panda::Array<PParticle> array_type;
    typedef panda::Collection<PParticle> collection_type;

    typedef panda::Element base_type;

    typedef pandanano::BranchName BranchName;
    typedef pandanano::BranchList BranchList;

    PParticle(char const* name = "");
    PParticle(PParticle const&);
    PParticle(datastore&, UInt_t idx);
    ~PParticle();
    PParticle& operator=(PParticle const&);
    void destructor(Bool_t recursive = kFALSE);

    panda::utils::BranchList const& getBranchNames() const override { return PParticle::branchNames; }

    static TString typeName() { return "PParticle"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    virtual TLorentzVector p4() const { TLorentzVector p4; p4.SetPtEtaPhiM(pt, eta, phi, 0.); return p4; }
    virtual double e() const { return p(); }
    double p() const { return pt * std::cosh(eta); }
    double px() const { return pt * std::cos(phi); }
    double py() const { return pt * std::sin(phi); }
    double pz() const { return pt * std::sinh(eta); }
    double dEta(PParticle const& p) const { return eta - p.eta; }
    double dPhi(PParticle const& p) const { return TVector2::Phi_mpi_pi(phi - p.phi); }
    double dR2(PParticle const& p) const { double d1(dEta(p)); double d2(dPhi(p)); return d1 * d1 + d2 * d2; }
    double dR(PParticle const& p) const { return std::sqrt(dR2(p)); }
    virtual void setPtEtaPhiM(double _pt, double _eta, double _phi, double);
    virtual void setXYZE(double px, double py, double pz, double);

    Float_t& pt;
    Float_t& eta;
    Float_t& phi;

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    PParticle(panda::ArrayBase*);

    void doInit_() override;
  };

  typedef panda::Array<PParticle> PParticleArray;
  typedef panda::Collection<PParticle> PParticleCollection;
  typedef panda::Ref<PParticle> PParticleRef;
  typedef panda::RefVector<PParticle> PParticleRefVector;

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

namespace panda {
  // Template specialization declaration
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PParticle>::branchNames;
}

#endif

