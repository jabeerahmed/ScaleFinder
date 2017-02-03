//
//  main.cpp
//  ScaleFinder
//
//  Created by Jabeer Ahmed (Intel) on 1/10/17.
//  Copyright © 2017 Me. All rights reserved.
//

#include <iostream>
#include "BasicTypes.hpp"
#include "NoteFactory.hpp"
#include "ScaleFactory.hpp"
#include "Data.hpp"
#include <queue>

using namespace std;

typedef pair<float, Scale*> ScaleMatch;
class ScaleMatchComp
{
public:
 
    bool operator() (const ScaleMatch& lhs, const ScaleMatch& rhs) const{
        return lhs.first < rhs.first;
    }
};


float calculateMatch(vector<Note> notes, Scale scale){
    float match = 0;
    
    vector<Note> scale_notes = scale.getNotes();
    
    for (Note note : notes){
        auto it = find(scale_notes.begin(), scale_notes.end(), note);
        if (it != scale_notes.end()) ++match;
    }
    
    return (match / scale_notes.size()) * 100;
}

void searchScales(vector<Note> notes){
    Scales* scales = ScaleFactory::GetScales();
    priority_queue<ScaleMatch, vector<ScaleMatch>, ScaleMatchComp> queue;
    
    for (Scales::iterator it = scales->begin(); it != scales->end(); it++){
        float match_score = calculateMatch(notes, it->second);
        queue.push(ScaleMatch(match_score, &(it->second)));
    }


    for (int i = 0; i < 50; i++){
        ScaleMatch s = queue.top();
        cout << " Scale = " << *(s.second) << " match = " << s.first << endl;
        queue.pop();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
//    std::cout << "Note - " << Cs << endl;
//    std::cout << "Scale -" << *(ScaleFactory::GetScale(F, Augmented)) << endl;

    searchScales(vector<Note>({Ass, C, Ds, E , G, As, B}));
    return 0;
}
