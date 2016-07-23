#include "tracer/array.h"            // definitions of array.h functions
#include <string>
#include "GL/gl.h"
#include "GL/freeglut.h"
#include "tracer/color.h"
#include "tracer/utility/gl.h"
#include "utility/gl_inl.cc"

namespace tracer {

template<typename T>
int ArrayTracer<T>::render_index = -1;

template<typename T>
ArrayTracer<T>::ArrayTracer(T* array,
                            size_t size,
                            float speed,
                            std::string window_title)
    : kRectangleWidth(50.0), kRectangleHeight(50.0), kWindowPadding(15.0),
      Tracer(0,
             NULL,
             (size * 50.0) + (15.0 * 2),  // 50 for rect width, 15 for padding
             50.0 + (15.0 * 2),           // 50 for rect height, 15 for padding
             speed,
             window_title) {
  size_ = size;
  array_.resize(size);
  colors_.assign(size, Color(100, 200, 200));
  for (int i = 0; i < size; i++)
    array_[i] = array[i];

  flush(0.01);
}

template<typename T>
ArrayTracer<T>::~ArrayTracer() {}

template<typename T>
void ArrayTracer<T>::render() {
  float beginning_x = kWindowPadding;
  if (render_index < 0) {
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < size_; i++) {
        utility::gl::draw_rectangle((beginning_x + i*kRectangleWidth),
                                    (window_height_/2.0 - kRectangleHeight/2.0),
                                    kRectangleWidth,
                                    kRectangleHeight,
                                    array_[i],
                                    colors_[i]);
    }
  } else {
    utility::gl::draw_rectangle((beginning_x + render_index*kRectangleWidth),
                                (window_height_/2.0 - kRectangleHeight/2.0),
                                kRectangleWidth,
                                kRectangleHeight,
                                array_[render_index],
                                colors_[render_index]);
  }

  glFlush();
}

}  // namespace tracer
