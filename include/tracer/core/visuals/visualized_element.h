#ifndef INCLUDE_TRACER_CORE_VISUALS_VISUALIZED_ELEMENT_H_
#define INCLUDE_TRACER_CORE_VISUALS_VISUALIZED_ELEMENT_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Visualized element, each visualized element (rectangle, circle, ...)
// has properties like background color, font color, x, y ...

#include "tracer/core/theme.h"
#include "tracer/core/visuals/element_state.h"

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
  ElementStateType current_state_;
};

}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/visuals/visualized_element_impl.h"

#endif  // INCLUDE_TRACER_CORE_VISUALS_VISUALIZED_ELEMENT_H_
