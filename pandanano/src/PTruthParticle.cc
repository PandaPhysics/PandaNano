#include "../interface/PTruthParticle.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PTruthParticle>::branchNames{std::initializer_list<TString>{"size", "mass", "pt", "eta", "phi", "pdgId"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PTruthParticle::branchNames{std::initializer_list<TString>{"mass", "pt", "eta", "phi", "pdgId"}, panda::utils::BranchName::kAttrName};

  void
  PTruthParticle::datastore::allocate(UInt_t _nmax)
  {
    PParticleM::datastore::allocate(_nmax);

    pdgId = new Int_t[nmax_];
  }

  void
  PTruthParticle::datastore::deallocate()
  {
    PParticleM::datastore::deallocate();

    delete [] pdgId;
    pdgId = 0;
  }

  void
  PTruthParticle::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PParticleM::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "pdgId"), _branches);
  }

  void
  PTruthParticle::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "pdgId"), pdgId, _branches, _setStatus);
  }

  void
  PTruthParticle::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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

    panda::utils::book(_tree, BranchName(_name, "pdgId"), size, 'I', pdgId, _branches);
  }

  void
  PTruthParticle::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PParticleM::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "pdgId"));
  }

  void
  PTruthParticle::datastore::resizeVectors_(UInt_t _size)
  {
    PParticleM::datastore::resizeVectors_(_size);

  }

  PTruthParticle::PTruthParticle(char const* _name/* = ""*/) :
    PParticleM(new PTruthParticleArray(1, _name)),
    pdgId(gStore.getData(this).pdgId[0])
  {
  }

  PTruthParticle::PTruthParticle(PTruthParticle const& _src) :
    PParticleM(new PTruthParticleArray(1, _src.getName())),
    pdgId(gStore.getData(this).pdgId[0])
  {
    PParticleM::operator=(_src);

    pdgId = _src.pdgId;
  }

  PTruthParticle::PTruthParticle(datastore& _data, UInt_t _idx) :
    PParticleM(_data, _idx),
    pdgId(_data.pdgId[_idx])
  {
  }

  /*protected*/
  PTruthParticle::PTruthParticle(panda::ArrayBase* _array) :
    PParticleM(_array),
    pdgId(gStore.getData(this).pdgId[0])
  {
  }

  PTruthParticle::~PTruthParticle()
  {
    destructor();
  }

  PTruthParticle&
  PTruthParticle::operator=(PTruthParticle const& _src)
  {
    PParticleM::operator=(_src);

    pdgId = _src.pdgId;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PTruthParticle::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PParticleM::destructor(kTRUE);
  }

  /*protected*/
  void
  PTruthParticle::doInit_()
  {
    PParticleM::doInit_();

    pdgId = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PTruthParticle::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PTruthParticle::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PParticleM::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "pdgId = " << pdgId << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

