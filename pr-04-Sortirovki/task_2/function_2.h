#pragma once
#ifdef FUNCTION_H

#endif  // FUNCTION_H
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void InputVector(vector <T> &a, int n) {
  for (int i = 0; i < n; i++) {
    T k;
    cin >> k;
    a.push_back(k);
  }
}
template <typename T>
int recurse_max(vector<T> a, int start, int max_element, int max_element_index) {
  if (start == a.size()) {
    return max_element_index;
  }
  if (a[start] > max_element) {
    max_element = a[start];
    max_element_index = start;
    return recurse_max(a, start + 1, max_element, max_element_index);
  } else {
    return recurse_max(a, start + 1, max_element, max_element_index);
  }
}