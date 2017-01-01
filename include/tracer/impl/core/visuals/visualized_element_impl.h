#ifndef INCLUDE_TRACER_IMPL_CORE_VISUALS_VISUALIZED_ELEMENT_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_VISUALS_VISUALIZED_ELEMENT_IMPL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of visualized_element.h header file.

#include "tracer/core/visuals/visualized_element.h"
#include "tracer/core/visuals/element_state.h"

namespace tracer {
namespace core {

// Constructor
template<typename T>
VisualizedElement<T>::VisualizedElement(
    int x, int y, T data, core::Theme& theme) : theme_(theme) {
  x_ = x;
  y_ = y;
  data_ = data;
  current_state_ = kNormal;
}

}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_VISUALS_VISUALIZED_ELEMENT_IMPL_H_
