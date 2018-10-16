#ifndef pandanano_PPileupInfo_h
#define pandanano_PPileupInfo_h

#include "Constants.h"
#include "BranchName.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PPileupInfo : public panda::Singlet {
  public:

    typedef panda::Singlet base_type;

    PPileupInfo(char const* name = "");
    PPileupInfo(PPileupInfo const&);
    ~PPileupInfo();
    PPileupInfo& operator=(PPileupInfo const&);

    panda::utils::BranchList const& getBranchNames() const override { return PPileupInfo::branchNames; }

    static TString typeName() { return "PPileupInfo"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    Float_t nTrueInt{};
    Int_t nPU{};
    Int_t sumEOOT{};
    Int_t sumLOOT{};

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

