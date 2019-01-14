//
//  version.cpp
//  kssio
//
//  Copyright © 2018 Klassen Software Solutions. All rights reserved.
//  Licensing follows the MIT License.
//

#include "version.hpp"
#include "_license_internal.h"
#include "_version_internal.h"

using namespace std;

string kss::contract::version() noexcept {
    return versionText;
}

string kss::contract::license() noexcept {
    return licenseText;
}
