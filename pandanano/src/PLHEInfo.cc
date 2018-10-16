#include "../interface/PLHEInfo.h"
#include "../../Framework/interface/IOUtils.h"

namespace pandanano {

  /*static*/
  BranchList const PLHEInfo::branchNames{std::initializer_list<TString>{"HT", "HTIncoming", "Vpt", "Njets", "Nb", "Nc", "Nuds", "Nglu", "NpNLO", "NpLO"}, panda::utils::BranchName::kAttrName};

  PLHEInfo::PLHEInfo(char const* _name/* = ""*/) :
    Singlet(_name)
  {
  }

  PLHEInfo::PLHEInfo(PLHEInfo const& _src) :
    Singlet(_src.name_),
    HT(_src.HT),
    HTIncoming(_src.HTIncoming),
    Vpt(_src.Vpt),
    Njets(_src.Njets),
    Nb(_src.Nb),
    Nc(_src.Nc),
    Nuds(_src.Nuds),
    Nglu(_src.Nglu),
    NpNLO(_src.NpNLO),
    NpLO(_src.NpLO)
  {
    HT = _src.HT;
    HTIncoming = _src.HTIncoming;
    Vpt = _src.Vpt;
    Njets = _src.Njets;
    Nb = _src.Nb;
    Nc = _src.Nc;
    Nuds = _src.Nuds;
    Nglu = _src.Nglu;
    NpNLO = _src.NpNLO;
    NpLO = _src.NpLO;
  }

  PLHEInfo::~PLHEInfo()
  {
  }

  PLHEInfo&
  PLHEInfo::operator=(PLHEInfo const& _src)
  {
    HT = _src.HT;
    HTIncoming = _src.HTIncoming;
    Vpt = _src.Vpt;
    Njets = _src.Njets;
    Nb = _src.Nb;
    Nc = _src.Nc;
    Nuds = _src.Nuds;
    Nglu = _src.Nglu;
    NpNLO = _src.NpNLO;
    NpLO = _src.NpLO;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  /*protected*/
  void
  PLHEInfo::doSetStatus_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    panda::utils::setStatus(_tree, BranchName(name_, "HT"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "HTIncoming"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "Vpt"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "Njets"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "Nb"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "Nc"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "Nuds"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "Nglu"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "NpNLO"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "NpLO"), _branches);
  }

  /*protected*/
  void
  PLHEInfo::doSetAddress_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    panda::utils::setAddress(_tree, BranchName(name_, "HT"), &HT, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "HTIncoming"), &HTIncoming, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "Vpt"), &Vpt, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "Njets"), &Njets, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "Nb"), &Nb, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "Nc"), &Nc, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "Nuds"), &Nuds, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "Nglu"), &Nglu, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "NpNLO"), &NpNLO, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "NpLO"), &NpLO, _branches, _setStatus);
  }

  /*protected*/
  void
  PLHEInfo::doBook_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/)
  {
    panda::utils::book(_tree, BranchName(name_, "HT"), "", 'F', &HT, _branches);
    panda::utils::book(_tree, BranchName(name_, "HTIncoming"), "", 'F', &HTIncoming, _branches);
    panda::utils::book(_tree, BranchName(name_, "Vpt"), "", 'F', &Vpt, _branches);
    panda::utils::book(_tree, BranchName(name_, "Njets"), "", 'b', &Njets, _branches);
    panda::utils::book(_tree, BranchName(name_, "Nb"), "", 'b', &Nb, _branches);
    panda::utils::book(_tree, BranchName(name_, "Nc"), "", 'b', &Nc, _branches);
    panda::utils::book(_tree, BranchName(name_, "Nuds"), "", 'b', &Nuds, _branches);
    panda::utils::book(_tree, BranchName(name_, "Nglu"), "", 'b', &Nglu, _branches);
    panda::utils::book(_tree, BranchName(name_, "NpNLO"), "", 'b', &NpNLO, _branches);
    panda::utils::book(_tree, BranchName(name_, "NpLO"), "", 'b', &NpLO, _branches);
  }

  /*protected*/
  void
  PLHEInfo::doInit_()
  {
    HT = 0.;
    HTIncoming = 0.;
    Vpt = 0.;
    Njets = 0;
    Nb = 0;
    Nc = 0;
    Nuds = 0;
    Nglu = 0;
    NpNLO = 0;
    NpLO = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PLHEInfo::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PLHEInfo::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    panda::Singlet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "HT = " << HT << std::endl;
    _out << indentation << "HTIncoming = " << HTIncoming << std::endl;
    _out << indentation << "Vpt = " << Vpt << std::endl;
    _out << indentation << "Njets = " << static_cast<const UInt_t>(Njets) << std::endl;
    _out << indentation << "Nb = " << static_cast<const UInt_t>(Nb) << std::endl;
    _out << indentation << "Nc = " << static_cast<const UInt_t>(Nc) << std::endl;
    _out << indentation << "Nuds = " << static_cast<const UInt_t>(Nuds) << std::endl;
    _out << indentation << "Nglu = " << static_cast<const UInt_t>(Nglu) << std::endl;
    _out << indentation << "NpNLO = " << static_cast<const UInt_t>(NpNLO) << std::endl;
    _out << indentation << "NpLO = " << static_cast<const UInt_t>(NpLO) << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

