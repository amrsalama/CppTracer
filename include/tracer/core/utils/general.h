#ifndef INCLUDE_TRACER_CORE_UTILS_GENERAL_H_
#define INCLUDE_TRACER_CORE_UTILS_GENERAL_H_

// Copyright © 2017.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// General core utilities for the whole library.

#include <string>

namespace tracer {
namespace core {
namespace utils {
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
//    Stringify('A');      => "A"
//    Stringify(true);     => "true"
//    Stringify(123.456);  => "123.456"
template<typename T> inline std::string Stringify(const T& data);
template<> inline std::string Stringify<bool>(const bool& data);
template<> inline std::string Stringify<double>(const double& data);
template<> inline std::string Stringify<float>(const float& data);
template<> inline std::string Stringify<long double>(const long double& data);  // NOLINT

// Delay for a specific amount of time (in seconds).
// Helps in control the speed of visualization.
//
// Examples:
//    Delay(0.5);
inline void Delay(float seconds);

}  // namespace general
}  // namespace utils
}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/utils/general_impl.h"

#endif  // INCLUDE_TRACER_CORE_UTILS_GENERAL_H_
