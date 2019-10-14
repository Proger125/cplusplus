#pragma once
#ifdef FUNCTION_H

#endif  // FUNCTION_H
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Point {
 public:
  int x, y;
  void InputPoint();
};
void Point::InputPoint() {
  int x, y;
  cout << "Enter the x of your point = ";
  cin >> x;
  cout << "Enter the y of your point = ";
  cin >> y;
  this->x = x;
  this->y = y;
}
class Rectangle {
 public:
  Point left, right;
  void InputRectangle(Point &Po_1, Point &Po_2);
  double SquareOfIntersection(Rectangle Rec);
};
void Rectangle::InputRectangle(Point &Po_1, Point &Po_2) {
  Po_1.InputPoint();
  Po_2.InputPoint();
  this->left = Po_1;
  this->right = Po_2;
}
double Rectangle::SquareOfIntersection(Rectangle Rec) {
  int left = max(this->left.x, Rec.left.x);
  int top = min(this->right.y, Rec.right.y);
  int right = min(this->right.x, Rec.right.x);
  int bottom = max(this->left.y, Rec.left.x);
  int width = right - left;
  int height = top - bottom;
  if ((width < 0) || (height < 0)) {
    return 0;
  }
  return width * height;
}