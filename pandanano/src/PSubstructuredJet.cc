#include "../interface/PSubstructuredJet.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PSubstructuredJet>::branchNames{std::initializer_list<TString>{"size", "btagCMVA", "btagCSVV2", "btagDeepB", "mass", "pt", "eta", "phi", "n2b1", "n3b1", "tau1", "tau2", "tau3", "tau4"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PSubstructuredJet::branchNames{std::initializer_list<TString>{"btagCMVA", "btagCSVV2", "btagDeepB", "mass", "pt", "eta", "phi", "n2b1", "n3b1", "tau1", "tau2", "tau3", "tau4"}, panda::utils::BranchName::kAttrName};

  void
  PSubstructuredJet::datastore::allocate(UInt_t _nmax)
  {
    PRecoJet::datastore::allocate(_nmax);

    n2b1 = new Float_t[nmax_];
    n3b1 = new Float_t[nmax_];
    tau1 = new Float_t[nmax_];
    tau2 = new Float_t[nmax_];
    tau3 = new Float_t[nmax_];
    tau4 = new Float_t[nmax_];
  }

  void
  PSubstructuredJet::datastore::deallocate()
  {
    PRecoJet::datastore::deallocate();

    delete [] n2b1;
    n2b1 = 0;
    delete [] n3b1;
    n3b1 = 0;
    delete [] tau1;
    tau1 = 0;
    delete [] tau2;
    tau2 = 0;
    delete [] tau3;
    tau3 = 0;
    delete [] tau4;
    tau4 = 0;
  }

  void
  PSubstructuredJet::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PRecoJet::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "n2b1"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "n3b1"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "tau1"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "tau2"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "tau3"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "tau4"), _branches);
  }

  void
  PSubstructuredJet::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PRecoJet::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "n2b1"), n2b1, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "n3b1"), n3b1, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "tau1"), tau1, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "tau2"), tau2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "tau3"), tau3, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "tau4"), tau4, _branches, _setStatus);
  }

  void
  PSubstructuredJet::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
  {
    PRecoJet::datastore::book(_tree, _name, _branches, _bookAs);

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

    panda::utils::book(_tree, BranchName(_name, "n2b1"), size, 'F', n2b1, _branches);
    panda::utils::book(_tree, BranchName(_name, "n3b1"), size, 'F', n3b1, _branches);
    panda::utils::book(_tree, BranchName(_name, "tau1"), size, 'F', tau1, _branches);
    panda::utils::book(_tree, BranchName(_name, "tau2"), size, 'F', tau2, _branches);
    panda::utils::book(_tree, BranchName(_name, "tau3"), size, 'F', tau3, _branches);
    panda::utils::book(_tree, BranchName(_name, "tau4"), size, 'F', tau4, _branches);
  }

  void
  PSubstructuredJet::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PRecoJet::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "n2b1"));
    panda::utils::resetAddress(_tree, BranchName(_name, "n3b1"));
    panda::utils::resetAddress(_tree, BranchName(_name, "tau1"));
    panda::utils::resetAddress(_tree, BranchName(_name, "tau2"));
    panda::utils::resetAddress(_tree, BranchName(_name, "tau3"));
    panda::utils::resetAddress(_tree, BranchName(_name, "tau4"));
  }

  void
  PSubstructuredJet::datastore::resizeVectors_(UInt_t _size)
  {
    PRecoJet::datastore::resizeVectors_(_size);

  }

  PSubstructuredJet::PSubstructuredJet(char const* _name/* = ""*/) :
    PRecoJet(new PSubstructuredJetArray(1, _name)),
    n2b1(gStore.getData(this).n2b1[0]),
    n3b1(gStore.getData(this).n3b1[0]),
    tau1(gStore.getData(this).tau1[0]),
    tau2(gStore.getData(this).tau2[0]),
    tau3(gStore.getData(this).tau3[0]),
    tau4(gStore.getData(this).tau4[0])
  {
  }

  PSubstructuredJet::PSubstructuredJet(PSubstructuredJet const& _src) :
    PRecoJet(new PSubstructuredJetArray(1, _src.getName())),
    n2b1(gStore.getData(this).n2b1[0]),
    n3b1(gStore.getData(this).n3b1[0]),
    tau1(gStore.getData(this).tau1[0]),
    tau2(gStore.getData(this).tau2[0]),
    tau3(gStore.getData(this).tau3[0]),
    tau4(gStore.getData(this).tau4[0])
  {
    PRecoJet::operator=(_src);

    n2b1 = _src.n2b1;
    n3b1 = _src.n3b1;
    tau1 = _src.tau1;
    tau2 = _src.tau2;
    tau3 = _src.tau3;
    tau4 = _src.tau4;
  }

  PSubstructuredJet::PSubstructuredJet(datastore& _data, UInt_t _idx) :
    PRecoJet(_data, _idx),
    n2b1(_data.n2b1[_idx]),
    n3b1(_data.n3b1[_idx]),
    tau1(_data.tau1[_idx]),
    tau2(_data.tau2[_idx]),
    tau3(_data.tau3[_idx]),
    tau4(_data.tau4[_idx])
  {
  }

  /*protected*/
  PSubstructuredJet::PSubstructuredJet(panda::ArrayBase* _array) :
    PRecoJet(_array),
    n2b1(gStore.getData(this).n2b1[0]),
    n3b1(gStore.getData(this).n3b1[0]),
    tau1(gStore.getData(this).tau1[0]),
    tau2(gStore.getData(this).tau2[0]),
    tau3(gStore.getData(this).tau3[0]),
    tau4(gStore.getData(this).tau4[0])
  {
  }

  PSubstructuredJet::~PSubstructuredJet()
  {
    destructor();
  }

  PSubstructuredJet&
  PSubstructuredJet::operator=(PSubstructuredJet const& _src)
  {
    PRecoJet::operator=(_src);

    n2b1 = _src.n2b1;
    n3b1 = _src.n3b1;
    tau1 = _src.tau1;
    tau2 = _src.tau2;
    tau3 = _src.tau3;
    tau4 = _src.tau4;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PSubstructuredJet::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PRecoJet::destructor(kTRUE);
  }

  /*protected*/
  void
  PSubstructuredJet::doInit_()
  {
    PRecoJet::doInit_();

    n2b1 = 0.;
    n3b1 = 0.;
    tau1 = 0.;
    tau2 = 0.;
    tau3 = 0.;
    tau4 = 0.;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PSubstructuredJet::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PSubstructuredJet::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PRecoJet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "n2b1 = " << n2b1 << std::endl;
    _out << indentation << "n3b1 = " << n3b1 << std::endl;
    _out << indentation << "tau1 = " << tau1 << std::endl;
    _out << indentation << "tau2 = " << tau2 << std::endl;
    _out << indentation << "tau3 = " << tau3 << std::endl;
    _out << indentation << "tau4 = " << tau4 << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

