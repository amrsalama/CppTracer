#ifndef INCLUDE_TRACER_CORE_VISUALS_RECTANGLE_VISUALIZED_ELEMENT_H_
#define INCLUDE_TRACER_CORE_VISUALS_RECTANGLE_VISUALIZED_ELEMENT_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Rectangle visualized element

#include "tracer/core/visuals/visualized_element.h"   // parent class

namespace tracer {
namespace core {

template<typename T>
class RectangleVisualizedElement : public core::VisualizedElement<T> {
 public:
  RectangleVisualizedElement(
    int x, int y, int width, int height, T data, core::Theme& theme);

  // Override render abstract method.
  using VisualizedElement<T>::render;    // avoid name hiding
  void render();

 private:
  int width_, height_;
};

}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/visuals/rectangle_visualized_element_impl.h"

#endif  // INCLUDE_TRACER_CORE_VISUALS_RECTANGLE_VISUALIZED_ELEMENT_H_
