#include "../interface/PRecoJet.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PRecoJet>::branchNames{std::initializer_list<TString>{"size", "mass", "pt", "eta", "phi", "btagCMVA", "btagCSVV2", "btagDeepB"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PRecoJet::branchNames{std::initializer_list<TString>{"mass", "pt", "eta", "phi", "btagCMVA", "btagCSVV2", "btagDeepB"}, panda::utils::BranchName::kAttrName};

  void
  PRecoJet::datastore::allocate(UInt_t _nmax)
  {
    PParticleM::datastore::allocate(_nmax);

    btagCMVA = new Float_t[nmax_];
    btagCSVV2 = new Float_t[nmax_];
    btagDeepB = new Float_t[nmax_];
  }

  void
  PRecoJet::datastore::deallocate()
  {
    PParticleM::datastore::deallocate();

    delete [] btagCMVA;
    btagCMVA = 0;
    delete [] btagCSVV2;
    btagCSVV2 = 0;
    delete [] btagDeepB;
    btagDeepB = 0;
  }

  void
  PRecoJet::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PParticleM::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "btagCMVA"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "btagCSVV2"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "btagDeepB"), _branches);
  }

  void
  PRecoJet::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "btagCMVA"), btagCMVA, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "btagCSVV2"), btagCSVV2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "btagDeepB"), btagDeepB, _branches, _setStatus);
  }

  void
  PRecoJet::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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

    panda::utils::book(_tree, BranchName(_name, "btagCMVA"), size, 'F', btagCMVA, _branches);
    panda::utils::book(_tree, BranchName(_name, "btagCSVV2"), size, 'F', btagCSVV2, _branches);
    panda::utils::book(_tree, BranchName(_name, "btagDeepB"), size, 'F', btagDeepB, _branches);
  }

  void
  PRecoJet::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PParticleM::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "btagCMVA"));
    panda::utils::resetAddress(_tree, BranchName(_name, "btagCSVV2"));
    panda::utils::resetAddress(_tree, BranchName(_name, "btagDeepB"));
  }

  void
  PRecoJet::datastore::resizeVectors_(UInt_t _size)
  {
    PParticleM::datastore::resizeVectors_(_size);

  }

  PRecoJet::PRecoJet(char const* _name/* = ""*/) :
    PParticleM(new PRecoJetArray(1, _name)),
    btagCMVA(gStore.getData(this).btagCMVA[0]),
    btagCSVV2(gStore.getData(this).btagCSVV2[0]),
    btagDeepB(gStore.getData(this).btagDeepB[0])
  {
  }

  PRecoJet::PRecoJet(PRecoJet const& _src) :
    PParticleM(new PRecoJetArray(1, _src.getName())),
    btagCMVA(gStore.getData(this).btagCMVA[0]),
    btagCSVV2(gStore.getData(this).btagCSVV2[0]),
    btagDeepB(gStore.getData(this).btagDeepB[0])
  {
    PParticleM::operator=(_src);

    btagCMVA = _src.btagCMVA;
    btagCSVV2 = _src.btagCSVV2;
    btagDeepB = _src.btagDeepB;
  }

  PRecoJet::PRecoJet(datastore& _data, UInt_t _idx) :
    PParticleM(_data, _idx),
    btagCMVA(_data.btagCMVA[_idx]),
    btagCSVV2(_data.btagCSVV2[_idx]),
    btagDeepB(_data.btagDeepB[_idx])
  {
  }

  /*protected*/
  PRecoJet::PRecoJet(panda::ArrayBase* _array) :
    PParticleM(_array),
    btagCMVA(gStore.getData(this).btagCMVA[0]),
    btagCSVV2(gStore.getData(this).btagCSVV2[0]),
    btagDeepB(gStore.getData(this).btagDeepB[0])
  {
  }

  PRecoJet::~PRecoJet()
  {
    destructor();
  }

  PRecoJet&
  PRecoJet::operator=(PRecoJet const& _src)
  {
    PParticleM::operator=(_src);

    btagCMVA = _src.btagCMVA;
    btagCSVV2 = _src.btagCSVV2;
    btagDeepB = _src.btagDeepB;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PRecoJet::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PParticleM::destructor(kTRUE);
  }

  /*protected*/
  void
  PRecoJet::doInit_()
  {
    PParticleM::doInit_();

    btagCMVA = 0.;
    btagCSVV2 = 0.;
    btagDeepB = 0.;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PRecoJet::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PRecoJet::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PParticleM::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "btagCMVA = " << btagCMVA << std::endl;
    _out << indentation << "btagCSVV2 = " << btagCSVV2 << std::endl;
    _out << indentation << "btagDeepB = " << btagDeepB << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

