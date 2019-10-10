#pragma once
#ifdef FUNCTIONS_H

#endif  // FUNCTIONS_H

#include <iostream>
#include <vector>
using namespace std;

void InputN(int& n) {
  cout << "Enter n = ";
  cin >> n;
}
int numeric_sqrt_rec(int n) {
  int value = 0;
  while (n > 0) {
    int k = n % 10;
    value += k;
    n /= 10;
  }
  n = value;
  if (n / 10 == 0) {
    return n;
  } else {
    return numeric_sqrt_rec(n);
  }
}