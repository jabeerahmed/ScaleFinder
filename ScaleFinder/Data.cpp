//
//  Data.cpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed (Intel) on 2/1/17.
//  Copyright © 2017 Me. All rights reserved.
//

#include "Data.hpp"

const Note C  = Note("C" ,  0), Dbb = Note("Dbb",  0), Bs   = Note("B#"  ,  0);
const Note Cs = Note("C#",  1), Db  = Note("Db" ,  1), Bss  = Note("B##" ,  1);
const Note D  = Note("D" ,  2), Ebb = Note("Ebb",  2), Css  = Note("C##" ,  2);
const Note Ds = Note("D#",  3), Eb  = Note("Eb" ,  3), Csss = Note("C###",  3);
const Note E  = Note("E" ,  4), Fb  = Note("Fb" ,  4), Dss  = Note("D##" ,  4);
const Note F  = Note("F" ,  5), Gbb = Note("Gbb",  5), Es   = Note("E#"  ,  5);
const Note Fs = Note("F#",  6), Gb  = Note("Gb" ,  6), Esss = Note("E###",  6);
const Note G  = Note("G" ,  7), Abb = Note("Abb",  7), Fss  = Note("F##" ,  7);
const Note Gs = Note("G#",  8), Ab  = Note("Ab" ,  8), Fsss = Note("F###",  8);
const Note A  = Note("A" ,  9), Bbb = Note("Bbb",  9), Gss  = Note("G##" ,  9);
const Note As = Note("A#", 10), Bb  = Note("Bb" , 10), Gsss = Note("G###", 10);
const Note B  = Note("B" , 11), Cb  = Note("Cb" , 11), Ass  = Note("A##" , 11);

/*                                                         "C"  "D"    "E"    "F"    "G"    "A"    "B"    "C"  */
const Interval Major        ("Major"        , std::vector<Step>{Whole, Whole, Half,  Whole, Whole, Whole, Half });
/*                                                         "C"  "D"    Eb     "F"    "G"    Ab      Bb     C   */
const Interval Minor        ("Minor"        , std::vector<Step>{Whole, Half,  Whole, Whole, Half,  Whole, Whole});
/*                                                         C      D#     E#     F#    G     A#      C   */
const Interval Blues        ("Blues"        , std::vector<Step>{(Step)3,Whole, Half, Half,(Step)3, Whole});
/*                                                          C    D     Eb      F      G      A      Bb     C   */
const Interval Dorian       ("Dorian"       , std::vector<Step>{Whole, Half,  Whole, Whole, Whole, Half,  Whole});
/*                                                          C    Db     Eb     F      G      Ab     Bb     C   */
const Interval Phrygian     ("Phrygian"     , std::vector<Step>{Half,  Whole, Whole, Whole, Half,  Whole, Whole});
/*                                                          C    D      E      F#     G      A      B      C   */
const Interval Lydian       ("Lydian"       , std::vector<Step>{Whole, Whole, Whole, Half,  Whole, Whole, Half });
/*                                                          C    D      E      F      G      A      Bb     C   */
const Interval Mixolydian   ("Mixolydian"   , std::vector<Step>{Whole, Whole, Half, Whole,  Whole, Half, Whole});
/*                                                          C    Db     Eb     F      Gb     Ab     Bb     C   */
const Interval Locrian      ("Locrian"      , std::vector<Step>{Half,  Whole, Whole, Half,  Whole, Whole, Whole});
/*                                                          C    D     Eb      F      G      Ab     B      C   */
const Interval HarmonicMinor("Harmonic Minor",std::vector<Step>{Whole, Half,  Whole, Whole, Half,(Step)3, Half});
/*                                                          C    D     E       F      G      Ab     B      C   */
const Interval HarmonicMajor("Harmonic Major",std::vector<Step>{Whole, Whole, Half, Whole, Half, (Step)3, Half});
/*                                                                         C    D       Eb    F#      G     Ab     B       C   */
const Interval HungarianMinor       ("Hungarian Minor"      ,std::vector<Step>{Whole,  Half,(Step)3, Half, Half, (Step)3, Half});
/*                                                                         C    D       Eb    F       G     A      B       C   */
const Interval JazzMinor            ("Jazz Minor"           ,std::vector<Step>{Whole,  Half, Whole, Whole, Whole, Whole,  Half});
/*                                                                         C    D       E     F#     G##     A#    C */
const Interval Prometheus           ("Prometheus"           ,std::vector<Step>{Whole, Whole, Whole,(Step)3, Half, Whole});
/*                                                                         C    D#       E     F##     G#    A##     C */
const Interval Augmented            ("Augmented"            ,std::vector<Step>{(Step)3, Half,(Step)3, Half,(Step)3, Half});
/*                                                                         C    D      Eb    F      Gb    Ab     Bbb   Cb     C */
const Interval Diminished           ("Diminished"           ,std::vector<Step>{Whole, Half, Whole, Half, Whole, Half, Whole, Half});
/*                                                                         C    Db     E      F     G      Ab    Bb     C   */
const Interval PhrygianDominant     ("Phrygian Dominant"    ,std::vector<Step>{ Half,(Step)3,Half, Whole, Half, Whole, Whole});
/*                                                                         C    D      E      F#     G#     A#     C         */
const Interval WholeTone            ("Whole Tone"           ,std::vector<Step>{Whole, Whole, Whole, Whole, Whole, Whole});
/*                                                                         C    Db     Eb     F      G      A      B      C   */
const Interval NeopolitanMajor      ("Neopolitan Major"     ,std::vector<Step>{ Half, Whole, Whole, Whole, Whole, Whole, Half});
/*                                                                         C    Db     Eb     F      G      Ab     B      C   */
const Interval NeopolitanMinor      ("Neopolitan Minor"     ,std::vector<Step>{ Half, Whole, Whole, Whole, Half ,(Step)3,Half});
/*                                                                         C    Db     E      F      Gb     Ab     B      C   */
const Interval Persian              ("Persian"              ,std::vector<Step>{ Half,(Step)3,Half , Half , Whole,(Step)3,Half});
/*                                                                         C    Db     E      F      G      Ab     B      C   */
const Interval DoubleHarmonicMajor  ("Double Harmonic Major",std::vector<Step>{ Half,(Step)3,Half , Whole, Half ,(Step)3,Half});










