//
//  Types.h
//  ScaleFinder
//
//  Created by Jabeer Ahmed (Intel) on 1/10/17.
//  Copyright © 2017 Me. All rights reserved.
//

#ifndef Types_h
#define Types_h

#include <vector>
#include <string>

union NoteName {
    const char c_str[3];
    const struct __parts{
        const char root;
        const char mode;
        __parts(const char note[3]):root(note[0]), mode(note[1]), __null_char('\n'){}

    private:
        const char __null_char;
        
    } parts;
    
    NoteName(const char note[3]):parts(note){}
};


class Note {
    const int keyNum;
public:
    const std::string root;
    const std::string flat;
    const std::string sharp;
    Note(const char nRoot[3], const char nFlat[3], const char nSharp[3], int nKeyNum):root(nRoot), flat(nFlat), sharp(nSharp), keyNum(nKeyNum){}

    inline const char* c_str(){ return root.c_str(); }
    inline std::string str(){ return root; }
        
    inline const char* c_str(const char note_root){
        if ( root[0] == note_root) return root.c_str();
        if ( flat[0] == note_root) return flat.c_str();
        if (sharp[0] == note_root) return sharp.c_str();
        return nullptr;
    }

    inline std::string str(const char note_root){
        if ( root[0] == note_root) return root;
        if ( flat[0] == note_root) return flat;
        if (sharp[0] == note_root) return sharp;
        return nullptr;
    }
};


class Scale {
    std::vector<int> steps;
public:
    const std::string Name;
};


#endif /* Types_h */
