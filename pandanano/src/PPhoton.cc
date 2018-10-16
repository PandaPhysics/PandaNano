#include "../interface/PPhoton.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PPhoton>::branchNames{std::initializer_list<TString>{"size", "charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask", "mass", "pt", "eta", "phi", "energyErr", "hoe", "mvaID", "pfRelIso03_all", "pfRelIso03_chg", "r9", "sieie", "cutBasedBitmap", "electronIdx", "vidNestedWPBitmap", "electronVeto", "isScEtaEB", "isScEtaEE", "mvaID_WP80", "mvaID_WP90", "pixelSeed"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PPhoton::branchNames{std::initializer_list<TString>{"charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask", "mass", "pt", "eta", "phi", "energyErr", "hoe", "mvaID", "pfRelIso03_all", "pfRelIso03_chg", "r9", "sieie", "cutBasedBitmap", "electronIdx", "vidNestedWPBitmap", "electronVeto", "isScEtaEB", "isScEtaEE", "mvaID_WP80", "mvaID_WP90", "pixelSeed"}, panda::utils::BranchName::kAttrName};

  void
  PPhoton::datastore::allocate(UInt_t _nmax)
  {
    PRecoParticle::datastore::allocate(_nmax);

    energyErr = new Float_t[nmax_];
    hoe = new Float_t[nmax_];
    mvaID = new Float_t[nmax_];
    pfRelIso03_all = new Float_t[nmax_];
    pfRelIso03_chg = new Float_t[nmax_];
    r9 = new Float_t[nmax_];
    sieie = new Float_t[nmax_];
    cutBasedBitmap = new Int_t[nmax_];
    electronIdx = new Int_t[nmax_];
    vidNestedWPBitmap = new Int_t[nmax_];
    electronVeto = new Bool_t[nmax_];
    isScEtaEB = new Bool_t[nmax_];
    isScEtaEE = new Bool_t[nmax_];
    mvaID_WP80 = new Bool_t[nmax_];
    mvaID_WP90 = new Bool_t[nmax_];
    pixelSeed = new Bool_t[nmax_];
  }

  void
  PPhoton::datastore::deallocate()
  {
    PRecoParticle::datastore::deallocate();

    delete [] energyErr;
    energyErr = 0;
    delete [] hoe;
    hoe = 0;
    delete [] mvaID;
    mvaID = 0;
    delete [] pfRelIso03_all;
    pfRelIso03_all = 0;
    delete [] pfRelIso03_chg;
    pfRelIso03_chg = 0;
    delete [] r9;
    r9 = 0;
    delete [] sieie;
    sieie = 0;
    delete [] cutBasedBitmap;
    cutBasedBitmap = 0;
    delete [] electronIdx;
    electronIdx = 0;
    delete [] vidNestedWPBitmap;
    vidNestedWPBitmap = 0;
    delete [] electronVeto;
    electronVeto = 0;
    delete [] isScEtaEB;
    isScEtaEB = 0;
    delete [] isScEtaEE;
    isScEtaEE = 0;
    delete [] mvaID_WP80;
    mvaID_WP80 = 0;
    delete [] mvaID_WP90;
    mvaID_WP90 = 0;
    delete [] pixelSeed;
    pixelSeed = 0;
  }

  void
  PPhoton::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PRecoParticle::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "energyErr"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "hoe"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaID"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pfRelIso03_all"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pfRelIso03_chg"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "r9"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "sieie"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "cutBasedBitmap"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "electronIdx"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "vidNestedWPBitmap"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "electronVeto"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "isScEtaEB"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "isScEtaEE"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaID_WP80"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaID_WP90"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pixelSeed"), _branches);
  }

  void
  PPhoton::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PRecoParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "energyErr"), energyErr, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "hoe"), hoe, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaID"), mvaID, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pfRelIso03_all"), pfRelIso03_all, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pfRelIso03_chg"), pfRelIso03_chg, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "r9"), r9, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "sieie"), sieie, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "cutBasedBitmap"), cutBasedBitmap, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "electronIdx"), electronIdx, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "vidNestedWPBitmap"), vidNestedWPBitmap, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "electronVeto"), electronVeto, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "isScEtaEB"), isScEtaEB, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "isScEtaEE"), isScEtaEE, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaID_WP80"), mvaID_WP80, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaID_WP90"), mvaID_WP90, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pixelSeed"), pixelSeed, _branches, _setStatus);
  }

  void
  PPhoton::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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

    panda::utils::book(_tree, BranchName(_name, "energyErr"), size, 'F', energyErr, _branches);
    panda::utils::book(_tree, BranchName(_name, "hoe"), size, 'F', hoe, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaID"), size, 'F', mvaID, _branches);
    panda::utils::book(_tree, BranchName(_name, "pfRelIso03_all"), size, 'F', pfRelIso03_all, _branches);
    panda::utils::book(_tree, BranchName(_name, "pfRelIso03_chg"), size, 'F', pfRelIso03_chg, _branches);
    panda::utils::book(_tree, BranchName(_name, "r9"), size, 'F', r9, _branches);
    panda::utils::book(_tree, BranchName(_name, "sieie"), size, 'F', sieie, _branches);
    panda::utils::book(_tree, BranchName(_name, "cutBasedBitmap"), size, 'I', cutBasedBitmap, _branches);
    panda::utils::book(_tree, BranchName(_name, "electronIdx"), size, 'I', electronIdx, _branches);
    panda::utils::book(_tree, BranchName(_name, "vidNestedWPBitmap"), size, 'I', vidNestedWPBitmap, _branches);
    panda::utils::book(_tree, BranchName(_name, "electronVeto"), size, 'O', electronVeto, _branches);
    panda::utils::book(_tree, BranchName(_name, "isScEtaEB"), size, 'O', isScEtaEB, _branches);
    panda::utils::book(_tree, BranchName(_name, "isScEtaEE"), size, 'O', isScEtaEE, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaID_WP80"), size, 'O', mvaID_WP80, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaID_WP90"), size, 'O', mvaID_WP90, _branches);
    panda::utils::book(_tree, BranchName(_name, "pixelSeed"), size, 'O', pixelSeed, _branches);
  }

  void
  PPhoton::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PRecoParticle::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "energyErr"));
    panda::utils::resetAddress(_tree, BranchName(_name, "hoe"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaID"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pfRelIso03_all"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pfRelIso03_chg"));
    panda::utils::resetAddress(_tree, BranchName(_name, "r9"));
    panda::utils::resetAddress(_tree, BranchName(_name, "sieie"));
    panda::utils::resetAddress(_tree, BranchName(_name, "cutBasedBitmap"));
    panda::utils::resetAddress(_tree, BranchName(_name, "electronIdx"));
    panda::utils::resetAddress(_tree, BranchName(_name, "vidNestedWPBitmap"));
    panda::utils::resetAddress(_tree, BranchName(_name, "electronVeto"));
    panda::utils::resetAddress(_tree, BranchName(_name, "isScEtaEB"));
    panda::utils::resetAddress(_tree, BranchName(_name, "isScEtaEE"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaID_WP80"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaID_WP90"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pixelSeed"));
  }

  void
  PPhoton::datastore::resizeVectors_(UInt_t _size)
  {
    PRecoParticle::datastore::resizeVectors_(_size);

  }

  PPhoton::PPhoton(char const* _name/* = ""*/) :
    PRecoParticle(new PPhotonArray(1, _name)),
    energyErr(gStore.getData(this).energyErr[0]),
    hoe(gStore.getData(this).hoe[0]),
    mvaID(gStore.getData(this).mvaID[0]),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    r9(gStore.getData(this).r9[0]),
    sieie(gStore.getData(this).sieie[0]),
    cutBasedBitmap(gStore.getData(this).cutBasedBitmap[0]),
    electronIdx(gStore.getData(this).electronIdx[0]),
    vidNestedWPBitmap(gStore.getData(this).vidNestedWPBitmap[0]),
    electronVeto(gStore.getData(this).electronVeto[0]),
    isScEtaEB(gStore.getData(this).isScEtaEB[0]),
    isScEtaEE(gStore.getData(this).isScEtaEE[0]),
    mvaID_WP80(gStore.getData(this).mvaID_WP80[0]),
    mvaID_WP90(gStore.getData(this).mvaID_WP90[0]),
    pixelSeed(gStore.getData(this).pixelSeed[0])
  {
  }

  PPhoton::PPhoton(PPhoton const& _src) :
    PRecoParticle(new PPhotonArray(1, _src.getName())),
    energyErr(gStore.getData(this).energyErr[0]),
    hoe(gStore.getData(this).hoe[0]),
    mvaID(gStore.getData(this).mvaID[0]),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    r9(gStore.getData(this).r9[0]),
    sieie(gStore.getData(this).sieie[0]),
    cutBasedBitmap(gStore.getData(this).cutBasedBitmap[0]),
    electronIdx(gStore.getData(this).electronIdx[0]),
    vidNestedWPBitmap(gStore.getData(this).vidNestedWPBitmap[0]),
    electronVeto(gStore.getData(this).electronVeto[0]),
    isScEtaEB(gStore.getData(this).isScEtaEB[0]),
    isScEtaEE(gStore.getData(this).isScEtaEE[0]),
    mvaID_WP80(gStore.getData(this).mvaID_WP80[0]),
    mvaID_WP90(gStore.getData(this).mvaID_WP90[0]),
    pixelSeed(gStore.getData(this).pixelSeed[0])
  {
    PRecoParticle::operator=(_src);

    energyErr = _src.energyErr;
    hoe = _src.hoe;
    mvaID = _src.mvaID;
    pfRelIso03_all = _src.pfRelIso03_all;
    pfRelIso03_chg = _src.pfRelIso03_chg;
    r9 = _src.r9;
    sieie = _src.sieie;
    cutBasedBitmap = _src.cutBasedBitmap;
    electronIdx = _src.electronIdx;
    vidNestedWPBitmap = _src.vidNestedWPBitmap;
    electronVeto = _src.electronVeto;
    isScEtaEB = _src.isScEtaEB;
    isScEtaEE = _src.isScEtaEE;
    mvaID_WP80 = _src.mvaID_WP80;
    mvaID_WP90 = _src.mvaID_WP90;
    pixelSeed = _src.pixelSeed;
  }

  PPhoton::PPhoton(datastore& _data, UInt_t _idx) :
    PRecoParticle(_data, _idx),
    energyErr(_data.energyErr[_idx]),
    hoe(_data.hoe[_idx]),
    mvaID(_data.mvaID[_idx]),
    pfRelIso03_all(_data.pfRelIso03_all[_idx]),
    pfRelIso03_chg(_data.pfRelIso03_chg[_idx]),
    r9(_data.r9[_idx]),
    sieie(_data.sieie[_idx]),
    cutBasedBitmap(_data.cutBasedBitmap[_idx]),
    electronIdx(_data.electronIdx[_idx]),
    vidNestedWPBitmap(_data.vidNestedWPBitmap[_idx]),
    electronVeto(_data.electronVeto[_idx]),
    isScEtaEB(_data.isScEtaEB[_idx]),
    isScEtaEE(_data.isScEtaEE[_idx]),
    mvaID_WP80(_data.mvaID_WP80[_idx]),
    mvaID_WP90(_data.mvaID_WP90[_idx]),
    pixelSeed(_data.pixelSeed[_idx])
  {
  }

  /*protected*/
  PPhoton::PPhoton(panda::ArrayBase* _array) :
    PRecoParticle(_array),
    energyErr(gStore.getData(this).energyErr[0]),
    hoe(gStore.getData(this).hoe[0]),
    mvaID(gStore.getData(this).mvaID[0]),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    r9(gStore.getData(this).r9[0]),
    sieie(gStore.getData(this).sieie[0]),
    cutBasedBitmap(gStore.getData(this).cutBasedBitmap[0]),
    electronIdx(gStore.getData(this).electronIdx[0]),
    vidNestedWPBitmap(gStore.getData(this).vidNestedWPBitmap[0]),
    electronVeto(gStore.getData(this).electronVeto[0]),
    isScEtaEB(gStore.getData(this).isScEtaEB[0]),
    isScEtaEE(gStore.getData(this).isScEtaEE[0]),
    mvaID_WP80(gStore.getData(this).mvaID_WP80[0]),
    mvaID_WP90(gStore.getData(this).mvaID_WP90[0]),
    pixelSeed(gStore.getData(this).pixelSeed[0])
  {
  }

  PPhoton::~PPhoton()
  {
    destructor();
  }

  PPhoton&
  PPhoton::operator=(PPhoton const& _src)
  {
    PRecoParticle::operator=(_src);

    energyErr = _src.energyErr;
    hoe = _src.hoe;
    mvaID = _src.mvaID;
    pfRelIso03_all = _src.pfRelIso03_all;
    pfRelIso03_chg = _src.pfRelIso03_chg;
    r9 = _src.r9;
    sieie = _src.sieie;
    cutBasedBitmap = _src.cutBasedBitmap;
    electronIdx = _src.electronIdx;
    vidNestedWPBitmap = _src.vidNestedWPBitmap;
    electronVeto = _src.electronVeto;
    isScEtaEB = _src.isScEtaEB;
    isScEtaEE = _src.isScEtaEE;
    mvaID_WP80 = _src.mvaID_WP80;
    mvaID_WP90 = _src.mvaID_WP90;
    pixelSeed = _src.pixelSeed;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PPhoton::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PRecoParticle::destructor(kTRUE);
  }

  /*protected*/
  void
  PPhoton::doInit_()
  {
    PRecoParticle::doInit_();

    energyErr = 0.;
    hoe = 0.;
    mvaID = 0.;
    pfRelIso03_all = 0.;
    pfRelIso03_chg = 0.;
    r9 = 0.;
    sieie = 0.;
    cutBasedBitmap = 0;
    electronIdx = 0;
    vidNestedWPBitmap = 0;
    electronVeto = false;
    isScEtaEB = false;
    isScEtaEE = false;
    mvaID_WP80 = false;
    mvaID_WP90 = false;
    pixelSeed = false;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PPhoton::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PPhoton::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PRecoParticle::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "energyErr = " << energyErr << std::endl;
    _out << indentation << "hoe = " << hoe << std::endl;
    _out << indentation << "mvaID = " << mvaID << std::endl;
    _out << indentation << "pfRelIso03_all = " << pfRelIso03_all << std::endl;
    _out << indentation << "pfRelIso03_chg = " << pfRelIso03_chg << std::endl;
    _out << indentation << "r9 = " << r9 << std::endl;
    _out << indentation << "sieie = " << sieie << std::endl;
    _out << indentation << "cutBasedBitmap = " << cutBasedBitmap << std::endl;
    _out << indentation << "electronIdx = " << electronIdx << std::endl;
    _out << indentation << "vidNestedWPBitmap = " << vidNestedWPBitmap << std::endl;
    _out << indentation << "electronVeto = " << electronVeto << std::endl;
    _out << indentation << "isScEtaEB = " << isScEtaEB << std::endl;
    _out << indentation << "isScEtaEE = " << isScEtaEE << std::endl;
    _out << indentation << "mvaID_WP80 = " << mvaID_WP80 << std::endl;
    _out << indentation << "mvaID_WP90 = " << mvaID_WP90 << std::endl;
    _out << indentation << "pixelSeed = " << pixelSeed << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

