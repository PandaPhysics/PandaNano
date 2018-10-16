#include "../interface/PBTagWeight.h"
#include "../../Framework/interface/IOUtils.h"

namespace pandanano {

  /*static*/
  BranchList const PBTagWeight::branchNames{std::initializer_list<TString>{"CSVV2", "DeepCSVB"}, panda::utils::BranchName::kAttrName};

  PBTagWeight::PBTagWeight(char const* _name/* = ""*/) :
    Singlet(_name)
  {
  }

  PBTagWeight::PBTagWeight(PBTagWeight const& _src) :
    Singlet(_src.name_),
    CSVV2(_src.CSVV2),
    DeepCSVB(_src.DeepCSVB)
  {
    CSVV2 = _src.CSVV2;
    DeepCSVB = _src.DeepCSVB;
  }

  PBTagWeight::~PBTagWeight()
  {
  }

  PBTagWeight&
  PBTagWeight::operator=(PBTagWeight const& _src)
  {
    CSVV2 = _src.CSVV2;
    DeepCSVB = _src.DeepCSVB;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  /*protected*/
  void
  PBTagWeight::doSetStatus_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    panda::utils::setStatus(_tree, BranchName(name_, "CSVV2"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "DeepCSVB"), _branches);
  }

  /*protected*/
  void
  PBTagWeight::doSetAddress_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    panda::utils::setAddress(_tree, BranchName(name_, "CSVV2"), &CSVV2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "DeepCSVB"), &DeepCSVB, _branches, _setStatus);
  }

  /*protected*/
  void
  PBTagWeight::doBook_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/)
  {
    panda::utils::book(_tree, BranchName(name_, "CSVV2"), "", 'F', &CSVV2, _branches);
    panda::utils::book(_tree, BranchName(name_, "DeepCSVB"), "", 'F', &DeepCSVB, _branches);
  }

  /*protected*/
  void
  PBTagWeight::doInit_()
  {
    CSVV2 = 0.;
    DeepCSVB = 0.;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PBTagWeight::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PBTagWeight::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    panda::Singlet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "CSVV2 = " << CSVV2 << std::endl;
    _out << indentation << "DeepCSVB = " << DeepCSVB << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

