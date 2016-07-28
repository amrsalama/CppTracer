#ifndef INCLUDE_TRACER_MATRIX_H_
#define INCLUDE_TRACER_MATRIX_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Matrix tracer, visualizes matrices,
// we can notify, select, deselect, update, ... any element in the matrix.

#include <string>
#include <vector>
#include <utility>
#include "tracer/core/themes.h"
#include "tracer/core/tracer.h"

namespace tracer {

template<typename T, size_t RowSize, size_t ColumnSize>
class MatrixTracer : public core::Tracer {
 public:
  MatrixTracer(T matrix[RowSize][ColumnSize],
              float speed = 0.5,
              const std::string& window_title = "Matrix tracer",
              const core::Theme& theme = DEFALUT_THEME);
  ~MatrixTracer();

  // Override update abstract methods.
  using Tracer::update;    // avoid name hiding
  void update(float speed) {}

  // Override notify abstract methods.
  using Tracer::notify;    // avoid name hiding
  void notify(int index, float speed) {}

  // Override select abstract methods.
  using Tracer::select;    // avoid name hiding
  void select(int index, float speed) {}

  // Override deselect abstract methods.
  using Tracer::deselect;  // avoid name hiding
  void deselect(int index, float speed) {}

 private:
  const float kRectangleWidth, kRectangleHeight, kWindowPadding;
  T (*matrix_ptr)[ColumnSize];      // pointer to the original matrix
  std::vector<T> matrix_;           // copy of original matrix data
  std::vector<core::VisualizedElement> elements_;

  // Override render abstract method.
  void render() {}
  void render(int index) {}
};

}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/matrix_impl.h"

#endif  // INCLUDE_TRACER_MATRIX_H_
