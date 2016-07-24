#ifndef INCLUDE_TRACER_IMPL_CORE_UTILITY_GL_H_
#define INCLUDE_TRACER_IMPL_CORE_UTILITY_GL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of gl.h utility header file.

#include <string>
#include "GL/gl.h"
#include "GL/freeglut.h"
#include "tracer/core/color.h"
#include "tracer/core/utility/general.h"

namespace tracer {
namespace core {
namespace utility {
namespace gl {

template<typename T>
void draw_rectangle(float x,
                    float y,
                    float width,
                    float height,
                    const T& data,
                    const Color& background_color = Color(70, 70, 70),
                    const Color& font_color = Color(255, 255, 255),
                    int padding = 2) {
    // Draw rectangle.
    glColor4f(background_color.get_red(),
              background_color.get_green(),
              background_color.get_blue(),
              background_color.get_alpha());
    glBegin(GL_POLYGON);
        glVertex2f(x + padding,         y + padding);           // lower left
        glVertex2f(x + padding,         y + height - padding);  // upper left
        glVertex2f(x + width - padding, y + height - padding);  // upper right
        glVertex2f(x + width - padding, y + padding);           // lower right
    glEnd();

    // Draw data.
    // The used font is GLUT_BITMAP_9_BY_15,
    // in which each character takes 9x15.
    glColor4f(font_color.get_red(),
              font_color.get_green(),
              font_color.get_blue(),
              font_color.get_alpha());
    std::string text = utility::general::stringify(data);
    glRasterPos2f(x + (width  / 2.0) - ((9 * text.size()) / 2.0),  // Center
                  y + (height / 2.0) - (15 / 2.0));                // Middle
    for (int i = 0; i < text.size(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
    }
}

}  // namespace gl
}  // namespace utility
}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_UTILITY_GL_H_
