#ifndef INCLUDE_TRACER_CORE_UTIL_COLOR_H_
#define INCLUDE_TRACER_CORE_UTIL_COLOR_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Color datatype, supports RGBA values.
// Saves red/green/blue/alpha values as floats to use them with freeglut.

#include <string>

namespace tracer {
namespace core {
namespace util {

class Color {
 public:
  // Default constructor, black color.
  Color();

  // Constructor for floating-point values,
  // each channel (red, green, ...) should
  // have a floating-point value from 0.0 to 1.0
  Color(float red, float green, float blue, float alpha = 1.0);

  // Constructor for integer values,
  // each channel (red, green, ...) should
  // have an integer value from 0 to 255
  Color(int red, int green, int blue, int alpha = 255);

  // Constructor for hexa values as string.
  // Hexa value from "#00000000" to "#FFFFFFFF".
  // Possible values examples: #336699, #336699FF, 336699, 336699FF
  explicit Color(std::string value);

  // Red channel getter/setter.
  inline float get_red() const;
  inline void set_red(float value);    // Setting value from 0.0 to 1.0
  inline void set_red(int value);      // Setting value from 0 to 255

  // Green channel getter/setter.
  inline float get_green() const;
  inline void set_green(float value);  // Setting value from 0.0 to 1.0
  inline void set_green(int value);    // Setting value from 0 to 255

  // Blue channel getter/setter.
  inline float get_blue() const;
  inline void set_blue(float value);   // Setting value from 0.0 to 1.0
  inline void set_blue(int value);     // Setting value from 0 to 255

  // Alpha channel getter/setter.
  inline float get_alpha() const;
  inline void set_alpha(float value);  // Setting value from 0.0 to 1.0
  inline void set_alpha(int value);    // Setting value from 0 to 255

 private:
  float red_, green_, blue_, alpha_;

  // Check if value is between 0.0 and 1.0,
  // if not try to return the best possible value.
  //
  // Examples:
  //    CheckConstraints(0.5);     => 0.5
  //    CheckConstraints(2.1);     => 1.0
  //    CheckConstraints(-0.5);    => 0.0
  inline float CheckConstraints(float value);

  // Check if value is between 0 and 255,
  // if not try to return the best possible value.
  //
  // Examples:
  //    CheckConstraints(127);    => 127
  //    CheckConstraints(210);    => 255
  //    CheckConstraints(-50);    => 0
  inline int CheckConstraints(int value);

  // Converts haxadecimal values to decimals.
  //
  // Examples:
  //    HexaToDecimal("FF");     => 255
  //    HexaToDecimal("33");     => 51
  int HexaToDecimal(const std::string &hexa);
};

}  // namespace util
}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/util/color_impl.h"

#endif  // INCLUDE_TRACER_CORE_UTIL_COLOR_H_
