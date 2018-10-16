#include "../interface/PPrimaryVertex.h"
#include "../../Framework/interface/IOUtils.h"

namespace pandanano {

  /*static*/
  BranchList const PPrimaryVertex::branchNames{std::initializer_list<TString>{"ndof", "x", "y", "z", "chi2", "score", "npvs", "npvsGood"}, panda::utils::BranchName::kAttrName};

  PPrimaryVertex::PPrimaryVertex(char const* _name/* = ""*/) :
    Singlet(_name)
  {
  }

  PPrimaryVertex::PPrimaryVertex(PPrimaryVertex const& _src) :
    Singlet(_src.name_),
    ndof(_src.ndof),
    x(_src.x),
    y(_src.y),
    z(_src.z),
    chi2(_src.chi2),
    score(_src.score),
    npvs(_src.npvs),
    npvsGood(_src.npvsGood)
  {
    ndof = _src.ndof;
    x = _src.x;
    y = _src.y;
    z = _src.z;
    chi2 = _src.chi2;
    score = _src.score;
    npvs = _src.npvs;
    npvsGood = _src.npvsGood;
  }

  PPrimaryVertex::~PPrimaryVertex()
  {
  }

  PPrimaryVertex&
  PPrimaryVertex::operator=(PPrimaryVertex const& _src)
  {
    ndof = _src.ndof;
    x = _src.x;
    y = _src.y;
    z = _src.z;
    chi2 = _src.chi2;
    score = _src.score;
    npvs = _src.npvs;
    npvsGood = _src.npvsGood;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  /*protected*/
  void
  PPrimaryVertex::doSetStatus_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    panda::utils::setStatus(_tree, BranchName(name_, "ndof"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "x"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "y"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "z"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "chi2"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "score"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "npvs"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "npvsGood"), _branches);
  }

  /*protected*/
  void
  PPrimaryVertex::doSetAddress_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    panda::utils::setAddress(_tree, BranchName(name_, "ndof"), &ndof, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "x"), &x, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "y"), &y, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "z"), &z, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "chi2"), &chi2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "score"), &score, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "npvs"), &npvs, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "npvsGood"), &npvsGood, _branches, _setStatus);
  }

  /*protected*/
  void
  PPrimaryVertex::doBook_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/)
  {
    panda::utils::book(_tree, BranchName(name_, "ndof"), "", 'F', &ndof, _branches);
    panda::utils::book(_tree, BranchName(name_, "x"), "", 'F', &x, _branches);
    panda::utils::book(_tree, BranchName(name_, "y"), "", 'F', &y, _branches);
    panda::utils::book(_tree, BranchName(name_, "z"), "", 'F', &z, _branches);
    panda::utils::book(_tree, BranchName(name_, "chi2"), "", 'F', &chi2, _branches);
    panda::utils::book(_tree, BranchName(name_, "score"), "", 'F', &score, _branches);
    panda::utils::book(_tree, BranchName(name_, "npvs"), "", 'I', &npvs, _branches);
    panda::utils::book(_tree, BranchName(name_, "npvsGood"), "", 'I', &npvsGood, _branches);
  }

  /*protected*/
  void
  PPrimaryVertex::doInit_()
  {
    ndof = 0.;
    x = 0.;
    y = 0.;
    z = 0.;
    chi2 = 0.;
    score = 0.;
    npvs = 0;
    npvsGood = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PPrimaryVertex::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PPrimaryVertex::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    panda::Singlet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "ndof = " << ndof << std::endl;
    _out << indentation << "x = " << x << std::endl;
    _out << indentation << "y = " << y << std::endl;
    _out << indentation << "z = " << z << std::endl;
    _out << indentation << "chi2 = " << chi2 << std::endl;
    _out << indentation << "score = " << score << std::endl;
    _out << indentation << "npvs = " << npvs << std::endl;
    _out << indentation << "npvsGood = " << npvsGood << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

