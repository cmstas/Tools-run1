// -*- C++ -*-
#ifndef SAMPLE_H
#define SAMPLE_H

#include <string>

enum Process { OTHER, TEST, WW, WZ, ZZ, Wjets, DYee, DYmm, DYtt, DY, Wgamma, Zgamma, ttbar, tW, 
	       LM0, LM1, LM2, LM3, LM4, LM5, LM6, LM7, LM8, LM9, LM9p, LM10, LM11,
	       InclusiveMu5Pt50, InclusiveMuPt15, 
	       QCDBCtoEPt20to30, QCDBCtoEPt30to80, QCDBCtoEPt80to170, 
	       QCDEMenrichedPt20to30, QCDEMenrichedPt30to80, QCDEMenrichedPt80to170, QCDpt30, QCDpt80,
	       QCDpt30to80,QCDpt80to170,QCDpt170to300,QCDpt300to470,QCDpt470to800,QCDpt800toInf};

class TChain;
// struct that contains all the necessary information about a sample
class Sample {
public:
     TChain 		*chain;
     enum Process 	process;
     int		histo_color;
     double		kFactor;
     std::string	name;
     bool               sm;
     double             upper_pthat;
};

Sample operator + (const Sample &, const Sample &);

// helper functions that provide samples from their default locations
// (takes the guesswork out of data access...)
Sample fTest ();

Sample fWW	();
// Sample fWW_excl	();
Sample fWZ	();
Sample fWZ_incl	();
Sample fZZ	();
Sample fWjets	();
Sample fWjetsAlpgenSingle();
Sample fWjetsSingle ();
Sample fZjetsAlpgenSingle();
Sample fWc	();
Sample fDYee 	();
Sample fDYmm 	();
Sample fDYtt 	();
Sample fVlqq	();
Sample fAstar	();
Sample fDY20tt	();
Sample fDY20mm	();
Sample fDY20ee  ();
Sample fWgamma	();
Sample fZgamma	();
Sample fttbar	();
Sample fttbar_taula	();
Sample ftW	();
Sample fSingleTop_tChannel	();
Sample fSingleTop_sChannel	();
Sample fLM0     ();
Sample fLM1     ();
Sample fLM2     ();
Sample fLM3     ();
Sample fLM4     ();
Sample fLM5     ();
Sample fLM6     ();
Sample fLM7     ();
Sample fLM8     ();
Sample fLM9     ();
Sample fLM9p    ();
Sample fLM10    ();
Sample fLM11    ();
  
// QCD samples
Sample fInclusiveMu5Pt50	();
Sample fInclusiveMuPt15	        ();
Sample fQCDBCtoEPt20to30	();
Sample fQCDBCtoEPt30to80	();
Sample fQCDBCtoEPt80to170	();
Sample fQCDEMenrichedPt20to30	();
Sample fQCDEMenrichedPt30to80	();
Sample fQCDEMenrichedPt80to170  ();
Sample fQCDpt30  ();
Sample fQCDpt80  ();
Sample fQCDpt30to80  ();
Sample fQCDpt80to170  ();
Sample fQCDpt170to300  ();
Sample fQCDpt300to470  ();
Sample fQCDpt470to800  ();
Sample fQCDpt800toInf  ();


// filter events by process
bool filterByProcess (enum Process sample);

#endif
