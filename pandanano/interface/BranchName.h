#ifndef pandanano_BranchName_h
#define pandanano_BranchName_h

#include "../../Framework/interface/BranchName.h"
#include "../../Framework/interface/BranchList.h"

namespace pandanano {

  class BranchNameSyntax {
  public:
    static TString generate(TString const&, TString const&);
    static std::pair<TString, TString> parse(TString const&);
  };

  class SizeBranchNameSyntax {
  public:
    static TString generate(TString const&, TString const&);
    static std::pair<TString, TString> parse(TString const&);
  };

  typedef panda::utils::BranchNameImpl<BranchNameSyntax, SizeBranchNameSyntax> BranchName;
  typedef panda::utils::BranchListImpl<BranchNameSyntax, SizeBranchNameSyntax> BranchList;

}

#endif

