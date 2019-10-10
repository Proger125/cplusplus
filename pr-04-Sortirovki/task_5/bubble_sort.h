#pragma once
#ifdef BUBBLE_SORT_H

#endif  // BUBBLE_SORT_H
#include <iostream>
#include <vector>

using namespace std;
template <typename T>
void Bubble_sort(vector<T> &a, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}
int InputN() {
  int n;
  cout << "Enter n = ";
  cin >> n;
  return n;
}
template <typename T>
void InputVector(vector<T> &a, int n) {
  T k;
  for (int i = 0; i < n; i++) {
    cout << "Enter the element = ";
    cin >> k;
    a.push_back(k);
  }
}