#ifndef INCLUDE_TRACER_CORE_VISUALIZED_ELEMENT_H_
#define INCLUDE_TRACER_CORE_VISUALIZED_ELEMENT_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Visualized elements

#include "tracer/core/color.h"

namespace tracer {
namespace core {

// Each visualized element (rectangle, circle, ...) has properties
// like background color, font color.
struct VisualizedElement {
  Color background_color, font_color;
  VisualizedElement(const Color& background, const Color& font)
    : background_color(background), font_color(font) {}
};

}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_CORE_VISUALIZED_ELEMENT_H_
