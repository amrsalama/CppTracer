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

  // Override update abstract method.
  // Update array tracer data, and visualize all changes happened to the array.
  //
  // Examples:
  //    update();
  //    update(0.5);
  void update();
  void update(float speed);

  // Override notify abstract methods.
  // Notify array element with the specified index,
  // which means to flash the element with a different color then
  // flash again to its previous color.
  // We can notify range of indices.
  //
  // Examples:
  //    notify(0);          notify index 0 with the defulat speed
  //    notify(0, 0.5);     notify index 0 for 0.5 second
  //    notify(0, 5);       notify range from 0 to 5 with default speed
  //    notify(0, 5, 0.5);  notify range from 0 to 5 for 0.5 second
  void notify(int index);
  void notify(int index, float speed);
  void notify(int index, double speed);
  void notify(int from_index, int to_index);
  void notify(int from_index, int to_index, float speed);

  // Override select abstract methods.
  // Select array element with the specified index,
  // which means to mark the element with a different color.
  // We can select range of indices.
  //
  // Examples:
  //    select(0);          select index 0 with the defulat speed
  //    select(0, 0.5);     select index 0 for 0.5 second
  //    select(0, 5);       select range from 0 to 5 with default speed
  //    select(0, 5, 0.5);  select range from 0 to 5 for 0.5 second
  void select(int index);
  void select(int index, float speed);
  void select(int index, double speed);
  void select(int from_index, int to_index);
  void select(int from_index, int to_index, float speed);

  // Override deselect abstract methods.
  // Deselect array element with the specified index,
  // which means to mark the element with its previous color.
  // We can deselect range of indices.
  // This is the opposite method to select,
  // so whenever you select an element you may want to deselect it agian.
  //
  // Examples:
  //    deselect(0);          dselect index 0 with the defulat speed
  //    deselect(0, 0.5);     dselect index 0 for 0.5 second
  //    deselect(0, 5);       dselect range from 0 to 5 with default speed
  //    deselect(0, 5, 0.5);  dselect range from 0 to 5 for 0.5 second
  void deselect(int index);
  void deselect(int index, float speed);
  void deselect(int index, double speed);
  void deselect(int from_index, int to_index);
  void deselect(int from_index, int to_index, float speed);

 private:
  const float kRectangleWidth, kRectangleHeight, kWindowPadding;
  T* array_ptr;               // pointer to the original array
  int size_;                  // array size
  std::vector<T> array_;      // copy of original array data
  std::vector<core::VisualizedElement> elements_;

  // Override render abstract method.
  void render(int index = -1);
};

}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/array_impl.h"

#endif  // INCLUDE_TRACER_ARRAY_H_
