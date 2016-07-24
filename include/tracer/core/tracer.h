#ifndef INCLUDE_TRACER_CORE_TRACER_H_
#define INCLUDE_TRACER_CORE_TRACER_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// The base abstract tracer class, defines the core functionality of the tracer.
// Handles glut windows initialization, and flushes outputs to screen.

#include <string>

namespace tracer {
namespace core {

class Tracer {
 public:
  Tracer(int argc,                  // [argc, argv] are required
         char** argv,               // by glut libarary (glutInit).
         float window_width,
         float window_height,
         float speed,
         const std::string& window_title);
  ~Tracer();

 protected:
  float window_width_;
  float window_height_;
  float speed_;

  // FLush the screen with a new iteration of render and delay
  // the screen for the specified amount of time (speed).
  // usend in every display method (e.g. notify, select, ...).
  //
  // If no speed specified or has negative value, the flush method will use
  // the default speed specified in tracer constructor.
  //
  // Examples:
  //    flush();
  //    flush(0.5);
  void flush(float speed = -1);

  // Abstract render method, each subclass has to implement its own
  // render method (e.g. array, matrix, graph, ...).
  virtual void render() = 0;

 private:
  const float kWindowMargin;        // Margin between tracers window.
  static int window_count_;         // The number of created tracers.
  static float window_x_position_;  // The x-position of the next tracer.
  static float window_y_position_;  // The y-position of the next tracer.
  int window_id_;                   // Window identifier.
};

}  // namespace core
}  // namespace tracer

// Defer the definition in an implementation file.
#include "tracer/impl/core/tracer.h"

#endif  // INCLUDE_TRACER_CORE_TRACER_H_
