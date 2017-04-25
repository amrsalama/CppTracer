#ifndef INCLUDE_TRACER_IMPL_CORE_UTILS_COLOR_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_UTILS_COLOR_IMPL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of color.h header file.

#include "tracer/core/utils/color.h"
#include <cmath>
#include <string>

namespace tracer {
namespace core {
namespace utils {

Color::Color() {
  red_   = 0.0;
  green_ = 0.0;
  blue_  = 0.0;
  alpha_ = 0.0;
}

Color::Color(double red, double green, double blue, double alpha) {
  red_   = CheckConstraints(red);
  green_ = CheckConstraints(green);
  blue_  = CheckConstraints(blue);
  alpha_ = CheckConstraints(alpha);
}

Color::Color(int red, int green, int blue, int alpha) {
  red_   = CheckConstraints(red) / 255.0;
  green_ = CheckConstraints(green) / 255.0;
  blue_  = CheckConstraints(blue) / 255.0;
  alpha_ = CheckConstraints(alpha) / 255.0;
}

Color::Color(std::string value) {
  if (value[0] == '#')
    value.erase(0, 1);

  red_   = CheckConstraints(HexaToDecimal(value.substr(0, 2))) / 255.0;
  green_ = CheckConstraints(HexaToDecimal(value.substr(2, 2))) / 255.0;
  blue_  = CheckConstraints(HexaToDecimal(value.substr(4, 2))) / 255.0;
  if (value.length() > 6)
    alpha_ = CheckConstraints(HexaToDecimal(value.substr(6, 2))) / 255.0;
  else
    alpha_ = 1.0;
}


// Red channel getter/setter.
float Color::get_red() const         { return red_; }
void  Color::set_red(double value)   { red_ = CheckConstraints(value); }
void  Color::set_red(int value)      { red_ = CheckConstraints(value)/255.0; }

// Green channel getter/setter.
float Color::get_green() const       { return green_; }
void  Color::set_green(double value) { green_ = CheckConstraints(value); }
void  Color::set_green(int value)    { green_ = CheckConstraints(value)/255.0; }

// Blue channel getter/setter.
float Color::get_blue() const        { return blue_; }
void  Color::set_blue(double value)  { blue_ = CheckConstraints(value); }
void  Color::set_blue(int value)     { blue_ = CheckConstraints(value)/255.0; }

// Alpha channel getter/setter.
float Color::get_alpha() const       { return alpha_; }
void  Color::set_alpha(double value) { alpha_ = CheckConstraints(value); }
void  Color::set_alpha(int value)    { alpha_ = CheckConstraints(value)/255.0; }


float Color::CheckConstraints(double value) {
  if (value < 0.0) value = 0.0;
  else if (value > 1.0) value = 1.0;
  return value;
}

int Color::CheckConstraints(int value) {
  if (value < 0) value = 0;
  else if (value > 255) value = 255;
  return value;
}


int Color::HexaToDecimal(const std::string &hexa) {
  int int_value = 0, p16 = 1;
  for (int i = hexa.length() - 1; i >= 0; i--) {
    char c = hexa[i];  // char by char
    // Convert small letters to capital letters.
    if (c >= 'a' && c <= 'z')
      c -= ('a'-'A');

    int x;  // integer value of c
    // convert char(hexa) to integer(decimal).
    if (c >= 'A' && c <= 'F') {
      x = static_cast<int>(c-'A') + 10;
    } else {
      x = static_cast<int>(c-'0');
    }

    // ... + (_ * 16^2) + (_ * 16^1) + (_ * 16^0)
    int_value += (x * p16);
    p16 *= 16;
  }
  return int_value;
}

}  // namespace utils
}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_UTILS_COLOR_IMPL_H_
