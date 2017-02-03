//
//  NoteFactory.hpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed (Intel) on 2/1/17.
//  Copyright © 2017 Me. All rights reserved.
//

#ifndef NoteFactory_hpp
#define NoteFactory_hpp

#include "BasicTypes.hpp"
#include <stdio.h>
#include <vector>
#include <string>

namespace NoteFactory {
    Note FindNote(unsigned int keyNumber);
    std::vector<Note> FindAllNotes(unsigned int keyNumber);
    Note GetNote(const std::string note);
}


#endif /* NoteFactory_hpp */
