#include "../interface/PJet.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PJet>::branchNames{std::initializer_list<TString>{"size", "btagCMVA", "btagCSVV2", "btagDeepB", "mass", "pt", "eta", "phi", "area", "btagDeepC", "btagDeepFlavB", "chEmEF", "chHEF", "muEF", "neEmEF", "neHEF", "qgl", "rawFactor", "bRegCorr", "bRegRes", "electronIdx1", "electronIdx2", "jetId", "muonIdx1", "muonIdx2", "nConstituents", "nElectrons", "nMuons", "puId", "genJetIdx", "hadronFlavour", "partonFlavour", "cleanmask"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PJet::branchNames{std::initializer_list<TString>{"btagCMVA", "btagCSVV2", "btagDeepB", "mass", "pt", "eta", "phi", "area", "btagDeepC", "btagDeepFlavB", "chEmEF", "chHEF", "muEF", "neEmEF", "neHEF", "qgl", "rawFactor", "bRegCorr", "bRegRes", "electronIdx1", "electronIdx2", "jetId", "muonIdx1", "muonIdx2", "nConstituents", "nElectrons", "nMuons", "puId", "genJetIdx", "hadronFlavour", "partonFlavour", "cleanmask"}, panda::utils::BranchName::kAttrName};

  void
  PJet::datastore::allocate(UInt_t _nmax)
  {
    PRecoJet::datastore::allocate(_nmax);

    area = new Float_t[nmax_];
    btagDeepC = new Float_t[nmax_];
    btagDeepFlavB = new Float_t[nmax_];
    chEmEF = new Float_t[nmax_];
    chHEF = new Float_t[nmax_];
    muEF = new Float_t[nmax_];
    neEmEF = new Float_t[nmax_];
    neHEF = new Float_t[nmax_];
    qgl = new Float_t[nmax_];
    rawFactor = new Float_t[nmax_];
    bRegCorr = new Float_t[nmax_];
    bRegRes = new Float_t[nmax_];
    electronIdx1 = new Int_t[nmax_];
    electronIdx2 = new Int_t[nmax_];
    jetId = new Int_t[nmax_];
    muonIdx1 = new Int_t[nmax_];
    muonIdx2 = new Int_t[nmax_];
    nConstituents = new Int_t[nmax_];
    nElectrons = new Int_t[nmax_];
    nMuons = new Int_t[nmax_];
    puId = new Int_t[nmax_];
    genJetIdx = new Int_t[nmax_];
    hadronFlavour = new Int_t[nmax_];
    partonFlavour = new Int_t[nmax_];
    cleanmask = new UChar_t[nmax_];
  }

  void
  PJet::datastore::deallocate()
  {
    PRecoJet::datastore::deallocate();

    delete [] area;
    area = 0;
    delete [] btagDeepC;
    btagDeepC = 0;
    delete [] btagDeepFlavB;
    btagDeepFlavB = 0;
    delete [] chEmEF;
    chEmEF = 0;
    delete [] chHEF;
    chHEF = 0;
    delete [] muEF;
    muEF = 0;
    delete [] neEmEF;
    neEmEF = 0;
    delete [] neHEF;
    neHEF = 0;
    delete [] qgl;
    qgl = 0;
    delete [] rawFactor;
    rawFactor = 0;
    delete [] bRegCorr;
    bRegCorr = 0;
    delete [] bRegRes;
    bRegRes = 0;
    delete [] electronIdx1;
    electronIdx1 = 0;
    delete [] electronIdx2;
    electronIdx2 = 0;
    delete [] jetId;
    jetId = 0;
    delete [] muonIdx1;
    muonIdx1 = 0;
    delete [] muonIdx2;
    muonIdx2 = 0;
    delete [] nConstituents;
    nConstituents = 0;
    delete [] nElectrons;
    nElectrons = 0;
    delete [] nMuons;
    nMuons = 0;
    delete [] puId;
    puId = 0;
    delete [] genJetIdx;
    genJetIdx = 0;
    delete [] hadronFlavour;
    hadronFlavour = 0;
    delete [] partonFlavour;
    partonFlavour = 0;
    delete [] cleanmask;
    cleanmask = 0;
  }

  void
  PJet::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PRecoJet::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "area"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "btagDeepC"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "btagDeepFlavB"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "chEmEF"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "chHEF"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "muEF"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "neEmEF"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "neHEF"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "qgl"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "rawFactor"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "bRegCorr"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "bRegRes"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "electronIdx1"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "electronIdx2"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "jetId"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "muonIdx1"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "muonIdx2"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "nConstituents"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "nElectrons"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "nMuons"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "puId"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "genJetIdx"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "hadronFlavour"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "partonFlavour"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "cleanmask"), _branches);
  }

  void
  PJet::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PRecoJet::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "area"), area, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "btagDeepC"), btagDeepC, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "btagDeepFlavB"), btagDeepFlavB, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "chEmEF"), chEmEF, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "chHEF"), chHEF, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "muEF"), muEF, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "neEmEF"), neEmEF, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "neHEF"), neHEF, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "qgl"), qgl, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "rawFactor"), rawFactor, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "bRegCorr"), bRegCorr, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "bRegRes"), bRegRes, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "electronIdx1"), electronIdx1, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "electronIdx2"), electronIdx2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "jetId"), jetId, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "muonIdx1"), muonIdx1, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "muonIdx2"), muonIdx2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "nConstituents"), nConstituents, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "nElectrons"), nElectrons, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "nMuons"), nMuons, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "puId"), puId, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "genJetIdx"), genJetIdx, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "hadronFlavour"), hadronFlavour, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "partonFlavour"), partonFlavour, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "cleanmask"), cleanmask, _branches, _setStatus);
  }

  void
  PJet::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
  {
    PRecoJet::datastore::book(_tree, _name, _branches, _bookAs);

    TString size;

    switch (_bookAs) {
    case aCollection:
      size = TString::Format("[%s]", BranchName(_name, "size").toString());
      break;
    case aArray:
      size = TString::Format("[%d]", nmax_);
      break;
    case aSinglet:
      size = "";
      break;
    }

    panda::utils::book(_tree, BranchName(_name, "area"), size, 'F', area, _branches);
    panda::utils::book(_tree, BranchName(_name, "btagDeepC"), size, 'F', btagDeepC, _branches);
    panda::utils::book(_tree, BranchName(_name, "btagDeepFlavB"), size, 'F', btagDeepFlavB, _branches);
    panda::utils::book(_tree, BranchName(_name, "chEmEF"), size, 'F', chEmEF, _branches);
    panda::utils::book(_tree, BranchName(_name, "chHEF"), size, 'F', chHEF, _branches);
    panda::utils::book(_tree, BranchName(_name, "muEF"), size, 'F', muEF, _branches);
    panda::utils::book(_tree, BranchName(_name, "neEmEF"), size, 'F', neEmEF, _branches);
    panda::utils::book(_tree, BranchName(_name, "neHEF"), size, 'F', neHEF, _branches);
    panda::utils::book(_tree, BranchName(_name, "qgl"), size, 'F', qgl, _branches);
    panda::utils::book(_tree, BranchName(_name, "rawFactor"), size, 'F', rawFactor, _branches);
    panda::utils::book(_tree, BranchName(_name, "bRegCorr"), size, 'F', bRegCorr, _branches);
    panda::utils::book(_tree, BranchName(_name, "bRegRes"), size, 'F', bRegRes, _branches);
    panda::utils::book(_tree, BranchName(_name, "electronIdx1"), size, 'I', electronIdx1, _branches);
    panda::utils::book(_tree, BranchName(_name, "electronIdx2"), size, 'I', electronIdx2, _branches);
    panda::utils::book(_tree, BranchName(_name, "jetId"), size, 'I', jetId, _branches);
    panda::utils::book(_tree, BranchName(_name, "muonIdx1"), size, 'I', muonIdx1, _branches);
    panda::utils::book(_tree, BranchName(_name, "muonIdx2"), size, 'I', muonIdx2, _branches);
    panda::utils::book(_tree, BranchName(_name, "nConstituents"), size, 'I', nConstituents, _branches);
    panda::utils::book(_tree, BranchName(_name, "nElectrons"), size, 'I', nElectrons, _branches);
    panda::utils::book(_tree, BranchName(_name, "nMuons"), size, 'I', nMuons, _branches);
    panda::utils::book(_tree, BranchName(_name, "puId"), size, 'I', puId, _branches);
    panda::utils::book(_tree, BranchName(_name, "genJetIdx"), size, 'I', genJetIdx, _branches);
    panda::utils::book(_tree, BranchName(_name, "hadronFlavour"), size, 'I', hadronFlavour, _branches);
    panda::utils::book(_tree, BranchName(_name, "partonFlavour"), size, 'I', partonFlavour, _branches);
    panda::utils::book(_tree, BranchName(_name, "cleanmask"), size, 'b', cleanmask, _branches);
  }

  void
  PJet::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PRecoJet::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "area"));
    panda::utils::resetAddress(_tree, BranchName(_name, "btagDeepC"));
    panda::utils::resetAddress(_tree, BranchName(_name, "btagDeepFlavB"));
    panda::utils::resetAddress(_tree, BranchName(_name, "chEmEF"));
    panda::utils::resetAddress(_tree, BranchName(_name, "chHEF"));
    panda::utils::resetAddress(_tree, BranchName(_name, "muEF"));
    panda::utils::resetAddress(_tree, BranchName(_name, "neEmEF"));
    panda::utils::resetAddress(_tree, BranchName(_name, "neHEF"));
    panda::utils::resetAddress(_tree, BranchName(_name, "qgl"));
    panda::utils::resetAddress(_tree, BranchName(_name, "rawFactor"));
    panda::utils::resetAddress(_tree, BranchName(_name, "bRegCorr"));
    panda::utils::resetAddress(_tree, BranchName(_name, "bRegRes"));
    panda::utils::resetAddress(_tree, BranchName(_name, "electronIdx1"));
    panda::utils::resetAddress(_tree, BranchName(_name, "electronIdx2"));
    panda::utils::resetAddress(_tree, BranchName(_name, "jetId"));
    panda::utils::resetAddress(_tree, BranchName(_name, "muonIdx1"));
    panda::utils::resetAddress(_tree, BranchName(_name, "muonIdx2"));
    panda::utils::resetAddress(_tree, BranchName(_name, "nConstituents"));
    panda::utils::resetAddress(_tree, BranchName(_name, "nElectrons"));
    panda::utils::resetAddress(_tree, BranchName(_name, "nMuons"));
    panda::utils::resetAddress(_tree, BranchName(_name, "puId"));
    panda::utils::resetAddress(_tree, BranchName(_name, "genJetIdx"));
    panda::utils::resetAddress(_tree, BranchName(_name, "hadronFlavour"));
    panda::utils::resetAddress(_tree, BranchName(_name, "partonFlavour"));
    panda::utils::resetAddress(_tree, BranchName(_name, "cleanmask"));
  }

  void
  PJet::datastore::resizeVectors_(UInt_t _size)
  {
    PRecoJet::datastore::resizeVectors_(_size);

  }

  PJet::PJet(char const* _name/* = ""*/) :
    PRecoJet(new PJetArray(1, _name)),
    area(gStore.getData(this).area[0]),
    btagDeepC(gStore.getData(this).btagDeepC[0]),
    btagDeepFlavB(gStore.getData(this).btagDeepFlavB[0]),
    chEmEF(gStore.getData(this).chEmEF[0]),
    chHEF(gStore.getData(this).chHEF[0]),
    muEF(gStore.getData(this).muEF[0]),
    neEmEF(gStore.getData(this).neEmEF[0]),
    neHEF(gStore.getData(this).neHEF[0]),
    qgl(gStore.getData(this).qgl[0]),
    rawFactor(gStore.getData(this).rawFactor[0]),
    bRegCorr(gStore.getData(this).bRegCorr[0]),
    bRegRes(gStore.getData(this).bRegRes[0]),
    electronIdx1(gStore.getData(this).electronIdx1[0]),
    electronIdx2(gStore.getData(this).electronIdx2[0]),
    jetId(gStore.getData(this).jetId[0]),
    muonIdx1(gStore.getData(this).muonIdx1[0]),
    muonIdx2(gStore.getData(this).muonIdx2[0]),
    nConstituents(gStore.getData(this).nConstituents[0]),
    nElectrons(gStore.getData(this).nElectrons[0]),
    nMuons(gStore.getData(this).nMuons[0]),
    puId(gStore.getData(this).puId[0]),
    genJetIdx(gStore.getData(this).genJetIdx[0]),
    hadronFlavour(gStore.getData(this).hadronFlavour[0]),
    partonFlavour(gStore.getData(this).partonFlavour[0]),
    cleanmask(gStore.getData(this).cleanmask[0])
  {
  }

  PJet::PJet(PJet const& _src) :
    PRecoJet(new PJetArray(1, _src.getName())),
    area(gStore.getData(this).area[0]),
    btagDeepC(gStore.getData(this).btagDeepC[0]),
    btagDeepFlavB(gStore.getData(this).btagDeepFlavB[0]),
    chEmEF(gStore.getData(this).chEmEF[0]),
    chHEF(gStore.getData(this).chHEF[0]),
    muEF(gStore.getData(this).muEF[0]),
    neEmEF(gStore.getData(this).neEmEF[0]),
    neHEF(gStore.getData(this).neHEF[0]),
    qgl(gStore.getData(this).qgl[0]),
    rawFactor(gStore.getData(this).rawFactor[0]),
    bRegCorr(gStore.getData(this).bRegCorr[0]),
    bRegRes(gStore.getData(this).bRegRes[0]),
    electronIdx1(gStore.getData(this).electronIdx1[0]),
    electronIdx2(gStore.getData(this).electronIdx2[0]),
    jetId(gStore.getData(this).jetId[0]),
    muonIdx1(gStore.getData(this).muonIdx1[0]),
    muonIdx2(gStore.getData(this).muonIdx2[0]),
    nConstituents(gStore.getData(this).nConstituents[0]),
    nElectrons(gStore.getData(this).nElectrons[0]),
    nMuons(gStore.getData(this).nMuons[0]),
    puId(gStore.getData(this).puId[0]),
    genJetIdx(gStore.getData(this).genJetIdx[0]),
    hadronFlavour(gStore.getData(this).hadronFlavour[0]),
    partonFlavour(gStore.getData(this).partonFlavour[0]),
    cleanmask(gStore.getData(this).cleanmask[0])
  {
    PRecoJet::operator=(_src);

    area = _src.area;
    btagDeepC = _src.btagDeepC;
    btagDeepFlavB = _src.btagDeepFlavB;
    chEmEF = _src.chEmEF;
    chHEF = _src.chHEF;
    muEF = _src.muEF;
    neEmEF = _src.neEmEF;
    neHEF = _src.neHEF;
    qgl = _src.qgl;
    rawFactor = _src.rawFactor;
    bRegCorr = _src.bRegCorr;
    bRegRes = _src.bRegRes;
    electronIdx1 = _src.electronIdx1;
    electronIdx2 = _src.electronIdx2;
    jetId = _src.jetId;
    muonIdx1 = _src.muonIdx1;
    muonIdx2 = _src.muonIdx2;
    nConstituents = _src.nConstituents;
    nElectrons = _src.nElectrons;
    nMuons = _src.nMuons;
    puId = _src.puId;
    genJetIdx = _src.genJetIdx;
    hadronFlavour = _src.hadronFlavour;
    partonFlavour = _src.partonFlavour;
    cleanmask = _src.cleanmask;
  }

  PJet::PJet(datastore& _data, UInt_t _idx) :
    PRecoJet(_data, _idx),
    area(_data.area[_idx]),
    btagDeepC(_data.btagDeepC[_idx]),
    btagDeepFlavB(_data.btagDeepFlavB[_idx]),
    chEmEF(_data.chEmEF[_idx]),
    chHEF(_data.chHEF[_idx]),
    muEF(_data.muEF[_idx]),
    neEmEF(_data.neEmEF[_idx]),
    neHEF(_data.neHEF[_idx]),
    qgl(_data.qgl[_idx]),
    rawFactor(_data.rawFactor[_idx]),
    bRegCorr(_data.bRegCorr[_idx]),
    bRegRes(_data.bRegRes[_idx]),
    electronIdx1(_data.electronIdx1[_idx]),
    electronIdx2(_data.electronIdx2[_idx]),
    jetId(_data.jetId[_idx]),
    muonIdx1(_data.muonIdx1[_idx]),
    muonIdx2(_data.muonIdx2[_idx]),
    nConstituents(_data.nConstituents[_idx]),
    nElectrons(_data.nElectrons[_idx]),
    nMuons(_data.nMuons[_idx]),
    puId(_data.puId[_idx]),
    genJetIdx(_data.genJetIdx[_idx]),
    hadronFlavour(_data.hadronFlavour[_idx]),
    partonFlavour(_data.partonFlavour[_idx]),
    cleanmask(_data.cleanmask[_idx])
  {
  }

  /*protected*/
  PJet::PJet(panda::ArrayBase* _array) :
    PRecoJet(_array),
    area(gStore.getData(this).area[0]),
    btagDeepC(gStore.getData(this).btagDeepC[0]),
    btagDeepFlavB(gStore.getData(this).btagDeepFlavB[0]),
    chEmEF(gStore.getData(this).chEmEF[0]),
    chHEF(gStore.getData(this).chHEF[0]),
    muEF(gStore.getData(this).muEF[0]),
    neEmEF(gStore.getData(this).neEmEF[0]),
    neHEF(gStore.getData(this).neHEF[0]),
    qgl(gStore.getData(this).qgl[0]),
    rawFactor(gStore.getData(this).rawFactor[0]),
    bRegCorr(gStore.getData(this).bRegCorr[0]),
    bRegRes(gStore.getData(this).bRegRes[0]),
    electronIdx1(gStore.getData(this).electronIdx1[0]),
    electronIdx2(gStore.getData(this).electronIdx2[0]),
    jetId(gStore.getData(this).jetId[0]),
    muonIdx1(gStore.getData(this).muonIdx1[0]),
    muonIdx2(gStore.getData(this).muonIdx2[0]),
    nConstituents(gStore.getData(this).nConstituents[0]),
    nElectrons(gStore.getData(this).nElectrons[0]),
    nMuons(gStore.getData(this).nMuons[0]),
    puId(gStore.getData(this).puId[0]),
    genJetIdx(gStore.getData(this).genJetIdx[0]),
    hadronFlavour(gStore.getData(this).hadronFlavour[0]),
    partonFlavour(gStore.getData(this).partonFlavour[0]),
    cleanmask(gStore.getData(this).cleanmask[0])
  {
  }

  PJet::~PJet()
  {
    destructor();
  }

  PJet&
  PJet::operator=(PJet const& _src)
  {
    PRecoJet::operator=(_src);

    area = _src.area;
    btagDeepC = _src.btagDeepC;
    btagDeepFlavB = _src.btagDeepFlavB;
    chEmEF = _src.chEmEF;
    chHEF = _src.chHEF;
    muEF = _src.muEF;
    neEmEF = _src.neEmEF;
    neHEF = _src.neHEF;
    qgl = _src.qgl;
    rawFactor = _src.rawFactor;
    bRegCorr = _src.bRegCorr;
    bRegRes = _src.bRegRes;
    electronIdx1 = _src.electronIdx1;
    electronIdx2 = _src.electronIdx2;
    jetId = _src.jetId;
    muonIdx1 = _src.muonIdx1;
    muonIdx2 = _src.muonIdx2;
    nConstituents = _src.nConstituents;
    nElectrons = _src.nElectrons;
    nMuons = _src.nMuons;
    puId = _src.puId;
    genJetIdx = _src.genJetIdx;
    hadronFlavour = _src.hadronFlavour;
    partonFlavour = _src.partonFlavour;
    cleanmask = _src.cleanmask;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PJet::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PRecoJet::destructor(kTRUE);
  }

  /*protected*/
  void
  PJet::doInit_()
  {
    PRecoJet::doInit_();

    area = 0.;
    btagDeepC = 0.;
    btagDeepFlavB = 0.;
    chEmEF = 0.;
    chHEF = 0.;
    muEF = 0.;
    neEmEF = 0.;
    neHEF = 0.;
    qgl = 0.;
    rawFactor = 0.;
    bRegCorr = 0.;
    bRegRes = 0.;
    electronIdx1 = 0;
    electronIdx2 = 0;
    jetId = 0;
    muonIdx1 = 0;
    muonIdx2 = 0;
    nConstituents = 0;
    nElectrons = 0;
    nMuons = 0;
    puId = 0;
    genJetIdx = 0;
    hadronFlavour = 0;
    partonFlavour = 0;
    cleanmask = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PJet::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PJet::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PRecoJet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "area = " << area << std::endl;
    _out << indentation << "btagDeepC = " << btagDeepC << std::endl;
    _out << indentation << "btagDeepFlavB = " << btagDeepFlavB << std::endl;
    _out << indentation << "chEmEF = " << chEmEF << std::endl;
    _out << indentation << "chHEF = " << chHEF << std::endl;
    _out << indentation << "muEF = " << muEF << std::endl;
    _out << indentation << "neEmEF = " << neEmEF << std::endl;
    _out << indentation << "neHEF = " << neHEF << std::endl;
    _out << indentation << "qgl = " << qgl << std::endl;
    _out << indentation << "rawFactor = " << rawFactor << std::endl;
    _out << indentation << "bRegCorr = " << bRegCorr << std::endl;
    _out << indentation << "bRegRes = " << bRegRes << std::endl;
    _out << indentation << "electronIdx1 = " << electronIdx1 << std::endl;
    _out << indentation << "electronIdx2 = " << electronIdx2 << std::endl;
    _out << indentation << "jetId = " << jetId << std::endl;
    _out << indentation << "muonIdx1 = " << muonIdx1 << std::endl;
    _out << indentation << "muonIdx2 = " << muonIdx2 << std::endl;
    _out << indentation << "nConstituents = " << nConstituents << std::endl;
    _out << indentation << "nElectrons = " << nElectrons << std::endl;
    _out << indentation << "nMuons = " << nMuons << std::endl;
    _out << indentation << "puId = " << puId << std::endl;
    _out << indentation << "genJetIdx = " << genJetIdx << std::endl;
    _out << indentation << "hadronFlavour = " << hadronFlavour << std::endl;
    _out << indentation << "partonFlavour = " << partonFlavour << std::endl;
    _out << indentation << "cleanmask = " << static_cast<const UInt_t>(cleanmask) << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

