#ifndef INCLUDE_TRACER_ARRAY_H_
#define INCLUDE_TRACER_ARRAY_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Array tracer, visualizes arrays and vectors,
// we can notify, select, deselect, update, ... any element in the array.

#include <string>
#include <vector>
#include "tracer/core/themes.h"
#include "tracer/core/tracer.h"

namespace tracer {

template<typename T>
class ArrayTracer : public core::Tracer {
 public:
  // ArrayTracer for normal array, must pass array size to tracer.
  // The speed is specified in seconds.
  //
  // Examples:
  //    int int_array[3] = {1, 2, 3};
  //    tracer::ArrayTracer<int> int_tracer(int_array, 3, 1, "Integer array");
  //
  //    char char_array[3] = {'A', 'B', 'C'};
  //    tracer::ArrayTracer<char> char_tracer(char_array, 3);
  ArrayTracer(T* array,
              int size,
              float speed = 0.5,
              const std::string& window_title = "Array tracer",
              const core::Theme& theme = DEFALUT_THEME);
  ~ArrayTracer();

  // Override update abstract methods.
  using Tracer::update;    // avoid name hiding
  void update(float speed);

  // Override notify abstract methods.
  using Tracer::notify;    // avoid name hiding
  void notify(int index, float speed);
  void notify(int from_index, int to_index);
  void notify(int from_index, int to_index, float speed);

  // Override select abstract methods.
  using Tracer::select;    // avoid name hiding
  void select(int index, float speed);
  void select(int from_index, int to_index);
  void select(int from_index, int to_index, float speed);

  // Override deselect abstract methods.
  using Tracer::deselect;  // avoid name hiding
  void deselect(int index, float speed);
  void deselect(int from_index, int to_index);
  void deselect(int from_index, int to_index, float speed);

 private:
  const float kRectangleWidth, kRectangleHeight, kWindowPadding;
  T* array_ptr;               // pointer to the original array
  int size_;                  // array size
  std::vector<T> array_;      // copy of original array data
  std::vector<core::VisualizedElement> elements_;

  // Override render abstract method.
  void render();
  void render(int index);
};

}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/array_impl.h"

#endif  // INCLUDE_TRACER_ARRAY_H_
