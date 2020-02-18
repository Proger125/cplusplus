#pragma once
#include "Screeen.h"
class Box {
 protected:
  int height_;
  int width_;
  int place_height_;
  int place_width_;

 public:
  void place(int place_height, int place_widht);
  int getHeight() const;
  int getWidth() const;
  virtual void layout() = 0;
  virtual void print(int x, int y, Screen& screen) = 0;
  virtual Box* clone(Box* box) = 0;
  virtual ~Box() = default;

 protected:
  Box(int height, int width, int place_height, int place_width);
};
