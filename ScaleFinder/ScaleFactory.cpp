//
//  ScaleFactory.cpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed (Intel) on 2/2/17.
//  Copyright © 2017 Me. All rights reserved.
//

#include <stdio.h>
#include "ScaleFactory.hpp"
#include "NoteFactory.hpp"

Scale::Scale(std::string scale_name, Note scale_root, Interval scale_interval):_interval(scale_interval), _name(scale_name), _root(scale_root){
    
    _notes.push_back(_root);
    int keynum = _root.keyNumber();
    for (auto s : _interval.steps()){
        keynum+=s;
        _notes.push_back(NoteFactory::FindNote(keynum));
    }
}
