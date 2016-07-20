#ifndef INCLUDE_TRACER_UTILITY_GENERAL_H_
#define INCLUDE_TRACER_UTILITY_GENERAL_H_

#include <string>
#include <sstream>

namespace tracer {
namespace utility {
namespace general {

  template<typename T>
  inline std::string stringify(const T &data) {
      std::stringstream string_stream;
      std::string converted_data;

      string_stream << data;
      string_stream >> converted_data;
      return converted_data;
  }

}  // namespace general
}  // namespace utility
}  // namespace tracer

#endif  // INCLUDE_TRACER_UTILITY_GENERAL_H_
