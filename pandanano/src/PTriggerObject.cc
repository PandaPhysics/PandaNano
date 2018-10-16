#include "../interface/PTriggerObject.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PTriggerObject>::branchNames{std::initializer_list<TString>{"size", "pt", "eta", "phi", "l1pt", "l1pt_2", "l2pt", "id", "l1iso", "l1charge", "filterBits"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PTriggerObject::branchNames{std::initializer_list<TString>{"pt", "eta", "phi", "l1pt", "l1pt_2", "l2pt", "id", "l1iso", "l1charge", "filterBits"}, panda::utils::BranchName::kAttrName};

  void
  PTriggerObject::datastore::allocate(UInt_t _nmax)
  {
    PParticle::datastore::allocate(_nmax);

    l1pt = new Float_t[nmax_];
    l1pt_2 = new Float_t[nmax_];
    l2pt = new Float_t[nmax_];
    id = new Int_t[nmax_];
    l1iso = new Int_t[nmax_];
    l1charge = new Int_t[nmax_];
    filterBits = new Int_t[nmax_];
  }

  void
  PTriggerObject::datastore::deallocate()
  {
    PParticle::datastore::deallocate();

    delete [] l1pt;
    l1pt = 0;
    delete [] l1pt_2;
    l1pt_2 = 0;
    delete [] l2pt;
    l2pt = 0;
    delete [] id;
    id = 0;
    delete [] l1iso;
    l1iso = 0;
    delete [] l1charge;
    l1charge = 0;
    delete [] filterBits;
    filterBits = 0;
  }

  void
  PTriggerObject::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PParticle::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "l1pt"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "l1pt_2"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "l2pt"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "id"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "l1iso"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "l1charge"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "filterBits"), _branches);
  }

  void
  PTriggerObject::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "l1pt"), l1pt, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "l1pt_2"), l1pt_2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "l2pt"), l2pt, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "id"), id, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "l1iso"), l1iso, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "l1charge"), l1charge, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "filterBits"), filterBits, _branches, _setStatus);
  }

  void
  PTriggerObject::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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

    panda::utils::book(_tree, BranchName(_name, "l1pt"), size, 'F', l1pt, _branches);
    panda::utils::book(_tree, BranchName(_name, "l1pt_2"), size, 'F', l1pt_2, _branches);
    panda::utils::book(_tree, BranchName(_name, "l2pt"), size, 'F', l2pt, _branches);
    panda::utils::book(_tree, BranchName(_name, "id"), size, 'I', id, _branches);
    panda::utils::book(_tree, BranchName(_name, "l1iso"), size, 'I', l1iso, _branches);
    panda::utils::book(_tree, BranchName(_name, "l1charge"), size, 'I', l1charge, _branches);
    panda::utils::book(_tree, BranchName(_name, "filterBits"), size, 'I', filterBits, _branches);
  }

  void
  PTriggerObject::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PParticle::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "l1pt"));
    panda::utils::resetAddress(_tree, BranchName(_name, "l1pt_2"));
    panda::utils::resetAddress(_tree, BranchName(_name, "l2pt"));
    panda::utils::resetAddress(_tree, BranchName(_name, "id"));
    panda::utils::resetAddress(_tree, BranchName(_name, "l1iso"));
    panda::utils::resetAddress(_tree, BranchName(_name, "l1charge"));
    panda::utils::resetAddress(_tree, BranchName(_name, "filterBits"));
  }

  void
  PTriggerObject::datastore::resizeVectors_(UInt_t _size)
  {
    PParticle::datastore::resizeVectors_(_size);

  }

  PTriggerObject::PTriggerObject(char const* _name/* = ""*/) :
    PParticle(new PTriggerObjectArray(1, _name)),
    l1pt(gStore.getData(this).l1pt[0]),
    l1pt_2(gStore.getData(this).l1pt_2[0]),
    l2pt(gStore.getData(this).l2pt[0]),
    id(gStore.getData(this).id[0]),
    l1iso(gStore.getData(this).l1iso[0]),
    l1charge(gStore.getData(this).l1charge[0]),
    filterBits(gStore.getData(this).filterBits[0])
  {
  }

  PTriggerObject::PTriggerObject(PTriggerObject const& _src) :
    PParticle(new PTriggerObjectArray(1, _src.getName())),
    l1pt(gStore.getData(this).l1pt[0]),
    l1pt_2(gStore.getData(this).l1pt_2[0]),
    l2pt(gStore.getData(this).l2pt[0]),
    id(gStore.getData(this).id[0]),
    l1iso(gStore.getData(this).l1iso[0]),
    l1charge(gStore.getData(this).l1charge[0]),
    filterBits(gStore.getData(this).filterBits[0])
  {
    PParticle::operator=(_src);

    l1pt = _src.l1pt;
    l1pt_2 = _src.l1pt_2;
    l2pt = _src.l2pt;
    id = _src.id;
    l1iso = _src.l1iso;
    l1charge = _src.l1charge;
    filterBits = _src.filterBits;
  }

  PTriggerObject::PTriggerObject(datastore& _data, UInt_t _idx) :
    PParticle(_data, _idx),
    l1pt(_data.l1pt[_idx]),
    l1pt_2(_data.l1pt_2[_idx]),
    l2pt(_data.l2pt[_idx]),
    id(_data.id[_idx]),
    l1iso(_data.l1iso[_idx]),
    l1charge(_data.l1charge[_idx]),
    filterBits(_data.filterBits[_idx])
  {
  }

  /*protected*/
  PTriggerObject::PTriggerObject(panda::ArrayBase* _array) :
    PParticle(_array),
    l1pt(gStore.getData(this).l1pt[0]),
    l1pt_2(gStore.getData(this).l1pt_2[0]),
    l2pt(gStore.getData(this).l2pt[0]),
    id(gStore.getData(this).id[0]),
    l1iso(gStore.getData(this).l1iso[0]),
    l1charge(gStore.getData(this).l1charge[0]),
    filterBits(gStore.getData(this).filterBits[0])
  {
  }

  PTriggerObject::~PTriggerObject()
  {
    destructor();
  }

  PTriggerObject&
  PTriggerObject::operator=(PTriggerObject const& _src)
  {
    PParticle::operator=(_src);

    l1pt = _src.l1pt;
    l1pt_2 = _src.l1pt_2;
    l2pt = _src.l2pt;
    id = _src.id;
    l1iso = _src.l1iso;
    l1charge = _src.l1charge;
    filterBits = _src.filterBits;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PTriggerObject::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PParticle::destructor(kTRUE);
  }

  /*protected*/
  void
  PTriggerObject::doInit_()
  {
    PParticle::doInit_();

    l1pt = 0.;
    l1pt_2 = 0.;
    l2pt = 0.;
    id = 0;
    l1iso = 0;
    l1charge = 0;
    filterBits = 0;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PTriggerObject::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PTriggerObject::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PParticle::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "l1pt = " << l1pt << std::endl;
    _out << indentation << "l1pt_2 = " << l1pt_2 << std::endl;
    _out << indentation << "l2pt = " << l2pt << std::endl;
    _out << indentation << "id = " << id << std::endl;
    _out << indentation << "l1iso = " << l1iso << std::endl;
    _out << indentation << "l1charge = " << l1charge << std::endl;
    _out << indentation << "filterBits = " << filterBits << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

