#include "../interface/PRecoParticle.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PRecoParticle>::branchNames{std::initializer_list<TString>{"size", "mass", "pt", "eta", "phi", "charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PRecoParticle::branchNames{std::initializer_list<TString>{"mass", "pt", "eta", "phi", "charge", "jetIdx", "pdgId", "genPartIdx", "genPartFlav", "cleanmask"}, panda::utils::BranchName::kAttrName};

  void
  PRecoParticle::datastore::allocate(UInt_t _nmax)
  {
    PParticleM::datastore::allocate(_nmax);

    charge = new Int_t[nmax_];
    jetIdx = new Int_t[nmax_];
    pdgId = new Int_t[nmax_];
    genPartIdx = new Int_t[nmax_];
    genPartFlav = new UChar_t[nmax_];
    cleanmask = new UChar_t[nmax_];
  }

  void
  PRecoParticle::datastore::deallocate()
  {
    PParticleM::datastore::deallocate();

    delete [] charge;
    charge = 0;
    delete [] jetIdx;
    jetIdx = 0;
    delete [] pdgId;
    pdgId = 0;
    delete [] genPartIdx;
    genPartIdx = 0;
    delete [] genPartFlav;
    genPartFlav = 0;
    delete [] cleanmask;
    cleanmask = 0;
  }

  void
  PRecoParticle::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PParticleM::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "charge"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "jetIdx"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pdgId"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "genPartIdx"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "genPartFlav"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "cleanmask"), _branches);
  }

  void
  PRecoParticle::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "charge"), charge, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "jetIdx"), jetIdx, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pdgId"), pdgId, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "genPartIdx"), genPartIdx, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "genPartFlav"), genPartFlav, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "cleanmask"), cleanmask, _branches, _setStatus);
  }

  void
  PRecoParticle::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
  {
    PParticleM::datastore::book(_tree, _name, _branches, _bookAs);

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

    panda::utils::book(_tree, BranchName(_name, "charge"), size, 'I', charge, _branches);
    panda::utils::book(_tree, BranchName(_name, "jetIdx"), size, 'I', jetIdx, _branches);
    panda::utils::book(_tree, BranchName(_name, "pdgId"), size, 'I', pdgId, _branches);
    panda::utils::book(_tree, BranchName(_name, "genPartIdx"), size, 'I', genPartIdx, _branches);
    panda::utils::book(_tree, BranchName(_name, "genPartFlav"), size, 'b', genPartFlav, _branches);
    panda::utils::book(_tree, BranchName(_name, "cleanmask"), size, 'b', cleanmask, _branches);
  }

  void
  PRecoParticle::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PParticleM::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "charge"));
    panda::utils::resetAddress(_tree, BranchName(_name, "jetIdx"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pdgId"));
    panda::utils::resetAddress(_tree, BranchName(_name, "genPartIdx"));
    panda::utils::resetAddress(_tree, BranchName(_name, "genPartFlav"));
    panda::utils::resetAddress(_tree, BranchName(_name, "cleanmask"));
  }

  void
  PRecoParticle::datastore::resizeVectors_(UInt_t _size)
  {
    PParticleM::datastore::resizeVectors_(_size);

  }

  PRecoParticle::PRecoParticle(char const* _name/* = ""*/) :
    PParticleM(new PRecoParticleArray(1, _name)),
    charge(gStore.getData(this).charge[0]),
    jetIdx(gStore.getData(this).jetIdx[0]),
    pdgId(gStore.getData(this).pdgId[0]),
    genPartIdx(gStore.getData(this).genPartIdx[0]),
    genPartFlav(gStore.getData(this).genPartFlav[0]),
    cleanmask(gStore.getData(this).cleanmask[0])
  {
  }

  PRecoParticle::PRecoParticle(PRecoParticle const& _src) :
    PParticleM(new PRecoParticleArray(1, _src.getName())),
    charge(gStore.getData(this).charge[0]),
    jetIdx(gStore.getData(this).jetIdx[0]),
    pdgId(gStore.getData(this).pdgId[0]),
    genPartIdx(gStore.getData(this).genPartIdx[0]),
    genPartFlav(gStore.getData(this).genPartFlav[0]),
    cleanmask(gStore.getData(this).cleanmask[0])
  {
    PParticleM::operator=(_src);

    charge = _src.charge;
    jetIdx = _src.jetIdx;
    pdgId = _src.pdgId;
    genPartIdx = _src.genPartIdx;
    genPartFlav = _src.genPartFlav;
    cleanmask = _src.cleanmask;
  }

  PRecoParticle::PRecoParticle(datastore& _data, UInt_t _idx) :
    PParticleM(_data, _idx),
    charge(_data.charge[_idx]),
    jetIdx(_data.jetIdx[_idx]),
    pdgId(_data.pdgId[_idx]),
    genPartIdx(_data.genPartIdx[_idx]),
    genPartFlav(_data.genPartFlav[_idx]),
    cleanmask(_data.cleanmask[_idx])
  {
  }

  /*protected*/
  PRecoParticle::PRecoParticle(panda::ArrayBase* _array) :
    PParticleM(_array),
    charge(gStore.getData(this).charge[0]),
    jetIdx(gStore.getData(this).jetIdx[0]),
    pdgId(gStore.getData(this).pdgId[0]),
    genPartIdx(gStore.getData(this).genPartIdx[0]),
    genPartFlav(gStore.getData(this).genPartFlav[0]),
    cleanmask(gStore.getData(this).cleanmask[0])
  {
  }

  PRecoParticle::~PRecoParticle()
  {
    destructor();
  }

  PRecoParticle&
  PRecoParticle::operator=(PRecoParticle const& _src)
  {
    PParticleM::operator=(_src);

    charge = _src.charge;
    jetIdx = _src.jetIdx;
    pdgId = _src.pdgId;
    genPartIdx = _src.genPartIdx;
    genPartFlav = _src.genPartFlav;
    cleanmask = _src.cleanmask;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PRecoParticle::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PParticleM::destructor(kTRUE);
  }

  /*protected*/
  void
  PRecoParticle::doInit_()
  {
    PParticleM::doInit_();

    charge = 0;
    jetIdx = 0;
    pdgId = 0;
    genPartIdx = 0;
    genPartFlav = 0;
    cleanmask = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PRecoParticle::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PRecoParticle::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PParticleM::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "charge = " << charge << std::endl;
    _out << indentation << "jetIdx = " << jetIdx << std::endl;
    _out << indentation << "pdgId = " << pdgId << std::endl;
    _out << indentation << "genPartIdx = " << genPartIdx << std::endl;
    _out << indentation << "genPartFlav = " << static_cast<const UInt_t>(genPartFlav) << std::endl;
    _out << indentation << "cleanmask = " << static_cast<const UInt_t>(cleanmask) << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

