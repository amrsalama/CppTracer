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
  (core::util::Color("#F5F5F5"),
   core::State(core::util::Color("#AAAAAA"), core::util::Color("#FFFFFF")),
   core::State(core::util::Color("#EF5B6E"), core::util::Color("#FFFFFF")),
   core::State(core::util::Color("#02A8F3"), core::util::Color("#FFFFFF")),
   core::State(core::util::Color("#40D47E"), core::util::Color("#FFFFFF")),
   core::State(core::util::Color("#18AC8F"), core::util::Color("#FFFFFF")));

// DarkTheme (@salama).
const core::Theme DARK_THEME
  (core::util::Color("#AAAAAA"),
   core::State(core::util::Color("#E6E6E6"), core::util::Color("#1E1E1E")),
   core::State(core::util::Color("#FFA0A0"), core::util::Color("#FFFFFF")),
   core::State(core::util::Color("#64C8FF"), core::util::Color("#FFFFFF")),
   core::State(core::util::Color("#32FF96"), core::util::Color("#FFFFFF")),
   core::State(core::util::Color("#00C864"), core::util::Color("#FFFFFF")));

const core::Theme& DEFALUT_THEME = LIGHT_THEME;

}  // namespace tracer

#endif  // INCLUDE_TRACER_CORE_THEMES_H_
