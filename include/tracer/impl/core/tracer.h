#ifndef INCLUDE_TRACER_IMPL_CORE_TRACER_H_
#define INCLUDE_TRACER_IMPL_CORE_TRACER_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// Implementation of tracer.h header file.

#include "tracer/core/tracer.h"
#include <string>
#include "GL/gl.h"
#include "GL/freeglut.h"
#include "tracer/core/utility/general.h"

namespace tracer {
namespace core {

// Initialization of the static shared variables among all tracers.
int Tracer::window_count_ = 0;
float Tracer::window_x_position_ = 100;
float Tracer::window_y_position_ = 100;

// Constructor
Tracer::Tracer(int argc,
               char** argv,
               float window_width,
               float window_height,
               float speed,
               const std::string& window_title,
               const Color& window_background) : kWindowMargin(50.0) {
  window_width_ = window_width;
  window_height_ = window_height;
  speed_ = speed;

  // Only call glutInit function first time the tracer is created,
  // this allows multiple tracers to be created with glut been
  // initalized only once.
  if (window_count_++ == 0)
    glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(window_width_, window_height_);
  glutInitWindowPosition(window_x_position_, window_y_position_);
  window_id_ = glutCreateWindow(window_title.c_str());

  glClearColor(window_background.get_red(),
               window_background.get_green(),
               window_background.get_blue(),
               window_background.get_alpha());
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, window_width_, 0, window_height_, 0, 1.0);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Increse the y-position by the window height + constant margin,
  // this allows the multiple tracers to have consistent positions.
  // TODO(@salama): Find a better placement method.
  window_y_position_ += (window_height_ + kWindowMargin);
}

// Destructor
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

void Tracer::flush(float speed, int index) {
  // Set the focus on this tracer window so that the following drawing will
  // (render) will be in this tracer.
  glutSetWindow(window_id_);

  for (int i = 0; i < 5; i++) {  // reduce the occurrence of semi-render problem
    if (index < 0) {  // negative value means render all the tracer data
      render();
    } else {          // render the element with this index
      render(index);
    }
  }

  if (speed < 0) {
    core::utility::general::delay(speed_);
  } else {
    core::utility::general::delay(speed);   // default speed
  }
}

}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_TRACER_H_
