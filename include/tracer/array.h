#ifndef INCLUDE_TRACER_ARRAY_H_
#define INCLUDE_TRACER_ARRAY_H_

#include <string>
#include <vector>
#include "tracer/color.h"
#include "tracer/tracer.h"

namespace tracer {

template<typename T>
class ArrayTracer : public Tracer {
 public:
  ArrayTracer(T* array,
              size_t size,
              float speed = 0.5,
              std::string window_title = "Array tracer");
  ~ArrayTracer();
  void render();

 private:
  const float kRectangleWidth, kRectangleHeight, kWindowPadding;
  int size_;
  std::vector<T> array_;
  std::vector<Color> colors_;

  // index of the array element to be rendered,
  // negative value means render all the array.
  static int render_index;
};

}  // namespace tracer

#endif  // INCLUDE_TRACER_ARRAY_H_
