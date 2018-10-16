#ifndef pandanano_PEventFilter_h
#define pandanano_PEventFilter_h

#include "Constants.h"
#include "BranchName.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PEventFilter : public panda::Singlet {
  public:

    typedef panda::Singlet base_type;

    PEventFilter(char const* name = "");
    PEventFilter(PEventFilter const&);
    ~PEventFilter();
    PEventFilter& operator=(PEventFilter const&);

    panda::utils::BranchList const& getBranchNames() const override { return PEventFilter::branchNames; }

    static TString typeName() { return "PEventFilter"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    Bool_t HBHENoiseFilter{};
    Bool_t HBHENoiseIsoFilter{};
    Bool_t CSCTightHaloFilter{};
    Bool_t CSCTightHaloTrkMuUnvetoFilter{};
    Bool_t CSCTightHalo2015Filter{};
    Bool_t globalTightHalo2016Filter{};
    Bool_t globalSuperTightHalo2016Filter{};
    Bool_t HcalStripHaloFilter{};
    Bool_t hcalLaserEventFilter{};
    Bool_t EcalDeadCellTriggerPrimitiveFilter{};
    Bool_t EcalDeadCellBoundaryEnergyFilter{};
    Bool_t ecalBadCalibFilter{};
    Bool_t goodVertices{};
    Bool_t eeBadScFilter{};
    Bool_t ecalLaserCorrFilter{};
    Bool_t trkPOGFilters{};
    Bool_t chargedHadronTrackResolutionFilter{};
    Bool_t muonBadTrackFilter{};
    Bool_t BadChargedCandidateFilter{};
    Bool_t BadPFMuonFilter{};
    Bool_t BadChargedCandidateSummer16Filter{};
    Bool_t BadPFMuonSummer16Filter{};
    Bool_t trkPOG_manystripclus53X{};
    Bool_t trkPOG_toomanystripclus53X{};
    Bool_t trkPOG_logErrorTooManyClusters{};
    Bool_t METFilters{};

    /* BEGIN CUSTOM classdef */
    /* END CUSTOM */

    static pandanano::BranchList const branchNames;

  protected:

    void doSetStatus_(TTree&, panda::utils::BranchList const&) override;
    void doSetAddress_(TTree&, panda::utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, panda::utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

#endif

