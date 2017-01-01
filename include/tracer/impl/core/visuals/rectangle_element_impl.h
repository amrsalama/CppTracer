#ifndef INCLUDE_TRACER_IMPL_CORE_VISUALS_RECTANGLE_ELEMENT_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_VISUALS_RECTANGLE_ELEMENT_IMPL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of rectangle_element.h header file.

#include "tracer/core/visuals/rectangle_element.h"
#include "tracer/core/util/gl.h"

namespace tracer {
namespace core {
namespace visuals {

// Constructor
template<typename T>
RectangleElement<T>::RectangleElement(
    int x, int y, int width, int height, T data, core::Theme& theme)
    : Element<T>(x, y, data, theme) {
  width_ = width;
  height_ = height;
}

// Render implementation for rectangle elements
template<typename T>
void RectangleElement<T>::render() {
  core::util::gl::DrawRectangle(
    this->x_, this->y_,
    this->width_, this->height_,
    this->data_,
    this->theme_.getElementState(this->current_state_).background_color,
    this->theme_.getElementState(this->current_state_).font_color);
}

}  // namespace visuals
}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_VISUALS_RECTANGLE_ELEMENT_IMPL_H_
