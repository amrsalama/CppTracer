#ifndef INCLUDE_TRACER_IMPL_CORE_COLOR_H_
#define INCLUDE_TRACER_IMPL_CORE_COLOR_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of color.h header file.

#include "tracer/core/color.h"

namespace tracer {
namespace core {

Color::Color() {
  red_   = 0.0;
  green_ = 0.0;
  blue_  = 0.0;
  alpha_ = 0.0;
}

Color::Color(float red, float green, float blue, float alpha) {
  red_   = check_constraints(red);
  green_ = check_constraints(green);
  blue_  = check_constraints(blue);
  alpha_ = check_constraints(alpha);
}

Color::Color(int red, int green, int blue, int alpha) {
  red_   = check_constraints(red) / 255.0;
  green_ = check_constraints(green) / 255.0;
  blue_  = check_constraints(blue) / 255.0;
  alpha_ = check_constraints(alpha) / 255.0;
}


// Red channel getter/setter.
float Color::get_red() const        { return red_; }
void  Color::set_red(float value)   { red_ = check_constraints(value); }
void  Color::set_red(int value)     { red_ = check_constraints(value)/255.0; }

// Green channel getter/setter.
float Color::get_green() const      { return green_; }
void  Color::set_green(float value) { green_ = check_constraints(value); }
void  Color::set_green(int value)   { green_ = check_constraints(value)/255.0; }

// Blue channel getter/setter.
float Color::get_blue() const       { return blue_; }
void  Color::set_blue(float value)  { blue_ = check_constraints(value); }
void  Color::set_blue(int value)    { blue_ = check_constraints(value)/255.0; }

// Alpha channel getter/setter.
float Color::get_alpha() const      { return alpha_; }
void  Color::set_alpha(float value) { alpha_ = check_constraints(value); }
void  Color::set_alpha(int value)   { alpha_ = check_constraints(value)/255.0; }


float Color::check_constraints(float value) {
  if (value < 0.0) value = 0.0;
  else if (value > 1.0) value = 1.0;
  return value;
}

int Color::check_constraints(int value) {
  if (value < 0) value = 0;
  else if (value > 255) value = 255;
  return value;
}

}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_COLOR_H_
