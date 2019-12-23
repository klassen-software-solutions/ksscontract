//
//  invariant.hpp
//  ksscontract
//
//  Created by Steven W. Klassen on 2019-12-21.
//  Copyright © 2019 Klassen Software Solutions. All rights reserved.
//  Licensing follows the MIT License.
//

#ifndef ksscontract_invariant_hpp
#define ksscontract_invariant_hpp

#include <functional>
#include <string>
#include <typeinfo>
#include <utility>

#include "contract.hpp"

namespace kss { namespace contract {

    namespace _private {
        // "Borrowed" from kssutil
        std::string demangle(const std::string& typeName);

        template <typename T>
        inline std::string name(const T& t = T()) {
            return demangle(typeid(t).name());
        }
    }

    /*!
     An invariant tracks the "value" of an object to check that it does not change within the scope
     of the invariant. Note that the "value" of the object is estimated using std::hash, hence for a
     custom class T you will need to define std::hash<T> in order to use an Invariant.

     If the object's hash has changed, the result will be equivalent to that of a failed postcondition.
     */
    template <class T>
    class Invariant {
    public:

        /*!
         To create an invariant, you must pass in a reference to the object that is being tracked, and
         the result of the KSS_EXPR(false) macro. This macro call is required in order to
         record the file and line numbers required for reporting if the invariant fails.

         Example:
         @code
         void myfn() {
            auto myobj = ...some object...;
            Invariant inv1(myobj, KSSEXPR(false));
            ... your function code...
         }
         @endcode
         */
        explicit Invariant(const T& t, _private::Expression&& expr) noexcept
        : _t(t), _expr(expr), _value(_hasher(t))
        {}

        ~Invariant() {
            _expr.result = (_hasher(_t) == _value);
            if (!_expr.result) {
                const auto name = _private::name(*this);
                _expr.expr = name.c_str();
                _private::performTerminatingCheck("Invariant", _expr);
            }
        }

        // Copying and moving are not allowed.
        Invariant(const Invariant&) = delete;
        Invariant(Invariant&&) = delete;
        Invariant& operator=(const Invariant&) = delete;
        Invariant& operator=(Invariant&&) = delete;

    private:
        const T&                _t;
        _private::Expression    _expr;
        std::hash<T>            _hasher;
        const size_t            _value;
    };
}}

#endif
