#ifndef INCLUDE_TRACER_CORE_THEMES_H_
#define INCLUDE_TRACER_CORE_THEMES_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Themes file.

#include "tracer/core/color.h"

namespace tracer {
namespace core {

// Each visualized element (rectangle, circle, ...) has properties
// like background color, font color.
typedef struct VisualizedElement {
  Color background_color, font_color;
  VisualizedElement(const Color& background, const Color& font)
    : background_color(background), font_color(font) {}
} VE;

// Themes for tracer, we can define many themes (light, dark, ...) as we want.
struct Theme {
  Color tracer_background_color;
  VE normal, notified, selected, updated, updated2;  // theme states

  // Default constructor initializes all states with black.
  Theme()
    : normal(VE(Color(), Color())),
      notified(VE(Color(), Color())),
      selected(VE(Color(), Color())),
      updated(VE(Color(), Color())),
      updated2(VE(Color(), Color())) {}

  Theme(const Color& tracer_background,
        const VisualizedElement& normal_state,
        const VisualizedElement& notified_state,
        const VisualizedElement& selected_state,
        const VisualizedElement& updated_state,
        const VisualizedElement& updated2_state)
    : tracer_background_color(tracer_background),
      normal(normal_state),
      notified(notified_state),
      selected(selected_state),
      updated(updated_state),
      updated2(updated2_state) {}
};

}  // namespace core

// LightTheme (@salama).
const core::Theme LIGHT_THEME
  (core::Color(245, 245, 245),
   core::VE(core::Color(170, 170, 170), core::Color(255, 255, 255)),
   core::VE(core::Color(239,  91, 110), core::Color(255, 255, 255)),
   core::VE(core::Color(2,   168, 243), core::Color(255, 255, 255)),
   core::VE(core::Color(64,  212, 126), core::Color(255, 255, 255)),
   core::VE(core::Color(24,  172, 143), core::Color(255, 255, 255)));

// DarkTheme (@salama).
const core::Theme DARK_THEME
  (core::Color(170, 170, 170),
   core::VE(core::Color(230, 230, 230), core::Color(30, 30, 30)),
   core::VE(core::Color(255, 160, 160), core::Color(255, 255, 255)),
   core::VE(core::Color(100, 200, 255), core::Color(255, 255, 255)),
   core::VE(core::Color(50,  255, 150), core::Color(255, 255, 255)),
   core::VE(core::Color(0,   200, 100), core::Color(255, 255, 255)));

const core::Theme& DEFALUT_THEME = LIGHT_THEME;

}  // namespace tracer

#endif  // INCLUDE_TRACER_CORE_THEMES_H_
