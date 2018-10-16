#include "../interface/PParticleM.h"
#include "../../Framework/interface/IOUtils.h"

namespace panda {
  /*static*/
  template<>
  pandanano::BranchList const Collection<pandanano::PParticleM>::branchNames{std::initializer_list<TString>{"size", "pt", "eta", "phi", "mass"}, panda::utils::BranchName::kAttrName};
}

namespace pandanano {

  /*static*/
  BranchList const PParticleM::branchNames{std::initializer_list<TString>{"pt", "eta", "phi", "mass"}, panda::utils::BranchName::kAttrName};

  void
  PParticleM::datastore::allocate(UInt_t _nmax)
  {
    PParticle::datastore::allocate(_nmax);

    mass = new Float_t[nmax_];
  }

  void
  PParticleM::datastore::deallocate()
  {
    PParticle::datastore::deallocate();

    delete [] mass;
    mass = 0;
  }

  void
  PParticleM::datastore::setStatus(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches)
  {
    PParticle::datastore::setStatus(_tree, _name, _branches);

    panda::utils::setStatus(_tree, BranchName(_name, "mass"), _branches);
  }

  void
  PParticleM::datastore::setAddress(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
  {
    PParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

    panda::utils::setAddress(_tree, BranchName(_name, "mass"), mass, _branches, _setStatus);
  }

  void
  PParticleM::datastore::book(TTree& _tree, TString const& _name, panda::utils::BranchList const& _branches/* = {"*"}*/, BookAs _bookAs/* = aCollection*/)
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

    panda::utils::book(_tree, BranchName(_name, "mass"), size, 'F', mass, _branches);
  }

  void
  PParticleM::datastore::releaseTree(TTree& _tree, TString const& _name)
  {
    PParticle::datastore::releaseTree(_tree, _name);

    panda::utils::resetAddress(_tree, BranchName(_name, "mass"));
  }

  void
  PParticleM::datastore::resizeVectors_(UInt_t _size)
  {
    PParticle::datastore::resizeVectors_(_size);

  }

  PParticleM::PParticleM(char const* _name/* = ""*/) :
    PParticle(new PParticleMArray(1, _name)),
    mass(gStore.getData(this).mass[0])
  {
  }

  PParticleM::PParticleM(PParticleM const& _src) :
    PParticle(new PParticleMArray(1, _src.getName())),
    mass(gStore.getData(this).mass[0])
  {
    PParticle::operator=(_src);

    mass = _src.mass;
  }

  PParticleM::PParticleM(datastore& _data, UInt_t _idx) :
    PParticle(_data, _idx),
    mass(_data.mass[_idx])
  {
  }

  /*protected*/
  PParticleM::PParticleM(panda::ArrayBase* _array) :
    PParticle(_array),
    mass(gStore.getData(this).mass[0])
  {
  }

  PParticleM::~PParticleM()
  {
    destructor();
  }

  PParticleM&
  PParticleM::operator=(PParticleM const& _src)
  {
    PParticle::operator=(_src);

    mass = _src.mass;

    /* BEGIN CUSTOM assignment */
    /* END CUSTOM */

    return *this;
  }

  void
  PParticleM::destructor(Bool_t _recursive/* = kFALSE*/)
  {
    /* BEGIN CUSTOM destructor */
    /* END CUSTOM */

    if (_recursive)
      PParticle::destructor(kTRUE);
  }

  /*protected*/
  void
  PParticleM::doInit_()
  {
    PParticle::doInit_();

    mass = 0.;

    /* BEGIN CUSTOM init */
    /* END CUSTOM */
  }

  void
  PParticleM::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
  {
    /* BEGIN CUSTOM print */
    dump(_out);
    /* END CUSTOM */
  }

  void
  PParticleM::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
  {
    PParticle::dump(_out, _indent);
    std::string indentation(_indent * 2, ' ');
    _out << indentation << "mass = " << mass << std::endl;
  }

  void
  PParticleM::setPtEtaPhiM(double _pt, double _eta, double _phi, double _mass)
  {
    pt = _pt;
    eta = _eta;
    phi = _phi;
    mass = _mass;
  }

  void
  PParticleM::setXYZE(double px, double py, double pz, double e)
  {
    pt = std::sqrt(px * px + py * py);
    double p(std::sqrt(px * px + py * py + pz * pz));
    eta = 0.5 * std::log((p + pz) / (p - pz));
    phi = std::atan2(py, px);
    mass = std::sqrt(e * e - p * p);
  }

  /* BEGIN CUSTOM global */
  /* END CUSTOM */

}

