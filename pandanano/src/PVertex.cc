#include "../interface/PVertex.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PVertex>::branchNames{std::initializer_list<TString>{"size", "z"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PVertex::branchNames{std::initializer_list<TString>{"z"}, panda::utils::BranchName::kAttrName};

  void
  PVertex::datastore::allocate(UInt_t _nmax)
  {
    panda::Element::datastore::allocate(_nmax);

    z = new Float_t[nmax_];
  }

  void
  PVertex::datastore::deallocate()
  {
    panda::Element::datastore::deallocate();

    delete [] z;
    z = 0;
  }

  void
  PVertex::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    panda::Element::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "z"), _branches);
  }

  void
  PVertex::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    panda::Element::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "z"), z, _branches, _setStatus);
  }

  void
  PVertex::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
  {
    panda::Element::datastore::book(_tree, _name, _branches, _bookAs);

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

    panda::utils::book(_tree, BranchName(_name, "z"), size, 'F', z, _branches);
  }

  void
  PVertex::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    panda::Element::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "z"));
  }

  void
  PVertex::datastore::resizeVectors_(UInt_t _size)
  {
    panda::Element::datastore::resizeVectors_(_size);

  }

  PVertex::PVertex(char const* _name/* = ""*/) :
    Element(new PVertexArray(1, _name)),
    z(gStore.getData(this).z[0])
  {
  }

  PVertex::PVertex(PVertex const& _src) :
    Element(new PVertexArray(1, _src.getName())),
    z(gStore.getData(this).z[0])
  {
    panda::Element::operator=(_src);

    z = _src.z;
  }

  PVertex::PVertex(datastore& _data, UInt_t _idx) :
    Element(_data, _idx),
    z(_data.z[_idx])
  {
  }

  /*protected*/
  PVertex::PVertex(panda::ArrayBase* _array) :
    Element(_array),
    z(gStore.getData(this).z[0])
  {
  }

  PVertex::~PVertex()
  {
    destructor();
  }

  PVertex&
  PVertex::operator=(PVertex const& _src)
  {
    panda::Element::operator=(_src);

    z = _src.z;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PVertex::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

  }

  /*protected*/
  void
  PVertex::doInit_()
  {
    z = 0.;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PVertex::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PVertex::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    panda::Element::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "z = " << z << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

