#ifndef INCLUDE_TRACER_CORE_VISUALS_ELEMENT_STATE_H_
#define INCLUDE_TRACER_CORE_VISUALS_ELEMENT_STATE_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Visualized elements states

#include "tracer/core/util/color.h"

namespace tracer {
namespace core {

enum ElementStateType {
  kNormal = 0,
  kNotified,
  kSelected,
  kUpdated1,
  kUpdated2,
};

struct ElementState {
  util::Color background_color, font_color;
  ElementState() {};
  ElementState(const util::Color& background, const util::Color& font)
    : background_color(background), font_color(font) {}
};

}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_CORE_VISUALS_ELEMENT_STATE_H_
