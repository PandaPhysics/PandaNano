#include "../interface/PGenJet.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PGenJet>::branchNames{std::initializer_list<TString>{"size", "mass", "pt", "eta", "phi", "partonFlavour", "hadronFlavour"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PGenJet::branchNames{std::initializer_list<TString>{"mass", "pt", "eta", "phi", "partonFlavour", "hadronFlavour"}, panda::utils::BranchName::kAttrName};

  void
  PGenJet::datastore::allocate(UInt_t _nmax)
  {
    PParticleM::datastore::allocate(_nmax);

    partonFlavour = new Int_t[nmax_];
    hadronFlavour = new UChar_t[nmax_];
  }

  void
  PGenJet::datastore::deallocate()
  {
    PParticleM::datastore::deallocate();

    delete [] partonFlavour;
    partonFlavour = 0;
    delete [] hadronFlavour;
    hadronFlavour = 0;
  }

  void
  PGenJet::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PParticleM::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "partonFlavour"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "hadronFlavour"), _branches);
  }

  void
  PGenJet::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "partonFlavour"), partonFlavour, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "hadronFlavour"), hadronFlavour, _branches, _setStatus);
  }

  void
  PGenJet::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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

    panda::utils::book(_tree, BranchName(_name, "partonFlavour"), size, 'I', partonFlavour, _branches);
    panda::utils::book(_tree, BranchName(_name, "hadronFlavour"), size, 'b', hadronFlavour, _branches);
  }

  void
  PGenJet::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PParticleM::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "partonFlavour"));
    panda::utils::resetAddress(_tree, BranchName(_name, "hadronFlavour"));
  }

  void
  PGenJet::datastore::resizeVectors_(UInt_t _size)
  {
    PParticleM::datastore::resizeVectors_(_size);

  }

  PGenJet::PGenJet(char const* _name/* = ""*/) :
    PParticleM(new PGenJetArray(1, _name)),
    partonFlavour(gStore.getData(this).partonFlavour[0]),
    hadronFlavour(gStore.getData(this).hadronFlavour[0])
  {
  }

  PGenJet::PGenJet(PGenJet const& _src) :
    PParticleM(new PGenJetArray(1, _src.getName())),
    partonFlavour(gStore.getData(this).partonFlavour[0]),
    hadronFlavour(gStore.getData(this).hadronFlavour[0])
  {
    PParticleM::operator=(_src);

    partonFlavour = _src.partonFlavour;
    hadronFlavour = _src.hadronFlavour;
  }

  PGenJet::PGenJet(datastore& _data, UInt_t _idx) :
    PParticleM(_data, _idx),
    partonFlavour(_data.partonFlavour[_idx]),
    hadronFlavour(_data.hadronFlavour[_idx])
  {
  }

  /*protected*/
  PGenJet::PGenJet(panda::ArrayBase* _array) :
    PParticleM(_array),
    partonFlavour(gStore.getData(this).partonFlavour[0]),
    hadronFlavour(gStore.getData(this).hadronFlavour[0])
  {
  }

  PGenJet::~PGenJet()
  {
    destructor();
  }

  PGenJet&
  PGenJet::operator=(PGenJet const& _src)
  {
    PParticleM::operator=(_src);

    partonFlavour = _src.partonFlavour;
    hadronFlavour = _src.hadronFlavour;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PGenJet::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PParticleM::destructor(kTRUE);
  }

  /*protected*/
  void
  PGenJet::doInit_()
  {
    PParticleM::doInit_();

    partonFlavour = 0;
    hadronFlavour = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PGenJet::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PGenJet::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PParticleM::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "partonFlavour = " << partonFlavour << std::endl;
    _out << indentation << "hadronFlavour = " << static_cast<const UInt_t>(hadronFlavour) << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

