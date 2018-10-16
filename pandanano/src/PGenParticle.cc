#include "../interface/PGenParticle.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PGenParticle>::branchNames{std::initializer_list<TString>{"size", "pdgId", "mass", "pt", "eta", "phi", "genPartIdxMother", "status", "statusFlags"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PGenParticle::branchNames{std::initializer_list<TString>{"pdgId", "mass", "pt", "eta", "phi", "genPartIdxMother", "status", "statusFlags"}, panda::utils::BranchName::kAttrName};

  void
  PGenParticle::datastore::allocate(UInt_t _nmax)
  {
    PTruthParticle::datastore::allocate(_nmax);

    genPartIdxMother = new Int_t[nmax_];
    status = new Int_t[nmax_];
    statusFlags = new Int_t[nmax_];
  }

  void
  PGenParticle::datastore::deallocate()
  {
    PTruthParticle::datastore::deallocate();

    delete [] genPartIdxMother;
    genPartIdxMother = 0;
    delete [] status;
    status = 0;
    delete [] statusFlags;
    statusFlags = 0;
  }

  void
  PGenParticle::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PTruthParticle::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "genPartIdxMother"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "status"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "statusFlags"), _branches);
  }

  void
  PGenParticle::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PTruthParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "genPartIdxMother"), genPartIdxMother, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "status"), status, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "statusFlags"), statusFlags, _branches, _setStatus);
  }

  void
  PGenParticle::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
  {
    PTruthParticle::datastore::book(_tree, _name, _branches, _bookAs);

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

    panda::utils::book(_tree, BranchName(_name, "genPartIdxMother"), size, 'I', genPartIdxMother, _branches);
    panda::utils::book(_tree, BranchName(_name, "status"), size, 'I', status, _branches);
    panda::utils::book(_tree, BranchName(_name, "statusFlags"), size, 'I', statusFlags, _branches);
  }

  void
  PGenParticle::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PTruthParticle::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "genPartIdxMother"));
    panda::utils::resetAddress(_tree, BranchName(_name, "status"));
    panda::utils::resetAddress(_tree, BranchName(_name, "statusFlags"));
  }

  void
  PGenParticle::datastore::resizeVectors_(UInt_t _size)
  {
    PTruthParticle::datastore::resizeVectors_(_size);

  }

  PGenParticle::PGenParticle(char const* _name/* = ""*/) :
    PTruthParticle(new PGenParticleArray(1, _name)),
    genPartIdxMother(gStore.getData(this).genPartIdxMother[0]),
    status(gStore.getData(this).status[0]),
    statusFlags(gStore.getData(this).statusFlags[0])
  {
  }

  PGenParticle::PGenParticle(PGenParticle const& _src) :
    PTruthParticle(new PGenParticleArray(1, _src.getName())),
    genPartIdxMother(gStore.getData(this).genPartIdxMother[0]),
    status(gStore.getData(this).status[0]),
    statusFlags(gStore.getData(this).statusFlags[0])
  {
    PTruthParticle::operator=(_src);

    genPartIdxMother = _src.genPartIdxMother;
    status = _src.status;
    statusFlags = _src.statusFlags;
  }

  PGenParticle::PGenParticle(datastore& _data, UInt_t _idx) :
    PTruthParticle(_data, _idx),
    genPartIdxMother(_data.genPartIdxMother[_idx]),
    status(_data.status[_idx]),
    statusFlags(_data.statusFlags[_idx])
  {
  }

  /*protected*/
  PGenParticle::PGenParticle(panda::ArrayBase* _array) :
    PTruthParticle(_array),
    genPartIdxMother(gStore.getData(this).genPartIdxMother[0]),
    status(gStore.getData(this).status[0]),
    statusFlags(gStore.getData(this).statusFlags[0])
  {
  }

  PGenParticle::~PGenParticle()
  {
    destructor();
  }

  PGenParticle&
  PGenParticle::operator=(PGenParticle const& _src)
  {
    PTruthParticle::operator=(_src);

    genPartIdxMother = _src.genPartIdxMother;
    status = _src.status;
    statusFlags = _src.statusFlags;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PGenParticle::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PTruthParticle::destructor(kTRUE);
  }

  /*protected*/
  void
  PGenParticle::doInit_()
  {
    PTruthParticle::doInit_();

    genPartIdxMother = 0;
    status = 0;
    statusFlags = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PGenParticle::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PGenParticle::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PTruthParticle::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "genPartIdxMother = " << genPartIdxMother << std::endl;
    _out << indentation << "status = " << status << std::endl;
    _out << indentation << "statusFlags = " << statusFlags << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

