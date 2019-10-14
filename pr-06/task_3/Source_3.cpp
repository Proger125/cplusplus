#include "Function.h"

int main() {
  Point first_left, first_right;
  Point sec_left, sec_right;
  Rectangle first, second;
  first.InputRectangle(first_left, first_right);
  second.InputRectangle(sec_left, sec_right);
  int square = first.SquareOfIntersection(second);
  cout << "The square of intersection = " << square << endl;
  system("pause");
  return 0;
}