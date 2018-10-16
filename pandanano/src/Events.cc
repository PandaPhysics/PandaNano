#include "../interface/Events.h"
#include "../../Framework/interface/IOUtils.h"

namespace pandanano {

  /*static*/
  BranchList const Events::branchNames{std::initializer_list<TString>{"run", "luminosityBlock", "event", "genWeight", "nLHEPdfWeight", "LHEPdfWeight", "nLHEScaleWeight", "LHEScaleWeight", "nPSWeight", "PSWeight", "fixedGridRhoFastjetAll", "fixedGridRhoFastjetCentralCalo", "fixedGridRhoFastjetCentralNeutral", "SoftActivityJetHT", "SoftActivityJetHT10", "SoftActivityJetHT2", "SoftActivityJetHT5", "SoftActivityJetNjets10", "SoftActivityJetNjets2", "SoftActivityJetNjets5", "genTtbarId", "L1simulation_step", "HLTriggerFirstPath", "L1Reco_step"}, panda::utils::BranchName::kAttrName};

  Events::Events() :
    panda::TreeEntry()
  {
    std::vector<panda::Object*> myObjects{std::initializer_list<panda::Object*>{&Generator, &LHE, &LHEPart, &btagWeight, &Electron, &FatJet, &GenJet, &GenJetAK8, &GenPart, &SubGenJetAK8, &GenVisTau, &LHEWeight, &IsoTrack, &Jet, &Muon, &Photon, &Pileup, &MET, &PuppiMET, &CaloMET, &TkMET, &RawMET, &GenMET, &GenDressedLepton, &SoftActivityJet, &SubJet, &Tau, &TrigObj, &OtherPV, &PV, &Flag}};
    objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
    std::vector<panda::CollectionBase*> myCollections{std::initializer_list<panda::CollectionBase*>{&LHEPart, &Electron, &FatJet, &GenJet, &GenJetAK8, &GenPart, &SubGenJetAK8, &GenVisTau, &IsoTrack, &Jet, &Muon, &Photon, &GenDressedLepton, &SoftActivityJet, &SubJet, &Tau, &TrigObj, &OtherPV}};
    collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

    /* BEGIN CUSTOM default_ctor */
    /* END CUSTOM */
  }

  Events::Events(Events const& _src) :
    TreeEntry(_src),
    Generator(_src.Generator),
    LHE(_src.LHE),
    LHEPart(_src.LHEPart),
    btagWeight(_src.btagWeight),
    Electron(_src.Electron),
    FatJet(_src.FatJet),
    GenJet(_src.GenJet),
    GenJetAK8(_src.GenJetAK8),
    GenPart(_src.GenPart),
    SubGenJetAK8(_src.SubGenJetAK8),
    GenVisTau(_src.GenVisTau),
    LHEWeight(_src.LHEWeight),
    IsoTrack(_src.IsoTrack),
    Jet(_src.Jet),
    Muon(_src.Muon),
    Photon(_src.Photon),
    Pileup(_src.Pileup),
    MET(_src.MET),
    PuppiMET(_src.PuppiMET),
    CaloMET(_src.CaloMET),
    TkMET(_src.TkMET),
    RawMET(_src.RawMET),
    GenMET(_src.GenMET),
    GenDressedLepton(_src.GenDressedLepton),
    SoftActivityJet(_src.SoftActivityJet),
    SubJet(_src.SubJet),
    Tau(_src.Tau),
    TrigObj(_src.TrigObj),
    OtherPV(_src.OtherPV),
    PV(_src.PV),
    Flag(_src.Flag),
    run(_src.run),
    luminosityBlock(_src.luminosityBlock),
    event(_src.event),
    genWeight(_src.genWeight),
    nLHEPdfWeight(_src.nLHEPdfWeight),
    LHEPdfWeight(_src.LHEPdfWeight),
    nLHEScaleWeight(_src.nLHEScaleWeight),
    LHEScaleWeight(_src.LHEScaleWeight),
    nPSWeight(_src.nPSWeight),
    PSWeight(_src.PSWeight),
    fixedGridRhoFastjetAll(_src.fixedGridRhoFastjetAll),
    fixedGridRhoFastjetCentralCalo(_src.fixedGridRhoFastjetCentralCalo),
    fixedGridRhoFastjetCentralNeutral(_src.fixedGridRhoFastjetCentralNeutral),
    SoftActivityJetHT(_src.SoftActivityJetHT),
    SoftActivityJetHT10(_src.SoftActivityJetHT10),
    SoftActivityJetHT2(_src.SoftActivityJetHT2),
    SoftActivityJetHT5(_src.SoftActivityJetHT5),
    SoftActivityJetNjets10(_src.SoftActivityJetNjets10),
    SoftActivityJetNjets2(_src.SoftActivityJetNjets2),
    SoftActivityJetNjets5(_src.SoftActivityJetNjets5),
    genTtbarId(_src.genTtbarId),
    L1simulation_step(_src.L1simulation_step),
    HLTriggerFirstPath(_src.HLTriggerFirstPath),
    L1Reco_step(_src.L1Reco_step)
  {
    std::vector<panda::Object*> myObjects{std::initializer_list<panda::Object*>{&Generator, &LHE, &LHEPart, &btagWeight, &Electron, &FatJet, &GenJet, &GenJetAK8, &GenPart, &SubGenJetAK8, &GenVisTau, &LHEWeight, &IsoTrack, &Jet, &Muon, &Photon, &Pileup, &MET, &PuppiMET, &CaloMET, &TkMET, &RawMET, &GenMET, &GenDressedLepton, &SoftActivityJet, &SubJet, &Tau, &TrigObj, &OtherPV, &PV, &Flag}};
    objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
    std::vector<panda::CollectionBase*> myCollections{std::initializer_list<panda::CollectionBase*>{&LHEPart, &Electron, &FatJet, &GenJet, &GenJetAK8, &GenPart, &SubGenJetAK8, &GenVisTau, &IsoTrack, &Jet, &Muon, &Photon, &GenDressedLepton, &SoftActivityJet, &SubJet, &Tau, &TrigObj, &OtherPV}};
    collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

    /* BEGIN CUSTOM copy_ctor */
    /* END CUSTOM */
  }

  Events::~Events()
  {
    /* BEGIN CUSTOM dtor */
    /* END CUSTOM */
  }

  Events&
  Events::operator=(Events const& _src)
  {
    panda::TreeEntry::operator=(_src);

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    run = _src.run;
    luminosityBlock = _src.luminosityBlock;
    event = _src.event;
    genWeight = _src.genWeight;
    nLHEPdfWeight = _src.nLHEPdfWeight;
    LHEPdfWeight = _src.LHEPdfWeight;
    nLHEScaleWeight = _src.nLHEScaleWeight;
    LHEScaleWeight = _src.LHEScaleWeight;
    nPSWeight = _src.nPSWeight;
    PSWeight = _src.PSWeight;
    fixedGridRhoFastjetAll = _src.fixedGridRhoFastjetAll;
    fixedGridRhoFastjetCentralCalo = _src.fixedGridRhoFastjetCentralCalo;
    fixedGridRhoFastjetCentralNeutral = _src.fixedGridRhoFastjetCentralNeutral;
    SoftActivityJetHT = _src.SoftActivityJetHT;
    SoftActivityJetHT10 = _src.SoftActivityJetHT10;
    SoftActivityJetHT2 = _src.SoftActivityJetHT2;
    SoftActivityJetHT5 = _src.SoftActivityJetHT5;
    SoftActivityJetNjets10 = _src.SoftActivityJetNjets10;
    SoftActivityJetNjets2 = _src.SoftActivityJetNjets2;
    SoftActivityJetNjets5 = _src.SoftActivityJetNjets5;
    genTtbarId = _src.genTtbarId;
    L1simulation_step = _src.L1simulation_step;
    HLTriggerFirstPath = _src.HLTriggerFirstPath;
    L1Reco_step = _src.L1Reco_step;
    Generator = _src.Generator;
    LHE = _src.LHE;
    LHEPart = _src.LHEPart;
    btagWeight = _src.btagWeight;
    Electron = _src.Electron;
    FatJet = _src.FatJet;
    GenJet = _src.GenJet;
    GenJetAK8 = _src.GenJetAK8;
    GenPart = _src.GenPart;
    SubGenJetAK8 = _src.SubGenJetAK8;
    GenVisTau = _src.GenVisTau;
    LHEWeight = _src.LHEWeight;
    IsoTrack = _src.IsoTrack;
    Jet = _src.Jet;
    Muon = _src.Muon;
    Photon = _src.Photon;
    Pileup = _src.Pileup;
    MET = _src.MET;
    PuppiMET = _src.PuppiMET;
    CaloMET = _src.CaloMET;
    TkMET = _src.TkMET;
    RawMET = _src.RawMET;
    GenMET = _src.GenMET;
    GenDressedLepton = _src.GenDressedLepton;
    SoftActivityJet = _src.SoftActivityJet;
    SubJet = _src.SubJet;
    Tau = _src.Tau;
    TrigObj = _src.TrigObj;
    OtherPV = _src.OtherPV;
    PV = _src.PV;
    Flag = _src.Flag;

    return *this;
  }

  void
  Events::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  Events::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    std::string indentation(_indent * 2, ' ');

    panda::TreeEntry::dump(_out, _indent);
    _out << indentation << "run = " << run << std::endl;
    _out << indentation << "luminosityBlock = " << luminosityBlock << std::endl;
    _out << indentation << "event = " << event << std::endl;
    _out << indentation << "genWeight = " << genWeight << std::endl;
    _out << indentation << "nLHEPdfWeight = " << nLHEPdfWeight << std::endl;
    _out << indentation << "LHEPdfWeight = " << LHEPdfWeight << std::endl;
    _out << indentation << "nLHEScaleWeight = " << nLHEScaleWeight << std::endl;
    _out << indentation << "LHEScaleWeight = " << LHEScaleWeight << std::endl;
    _out << indentation << "nPSWeight = " << nPSWeight << std::endl;
    _out << indentation << "PSWeight = " << PSWeight << std::endl;
    _out << indentation << "fixedGridRhoFastjetAll = " << fixedGridRhoFastjetAll << std::endl;
    _out << indentation << "fixedGridRhoFastjetCentralCalo = " << fixedGridRhoFastjetCentralCalo << std::endl;
    _out << indentation << "fixedGridRhoFastjetCentralNeutral = " << fixedGridRhoFastjetCentralNeutral << std::endl;
    _out << indentation << "SoftActivityJetHT = " << SoftActivityJetHT << std::endl;
    _out << indentation << "SoftActivityJetHT10 = " << SoftActivityJetHT10 << std::endl;
    _out << indentation << "SoftActivityJetHT2 = " << SoftActivityJetHT2 << std::endl;
    _out << indentation << "SoftActivityJetHT5 = " << SoftActivityJetHT5 << std::endl;
    _out << indentation << "SoftActivityJetNjets10 = " << SoftActivityJetNjets10 << std::endl;
    _out << indentation << "SoftActivityJetNjets2 = " << SoftActivityJetNjets2 << std::endl;
    _out << indentation << "SoftActivityJetNjets5 = " << SoftActivityJetNjets5 << std::endl;
    _out << indentation << "genTtbarId = " << genTtbarId << std::endl;
    _out << indentation << "L1simulation_step = " << L1simulation_step << std::endl;
    _out << indentation << "HLTriggerFirstPath = " << HLTriggerFirstPath << std::endl;
    _out << indentation << "L1Reco_step = " << L1Reco_step << std::endl;
    _out << std::endl;
    _out << indentation << "{" << Generator.getName() << "}: " << Generator.typeName() << std::endl;
    Generator.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << LHE.getName() << "}: " << LHE.typeName() << std::endl;
    LHE.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << LHEPart.getName() << "}: " << LHEPart.typeName() << std::endl;
    LHEPart.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << btagWeight.getName() << "}: " << btagWeight.typeName() << std::endl;
    btagWeight.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << Electron.getName() << "}: " << Electron.typeName() << std::endl;
    Electron.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << FatJet.getName() << "}: " << FatJet.typeName() << std::endl;
    FatJet.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << GenJet.getName() << "}: " << GenJet.typeName() << std::endl;
    GenJet.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << GenJetAK8.getName() << "}: " << GenJetAK8.typeName() << std::endl;
    GenJetAK8.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << GenPart.getName() << "}: " << GenPart.typeName() << std::endl;
    GenPart.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << SubGenJetAK8.getName() << "}: " << SubGenJetAK8.typeName() << std::endl;
    SubGenJetAK8.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << GenVisTau.getName() << "}: " << GenVisTau.typeName() << std::endl;
    GenVisTau.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << LHEWeight.getName() << "}: " << LHEWeight.typeName() << std::endl;
    LHEWeight.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << IsoTrack.getName() << "}: " << IsoTrack.typeName() << std::endl;
    IsoTrack.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << Jet.getName() << "}: " << Jet.typeName() << std::endl;
    Jet.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << Muon.getName() << "}: " << Muon.typeName() << std::endl;
    Muon.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << Photon.getName() << "}: " << Photon.typeName() << std::endl;
    Photon.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << Pileup.getName() << "}: " << Pileup.typeName() << std::endl;
    Pileup.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << MET.getName() << "}: " << MET.typeName() << std::endl;
    MET.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << PuppiMET.getName() << "}: " << PuppiMET.typeName() << std::endl;
    PuppiMET.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << CaloMET.getName() << "}: " << CaloMET.typeName() << std::endl;
    CaloMET.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << TkMET.getName() << "}: " << TkMET.typeName() << std::endl;
    TkMET.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << RawMET.getName() << "}: " << RawMET.typeName() << std::endl;
    RawMET.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << GenMET.getName() << "}: " << GenMET.typeName() << std::endl;
    GenMET.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << GenDressedLepton.getName() << "}: " << GenDressedLepton.typeName() << std::endl;
    GenDressedLepton.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << SoftActivityJet.getName() << "}: " << SoftActivityJet.typeName() << std::endl;
    SoftActivityJet.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << SubJet.getName() << "}: " << SubJet.typeName() << std::endl;
    SubJet.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << Tau.getName() << "}: " << Tau.typeName() << std::endl;
    Tau.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << TrigObj.getName() << "}: " << TrigObj.typeName() << std::endl;
    TrigObj.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << OtherPV.getName() << "}: " << OtherPV.typeName() << std::endl;
    OtherPV.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << PV.getName() << "}: " << PV.typeName() << std::endl;
    PV.dump(_out, _indent);
    _out << std::endl;
    _out << indentation << "{" << Flag.getName() << "}: " << Flag.typeName() << std::endl;
    Flag.dump(_out, _indent);
    _out << std::endl;
  }

  /*protected*/
  void
  Events::doSetStatus_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    panda::utils::setStatus(_tree, BranchName("run"), _branches);
    panda::utils::setStatus(_tree, BranchName("luminosityBlock"), _branches);
    panda::utils::setStatus(_tree, BranchName("event"), _branches);
    panda::utils::setStatus(_tree, BranchName("genWeight"), _branches);
    panda::utils::setStatus(_tree, BranchName("nLHEPdfWeight"), _branches);
    panda::utils::setStatus(_tree, BranchName("LHEPdfWeight"), _branches);
    panda::utils::setStatus(_tree, BranchName("nLHEScaleWeight"), _branches);
    panda::utils::setStatus(_tree, BranchName("LHEScaleWeight"), _branches);
    panda::utils::setStatus(_tree, BranchName("nPSWeight"), _branches);
    panda::utils::setStatus(_tree, BranchName("PSWeight"), _branches);
    panda::utils::setStatus(_tree, BranchName("fixedGridRhoFastjetAll"), _branches);
    panda::utils::setStatus(_tree, BranchName("fixedGridRhoFastjetCentralCalo"), _branches);
    panda::utils::setStatus(_tree, BranchName("fixedGridRhoFastjetCentralNeutral"), _branches);
    panda::utils::setStatus(_tree, BranchName("SoftActivityJetHT"), _branches);
    panda::utils::setStatus(_tree, BranchName("SoftActivityJetHT10"), _branches);
    panda::utils::setStatus(_tree, BranchName("SoftActivityJetHT2"), _branches);
    panda::utils::setStatus(_tree, BranchName("SoftActivityJetHT5"), _branches);
    panda::utils::setStatus(_tree, BranchName("SoftActivityJetNjets10"), _branches);
    panda::utils::setStatus(_tree, BranchName("SoftActivityJetNjets2"), _branches);
    panda::utils::setStatus(_tree, BranchName("SoftActivityJetNjets5"), _branches);
    panda::utils::setStatus(_tree, BranchName("genTtbarId"), _branches);
    panda::utils::setStatus(_tree, BranchName("L1simulation_step"), _branches);
    panda::utils::setStatus(_tree, BranchName("HLTriggerFirstPath"), _branches);
    panda::utils::setStatus(_tree, BranchName("L1Reco_step"), _branches);
  }

  /*protected*/
  void
  Events::doSetAddress_(TTree& _tree, panda::utils::BranchList const& _branches, Bool_t _setStatus)
  {
    panda::utils::setAddress(_tree, BranchName("run"), &run, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("luminosityBlock"), &luminosityBlock, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("event"), &event, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("genWeight"), &genWeight, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("nLHEPdfWeight"), &nLHEPdfWeight, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("LHEPdfWeight"), &LHEPdfWeight, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("nLHEScaleWeight"), &nLHEScaleWeight, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("LHEScaleWeight"), &LHEScaleWeight, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("nPSWeight"), &nPSWeight, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("PSWeight"), &PSWeight, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("fixedGridRhoFastjetAll"), &fixedGridRhoFastjetAll, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("fixedGridRhoFastjetCentralCalo"), &fixedGridRhoFastjetCentralCalo, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("fixedGridRhoFastjetCentralNeutral"), &fixedGridRhoFastjetCentralNeutral, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("SoftActivityJetHT"), &SoftActivityJetHT, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("SoftActivityJetHT10"), &SoftActivityJetHT10, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("SoftActivityJetHT2"), &SoftActivityJetHT2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("SoftActivityJetHT5"), &SoftActivityJetHT5, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("SoftActivityJetNjets10"), &SoftActivityJetNjets10, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("SoftActivityJetNjets2"), &SoftActivityJetNjets2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("SoftActivityJetNjets5"), &SoftActivityJetNjets5, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("genTtbarId"), &genTtbarId, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("L1simulation_step"), &L1simulation_step, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("HLTriggerFirstPath"), &HLTriggerFirstPath, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName("L1Reco_step"), &L1Reco_step, _branches, _setStatus);
  }

  /*protected*/
  void
  Events::doBook_(TTree& _tree, panda::utils::BranchList const& _branches)
  {
    panda::utils::book(_tree, BranchName("run"), "", 'i', &run, _branches);
    panda::utils::book(_tree, BranchName("luminosityBlock"), "", 'i', &luminosityBlock, _branches);
    panda::utils::book(_tree, BranchName("event"), "", 'l', &event, _branches);
    panda::utils::book(_tree, BranchName("genWeight"), "", 'F', &genWeight, _branches);
    panda::utils::book(_tree, BranchName("nLHEPdfWeight"), "", 'i', &nLHEPdfWeight, _branches);
    panda::utils::book(_tree, BranchName("LHEPdfWeight"), "", 'F', &LHEPdfWeight, _branches);
    panda::utils::book(_tree, BranchName("nLHEScaleWeight"), "", 'i', &nLHEScaleWeight, _branches);
    panda::utils::book(_tree, BranchName("LHEScaleWeight"), "", 'F', &LHEScaleWeight, _branches);
    panda::utils::book(_tree, BranchName("nPSWeight"), "", 'i', &nPSWeight, _branches);
    panda::utils::book(_tree, BranchName("PSWeight"), "", 'F', &PSWeight, _branches);
    panda::utils::book(_tree, BranchName("fixedGridRhoFastjetAll"), "", 'F', &fixedGridRhoFastjetAll, _branches);
    panda::utils::book(_tree, BranchName("fixedGridRhoFastjetCentralCalo"), "", 'F', &fixedGridRhoFastjetCentralCalo, _branches);
    panda::utils::book(_tree, BranchName("fixedGridRhoFastjetCentralNeutral"), "", 'F', &fixedGridRhoFastjetCentralNeutral, _branches);
    panda::utils::book(_tree, BranchName("SoftActivityJetHT"), "", 'F', &SoftActivityJetHT, _branches);
    panda::utils::book(_tree, BranchName("SoftActivityJetHT10"), "", 'F', &SoftActivityJetHT10, _branches);
    panda::utils::book(_tree, BranchName("SoftActivityJetHT2"), "", 'F', &SoftActivityJetHT2, _branches);
    panda::utils::book(_tree, BranchName("SoftActivityJetHT5"), "", 'F', &SoftActivityJetHT5, _branches);
    panda::utils::book(_tree, BranchName("SoftActivityJetNjets10"), "", 'I', &SoftActivityJetNjets10, _branches);
    panda::utils::book(_tree, BranchName("SoftActivityJetNjets2"), "", 'I', &SoftActivityJetNjets2, _branches);
    panda::utils::book(_tree, BranchName("SoftActivityJetNjets5"), "", 'I', &SoftActivityJetNjets5, _branches);
    panda::utils::book(_tree, BranchName("genTtbarId"), "", 'I', &genTtbarId, _branches);
    panda::utils::book(_tree, BranchName("L1simulation_step"), "", 'O', &L1simulation_step, _branches);
    panda::utils::book(_tree, BranchName("HLTriggerFirstPath"), "", 'O', &HLTriggerFirstPath, _branches);
    panda::utils::book(_tree, BranchName("L1Reco_step"), "", 'O', &L1Reco_step, _branches);
  }

  /*protected*/
  void
  Events::doGetEntry_(TTree& _tree)
  {

    /* BEGIN CUSTOM get_entry */
    /* END CUSTOM */
  }

  /*protected*/
  void
  Events::doInit_()
  {
    run = 0;
    luminosityBlock = 0;
    event = 0;
    genWeight = 0.;
    nLHEPdfWeight = 0;
    LHEPdfWeight = 0.;
    nLHEScaleWeight = 0;
    LHEScaleWeight = 0.;
    nPSWeight = 0;
    PSWeight = 0.;
    fixedGridRhoFastjetAll = 0.;
    fixedGridRhoFastjetCentralCalo = 0.;
    fixedGridRhoFastjetCentralNeutral = 0.;
    SoftActivityJetHT = 0.;
    SoftActivityJetHT10 = 0.;
    SoftActivityJetHT2 = 0.;
    SoftActivityJetHT5 = 0.;
    SoftActivityJetNjets10 = 0;
    SoftActivityJetNjets2 = 0;
    SoftActivityJetNjets5 = 0;
    genTtbarId = 0;
    L1simulation_step = false;
    HLTriggerFirstPath = false;
    L1Reco_step = false;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  /*protected*/
  void
  Events::doUnlink_(TTree& _tree)
  {
    /* BEGIN CUSTOM unlink */
    /* END CUSTOM */
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

