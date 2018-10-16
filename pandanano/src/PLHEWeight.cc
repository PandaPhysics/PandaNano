#include "../interface/PLHEWeight.h"
#include "../../Framework/interface/IOUtils.h"

namespace pandanano {

  /*static*/
  BranchList const PLHEWeight::branchNames{std::initializer_list<TString>{"originalXWGTUP"}, panda::utils::BranchName::kAttrName};

  PLHEWeight::PLHEWeight(char const* _name/* = ""*/) :
    Singlet(_name)
  {
  }

  PLHEWeight::PLHEWeight(PLHEWeight const& _src) :
    Singlet(_src.name_),
    originalXWGTUP(_src.originalXWGTUP)
  {
    originalXWGTUP = _src.originalXWGTUP;
  }

  PLHEWeight::~PLHEWeight()
  {
  }

  PLHEWeight&
  PLHEWeight::operator=(PLHEWeight const& _src)
  {
    originalXWGTUP = _src.originalXWGTUP;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  /*protected*/
  void
  PLHEWeight::doSetStatus_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    panda::utils::setStatus(_tree, BranchName(name_, "originalXWGTUP"), _branches);
  }

  /*protected*/
  void
  PLHEWeight::doSetAddress_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    panda::utils::setAddress(_tree, BranchName(name_, "originalXWGTUP"), &originalXWGTUP, _branches, _setStatus);
  }

  /*protected*/
  void
  PLHEWeight::doBook_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/)
  {
    panda::utils::book(_tree, BranchName(name_, "originalXWGTUP"), "", 'F', &originalXWGTUP, _branches);
  }

  /*protected*/
  void
  PLHEWeight::doInit_()
  {
    originalXWGTUP = 0.;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PLHEWeight::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PLHEWeight::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    panda::Singlet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "originalXWGTUP = " << originalXWGTUP << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

