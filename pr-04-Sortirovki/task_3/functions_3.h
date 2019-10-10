#pragma once
#ifdef FUNCTIONS_H

#endif  // FUNCTIONS_H

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
void InputString(string &a) {
  cout << "Enter the string = " << endl;
  getline(cin, a);
}
void InputParametres(int &start, int &end) {
  cout << "Enter the start of substring = ";
  cin >> start;
  cout << "Enter the end of substring = ";
  cin >> end;
}
bool is_sym_rec(string a, int start, int end) {
  if (start == end || start > end) {
    return true;
  }
  if (a[start] == a[end]) {
    return is_sym_rec(a, start + 1, end - 1);
  } else {
    return false;
  }
}