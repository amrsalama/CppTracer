#include <string>
#include "GL/gl.h"
#include "GL/freeglut.h"
#include "tracer/tracer.h"

namespace tracer {

// Initialization of the static shared variables among all tracers.
int Tracer::window_count_ = 0;
float Tracer::window_x_position_ = 100;
float Tracer::window_y_position_ = 100;

Tracer::Tracer(int argc,
               char** argv,
               float window_width,
               float window_height,
               const std::string& window_title) : kWindowMargin(50.0) {
  window_width_ = window_width;
  window_height_ = window_height;

  // Only call glutInit function first time the tracer is created,
  // this allows multiple tracers to be created with glut been
  // initalized only once.
  if (window_count_++ == 0)
    glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(window_width_, window_height_);
  glutInitWindowPosition(window_x_position_, window_y_position_);
  window_id_ = glutCreateWindow(window_title.c_str());

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, window_width_, 0, window_height_, 0, 1.0);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  // Increse the y-position by the window height + a constant margin,
  // this allows the multiple tracers to have consistent positions.
  // TODO(@salama): Find a better placement method.
  window_y_position_ += (window_height_ + kWindowMargin);
}

Tracer::~Tracer() {
  window_count_--;
  window_y_position_ -= (window_height_ + kWindowMargin);

  // Hide the current tracer window and exit glut
  // whenever there are no more tracers.
  glutSetWindow(window_id_);
  glutHideWindow();
  if (window_count_ == 0)
    glutExit();
}

}  // namespace tracer
