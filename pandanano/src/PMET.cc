#include "../interface/PMET.h"
#include "../../Framework/interface/IOUtils.h"

namespace pandanano {

  /*static*/
  BranchList const PMET::branchNames{std::initializer_list<TString>{"phi", "pt", "sumEt"}, panda::utils::BranchName::kAttrName};

  PMET::PMET(char const* _name/* = ""*/) :
    Singlet(_name)
  {
  }

  PMET::PMET(PMET const& _src) :
    Singlet(_src.name_),
    phi(_src.phi),
    pt(_src.pt),
    sumEt(_src.sumEt)
  {
    phi = _src.phi;
    pt = _src.pt;
    sumEt = _src.sumEt;
  }

  PMET::~PMET()
  {
  }

  PMET&
  PMET::operator=(PMET const& _src)
  {
    phi = _src.phi;
    pt = _src.pt;
    sumEt = _src.sumEt;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  /*protected*/
  void
  PMET::doSetStatus_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    panda::utils::setStatus(_tree, BranchName(name_, "phi"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "pt"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "sumEt"), _branches);
  }

  /*protected*/
  void
  PMET::doSetAddress_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    panda::utils::setAddress(_tree, BranchName(name_, "phi"), &phi, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "pt"), &pt, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "sumEt"), &sumEt, _branches, _setStatus);
  }

  /*protected*/
  void
  PMET::doBook_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/)
  {
    panda::utils::book(_tree, BranchName(name_, "phi"), "", 'F', &phi, _branches);
    panda::utils::book(_tree, BranchName(name_, "pt"), "", 'F', &pt, _branches);
    panda::utils::book(_tree, BranchName(name_, "sumEt"), "", 'F', &sumEt, _branches);
  }

  /*protected*/
  void
  PMET::doInit_()
  {
    phi = 0.;
    pt = 0.;
    sumEt = 0.;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PMET::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PMET::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    panda::Singlet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "phi = " << phi << std::endl;
    _out << indentation << "pt = " << pt << std::endl;
    _out << indentation << "sumEt = " << sumEt << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

