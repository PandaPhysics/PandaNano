#include "../interface/PMuon.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PMuon>::branchNames{std::initializer_list<TString>{"size", "dxy", "dxyErr", "dz", "dzErr", "ip3d", "miniPFRelIso_all", "miniPFRelIso_chg", "tightCharge", "isPFcand", "charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask", "mass", "pt", "eta", "phi", "pfRelIso03_all", "pfRelIso03_chg", "pfRelIso04_all", "ptErr", "segmentComp", "sip3d", "mvaTTH", "nStations", "nTrackerLayers", "highPtId", "mediumId", "softId", "tightId"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PMuon::branchNames{std::initializer_list<TString>{"dxy", "dxyErr", "dz", "dzErr", "ip3d", "miniPFRelIso_all", "miniPFRelIso_chg", "tightCharge", "isPFcand", "charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask", "mass", "pt", "eta", "phi", "pfRelIso03_all", "pfRelIso03_chg", "pfRelIso04_all", "ptErr", "segmentComp", "sip3d", "mvaTTH", "nStations", "nTrackerLayers", "highPtId", "mediumId", "softId", "tightId"}, panda::utils::BranchName::kAttrName};

  void
  PMuon::datastore::allocate(UInt_t _nmax)
  {
    PLepton::datastore::allocate(_nmax);

    pfRelIso03_all = new Float_t[nmax_];
    pfRelIso03_chg = new Float_t[nmax_];
    pfRelIso04_all = new Float_t[nmax_];
    ptErr = new Float_t[nmax_];
    segmentComp = new Float_t[nmax_];
    sip3d = new Float_t[nmax_];
    mvaTTH = new Float_t[nmax_];
    nStations = new Int_t[nmax_];
    nTrackerLayers = new Int_t[nmax_];
    highPtId = new UChar_t[nmax_];
    mediumId = new Bool_t[nmax_];
    softId = new Bool_t[nmax_];
    tightId = new Bool_t[nmax_];
  }

  void
  PMuon::datastore::deallocate()
  {
    PLepton::datastore::deallocate();

    delete [] pfRelIso03_all;
    pfRelIso03_all = 0;
    delete [] pfRelIso03_chg;
    pfRelIso03_chg = 0;
    delete [] pfRelIso04_all;
    pfRelIso04_all = 0;
    delete [] ptErr;
    ptErr = 0;
    delete [] segmentComp;
    segmentComp = 0;
    delete [] sip3d;
    sip3d = 0;
    delete [] mvaTTH;
    mvaTTH = 0;
    delete [] nStations;
    nStations = 0;
    delete [] nTrackerLayers;
    nTrackerLayers = 0;
    delete [] highPtId;
    highPtId = 0;
    delete [] mediumId;
    mediumId = 0;
    delete [] softId;
    softId = 0;
    delete [] tightId;
    tightId = 0;
  }

  void
  PMuon::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PLepton::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "pfRelIso03_all"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pfRelIso03_chg"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pfRelIso04_all"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "ptErr"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "segmentComp"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "sip3d"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mvaTTH"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "nStations"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "nTrackerLayers"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "highPtId"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "mediumId"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "softId"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "tightId"), _branches);
  }

  void
  PMuon::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PLepton::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "pfRelIso03_all"), pfRelIso03_all, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pfRelIso03_chg"), pfRelIso03_chg, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pfRelIso04_all"), pfRelIso04_all, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "ptErr"), ptErr, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "segmentComp"), segmentComp, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "sip3d"), sip3d, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mvaTTH"), mvaTTH, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "nStations"), nStations, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "nTrackerLayers"), nTrackerLayers, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "highPtId"), highPtId, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "mediumId"), mediumId, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "softId"), softId, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "tightId"), tightId, _branches, _setStatus);
  }

  void
  PMuon::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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

    panda::utils::book(_tree, BranchName(_name, "pfRelIso03_all"), size, 'F', pfRelIso03_all, _branches);
    panda::utils::book(_tree, BranchName(_name, "pfRelIso03_chg"), size, 'F', pfRelIso03_chg, _branches);
    panda::utils::book(_tree, BranchName(_name, "pfRelIso04_all"), size, 'F', pfRelIso04_all, _branches);
    panda::utils::book(_tree, BranchName(_name, "ptErr"), size, 'F', ptErr, _branches);
    panda::utils::book(_tree, BranchName(_name, "segmentComp"), size, 'F', segmentComp, _branches);
    panda::utils::book(_tree, BranchName(_name, "sip3d"), size, 'F', sip3d, _branches);
    panda::utils::book(_tree, BranchName(_name, "mvaTTH"), size, 'F', mvaTTH, _branches);
    panda::utils::book(_tree, BranchName(_name, "nStations"), size, 'I', nStations, _branches);
    panda::utils::book(_tree, BranchName(_name, "nTrackerLayers"), size, 'I', nTrackerLayers, _branches);
    panda::utils::book(_tree, BranchName(_name, "highPtId"), size, 'b', highPtId, _branches);
    panda::utils::book(_tree, BranchName(_name, "mediumId"), size, 'O', mediumId, _branches);
    panda::utils::book(_tree, BranchName(_name, "softId"), size, 'O', softId, _branches);
    panda::utils::book(_tree, BranchName(_name, "tightId"), size, 'O', tightId, _branches);
  }

  void
  PMuon::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PLepton::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "pfRelIso03_all"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pfRelIso03_chg"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pfRelIso04_all"));
    panda::utils::resetAddress(_tree, BranchName(_name, "ptErr"));
    panda::utils::resetAddress(_tree, BranchName(_name, "segmentComp"));
    panda::utils::resetAddress(_tree, BranchName(_name, "sip3d"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mvaTTH"));
    panda::utils::resetAddress(_tree, BranchName(_name, "nStations"));
    panda::utils::resetAddress(_tree, BranchName(_name, "nTrackerLayers"));
    panda::utils::resetAddress(_tree, BranchName(_name, "highPtId"));
    panda::utils::resetAddress(_tree, BranchName(_name, "mediumId"));
    panda::utils::resetAddress(_tree, BranchName(_name, "softId"));
    panda::utils::resetAddress(_tree, BranchName(_name, "tightId"));
  }

  void
  PMuon::datastore::resizeVectors_(UInt_t _size)
  {
    PLepton::datastore::resizeVectors_(_size);

  }

  PMuon::PMuon(char const* _name/* = ""*/) :
    PLepton(new PMuonArray(1, _name)),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    pfRelIso04_all(gStore.getData(this).pfRelIso04_all[0]),
    ptErr(gStore.getData(this).ptErr[0]),
    segmentComp(gStore.getData(this).segmentComp[0]),
    sip3d(gStore.getData(this).sip3d[0]),
    mvaTTH(gStore.getData(this).mvaTTH[0]),
    nStations(gStore.getData(this).nStations[0]),
    nTrackerLayers(gStore.getData(this).nTrackerLayers[0]),
    highPtId(gStore.getData(this).highPtId[0]),
    mediumId(gStore.getData(this).mediumId[0]),
    softId(gStore.getData(this).softId[0]),
    tightId(gStore.getData(this).tightId[0])
  {
  }

  PMuon::PMuon(PMuon const& _src) :
    PLepton(new PMuonArray(1, _src.getName())),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    pfRelIso04_all(gStore.getData(this).pfRelIso04_all[0]),
    ptErr(gStore.getData(this).ptErr[0]),
    segmentComp(gStore.getData(this).segmentComp[0]),
    sip3d(gStore.getData(this).sip3d[0]),
    mvaTTH(gStore.getData(this).mvaTTH[0]),
    nStations(gStore.getData(this).nStations[0]),
    nTrackerLayers(gStore.getData(this).nTrackerLayers[0]),
    highPtId(gStore.getData(this).highPtId[0]),
    mediumId(gStore.getData(this).mediumId[0]),
    softId(gStore.getData(this).softId[0]),
    tightId(gStore.getData(this).tightId[0])
  {
    PLepton::operator=(_src);

    pfRelIso03_all = _src.pfRelIso03_all;
    pfRelIso03_chg = _src.pfRelIso03_chg;
    pfRelIso04_all = _src.pfRelIso04_all;
    ptErr = _src.ptErr;
    segmentComp = _src.segmentComp;
    sip3d = _src.sip3d;
    mvaTTH = _src.mvaTTH;
    nStations = _src.nStations;
    nTrackerLayers = _src.nTrackerLayers;
    highPtId = _src.highPtId;
    mediumId = _src.mediumId;
    softId = _src.softId;
    tightId = _src.tightId;
  }

  PMuon::PMuon(datastore& _data, UInt_t _idx) :
    PLepton(_data, _idx),
    pfRelIso03_all(_data.pfRelIso03_all[_idx]),
    pfRelIso03_chg(_data.pfRelIso03_chg[_idx]),
    pfRelIso04_all(_data.pfRelIso04_all[_idx]),
    ptErr(_data.ptErr[_idx]),
    segmentComp(_data.segmentComp[_idx]),
    sip3d(_data.sip3d[_idx]),
    mvaTTH(_data.mvaTTH[_idx]),
    nStations(_data.nStations[_idx]),
    nTrackerLayers(_data.nTrackerLayers[_idx]),
    highPtId(_data.highPtId[_idx]),
    mediumId(_data.mediumId[_idx]),
    softId(_data.softId[_idx]),
    tightId(_data.tightId[_idx])
  {
  }

  /*protected*/
  PMuon::PMuon(panda::ArrayBase* _array) :
    PLepton(_array),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    pfRelIso04_all(gStore.getData(this).pfRelIso04_all[0]),
    ptErr(gStore.getData(this).ptErr[0]),
    segmentComp(gStore.getData(this).segmentComp[0]),
    sip3d(gStore.getData(this).sip3d[0]),
    mvaTTH(gStore.getData(this).mvaTTH[0]),
    nStations(gStore.getData(this).nStations[0]),
    nTrackerLayers(gStore.getData(this).nTrackerLayers[0]),
    highPtId(gStore.getData(this).highPtId[0]),
    mediumId(gStore.getData(this).mediumId[0]),
    softId(gStore.getData(this).softId[0]),
    tightId(gStore.getData(this).tightId[0])
  {
  }

  PMuon::~PMuon()
  {
    destructor();
  }

  PMuon&
  PMuon::operator=(PMuon const& _src)
  {
    PLepton::operator=(_src);

    pfRelIso03_all = _src.pfRelIso03_all;
    pfRelIso03_chg = _src.pfRelIso03_chg;
    pfRelIso04_all = _src.pfRelIso04_all;
    ptErr = _src.ptErr;
    segmentComp = _src.segmentComp;
    sip3d = _src.sip3d;
    mvaTTH = _src.mvaTTH;
    nStations = _src.nStations;
    nTrackerLayers = _src.nTrackerLayers;
    highPtId = _src.highPtId;
    mediumId = _src.mediumId;
    softId = _src.softId;
    tightId = _src.tightId;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PMuon::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PLepton::destructor(kTRUE);
  }

  /*protected*/
  void
  PMuon::doInit_()
  {
    PLepton::doInit_();

    pfRelIso03_all = 0.;
    pfRelIso03_chg = 0.;
    pfRelIso04_all = 0.;
    ptErr = 0.;
    segmentComp = 0.;
    sip3d = 0.;
    mvaTTH = 0.;
    nStations = 0;
    nTrackerLayers = 0;
    highPtId = 0;
    mediumId = false;
    softId = false;
    tightId = false;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PMuon::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PMuon::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PLepton::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "pfRelIso03_all = " << pfRelIso03_all << std::endl;
    _out << indentation << "pfRelIso03_chg = " << pfRelIso03_chg << std::endl;
    _out << indentation << "pfRelIso04_all = " << pfRelIso04_all << std::endl;
    _out << indentation << "ptErr = " << ptErr << std::endl;
    _out << indentation << "segmentComp = " << segmentComp << std::endl;
    _out << indentation << "sip3d = " << sip3d << std::endl;
    _out << indentation << "mvaTTH = " << mvaTTH << std::endl;
    _out << indentation << "nStations = " << nStations << std::endl;
    _out << indentation << "nTrackerLayers = " << nTrackerLayers << std::endl;
    _out << indentation << "highPtId = " << static_cast<const UInt_t>(highPtId) << std::endl;
    _out << indentation << "mediumId = " << mediumId << std::endl;
    _out << indentation << "softId = " << softId << std::endl;
    _out << indentation << "tightId = " << tightId << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

