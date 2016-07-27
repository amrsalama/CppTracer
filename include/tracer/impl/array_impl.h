#ifndef INCLUDE_TRACER_IMPL_ARRAY_IMPL_H_
#define INCLUDE_TRACER_IMPL_ARRAY_IMPL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of array.h tracer header file.

#include "tracer/array.h"
#include <string>
#include <vector>
#include "GL/gl.h"
#include "GL/freeglut.h"
#include "tracer/core/themes.h"
#include "tracer/core/utility/gl.h"

namespace tracer {

// Constructor
template<typename T>
ArrayTracer<T>::ArrayTracer(T* array,
                            int size,
                            float speed,
                            const std::string& window_title,
                            const core::Theme& theme)
    : kRectangleWidth(50.0), kRectangleHeight(50.0), kWindowPadding(15.0),
      Tracer(0,     // argc
             NULL,  // argv
             (50.0 * size) + (15.0 * 2),  // 50 for rect width,  15 for padding
             (50.0)        + (15.0 * 2),  // 50 for rect height, 15 for padding
             speed,
             window_title,
             theme) {
  array_ptr = array;                      // save pointer to the original array
  size_ = size;
  array_.assign(array, array + size);
  elements_.assign(size, theme.normal);

  // Display the tracer and wait for 0.2 second.
  flush(0.2);
}


// Destructor
template<typename T>
ArrayTracer<T>::~ArrayTracer() {}


// Overloaded render method,
// Render all the array.
template<typename T>
void ArrayTracer<T>::render() {
  float beginning_x = kWindowPadding;
  glClear(GL_COLOR_BUFFER_BIT);    // clear color buffer
  for (int i = 0; i < size_; i++) {
    core::utility::gl
    ::draw_rectangle((beginning_x + i * kRectangleWidth),
                     (window_height_ / 2.0 - kRectangleHeight / 2.0),
                     kRectangleWidth,
                     kRectangleHeight,
                     array_[i],
                     elements_[i].background_color,
                     elements_[i].font_color);
  }
  glFlush();
}

template<typename T>
void ArrayTracer<T>::render(int index) {
  float beginning_x = kWindowPadding;
  core::utility::gl
  ::draw_rectangle((beginning_x + index * kRectangleWidth),
                   (window_height_ / 2.0 - kRectangleHeight / 2.0),
                   kRectangleWidth,
                   kRectangleHeight,
                   array_[index],
                   elements_[index].background_color,
                   elements_[index].font_color);
  glFlush();
}


// Update visualization method
template<typename T>
void ArrayTracer<T>::update(float speed) {
  // Get all changed elements indices.
  std::vector<int> changed_elements_indices;
  std::vector<core::VisualizedElement> current_styles;  // temps
  for (int i = 0; i < size_; i++) {
    if (array_[i] != array_ptr[i]) {
      changed_elements_indices.push_back(i);
      current_styles.push_back(elements_[i]);
    }
  }

  // If no changes happen just return.
  if (changed_elements_indices.empty())
    return;

  int index;
  // Update in 3 steps:
  // 1. Mark all changed elements with updated style.
  for (int i = 0; i < changed_elements_indices.size(); i++) {
    index = changed_elements_indices[i];
    elements_[index] = theme_.updated;
    flush(0.0, index);  // flush the element to screen, we don't need to wait
  }
  flush(speed / 3.0, index);

  // 2. Update array data.
  for (int i = 0; i < changed_elements_indices.size(); i++) {
    index = changed_elements_indices[i];
    elements_[index] = theme_.updated2;
    array_[index] = array_ptr[index];  // update array data
    flush(0.0, index);  // flush the element to screen, we don't need to wait
  }
  flush(speed / 3.0, index);

  // 3. Unmark all changed elements.
  for (int i = 0; i < changed_elements_indices.size(); i++) {
    index = changed_elements_indices[i];
    elements_[index] = current_styles[i];
    flush(0.0, index);  // flush the element to screen, we don't need to wait
  }
  flush(speed / 3.0, index);
}


// Notify visualization method
template<typename T>
void ArrayTracer<T>::notify(int index, float speed) {
  core::VisualizedElement current_style = elements_[index];  // temp

  // Flash the element notified style.
  elements_[index] = theme_.notified;
  flush(speed / 2.0, index);

  // Flash again to its previous style.
  elements_[index] = current_style;
  flush(speed / 2.0, index);
}

template<typename T>
void ArrayTracer<T>::notify(int from_index, int to_index) {
  notify(from_index, to_index, speed_);
}

template<typename T>
void ArrayTracer<T>::notify(int from_index, int to_index, float speed) {
  std::vector<core::VisualizedElement> current_styles;  // temps
  for (int i = from_index; i <= to_index; i++) {
    current_styles.push_back(elements_[i]);
    elements_[i] = theme_.notified;
    flush(0.0, i);
  }
  flush(speed / 2.0, to_index);

  for (int i = from_index, j = 0; i <= to_index; i++, j++) {
    elements_[i] = current_styles[j];
    flush(0.0, i);
  }
  flush(speed / 2.0, to_index);
}


// Select visualization methods
template<typename T>
void ArrayTracer<T>::select(int index, float speed) {
  elements_[index] = theme_.selected;
  flush(speed, index);
}

template<typename T>
void ArrayTracer<T>::select(int from_index, int to_index) {
  select(from_index, to_index, speed_);
}

template<typename T>
void ArrayTracer<T>::select(int from_index, int to_index, float speed) {
  for (int i = from_index; i <= to_index; i++) {
    elements_[i] = theme_.selected;
    flush(0.0, i);
  }
  flush(speed, to_index);
}


// Deselect visualization method
template<typename T>
void ArrayTracer<T>::deselect(int index, float speed) {
  elements_[index] = theme_.normal;
  flush(speed, index);
}

template<typename T>
void ArrayTracer<T>::deselect(int from_index, int to_index) {
  deselect(from_index, to_index, speed_);
}

template<typename T>
void ArrayTracer<T>::deselect(int from_index, int to_index, float speed) {
  for (int i = from_index; i <= to_index; i++) {
    elements_[i] = theme_.normal;
    flush(0.0, i);
  }
  flush(speed, to_index);
}

}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_ARRAY_IMPL_H_
