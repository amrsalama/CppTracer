#ifndef INCLUDE_TRACER_CORE_UTILS_COLOR_H_
#define INCLUDE_TRACER_CORE_UTILS_COLOR_H_

// Copyright © 2017.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Color datatype, supports RGBA values.
// Saves red/green/blue/alpha values as floats to use them with freeglut.

#include <string>

namespace tracer {
namespace core {
namespace utils {

class Color {
 public:
  // Default constructor, black color.
  Color();

  // Constructor for floating-point values,
  // each channel (red, green, ...) should
  // have a floating-point value from 0.0 to 1.0
  Color(double red, double green, double blue, double alpha = 1.0);

  // Constructor for integer values,
  // each channel (red, green, ...) should
  // have an integer value from 0 to 255
  Color(int red, int green, int blue, int alpha = 255);

  // Constructor for hexa values as string.
  // Hexa value from "#00000000" to "#FFFFFFFF".
  // Possible value examples: #336699, #336699FF, 336699, 336699FF
  explicit Color(const std::string &value);

  // Red channel getter/setter.
  inline float get_red() const;
  inline void set_red(double value);              // value range (0.0 to 1.0)
  inline void set_red(int value);                 // value range (0 to 255)
  inline void set_red(const std::string &value);  // value range (00 to FF)

  // Green channel getter/setter.
  inline float get_green() const;
  inline void set_green(double value);              // value range (0.0 to 1.0)
  inline void set_green(int value);                 // value range (0 to 255)
  inline void set_green(const std::string &value);  // value range (00 to FF)

  // Blue channel getter/setter.
  inline float get_blue() const;
  inline void set_blue(double value);              // value range (0.0 to 1.0)
  inline void set_blue(int value);                 // value range (0 to 255)
  inline void set_blue(const std::string &value);  // value range (00 to FF)

  // Alpha channel getter/setter.
  inline float get_alpha() const;
  inline void set_alpha(double value);              // value range (0.0 to 1.0)
  inline void set_alpha(int value);                 // value range (0 to 255)
  inline void set_alpha(const std::string &value);  // value range (00 to FF)

 private:
  float red_, green_, blue_, alpha_;

  // Convert value to floating-point number in range (0.0 to 1.0)
  float normalize(double value);
  float normalize(int value);
  float normalize(const std::string &value);

  // Converts haxadecimal values to decimals.
  //
  // Examples:
  //    HexaToDecimal("FF");     => 255
  //    HexaToDecimal("33");     => 51
  int HexaToDecimal(const std::string &hexa);
};

}  // namespace utils
}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/utils/color_impl.h"

#endif  // INCLUDE_TRACER_CORE_UTILS_COLOR_H_
