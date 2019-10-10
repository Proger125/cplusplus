#include "function.h"

int main() {
  double x, y;
  x = InputParam_a();
  y = InputParam_b();
  if ((is_under_line(x, y) && is_under_cos(x, y) && is_in_parabola(x, y) &&
       is_in_circle(x, y) && is_under_null(x,y)) ||
      (!is_under_line(x, y) && !is_under_cos(x, y) && !is_in_parabola(x, y) && is_in_circle(x,y))) {
    cout << "Your point are in the right area" << endl;
  } else {
    cout << "Your point aren't in the right area" << endl;
  }
  system("pause");
  return 0;
}