//
//  ScaleFactory.h
//  ScaleFinder
//
//  Created by Jabeer Ahmed on 2/1/17.
//  Copyright © 2017 Me. All rights reserved.
//

#ifndef ScaleFactory_h
#define ScaleFactory_h


#include "BasicTypes.hpp"
#include "NoteFactory.hpp"
#include <map>
#include <string>

typedef std::map<std::string, Scale> Scales;

namespace ScaleFactory {
    Scale* GetScale(const std::string name);
    Scale* GetScale(const Note& note, const Interval& interval);
    Scales* GetScales();
}

#endif /* ScaleFactory_h */
