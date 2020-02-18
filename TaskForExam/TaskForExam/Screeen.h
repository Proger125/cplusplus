#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Screen {
 private:
  int height_;
  int width_;
  char** data_;

 public:
  char* operator[](int index);
  int getHeight() const;
  int getWidth() const;
  void set(int x, int y, char c);
  friend ostream& operator <<(ostream& out, const Screen &screen);

 protected:
  Screen() = default;
  Screen(int height, int width);
  Screen(int height, int width, char c);
};
ostream& operator <<(ostream& out, const Screen &screen) {
  for (int i = 0; i < screen.height_; i++) {
    for (int j = 0; j < screen.width_; j++) {
      out << screen.data_[i][j] << " ";
    }
    out << endl;
  }
  return out;
}
