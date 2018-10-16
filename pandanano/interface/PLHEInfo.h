#ifndef pandanano_PLHEInfo_h
#define pandanano_PLHEInfo_h

#include "Constants.h"
#include "BranchName.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace pandanano {

  class PLHEInfo : public panda::Singlet {
  public:

    typedef panda::Singlet base_type;

    PLHEInfo(char const* name = "");
    PLHEInfo(PLHEInfo const&);
    ~PLHEInfo();
    PLHEInfo& operator=(PLHEInfo const&);

    panda::utils::BranchList const& getBranchNames() const override { return PLHEInfo::branchNames; }

    static TString typeName() { return "PLHEInfo"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout, UInt_t indent = 0) const override;

    Float_t HT{};
    Float_t HTIncoming{};
    Float_t Vpt{};
    UChar_t Njets{};
    UChar_t Nb{};
    UChar_t Nc{};
    UChar_t Nuds{};
    UChar_t Nglu{};
    UChar_t NpNLO{};
    UChar_t NpLO{};

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

