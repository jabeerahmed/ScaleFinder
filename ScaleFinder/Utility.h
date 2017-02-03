//
//  Utility.h
//  ScaleFinder
//
//  Created by Jabeer Ahmed (Intel) on 2/1/17.
//  Copyright © 2017 Me. All rights reserved.
//

#ifndef Utility_h
#define Utility_h

#include <string>
#include <sstream>

namespace Util {
    
    template<typename T>
    std::string add_str(const std::string a, const T& b){
        std::stringstream ss(a);
        ss << b;
        return ss.str();
    }
}

#endif /* Utility_h */
