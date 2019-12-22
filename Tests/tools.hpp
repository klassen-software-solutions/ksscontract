//
//  tools.hpp
//  unittest
//
//  Created by Steven W. Klassen on 2019-12-21.
//  Copyright © 2019 Klassen Software Solutions. All rights reserved.
//

#ifndef tools_hpp
#define tools_hpp

#include <functional>
#include <iostream>
#include <sstream>
#include <string>

#include "ksstest.hpp"

// "Borrowed" from kssio
void suppress(std::ostream& os, const std::function<void ()>& fn);

class ContractTestSuite : public kss::test::TestSuite, public kss::test::MustNotBeParallel {
public:
    ContractTestSuite(test_case_list_t fns) : kss::test::TestSuite("contract", fns) {}
};


#endif /* tools_hpp */
