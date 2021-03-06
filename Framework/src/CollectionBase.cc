#include "../interface/CollectionBase.h"
#include "../interface/IOUtils.h"

#include "TList.h"

panda::CollectionBase::~CollectionBase()
{
  unsigned iT(0);
  while (iT != outputs_.size()) {
    if (utils::removeBranchArrayUpdator(*this, *outputs_[iT].first))
      continue; // function call reduced the outputs_ vector size

    ++iT; // if for some reason the object was already deregistered from the tree
  }
}

void
panda::CollectionBase::setStatus(TTree& _tree, utils::BranchList const& _branches)
{
  // If the size branch does not exist, there is nothing to read from this tree.
  // See comments in IOUtils.cc checkStatus for the ordering of function calls here.
  if (!_tree.GetBranch(getSizeBranchName_().toString()) && _tree.GetTreeNumber() >= 0)
    return;

  // If explicitly instructed to turn off size -> turn size false
  if (_branches.vetoes(getSizeBranchName_()))
    _tree.SetBranchStatus(getSizeBranchName_().toString(), false);
  else
    _tree.SetBranchStatus(getSizeBranchName_().toString(), true);

  getData().setStatus(_tree, name_, _branches);
}

UInt_t
panda::CollectionBase::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  doSetAddress_(_tree, _branches, _setStatus, true);

  UInt_t treeId(registerInput_(_tree));

  // if this is a new tree, we need to expand our input vectors
  if (treeId == inputInSynch_.size())
    inputInSynch_.push_back(true);

  return treeId;
}

void
panda::CollectionBase::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  if (!_branches.includes(utils::BaseBranchName(name_)))
    return;

  for (auto& output : outputs_) {
    if (output.first == &_tree)
      throw std::runtime_error(("Doubly booking collection " + name_ + " on tree").Data());
  }

  _tree.Branch(getSizeBranchName_().toString(), &size_, "size/i");

  getData().book(_tree, name_, _branches, Element::datastore::aCollection);

  outputs_.emplace_back(&_tree, true);
  
  // Repurposing BranchArrayUpdator for pointer cleaning.
  // We are not adding this updator to the tree notify list.
  _tree.GetUserInfo()->Add(new utils::BranchArrayUpdator(*this, _tree));
}

Int_t
panda::CollectionBase::getEntry(UInt_t _treeId, Long64_t _entry, Bool_t _localEntry/* = kFALSE*/)
{
  init();

  auto& tree(*inputBranches_[_treeId].first);
  auto& branches(inputBranches_[_treeId].second);

  if (!_localEntry)
    _entry = tree.LoadTree(_entry);

  // If the input tree is a TChain and there was a tree transition, LoadTree will call Notify
  // which in turn executes BranchArrayUpdator::Notify, updating the size branch automatically.

  // TBranch for size is always the first element of the branches array, because getBranchNames
  // returns name.size first.
  auto* sizeBranch(branches.at(0));
  if (!sizeBranch || sizeBranch->TestBit(kDoNotProcess))
    return 0;

  int bytes(sizeBranch->GetEntry(_entry));
  if (bytes <= 0)
    return bytes;

  // sizeIn_ is updated. Now resize the container by possibly reallocating.
  resize(sizeIn_);

  // in-synch flag may be reset during resize()
  if (!inputInSynch_[_treeId]) {
    // setStatus is false -> won't set address on branches that are turned off
    doSetAddress_(tree, {"*"}, false, true);
    inputInSynch_[_treeId] = true;
  }

  for (unsigned iB(1); iB != branches.size(); ++iB) {
    auto* branch(branches[iB]);
    if (branch && !branch->TestBit(kDoNotProcess))
      bytes += branch->GetEntry(_entry);
  }

  return bytes;
}

Int_t
panda::CollectionBase::fill(TTree& _tree)
{
  prepareFill(_tree);

  return _tree.Fill();
}

void
panda::CollectionBase::setName(char const* _name)
{
  ContainerBase::setName(_name);
  getSizeBranchName_().setObj(_name);
}

void
panda::CollectionBase::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  _out << "size: " << size() << ", allocated size: " << getData().nmax() << std::endl;
  ContainerBase::print(_out, _level);
}

void
panda::CollectionBase::dump(std::ostream& _out/* = std::cout*/, UInt_t _indent/* = 0*/) const
{
  std::string indentation(_indent * 2, ' ');
  _out << indentation << "size_ = " << size_ << std::endl;
  _out << indentation << "sizeIn_ = " << sizeIn_ << std::endl;
  ContainerBase::dump(_out, _indent);
}

void
panda::CollectionBase::unlink(TTree& _tree)
{
  ReaderObject::unlink(_tree);

  for (auto itr(outputs_.begin()); itr != outputs_.end(); ++itr) {
    if (itr->first == &_tree) {
      outputs_.erase(itr);
      return;
    }
  }
}

void
panda::CollectionBase::resize(UInt_t _size)
{
  if (_size > getData().nmax()) {
    UInt_t nmax(getData().nmax());
    while (nmax < _size)
      nmax *= 2;

    reallocate_(nmax);

    // signal address change
    inputInSynch_.assign(inputInSynch_.size(), false);
    for (auto& output : outputs_)
      output.second = false;
  }

  unsigned oldSize(size_);

  size_ = _size;
  getData().resizeVectors_(_size);

  for (unsigned iE(oldSize); iE < size_; ++iE)
    elemAt(iE).init();
}

void
panda::CollectionBase::reserve(UInt_t _size)
{
  if (_size > getData().nmax()) {
    reallocate_(_size);

    // signal address change
    inputInSynch_.assign(inputInSynch_.size(), false);
    for (auto& output : outputs_)
      output.second = false;
  }
}

void
panda::CollectionBase::prepareFill(TTree& _tree)
{
  if (outputs_.empty())
    return;

  for (auto& output : outputs_) {
    if (output.first == &_tree) {
      if (!output.second) {
        doSetAddress_(_tree, {"*"}, false, false);
        output.second = true;
      }
      break;
    }
  }
}

/*private*/
void
panda::CollectionBase::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus, Bool_t _asInput)
{
  if (!_branches.includes(utils::BaseBranchName(name_)))
    return;

  if (_branches.vetoes(getSizeBranchName_()))
    return;

  Int_t sizeStatus(0);
  if (_asInput)
    sizeStatus = utils::setAddress(_tree, getSizeBranchName_(), &sizeIn_, {"*"}, _setStatus);
  else
    sizeStatus = utils::setAddress(_tree, getSizeBranchName_(), &size_, {"*"}, _setStatus);

  if (sizeStatus != 1)
    return;
  
  getData().setAddress(_tree, name_, _branches, _setStatus);
}
