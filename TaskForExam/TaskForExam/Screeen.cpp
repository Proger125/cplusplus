#include "Screeen.h"
char* Screen::operator[](int index) { return data_[index]; }
int Screen::getHeight() const { return height_; }
int Screen::getWidth() const { return width_; }
void Screen::set(int x, int y, char c) { data_[x][y] = c; }
Screen::Screen(int height, int width) {
  height_ = height;
  width_ = width;
}
Screen::Screen(int height, int width, char c) {
  height_ = height;
  width_ = width;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      data_[i][j] = c;
	}
  }
}