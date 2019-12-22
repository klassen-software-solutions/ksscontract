//
//  rtti.cpp
//  kssio
//
//  Created by Steven W. Klassen on 2014-01-22.
//  Copyright (c) 2014 Klassen Software Solutions. All rights reserved.
//  Licensing follows the MIT License.
//

#include <stdexcept>
#include <cxxabi.h>
#include "invariant.hpp"

using namespace std;

string kss::contract::_private::demangle(const string& tname) {
    int status;
    char* val = abi::__cxa_demangle(tname.c_str(), 0, 0, &status);
    if (val == nullptr) {
        throw runtime_error("Failed to demangle '" + tname + "'");
    }
	return string(val);
}
