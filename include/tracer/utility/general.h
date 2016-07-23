#ifndef INCLUDE_TRACER_UTILITY_GENERAL_H_
#define INCLUDE_TRACER_UTILITY_GENERAL_H_

#include <string>

namespace tracer {
namespace utility {
namespace general {

// Converts data types to string to visualize them.
// Great example from "isocpp.org",
// LINK: https://isocpp.org/wiki/faq/templates#template-specialization-example
template<typename T> inline std::string stringify(const T& data);

// Template specialization for bool type,
// convert bool to "true" and "false" over "1" and "0".
template<> inline std::string stringify<bool>(const bool& data);

// Template specialization for floating point types,
// the floating point output contains all possible digits.
template<> inline std::string stringify<double>(const double& data);
template<> inline std::string stringify<float>(const float& data);
template<> inline std::string stringify<long double>(const long double& data);

// Delay with the specific amount of time (in seconds)
inline void delay(float seconds);

}  // namespace general
}  // namespace utility
}  // namespace tracer

// Defer definition in implementation file
#include "tracer/impl/utility/general.ipp"

#endif  // INCLUDE_TRACER_UTILITY_GENERAL_H_
