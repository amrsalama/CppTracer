#ifndef INCLUDE_TRACER_IMPL_CORE_UTIL_GL_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_UTIL_GL_IMPL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of gl.h utility header file.

#include "tracer/core/util/gl.h"
#include <algorithm>
#include <string>
#include "GL/gl.h"
#include "GL/freeglut.h"
#include "tracer/core/util/color.h"
#include "tracer/core/util/general.h"

namespace tracer {
namespace core {
namespace util {
namespace gl {

template<typename T>
void DrawRectangle(float x,
                    float y,
                    float width,
                    float height,
                    const T& data,
                    const Color& background_color,
                    const Color& font_color,
                    int padding) {
    if (x < 0) x = 0;  // can't be less than 0
    if (y < 0) y = 0;  // can't be less than 0

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
    std::string text = util::general::Stringify(data);

    // Support tab '\t' character in strings.
    // Convert '\t' to 2 spaces.
    int index = 0;
    while (true) {
      index = text.find("\t", index);
      if (index == std::string::npos) break;
      text.replace(index, 1, "  ");
      index += 2;
    }

    // Support new line '\n' character in strings.
    int endl_count = std::count(text.begin(), text.end(), '\n');

    // Calculate maximum line width within the text.
    // Width here means number of characters.
    int max_line_width;
    if (endl_count > 0) {
      max_line_width = 0;
      int temp_line_width = 0;
      for (int i = 0; i < text.size(); i++) {
        if (text[i] == '\n') {
          max_line_width = std::max(max_line_width, temp_line_width);
          temp_line_width = 0;
          continue;
        }
        temp_line_width++;
      }
      max_line_width = std::max(max_line_width, temp_line_width);
    } else {
      max_line_width = text.size();
    }

    // Calculate the position of the text.
    int text_x_pos = x + ((width  - (9 * max_line_width)) / 2.0);    // Center
    int text_y_pos = y + ((height - 15 + (15 * endl_count)) / 2.0);  // Middle
    if (text_x_pos < 0) text_x_pos = 0;  // can't be less than 0
    if (text_y_pos < 0) text_y_pos = 0;  // can't be less than 0

    glRasterPos2f(text_x_pos, text_y_pos);
    for (int i = 0; i < text.size(); i++) {
      // Support '\n',
      // if the next char is '\n' move to the next line.
      if (text[i] == '\n') {
        text_y_pos -= 15;
        glRasterPos2f(text_x_pos, text_y_pos);
        continue;
      }

      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
    }
}

}  // namespace gl
}  // namespace util
}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_UTIL_GL_IMPL_H_
