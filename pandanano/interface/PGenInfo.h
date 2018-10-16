#ifndef pandanano_PGenInfo_h
#define pandanano_PGenInfo_h

#include "Constants.h"
#include "BranchName.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PGenInfo : public panda::Singlet {
  public:

    typedef panda::Singlet base_type;

    PGenInfo(char const* name = "");
    PGenInfo(PGenInfo const&);
    ~PGenInfo();
    PGenInfo& operator=(PGenInfo const&);

    panda::utils::BranchList const& getBranchNames() const override { return PGenInfo::branchNames; }

    static TString typeName() { return "PGenInfo"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    Float_t binvar{};
    Float_t scalePDF{};
    Float_t weight{};
    Float_t x1{};
    Float_t x2{};
    Float_t xpdf1{};
    Float_t xpdf2{};
    Int_t id1{};
    Int_t id2{};

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

