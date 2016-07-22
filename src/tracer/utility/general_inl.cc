#include "tracer/utility/general.h"  // definitions of general.h functions
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include "tracer/configure.h"        // defines OS_WINDOWS, etc.

#ifdef OS_WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace tracer {
namespace utility {
namespace general {

template<typename T>
inline std::string stringify(const T& data) {
    std::ostringstream string_stream;
    string_stream << data;
    return string_stream.str();
}

template<>
inline std::string stringify<bool>(const bool& data) {
  std::ostringstream string_stream;
  string_stream << std::boolalpha << data;
  return string_stream.str();
}

template<>
inline std::string stringify<double>(const double& data) {
  const int sigdigits = std::numeric_limits<double>::digits10;
  std::ostringstream string_stream;
  string_stream << std::setprecision(sigdigits) << data;
  return string_stream.str();
}

template<>
inline std::string stringify<float>(const float& data) {
  const int sigdigits = std::numeric_limits<float>::digits10;
  std::ostringstream string_stream;
  string_stream << std::setprecision(sigdigits) << data;
  return string_stream.str();
}

template<>
inline std::string stringify<long double>(const long double& data) {
  const int sigdigits = std::numeric_limits<long double>::digits10;
  std::ostringstream string_stream;
  string_stream << std::setprecision(sigdigits) << data;
  return string_stream.str();
}

inline void delay(float seconds) {
  #ifdef OS_WINDOWS
  int milisec = static_cast<int>(seconds * 1000);
  Sleep(milisec);
  #else
  int microsec = static_cast<int>(seconds * 1000000);
  usleep(microsec);
  #endif
}

}  // namespace general
}  // namespace utility
}  // namespace tracer
