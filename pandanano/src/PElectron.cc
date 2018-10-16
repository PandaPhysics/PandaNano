#include "../interface/PElectron.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PElectron>::branchNames{std::initializer_list<TString>{"size", "dxy", "dxyErr", "dz", "dzErr", "ip3d", "miniPFRelIso_all", "miniPFRelIso_chg", "tightCharge", "isPFcand", "charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask", "mass", "pt", "eta", "phi", "deltaEtaSC", "dr03EcalRecHitSumEt", "dr03HcalDepth1TowerSumEt", "dr03TkSumPt", "eInvMinusPInv", "energyErr", "hoe", "pfRelIso03_all", "pfRelIso03_chg", "r9", "sieie", "sip3d", "mvaTTH", "cutBased", "cutBased_Fall17_V1", "photonIdx", "vidNestedWPBitmap", "convVeto", "cutBased_HEEP", "lostHits", "mvaFall17V1Iso", "mvaFall17V1noIso", "mvaFall17V2Iso", "mvaFall17V2noIso", "mvaFall17V1Iso_WP80", "mvaFall17V1Iso_WP90", "mvaFall17V1Iso_WPL", "mvaFall17V1noIso_WP80", "mvaFall17V1noIso_WP90", "mvaFall17V1noIso_WPL", "mvaFall17V2Iso_WP80", "mvaFall17V2Iso_WP90", "mvaFall17V2Iso_WPL", "mvaFall17V2noIso_WP80", "mvaFall17V2noIso_WP90", "mvaFall17V2noIso_WPL"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PElectron::branchNames{std::initializer_list<TString>{"dxy", "dxyErr", "dz", "dzErr", "ip3d", "miniPFRelIso_all", "miniPFRelIso_chg", "tightCharge", "isPFcand", "charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask", "mass", "pt", "eta", "phi", "deltaEtaSC", "dr03EcalRecHitSumEt", "dr03HcalDepth1TowerSumEt", "dr03TkSumPt", "eInvMinusPInv", "energyErr", "hoe", "pfRelIso03_all", "pfRelIso03_chg", "r9", "sieie", "sip3d", "mvaTTH", "cutBased", "cutBased_Fall17_V1", "photonIdx", "vidNestedWPBitmap", "convVeto", "cutBased_HEEP", "lostHits", "mvaFall17V1Iso", "mvaFall17V1noIso", "mvaFall17V2Iso", "mvaFall17V2noIso", "mvaFall17V1Iso_WP80", "mvaFall17V1Iso_WP90", "mvaFall17V1Iso_WPL", "mvaFall17V1noIso_WP80", "mvaFall17V1noIso_WP90", "mvaFall17V1noIso_WPL", "mvaFall17V2Iso_WP80", "mvaFall17V2Iso_WP90", "mvaFall17V2Iso_WPL", "mvaFall17V2noIso_WP80", "mvaFall17V2noIso_WP90", "mvaFall17V2noIso_WPL"}, panda::utils::BranchName::kAttrName};

  void
  PElectron::datastore::allocate(UInt_t _nmax)
  {
    PLepton::datastore::allocate(_nmax);

    deltaEtaSC = new Float_t[nmax_];
    dr03EcalRecHitSumEt = new Float_t[nmax_];
    dr03HcalDepth1TowerSumEt = new Float_t[nmax_];
    dr03TkSumPt = new Float_t[nmax_];
    eInvMinusPInv = new Float_t[nmax_];
    energyErr = new Float_t[nmax_];
    hoe = new Float_t[nmax_];
    pfRelIso03_all = new Float_t[nmax_];
    pfRelIso03_chg = new Float_t[nmax_];
    r9 = new Float_t[nmax_];
    sieie = new Float_t[nmax_];
    sip3d = new Float_t[nmax_];
    mvaTTH = new Float_t[nmax_];
    cutBased = new Int_t[nmax_];
    cutBased_Fall17_V1 = new Int_t[nmax_];
    photonIdx = new Int_t[nmax_];
    vidNestedWPBitmap = new Int_t[nmax_];
    convVeto = new Bool_t[nmax_];
    cutBased_HEEP = new Bool_t[nmax_];
    lostHits = new UChar_t[nmax_];
    mvaFall17V1Iso = new Float_t[nmax_];
    mvaFall17V1noIso = new Float_t[nmax_];
    mvaFall17V2Iso = new Float_t[nmax_];
    mvaFall17V2noIso = new Float_t[nmax_];
    mvaFall17V1Iso_WP80 = new Bool_t[nmax_];
    mvaFall17V1Iso_WP90 = new Bool_t[nmax_];
    mvaFall17V1Iso_WPL = new Bool_t[nmax_];
    mvaFall17V1noIso_WP80 = new Bool_t[nmax_];
    mvaFall17V1noIso_WP90 = new Bool_t[nmax_];
    mvaFall17V1noIso_WPL = new Bool_t[nmax_];
    mvaFall17V2Iso_WP80 = new Bool_t[nmax_];
    mvaFall17V2Iso_WP90 = new Bool_t[nmax_];
    mvaFall17V2Iso_WPL = new Bool_t[nmax_];
    mvaFall17V2noIso_WP80 = new Bool_t[nmax_];
    mvaFall17V2noIso_WP90 = new Bool_t[nmax_];
    mvaFall17V2noIso_WPL = new Bool_t[nmax_];
  }

  void
  PElectron::datastore::deallocate()
  {
    PLepton::datastore::deallocate();

    delete [] deltaEtaSC;
    deltaEtaSC = 0;
    delete [] dr03EcalRecHitSumEt;
    dr03EcalRecHitSumEt = 0;
    delete [] dr03HcalDepth1TowerSumEt;
    dr03HcalDepth1TowerSumEt = 0;
    delete [] dr03TkSumPt;
    dr03TkSumPt = 0;
    delete [] eInvMinusPInv;
    eInvMinusPInv = 0;
    delete [] energyErr;
    energyErr = 0;
    delete [] hoe;
    hoe = 0;
    delete [] pfRelIso03_all;
    pfRelIso03_all = 0;
    delete [] pfRelIso03_chg;
    pfRelIso03_chg = 0;
    delete [] r9;
    r9 = 0;
    delete [] sieie;
    sieie = 0;
    delete [] sip3d;
    sip3d = 0;
    delete [] mvaTTH;
    mvaTTH = 0;
    delete [] cutBased;
    cutBased = 0;
    delete [] cutBased_Fall17_V1;
    cutBased_Fall17_V1 = 0;
    delete [] photonIdx;
    photonIdx = 0;
    delete [] vidNestedWPBitmap;
    vidNestedWPBitmap = 0;
    delete [] convVeto;
    convVeto = 0;
    delete [] cutBased_HEEP;
    cutBased_HEEP = 0;
    delete [] lostHits;
    lostHits = 0;
    delete [] mvaFall17V1Iso;
    mvaFall17V1Iso = 0;
    delete [] mvaFall17V1noIso;
    mvaFall17V1noIso = 0;
    delete [] mvaFall17V2Iso;
    mvaFall17V2Iso = 0;
    delete [] mvaFall17V2noIso;
    mvaFall17V2noIso = 0;
    delete [] mvaFall17V1Iso_WP80;
    mvaFall17V1Iso_WP80 = 0;
    delete [] mvaFall17V1Iso_WP90;
    mvaFall17V1Iso_WP90 = 0;
    delete [] mvaFall17V1Iso_WPL;
    mvaFall17V1Iso_WPL = 0;
    delete [] mvaFall17V1noIso_WP80;
    mvaFall17V1noIso_WP80 = 0;
    delete [] mvaFall17V1noIso_WP90;
    mvaFall17V1noIso_WP90 = 0;
    delete [] mvaFall17V1noIso_WPL;
    mvaFall17V1noIso_WPL = 0;
    delete [] mvaFall17V2Iso_WP80;
    mvaFall17V2Iso_WP80 = 0;
    delete [] mvaFall17V2Iso_WP90;
    mvaFall17V2Iso_WP90 = 0;
    delete [] mvaFall17V2Iso_WPL;
    mvaFall17V2Iso_WPL = 0;
    delete [] mvaFall17V2noIso_WP80;
    mvaFall17V2noIso_WP80 = 0;
    delete [] mvaFall17V2noIso_WP90;
    mvaFall17V2noIso_WP90 = 0;
    delete [] mvaFall17V2noIso_WPL;
    mvaFall17V2noIso_WPL = 0;
  }

  void
  PElectron::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PLepton::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "deltaEtaSC"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "dr03EcalRecHitSumEt"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "dr03HcalDepth1TowerSumEt"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "dr03TkSumPt"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "eInvMinusPInv"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "energyErr"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "hoe"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pfRelIso03_all"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pfRelIso03_chg"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "r9"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "sieie"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "sip3d"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaTTH"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "cutBased"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "cutBased_Fall17_V1"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "photonIdx"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "vidNestedWPBitmap"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "convVeto"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "cutBased_HEEP"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "lostHits"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V1Iso"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V1noIso"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V2Iso"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V2noIso"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V1Iso_WP80"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V1Iso_WP90"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V1Iso_WPL"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V1noIso_WP80"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V1noIso_WP90"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V1noIso_WPL"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V2Iso_WP80"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V2Iso_WP90"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V2Iso_WPL"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V2noIso_WP80"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V2noIso_WP90"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaFall17V2noIso_WPL"), _branches);
  }

  void
  PElectron::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PLepton::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "deltaEtaSC"), deltaEtaSC, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "dr03EcalRecHitSumEt"), dr03EcalRecHitSumEt, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "dr03HcalDepth1TowerSumEt"), dr03HcalDepth1TowerSumEt, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "dr03TkSumPt"), dr03TkSumPt, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "eInvMinusPInv"), eInvMinusPInv, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "energyErr"), energyErr, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "hoe"), hoe, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pfRelIso03_all"), pfRelIso03_all, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pfRelIso03_chg"), pfRelIso03_chg, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "r9"), r9, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "sieie"), sieie, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "sip3d"), sip3d, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaTTH"), mvaTTH, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "cutBased"), cutBased, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "cutBased_Fall17_V1"), cutBased_Fall17_V1, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "photonIdx"), photonIdx, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "vidNestedWPBitmap"), vidNestedWPBitmap, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "convVeto"), convVeto, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "cutBased_HEEP"), cutBased_HEEP, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "lostHits"), lostHits, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V1Iso"), mvaFall17V1Iso, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V1noIso"), mvaFall17V1noIso, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V2Iso"), mvaFall17V2Iso, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V2noIso"), mvaFall17V2noIso, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V1Iso_WP80"), mvaFall17V1Iso_WP80, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V1Iso_WP90"), mvaFall17V1Iso_WP90, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V1Iso_WPL"), mvaFall17V1Iso_WPL, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V1noIso_WP80"), mvaFall17V1noIso_WP80, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V1noIso_WP90"), mvaFall17V1noIso_WP90, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V1noIso_WPL"), mvaFall17V1noIso_WPL, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V2Iso_WP80"), mvaFall17V2Iso_WP80, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V2Iso_WP90"), mvaFall17V2Iso_WP90, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V2Iso_WPL"), mvaFall17V2Iso_WPL, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V2noIso_WP80"), mvaFall17V2noIso_WP80, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V2noIso_WP90"), mvaFall17V2noIso_WP90, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaFall17V2noIso_WPL"), mvaFall17V2noIso_WPL, _branches, _setStatus);
  }

  void
  PElectron::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
  {
    PLepton::datastore::book(_tree, _name, _branches, _bookAs);

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

    panda::utils::book(_tree, BranchName(_name, "deltaEtaSC"), size, 'F', deltaEtaSC, _branches);
    panda::utils::book(_tree, BranchName(_name, "dr03EcalRecHitSumEt"), size, 'F', dr03EcalRecHitSumEt, _branches);
    panda::utils::book(_tree, BranchName(_name, "dr03HcalDepth1TowerSumEt"), size, 'F', dr03HcalDepth1TowerSumEt, _branches);
    panda::utils::book(_tree, BranchName(_name, "dr03TkSumPt"), size, 'F', dr03TkSumPt, _branches);
    panda::utils::book(_tree, BranchName(_name, "eInvMinusPInv"), size, 'F', eInvMinusPInv, _branches);
    panda::utils::book(_tree, BranchName(_name, "energyErr"), size, 'F', energyErr, _branches);
    panda::utils::book(_tree, BranchName(_name, "hoe"), size, 'F', hoe, _branches);
    panda::utils::book(_tree, BranchName(_name, "pfRelIso03_all"), size, 'F', pfRelIso03_all, _branches);
    panda::utils::book(_tree, BranchName(_name, "pfRelIso03_chg"), size, 'F', pfRelIso03_chg, _branches);
    panda::utils::book(_tree, BranchName(_name, "r9"), size, 'F', r9, _branches);
    panda::utils::book(_tree, BranchName(_name, "sieie"), size, 'F', sieie, _branches);
    panda::utils::book(_tree, BranchName(_name, "sip3d"), size, 'F', sip3d, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaTTH"), size, 'F', mvaTTH, _branches);
    panda::utils::book(_tree, BranchName(_name, "cutBased"), size, 'I', cutBased, _branches);
    panda::utils::book(_tree, BranchName(_name, "cutBased_Fall17_V1"), size, 'I', cutBased_Fall17_V1, _branches);
    panda::utils::book(_tree, BranchName(_name, "photonIdx"), size, 'I', photonIdx, _branches);
    panda::utils::book(_tree, BranchName(_name, "vidNestedWPBitmap"), size, 'I', vidNestedWPBitmap, _branches);
    panda::utils::book(_tree, BranchName(_name, "convVeto"), size, 'O', convVeto, _branches);
    panda::utils::book(_tree, BranchName(_name, "cutBased_HEEP"), size, 'O', cutBased_HEEP, _branches);
    panda::utils::book(_tree, BranchName(_name, "lostHits"), size, 'b', lostHits, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V1Iso"), size, 'F', mvaFall17V1Iso, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V1noIso"), size, 'F', mvaFall17V1noIso, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V2Iso"), size, 'F', mvaFall17V2Iso, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V2noIso"), size, 'F', mvaFall17V2noIso, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V1Iso_WP80"), size, 'O', mvaFall17V1Iso_WP80, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V1Iso_WP90"), size, 'O', mvaFall17V1Iso_WP90, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V1Iso_WPL"), size, 'O', mvaFall17V1Iso_WPL, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V1noIso_WP80"), size, 'O', mvaFall17V1noIso_WP80, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V1noIso_WP90"), size, 'O', mvaFall17V1noIso_WP90, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V1noIso_WPL"), size, 'O', mvaFall17V1noIso_WPL, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V2Iso_WP80"), size, 'O', mvaFall17V2Iso_WP80, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V2Iso_WP90"), size, 'O', mvaFall17V2Iso_WP90, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V2Iso_WPL"), size, 'O', mvaFall17V2Iso_WPL, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V2noIso_WP80"), size, 'O', mvaFall17V2noIso_WP80, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V2noIso_WP90"), size, 'O', mvaFall17V2noIso_WP90, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaFall17V2noIso_WPL"), size, 'O', mvaFall17V2noIso_WPL, _branches);
  }

  void
  PElectron::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PLepton::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "deltaEtaSC"));
    panda::utils::resetAddress(_tree, BranchName(_name, "dr03EcalRecHitSumEt"));
    panda::utils::resetAddress(_tree, BranchName(_name, "dr03HcalDepth1TowerSumEt"));
    panda::utils::resetAddress(_tree, BranchName(_name, "dr03TkSumPt"));
    panda::utils::resetAddress(_tree, BranchName(_name, "eInvMinusPInv"));
    panda::utils::resetAddress(_tree, BranchName(_name, "energyErr"));
    panda::utils::resetAddress(_tree, BranchName(_name, "hoe"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pfRelIso03_all"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pfRelIso03_chg"));
    panda::utils::resetAddress(_tree, BranchName(_name, "r9"));
    panda::utils::resetAddress(_tree, BranchName(_name, "sieie"));
    panda::utils::resetAddress(_tree, BranchName(_name, "sip3d"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaTTH"));
    panda::utils::resetAddress(_tree, BranchName(_name, "cutBased"));
    panda::utils::resetAddress(_tree, BranchName(_name, "cutBased_Fall17_V1"));
    panda::utils::resetAddress(_tree, BranchName(_name, "photonIdx"));
    panda::utils::resetAddress(_tree, BranchName(_name, "vidNestedWPBitmap"));
    panda::utils::resetAddress(_tree, BranchName(_name, "convVeto"));
    panda::utils::resetAddress(_tree, BranchName(_name, "cutBased_HEEP"));
    panda::utils::resetAddress(_tree, BranchName(_name, "lostHits"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V1Iso"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V1noIso"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V2Iso"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V2noIso"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V1Iso_WP80"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V1Iso_WP90"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V1Iso_WPL"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V1noIso_WP80"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V1noIso_WP90"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V1noIso_WPL"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V2Iso_WP80"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V2Iso_WP90"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V2Iso_WPL"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V2noIso_WP80"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V2noIso_WP90"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaFall17V2noIso_WPL"));
  }

  void
  PElectron::datastore::resizeVectors_(UInt_t _size)
  {
    PLepton::datastore::resizeVectors_(_size);

  }

  PElectron::PElectron(char const* _name/* = ""*/) :
    PLepton(new PElectronArray(1, _name)),
    deltaEtaSC(gStore.getData(this).deltaEtaSC[0]),
    dr03EcalRecHitSumEt(gStore.getData(this).dr03EcalRecHitSumEt[0]),
    dr03HcalDepth1TowerSumEt(gStore.getData(this).dr03HcalDepth1TowerSumEt[0]),
    dr03TkSumPt(gStore.getData(this).dr03TkSumPt[0]),
    eInvMinusPInv(gStore.getData(this).eInvMinusPInv[0]),
    energyErr(gStore.getData(this).energyErr[0]),
    hoe(gStore.getData(this).hoe[0]),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    r9(gStore.getData(this).r9[0]),
    sieie(gStore.getData(this).sieie[0]),
    sip3d(gStore.getData(this).sip3d[0]),
    mvaTTH(gStore.getData(this).mvaTTH[0]),
    cutBased(gStore.getData(this).cutBased[0]),
    cutBased_Fall17_V1(gStore.getData(this).cutBased_Fall17_V1[0]),
    photonIdx(gStore.getData(this).photonIdx[0]),
    vidNestedWPBitmap(gStore.getData(this).vidNestedWPBitmap[0]),
    convVeto(gStore.getData(this).convVeto[0]),
    cutBased_HEEP(gStore.getData(this).cutBased_HEEP[0]),
    lostHits(gStore.getData(this).lostHits[0]),
    mvaFall17V1Iso(gStore.getData(this).mvaFall17V1Iso[0]),
    mvaFall17V1noIso(gStore.getData(this).mvaFall17V1noIso[0]),
    mvaFall17V2Iso(gStore.getData(this).mvaFall17V2Iso[0]),
    mvaFall17V2noIso(gStore.getData(this).mvaFall17V2noIso[0]),
    mvaFall17V1Iso_WP80(gStore.getData(this).mvaFall17V1Iso_WP80[0]),
    mvaFall17V1Iso_WP90(gStore.getData(this).mvaFall17V1Iso_WP90[0]),
    mvaFall17V1Iso_WPL(gStore.getData(this).mvaFall17V1Iso_WPL[0]),
    mvaFall17V1noIso_WP80(gStore.getData(this).mvaFall17V1noIso_WP80[0]),
    mvaFall17V1noIso_WP90(gStore.getData(this).mvaFall17V1noIso_WP90[0]),
    mvaFall17V1noIso_WPL(gStore.getData(this).mvaFall17V1noIso_WPL[0]),
    mvaFall17V2Iso_WP80(gStore.getData(this).mvaFall17V2Iso_WP80[0]),
    mvaFall17V2Iso_WP90(gStore.getData(this).mvaFall17V2Iso_WP90[0]),
    mvaFall17V2Iso_WPL(gStore.getData(this).mvaFall17V2Iso_WPL[0]),
    mvaFall17V2noIso_WP80(gStore.getData(this).mvaFall17V2noIso_WP80[0]),
    mvaFall17V2noIso_WP90(gStore.getData(this).mvaFall17V2noIso_WP90[0]),
    mvaFall17V2noIso_WPL(gStore.getData(this).mvaFall17V2noIso_WPL[0])
  {
  }

  PElectron::PElectron(PElectron const& _src) :
    PLepton(new PElectronArray(1, _src.getName())),
    deltaEtaSC(gStore.getData(this).deltaEtaSC[0]),
    dr03EcalRecHitSumEt(gStore.getData(this).dr03EcalRecHitSumEt[0]),
    dr03HcalDepth1TowerSumEt(gStore.getData(this).dr03HcalDepth1TowerSumEt[0]),
    dr03TkSumPt(gStore.getData(this).dr03TkSumPt[0]),
    eInvMinusPInv(gStore.getData(this).eInvMinusPInv[0]),
    energyErr(gStore.getData(this).energyErr[0]),
    hoe(gStore.getData(this).hoe[0]),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    r9(gStore.getData(this).r9[0]),
    sieie(gStore.getData(this).sieie[0]),
    sip3d(gStore.getData(this).sip3d[0]),
    mvaTTH(gStore.getData(this).mvaTTH[0]),
    cutBased(gStore.getData(this).cutBased[0]),
    cutBased_Fall17_V1(gStore.getData(this).cutBased_Fall17_V1[0]),
    photonIdx(gStore.getData(this).photonIdx[0]),
    vidNestedWPBitmap(gStore.getData(this).vidNestedWPBitmap[0]),
    convVeto(gStore.getData(this).convVeto[0]),
    cutBased_HEEP(gStore.getData(this).cutBased_HEEP[0]),
    lostHits(gStore.getData(this).lostHits[0]),
    mvaFall17V1Iso(gStore.getData(this).mvaFall17V1Iso[0]),
    mvaFall17V1noIso(gStore.getData(this).mvaFall17V1noIso[0]),
    mvaFall17V2Iso(gStore.getData(this).mvaFall17V2Iso[0]),
    mvaFall17V2noIso(gStore.getData(this).mvaFall17V2noIso[0]),
    mvaFall17V1Iso_WP80(gStore.getData(this).mvaFall17V1Iso_WP80[0]),
    mvaFall17V1Iso_WP90(gStore.getData(this).mvaFall17V1Iso_WP90[0]),
    mvaFall17V1Iso_WPL(gStore.getData(this).mvaFall17V1Iso_WPL[0]),
    mvaFall17V1noIso_WP80(gStore.getData(this).mvaFall17V1noIso_WP80[0]),
    mvaFall17V1noIso_WP90(gStore.getData(this).mvaFall17V1noIso_WP90[0]),
    mvaFall17V1noIso_WPL(gStore.getData(this).mvaFall17V1noIso_WPL[0]),
    mvaFall17V2Iso_WP80(gStore.getData(this).mvaFall17V2Iso_WP80[0]),
    mvaFall17V2Iso_WP90(gStore.getData(this).mvaFall17V2Iso_WP90[0]),
    mvaFall17V2Iso_WPL(gStore.getData(this).mvaFall17V2Iso_WPL[0]),
    mvaFall17V2noIso_WP80(gStore.getData(this).mvaFall17V2noIso_WP80[0]),
    mvaFall17V2noIso_WP90(gStore.getData(this).mvaFall17V2noIso_WP90[0]),
    mvaFall17V2noIso_WPL(gStore.getData(this).mvaFall17V2noIso_WPL[0])
  {
    PLepton::operator=(_src);

    deltaEtaSC = _src.deltaEtaSC;
    dr03EcalRecHitSumEt = _src.dr03EcalRecHitSumEt;
    dr03HcalDepth1TowerSumEt = _src.dr03HcalDepth1TowerSumEt;
    dr03TkSumPt = _src.dr03TkSumPt;
    eInvMinusPInv = _src.eInvMinusPInv;
    energyErr = _src.energyErr;
    hoe = _src.hoe;
    pfRelIso03_all = _src.pfRelIso03_all;
    pfRelIso03_chg = _src.pfRelIso03_chg;
    r9 = _src.r9;
    sieie = _src.sieie;
    sip3d = _src.sip3d;
    mvaTTH = _src.mvaTTH;
    cutBased = _src.cutBased;
    cutBased_Fall17_V1 = _src.cutBased_Fall17_V1;
    photonIdx = _src.photonIdx;
    vidNestedWPBitmap = _src.vidNestedWPBitmap;
    convVeto = _src.convVeto;
    cutBased_HEEP = _src.cutBased_HEEP;
    lostHits = _src.lostHits;
    mvaFall17V1Iso = _src.mvaFall17V1Iso;
    mvaFall17V1noIso = _src.mvaFall17V1noIso;
    mvaFall17V2Iso = _src.mvaFall17V2Iso;
    mvaFall17V2noIso = _src.mvaFall17V2noIso;
    mvaFall17V1Iso_WP80 = _src.mvaFall17V1Iso_WP80;
    mvaFall17V1Iso_WP90 = _src.mvaFall17V1Iso_WP90;
    mvaFall17V1Iso_WPL = _src.mvaFall17V1Iso_WPL;
    mvaFall17V1noIso_WP80 = _src.mvaFall17V1noIso_WP80;
    mvaFall17V1noIso_WP90 = _src.mvaFall17V1noIso_WP90;
    mvaFall17V1noIso_WPL = _src.mvaFall17V1noIso_WPL;
    mvaFall17V2Iso_WP80 = _src.mvaFall17V2Iso_WP80;
    mvaFall17V2Iso_WP90 = _src.mvaFall17V2Iso_WP90;
    mvaFall17V2Iso_WPL = _src.mvaFall17V2Iso_WPL;
    mvaFall17V2noIso_WP80 = _src.mvaFall17V2noIso_WP80;
    mvaFall17V2noIso_WP90 = _src.mvaFall17V2noIso_WP90;
    mvaFall17V2noIso_WPL = _src.mvaFall17V2noIso_WPL;
  }

  PElectron::PElectron(datastore& _data, UInt_t _idx) :
    PLepton(_data, _idx),
    deltaEtaSC(_data.deltaEtaSC[_idx]),
    dr03EcalRecHitSumEt(_data.dr03EcalRecHitSumEt[_idx]),
    dr03HcalDepth1TowerSumEt(_data.dr03HcalDepth1TowerSumEt[_idx]),
    dr03TkSumPt(_data.dr03TkSumPt[_idx]),
    eInvMinusPInv(_data.eInvMinusPInv[_idx]),
    energyErr(_data.energyErr[_idx]),
    hoe(_data.hoe[_idx]),
    pfRelIso03_all(_data.pfRelIso03_all[_idx]),
    pfRelIso03_chg(_data.pfRelIso03_chg[_idx]),
    r9(_data.r9[_idx]),
    sieie(_data.sieie[_idx]),
    sip3d(_data.sip3d[_idx]),
    mvaTTH(_data.mvaTTH[_idx]),
    cutBased(_data.cutBased[_idx]),
    cutBased_Fall17_V1(_data.cutBased_Fall17_V1[_idx]),
    photonIdx(_data.photonIdx[_idx]),
    vidNestedWPBitmap(_data.vidNestedWPBitmap[_idx]),
    convVeto(_data.convVeto[_idx]),
    cutBased_HEEP(_data.cutBased_HEEP[_idx]),
    lostHits(_data.lostHits[_idx]),
    mvaFall17V1Iso(_data.mvaFall17V1Iso[_idx]),
    mvaFall17V1noIso(_data.mvaFall17V1noIso[_idx]),
    mvaFall17V2Iso(_data.mvaFall17V2Iso[_idx]),
    mvaFall17V2noIso(_data.mvaFall17V2noIso[_idx]),
    mvaFall17V1Iso_WP80(_data.mvaFall17V1Iso_WP80[_idx]),
    mvaFall17V1Iso_WP90(_data.mvaFall17V1Iso_WP90[_idx]),
    mvaFall17V1Iso_WPL(_data.mvaFall17V1Iso_WPL[_idx]),
    mvaFall17V1noIso_WP80(_data.mvaFall17V1noIso_WP80[_idx]),
    mvaFall17V1noIso_WP90(_data.mvaFall17V1noIso_WP90[_idx]),
    mvaFall17V1noIso_WPL(_data.mvaFall17V1noIso_WPL[_idx]),
    mvaFall17V2Iso_WP80(_data.mvaFall17V2Iso_WP80[_idx]),
    mvaFall17V2Iso_WP90(_data.mvaFall17V2Iso_WP90[_idx]),
    mvaFall17V2Iso_WPL(_data.mvaFall17V2Iso_WPL[_idx]),
    mvaFall17V2noIso_WP80(_data.mvaFall17V2noIso_WP80[_idx]),
    mvaFall17V2noIso_WP90(_data.mvaFall17V2noIso_WP90[_idx]),
    mvaFall17V2noIso_WPL(_data.mvaFall17V2noIso_WPL[_idx])
  {
  }

  /*protected*/
  PElectron::PElectron(panda::ArrayBase* _array) :
    PLepton(_array),
    deltaEtaSC(gStore.getData(this).deltaEtaSC[0]),
    dr03EcalRecHitSumEt(gStore.getData(this).dr03EcalRecHitSumEt[0]),
    dr03HcalDepth1TowerSumEt(gStore.getData(this).dr03HcalDepth1TowerSumEt[0]),
    dr03TkSumPt(gStore.getData(this).dr03TkSumPt[0]),
    eInvMinusPInv(gStore.getData(this).eInvMinusPInv[0]),
    energyErr(gStore.getData(this).energyErr[0]),
    hoe(gStore.getData(this).hoe[0]),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    r9(gStore.getData(this).r9[0]),
    sieie(gStore.getData(this).sieie[0]),
    sip3d(gStore.getData(this).sip3d[0]),
    mvaTTH(gStore.getData(this).mvaTTH[0]),
    cutBased(gStore.getData(this).cutBased[0]),
    cutBased_Fall17_V1(gStore.getData(this).cutBased_Fall17_V1[0]),
    photonIdx(gStore.getData(this).photonIdx[0]),
    vidNestedWPBitmap(gStore.getData(this).vidNestedWPBitmap[0]),
    convVeto(gStore.getData(this).convVeto[0]),
    cutBased_HEEP(gStore.getData(this).cutBased_HEEP[0]),
    lostHits(gStore.getData(this).lostHits[0]),
    mvaFall17V1Iso(gStore.getData(this).mvaFall17V1Iso[0]),
    mvaFall17V1noIso(gStore.getData(this).mvaFall17V1noIso[0]),
    mvaFall17V2Iso(gStore.getData(this).mvaFall17V2Iso[0]),
    mvaFall17V2noIso(gStore.getData(this).mvaFall17V2noIso[0]),
    mvaFall17V1Iso_WP80(gStore.getData(this).mvaFall17V1Iso_WP80[0]),
    mvaFall17V1Iso_WP90(gStore.getData(this).mvaFall17V1Iso_WP90[0]),
    mvaFall17V1Iso_WPL(gStore.getData(this).mvaFall17V1Iso_WPL[0]),
    mvaFall17V1noIso_WP80(gStore.getData(this).mvaFall17V1noIso_WP80[0]),
    mvaFall17V1noIso_WP90(gStore.getData(this).mvaFall17V1noIso_WP90[0]),
    mvaFall17V1noIso_WPL(gStore.getData(this).mvaFall17V1noIso_WPL[0]),
    mvaFall17V2Iso_WP80(gStore.getData(this).mvaFall17V2Iso_WP80[0]),
    mvaFall17V2Iso_WP90(gStore.getData(this).mvaFall17V2Iso_WP90[0]),
    mvaFall17V2Iso_WPL(gStore.getData(this).mvaFall17V2Iso_WPL[0]),
    mvaFall17V2noIso_WP80(gStore.getData(this).mvaFall17V2noIso_WP80[0]),
    mvaFall17V2noIso_WP90(gStore.getData(this).mvaFall17V2noIso_WP90[0]),
    mvaFall17V2noIso_WPL(gStore.getData(this).mvaFall17V2noIso_WPL[0])
  {
  }

  PElectron::~PElectron()
  {
    destructor();
  }

  PElectron&
  PElectron::operator=(PElectron const& _src)
  {
    PLepton::operator=(_src);

    deltaEtaSC = _src.deltaEtaSC;
    dr03EcalRecHitSumEt = _src.dr03EcalRecHitSumEt;
    dr03HcalDepth1TowerSumEt = _src.dr03HcalDepth1TowerSumEt;
    dr03TkSumPt = _src.dr03TkSumPt;
    eInvMinusPInv = _src.eInvMinusPInv;
    energyErr = _src.energyErr;
    hoe = _src.hoe;
    pfRelIso03_all = _src.pfRelIso03_all;
    pfRelIso03_chg = _src.pfRelIso03_chg;
    r9 = _src.r9;
    sieie = _src.sieie;
    sip3d = _src.sip3d;
    mvaTTH = _src.mvaTTH;
    cutBased = _src.cutBased;
    cutBased_Fall17_V1 = _src.cutBased_Fall17_V1;
    photonIdx = _src.photonIdx;
    vidNestedWPBitmap = _src.vidNestedWPBitmap;
    convVeto = _src.convVeto;
    cutBased_HEEP = _src.cutBased_HEEP;
    lostHits = _src.lostHits;
    mvaFall17V1Iso = _src.mvaFall17V1Iso;
    mvaFall17V1noIso = _src.mvaFall17V1noIso;
    mvaFall17V2Iso = _src.mvaFall17V2Iso;
    mvaFall17V2noIso = _src.mvaFall17V2noIso;
    mvaFall17V1Iso_WP80 = _src.mvaFall17V1Iso_WP80;
    mvaFall17V1Iso_WP90 = _src.mvaFall17V1Iso_WP90;
    mvaFall17V1Iso_WPL = _src.mvaFall17V1Iso_WPL;
    mvaFall17V1noIso_WP80 = _src.mvaFall17V1noIso_WP80;
    mvaFall17V1noIso_WP90 = _src.mvaFall17V1noIso_WP90;
    mvaFall17V1noIso_WPL = _src.mvaFall17V1noIso_WPL;
    mvaFall17V2Iso_WP80 = _src.mvaFall17V2Iso_WP80;
    mvaFall17V2Iso_WP90 = _src.mvaFall17V2Iso_WP90;
    mvaFall17V2Iso_WPL = _src.mvaFall17V2Iso_WPL;
    mvaFall17V2noIso_WP80 = _src.mvaFall17V2noIso_WP80;
    mvaFall17V2noIso_WP90 = _src.mvaFall17V2noIso_WP90;
    mvaFall17V2noIso_WPL = _src.mvaFall17V2noIso_WPL;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PElectron::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PLepton::destructor(kTRUE);
  }

  /*protected*/
  void
  PElectron::doInit_()
  {
    PLepton::doInit_();

    deltaEtaSC = 0.;
    dr03EcalRecHitSumEt = 0.;
    dr03HcalDepth1TowerSumEt = 0.;
    dr03TkSumPt = 0.;
    eInvMinusPInv = 0.;
    energyErr = 0.;
    hoe = 0.;
    pfRelIso03_all = 0.;
    pfRelIso03_chg = 0.;
    r9 = 0.;
    sieie = 0.;
    sip3d = 0.;
    mvaTTH = 0.;
    cutBased = 0;
    cutBased_Fall17_V1 = 0;
    photonIdx = 0;
    vidNestedWPBitmap = 0;
    convVeto = false;
    cutBased_HEEP = false;
    lostHits = 0;
    mvaFall17V1Iso = 0.;
    mvaFall17V1noIso = 0.;
    mvaFall17V2Iso = 0.;
    mvaFall17V2noIso = 0.;
    mvaFall17V1Iso_WP80 = false;
    mvaFall17V1Iso_WP90 = false;
    mvaFall17V1Iso_WPL = false;
    mvaFall17V1noIso_WP80 = false;
    mvaFall17V1noIso_WP90 = false;
    mvaFall17V1noIso_WPL = false;
    mvaFall17V2Iso_WP80 = false;
    mvaFall17V2Iso_WP90 = false;
    mvaFall17V2Iso_WPL = false;
    mvaFall17V2noIso_WP80 = false;
    mvaFall17V2noIso_WP90 = false;
    mvaFall17V2noIso_WPL = false;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PElectron::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PElectron::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PLepton::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "deltaEtaSC = " << deltaEtaSC << std::endl;
    _out << indentation << "dr03EcalRecHitSumEt = " << dr03EcalRecHitSumEt << std::endl;
    _out << indentation << "dr03HcalDepth1TowerSumEt = " << dr03HcalDepth1TowerSumEt << std::endl;
    _out << indentation << "dr03TkSumPt = " << dr03TkSumPt << std::endl;
    _out << indentation << "eInvMinusPInv = " << eInvMinusPInv << std::endl;
    _out << indentation << "energyErr = " << energyErr << std::endl;
    _out << indentation << "hoe = " << hoe << std::endl;
    _out << indentation << "pfRelIso03_all = " << pfRelIso03_all << std::endl;
    _out << indentation << "pfRelIso03_chg = " << pfRelIso03_chg << std::endl;
    _out << indentation << "r9 = " << r9 << std::endl;
    _out << indentation << "sieie = " << sieie << std::endl;
    _out << indentation << "sip3d = " << sip3d << std::endl;
    _out << indentation << "mvaTTH = " << mvaTTH << std::endl;
    _out << indentation << "cutBased = " << cutBased << std::endl;
    _out << indentation << "cutBased_Fall17_V1 = " << cutBased_Fall17_V1 << std::endl;
    _out << indentation << "photonIdx = " << photonIdx << std::endl;
    _out << indentation << "vidNestedWPBitmap = " << vidNestedWPBitmap << std::endl;
    _out << indentation << "convVeto = " << convVeto << std::endl;
    _out << indentation << "cutBased_HEEP = " << cutBased_HEEP << std::endl;
    _out << indentation << "lostHits = " << static_cast<const UInt_t>(lostHits) << std::endl;
    _out << indentation << "mvaFall17V1Iso = " << mvaFall17V1Iso << std::endl;
    _out << indentation << "mvaFall17V1noIso = " << mvaFall17V1noIso << std::endl;
    _out << indentation << "mvaFall17V2Iso = " << mvaFall17V2Iso << std::endl;
    _out << indentation << "mvaFall17V2noIso = " << mvaFall17V2noIso << std::endl;
    _out << indentation << "mvaFall17V1Iso_WP80 = " << mvaFall17V1Iso_WP80 << std::endl;
    _out << indentation << "mvaFall17V1Iso_WP90 = " << mvaFall17V1Iso_WP90 << std::endl;
    _out << indentation << "mvaFall17V1Iso_WPL = " << mvaFall17V1Iso_WPL << std::endl;
    _out << indentation << "mvaFall17V1noIso_WP80 = " << mvaFall17V1noIso_WP80 << std::endl;
    _out << indentation << "mvaFall17V1noIso_WP90 = " << mvaFall17V1noIso_WP90 << std::endl;
    _out << indentation << "mvaFall17V1noIso_WPL = " << mvaFall17V1noIso_WPL << std::endl;
    _out << indentation << "mvaFall17V2Iso_WP80 = " << mvaFall17V2Iso_WP80 << std::endl;
    _out << indentation << "mvaFall17V2Iso_WP90 = " << mvaFall17V2Iso_WP90 << std::endl;
    _out << indentation << "mvaFall17V2Iso_WPL = " << mvaFall17V2Iso_WPL << std::endl;
    _out << indentation << "mvaFall17V2noIso_WP80 = " << mvaFall17V2noIso_WP80 << std::endl;
    _out << indentation << "mvaFall17V2noIso_WP90 = " << mvaFall17V2noIso_WP90 << std::endl;
    _out << indentation << "mvaFall17V2noIso_WPL = " << mvaFall17V2noIso_WPL << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

