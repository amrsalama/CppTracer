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
}


// Destructor
template<typename T, size_t RowSize, size_t ColumnSize>
MatrixTracer<T, RowSize, ColumnSize>::~MatrixTracer() {}

}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_MATRIX_IMPL_H_
