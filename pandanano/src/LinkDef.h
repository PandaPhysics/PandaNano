#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/Object.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/ReaderObject.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/Singlet.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/Element.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/ContainerBase.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/ArrayBase.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/CollectionBase.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/TreeEntry.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/RRNG.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/BranchName.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/Framework/interface/BranchList.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PBTagWeight.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PGenInfo.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PLHEInfo.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PLHEWeight.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PPileupInfo.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PEventFilter.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PParticle.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PParticleM.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PRecoParticle.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PMET.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PRecoMET.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PPrimaryVertex.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PVertex.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PSecondaryVertex.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PTruthParticle.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PGenParticle.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PRecoJet.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PJet.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PSubstructuredJet.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PFatJet.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PGenJet.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PLepton.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PElectron.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PMuon.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PPhoton.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PTau.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PGenTau.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PIsoTrack.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/PTriggerObject.h"
#include "/afs/cern.ch/user/y/yiiyama/src/pandanano/pandanano/interface/Events.h"

#ifdef __CLING__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

#pragma link C++ namespace panda;
#pragma link C++ namespace panda::utils;
#pragma link C++ class panda::Object;
#pragma link C++ class panda::ReaderObject;
#pragma link C++ class panda::Singlet;
#pragma link C++ class panda::Element;
#pragma link C++ class panda::ContainerBase;
#pragma link C++ class panda::ArrayBase;
#pragma link C++ class panda::CollectionBase;
#pragma link C++ class panda::TreeEntry;
#pragma link C++ class panda::RRNG;
#pragma link C++ class panda::utils::BranchName;
#pragma link C++ class panda::utils::BranchList;
#pragma link C++ namespace pandanano;
#pragma link C++ class panda::utils::BranchNameImpl<pandanano::BranchNameSyntax, pandanano::SizeBranchNameSyntax>;
#pragma link C++ class panda::utils::BranchListImpl<pandanano::BranchNameSyntax, pandanano::SizeBranchNameSyntax>;
#pragma link C++ typedef pandanano::BranchName;
#pragma link C++ typedef pandanano::BranchList;
#pragma link C++ class pandanano::PBTagWeight;
#pragma link C++ class pandanano::PGenInfo;
#pragma link C++ class pandanano::PLHEInfo;
#pragma link C++ class pandanano::PLHEWeight;
#pragma link C++ class pandanano::PPileupInfo;
#pragma link C++ class pandanano::PEventFilter;
#pragma link C++ class pandanano::PParticle;
#pragma link C++ class pandanano::PParticleM;
#pragma link C++ class pandanano::PRecoParticle;
#pragma link C++ class pandanano::PMET;
#pragma link C++ class pandanano::PRecoMET;
#pragma link C++ class pandanano::PPrimaryVertex;
#pragma link C++ class pandanano::PVertex;
#pragma link C++ class pandanano::PSecondaryVertex;
#pragma link C++ class pandanano::PTruthParticle;
#pragma link C++ class pandanano::PGenParticle;
#pragma link C++ class pandanano::PRecoJet;
#pragma link C++ class pandanano::PJet;
#pragma link C++ class pandanano::PSubstructuredJet;
#pragma link C++ class pandanano::PFatJet;
#pragma link C++ class pandanano::PGenJet;
#pragma link C++ class pandanano::PLepton;
#pragma link C++ class pandanano::PElectron;
#pragma link C++ class pandanano::PMuon;
#pragma link C++ class pandanano::PPhoton;
#pragma link C++ class pandanano::PTau;
#pragma link C++ class pandanano::PGenTau;
#pragma link C++ class pandanano::PIsoTrack;
#pragma link C++ class pandanano::PTriggerObject;
#pragma link C++ class panda::Array<pandanano::PParticle>;
#pragma link C++ class panda::Collection<pandanano::PParticle>;
#pragma link C++ class panda::Ref<pandanano::PParticle>;
#pragma link C++ class panda::RefVector<pandanano::PParticle>;
#pragma link C++ typedef pandanano::PParticleArray;
#pragma link C++ typedef pandanano::PParticleCollection;
#pragma link C++ typedef pandanano::PParticleRef;
#pragma link C++ typedef pandanano::PParticleRefVector;
#pragma link C++ class panda::Array<pandanano::PParticleM>;
#pragma link C++ class panda::Collection<pandanano::PParticleM>;
#pragma link C++ class panda::Ref<pandanano::PParticleM>;
#pragma link C++ class panda::RefVector<pandanano::PParticleM>;
#pragma link C++ typedef pandanano::PParticleMArray;
#pragma link C++ typedef pandanano::PParticleMCollection;
#pragma link C++ typedef pandanano::PParticleMRef;
#pragma link C++ typedef pandanano::PParticleMRefVector;
#pragma link C++ class panda::Array<pandanano::PRecoParticle>;
#pragma link C++ class panda::Collection<pandanano::PRecoParticle>;
#pragma link C++ class panda::Ref<pandanano::PRecoParticle>;
#pragma link C++ class panda::RefVector<pandanano::PRecoParticle>;
#pragma link C++ typedef pandanano::PRecoParticleArray;
#pragma link C++ typedef pandanano::PRecoParticleCollection;
#pragma link C++ typedef pandanano::PRecoParticleRef;
#pragma link C++ typedef pandanano::PRecoParticleRefVector;
#pragma link C++ class panda::Array<pandanano::PVertex>;
#pragma link C++ class panda::Collection<pandanano::PVertex>;
#pragma link C++ class panda::Ref<pandanano::PVertex>;
#pragma link C++ class panda::RefVector<pandanano::PVertex>;
#pragma link C++ typedef pandanano::PVertexArray;
#pragma link C++ typedef pandanano::PVertexCollection;
#pragma link C++ typedef pandanano::PVertexRef;
#pragma link C++ typedef pandanano::PVertexRefVector;
#pragma link C++ class panda::Array<pandanano::PSecondaryVertex>;
#pragma link C++ class panda::Collection<pandanano::PSecondaryVertex>;
#pragma link C++ class panda::Ref<pandanano::PSecondaryVertex>;
#pragma link C++ class panda::RefVector<pandanano::PSecondaryVertex>;
#pragma link C++ typedef pandanano::PSecondaryVertexArray;
#pragma link C++ typedef pandanano::PSecondaryVertexCollection;
#pragma link C++ typedef pandanano::PSecondaryVertexRef;
#pragma link C++ typedef pandanano::PSecondaryVertexRefVector;
#pragma link C++ class panda::Array<pandanano::PTruthParticle>;
#pragma link C++ class panda::Collection<pandanano::PTruthParticle>;
#pragma link C++ class panda::Ref<pandanano::PTruthParticle>;
#pragma link C++ class panda::RefVector<pandanano::PTruthParticle>;
#pragma link C++ typedef pandanano::PTruthParticleArray;
#pragma link C++ typedef pandanano::PTruthParticleCollection;
#pragma link C++ typedef pandanano::PTruthParticleRef;
#pragma link C++ typedef pandanano::PTruthParticleRefVector;
#pragma link C++ class panda::Array<pandanano::PGenParticle>;
#pragma link C++ class panda::Collection<pandanano::PGenParticle>;
#pragma link C++ class panda::Ref<pandanano::PGenParticle>;
#pragma link C++ class panda::RefVector<pandanano::PGenParticle>;
#pragma link C++ typedef pandanano::PGenParticleArray;
#pragma link C++ typedef pandanano::PGenParticleCollection;
#pragma link C++ typedef pandanano::PGenParticleRef;
#pragma link C++ typedef pandanano::PGenParticleRefVector;
#pragma link C++ class panda::Array<pandanano::PRecoJet>;
#pragma link C++ class panda::Collection<pandanano::PRecoJet>;
#pragma link C++ class panda::Ref<pandanano::PRecoJet>;
#pragma link C++ class panda::RefVector<pandanano::PRecoJet>;
#pragma link C++ typedef pandanano::PRecoJetArray;
#pragma link C++ typedef pandanano::PRecoJetCollection;
#pragma link C++ typedef pandanano::PRecoJetRef;
#pragma link C++ typedef pandanano::PRecoJetRefVector;
#pragma link C++ class panda::Array<pandanano::PJet>;
#pragma link C++ class panda::Collection<pandanano::PJet>;
#pragma link C++ class panda::Ref<pandanano::PJet>;
#pragma link C++ class panda::RefVector<pandanano::PJet>;
#pragma link C++ typedef pandanano::PJetArray;
#pragma link C++ typedef pandanano::PJetCollection;
#pragma link C++ typedef pandanano::PJetRef;
#pragma link C++ typedef pandanano::PJetRefVector;
#pragma link C++ class panda::Array<pandanano::PSubstructuredJet>;
#pragma link C++ class panda::Collection<pandanano::PSubstructuredJet>;
#pragma link C++ class panda::Ref<pandanano::PSubstructuredJet>;
#pragma link C++ class panda::RefVector<pandanano::PSubstructuredJet>;
#pragma link C++ typedef pandanano::PSubstructuredJetArray;
#pragma link C++ typedef pandanano::PSubstructuredJetCollection;
#pragma link C++ typedef pandanano::PSubstructuredJetRef;
#pragma link C++ typedef pandanano::PSubstructuredJetRefVector;
#pragma link C++ class panda::Array<pandanano::PFatJet>;
#pragma link C++ class panda::Collection<pandanano::PFatJet>;
#pragma link C++ class panda::Ref<pandanano::PFatJet>;
#pragma link C++ class panda::RefVector<pandanano::PFatJet>;
#pragma link C++ typedef pandanano::PFatJetArray;
#pragma link C++ typedef pandanano::PFatJetCollection;
#pragma link C++ typedef pandanano::PFatJetRef;
#pragma link C++ typedef pandanano::PFatJetRefVector;
#pragma link C++ class panda::Array<pandanano::PGenJet>;
#pragma link C++ class panda::Collection<pandanano::PGenJet>;
#pragma link C++ class panda::Ref<pandanano::PGenJet>;
#pragma link C++ class panda::RefVector<pandanano::PGenJet>;
#pragma link C++ typedef pandanano::PGenJetArray;
#pragma link C++ typedef pandanano::PGenJetCollection;
#pragma link C++ typedef pandanano::PGenJetRef;
#pragma link C++ typedef pandanano::PGenJetRefVector;
#pragma link C++ class panda::Array<pandanano::PLepton>;
#pragma link C++ class panda::Collection<pandanano::PLepton>;
#pragma link C++ class panda::Ref<pandanano::PLepton>;
#pragma link C++ class panda::RefVector<pandanano::PLepton>;
#pragma link C++ typedef pandanano::PLeptonArray;
#pragma link C++ typedef pandanano::PLeptonCollection;
#pragma link C++ typedef pandanano::PLeptonRef;
#pragma link C++ typedef pandanano::PLeptonRefVector;
#pragma link C++ class panda::Array<pandanano::PElectron>;
#pragma link C++ class panda::Collection<pandanano::PElectron>;
#pragma link C++ class panda::Ref<pandanano::PElectron>;
#pragma link C++ class panda::RefVector<pandanano::PElectron>;
#pragma link C++ typedef pandanano::PElectronArray;
#pragma link C++ typedef pandanano::PElectronCollection;
#pragma link C++ typedef pandanano::PElectronRef;
#pragma link C++ typedef pandanano::PElectronRefVector;
#pragma link C++ class panda::Array<pandanano::PMuon>;
#pragma link C++ class panda::Collection<pandanano::PMuon>;
#pragma link C++ class panda::Ref<pandanano::PMuon>;
#pragma link C++ class panda::RefVector<pandanano::PMuon>;
#pragma link C++ typedef pandanano::PMuonArray;
#pragma link C++ typedef pandanano::PMuonCollection;
#pragma link C++ typedef pandanano::PMuonRef;
#pragma link C++ typedef pandanano::PMuonRefVector;
#pragma link C++ class panda::Array<pandanano::PPhoton>;
#pragma link C++ class panda::Collection<pandanano::PPhoton>;
#pragma link C++ class panda::Ref<pandanano::PPhoton>;
#pragma link C++ class panda::RefVector<pandanano::PPhoton>;
#pragma link C++ typedef pandanano::PPhotonArray;
#pragma link C++ typedef pandanano::PPhotonCollection;
#pragma link C++ typedef pandanano::PPhotonRef;
#pragma link C++ typedef pandanano::PPhotonRefVector;
#pragma link C++ class panda::Array<pandanano::PTau>;
#pragma link C++ class panda::Collection<pandanano::PTau>;
#pragma link C++ class panda::Ref<pandanano::PTau>;
#pragma link C++ class panda::RefVector<pandanano::PTau>;
#pragma link C++ typedef pandanano::PTauArray;
#pragma link C++ typedef pandanano::PTauCollection;
#pragma link C++ typedef pandanano::PTauRef;
#pragma link C++ typedef pandanano::PTauRefVector;
#pragma link C++ class panda::Array<pandanano::PGenTau>;
#pragma link C++ class panda::Collection<pandanano::PGenTau>;
#pragma link C++ class panda::Ref<pandanano::PGenTau>;
#pragma link C++ class panda::RefVector<pandanano::PGenTau>;
#pragma link C++ typedef pandanano::PGenTauArray;
#pragma link C++ typedef pandanano::PGenTauCollection;
#pragma link C++ typedef pandanano::PGenTauRef;
#pragma link C++ typedef pandanano::PGenTauRefVector;
#pragma link C++ class panda::Array<pandanano::PIsoTrack>;
#pragma link C++ class panda::Collection<pandanano::PIsoTrack>;
#pragma link C++ class panda::Ref<pandanano::PIsoTrack>;
#pragma link C++ class panda::RefVector<pandanano::PIsoTrack>;
#pragma link C++ typedef pandanano::PIsoTrackArray;
#pragma link C++ typedef pandanano::PIsoTrackCollection;
#pragma link C++ typedef pandanano::PIsoTrackRef;
#pragma link C++ typedef pandanano::PIsoTrackRefVector;
#pragma link C++ class panda::Array<pandanano::PTriggerObject>;
#pragma link C++ class panda::Collection<pandanano::PTriggerObject>;
#pragma link C++ class panda::Ref<pandanano::PTriggerObject>;
#pragma link C++ class panda::RefVector<pandanano::PTriggerObject>;
#pragma link C++ typedef pandanano::PTriggerObjectArray;
#pragma link C++ typedef pandanano::PTriggerObjectCollection;
#pragma link C++ typedef pandanano::PTriggerObjectRef;
#pragma link C++ typedef pandanano::PTriggerObjectRefVector;
#pragma link C++ class pandanano::Events;

#endif

