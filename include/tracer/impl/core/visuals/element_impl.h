#ifndef INCLUDE_TRACER_IMPL_CORE_VISUALS_ELEMENT_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_VISUALS_ELEMENT_IMPL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of element.h header file.

#include "tracer/core/visuals/element.h"
#include "tracer/core/visuals/element_state.h"

namespace tracer {
namespace core {
namespace visuals {

// Constructor
template<typename T>
Element<T>::Element(
    int x, int y, T data, core::Theme& theme) : theme_(theme) {
  x_ = x;
  y_ = y;
  data_ = data;
  current_state_ = kNormal;
}

}  // namespace visuals
}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_VISUALS_ELEMENT_IMPL_H_
