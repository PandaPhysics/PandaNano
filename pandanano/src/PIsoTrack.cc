#include "../interface/PIsoTrack.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PIsoTrack>::branchNames{std::initializer_list<TString>{"size", "pt", "eta", "phi", "dxy", "dz", "pfRelIso03_all", "pfRelIso03_chg", "miniPFRelIso_all", "miniPFRelIso_chg", "pdgId", "isHighPurityTrack", "isPFcand"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PIsoTrack::branchNames{std::initializer_list<TString>{"pt", "eta", "phi", "dxy", "dz", "pfRelIso03_all", "pfRelIso03_chg", "miniPFRelIso_all", "miniPFRelIso_chg", "pdgId", "isHighPurityTrack", "isPFcand"}, panda::utils::BranchName::kAttrName};

  void
  PIsoTrack::datastore::allocate(UInt_t _nmax)
  {
    PParticle::datastore::allocate(_nmax);

    dxy = new Float_t[nmax_];
    dz = new Float_t[nmax_];
    pfRelIso03_all = new Float_t[nmax_];
    pfRelIso03_chg = new Float_t[nmax_];
    miniPFRelIso_all = new Float_t[nmax_];
    miniPFRelIso_chg = new Float_t[nmax_];
    pdgId = new Int_t[nmax_];
    isHighPurityTrack = new Bool_t[nmax_];
    isPFcand = new Bool_t[nmax_];
  }

  void
  PIsoTrack::datastore::deallocate()
  {
    PParticle::datastore::deallocate();

    delete [] dxy;
    dxy = 0;
    delete [] dz;
    dz = 0;
    delete [] pfRelIso03_all;
    pfRelIso03_all = 0;
    delete [] pfRelIso03_chg;
    pfRelIso03_chg = 0;
    delete [] miniPFRelIso_all;
    miniPFRelIso_all = 0;
    delete [] miniPFRelIso_chg;
    miniPFRelIso_chg = 0;
    delete [] pdgId;
    pdgId = 0;
    delete [] isHighPurityTrack;
    isHighPurityTrack = 0;
    delete [] isPFcand;
    isPFcand = 0;
  }

  void
  PIsoTrack::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PParticle::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "dxy"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "dz"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pfRelIso03_all"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pfRelIso03_chg"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "miniPFRelIso_all"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "miniPFRelIso_chg"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pdgId"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "isHighPurityTrack"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "isPFcand"), _branches);
  }

  void
  PIsoTrack::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "dxy"), dxy, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "dz"), dz, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pfRelIso03_all"), pfRelIso03_all, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pfRelIso03_chg"), pfRelIso03_chg, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "miniPFRelIso_all"), miniPFRelIso_all, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "miniPFRelIso_chg"), miniPFRelIso_chg, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pdgId"), pdgId, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "isHighPurityTrack"), isHighPurityTrack, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "isPFcand"), isPFcand, _branches, _setStatus);
  }

  void
  PIsoTrack::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
  {
    PParticle::datastore::book(_tree, _name, _branches, _bookAs);

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
    panda::utils::book(_tree, BranchName(_name, "dz"), size, 'F', dz, _branches);
    panda::utils::book(_tree, BranchName(_name, "pfRelIso03_all"), size, 'F', pfRelIso03_all, _branches);
    panda::utils::book(_tree, BranchName(_name, "pfRelIso03_chg"), size, 'F', pfRelIso03_chg, _branches);
    panda::utils::book(_tree, BranchName(_name, "miniPFRelIso_all"), size, 'F', miniPFRelIso_all, _branches);
    panda::utils::book(_tree, BranchName(_name, "miniPFRelIso_chg"), size, 'F', miniPFRelIso_chg, _branches);
    panda::utils::book(_tree, BranchName(_name, "pdgId"), size, 'I', pdgId, _branches);
    panda::utils::book(_tree, BranchName(_name, "isHighPurityTrack"), size, 'O', isHighPurityTrack, _branches);
    panda::utils::book(_tree, BranchName(_name, "isPFcand"), size, 'O', isPFcand, _branches);
  }

  void
  PIsoTrack::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PParticle::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "dxy"));
    panda::utils::resetAddress(_tree, BranchName(_name, "dz"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pfRelIso03_all"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pfRelIso03_chg"));
    panda::utils::resetAddress(_tree, BranchName(_name, "miniPFRelIso_all"));
    panda::utils::resetAddress(_tree, BranchName(_name, "miniPFRelIso_chg"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pdgId"));
    panda::utils::resetAddress(_tree, BranchName(_name, "isHighPurityTrack"));
    panda::utils::resetAddress(_tree, BranchName(_name, "isPFcand"));
  }

  void
  PIsoTrack::datastore::resizeVectors_(UInt_t _size)
  {
    PParticle::datastore::resizeVectors_(_size);

  }

  PIsoTrack::PIsoTrack(char const* _name/* = ""*/) :
    PParticle(new PIsoTrackArray(1, _name)),
    dxy(gStore.getData(this).dxy[0]),
    dz(gStore.getData(this).dz[0]),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    miniPFRelIso_all(gStore.getData(this).miniPFRelIso_all[0]),
    miniPFRelIso_chg(gStore.getData(this).miniPFRelIso_chg[0]),
    pdgId(gStore.getData(this).pdgId[0]),
    isHighPurityTrack(gStore.getData(this).isHighPurityTrack[0]),
    isPFcand(gStore.getData(this).isPFcand[0])
  {
  }

  PIsoTrack::PIsoTrack(PIsoTrack const& _src) :
    PParticle(new PIsoTrackArray(1, _src.getName())),
    dxy(gStore.getData(this).dxy[0]),
    dz(gStore.getData(this).dz[0]),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    miniPFRelIso_all(gStore.getData(this).miniPFRelIso_all[0]),
    miniPFRelIso_chg(gStore.getData(this).miniPFRelIso_chg[0]),
    pdgId(gStore.getData(this).pdgId[0]),
    isHighPurityTrack(gStore.getData(this).isHighPurityTrack[0]),
    isPFcand(gStore.getData(this).isPFcand[0])
  {
    PParticle::operator=(_src);

    dxy = _src.dxy;
    dz = _src.dz;
    pfRelIso03_all = _src.pfRelIso03_all;
    pfRelIso03_chg = _src.pfRelIso03_chg;
    miniPFRelIso_all = _src.miniPFRelIso_all;
    miniPFRelIso_chg = _src.miniPFRelIso_chg;
    pdgId = _src.pdgId;
    isHighPurityTrack = _src.isHighPurityTrack;
    isPFcand = _src.isPFcand;
  }

  PIsoTrack::PIsoTrack(datastore& _data, UInt_t _idx) :
    PParticle(_data, _idx),
    dxy(_data.dxy[_idx]),
    dz(_data.dz[_idx]),
    pfRelIso03_all(_data.pfRelIso03_all[_idx]),
    pfRelIso03_chg(_data.pfRelIso03_chg[_idx]),
    miniPFRelIso_all(_data.miniPFRelIso_all[_idx]),
    miniPFRelIso_chg(_data.miniPFRelIso_chg[_idx]),
    pdgId(_data.pdgId[_idx]),
    isHighPurityTrack(_data.isHighPurityTrack[_idx]),
    isPFcand(_data.isPFcand[_idx])
  {
  }

  /*protected*/
  PIsoTrack::PIsoTrack(panda::ArrayBase* _array) :
    PParticle(_array),
    dxy(gStore.getData(this).dxy[0]),
    dz(gStore.getData(this).dz[0]),
    pfRelIso03_all(gStore.getData(this).pfRelIso03_all[0]),
    pfRelIso03_chg(gStore.getData(this).pfRelIso03_chg[0]),
    miniPFRelIso_all(gStore.getData(this).miniPFRelIso_all[0]),
    miniPFRelIso_chg(gStore.getData(this).miniPFRelIso_chg[0]),
    pdgId(gStore.getData(this).pdgId[0]),
    isHighPurityTrack(gStore.getData(this).isHighPurityTrack[0]),
    isPFcand(gStore.getData(this).isPFcand[0])
  {
  }

  PIsoTrack::~PIsoTrack()
  {
    destructor();
  }

  PIsoTrack&
  PIsoTrack::operator=(PIsoTrack const& _src)
  {
    PParticle::operator=(_src);

    dxy = _src.dxy;
    dz = _src.dz;
    pfRelIso03_all = _src.pfRelIso03_all;
    pfRelIso03_chg = _src.pfRelIso03_chg;
    miniPFRelIso_all = _src.miniPFRelIso_all;
    miniPFRelIso_chg = _src.miniPFRelIso_chg;
    pdgId = _src.pdgId;
    isHighPurityTrack = _src.isHighPurityTrack;
    isPFcand = _src.isPFcand;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PIsoTrack::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PParticle::destructor(kTRUE);
  }

  /*protected*/
  void
  PIsoTrack::doInit_()
  {
    PParticle::doInit_();

    dxy = 0.;
    dz = 0.;
    pfRelIso03_all = 0.;
    pfRelIso03_chg = 0.;
    miniPFRelIso_all = 0.;
    miniPFRelIso_chg = 0.;
    pdgId = 0;
    isHighPurityTrack = false;
    isPFcand = false;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PIsoTrack::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PIsoTrack::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PParticle::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "dxy = " << dxy << std::endl;
    _out << indentation << "dz = " << dz << std::endl;
    _out << indentation << "pfRelIso03_all = " << pfRelIso03_all << std::endl;
    _out << indentation << "pfRelIso03_chg = " << pfRelIso03_chg << std::endl;
    _out << indentation << "miniPFRelIso_all = " << miniPFRelIso_all << std::endl;
    _out << indentation << "miniPFRelIso_chg = " << miniPFRelIso_chg << std::endl;
    _out << indentation << "pdgId = " << pdgId << std::endl;
    _out << indentation << "isHighPurityTrack = " << isHighPurityTrack << std::endl;
    _out << indentation << "isPFcand = " << isPFcand << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

