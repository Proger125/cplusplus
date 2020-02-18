#pragma once
#include "Box.h"
class CharBox : public Box {
 private:
  char symbol_;

 public:
  CharBox(int place_height, int place_width, char symbol);
  void layout() override;
  void print(int x, int y, Screen& screen) override;
  Box* clone(Box* box) override;
  ~CharBox() override;
};
