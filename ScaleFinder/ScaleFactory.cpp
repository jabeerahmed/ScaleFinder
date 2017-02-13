//
//  ScaleFactory.cpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed on 2/2/17.
//  Copyright © 2017 Me. All rights reserved.
//

#include "Data.hpp"
#include <stdio.h>
#include <map>
#include <string>
#include "ScaleFactory.hpp"
#include "NoteFactory.hpp"

Scale::Scale(const Note& root, const Interval& interval): pair<Note, Interval>(root, interval){

    _name = ScaleName(root, interval);
    _notes.push_back(root);
    int keynum = root.keyNumber();
    for (auto s : interval.steps()){
        keynum+=s;
        _notes.push_back(NoteFactory::FindNote(keynum));
    }
}


using namespace std;

class ScaleFactoryImpl {
    
    ScaleFactoryImpl(){
        for (Note note: AllNotes) {
            for (Interval interval : AllIntervals) {
                Scale s(note, interval);
                scales.insert(pair<string, Scale>(s.getName(), s));
            }
        }
    }
    
    static ScaleFactoryImpl* sScaleFactory;

    Scales scales;

public:
    
    static Scales* GetScales() {
        return &(GetInstance()->scales);
    }
    
    static ScaleFactoryImpl* GetInstance() {
        if (sScaleFactory == nullptr) sScaleFactory = new ScaleFactoryImpl();
        return sScaleFactory;
    }
    
};

Scale* ScaleFactory::GetScale(const std::string name){
    Scales* scales = ScaleFactoryImpl::GetScales();
    Scales::iterator it = scales->find(name);
    if (it != scales->end()) {
        Scale* scale = &(it->second);
        return scale;
    }
    else return nullptr;
}

Scale* ScaleFactory::GetScale(const Note& note, const Interval& interval){
    return GetScale(Scale::ScaleName(note, interval));
}

Scales* ScaleFactory::GetScales(){
    return ScaleFactoryImpl::GetScales();
}

ScaleFactoryImpl* ScaleFactoryImpl::sScaleFactory = nullptr;

