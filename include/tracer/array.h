#ifndef INCLUDE_TRACER_ARRAY_H_
#define INCLUDE_TRACER_ARRAY_H_

#include <string>
#include <vector>
#include "tracer/core/color.h"
#include "tracer/core/tracer.h"

namespace tracer {

template<typename T>
class ArrayTracer : public core::Tracer {
 public:
  ArrayTracer(T* array,
              size_t size,
              float speed = 0.5,
              std::string window_title = "Array tracer");
  ~ArrayTracer();
  void render();
  void notify(size_t index, float speed = -1);
  void select(size_t index, float speed = -1);
  void deselect(size_t index, float speed = -1);

 private:
  const float kRectangleWidth, kRectangleHeight, kWindowPadding;
  int size_;
  std::vector<T> array_;
  std::vector<core::Color> colors_;

  // index of the array element to be rendered,
  // negative value means render all the array.
  static int render_index;
};

}  // namespace tracer

// Defer definition in implementation file
#include "tracer/impl/array.ipp"

#endif  // INCLUDE_TRACER_ARRAY_H_