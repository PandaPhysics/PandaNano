#include "../interface/PTau.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PTau>::branchNames{std::initializer_list<TString>{"size", "charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask", "mass", "pt", "eta", "phi", "chargedIso", "dxy", "dz", "leadTkDeltaEta", "leadTkDeltaPhi", "leadTkPtOverTauPt", "neutralIso", "photonsOutsideSignalCone", "puCorr", "rawAntiEle", "rawIso", "rawIsodR03", "decayMode", "rawAntiEleCat", "idAntiEle", "idAntiMu", "idDecayMode", "idDecayModeNewDMs"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PTau::branchNames{std::initializer_list<TString>{"charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask", "mass", "pt", "eta", "phi", "chargedIso", "dxy", "dz", "leadTkDeltaEta", "leadTkDeltaPhi", "leadTkPtOverTauPt", "neutralIso", "photonsOutsideSignalCone", "puCorr", "rawAntiEle", "rawIso", "rawIsodR03", "decayMode", "rawAntiEleCat", "idAntiEle", "idAntiMu", "idDecayMode", "idDecayModeNewDMs"}, panda::utils::BranchName::kAttrName};

  void
  PTau::datastore::allocate(UInt_t _nmax)
  {
    PRecoParticle::datastore::allocate(_nmax);

    chargedIso = new Float_t[nmax_];
    dxy = new Float_t[nmax_];
    dz = new Float_t[nmax_];
    leadTkDeltaEta = new Float_t[nmax_];
    leadTkDeltaPhi = new Float_t[nmax_];
    leadTkPtOverTauPt = new Float_t[nmax_];
    neutralIso = new Float_t[nmax_];
    photonsOutsideSignalCone = new Float_t[nmax_];
    puCorr = new Float_t[nmax_];
    rawAntiEle = new Float_t[nmax_];
    rawIso = new Float_t[nmax_];
    rawIsodR03 = new Float_t[nmax_];
    decayMode = new Int_t[nmax_];
    rawAntiEleCat = new Int_t[nmax_];
    idAntiEle = new UChar_t[nmax_];
    idAntiMu = new UChar_t[nmax_];
    idDecayMode = new Bool_t[nmax_];
    idDecayModeNewDMs = new Bool_t[nmax_];
  }

  void
  PTau::datastore::deallocate()
  {
    PRecoParticle::datastore::deallocate();

    delete [] chargedIso;
    chargedIso = 0;
    delete [] dxy;
    dxy = 0;
    delete [] dz;
    dz = 0;
    delete [] leadTkDeltaEta;
    leadTkDeltaEta = 0;
    delete [] leadTkDeltaPhi;
    leadTkDeltaPhi = 0;
    delete [] leadTkPtOverTauPt;
    leadTkPtOverTauPt = 0;
    delete [] neutralIso;
    neutralIso = 0;
    delete [] photonsOutsideSignalCone;
    photonsOutsideSignalCone = 0;
    delete [] puCorr;
    puCorr = 0;
    delete [] rawAntiEle;
    rawAntiEle = 0;
    delete [] rawIso;
    rawIso = 0;
    delete [] rawIsodR03;
    rawIsodR03 = 0;
    delete [] decayMode;
    decayMode = 0;
    delete [] rawAntiEleCat;
    rawAntiEleCat = 0;
    delete [] idAntiEle;
    idAntiEle = 0;
    delete [] idAntiMu;
    idAntiMu = 0;
    delete [] idDecayMode;
    idDecayMode = 0;
    delete [] idDecayModeNewDMs;
    idDecayModeNewDMs = 0;
  }

  void
  PTau::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PRecoParticle::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "chargedIso"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "dxy"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "dz"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "leadTkDeltaEta"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "leadTkDeltaPhi"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "leadTkPtOverTauPt"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "neutralIso"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "photonsOutsideSignalCone"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "puCorr"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "rawAntiEle"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "rawIso"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "rawIsodR03"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "decayMode"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "rawAntiEleCat"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "idAntiEle"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "idAntiMu"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "idDecayMode"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "idDecayModeNewDMs"), _branches);
  }

  void
  PTau::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PRecoParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "chargedIso"), chargedIso, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "dxy"), dxy, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "dz"), dz, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "leadTkDeltaEta"), leadTkDeltaEta, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "leadTkDeltaPhi"), leadTkDeltaPhi, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "leadTkPtOverTauPt"), leadTkPtOverTauPt, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "neutralIso"), neutralIso, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "photonsOutsideSignalCone"), photonsOutsideSignalCone, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "puCorr"), puCorr, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "rawAntiEle"), rawAntiEle, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "rawIso"), rawIso, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "rawIsodR03"), rawIsodR03, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "decayMode"), decayMode, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "rawAntiEleCat"), rawAntiEleCat, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "idAntiEle"), idAntiEle, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "idAntiMu"), idAntiMu, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "idDecayMode"), idDecayMode, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "idDecayModeNewDMs"), idDecayModeNewDMs, _branches, _setStatus);
  }

  void
  PTau::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
  {
    PRecoParticle::datastore::book(_tree, _name, _branches, _bookAs);

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

    panda::utils::book(_tree, BranchName(_name, "chargedIso"), size, 'F', chargedIso, _branches);
    panda::utils::book(_tree, BranchName(_name, "dxy"), size, 'F', dxy, _branches);
    panda::utils::book(_tree, BranchName(_name, "dz"), size, 'F', dz, _branches);
    panda::utils::book(_tree, BranchName(_name, "leadTkDeltaEta"), size, 'F', leadTkDeltaEta, _branches);
    panda::utils::book(_tree, BranchName(_name, "leadTkDeltaPhi"), size, 'F', leadTkDeltaPhi, _branches);
    panda::utils::book(_tree, BranchName(_name, "leadTkPtOverTauPt"), size, 'F', leadTkPtOverTauPt, _branches);
    panda::utils::book(_tree, BranchName(_name, "neutralIso"), size, 'F', neutralIso, _branches);
    panda::utils::book(_tree, BranchName(_name, "photonsOutsideSignalCone"), size, 'F', photonsOutsideSignalCone, _branches);
    panda::utils::book(_tree, BranchName(_name, "puCorr"), size, 'F', puCorr, _branches);
    panda::utils::book(_tree, BranchName(_name, "rawAntiEle"), size, 'F', rawAntiEle, _branches);
    panda::utils::book(_tree, BranchName(_name, "rawIso"), size, 'F', rawIso, _branches);
    panda::utils::book(_tree, BranchName(_name, "rawIsodR03"), size, 'F', rawIsodR03, _branches);
    panda::utils::book(_tree, BranchName(_name, "decayMode"), size, 'I', decayMode, _branches);
    panda::utils::book(_tree, BranchName(_name, "rawAntiEleCat"), size, 'I', rawAntiEleCat, _branches);
    panda::utils::book(_tree, BranchName(_name, "idAntiEle"), size, 'b', idAntiEle, _branches);
    panda::utils::book(_tree, BranchName(_name, "idAntiMu"), size, 'b', idAntiMu, _branches);
    panda::utils::book(_tree, BranchName(_name, "idDecayMode"), size, 'O', idDecayMode, _branches);
    panda::utils::book(_tree, BranchName(_name, "idDecayModeNewDMs"), size, 'O', idDecayModeNewDMs, _branches);
  }

  void
  PTau::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PRecoParticle::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "chargedIso"));
    panda::utils::resetAddress(_tree, BranchName(_name, "dxy"));
    panda::utils::resetAddress(_tree, BranchName(_name, "dz"));
    panda::utils::resetAddress(_tree, BranchName(_name, "leadTkDeltaEta"));
    panda::utils::resetAddress(_tree, BranchName(_name, "leadTkDeltaPhi"));
    panda::utils::resetAddress(_tree, BranchName(_name, "leadTkPtOverTauPt"));
    panda::utils::resetAddress(_tree, BranchName(_name, "neutralIso"));
    panda::utils::resetAddress(_tree, BranchName(_name, "photonsOutsideSignalCone"));
    panda::utils::resetAddress(_tree, BranchName(_name, "puCorr"));
    panda::utils::resetAddress(_tree, BranchName(_name, "rawAntiEle"));
    panda::utils::resetAddress(_tree, BranchName(_name, "rawIso"));
    panda::utils::resetAddress(_tree, BranchName(_name, "rawIsodR03"));
    panda::utils::resetAddress(_tree, BranchName(_name, "decayMode"));
    panda::utils::resetAddress(_tree, BranchName(_name, "rawAntiEleCat"));
    panda::utils::resetAddress(_tree, BranchName(_name, "idAntiEle"));
    panda::utils::resetAddress(_tree, BranchName(_name, "idAntiMu"));
    panda::utils::resetAddress(_tree, BranchName(_name, "idDecayMode"));
    panda::utils::resetAddress(_tree, BranchName(_name, "idDecayModeNewDMs"));
  }

  void
  PTau::datastore::resizeVectors_(UInt_t _size)
  {
    PRecoParticle::datastore::resizeVectors_(_size);

  }

  PTau::PTau(char const* _name/* = ""*/) :
    PRecoParticle(new PTauArray(1, _name)),
    chargedIso(gStore.getData(this).chargedIso[0]),
    dxy(gStore.getData(this).dxy[0]),
    dz(gStore.getData(this).dz[0]),
    leadTkDeltaEta(gStore.getData(this).leadTkDeltaEta[0]),
    leadTkDeltaPhi(gStore.getData(this).leadTkDeltaPhi[0]),
    leadTkPtOverTauPt(gStore.getData(this).leadTkPtOverTauPt[0]),
    neutralIso(gStore.getData(this).neutralIso[0]),
    photonsOutsideSignalCone(gStore.getData(this).photonsOutsideSignalCone[0]),
    puCorr(gStore.getData(this).puCorr[0]),
    rawAntiEle(gStore.getData(this).rawAntiEle[0]),
    rawIso(gStore.getData(this).rawIso[0]),
    rawIsodR03(gStore.getData(this).rawIsodR03[0]),
    decayMode(gStore.getData(this).decayMode[0]),
    rawAntiEleCat(gStore.getData(this).rawAntiEleCat[0]),
    idAntiEle(gStore.getData(this).idAntiEle[0]),
    idAntiMu(gStore.getData(this).idAntiMu[0]),
    idDecayMode(gStore.getData(this).idDecayMode[0]),
    idDecayModeNewDMs(gStore.getData(this).idDecayModeNewDMs[0])
  {
  }

  PTau::PTau(PTau const& _src) :
    PRecoParticle(new PTauArray(1, _src.getName())),
    chargedIso(gStore.getData(this).chargedIso[0]),
    dxy(gStore.getData(this).dxy[0]),
    dz(gStore.getData(this).dz[0]),
    leadTkDeltaEta(gStore.getData(this).leadTkDeltaEta[0]),
    leadTkDeltaPhi(gStore.getData(this).leadTkDeltaPhi[0]),
    leadTkPtOverTauPt(gStore.getData(this).leadTkPtOverTauPt[0]),
    neutralIso(gStore.getData(this).neutralIso[0]),
    photonsOutsideSignalCone(gStore.getData(this).photonsOutsideSignalCone[0]),
    puCorr(gStore.getData(this).puCorr[0]),
    rawAntiEle(gStore.getData(this).rawAntiEle[0]),
    rawIso(gStore.getData(this).rawIso[0]),
    rawIsodR03(gStore.getData(this).rawIsodR03[0]),
    decayMode(gStore.getData(this).decayMode[0]),
    rawAntiEleCat(gStore.getData(this).rawAntiEleCat[0]),
    idAntiEle(gStore.getData(this).idAntiEle[0]),
    idAntiMu(gStore.getData(this).idAntiMu[0]),
    idDecayMode(gStore.getData(this).idDecayMode[0]),
    idDecayModeNewDMs(gStore.getData(this).idDecayModeNewDMs[0])
  {
    PRecoParticle::operator=(_src);

    chargedIso = _src.chargedIso;
    dxy = _src.dxy;
    dz = _src.dz;
    leadTkDeltaEta = _src.leadTkDeltaEta;
    leadTkDeltaPhi = _src.leadTkDeltaPhi;
    leadTkPtOverTauPt = _src.leadTkPtOverTauPt;
    neutralIso = _src.neutralIso;
    photonsOutsideSignalCone = _src.photonsOutsideSignalCone;
    puCorr = _src.puCorr;
    rawAntiEle = _src.rawAntiEle;
    rawIso = _src.rawIso;
    rawIsodR03 = _src.rawIsodR03;
    decayMode = _src.decayMode;
    rawAntiEleCat = _src.rawAntiEleCat;
    idAntiEle = _src.idAntiEle;
    idAntiMu = _src.idAntiMu;
    idDecayMode = _src.idDecayMode;
    idDecayModeNewDMs = _src.idDecayModeNewDMs;
  }

  PTau::PTau(datastore& _data, UInt_t _idx) :
    PRecoParticle(_data, _idx),
    chargedIso(_data.chargedIso[_idx]),
    dxy(_data.dxy[_idx]),
    dz(_data.dz[_idx]),
    leadTkDeltaEta(_data.leadTkDeltaEta[_idx]),
    leadTkDeltaPhi(_data.leadTkDeltaPhi[_idx]),
    leadTkPtOverTauPt(_data.leadTkPtOverTauPt[_idx]),
    neutralIso(_data.neutralIso[_idx]),
    photonsOutsideSignalCone(_data.photonsOutsideSignalCone[_idx]),
    puCorr(_data.puCorr[_idx]),
    rawAntiEle(_data.rawAntiEle[_idx]),
    rawIso(_data.rawIso[_idx]),
    rawIsodR03(_data.rawIsodR03[_idx]),
    decayMode(_data.decayMode[_idx]),
    rawAntiEleCat(_data.rawAntiEleCat[_idx]),
    idAntiEle(_data.idAntiEle[_idx]),
    idAntiMu(_data.idAntiMu[_idx]),
    idDecayMode(_data.idDecayMode[_idx]),
    idDecayModeNewDMs(_data.idDecayModeNewDMs[_idx])
  {
  }

  /*protected*/
  PTau::PTau(panda::ArrayBase* _array) :
    PRecoParticle(_array),
    chargedIso(gStore.getData(this).chargedIso[0]),
    dxy(gStore.getData(this).dxy[0]),
    dz(gStore.getData(this).dz[0]),
    leadTkDeltaEta(gStore.getData(this).leadTkDeltaEta[0]),
    leadTkDeltaPhi(gStore.getData(this).leadTkDeltaPhi[0]),
    leadTkPtOverTauPt(gStore.getData(this).leadTkPtOverTauPt[0]),
    neutralIso(gStore.getData(this).neutralIso[0]),
    photonsOutsideSignalCone(gStore.getData(this).photonsOutsideSignalCone[0]),
    puCorr(gStore.getData(this).puCorr[0]),
    rawAntiEle(gStore.getData(this).rawAntiEle[0]),
    rawIso(gStore.getData(this).rawIso[0]),
    rawIsodR03(gStore.getData(this).rawIsodR03[0]),
    decayMode(gStore.getData(this).decayMode[0]),
    rawAntiEleCat(gStore.getData(this).rawAntiEleCat[0]),
    idAntiEle(gStore.getData(this).idAntiEle[0]),
    idAntiMu(gStore.getData(this).idAntiMu[0]),
    idDecayMode(gStore.getData(this).idDecayMode[0]),
    idDecayModeNewDMs(gStore.getData(this).idDecayModeNewDMs[0])
  {
  }

  PTau::~PTau()
  {
    destructor();
  }

  PTau&
  PTau::operator=(PTau const& _src)
  {
    PRecoParticle::operator=(_src);

    chargedIso = _src.chargedIso;
    dxy = _src.dxy;
    dz = _src.dz;
    leadTkDeltaEta = _src.leadTkDeltaEta;
    leadTkDeltaPhi = _src.leadTkDeltaPhi;
    leadTkPtOverTauPt = _src.leadTkPtOverTauPt;
    neutralIso = _src.neutralIso;
    photonsOutsideSignalCone = _src.photonsOutsideSignalCone;
    puCorr = _src.puCorr;
    rawAntiEle = _src.rawAntiEle;
    rawIso = _src.rawIso;
    rawIsodR03 = _src.rawIsodR03;
    decayMode = _src.decayMode;
    rawAntiEleCat = _src.rawAntiEleCat;
    idAntiEle = _src.idAntiEle;
    idAntiMu = _src.idAntiMu;
    idDecayMode = _src.idDecayMode;
    idDecayModeNewDMs = _src.idDecayModeNewDMs;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PTau::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PRecoParticle::destructor(kTRUE);
  }

  /*protected*/
  void
  PTau::doInit_()
  {
    PRecoParticle::doInit_();

    chargedIso = 0.;
    dxy = 0.;
    dz = 0.;
    leadTkDeltaEta = 0.;
    leadTkDeltaPhi = 0.;
    leadTkPtOverTauPt = 0.;
    neutralIso = 0.;
    photonsOutsideSignalCone = 0.;
    puCorr = 0.;
    rawAntiEle = 0.;
    rawIso = 0.;
    rawIsodR03 = 0.;
    decayMode = 0;
    rawAntiEleCat = 0;
    idAntiEle = 0;
    idAntiMu = 0;
    idDecayMode = false;
    idDecayModeNewDMs = false;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PTau::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PTau::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PRecoParticle::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "chargedIso = " << chargedIso << std::endl;
    _out << indentation << "dxy = " << dxy << std::endl;
    _out << indentation << "dz = " << dz << std::endl;
    _out << indentation << "leadTkDeltaEta = " << leadTkDeltaEta << std::endl;
    _out << indentation << "leadTkDeltaPhi = " << leadTkDeltaPhi << std::endl;
    _out << indentation << "leadTkPtOverTauPt = " << leadTkPtOverTauPt << std::endl;
    _out << indentation << "neutralIso = " << neutralIso << std::endl;
    _out << indentation << "photonsOutsideSignalCone = " << photonsOutsideSignalCone << std::endl;
    _out << indentation << "puCorr = " << puCorr << std::endl;
    _out << indentation << "rawAntiEle = " << rawAntiEle << std::endl;
    _out << indentation << "rawIso = " << rawIso << std::endl;
    _out << indentation << "rawIsodR03 = " << rawIsodR03 << std::endl;
    _out << indentation << "decayMode = " << decayMode << std::endl;
    _out << indentation << "rawAntiEleCat = " << rawAntiEleCat << std::endl;
    _out << indentation << "idAntiEle = " << static_cast<const UInt_t>(idAntiEle) << std::endl;
    _out << indentation << "idAntiMu = " << static_cast<const UInt_t>(idAntiMu) << std::endl;
    _out << indentation << "idDecayMode = " << idDecayMode << std::endl;
    _out << indentation << "idDecayModeNewDMs = " << idDecayModeNewDMs << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

