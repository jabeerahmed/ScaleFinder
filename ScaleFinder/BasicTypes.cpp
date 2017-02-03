//
//  BasicTypes.cpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed (Intel) on 1/11/17.
//  Copyright © 2017 Me. All rights reserved.
//

#include "BasicTypes.hpp"
#include "NoteFactory.hpp"
#include <set>
#include <vector>

Note Note::FindNote(unsigned int keyNumber){
    return NoteFactory::FindNote(keyNumber);
}


std::vector<Note> Note::findAllNotes(unsigned int keyNumber){
    return NoteFactory::FindAllNotes(keyNumber);
}


Note Note::GetNote(const std::string note) {
    return NoteFactory::GetNote(note);
}
