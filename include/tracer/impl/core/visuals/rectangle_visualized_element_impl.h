#ifndef INCLUDE_TRACER_IMPL_CORE_VISUALS_RECTANGLE_VISUALIZED_ELEMENT_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_VISUALS_RECTANGLE_VISUALIZED_ELEMENT_IMPL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of rectangle_visualized_element.h header file.

#include "tracer/core/visuals/rectangle_visualized_element.h"
#include "tracer/core/util/gl.h"

namespace tracer {
namespace core {

// Constructor
template<typename T>
RectangleVisualizedElement<T>::RectangleVisualizedElement(
    int x, int y, int width, int height, T data, core::Theme& theme)
    : VisualizedElement<T>(x, y, data, theme) {
  width_ = width;
  height_ = height;
}

// Render implementation for rectangle elements
template<typename T>
void RectangleVisualizedElement<T>::render() {
  core::util::gl::draw_rectangle(
    this->x_, this->y_,
    this->width_, this->height_,
    this->data_,
    this->current_state_.background_color,
    this->current_state_.font_color);
}

}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_VISUALS_RECTANGLE_VISUALIZED_ELEMENT_IMPL_H_
