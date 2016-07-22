#ifndef INCLUDE_TRACER_COLOR_H_
#define INCLUDE_TRACER_COLOR_H_

namespace tracer {

class Color {
 public:
  // Constructor for floating-point values,
  // each channel (red, green, ...) should
  // have a floating-point value from 0.0 to 1.0
  Color(float red, float green, float blue, float alpha = 1.0);

  // Constructor for integer values,
  // each channel (red, green, ...) should
  // have an integer value from 0 to 255
  Color(int red, int green, int blue, int alpha = 255);

  float get_red() const;
  void set_red(float value);
  void set_red(int value);

  float get_blue() const;
  void set_blue(float value);
  void set_blue(int value);

  float get_green() const;
  void set_green(float value);
  void set_green(int value);

  float get_alpha() const;
  void set_alpha(float value);
  void set_alpha(int value);

 private:
  float red_, green_, blue_, alpha_;
  float check_constraints(float value);
  int check_constraints(int value);
};

}  // namespace tracer

#endif  // INCLUDE_TRACER_COLOR_H_
