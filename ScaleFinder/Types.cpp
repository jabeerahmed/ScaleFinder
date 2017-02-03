//
//  Types.cpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed (Intel) on 1/10/17.
//  Copyright © 2017 Me. All rights reserved.
//

#include <stdio.h>
#include "Types.h"

using namespace std;

static vector<const char> NoteRoots = {'C', 'D', 'E', 'F', 'G', 'A', 'B'};
static vector<Note> __NoteList = {
    Note("C" , "Dbb", "B#" ,  0),
    Note("C#", "Db" , "B##",  1),
    Note("D" , "Ebb", "C##",  2),
    Note("D#", "Eb" , "C###", 3),
    Note("E" , "Fb" , "D##",  4),
    Note("F" , "Gbb", "E#",   5),
    Note("F#", "Gb" , "E###", 6),
    Note("G" , "Abb", "F##",  7),
    Note("G#", "Ab" , "F###", 8),
    Note("A" , "Bbb", "G##",  9),
    Note("A#", "Bb" , "G###",10),
    Note("B" , "Cb" , "A##", 11),
};



