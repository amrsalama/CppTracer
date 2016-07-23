#ifndef INCLUDE_TRACER_CORE_UTILITY_GL_H_
#define INCLUDE_TRACER_CORE_UTILITY_GL_H_

#include "tracer/core/color.h"

namespace tracer {
namespace core {
namespace utility {
namespace gl {

// Draw a rectangle with a specific x, w, width, height and the data to be
// visualized, and with optional background color, text color and padding.
// This is a useful utility to be used in many tracers (e.g. 1d array, ...).
template<typename T>
void draw_rectangle(float x,
                    float y,
                    float width,
                    float height,
                    const T& data,
                    const Color& background_color = Color(70, 70, 70),
                    const Color& font_color = Color(255, 255, 255),
                    int padding = 2);

}  // namespace gl
}  // namespace utility
}  // namespace core
}  // namespace tracer

// Defer definition in implementation file
#include "tracer/impl/core/utility/gl.ipp"

#endif  // INCLUDE_TRACER_CORE_UTILITY_GL_H_
