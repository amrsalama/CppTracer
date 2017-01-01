#ifndef INCLUDE_TRACER_IMPL_CORE_THEME_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_THEME_IMPL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of theme.h header file.

#include "tracer/core/theme.h"
#include "tracer/core/util/color.h"
#include "tracer/core/visuals/element_state.h"

namespace tracer {
namespace core {

Theme::Theme() {
  tracer_background_color_ = util::Color();
  states_[kNormal]   = ElementState(util::Color(), util::Color());
  states_[kNotified] = ElementState(util::Color(), util::Color());
  states_[kSelected] = ElementState(util::Color(), util::Color());
  states_[kUpdated1] = ElementState(util::Color(), util::Color());
  states_[kUpdated2] = ElementState(util::Color(), util::Color());
}

Theme::Theme(const util::Color& tracer_background,
             const ElementState& normal_state,
             const ElementState& notified_state,
             const ElementState& selected_state,
             const ElementState& updated1_state,
             const ElementState& updated2_state) {
  tracer_background_color_ = tracer_background;
  states_[kNormal]   = normal_state;
  states_[kNotified] = notified_state;
  states_[kSelected] = selected_state;
  states_[kUpdated1] = updated1_state;
  states_[kUpdated2] = updated2_state;
}

util::Color Theme::getTracerBackgroundColor() {
  return tracer_background_color_;
}

ElementState Theme::getElementState(ElementStateType state) {
  return states_[state];
}

}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_THEME_IMPL_H_
