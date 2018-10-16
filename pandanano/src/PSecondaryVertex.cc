#include "../interface/PSecondaryVertex.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PSecondaryVertex>::branchNames{std::initializer_list<TString>{"size", "mass", "pt", "eta", "phi", "dlen", "dlenSig", "pAngle", "chi2", "ndof", "x", "y", "z"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PSecondaryVertex::branchNames{std::initializer_list<TString>{"mass", "pt", "eta", "phi", "dlen", "dlenSig", "pAngle", "chi2", "ndof", "x", "y", "z"}, panda::utils::BranchName::kAttrName};

  void
  PSecondaryVertex::datastore::allocate(UInt_t _nmax)
  {
    PParticleM::datastore::allocate(_nmax);

    dlen = new Float_t[nmax_];
    dlenSig = new Float_t[nmax_];
    pAngle = new Float_t[nmax_];
    chi2 = new Float_t[nmax_];
    ndof = new Float_t[nmax_];
    x = new Float_t[nmax_];
    y = new Float_t[nmax_];
    z = new Float_t[nmax_];
  }

  void
  PSecondaryVertex::datastore::deallocate()
  {
    PParticleM::datastore::deallocate();

    delete [] dlen;
    dlen = 0;
    delete [] dlenSig;
    dlenSig = 0;
    delete [] pAngle;
    pAngle = 0;
    delete [] chi2;
    chi2 = 0;
    delete [] ndof;
    ndof = 0;
    delete [] x;
    x = 0;
    delete [] y;
    y = 0;
    delete [] z;
    z = 0;
  }

  void
  PSecondaryVertex::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PParticleM::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "dlen"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "dlenSig"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "pAngle"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "chi2"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "ndof"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "x"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "y"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "z"), _branches);
  }

  void
  PSecondaryVertex::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "dlen"), dlen, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "dlenSig"), dlenSig, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "pAngle"), pAngle, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "chi2"), chi2, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "ndof"), ndof, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "x"), x, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "y"), y, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "z"), z, _branches, _setStatus);
  }

  void
  PSecondaryVertex::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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

    panda::utils::book(_tree, BranchName(_name, "dlen"), size, 'F', dlen, _branches);
    panda::utils::book(_tree, BranchName(_name, "dlenSig"), size, 'F', dlenSig, _branches);
    panda::utils::book(_tree, BranchName(_name, "pAngle"), size, 'F', pAngle, _branches);
    panda::utils::book(_tree, BranchName(_name, "chi2"), size, 'F', chi2, _branches);
    panda::utils::book(_tree, BranchName(_name, "ndof"), size, 'F', ndof, _branches);
    panda::utils::book(_tree, BranchName(_name, "x"), size, 'F', x, _branches);
    panda::utils::book(_tree, BranchName(_name, "y"), size, 'F', y, _branches);
    panda::utils::book(_tree, BranchName(_name, "z"), size, 'F', z, _branches);
  }

  void
  PSecondaryVertex::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PParticleM::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "dlen"));
    panda::utils::resetAddress(_tree, BranchName(_name, "dlenSig"));
    panda::utils::resetAddress(_tree, BranchName(_name, "pAngle"));
    panda::utils::resetAddress(_tree, BranchName(_name, "chi2"));
    panda::utils::resetAddress(_tree, BranchName(_name, "ndof"));
    panda::utils::resetAddress(_tree, BranchName(_name, "x"));
    panda::utils::resetAddress(_tree, BranchName(_name, "y"));
    panda::utils::resetAddress(_tree, BranchName(_name, "z"));
  }

  void
  PSecondaryVertex::datastore::resizeVectors_(UInt_t _size)
  {
    PParticleM::datastore::resizeVectors_(_size);

  }

  PSecondaryVertex::PSecondaryVertex(char const* _name/* = ""*/) :
    PParticleM(new PSecondaryVertexArray(1, _name)),
    dlen(gStore.getData(this).dlen[0]),
    dlenSig(gStore.getData(this).dlenSig[0]),
    pAngle(gStore.getData(this).pAngle[0]),
    chi2(gStore.getData(this).chi2[0]),
    ndof(gStore.getData(this).ndof[0]),
    x(gStore.getData(this).x[0]),
    y(gStore.getData(this).y[0]),
    z(gStore.getData(this).z[0])
  {
  }

  PSecondaryVertex::PSecondaryVertex(PSecondaryVertex const& _src) :
    PParticleM(new PSecondaryVertexArray(1, _src.getName())),
    dlen(gStore.getData(this).dlen[0]),
    dlenSig(gStore.getData(this).dlenSig[0]),
    pAngle(gStore.getData(this).pAngle[0]),
    chi2(gStore.getData(this).chi2[0]),
    ndof(gStore.getData(this).ndof[0]),
    x(gStore.getData(this).x[0]),
    y(gStore.getData(this).y[0]),
    z(gStore.getData(this).z[0])
  {
    PParticleM::operator=(_src);

    dlen = _src.dlen;
    dlenSig = _src.dlenSig;
    pAngle = _src.pAngle;
    chi2 = _src.chi2;
    ndof = _src.ndof;
    x = _src.x;
    y = _src.y;
    z = _src.z;
  }

  PSecondaryVertex::PSecondaryVertex(datastore& _data, UInt_t _idx) :
    PParticleM(_data, _idx),
    dlen(_data.dlen[_idx]),
    dlenSig(_data.dlenSig[_idx]),
    pAngle(_data.pAngle[_idx]),
    chi2(_data.chi2[_idx]),
    ndof(_data.ndof[_idx]),
    x(_data.x[_idx]),
    y(_data.y[_idx]),
    z(_data.z[_idx])
  {
  }

  /*protected*/
  PSecondaryVertex::PSecondaryVertex(panda::ArrayBase* _array) :
    PParticleM(_array),
    dlen(gStore.getData(this).dlen[0]),
    dlenSig(gStore.getData(this).dlenSig[0]),
    pAngle(gStore.getData(this).pAngle[0]),
    chi2(gStore.getData(this).chi2[0]),
    ndof(gStore.getData(this).ndof[0]),
    x(gStore.getData(this).x[0]),
    y(gStore.getData(this).y[0]),
    z(gStore.getData(this).z[0])
  {
  }

  PSecondaryVertex::~PSecondaryVertex()
  {
    destructor();
  }

  PSecondaryVertex&
  PSecondaryVertex::operator=(PSecondaryVertex const& _src)
  {
    PParticleM::operator=(_src);

    dlen = _src.dlen;
    dlenSig = _src.dlenSig;
    pAngle = _src.pAngle;
    chi2 = _src.chi2;
    ndof = _src.ndof;
    x = _src.x;
    y = _src.y;
    z = _src.z;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PSecondaryVertex::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PParticleM::destructor(kTRUE);
  }

  /*protected*/
  void
  PSecondaryVertex::doInit_()
  {
    PParticleM::doInit_();

    dlen = 0.;
    dlenSig = 0.;
    pAngle = 0.;
    chi2 = 0.;
    ndof = 0.;
    x = 0.;
    y = 0.;
    z = 0.;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PSecondaryVertex::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PSecondaryVertex::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PParticleM::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "dlen = " << dlen << std::endl;
    _out << indentation << "dlenSig = " << dlenSig << std::endl;
    _out << indentation << "pAngle = " << pAngle << std::endl;
    _out << indentation << "chi2 = " << chi2 << std::endl;
    _out << indentation << "ndof = " << ndof << std::endl;
    _out << indentation << "x = " << x << std::endl;
    _out << indentation << "y = " << y << std::endl;
    _out << indentation << "z = " << z << std::endl;
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

