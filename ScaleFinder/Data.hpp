//
//  Data.hpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed on 2/1/17.
//  Copyright © 2017 Me. All rights reserved.
//

#ifndef Data_hpp
#define Data_hpp

#include <stdio.h>
#include <set>
#include "BasicTypes.hpp"

// All the intervals
extern const Interval Major, Minor, Dorian, Phrygian, Lydian, Mixolydian, Locrian, HarmonicMinor, HarmonicMajor;
extern const Interval HungarianMinor, JazzMinor, Prometheus, Augmented, Diminished, PhrygianDominant, WholeTone;
extern const Interval NeopolitanMajor, NeopolitanMinor, Persian, DoubleHarmonicMajor;
extern const std::set<Interval> AllIntervals;

// All the Notes
extern const Note C  , Cs , D  , Ds , E  , F  , Fs , G  , Gs , A  , As , B  ;
extern const Note Dbb, Db , Ebb, Eb , Fb , Gbb, Gb , Abb, Ab , Bbb, Bb , Cb ;
extern const Note Bs , Bss, Css,Csss, Dss, Es ,Esss, Fss,Fsss, Gss,Gsss, Ass;
extern const std::set<Note> AllNotes;

#endif /* Data_hpp */
