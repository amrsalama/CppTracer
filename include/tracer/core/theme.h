#ifndef INCLUDE_TRACER_CORE_THEME_H_
#define INCLUDE_TRACER_CORE_THEME_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Themes file.

#include <map>
#include "tracer/core/utils/color.h"
#include "tracer/core/visuals/element_state.h"

namespace tracer {
namespace core {

// Themes for tracer, we can define many themes (light, dark, ...) as we want.
class Theme {
 public:
  Theme();  // Default constructor initializes all states with black.
  Theme(const utils::Color& tracer_background,
        const visuals::ElementState& normal_state,
        const visuals::ElementState& notified_state,
        const visuals::ElementState& selected_state,
        const visuals::ElementState& updated1_state,
        const visuals::ElementState& updated2_state);

  inline utils::Color getTracerBackgroundColor();
  inline visuals::ElementState getElementState(visuals::ElementStateType state);

 private:
  utils::Color tracer_background_color_;
  std::map<visuals::ElementStateType, visuals::ElementState> states_;
};

}  // namespace core

// LightTheme (@salama).
const core::Theme LIGHT_THEME
  (core::utils::Color("#F5F5F5"),
   core::visuals::ElementState(core::utils::Color("#AAAAAA"), core::utils::Color("#FFFFFF")),
   core::visuals::ElementState(core::utils::Color("#EF5B6E"), core::utils::Color("#FFFFFF")),
   core::visuals::ElementState(core::utils::Color("#02A8F3"), core::utils::Color("#FFFFFF")),
   core::visuals::ElementState(core::utils::Color("#40D47E"), core::utils::Color("#FFFFFF")),
   core::visuals::ElementState(core::utils::Color("#18AC8F"), core::utils::Color("#FFFFFF")));

// DarkTheme (@salama).
const core::Theme DARK_THEME
  (core::utils::Color("#AAAAAA"),
   core::visuals::ElementState(core::utils::Color("#E6E6E6"), core::utils::Color("#1E1E1E")),
   core::visuals::ElementState(core::utils::Color("#FFA0A0"), core::utils::Color("#FFFFFF")),
   core::visuals::ElementState(core::utils::Color("#64C8FF"), core::utils::Color("#FFFFFF")),
   core::visuals::ElementState(core::utils::Color("#32FF96"), core::utils::Color("#FFFFFF")),
   core::visuals::ElementState(core::utils::Color("#00C864"), core::utils::Color("#FFFFFF")));

}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/theme_impl.h"

#endif  // INCLUDE_TRACER_CORE_THEME_H_
