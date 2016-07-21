#ifndef INCLUDE_TRACER_COLOR_H_
#define INCLUDE_TRACER_COLOR_H_

#include <stdio.h>

namespace tracer {

struct Color {
  float r, g, b, a;   // red, green, blue and alpha channels

  // Constructor for floating-point values,
  // each channel (red, green, ...) should
  // have a floating-point value from 0.0 to 1.0
  Color(const float &red,
        const float &green,
        const float &blue,
        const float &alpha = 1.0) : r(red), g(green), b(blue), a(alpha) {
    // Check red channel constraints
    if (r < 0.0) r = 0.0;
    else if (r > 1.0) r = 1.0;

    // Check green channel constraints
    if (g < 0.0) g = 0.0;
    else if (g > 1.0) g = 1.0;

    // Check blue channel constraints
    if (b < 0.0) b = 0.0;
    else if (b > 1.0) b = 1.0;

    // Check alpha channel constraints
    if (a < 0.0) a = 0.0;
    else if (a > 1.0) a = 1.0;
  }

  // Constructor for integer values,
  // each channel (red, green, ...) should
  // have an integer value from 0 to 255
  Color(const int &red,
        const int &green,
        const int &blue,
        const int &alpha = 255) : r(red/255.0),
                                  g(green/255.0),
                                  b(blue/255.0),
                                  a(alpha/255.0) {
    // Check red channel constraints
    if (r < 0) r = 0;
    else if (r > 255) r = 255;

    // Check green channel constraints
    if (g < 0) g = 0;
    else if (g > 255) g = 255;

    // Check blue channel constraints
    if (b < 0) b = 0;
    else if (b > 255) b = 255;

    // Check alpha channel constraints
    if (a < 0) a = 0;
    else if (a > 255) a = 255;
  }
};

}  // namespace tracer

#endif  // INCLUDE_TRACER_COLOR_H_
