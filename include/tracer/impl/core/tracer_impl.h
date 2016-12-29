#ifndef INCLUDE_TRACER_IMPL_CORE_TRACER_IMPL_H_
#define INCLUDE_TRACER_IMPL_CORE_TRACER_IMPL_H_

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
#include "tracer/core/util/general.h"

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
               const Theme& theme) : kWindowMargin(50.0) {
  window_width_ = window_width;
  window_height_ = window_height;
  speed_ = speed;
  theme_ = theme;

  // Only call glutInit function first time the tracer is created,
  // this allows multiple tracers to be created with glut been
  // initalized only once.
  if (window_count_++ == 0)
    glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(window_width_, window_height_);
  glutInitWindowPosition(window_x_position_, window_y_position_);
  window_id_ = glutCreateWindow(window_title.c_str());

  glClearColor(theme.tracer_background_color.get_red(),
               theme.tracer_background_color.get_green(),
               theme.tracer_background_color.get_blue(),
               theme.tracer_background_color.get_alpha());
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


// Flush
void Tracer::flush(float speed, int index) {
  // Set the focus on this tracer window so that the following drawing will
  // (render) will be in this tracer.
  glutSetWindow(window_id_);
  glutMainLoopEvent();  // processes a single iteration in the freeglut loop

  for (int i = 0; i < 5; i++) {  // reduce the occurrence of semi-render problem
    if (index < 0) {  // negative value means render all the tracer data
      render();
    } else {          // render the element with this index
      render(index);
    }
  }

  if (speed < 0) {
    core::util::general::Delay(speed_);  // default speed
  } else {
    core::util::general::Delay(speed);
  }
}


// visualization methods with default values.
void Tracer::update() {
  update(speed_);
}
void Tracer::notify(int index) {
  notify(index, speed_);
}
void Tracer::notify(int index, double speed) {
  notify(index, static_cast<float>(speed));
}
void Tracer::select(int index) {
  select(index, speed_);
}
void Tracer::select(int index, double speed) {
  select(index, static_cast<float>(speed));
}
void Tracer::deselect(int index) {
  deselect(index, speed_);
}
void Tracer::deselect(int index, double speed) {
  deselect(index, static_cast<float>(speed));
}

}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_IMPL_CORE_TRACER_IMPL_H_
