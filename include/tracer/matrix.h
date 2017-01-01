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
#include "tracer/core/theme.h"
#include "tracer/core/tracer.h"

namespace tracer {

template<typename T, size_t RowSize, size_t ColumnSize>
class MatrixTracer : public core::Tracer {
 public:
  MatrixTracer(T (*matrix)[ColumnSize],
              float speed = 0.5,
              const std::string& window_title = "Matrix tracer",
              const core::Theme& theme = DEFALUT_THEME);
  ~MatrixTracer();

  // Override update abstract methods.
  using Tracer::update;    // avoid name hiding
  void update(float speed);

  // Override notify abstract methods.
  using Tracer::notify;    // avoid name hiding
  void notify(int index, float speed);
  void notify(int row_index, int column_index);
  void notify(int row_index, int column_index, float speed);

  // Override select abstract methods.
  using Tracer::select;    // avoid name hiding
  void select(int index, float speed);
  void select(int row_index, int column_index);
  void select(int row_index, int column_index, float speed);

  // Override deselect abstract methods.
  using Tracer::deselect;  // avoid name hiding
  void deselect(int index, float speed);
  void deselect(int row_index, int column_index);
  void deselect(int row_index, int column_index, float speed);

 private:
  const float kRectangleWidth, kRectangleHeight, kWindowPadding;
  T (*matrix_ptr)[ColumnSize];      // pointer to the original matrix
  std::vector<T> matrix_;           // copy of original matrix data
  std::vector<core::visuals::ElementState> elements_;

  // Override render abstract method.
  void render();
  void render(int index);

  // We use this to methods (flatten and reshape) to handle the idea
  // of flatten index instead of the real row index and column index of matrix.
  // Which means if we have a matrix of size 2x3, we will have a flatten array
  // of 6 elements instead.
  //
  // Examples:
  //    if we have matrix of size 4x8,
  //    flatten(0, 1);      => 1
  //    flatten(3, 5);      => 29
  inline int flatten(int row_index, int column_index);
  // Examples:
  //    if we have matrix of size 4x8,
  //    reshape(1);         => pair<int>(0, 1)
  //    reshape(29);        => pair<int>(3, 5)
  inline std::pair<int, int> reshape(int index);
};

}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/matrix_impl.h"

#endif  // INCLUDE_TRACER_MATRIX_H_
