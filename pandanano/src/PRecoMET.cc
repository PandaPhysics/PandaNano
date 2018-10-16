#include "../interface/PRecoMET.h"
#include "../../Framework/interface/IOUtils.h"

namespace pandanano {

  /*static*/
  BranchList const PRecoMET::branchNames{std::initializer_list<TString>{"phi", "pt", "sumEt", "MetUnclustEnUpDeltaX", "MetUnclustEnUpDeltaY", "covXX", "covXY", "covYY", "significance", "fiducialGenPhi", "fiducialGenPt"}, panda::utils::BranchName::kAttrName};

  PRecoMET::PRecoMET(char const* _name/* = ""*/) :
    PMET(_name)
  {
  }

  PRecoMET::PRecoMET(PRecoMET const& _src) :
    PMET(_src.name_),
    MetUnclustEnUpDeltaX(_src.MetUnclustEnUpDeltaX),
    MetUnclustEnUpDeltaY(_src.MetUnclustEnUpDeltaY),
    covXX(_src.covXX),
    covXY(_src.covXY),
    covYY(_src.covYY),
    significance(_src.significance),
    fiducialGenPhi(_src.fiducialGenPhi),
    fiducialGenPt(_src.fiducialGenPt)
  {
    MetUnclustEnUpDeltaX = _src.MetUnclustEnUpDeltaX;
    MetUnclustEnUpDeltaY = _src.MetUnclustEnUpDeltaY;
    covXX = _src.covXX;
    covXY = _src.covXY;
    covYY = _src.covYY;
    significance = _src.significance;
    fiducialGenPhi = _src.fiducialGenPhi;
    fiducialGenPt = _src.fiducialGenPt;
  }

  PRecoMET::~PRecoMET()
  {
  }

  PRecoMET&
  PRecoMET::operator=(PRecoMET const& _src)
  {
    PMET::operator=(_src);

    MetUnclustEnUpDeltaX = _src.MetUnclustEnUpDeltaX;
    MetUnclustEnUpDeltaY = _src.MetUnclustEnUpDeltaY;
    covXX = _src.covXX;
    covXY = _src.covXY;
    covYY = _src.covYY;
    significance = _src.significance;
    fiducialGenPhi = _src.fiducialGenPhi;
    fiducialGenPt = _src.fiducialGenPt;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  /*protected*/
  void
  PRecoMET::doSetStatus_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    PMET::doSetStatus_(_tree, _branches);

    panda::utils::setStatus(_tree, BranchName(name_, "MetUnclustEnUpDeltaX"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "MetUnclustEnUpDeltaY"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "covXX"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "covXY"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "covYY"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "significance"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "fiducialGenPhi"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "fiducialGenPt"), _branches);
  }

  /*protected*/
  void
  PRecoMET::doSetAddress_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PMET::doSetAddress_(_tree, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(name_, "MetUnclustEnUpDeltaX"), &MetUnclustEnUpDeltaX, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "MetUnclustEnUpDeltaY"), &MetUnclustEnUpDeltaY, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "covXX"), &covXX, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "covXY"), &covXY, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "covYY"), &covYY, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "significance"), &significance, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "fiducialGenPhi"), &fiducialGenPhi, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "fiducialGenPt"), &fiducialGenPt, _branches, _setStatus);
  }

  /*protected*/
  void
  PRecoMET::doBook_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/)
  {
    PMET::doBook_(_tree, _branches);

    panda::utils::book(_tree, BranchName(name_, "MetUnclustEnUpDeltaX"), "", 'F', &MetUnclustEnUpDeltaX, _branches);
    panda::utils::book(_tree, BranchName(name_, "MetUnclustEnUpDeltaY"), "", 'F', &MetUnclustEnUpDeltaY, _branches);
    panda::utils::book(_tree, BranchName(name_, "covXX"), "", 'F', &covXX, _branches);
    panda::utils::book(_tree, BranchName(name_, "covXY"), "", 'F', &covXY, _branches);
    panda::utils::book(_tree, BranchName(name_, "covYY"), "", 'F', &covYY, _branches);
    panda::utils::book(_tree, BranchName(name_, "significance"), "", 'F', &significance, _branches);
    panda::utils::book(_tree, BranchName(name_, "fiducialGenPhi"), "", 'F', &fiducialGenPhi, _branches);
    panda::utils::book(_tree, BranchName(name_, "fiducialGenPt"), "", 'F', &fiducialGenPt, _branches);
  }

  /*protected*/
  void
  PRecoMET::doInit_()
  {
    PMET::doInit_();

    MetUnclustEnUpDeltaX = 0.;
    MetUnclustEnUpDeltaY = 0.;
    covXX = 0.;
    covXY = 0.;
    covYY = 0.;
    significance = 0.;
    fiducialGenPhi = 0.;
    fiducialGenPt = 0.;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PRecoMET::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PRecoMET::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PMET::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "MetUnclustEnUpDeltaX = " << MetUnclustEnUpDeltaX << std::endl;
    _out << indentation << "MetUnclustEnUpDeltaY = " << MetUnclustEnUpDeltaY << std::endl;
    _out << indentation << "covXX = " << covXX << std::endl;
    _out << indentation << "covXY = " << covXY << std::endl;
    _out << indentation << "covYY = " << covYY << std::endl;
    _out << indentation << "significance = " << significance << std::endl;
    _out << indentation << "fiducialGenPhi = " << fiducialGenPhi << std::endl;
    _out << indentation << "fiducialGenPt = " << fiducialGenPt << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

