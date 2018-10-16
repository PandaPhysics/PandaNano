#include "../interface/PParticle.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PParticle>::branchNames{std::initializer_list<TString>{"size", "pt", "eta", "phi"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PParticle::branchNames{std::initializer_list<TString>{"pt", "eta", "phi"}, panda::utils::BranchName::kAttrName};

  void
  PParticle::datastore::allocate(UInt_t _nmax)
  {
    panda::Element::datastore::allocate(_nmax);

    pt = new Float_t[nmax_];
    eta = new Float_t[nmax_];
    phi = new Float_t[nmax_];
  }

  void
  PParticle::datastore::deallocate()
  {
    panda::Element::datastore::deallocate();

    delete [] pt;
    pt = 0;
    delete [] eta;
    eta = 0;
    delete [] phi;
    phi = 0;
  }

  void
  PParticle::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    panda::Element::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "pt"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "eta"), _branches);
    panda::utils::setStatus(_tree, BranchName(_name, "phi"), _branches);
  }

  void
  PParticle::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    panda::Element::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "pt"), pt, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "eta"), eta, _branches, _setStatus);
    panda::utils::setAddress(_tree, BranchName(_name, "phi"), phi, _branches, _setStatus);
  }

  void
  PParticle::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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

    panda::utils::book(_tree, BranchName(_name, "pt"), size, 'F', pt, _branches);
    panda::utils::book(_tree, BranchName(_name, "eta"), size, 'F', eta, _branches);
    panda::utils::book(_tree, BranchName(_name, "phi"), size, 'F', phi, _branches);
  }

  void
  PParticle::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    panda::Element::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "pt"));
    panda::utils::resetAddress(_tree, BranchName(_name, "eta"));
    panda::utils::resetAddress(_tree, BranchName(_name, "phi"));
  }

  void
  PParticle::datastore::resizeVectors_(UInt_t _size)
  {
    panda::Element::datastore::resizeVectors_(_size);

  }

  PParticle::PParticle(char const* _name/* = ""*/) :
    Element(new PParticleArray(1, _name)),
    pt(gStore.getData(this).pt[0]),
    eta(gStore.getData(this).eta[0]),
    phi(gStore.getData(this).phi[0])
  {
  }

  PParticle::PParticle(PParticle const& _src) :
    Element(new PParticleArray(1, _src.getName())),
    pt(gStore.getData(this).pt[0]),
    eta(gStore.getData(this).eta[0]),
    phi(gStore.getData(this).phi[0])
  {
    panda::Element::operator=(_src);

    pt = _src.pt;
    eta = _src.eta;
    phi = _src.phi;
  }

  PParticle::PParticle(datastore& _data, UInt_t _idx) :
    Element(_data, _idx),
    pt(_data.pt[_idx]),
    eta(_data.eta[_idx]),
    phi(_data.phi[_idx])
  {
  }

  /*protected*/
  PParticle::PParticle(panda::ArrayBase* _array) :
    Element(_array),
    pt(gStore.getData(this).pt[0]),
    eta(gStore.getData(this).eta[0]),
    phi(gStore.getData(this).phi[0])
  {
  }

  PParticle::~PParticle()
  {
    destructor();
  }

  PParticle&
  PParticle::operator=(PParticle const& _src)
  {
    panda::Element::operator=(_src);

    pt = _src.pt;
    eta = _src.eta;
    phi = _src.phi;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PParticle::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

  }

  /*protected*/
  void
  PParticle::doInit_()
  {
    pt = 0.;
    eta = 0.;
    phi = 0.;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PParticle::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PParticle::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    panda::Element::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "pt = " << pt << std::endl;
    _out << indentation << "eta = " << eta << std::endl;
    _out << indentation << "phi = " << phi << std::endl;
  }

  void
  PParticle::setPtEtaPhiM(double _pt, double _eta, double _phi, double)
  {
    pt = _pt;
    eta = _eta;
    phi = _phi;
  }

  void
  PParticle::setXYZE(double px, double py, double pz, double)
  {
    pt = std::sqrt(px * px + py * py);
    double p(std::sqrt(px * px + py * py + pz * pz));
    eta = 0.5 * std::log((p + pz) / (p - pz));
    phi = std::atan2(py, px);
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

