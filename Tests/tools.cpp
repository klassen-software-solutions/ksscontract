//
//  tools.cpp
//  unittest
//
//  Created by Steven W. Klassen on 2019-12-21.
//  Copyright © 2019 Klassen Software Solutions. All rights reserved.
//

#include "tools.hpp"

using namespace std;

void suppress(ostream &os, const function<void ()>& fn) {
    os.flush();
    stringstream redirectStream;
    streambuf* oldbuf = os.rdbuf(redirectStream.rdbuf());
    fn();
    os.flush();
    os.rdbuf(oldbuf);
}
