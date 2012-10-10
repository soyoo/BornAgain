//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Oct 10 15:14:35 2012 by ROOT version 5.34/01
// from TTree FitSuiteTree/Oh, my data
// found on file: ../../../../fitsuite.root
//////////////////////////////////////////////////////////

#ifndef FitData_h
#define FitData_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class FitData {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //TreeEventFitData *Event;
   Int_t           niter;
   vector<vector<double> > real_data;
   vector<vector<double> > fit_data;
   vector<vector<double> > diff;
   vector<vector<double> > axis0;
   vector<vector<double> > axis1;
   Double_t        chi2;
   vector<double>  params;
   vector<string>  parnames;

   // List of branches
   TBranch        *b_Event_niter;   //!
   TBranch        *b_Event_real_data;   //!
   TBranch        *b_Event_fit_data;   //!
   TBranch        *b_Event_diff;   //!
   TBranch        *b_Event_axis0;   //!
   TBranch        *b_Event_axis1;   //!
   TBranch        *b_Event_chi2;   //!
   TBranch        *b_Event_params;   //!
   TBranch        *b_Event_parnames;   //!

   FitData(TTree *tree=0);
   virtual ~FitData();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef FitData_cxx
FitData::FitData(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../../../../fitsuite.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../../../../fitsuite.root");
      }
      f->GetObject("FitSuiteTree",tree);

   }
   Init(tree);
}

FitData::~FitData()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t FitData::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t FitData::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void FitData::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("niter", &niter, &b_Event_niter);
   fChain->SetBranchAddress("real_data", &real_data, &b_Event_real_data);
   fChain->SetBranchAddress("fit_data", &fit_data, &b_Event_fit_data);
   fChain->SetBranchAddress("diff", &diff, &b_Event_diff);
   fChain->SetBranchAddress("axis0", &axis0, &b_Event_axis0);
   fChain->SetBranchAddress("axis1", &axis1, &b_Event_axis1);
   fChain->SetBranchAddress("chi2", &chi2, &b_Event_chi2);
   fChain->SetBranchAddress("params", &params, &b_Event_params);
   fChain->SetBranchAddress("parnames", &parnames, &b_Event_parnames);
   Notify();
}

Bool_t FitData::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void FitData::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t FitData::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef FitData_cxx
