#pragma once
#ifdef FUNCTION_H

#endif  // FUNCTION_H

#include <cmath>
#include <iostream>

using namespace std;
double InputParam_a() {
  double a;
  cout << "Enter x = ";
  cin >> a;
  return a;
}
double InputParam_b() {
  double b;
  cout << "Enter y = ";
  cin >> b;
  return b;
}
bool is_in_parabola(double x, double y) {
  if (x * x + 2 * x - sqrt(15) <= y) {
    return true;
  } else {
    return false;
  }
}
bool is_under_cos(double x, double y) {
  if (cos(2 * x) >= y) {
    return true;
  } else {
    return false;
  }
}
bool is_under_null(double x, double y) {
  if (x >= -0.785 && x <= 0.785 && y <= 0) {
    return true;
  } else if (x < -0.785 || x > 0.785){
    return true;
  } else {
    return false;
  }
}
bool is_in_circle(double x, double y) {
  if (x * x + y * y <= 15) {
    return true;
  } else {
    return false;
  }
}
bool is_under_line(double x, double y) {
  if (-x + 3 >= y) {
    return true;
  } else {
    return false;
  }
}
