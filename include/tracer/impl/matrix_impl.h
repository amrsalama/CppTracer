#ifndef INCLUDE_TRACER_IMPL_MATRIX_IMPL_H_
#define INCLUDE_TRACER_IMPL_MATRIX_IMPL_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of matrix.h tracer header file.

#include "tracer/matrix.h"
#include <string>
#include <vector>
#include <utility>    // std::pair
#include "GL/gl.h"
#include "GL/freeglut.h"
#include "tracer/core/themes.h"
#include "tracer/core/utility/gl.h"

namespace tracer {

// Constructor
template<typename T, size_t RowSize, size_t ColumnSize>
MatrixTracer<T, RowSize, ColumnSize>::
MatrixTracer(T (*matrix)[ColumnSize],
             float speed,
             const std::string& window_title,
             const core::Theme& theme)
    : kRectangleWidth(50.0), kRectangleHeight(50.0), kWindowPadding(15.0),
      Tracer(0,     // argc
             NULL,  // argv
             50.0*ColumnSize + 15.0*2,  // 50 for rect width,  15 for padding
             50.0*RowSize    + 15.0*2,  // 50 for rect height, 15 for padding
             speed,
             window_title,
             theme) {
  matrix_ptr = matrix;                  // save pointer to the original matrix

  // We use the flatten index instead of the real row index and column index.
  // Which means if we have matrix of size 2x3, we will have a flatten array
  // of 6 elements instead.
  // We use flatten and reshape methods to handle this idea.
  elements_.assign(RowSize * ColumnSize, theme.normal);
  matrix_.resize(RowSize * ColumnSize);
  for (int i = 0; i < RowSize; i++) {
    for (int j = 0; j < ColumnSize; j++) {
      matrix_[flatten(i, j)] = matrix[i][j];
    }
  }

  // Display the tracer and wait for 0.2 second.
  flush(0.2);
}


// Destructor
template<typename T, size_t RowSize, size_t ColumnSize>
MatrixTracer<T, RowSize, ColumnSize>::~MatrixTracer() {}


// Overloaded render method,
// Render all the array.
template<typename T, size_t RowSize, size_t ColumnSize>
void MatrixTracer<T, RowSize, ColumnSize>::render() {
  float beginning_x, beginning_y;
  beginning_x = kWindowPadding;
  beginning_y = window_height_ - kWindowPadding - kRectangleHeight;  // up-down

  glClear(GL_COLOR_BUFFER_BIT);    // clear color buffer
  for (int i = RowSize - 1; i >= 0; i--) {
    for (int j = 0; j < ColumnSize; j++) {
      core::utility::gl
      ::draw_rectangle((beginning_x + j * kRectangleWidth),
                       (beginning_y - i * kRectangleHeight),
                       kRectangleWidth,
                       kRectangleHeight,
                       matrix_[flatten(i, j)],
                       elements_[flatten(i, j)].background_color,
                       elements_[flatten(i, j)].font_color);
    }
  }
  glFlush();
}

template<typename T, size_t RowSize, size_t ColumnSize>
void MatrixTracer<T, RowSize, ColumnSize>::render(int index) {
  float beginning_x = kWindowPadding;
  float beginning_y = window_height_ - kWindowPadding - kRectangleHeight;

  std::pair<int, int> row_column = reshape(index);
  int row = row_column.first, column = row_column.second;

  core::utility::gl
  ::draw_rectangle((beginning_x + column * kRectangleWidth),
                   (beginning_y - row * kRectangleHeight),
                   kRectangleWidth,
                   kRectangleHeight,
                   matrix_[index],
                   elements_[index].background_color,
                   elements_[index].font_color);
  glFlush();
}


template<typename T, size_t RowSize, size_t ColumnSize>
int MatrixTracer<T, RowSize, ColumnSize>::
flatten(int row_index, int column_index) {
  return row_index * ColumnSize + column_index;
}

template<typename T, size_t RowSize, size_t ColumnSize>
std::pair<int, int> MatrixTracer<T, RowSize, ColumnSize>::
reshape(int index) {
  int row_index = index / ColumnSize;
  int column_index = index - (row_index * ColumnSize);
  return std::make_pair(row_index, column_index);
}

}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_MATRIX_IMPL_H_
