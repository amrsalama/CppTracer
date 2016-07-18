#ifndef INCLUDE_TRACER_TRACER_H_
#define INCLUDE_TRACER_TRACER_H_

#include "GL/freeglut.h"
#include "GL/gl.h"

class Tracer {
 public:
  Tracer(int argc, char** argv, float window_width, float windw_height);
  ~Tracer();
};

#endif  // INCLUDE_TRACER_TRACER_H_
