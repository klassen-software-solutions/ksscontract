# ksscontract
Tools to assist with "programming by contract"

## Prerequisites

This library has no prerequisites other than the standard C++ library.

## Description

This library contains items useful in coding based on 
[Design by Contract](https://en.wikipedia.org/wiki/Design_by_contract). Specifically it provides the ability
to add checks on parameters, preconditions, postconditions, and middle conditions in an expressive
manner.

[API Documentation](https://www.kss.cc/apis/ksscontract/docs/index.html) 

### To terminate or not to terminate?

A common debate in programming by contract is what action should be taken when a contract
condition fails. We have taken the opinion that the `parameters` failures will throw a
`std::invalid_argument` exception and all other condition failures will write an error message
to the standard error device, and then call `std::terminate()` to halt the program. (This is largely
following the advice of Ferguson, Schneier, and Kohno in their book _Cryptography Engineering_.
It was that book as well as Schneier's book _Click Here to Kill Everybody_ that were the primary
influencers in our decision to create this library.)

In addition we chose that the condition checks would always take place regardless of whether
your code is compiled in debug mode or production mode.

### Customizing the actions

The above decisions can be changed in two ways.

First of all, if you would like to only perform the checks in debug mode, you can bracket the calls
with `#if !defined(NDEBUG)` which will make them follow the same rules as the `assert`
macro. (In fact we do this for a few of our checks when we know they would adversely affect
the performance of the system, either because the particular condition is an expensive one
to check, or because it occurs in a portion of the code that is particulary time sensitive. But we
try to avoid this as the production code is the code that is most likely to be attacked, hence is
where the correctness checks are most important.)

However, if you want to change the action on when a condition fails, you will need to modify the
code in this library. In that case we recommend that you copy the files `contract.hpp` and
`contract.cpp` into your own library, change the namespace if you so desire, and then
modify the `performThrowingCheck` and the `performTerminatingCheck` to act as you
desire.

### Using this library

TODO: give some basic examples

## Contributing

If you wish to make changes to this library that you believe will be useful to others, you can
contribute to the project. If you do, there are a number of policies you should follow:

* Check the issues to see if there are already similar bug reports or enhancements.
* Feel free to add bug reports and enhancements at any time.
* Don't work on things that are not part of an approved project.
* Don't create projects - they are only created the by owner.
* Projects are created based on conversations on the wiki.
* Feel free to initiate or join conversations on the wiki.
* Follow our [C++ Coding Standards](https://www.kss.cc/standards/c-.html).
