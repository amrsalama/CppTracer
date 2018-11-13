#ifndef INCLUDE_TRACER_IMPL_CORE_UTILS_COLOR_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_UTILS_COLOR_IMPL_H_

// Copyright © 2017.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of color.h header file.

#include "tracer/core/utils/color.h"
#include <cmath>
#include <string>
#include <stdexcept>

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
  red_   = normalize(red);
  green_ = normalize(green);
  blue_  = normalize(blue);
  alpha_ = normalize(alpha);
}

Color::Color(int red, int green, int blue, int alpha) {
  red_   = normalize(red);
  green_ = normalize(green);
  blue_  = normalize(blue);
  alpha_ = normalize(alpha);
}

Color::Color(const std::string &value) {
  int start_index = (value[0] == '#' ? 1 : 0);
  if (value.size() < (start_index + 6) || value.size() > (start_index + 8))
    throw std::invalid_argument("Invalid color format: " + value);

  red_   = normalize(value.substr(start_index + 0, 2));
  green_ = normalize(value.substr(start_index + 2, 2));
  blue_  = normalize(value.substr(start_index + 4, 2));
  if (value.length() > (start_index + 6)) {
    alpha_ = normalize(value.substr(start_index + 6, 2));
  } else {
    alpha_ = 1.0;
  }
}


// Red channel getter/setter.
float Color::get_red() const                   { return red_; }
void  Color::set_red(double value)             { red_ = normalize(value); }
void  Color::set_red(int value)                { red_ = normalize(value); }
void  Color::set_red(const std::string &value) { red_ = normalize(value); }

// Green channel getter/setter.
float Color::get_green() const                   { return green_; }
void  Color::set_green(double value)             { green_ = normalize(value); }
void  Color::set_green(int value)                { green_ = normalize(value); }
void  Color::set_green(const std::string &value) { green_ = normalize(value); }

// Blue channel getter/setter.
float Color::get_blue() const                   { return blue_; }
void  Color::set_blue(double value)             { blue_ = normalize(value); }
void  Color::set_blue(int value)                { blue_ = normalize(value); }
void  Color::set_blue(const std::string &value) { blue_ = normalize(value); }

// Alpha channel getter/setter.
float Color::get_alpha() const                   { return alpha_; }
void  Color::set_alpha(double value)             { alpha_ = normalize(value); }
void  Color::set_alpha(int value)                { alpha_ = normalize(value); }
void  Color::set_alpha(const std::string &value) { alpha_ = normalize(value); }


float Color::normalize(double value) {
  if (value < 0.0 || value > 1.0)
    throw std::invalid_argument("value should be between 0.0 and 1.0");
  return value;
}

float Color::normalize(int value) {
  if (value < 0 || value > 255)
    throw std::invalid_argument("value should be between 0 and 255");
  return value/255.0;
}

float Color::normalize(const std::string &value) {
  bool valid = true;

  // Value should has the length of 2 (example: FF)
  // or 3 if it starts with # (example: #FF)
  valid &= (value[0] == '#' ? (value.size() == 3) : (value.size() == 2));
  for (int i = (value[0] == '#' ? 1 : 0); valid && i < value.size(); i++) {
    char c = value[i];
    // Convert small letters to capital letters.
    if (c >= 'a' && c <= 'f')
      c -= ('a'-'A');
    valid &= (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F');
  }

  if (!valid)
    throw std::invalid_argument("value should be between 00 and FF");

  return HexaToDecimal(value)/255.0;
}

int Color::HexaToDecimal(const std::string &hexa) {
  int int_value = 0, power_of_16 = 1;
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
    int_value += (x * power_of_16);
    power_of_16 *= 16;
  }
  return int_value;
}

}  // namespace utils
}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_UTILS_COLOR_IMPL_H_
