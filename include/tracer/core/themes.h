#ifndef INCLUDE_TRACER_CORE_THEMES_H_
#define INCLUDE_TRACER_CORE_THEMES_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Themes file.

#include "tracer/core/util/color.h"

namespace tracer {
namespace core {

struct State {
  util::Color background_color, font_color;
  State(const util::Color& background, const util::Color& font)
    : background_color(background), font_color(font) {}
};

// Themes for tracer, we can define many themes (light, dark, ...) as we want.
struct Theme {
  util::Color tracer_background_color;
  State normal, notified, selected, updated, updated2;  // states

  // Default constructor initializes all states with black.
  Theme()
    : normal(State(util::Color(), util::Color())),
      notified(State(util::Color(), util::Color())),
      selected(State(util::Color(), util::Color())),
      updated(State(util::Color(), util::Color())),
      updated2(State(util::Color(), util::Color())) {}

  Theme(const util::Color& tracer_background,
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
  (core::util::Color(245, 245, 245),
   core::State(core::util::Color(170, 170, 170),
               core::util::Color(255, 255, 255)),
   core::State(core::util::Color(239,  91, 110),
               core::util::Color(255, 255, 255)),
   core::State(core::util::Color(2,   168, 243),
               core::util::Color(255, 255, 255)),
   core::State(core::util::Color(64,  212, 126),
               core::util::Color(255, 255, 255)),
   core::State(core::util::Color(24,  172, 143),
               core::util::Color(255, 255, 255)));

// DarkTheme (@salama).
const core::Theme DARK_THEME
  (core::util::Color(170, 170, 170),
   core::State(core::util::Color(230, 230, 230),
               core::util::Color(30, 30, 30)),
   core::State(core::util::Color(255, 160, 160),
               core::util::Color(255, 255, 255)),
   core::State(core::util::Color(100, 200, 255),
               core::util::Color(255, 255, 255)),
   core::State(core::util::Color(50,  255, 150),
               core::util::Color(255, 255, 255)),
   core::State(core::util::Color(0,   200, 100),
               core::util::Color(255, 255, 255)));

const core::Theme& DEFALUT_THEME = LIGHT_THEME;

}  // namespace tracer

#endif  // INCLUDE_TRACER_CORE_THEMES_H_
