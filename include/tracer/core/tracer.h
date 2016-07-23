#ifndef INCLUDE_TRACER_CORE_TRACER_H_
#define INCLUDE_TRACER_CORE_TRACER_H_

#include <string>

namespace tracer {
namespace core {

// The base tracer class
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
  // usend in every display functions (e.g. notify, select, ...).
  void flush(float speed = -1);

  // Abstract render method, each subclass has to implement its own
  // render method (e.g. array, matrix, graph, ...).
  virtual void render() = 0;

 private:
  const float kWindowMargin;        // Margin between tracers window.
  static int window_count_;         // The number of created tracers.
  static float window_x_position_;  // The x-position of the next tracer.
  static float window_y_position_;  // The y-position of the next tracer.
  int window_id_;
};

}  // namespace core
}  // namespace tracer

#endif  // INCLUDE_TRACER_CORE_TRACER_H_
