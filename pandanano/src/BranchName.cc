#include "../interface/BranchName.h"

namespace pandanano {

  /*static*/
  TString
  BranchNameSyntax::generate(TString const& _obj, TString const& _br)
  {
    if (_br.Length() == 0)
      return _obj;
    else
      return _obj + "_" + _br;
  }

  /*static*/
  std::pair<TString, TString>
  BranchNameSyntax::parse(TString const& _str)
  {
    TString fullName(_str);
    int pos(fullName.Index("_"));
    if (pos == -1)
      return std::pair<TString, TString>(fullName, "");
    else {
      return std::pair<TString, TString>(fullName(0, pos), fullName(pos + 1, fullName.Length()));
    }
  }

  /*static*/
  TString
  SizeBranchNameSyntax::generate(TString const& _obj, TString const& _br)
  {
    return "n" + _obj;
  }

  /*static*/
  std::pair<TString, TString>
  SizeBranchNameSyntax::parse(TString const& _str)
  {
    if (_str(0) != 'n')
      return std::pair<TString, TString>();
    else
      return std::pair<TString, TString>(_str(1, _str.Length()), "size");
  }

}

