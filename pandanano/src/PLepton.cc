#include "../interface/PLepton.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PLepton>::branchNames{std::initializer_list<TString>{"size", "charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask", "mass", "pt", "eta", "phi", "dxy", "dxyErr", "dz", "dzErr", "ip3d", "miniPFRelIso_all", "miniPFRelIso_chg", "tightCharge", "isPFcand"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PLepton::branchNames{std::initializer_list<TString>{"charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask", "mass", "pt", "eta", "phi", "dxy", "dxyErr", "dz", "dzErr", "ip3d", "miniPFRelIso_all", "miniPFRelIso_chg", "tightCharge", "isPFcand"}, panda::utils::BranchName::kAttrName};

  void
  PLepton::datastore::allocate(UInt_t _nmax)
  {
    PRecoParticle::datastore::allocate(_nmax);

    dxy = new Float_t[nmax_];
    dxyErr = new Float_t[nmax_];
    dz = new Float_t[nmax_];
    dzErr = new Float_t[nmax_];
    ip3d = new Float_t[nmax_];
    miniPFRelIso_all = new Float_t[nmax_];
    miniPFRelIso_chg = new Float_t[nmax_];
    tightCharge = new Int_t[nmax_];
    isPFcand = new Bool_t[nmax_];
  }

  void
  PLepton::datastore::deallocate()
  {
    PRecoParticle::datastore::deallocate();

    delete [] dxy;
    dxy = 0;
    delete [] dxyErr;
    dxyErr = 0;
    delete [] dz;
    dz = 0;
    delete [] dzErr;
    dzErr = 0;
    delete [] ip3d;
    ip3d = 0;
    delete [] miniPFRelIso_all;
    miniPFRelIso_all = 0;
    delete [] miniPFRelIso_chg;
    miniPFRelIso_chg = 0;
    delete [] tightCharge;
    tightCharge = 0;
    delete [] isPFcand;
    isPFcand = 0;
  }

  void
  PLepton::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PRecoParticle::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "dxy"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "dxyErr"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "dz"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "dzErr"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "ip3d"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "miniPFRelIso_all"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "miniPFRelIso_chg"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "tightCharge"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "isPFcand"), _branches);
  }

  void
  PLepton::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PRecoParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "dxy"), dxy, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "dxyErr"), dxyErr, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "dz"), dz, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "dzErr"), dzErr, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "ip3d"), ip3d, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "miniPFRelIso_all"), miniPFRelIso_all, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "miniPFRelIso_chg"), miniPFRelIso_chg, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "tightCharge"), tightCharge, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "isPFcand"), isPFcand, _branches, _setStatus);
  }

  void
  PLepton::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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

    panda::utils::book(_tree, BranchName(_name, "dxy"), size, 'F', dxy, _branches);
    panda::utils::book(_tree, BranchName(_name, "dxyErr"), size, 'F', dxyErr, _branches);
    panda::utils::book(_tree, BranchName(_name, "dz"), size, 'F', dz, _branches);
    panda::utils::book(_tree, BranchName(_name, "dzErr"), size, 'F', dzErr, _branches);
    panda::utils::book(_tree, BranchName(_name, "ip3d"), size, 'F', ip3d, _branches);
    panda::utils::book(_tree, BranchName(_name, "miniPFRelIso_all"), size, 'F', miniPFRelIso_all, _branches);
    panda::utils::book(_tree, BranchName(_name, "miniPFRelIso_chg"), size, 'F', miniPFRelIso_chg, _branches);
    panda::utils::book(_tree, BranchName(_name, "tightCharge"), size, 'I', tightCharge, _branches);
    panda::utils::book(_tree, BranchName(_name, "isPFcand"), size, 'O', isPFcand, _branches);
  }

  void
  PLepton::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PRecoParticle::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "dxy"));
    panda::utils::resetAddress(_tree, BranchName(_name, "dxyErr"));
    panda::utils::resetAddress(_tree, BranchName(_name, "dz"));
    panda::utils::resetAddress(_tree, BranchName(_name, "dzErr"));
    panda::utils::resetAddress(_tree, BranchName(_name, "ip3d"));
    panda::utils::resetAddress(_tree, BranchName(_name, "miniPFRelIso_all"));
    panda::utils::resetAddress(_tree, BranchName(_name, "miniPFRelIso_chg"));
    panda::utils::resetAddress(_tree, BranchName(_name, "tightCharge"));
    panda::utils::resetAddress(_tree, BranchName(_name, "isPFcand"));
  }

  void
  PLepton::datastore::resizeVectors_(UInt_t _size)
  {
    PRecoParticle::datastore::resizeVectors_(_size);

  }

  PLepton::PLepton(char const* _name/* = ""*/) :
    PRecoParticle(new PLeptonArray(1, _name)),
    dxy(gStore.getData(this).dxy[0]),
    dxyErr(gStore.getData(this).dxyErr[0]),
    dz(gStore.getData(this).dz[0]),
    dzErr(gStore.getData(this).dzErr[0]),
    ip3d(gStore.getData(this).ip3d[0]),
    miniPFRelIso_all(gStore.getData(this).miniPFRelIso_all[0]),
    miniPFRelIso_chg(gStore.getData(this).miniPFRelIso_chg[0]),
    tightCharge(gStore.getData(this).tightCharge[0]),
    isPFcand(gStore.getData(this).isPFcand[0])
  {
  }

  PLepton::PLepton(PLepton const& _src) :
    PRecoParticle(new PLeptonArray(1, _src.getName())),
    dxy(gStore.getData(this).dxy[0]),
    dxyErr(gStore.getData(this).dxyErr[0]),
    dz(gStore.getData(this).dz[0]),
    dzErr(gStore.getData(this).dzErr[0]),
    ip3d(gStore.getData(this).ip3d[0]),
    miniPFRelIso_all(gStore.getData(this).miniPFRelIso_all[0]),
    miniPFRelIso_chg(gStore.getData(this).miniPFRelIso_chg[0]),
    tightCharge(gStore.getData(this).tightCharge[0]),
    isPFcand(gStore.getData(this).isPFcand[0])
  {
    PRecoParticle::operator=(_src);

    dxy = _src.dxy;
    dxyErr = _src.dxyErr;
    dz = _src.dz;
    dzErr = _src.dzErr;
    ip3d = _src.ip3d;
    miniPFRelIso_all = _src.miniPFRelIso_all;
    miniPFRelIso_chg = _src.miniPFRelIso_chg;
    tightCharge = _src.tightCharge;
    isPFcand = _src.isPFcand;
  }

  PLepton::PLepton(datastore& _data, UInt_t _idx) :
    PRecoParticle(_data, _idx),
    dxy(_data.dxy[_idx]),
    dxyErr(_data.dxyErr[_idx]),
    dz(_data.dz[_idx]),
    dzErr(_data.dzErr[_idx]),
    ip3d(_data.ip3d[_idx]),
    miniPFRelIso_all(_data.miniPFRelIso_all[_idx]),
    miniPFRelIso_chg(_data.miniPFRelIso_chg[_idx]),
    tightCharge(_data.tightCharge[_idx]),
    isPFcand(_data.isPFcand[_idx])
  {
  }

  /*protected*/
  PLepton::PLepton(panda::ArrayBase* _array) :
    PRecoParticle(_array),
    dxy(gStore.getData(this).dxy[0]),
    dxyErr(gStore.getData(this).dxyErr[0]),
    dz(gStore.getData(this).dz[0]),
    dzErr(gStore.getData(this).dzErr[0]),
    ip3d(gStore.getData(this).ip3d[0]),
    miniPFRelIso_all(gStore.getData(this).miniPFRelIso_all[0]),
    miniPFRelIso_chg(gStore.getData(this).miniPFRelIso_chg[0]),
    tightCharge(gStore.getData(this).tightCharge[0]),
    isPFcand(gStore.getData(this).isPFcand[0])
  {
  }

  PLepton::~PLepton()
  {
    destructor();
  }

  PLepton&
  PLepton::operator=(PLepton const& _src)
  {
    PRecoParticle::operator=(_src);

    dxy = _src.dxy;
    dxyErr = _src.dxyErr;
    dz = _src.dz;
    dzErr = _src.dzErr;
    ip3d = _src.ip3d;
    miniPFRelIso_all = _src.miniPFRelIso_all;
    miniPFRelIso_chg = _src.miniPFRelIso_chg;
    tightCharge = _src.tightCharge;
    isPFcand = _src.isPFcand;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PLepton::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PRecoParticle::destructor(kTRUE);
  }

  /*protected*/
  void
  PLepton::doInit_()
  {
    PRecoParticle::doInit_();

    dxy = 0.;
    dxyErr = 0.;
    dz = 0.;
    dzErr = 0.;
    ip3d = 0.;
    miniPFRelIso_all = 0.;
    miniPFRelIso_chg = 0.;
    tightCharge = 0;
    isPFcand = false;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PLepton::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PLepton::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PRecoParticle::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "dxy = " << dxy << std::endl;
    _out << indentation << "dxyErr = " << dxyErr << std::endl;
    _out << indentation << "dz = " << dz << std::endl;
    _out << indentation << "dzErr = " << dzErr << std::endl;
    _out << indentation << "ip3d = " << ip3d << std::endl;
    _out << indentation << "miniPFRelIso_all = " << miniPFRelIso_all << std::endl;
    _out << indentation << "miniPFRelIso_chg = " << miniPFRelIso_chg << std::endl;
    _out << indentation << "tightCharge = " << tightCharge << std::endl;
    _out << indentation << "isPFcand = " << isPFcand << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

