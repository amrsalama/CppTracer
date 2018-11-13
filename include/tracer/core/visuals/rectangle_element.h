#ifndef INCLUDE_TRACER_CORE_VISUALS_RECTANGLE_ELEMENT_H_
#define INCLUDE_TRACER_CORE_VISUALS_RECTANGLE_ELEMENT_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Rectangle visualized element

#include "tracer/core/visuals/element.h"   // parent class

namespace tracer {
namespace core {
namespace visuals {

template<typename T>
class RectangleElement : public Element<T> {
 public:
  RectangleElement(
    int x, int y, int width, int height, T data, const core::Theme& theme);

  // Override render abstract method.
  using Element<T>::render;    // avoid name hiding
  void render();

 private:
  int width_, height_;
};

}  // namespace visuals
}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/visuals/rectangle_element_impl.h"

#endif  // INCLUDE_TRACER_CORE_VISUALS_RECTANGLE_ELEMENT_H_
