#ifndef pandanano_PBTagWeight_h
#define pandanano_PBTagWeight_h

#include "Constants.h"
#include "BranchName.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PBTagWeight : public panda::Singlet {
  public:

    typedef panda::Singlet base_type;

    PBTagWeight(char const* name = "");
    PBTagWeight(PBTagWeight const&);
    ~PBTagWeight();
    PBTagWeight& operator=(PBTagWeight const&);

    panda::utils::BranchList const& getBranchNames() const override { return PBTagWeight::branchNames; }

    static TString typeName() { return "PBTagWeight"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    Float_t CSVV2{};
    Float_t DeepCSVB{};

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

