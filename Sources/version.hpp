//
//  version.hpp
//  ksscontract
//
//  Copyright © 2018 Klassen Software Solutions. All rights reserved.
//  Licensing follows the MIT License.
//

#ifndef kssio_version_hpp
#define kssio_version_hpp

#include <string>

namespace kss::contract {

    /*!
     Returns a string of the form x.y.z<optional tags> that describes the version
     of this library.
     */
    [[nodiscard]] std::string version() noexcept;

    /*!
     Returns the text of the software license.
     */
    [[nodiscard]] std::string license() noexcept;

}

#endif /* version_hpp */
