#include "../interface/PGenTau.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PGenTau>::branchNames{std::initializer_list<TString>{"size", "mass", "pt", "eta", "phi", "charge", "genPartIdxMother", "status"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PGenTau::branchNames{std::initializer_list<TString>{"mass", "pt", "eta", "phi", "charge", "genPartIdxMother", "status"}, panda::utils::BranchName::kAttrName};

  void
  PGenTau::datastore::allocate(UInt_t _nmax)
  {
    PParticleM::datastore::allocate(_nmax);

    charge = new Int_t[nmax_];
    genPartIdxMother = new Int_t[nmax_];
    status = new Int_t[nmax_];
  }

  void
  PGenTau::datastore::deallocate()
  {
    PParticleM::datastore::deallocate();

    delete [] charge;
    charge = 0;
    delete [] genPartIdxMother;
    genPartIdxMother = 0;
    delete [] status;
    status = 0;
  }

  void
  PGenTau::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PParticleM::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "charge"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "genPartIdxMother"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "status"), _branches);
  }

  void
  PGenTau::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "charge"), charge, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "genPartIdxMother"), genPartIdxMother, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "status"), status, _branches, _setStatus);
  }

  void
  PGenTau::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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
    panda::utils::book(_tree, BranchName(_name, "genPartIdxMother"), size, 'I', genPartIdxMother, _branches);
    panda::utils::book(_tree, BranchName(_name, "status"), size, 'I', status, _branches);
  }

  void
  PGenTau::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PParticleM::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "charge"));
    panda::utils::resetAddress(_tree, BranchName(_name, "genPartIdxMother"));
    panda::utils::resetAddress(_tree, BranchName(_name, "status"));
  }

  void
  PGenTau::datastore::resizeVectors_(UInt_t _size)
  {
    PParticleM::datastore::resizeVectors_(_size);

  }

  PGenTau::PGenTau(char const* _name/* = ""*/) :
    PParticleM(new PGenTauArray(1, _name)),
    charge(gStore.getData(this).charge[0]),
    genPartIdxMother(gStore.getData(this).genPartIdxMother[0]),
    status(gStore.getData(this).status[0])
  {
  }

  PGenTau::PGenTau(PGenTau const& _src) :
    PParticleM(new PGenTauArray(1, _src.getName())),
    charge(gStore.getData(this).charge[0]),
    genPartIdxMother(gStore.getData(this).genPartIdxMother[0]),
    status(gStore.getData(this).status[0])
  {
    PParticleM::operator=(_src);

    charge = _src.charge;
    genPartIdxMother = _src.genPartIdxMother;
    status = _src.status;
  }

  PGenTau::PGenTau(datastore& _data, UInt_t _idx) :
    PParticleM(_data, _idx),
    charge(_data.charge[_idx]),
    genPartIdxMother(_data.genPartIdxMother[_idx]),
    status(_data.status[_idx])
  {
  }

  /*protected*/
  PGenTau::PGenTau(panda::ArrayBase* _array) :
    PParticleM(_array),
    charge(gStore.getData(this).charge[0]),
    genPartIdxMother(gStore.getData(this).genPartIdxMother[0]),
    status(gStore.getData(this).status[0])
  {
  }

  PGenTau::~PGenTau()
  {
    destructor();
  }

  PGenTau&
  PGenTau::operator=(PGenTau const& _src)
  {
    PParticleM::operator=(_src);

    charge = _src.charge;
    genPartIdxMother = _src.genPartIdxMother;
    status = _src.status;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PGenTau::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PParticleM::destructor(kTRUE);
  }

  /*protected*/
  void
  PGenTau::doInit_()
  {
    PParticleM::doInit_();

    charge = 0;
    genPartIdxMother = 0;
    status = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PGenTau::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PGenTau::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PParticleM::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "charge = " << charge << std::endl;
    _out << indentation << "genPartIdxMother = " << genPartIdxMother << std::endl;
    _out << indentation << "status = " << status << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

