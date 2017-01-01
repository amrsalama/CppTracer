#ifndef INCLUDE_TRACER_IMPL_CORE_THEME_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_THEME_IMPL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of theme.h header file.

#include "tracer/core/theme.h"
#include "tracer/core/utils/color.h"
#include "tracer/core/visuals/element_state.h"

namespace tracer {
namespace core {

Theme::Theme() {
  tracer_background_color_ = utils::Color();
  states_[visuals::kNormal]   = visuals::ElementState(utils::Color(), utils::Color());
  states_[visuals::kNotified] = visuals::ElementState(utils::Color(), utils::Color());
  states_[visuals::kSelected] = visuals::ElementState(utils::Color(), utils::Color());
  states_[visuals::kUpdated1] = visuals::ElementState(utils::Color(), utils::Color());
  states_[visuals::kUpdated2] = visuals::ElementState(utils::Color(), utils::Color());
}

Theme::Theme(const utils::Color& tracer_background,
             const visuals::ElementState& normal_state,
             const visuals::ElementState& notified_state,
             const visuals::ElementState& selected_state,
             const visuals::ElementState& updated1_state,
             const visuals::ElementState& updated2_state) {
  tracer_background_color_ = tracer_background;
  states_[visuals::kNormal]   = normal_state;
  states_[visuals::kNotified] = notified_state;
  states_[visuals::kSelected] = selected_state;
  states_[visuals::kUpdated1] = updated1_state;
  states_[visuals::kUpdated2] = updated2_state;
}

utils::Color Theme::getTracerBackgroundColor() {
  return tracer_background_color_;
}

visuals::ElementState Theme::getElementState(visuals::ElementStateType state) {
  return states_[state];
}

}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_THEME_IMPL_H_
