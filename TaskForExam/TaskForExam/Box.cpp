#include "Box.h"
void Box::place(int place_height, int place_width){
  place_height_ = place_height;
  place_width_ = place_width;
}
int Box::getHeight() const { return height_; }
int Box::getWidth() const { return width_; }
Box::Box(int height, int width, int place_height, int place_width) {
  height_ = height;
  width_ = width;
  place_height_ = place_height;
  place_width_ = place_width;
}