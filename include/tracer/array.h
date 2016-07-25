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
#include "tracer/core/color.h"
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
              size_t size,
              float speed = 0.5,
              std::string window_title = "Array tracer",
              core::Theme theme = DEFALUT_THEME);
  ~ArrayTracer();

  // Override update abstract method.
  // Update array tracer data, and visualize all changes happened to the array.
  //
  // Examples:
  //    update();
  //    update(0.5);
  void update(float speed = -1);

  // Override notify abstract method.
  // Notify array element with the specified index,
  // which means to flash the element with a different color then
  // flash again to its previous color.
  //
  // Examples:
  //    notify(0);
  //    notify(0, 0.5);
  void notify(size_t index, float speed = -1);

  // Override select abstract method.
  // Select array element with the specified index,
  // which means to mark the element with a different color.
  //
  // Examples:
  //    select(0);
  //    select(0, 0.5);
  void select(size_t index, float speed = -1);

  // Override deselect abstract method.
  // Deselect array element with the specified index,
  // which means to mark the element with its previous color.
  // This is the opposite method to select,
  // so whenever you select an element you may want to deselect it agian.
  //
  // Examples:
  //    deselect(0);
  //    deselect(0, 0.5);
  void deselect(size_t index, float speed = -1);

 private:
  const float kRectangleWidth, kRectangleHeight, kWindowPadding;
  T* array_ptr;
  int size_;
  std::vector<T> array_;
  std::vector<core::VisualizedElement> elements_;
  core::Theme theme_;

  // Override render abstract method.
  void render(int index = -1);
};

}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/array.h"

#endif  // INCLUDE_TRACER_ARRAY_H_
