#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

namespace tracer {
namespace utility {
namespace general {

// Converts data types to string to visualize them.
// Great example from "isocpp.org",
// LINK: https://isocpp.org/wiki/faq/templates#template-specialization-example
template<typename T>
inline std::string stringify(const T& data) {
    std::ostringstream string_stream;
    string_stream << data;
    return string_stream.str();
}

// Template specialization for bool type,
// convert bool to "true" and "false" over "1" and "0".
template<>
inline std::string stringify<bool>(const bool& data) {
  std::ostringstream string_stream;
  string_stream << std::boolalpha << data;
  return string_stream.str();
}

// Template specialization for double type,
// the floating point output contains all possible digits.
template<>
inline std::string stringify<double>(const double& data) {
  const int sigdigits = std::numeric_limits<double>::digits10;
  std::ostringstream string_stream;
  string_stream << std::setprecision(sigdigits) << data;
  return string_stream.str();
}

// Template specialization for float type,
// the floating point output contains all possible digits.
template<>
inline std::string stringify<float>(const float& data) {
  const int sigdigits = std::numeric_limits<float>::digits10;
  std::ostringstream string_stream;
  string_stream << std::setprecision(sigdigits) << data;
  return string_stream.str();
}

// Template specialization for long double type,
// the floating point output contains all possible digits.
template<>
inline std::string stringify<long double>(const long double& data) {
  const int sigdigits = std::numeric_limits<long double>::digits10;
  std::ostringstream string_stream;
  string_stream << std::setprecision(sigdigits) << data;
  return string_stream.str();
}

}  // namespace general
}  // namespace utility
}  // namespace tracer
