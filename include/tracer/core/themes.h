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

struct State {
  Color background_color, font_color;
  State(const Color& background, const Color& font)
    : background_color(background), font_color(font) {}
};

// Themes for tracer, we can define many themes (light, dark, ...) as we want.
struct Theme {
  Color tracer_background_color;
  State normal, notified, selected, updated, updated2;  // states

  // Default constructor initializes all states with black.
  Theme()
    : normal(State(Color(), Color())),
      notified(State(Color(), Color())),
      selected(State(Color(), Color())),
      updated(State(Color(), Color())),
      updated2(State(Color(), Color())) {}

  Theme(const Color& tracer_background,
        const State& normal_state,
        const State& notified_state,
        const State& selected_state,
        const State& updated_state,
        const State& updated2_state)
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
   core::State(core::Color(170, 170, 170), core::Color(255, 255, 255)),
   core::State(core::Color(239,  91, 110), core::Color(255, 255, 255)),
   core::State(core::Color(2,   168, 243), core::Color(255, 255, 255)),
   core::State(core::Color(64,  212, 126), core::Color(255, 255, 255)),
   core::State(core::Color(24,  172, 143), core::Color(255, 255, 255)));

// DarkTheme (@salama).
const core::Theme DARK_THEME
  (core::Color(170, 170, 170),
   core::State(core::Color(230, 230, 230), core::Color(30, 30, 30)),
   core::State(core::Color(255, 160, 160), core::Color(255, 255, 255)),
   core::State(core::Color(100, 200, 255), core::Color(255, 255, 255)),
   core::State(core::Color(50,  255, 150), core::Color(255, 255, 255)),
   core::State(core::Color(0,   200, 100), core::Color(255, 255, 255)));

const core::Theme& DEFALUT_THEME = LIGHT_THEME;

}  // namespace tracer

#endif  // INCLUDE_TRACER_CORE_THEMES_H_
