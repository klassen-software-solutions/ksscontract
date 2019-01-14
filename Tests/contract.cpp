//
//  contract.cpp
//  unittest
//
//  Created by Steven W. Klassen on 2019-01-13.
//  Copyright © 2019 Klassen Software Solutions. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <kss/contract/contract.hpp>
#include "ksstest.hpp"

using namespace std;
using namespace kss::test;
namespace contract = kss::contract;

namespace {
    // "Borrowed" from kssio.
    void suppress(ostream &os, const function<void ()>& fn) {
        os.flush();
        stringstream redirectStream;
        streambuf* oldbuf = os.rdbuf(redirectStream.rdbuf());
        fn();
        os.flush();
        os.rdbuf(oldbuf);
    }

    class ContractTestSuite : public TestSuite, public MustNotBeParallel {
    public:
        ContractTestSuite(test_case_list fns) : TestSuite("contract", fns) {}
    };
}

static ContractTestSuite ts({
    make_pair("passing", [](TestSuite&) {
        contract::parameters({ KSS_EXPR(true) });
        contract::preconditions({ KSS_EXPR(true) });
        contract::conditions({ KSS_EXPR(true) });
        contract::postconditions({ KSS_EXPR(true) });

        // Nothing to check except that we get here.
        KSS_ASSERT(true);
    }),
    make_pair("failing", [](TestSuite&) {
        suppress(cerr, [] {
            KSS_ASSERT(throwsException<invalid_argument>([]{
                contract::parameters({ KSS_EXPR(false) });
            }));
            KSS_ASSERT(terminates([]{
                contract::preconditions({ KSS_EXPR(false) });
            }));
            KSS_ASSERT(terminates([]{
                contract::conditions({ KSS_EXPR(false) });
            }));
            KSS_ASSERT(terminates([]{
                contract::postconditions({ KSS_EXPR(false) });
            }));
        });
    })
});
