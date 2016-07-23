#ifndef INCLUDE_TRACER_CORE_UTILITY_GENERAL_H_
#define INCLUDE_TRACER_CORE_UTILITY_GENERAL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// General core utilities for the whole library.

#include <string>

namespace tracer {
namespace core {
namespace utility {
namespace general {

// Converts different data types to string to visualize them.
// Great example from "isocpp.org",
// REF: https://isocpp.org/wiki/faq/templates#template-specialization-example
//
// Template specialization for bool type,
// convert bool to "true" and "false" over "1" and "0".
//
// Template specialization for floating-point types,
// the floating-point output contains all possible digits.
//
// Examples:
//    stringify('A');      => "A"
//    stringify(true);     => "true"
//    stringify(123.456);  => "123.456"
template<typename T> inline std::string stringify(const T& data);
template<> inline std::string stringify<bool>(const bool& data);
template<> inline std::string stringify<double>(const double& data);
template<> inline std::string stringify<float>(const float& data);
template<> inline std::string stringify<long double>(const long double& data);

// Delay for a specific amount of time (in seconds).
// Helps in control the speed of visualization.
//
// Examples:
//    delay(0.5);
inline void delay(float seconds);

}  // namespace general
}  // namespace utility
}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/utility/general.ipp"

#endif  // INCLUDE_TRACER_CORE_UTILITY_GENERAL_H_
