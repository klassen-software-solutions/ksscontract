//
//  version.cpp
//  unittest
//
//  Copyright © 2018 Klassen Software Solutions. All rights reserved.
//  Licensing follows the MIT License.
//

#include <kss/contract/version.hpp>
#include "ksstest.hpp"

using namespace std;
using namespace kss::test;


static TestSuite ts("version", {
    make_pair("existance", [](TestSuite&) {
        KSS_ASSERT(!kss::contract::version().empty());
        KSS_ASSERT(!kss::contract::license().empty());
    })
});
