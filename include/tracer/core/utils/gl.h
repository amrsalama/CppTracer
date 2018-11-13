#ifndef INCLUDE_TRACER_CORE_UTILS_GL_H_
#define INCLUDE_TRACER_CORE_UTILS_GL_H_

// Copyright © 2017.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// freeglut (OpenGL) core utilities for the whole library.
// In general, this utilities define the basic shapes drawing with some
// data visualization (e.g. rectangles, circles, arrows, ...).

#include "tracer/core/utils/color.h"

namespace tracer {
namespace core {
namespace utils {
namespace gl {

// Draw a rectangle with the specified x, w, width, height and the data to be
// visualized, and with optional background color, text color and padding.
// This is a useful utility to be used in many tracers (e.g. array, matrix, ...)
//
// Examples:
//    DrawRectangle(0, 0, 100, 100, 11, Color(255, 0, 0));
//    DrawRectangle(0, 0, 100, 100, 22, Color(255, 0, 0), Color(0, 0, 0));
//    DrawRectangle(0, 0, 100, 100, 33, Color(255, 0, 0), Color(0, 0, 0), 5);
template<typename T>
void DrawRectangle(int x, int y, int width, int height, const T& data,
                   const Color& background_color = Color("#000000"),
                   const Color& font_color = Color("#FFFFFF"),
                   int padding = 2);

}  // namespace gl
}  // namespace utils
}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/utils/gl_impl.h"

#endif  // INCLUDE_TRACER_CORE_UTILS_GL_H_
