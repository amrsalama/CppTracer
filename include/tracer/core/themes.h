#ifndef INCLUDE_TRACER_CORE_THEMES_H_
#define INCLUDE_TRACER_CORE_THEMES_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Themes file

#include "tracer/core/color.h"

namespace tracer {
namespace core {

typedef struct VisualizedElement {
  Color background_color, font_color;
  VisualizedElement(Color background, Color font)
    : background_color(background), font_color(font) {}
} VE;

struct Theme {
  core::Color tracer_background_color;
  VisualizedElement normal, notified, selected, updated, updated2;
  Theme()
    : normal(VE(core::Color(0, 0, 0),   core::Color(0, 0, 0))),
      notified(VE(core::Color(0, 0, 0), core::Color(0, 0, 0))),
      selected(VE(core::Color(0, 0, 0), core::Color(0, 0, 0))),
      updated(VE(core::Color(0, 0, 0),  core::Color(0, 0, 0))),
      updated2(VE(core::Color(0, 0, 0), core::Color(0, 0, 0))) {}
  Theme(core::Color tracer_background,
        VisualizedElement normal_style,
        VisualizedElement notified_style,
        VisualizedElement selected_style,
        VisualizedElement updated_style,
        VisualizedElement updated2_style)
    : tracer_background_color(tracer_background),
      normal(normal_style),
      notified(notified_style),
      selected(selected_style),
      updated(updated_style),
      updated2(updated2_style) {}
};

}  // namespace core

const core::Theme DEFALUT_THEME
  (core::Color(245, 245, 245),
   core::VE(core::Color(230, 230, 230), core::Color(30, 30, 30)),
   core::VE(core::Color(255, 160, 160), core::Color(255, 255, 255)),
   core::VE(core::Color(100, 200, 255), core::Color(255, 255, 255)),
   core::VE(core::Color(50, 255, 150),  core::Color(255, 255, 255)),
   core::VE(core::Color(0, 200, 100),   core::Color(255, 255, 255)));

}  // namespace tracer

#endif  // INCLUDE_TRACER_CORE_THEMES_H_
