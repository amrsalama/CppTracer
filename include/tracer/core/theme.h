#ifndef INCLUDE_TRACER_CORE_THEME_H_
#define INCLUDE_TRACER_CORE_THEME_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Themes file.

#include <map>
#include "tracer/core/util/color.h"
#include "tracer/core/visuals/element_state.h"

namespace tracer {
namespace core {

// Themes for tracer, we can define many themes (light, dark, ...) as we want.
class Theme {
 public:
  Theme();  // Default constructor initializes all states with black.
  Theme(const util::Color& tracer_background,
        const ElementState& normal_state,
        const ElementState& notified_state,
        const ElementState& selected_state,
        const ElementState& updated1_state,
        const ElementState& updated2_state);

  inline util::Color getTracerBackgroundColor();
  inline ElementState getElementState(ElementStateType state);

 private:
  util::Color tracer_background_color_;
  std::map<ElementStateType, ElementState> states_;
};

}  // namespace core

// LightTheme (@salama).
const core::Theme LIGHT_THEME
  (core::util::Color("#F5F5F5"),
   core::ElementState(core::util::Color("#AAAAAA"), core::util::Color("#FFFFFF")),
   core::ElementState(core::util::Color("#EF5B6E"), core::util::Color("#FFFFFF")),
   core::ElementState(core::util::Color("#02A8F3"), core::util::Color("#FFFFFF")),
   core::ElementState(core::util::Color("#40D47E"), core::util::Color("#FFFFFF")),
   core::ElementState(core::util::Color("#18AC8F"), core::util::Color("#FFFFFF")));

// DarkTheme (@salama).
const core::Theme DARK_THEME
  (core::util::Color("#AAAAAA"),
   core::ElementState(core::util::Color("#E6E6E6"), core::util::Color("#1E1E1E")),
   core::ElementState(core::util::Color("#FFA0A0"), core::util::Color("#FFFFFF")),
   core::ElementState(core::util::Color("#64C8FF"), core::util::Color("#FFFFFF")),
   core::ElementState(core::util::Color("#32FF96"), core::util::Color("#FFFFFF")),
   core::ElementState(core::util::Color("#00C864"), core::util::Color("#FFFFFF")));

const core::Theme& DEFALUT_THEME = LIGHT_THEME;

}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/theme_impl.h"

#endif  // INCLUDE_TRACER_CORE_THEME_H_
