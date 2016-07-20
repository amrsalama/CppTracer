#ifndef INCLUDE_TRACER_TRACER_H_
#define INCLUDE_TRACER_TRACER_H_

#include <string>
#include "GL/freeglut.h"
#include "GL/gl.h"

// The base tracer class
class Tracer {
 public:
  Tracer(int argc,                  // [argc, argv] are required
        char **argv,                // by glut libarary (glutInit).
        const float &window_width,
        const float &window_height,
        const std::string &window_title);
  ~Tracer();
 protected:
  float window_width_;
  float window_height_;
 private:
  const float kWindowMargin;        // Margin between tracers window.
  static int window_count_;         // The number of created tracers.
  static float window_x_position_;  // The x-position of the next tracer.
  static float window_y_position_;  // The y-position of the next tracer.
  int window_id_;
};

#endif  // INCLUDE_TRACER_TRACER_H_
