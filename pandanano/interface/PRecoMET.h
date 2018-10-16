#ifndef pandanano_PRecoMET_h
#define pandanano_PRecoMET_h

#include "Constants.h"
#include "BranchName.h"
#include "PMET.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PRecoMET : public PMET {
  public:

    typedef PMET base_type;

    PRecoMET(char const* name = "");
    PRecoMET(PRecoMET const&);
    ~PRecoMET();
    PRecoMET& operator=(PRecoMET const&);

    panda::utils::BranchList const& getBranchNames() const override { return PRecoMET::branchNames; }

    static TString typeName() { return "PRecoMET"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    /* PMET
    Float_t phi{};
    Float_t pt{};
    Float_t sumEt{};
    */
    Float_t MetUnclustEnUpDeltaX{};
    Float_t MetUnclustEnUpDeltaY{};
    Float_t covXX{};
    Float_t covXY{};
    Float_t covYY{};
    Float_t significance{};
    Float_t fiducialGenPhi{};
    Float_t fiducialGenPt{};

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

