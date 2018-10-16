#include "../interface/PGenInfo.h"
#include "../../Framework/interface/IOUtils.h"

namespace pandanano {

  /*static*/
  BranchList const PGenInfo::branchNames{std::initializer_list<TString>{"binvar", "scalePDF", "weight", "x1", "x2", "xpdf1", "xpdf2", "id1", "id2"}, panda::utils::BranchName::kAttrName};

  PGenInfo::PGenInfo(char const* _name/* = ""*/) :
    Singlet(_name)
  {
  }

  PGenInfo::PGenInfo(PGenInfo const& _src) :
    Singlet(_src.name_),
    binvar(_src.binvar),
    scalePDF(_src.scalePDF),
    weight(_src.weight),
    x1(_src.x1),
    x2(_src.x2),
    xpdf1(_src.xpdf1),
    xpdf2(_src.xpdf2),
    id1(_src.id1),
    id2(_src.id2)
  {
    binvar = _src.binvar;
    scalePDF = _src.scalePDF;
    weight = _src.weight;
    x1 = _src.x1;
    x2 = _src.x2;
    xpdf1 = _src.xpdf1;
    xpdf2 = _src.xpdf2;
    id1 = _src.id1;
    id2 = _src.id2;
  }

  PGenInfo::~PGenInfo()
  {
  }

  PGenInfo&
  PGenInfo::operator=(PGenInfo const& _src)
  {
    binvar = _src.binvar;
    scalePDF = _src.scalePDF;
    weight = _src.weight;
    x1 = _src.x1;
    x2 = _src.x2;
    xpdf1 = _src.xpdf1;
    xpdf2 = _src.xpdf2;
    id1 = _src.id1;
    id2 = _src.id2;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  /*protected*/
  void
  PGenInfo::doSetStatus_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    panda::utils::setStatus(_tree, BranchName(name_, "binvar"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "scalePDF"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "weight"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "x1"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "x2"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "xpdf1"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "xpdf2"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "id1"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "id2"), _branches);
  }

  /*protected*/
  void
  PGenInfo::doSetAddress_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    panda::utils::setAddress(_tree, BranchName(name_, "binvar"), &binvar, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "scalePDF"), &scalePDF, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "weight"), &weight, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "x1"), &x1, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "x2"), &x2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "xpdf1"), &xpdf1, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "xpdf2"), &xpdf2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "id1"), &id1, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "id2"), &id2, _branches, _setStatus);
  }

  /*protected*/
  void
  PGenInfo::doBook_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/)
  {
    panda::utils::book(_tree, BranchName(name_, "binvar"), "", 'F', &binvar, _branches);
    panda::utils::book(_tree, BranchName(name_, "scalePDF"), "", 'F', &scalePDF, _branches);
    panda::utils::book(_tree, BranchName(name_, "weight"), "", 'F', &weight, _branches);
    panda::utils::book(_tree, BranchName(name_, "x1"), "", 'F', &x1, _branches);
    panda::utils::book(_tree, BranchName(name_, "x2"), "", 'F', &x2, _branches);
    panda::utils::book(_tree, BranchName(name_, "xpdf1"), "", 'F', &xpdf1, _branches);
    panda::utils::book(_tree, BranchName(name_, "xpdf2"), "", 'F', &xpdf2, _branches);
    panda::utils::book(_tree, BranchName(name_, "id1"), "", 'I', &id1, _branches);
    panda::utils::book(_tree, BranchName(name_, "id2"), "", 'I', &id2, _branches);
  }

  /*protected*/
  void
  PGenInfo::doInit_()
  {
    binvar = 0.;
    scalePDF = 0.;
    weight = 0.;
    x1 = 0.;
    x2 = 0.;
    xpdf1 = 0.;
    xpdf2 = 0.;
    id1 = 0;
    id2 = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PGenInfo::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PGenInfo::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    panda::Singlet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "binvar = " << binvar << std::endl;
    _out << indentation << "scalePDF = " << scalePDF << std::endl;
    _out << indentation << "weight = " << weight << std::endl;
    _out << indentation << "x1 = " << x1 << std::endl;
    _out << indentation << "x2 = " << x2 << std::endl;
    _out << indentation << "xpdf1 = " << xpdf1 << std::endl;
    _out << indentation << "xpdf2 = " << xpdf2 << std::endl;
    _out << indentation << "id1 = " << id1 << std::endl;
    _out << indentation << "id2 = " << id2 << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

