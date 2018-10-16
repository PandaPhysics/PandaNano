#include "../interface/PPileupInfo.h"
#include "../../Framework/interface/IOUtils.h"

namespace pandanano {

  /*static*/
  BranchList const PPileupInfo::branchNames{std::initializer_list<TString>{"nTrueInt", "nPU", "sumEOOT", "sumLOOT"}, panda::utils::BranchName::kAttrName};

  PPileupInfo::PPileupInfo(char const* _name/* = ""*/) :
    Singlet(_name)
  {
  }

  PPileupInfo::PPileupInfo(PPileupInfo const& _src) :
    Singlet(_src.name_),
    nTrueInt(_src.nTrueInt),
    nPU(_src.nPU),
    sumEOOT(_src.sumEOOT),
    sumLOOT(_src.sumLOOT)
  {
    nTrueInt = _src.nTrueInt;
    nPU = _src.nPU;
    sumEOOT = _src.sumEOOT;
    sumLOOT = _src.sumLOOT;
  }

  PPileupInfo::~PPileupInfo()
  {
  }

  PPileupInfo&
  PPileupInfo::operator=(PPileupInfo const& _src)
  {
    nTrueInt = _src.nTrueInt;
    nPU = _src.nPU;
    sumEOOT = _src.sumEOOT;
    sumLOOT = _src.sumLOOT;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  /*protected*/
  void
  PPileupInfo::doSetStatus_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    panda::utils::setStatus(_tree, BranchName(name_, "nTrueInt"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "nPU"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "sumEOOT"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "sumLOOT"), _branches);
  }

  /*protected*/
  void
  PPileupInfo::doSetAddress_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    panda::utils::setAddress(_tree, BranchName(name_, "nTrueInt"), &nTrueInt, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "nPU"), &nPU, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "sumEOOT"), &sumEOOT, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "sumLOOT"), &sumLOOT, _branches, _setStatus);
  }

  /*protected*/
  void
  PPileupInfo::doBook_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/)
  {
    panda::utils::book(_tree, BranchName(name_, "nTrueInt"), "", 'F', &nTrueInt, _branches);
    panda::utils::book(_tree, BranchName(name_, "nPU"), "", 'I', &nPU, _branches);
    panda::utils::book(_tree, BranchName(name_, "sumEOOT"), "", 'I', &sumEOOT, _branches);
    panda::utils::book(_tree, BranchName(name_, "sumLOOT"), "", 'I', &sumLOOT, _branches);
  }

  /*protected*/
  void
  PPileupInfo::doInit_()
  {
    nTrueInt = 0.;
    nPU = 0;
    sumEOOT = 0;
    sumLOOT = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PPileupInfo::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PPileupInfo::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    panda::Singlet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "nTrueInt = " << nTrueInt << std::endl;
    _out << indentation << "nPU = " << nPU << std::endl;
    _out << indentation << "sumEOOT = " << sumEOOT << std::endl;
    _out << indentation << "sumLOOT = " << sumLOOT << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

