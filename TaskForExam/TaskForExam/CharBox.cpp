#include "CharBox.h"
CharBox::CharBox(int place_height, int place_width, char symbol)
    : Box(1, 1, place_height, place_width) {
  symbol_ = symbol;
}
void CharBox::layout() {
  height_ = 1;
  width_ = 1;
}
void CharBox::print(int x, int y, Screen& screen) {
  int co_x = x + this->place_height_;
  int co_y = y + this->place_width_;
  screen.set(co_x, co_y, symbol_);
}
Box* CharBox::clone(Box* box) {
  return new CharBox(this->place_height_, this->place_width_, this->symbol_);
}
CharBox::~CharBox() { delete this; }