#ifndef INCLUDE_TRACER_IMPL_ARRAY_H_
#define INCLUDE_TRACER_IMPL_ARRAY_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of array.h tracer header file.

#include <string>
#include "GL/gl.h"
#include "GL/freeglut.h"
#include "tracer/core/color.h"
#include "tracer/core/utility/gl.h"

namespace tracer {

// Initialization of static variables.
template<typename T>
int ArrayTracer<T>::render_index = -1;

// Constructor
template<typename T>
ArrayTracer<T>
::ArrayTracer(T* array, size_t size, float speed, std::string window_title)
    : kRectangleWidth(50.0), kRectangleHeight(50.0), kWindowPadding(15.0),
      Tracer(0,     // argc
             NULL,  // argv
             (50.0 * size) + (15.0 * 2),  // 50 for rect width,  15 for padding
             (50.0)        + (15.0 * 2),  // 50 for rect height, 15 for padding
             speed,
             window_title) {
  size_ = size;
  array_.resize(size);
  colors_.assign(size, core::Color(100, 200, 200));  // default rect color
  for (int i = 0; i < size; i++)
    array_[i] = array[i];

  // Display the tracer and wait for 0.2 second.
  flush(0.2);
}

// Destructor
template<typename T>
ArrayTracer<T>::~ArrayTracer() {}

// Overloaded render method
template<typename T>
void ArrayTracer<T>::render() {
  float beginning_x = kWindowPadding;

  if (render_index < 0) {            // render all the array
    glClear(GL_COLOR_BUFFER_BIT);    // clear color buffer
    for (int i = 0; i < size_; i++) {
      core::utility::gl
      ::draw_rectangle((beginning_x + i*kRectangleWidth),
                       (window_height_/2.0 - kRectangleHeight/2.0),
                       kRectangleWidth, kRectangleHeight,
                       array_[i], colors_[i]);
    }
  } else {
    core::utility::gl
    ::draw_rectangle((beginning_x + render_index*kRectangleWidth),
                     (window_height_/2.0 - kRectangleHeight/2.0),
                     kRectangleWidth, kRectangleHeight,
                     array_[render_index], colors_[render_index]);
  }

  glFlush();
}

// Notify visualization method
template<typename T>
void ArrayTracer<T>::notify(size_t index, float speed) {
  speed = (speed > 0 ? speed : speed_);

  // Set the current render index to the element index.
  render_index = index;

  // Flash the element with a different color.
  colors_[index].set_red(255);
  flush(speed);

  // Flash again to its previous color.
  colors_[index].set_red(100);
  flush(speed);

  // Reset render index.
  render_index = -1;
}

// Select visualization method
template<typename T>
void ArrayTracer<T>::select(size_t index, float speed) {
  speed = (speed > 0 ? speed : speed_);

  // Set the current render index to the element index.
  render_index = index;

  // Mark the element with a different color.
  colors_[index].set_blue(255);
  flush(speed);

  // Reset render index.
  render_index = -1;
}

// Deselect visualization method
template<typename T>
void ArrayTracer<T>::deselect(size_t index, float speed) {
  speed = (speed > 0 ? speed : speed_);

  // Set the current render index to the element index.
  render_index = index;

  // Mark the element with its previous color.
  colors_[index].set_blue(200);
  flush(speed);

  // Reset render index.
  render_index = -1;
}

}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_ARRAY_H_
