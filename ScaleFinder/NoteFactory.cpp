//
//  NoteFactory.cpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed (Intel) on 2/1/17.
//  Copyright © 2017 Me. All rights reserved.
//

#include "NoteFactory.hpp"
#include <string>
#include <vector>
#include <map>
#include "BasicTypes.hpp"
#include "Data.hpp"

using namespace std;

class NoteFactoryImpl;
static NoteFactoryImpl* sNoteFactoryImpl = nullptr;

class NoteFactoryImpl {

    vector<vector<Note>> notes;
    map<string, Note> name_to_notes;

    NoteFactoryImpl():notes(vector<vector<Note>>(12)){
        notes[ 0] = vector<Note>({C  , Dbb, Bs   });
        notes[ 1] = vector<Note>({Cs , Db , Bss  });
        notes[ 2] = vector<Note>({D  , Ebb, Css  });
        notes[ 3] = vector<Note>({Ds , Eb , Csss });
        notes[ 4] = vector<Note>({E  , Fb , Dss  });
        notes[ 5] = vector<Note>({F  , Gbb, Es   });
        notes[ 6] = vector<Note>({Fs , Gb , Esss });
        notes[ 7] = vector<Note>({G  , Abb, Fss  });
        notes[ 8] = vector<Note>({Gs , Ab , Fsss });
        notes[ 9] = vector<Note>({A  , Bbb, Gss  });
        notes[10] = vector<Note>({As , Bb , Gsss });
        notes[11] = vector<Note>({B  , Cb , Ass  });
        for (auto key_notes : notes){
            for (auto note : key_notes){
                name_to_notes.insert(pair<string, Note>(note.name(), note));
            }
        }
    }
    
    ~NoteFactoryImpl(){
        
    }

public:
    static NoteFactoryImpl* GetFactory() {
        if (sNoteFactoryImpl == nullptr) sNoteFactoryImpl = new NoteFactoryImpl();
        return sNoteFactoryImpl;
    }

    Note findNote(unsigned int keyNumber) {
        keyNumber = keyNumber % 12;
        return notes[keyNumber][0];
    }

    vector<Note> findAllNotes(unsigned int keyNumber){
        keyNumber = keyNumber % 12;
        return notes[keyNumber];
    }
    
    Note GetNote(const string note){
        map<string, Note>::iterator it = name_to_notes.find(note);
        if (it != name_to_notes.end()) return it->second;
        throw "invalid note name";
    }
};


namespace NoteFactory {
    Note FindNote(unsigned int keyNumber){
        return NoteFactoryImpl::GetFactory()->findNote(keyNumber);
    }
    
    std::vector<Note> FindAllNotes(unsigned int keyNumber){
        return NoteFactoryImpl::GetFactory()->findAllNotes(keyNumber);
    }
    
    Note GetNote(const std::string note) {
        return NoteFactoryImpl::GetFactory()->GetNote(note);
    }
}
