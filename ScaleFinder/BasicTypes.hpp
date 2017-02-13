//
//  BasicTypes.hpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed on 1/11/17.
//  Copyright © 2017 Me. All rights reserved.
//

#pragma once

#ifndef BasicTypes_hpp
#define BasicTypes_hpp

#include <map>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>

class Note {
protected:
    const std::string _name;
    const int _keyNumber;
    static int __instance_id;
    const int id = ++__instance_id;

public:
    Note(std::string n_name, int n_keynumber):_name(n_name), _keyNumber(n_keynumber){}
    inline std::string name() const { return _name; }
    inline char root() const { return _name[0]; }
    inline int keyNumber() const { return _keyNumber; }
    
    friend bool operator<(const Note& rhs, const Note& lhs){
        return rhs._name.compare(lhs._name) < 0;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Note& note){
        os << note._name ;
        return os;
    }
    
    bool operator==(const Note& lhs){
        return _keyNumber == lhs.keyNumber();
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
    friend bool operator<(const Interval& rhs, const Interval& lhs) {
        return rhs._name.compare(lhs._name) < 0;
    }
    
private:
    std::string _name;
    std::vector<Step> _steps;
    static int __instance_id;
    const int id = ++__instance_id;
};


class Scale : private std::pair<Note, Interval> {
public:
    
    Scale(const Note& scale_root, const Interval& scale_interval);
    inline std::vector<Note> getNotes() const { return _notes; }
    inline Note getRoot() const { return this->first; }
    inline Interval getInterval() const { return this->second; }
    inline std::string getName() const { return _name; }
    
    static std::string ScaleName(const Note& note, const Interval& interval){
        return note.name() + " " + interval.name();;
    }
    
    friend bool operator<(const Scale& rhs, const Scale& lhs){
        return rhs._name.compare(lhs._name) < 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const Scale& scale){
        os << scale.getName() << ' ';
        os << '[';
        for (auto n : scale._notes) {
            os << n.name() << ' ';
        }
        os << ']';
        return os;
    }

private:

    static constexpr char __note_sequence[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B'};
    std::vector<Note> _notes;
    std::string _name;

    static int __instance_id;
    const int id = ++__instance_id;
};

#endif /* BasicTypes_hpp */
