#ifndef INCLUDE_TRACER_CORE_VISUALS_VISUALIZED_ELEMENT_H_
#define INCLUDE_TRACER_CORE_VISUALS_VISUALIZED_ELEMENT_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Visualized element, each visualized element (rectangle, circle, ...)
// has properties like background color, font color, x, y ...

#include "tracer/core/themes.h"   // State

namespace tracer {
namespace core {

template<typename T>
class VisualizedElement {
 public:
  VisualizedElement(int x, int y, T data, core::Theme& theme);
  virtual void render() = 0;

 protected:
  T data_;
  int x_, y_;
  core::Theme &theme_;
  core::State current_state_;   // @TODO: better reference to state
};

}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/visuals/visualized_element_impl.h"

#endif  // INCLUDE_TRACER_CORE_VISUALS_VISUALIZED_ELEMENT_H_
