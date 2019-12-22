//
//  invariant.cpp
//  unittest
//
//  Created by Steven W. Klassen on 2019-12-21.
//  Copyright © 2019 Klassen Software Solutions. All rights reserved.
//

#include <string>
#include <kss/contract/invariant.hpp>
#include "ksstest.hpp"
#include "tools.hpp"

using namespace std;
using namespace kss::test;
namespace contract = kss::contract;

#define HI(t) (t, contract::_private::Expression())

static ContractTestSuite ts({
    make_pair("passing", [] {
        string t = "hi";
        contract::Invariant<string> inv(t, KSS_EXPR(false));
    }),
    make_pair("failing", [] {
        suppress(cerr, [] {
            KSS_ASSERT(terminates([] {
                string t = "hi";
                contract::Invariant<string> inv(t, KSS_EXPR(false));
                t = "there";
            }));
        });
    })
});
