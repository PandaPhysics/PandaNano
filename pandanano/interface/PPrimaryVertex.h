#ifndef pandanano_PPrimaryVertex_h
#define pandanano_PPrimaryVertex_h

#include "Constants.h"
#include "BranchName.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PPrimaryVertex : public panda::Singlet {
  public:

    typedef panda::Singlet base_type;

    PPrimaryVertex(char const* name = "");
    PPrimaryVertex(PPrimaryVertex const&);
    ~PPrimaryVertex();
    PPrimaryVertex& operator=(PPrimaryVertex const&);

    panda::utils::BranchList const& getBranchNames() const override { return PPrimaryVertex::branchNames; }

    static TString typeName() { return "PPrimaryVertex"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    Float_t ndof{};
    Float_t x{};
    Float_t y{};
    Float_t z{};
    Float_t chi2{};
    Float_t score{};
    Int_t npvs{};
    Int_t npvsGood{};

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

