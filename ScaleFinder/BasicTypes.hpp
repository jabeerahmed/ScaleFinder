//
//  BasicTypes.hpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed (Intel) on 1/11/17.
//  Copyright © 2017 Me. All rights reserved.
//

#pragma once

#ifndef BasicTypes_hpp
#define BasicTypes_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include "Utility.h"

class Note {
protected:
    const std::string _name;
    const int _keyNumber;
public:
    Note(std::string n_name, int n_keynumber):_name(n_name), _keyNumber(n_keynumber){}
    inline std::string name() const { return _name; }
    inline char root() const { return _name[0]; }
    inline int keyNumber() const { return _keyNumber; }
    
    friend std::ostream& operator<<(std::ostream& os, const Note& note){
        os << note._name ;
        return os;
    }
    
    static Note FindNote(unsigned int keyNumber);
    static std::vector<Note> findAllNotes(unsigned int keyNumber);
    static Note GetNote(const std::string note);
};



enum Step { Whole = 2, Half = 1};

class Interval {
public:
    
    Interval(const std::string interval_name, const std::vector<Step>& interval_steps): _name(interval_name), _steps(interval_steps){
        int i = 0;
        for (auto step : _steps) i+= step;

        if (i != 12) {
            std::stringstream ss;
            ss << "Error creating Interval with Name: " << interval_name << ". Expected total steps = 12, but got = " << i;
            std::cout << ss.str() << std::endl;
        }
    }
    inline std::vector<Step> steps() const { return _steps; }
    inline std::string name() const { return _name; }

private:
    std::vector<Step> _steps;
    std::string _name;
};


class Scale {
public:
    
    Scale(std::string scale_name, Note scale_root, Interval scale_interval);
    inline std::vector<Note> getNotes() const { return _notes; }
    
private:
    std::vector<Note> _notes;
    Interval _interval;
    std::string _name;
    Note _root;
};

#endif /* BasicTypes_hpp */
