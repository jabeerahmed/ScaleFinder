//
//  BasicTypes.cpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed on 1/11/17.
//  Copyright © 2017 Me. All rights reserved.
//

#include "BasicTypes.hpp"
#include "NoteFactory.hpp"
#include <set>
#include <vector>


int Note::__instance_id = 0;
int Scale::__instance_id = 0;
int Interval::__instance_id = 0;

Note Note::FindNote(unsigned int keyNumber){
    return NoteFactory::FindNote(keyNumber);
}


std::vector<Note> Note::findAllNotes(unsigned int keyNumber){
    return NoteFactory::FindAllNotes(keyNumber);
}


Note Note::GetNote(const std::string note) {
    return NoteFactory::GetNote(note);
}
