#include "../interface/PFatJet.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PFatJet>::branchNames{std::initializer_list<TString>{"size", "n2b1", "n3b1", "tau1", "tau2", "tau3", "tau4", "btagCMVA", "btagCSVV2", "btagDeepB", "mass", "pt", "eta", "phi", "area", "btagHbb", "msoftdrop", "rawFactor", "jetId", "subJetIdx1", "subJetIdx2"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PFatJet::branchNames{std::initializer_list<TString>{"n2b1", "n3b1", "tau1", "tau2", "tau3", "tau4", "btagCMVA", "btagCSVV2", "btagDeepB", "mass", "pt", "eta", "phi", "area", "btagHbb", "msoftdrop", "rawFactor", "jetId", "subJetIdx1", "subJetIdx2"}, panda::utils::BranchName::kAttrName};

  void
  PFatJet::datastore::allocate(UInt_t _nmax)
  {
    PSubstructuredJet::datastore::allocate(_nmax);

    area = new Float_t[nmax_];
    btagHbb = new Float_t[nmax_];
    msoftdrop = new Float_t[nmax_];
    rawFactor = new Float_t[nmax_];
    jetId = new Int_t[nmax_];
    subJetIdx1 = new Int_t[nmax_];
    subJetIdx2 = new Int_t[nmax_];
  }

  void
  PFatJet::datastore::deallocate()
  {
    PSubstructuredJet::datastore::deallocate();

    delete [] area;
    area = 0;
    delete [] btagHbb;
    btagHbb = 0;
    delete [] msoftdrop;
    msoftdrop = 0;
    delete [] rawFactor;
    rawFactor = 0;
    delete [] jetId;
    jetId = 0;
    delete [] subJetIdx1;
    subJetIdx1 = 0;
    delete [] subJetIdx2;
    subJetIdx2 = 0;
  }

  void
  PFatJet::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PSubstructuredJet::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "area"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "btagHbb"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "msoftdrop"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "rawFactor"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "jetId"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "subJetIdx1"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "subJetIdx2"), _branches);
  }

  void
  PFatJet::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PSubstructuredJet::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "area"), area, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "btagHbb"), btagHbb, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "msoftdrop"), msoftdrop, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "rawFactor"), rawFactor, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "jetId"), jetId, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "subJetIdx1"), subJetIdx1, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "subJetIdx2"), subJetIdx2, _branches, _setStatus);
  }

  void
  PFatJet::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
  {
    PSubstructuredJet::datastore::book(_tree, _name, _branches, _bookAs);

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

    panda::utils::book(_tree, BranchName(_name, "area"), size, 'F', area, _branches);
    panda::utils::book(_tree, BranchName(_name, "btagHbb"), size, 'F', btagHbb, _branches);
    panda::utils::book(_tree, BranchName(_name, "msoftdrop"), size, 'F', msoftdrop, _branches);
    panda::utils::book(_tree, BranchName(_name, "rawFactor"), size, 'F', rawFactor, _branches);
    panda::utils::book(_tree, BranchName(_name, "jetId"), size, 'I', jetId, _branches);
    panda::utils::book(_tree, BranchName(_name, "subJetIdx1"), size, 'I', subJetIdx1, _branches);
    panda::utils::book(_tree, BranchName(_name, "subJetIdx2"), size, 'I', subJetIdx2, _branches);
  }

  void
  PFatJet::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PSubstructuredJet::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "area"));
    panda::utils::resetAddress(_tree, BranchName(_name, "btagHbb"));
    panda::utils::resetAddress(_tree, BranchName(_name, "msoftdrop"));
    panda::utils::resetAddress(_tree, BranchName(_name, "rawFactor"));
    panda::utils::resetAddress(_tree, BranchName(_name, "jetId"));
    panda::utils::resetAddress(_tree, BranchName(_name, "subJetIdx1"));
    panda::utils::resetAddress(_tree, BranchName(_name, "subJetIdx2"));
  }

  void
  PFatJet::datastore::resizeVectors_(UInt_t _size)
  {
    PSubstructuredJet::datastore::resizeVectors_(_size);

  }

  PFatJet::PFatJet(char const* _name/* = ""*/) :
    PSubstructuredJet(new PFatJetArray(1, _name)),
    area(gStore.getData(this).area[0]),
    btagHbb(gStore.getData(this).btagHbb[0]),
    msoftdrop(gStore.getData(this).msoftdrop[0]),
    rawFactor(gStore.getData(this).rawFactor[0]),
    jetId(gStore.getData(this).jetId[0]),
    subJetIdx1(gStore.getData(this).subJetIdx1[0]),
    subJetIdx2(gStore.getData(this).subJetIdx2[0])
  {
  }

  PFatJet::PFatJet(PFatJet const& _src) :
    PSubstructuredJet(new PFatJetArray(1, _src.getName())),
    area(gStore.getData(this).area[0]),
    btagHbb(gStore.getData(this).btagHbb[0]),
    msoftdrop(gStore.getData(this).msoftdrop[0]),
    rawFactor(gStore.getData(this).rawFactor[0]),
    jetId(gStore.getData(this).jetId[0]),
    subJetIdx1(gStore.getData(this).subJetIdx1[0]),
    subJetIdx2(gStore.getData(this).subJetIdx2[0])
  {
    PSubstructuredJet::operator=(_src);

    area = _src.area;
    btagHbb = _src.btagHbb;
    msoftdrop = _src.msoftdrop;
    rawFactor = _src.rawFactor;
    jetId = _src.jetId;
    subJetIdx1 = _src.subJetIdx1;
    subJetIdx2 = _src.subJetIdx2;
  }

  PFatJet::PFatJet(datastore& _data, UInt_t _idx) :
    PSubstructuredJet(_data, _idx),
    area(_data.area[_idx]),
    btagHbb(_data.btagHbb[_idx]),
    msoftdrop(_data.msoftdrop[_idx]),
    rawFactor(_data.rawFactor[_idx]),
    jetId(_data.jetId[_idx]),
    subJetIdx1(_data.subJetIdx1[_idx]),
    subJetIdx2(_data.subJetIdx2[_idx])
  {
  }

  /*protected*/
  PFatJet::PFatJet(panda::ArrayBase* _array) :
    PSubstructuredJet(_array),
    area(gStore.getData(this).area[0]),
    btagHbb(gStore.getData(this).btagHbb[0]),
    msoftdrop(gStore.getData(this).msoftdrop[0]),
    rawFactor(gStore.getData(this).rawFactor[0]),
    jetId(gStore.getData(this).jetId[0]),
    subJetIdx1(gStore.getData(this).subJetIdx1[0]),
    subJetIdx2(gStore.getData(this).subJetIdx2[0])
  {
  }

  PFatJet::~PFatJet()
  {
    destructor();
  }

  PFatJet&
  PFatJet::operator=(PFatJet const& _src)
  {
    PSubstructuredJet::operator=(_src);

    area = _src.area;
    btagHbb = _src.btagHbb;
    msoftdrop = _src.msoftdrop;
    rawFactor = _src.rawFactor;
    jetId = _src.jetId;
    subJetIdx1 = _src.subJetIdx1;
    subJetIdx2 = _src.subJetIdx2;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PFatJet::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PSubstructuredJet::destructor(kTRUE);
  }

  /*protected*/
  void
  PFatJet::doInit_()
  {
    PSubstructuredJet::doInit_();

    area = 0.;
    btagHbb = 0.;
    msoftdrop = 0.;
    rawFactor = 0.;
    jetId = 0;
    subJetIdx1 = 0;
    subJetIdx2 = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PFatJet::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PFatJet::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PSubstructuredJet::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "area = " << area << std::endl;
    _out << indentation << "btagHbb = " << btagHbb << std::endl;
    _out << indentation << "msoftdrop = " << msoftdrop << std::endl;
    _out << indentation << "rawFactor = " << rawFactor << std::endl;
    _out << indentation << "jetId = " << jetId << std::endl;
    _out << indentation << "subJetIdx1 = " << subJetIdx1 << std::endl;
    _out << indentation << "subJetIdx2 = " << subJetIdx2 << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

