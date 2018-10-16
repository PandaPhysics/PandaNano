#include "../interface/PEventFilter.h"
#include "../../Framework/interface/IOUtils.h"

namespace pandanano {

  /*static*/
  BranchList const PEventFilter::branchNames{std::initializer_list<TString>{"HBHENoiseFilter", "HBHENoiseIsoFilter", "CSCTightHaloFilter", "CSCTightHaloTrkMuUnvetoFilter", "CSCTightHalo2015Filter", "globalTightHalo2016Filter", "globalSuperTightHalo2016Filter", "HcalStripHaloFilter", "hcalLaserEventFilter", "EcalDeadCellTriggerPrimitiveFilter", "EcalDeadCellBoundaryEnergyFilter", "ecalBadCalibFilter", "goodVertices", "eeBadScFilter", "ecalLaserCorrFilter", "trkPOGFilters", "chargedHadronTrackResolutionFilter", "muonBadTrackFilter", "BadChargedCandidateFilter", "BadPFMuonFilter", "BadChargedCandidateSummer16Filter", "BadPFMuonSummer16Filter", "trkPOG_manystripclus53X", "trkPOG_toomanystripclus53X", "trkPOG_logErrorTooManyClusters", "METFilters"}, panda::utils::BranchName::kAttrName};

  PEventFilter::PEventFilter(char const* _name/* = ""*/) :
    Singlet(_name)
  {
  }

  PEventFilter::PEventFilter(PEventFilter const& _src) :
    Singlet(_src.name_),
    HBHENoiseFilter(_src.HBHENoiseFilter),
    HBHENoiseIsoFilter(_src.HBHENoiseIsoFilter),
    CSCTightHaloFilter(_src.CSCTightHaloFilter),
    CSCTightHaloTrkMuUnvetoFilter(_src.CSCTightHaloTrkMuUnvetoFilter),
    CSCTightHalo2015Filter(_src.CSCTightHalo2015Filter),
    globalTightHalo2016Filter(_src.globalTightHalo2016Filter),
    globalSuperTightHalo2016Filter(_src.globalSuperTightHalo2016Filter),
    HcalStripHaloFilter(_src.HcalStripHaloFilter),
    hcalLaserEventFilter(_src.hcalLaserEventFilter),
    EcalDeadCellTriggerPrimitiveFilter(_src.EcalDeadCellTriggerPrimitiveFilter),
    EcalDeadCellBoundaryEnergyFilter(_src.EcalDeadCellBoundaryEnergyFilter),
    ecalBadCalibFilter(_src.ecalBadCalibFilter),
    goodVertices(_src.goodVertices),
    eeBadScFilter(_src.eeBadScFilter),
    ecalLaserCorrFilter(_src.ecalLaserCorrFilter),
    trkPOGFilters(_src.trkPOGFilters),
    chargedHadronTrackResolutionFilter(_src.chargedHadronTrackResolutionFilter),
    muonBadTrackFilter(_src.muonBadTrackFilter),
    BadChargedCandidateFilter(_src.BadChargedCandidateFilter),
    BadPFMuonFilter(_src.BadPFMuonFilter),
    BadChargedCandidateSummer16Filter(_src.BadChargedCandidateSummer16Filter),
    BadPFMuonSummer16Filter(_src.BadPFMuonSummer16Filter),
    trkPOG_manystripclus53X(_src.trkPOG_manystripclus53X),
    trkPOG_toomanystripclus53X(_src.trkPOG_toomanystripclus53X),
    trkPOG_logErrorTooManyClusters(_src.trkPOG_logErrorTooManyClusters),
    METFilters(_src.METFilters)
  {
    HBHENoiseFilter = _src.HBHENoiseFilter;
    HBHENoiseIsoFilter = _src.HBHENoiseIsoFilter;
    CSCTightHaloFilter = _src.CSCTightHaloFilter;
    CSCTightHaloTrkMuUnvetoFilter = _src.CSCTightHaloTrkMuUnvetoFilter;
    CSCTightHalo2015Filter = _src.CSCTightHalo2015Filter;
    globalTightHalo2016Filter = _src.globalTightHalo2016Filter;
    globalSuperTightHalo2016Filter = _src.globalSuperTightHalo2016Filter;
    HcalStripHaloFilter = _src.HcalStripHaloFilter;
    hcalLaserEventFilter = _src.hcalLaserEventFilter;
    EcalDeadCellTriggerPrimitiveFilter = _src.EcalDeadCellTriggerPrimitiveFilter;
    EcalDeadCellBoundaryEnergyFilter = _src.EcalDeadCellBoundaryEnergyFilter;
    ecalBadCalibFilter = _src.ecalBadCalibFilter;
    goodVertices = _src.goodVertices;
    eeBadScFilter = _src.eeBadScFilter;
    ecalLaserCorrFilter = _src.ecalLaserCorrFilter;
    trkPOGFilters = _src.trkPOGFilters;
    chargedHadronTrackResolutionFilter = _src.chargedHadronTrackResolutionFilter;
    muonBadTrackFilter = _src.muonBadTrackFilter;
    BadChargedCandidateFilter = _src.BadChargedCandidateFilter;
    BadPFMuonFilter = _src.BadPFMuonFilter;
    BadChargedCandidateSummer16Filter = _src.BadChargedCandidateSummer16Filter;
    BadPFMuonSummer16Filter = _src.BadPFMuonSummer16Filter;
    trkPOG_manystripclus53X = _src.trkPOG_manystripclus53X;
    trkPOG_toomanystripclus53X = _src.trkPOG_toomanystripclus53X;
    trkPOG_logErrorTooManyClusters = _src.trkPOG_logErrorTooManyClusters;
    METFilters = _src.METFilters;
  }

  PEventFilter::~PEventFilter()
  {
  }

  PEventFilter&
  PEventFilter::operator=(PEventFilter const& _src)
  {
    HBHENoiseFilter = _src.HBHENoiseFilter;
    HBHENoiseIsoFilter = _src.HBHENoiseIsoFilter;
    CSCTightHaloFilter = _src.CSCTightHaloFilter;
    CSCTightHaloTrkMuUnvetoFilter = _src.CSCTightHaloTrkMuUnvetoFilter;
    CSCTightHalo2015Filter = _src.CSCTightHalo2015Filter;
    globalTightHalo2016Filter = _src.globalTightHalo2016Filter;
    globalSuperTightHalo2016Filter = _src.globalSuperTightHalo2016Filter;
    HcalStripHaloFilter = _src.HcalStripHaloFilter;
    hcalLaserEventFilter = _src.hcalLaserEventFilter;
    EcalDeadCellTriggerPrimitiveFilter = _src.EcalDeadCellTriggerPrimitiveFilter;
    EcalDeadCellBoundaryEnergyFilter = _src.EcalDeadCellBoundaryEnergyFilter;
    ecalBadCalibFilter = _src.ecalBadCalibFilter;
    goodVertices = _src.goodVertices;
    eeBadScFilter = _src.eeBadScFilter;
    ecalLaserCorrFilter = _src.ecalLaserCorrFilter;
    trkPOGFilters = _src.trkPOGFilters;
    chargedHadronTrackResolutionFilter = _src.chargedHadronTrackResolutionFilter;
    muonBadTrackFilter = _src.muonBadTrackFilter;
    BadChargedCandidateFilter = _src.BadChargedCandidateFilter;
    BadPFMuonFilter = _src.BadPFMuonFilter;
    BadChargedCandidateSummer16Filter = _src.BadChargedCandidateSummer16Filter;
    BadPFMuonSummer16Filter = _src.BadPFMuonSummer16Filter;
    trkPOG_manystripclus53X = _src.trkPOG_manystripclus53X;
    trkPOG_toomanystripclus53X = _src.trkPOG_toomanystripclus53X;
    trkPOG_logErrorTooManyClusters = _src.trkPOG_logErrorTooManyClusters;
    METFilters = _src.METFilters;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  /*protected*/
  void
  PEventFilter::doSetStatus_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    panda::utils::setStatus(_tree, BranchName(name_, "HBHENoiseFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "HBHENoiseIsoFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "CSCTightHaloFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "CSCTightHaloTrkMuUnvetoFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "CSCTightHalo2015Filter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "globalTightHalo2016Filter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "globalSuperTightHalo2016Filter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "HcalStripHaloFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "hcalLaserEventFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "EcalDeadCellTriggerPrimitiveFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "EcalDeadCellBoundaryEnergyFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "ecalBadCalibFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "goodVertices"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "eeBadScFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "ecalLaserCorrFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "trkPOGFilters"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "chargedHadronTrackResolutionFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "muonBadTrackFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "BadChargedCandidateFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "BadPFMuonFilter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "BadChargedCandidateSummer16Filter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "BadPFMuonSummer16Filter"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "trkPOG_manystripclus53X"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "trkPOG_toomanystripclus53X"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "trkPOG_logErrorTooManyClusters"), _branches);
    panda::utils::setStatus(_tree, BranchName(name_, "METFilters"), _branches);
  }

  /*protected*/
  void
  PEventFilter::doSetAddress_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    panda::utils::setAddress(_tree, BranchName(name_, "HBHENoiseFilter"), &HBHENoiseFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "HBHENoiseIsoFilter"), &HBHENoiseIsoFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "CSCTightHaloFilter"), &CSCTightHaloFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "CSCTightHaloTrkMuUnvetoFilter"), &CSCTightHaloTrkMuUnvetoFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "CSCTightHalo2015Filter"), &CSCTightHalo2015Filter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "globalTightHalo2016Filter"), &globalTightHalo2016Filter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "globalSuperTightHalo2016Filter"), &globalSuperTightHalo2016Filter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "HcalStripHaloFilter"), &HcalStripHaloFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "hcalLaserEventFilter"), &hcalLaserEventFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "EcalDeadCellTriggerPrimitiveFilter"), &EcalDeadCellTriggerPrimitiveFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "EcalDeadCellBoundaryEnergyFilter"), &EcalDeadCellBoundaryEnergyFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "ecalBadCalibFilter"), &ecalBadCalibFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "goodVertices"), &goodVertices, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "eeBadScFilter"), &eeBadScFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "ecalLaserCorrFilter"), &ecalLaserCorrFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "trkPOGFilters"), &trkPOGFilters, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "chargedHadronTrackResolutionFilter"), &chargedHadronTrackResolutionFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "muonBadTrackFilter"), &muonBadTrackFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "BadChargedCandidateFilter"), &BadChargedCandidateFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "BadPFMuonFilter"), &BadPFMuonFilter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "BadChargedCandidateSummer16Filter"), &BadChargedCandidateSummer16Filter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "BadPFMuonSummer16Filter"), &BadPFMuonSummer16Filter, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "trkPOG_manystripclus53X"), &trkPOG_manystripclus53X, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "trkPOG_toomanystripclus53X"), &trkPOG_toomanystripclus53X, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "trkPOG_logErrorTooManyClusters"), &trkPOG_logErrorTooManyClusters, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(name_, "METFilters"), &METFilters, _branches, _setStatus);
  }

  /*protected*/
  void
  PEventFilter::doBook_(TTree& _tree, panda::utils::BranchList const& _branches/* = {"*"}*/)
  {
    panda::utils::book(_tree, BranchName(name_, "HBHENoiseFilter"), "", 'O', &HBHENoiseFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "HBHENoiseIsoFilter"), "", 'O', &HBHENoiseIsoFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "CSCTightHaloFilter"), "", 'O', &CSCTightHaloFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "CSCTightHaloTrkMuUnvetoFilter"), "", 'O', &CSCTightHaloTrkMuUnvetoFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "CSCTightHalo2015Filter"), "", 'O', &CSCTightHalo2015Filter, _branches);
    panda::utils::book(_tree, BranchName(name_, "globalTightHalo2016Filter"), "", 'O', &globalTightHalo2016Filter, _branches);
    panda::utils::book(_tree, BranchName(name_, "globalSuperTightHalo2016Filter"), "", 'O', &globalSuperTightHalo2016Filter, _branches);
    panda::utils::book(_tree, BranchName(name_, "HcalStripHaloFilter"), "", 'O', &HcalStripHaloFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "hcalLaserEventFilter"), "", 'O', &hcalLaserEventFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "EcalDeadCellTriggerPrimitiveFilter"), "", 'O', &EcalDeadCellTriggerPrimitiveFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "EcalDeadCellBoundaryEnergyFilter"), "", 'O', &EcalDeadCellBoundaryEnergyFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "ecalBadCalibFilter"), "", 'O', &ecalBadCalibFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "goodVertices"), "", 'O', &goodVertices, _branches);
    panda::utils::book(_tree, BranchName(name_, "eeBadScFilter"), "", 'O', &eeBadScFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "ecalLaserCorrFilter"), "", 'O', &ecalLaserCorrFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "trkPOGFilters"), "", 'O', &trkPOGFilters, _branches);
    panda::utils::book(_tree, BranchName(name_, "chargedHadronTrackResolutionFilter"), "", 'O', &chargedHadronTrackResolutionFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "muonBadTrackFilter"), "", 'O', &muonBadTrackFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "BadChargedCandidateFilter"), "", 'O', &BadChargedCandidateFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "BadPFMuonFilter"), "", 'O', &BadPFMuonFilter, _branches);
    panda::utils::book(_tree, BranchName(name_, "BadChargedCandidateSummer16Filter"), "", 'O', &BadChargedCandidateSummer16Filter, _branches);
    panda::utils::book(_tree, BranchName(name_, "BadPFMuonSummer16Filter"), "", 'O', &BadPFMuonSummer16Filter, _branches);
    panda::utils::book(_tree, BranchName(name_, "trkPOG_manystripclus53X"), "", 'O', &trkPOG_manystripclus53X, _branches);
    panda::utils::book(_tree, BranchName(name_, "trkPOG_toomanystripclus53X"), "", 'O', &trkPOG_toomanystripclus53X, _branches);
    panda::utils::book(_tree, BranchName(name_, "trkPOG_logErrorTooManyClusters"), "", 'O', &trkPOG_logErrorTooManyClusters, _branches);
    panda::utils::book(_tree, BranchName(name_, "METFilters"), "", 'O', &METFilters, _branches);
  }

  /*protected*/
  void
  PEventFilter::doInit_()
  {
    HBHENoiseFilter = false;
    HBHENoiseIsoFilter = false;
    CSCTightHaloFilter = false;
    CSCTightHaloTrkMuUnvetoFilter = false;
    CSCTightHalo2015Filter = false;
    globalTightHalo2016Filter = false;
    globalSuperTightHalo2016Filter = false;
    HcalStripHaloFilter = false;
    hcalLaserEventFilter = false;
    EcalDeadCellTriggerPrimitiveFilter = false;
    EcalDeadCellBoundaryEnergyFilter = false;
    ecalBadCalibFilter = false;
    goodVertices = false;
    eeBadScFilter = false;
    ecalLaserCorrFilter = false;
    trkPOGFilters = false;
    chargedHadronTrackResolutionFilter = false;
    muonBadTrackFilter = false;
    BadChargedCandidateFilter = false;
    BadPFMuonFilter = false;
    BadChargedCandidateSummer16Filter = false;
    BadPFMuonSummer16Filter = false;
    trkPOG_manystripclus53X = false;
    trkPOG_toomanystripclus53X = false;
    trkPOG_logErrorTooManyClusters = false;
    METFilters = false;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PEventFilter::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PEventFilter::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    panda::Singlet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "HBHENoiseFilter = " << HBHENoiseFilter << std::endl;
    _out << indentation << "HBHENoiseIsoFilter = " << HBHENoiseIsoFilter << std::endl;
    _out << indentation << "CSCTightHaloFilter = " << CSCTightHaloFilter << std::endl;
    _out << indentation << "CSCTightHaloTrkMuUnvetoFilter = " << CSCTightHaloTrkMuUnvetoFilter << std::endl;
    _out << indentation << "CSCTightHalo2015Filter = " << CSCTightHalo2015Filter << std::endl;
    _out << indentation << "globalTightHalo2016Filter = " << globalTightHalo2016Filter << std::endl;
    _out << indentation << "globalSuperTightHalo2016Filter = " << globalSuperTightHalo2016Filter << std::endl;
    _out << indentation << "HcalStripHaloFilter = " << HcalStripHaloFilter << std::endl;
    _out << indentation << "hcalLaserEventFilter = " << hcalLaserEventFilter << std::endl;
    _out << indentation << "EcalDeadCellTriggerPrimitiveFilter = " << EcalDeadCellTriggerPrimitiveFilter << std::endl;
    _out << indentation << "EcalDeadCellBoundaryEnergyFilter = " << EcalDeadCellBoundaryEnergyFilter << std::endl;
    _out << indentation << "ecalBadCalibFilter = " << ecalBadCalibFilter << std::endl;
    _out << indentation << "goodVertices = " << goodVertices << std::endl;
    _out << indentation << "eeBadScFilter = " << eeBadScFilter << std::endl;
    _out << indentation << "ecalLaserCorrFilter = " << ecalLaserCorrFilter << std::endl;
    _out << indentation << "trkPOGFilters = " << trkPOGFilters << std::endl;
    _out << indentation << "chargedHadronTrackResolutionFilter = " << chargedHadronTrackResolutionFilter << std::endl;
    _out << indentation << "muonBadTrackFilter = " << muonBadTrackFilter << std::endl;
    _out << indentation << "BadChargedCandidateFilter = " << BadChargedCandidateFilter << std::endl;
    _out << indentation << "BadPFMuonFilter = " << BadPFMuonFilter << std::endl;
    _out << indentation << "BadChargedCandidateSummer16Filter = " << BadChargedCandidateSummer16Filter << std::endl;
    _out << indentation << "BadPFMuonSummer16Filter = " << BadPFMuonSummer16Filter << std::endl;
    _out << indentation << "trkPOG_manystripclus53X = " << trkPOG_manystripclus53X << std::endl;
    _out << indentation << "trkPOG_toomanystripclus53X = " << trkPOG_toomanystripclus53X << std::endl;
    _out << indentation << "trkPOG_logErrorTooManyClusters = " << trkPOG_logErrorTooManyClusters << std::endl;
    _out << indentation << "METFilters = " << METFilters << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

