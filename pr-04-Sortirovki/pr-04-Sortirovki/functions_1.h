#pragma once
#ifdef FUNCTIONS_H

#endif  // FUNCTIONS_H
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void InputInteger(int &a, int &b, int &c) {
  cout << "Enter three integer numbers = ";
  cin >> a >> b >> c;
}
void InputDouble(double &aa, double &bb) {
  cout << "Enter two double numbers = ";
  cin >> aa >> bb;
}
void InputChar(char &aaa, char &bbb) {
  cout << "Enter two char symbols = ";
  cin >> aaa >> bbb;
}
void InputString(string &aaaa, string &bbbb) {
  cout << "Enter the first string = ";
  getline(cin, aaaa);
  cout << "Enter the second string = ";
  getline(cin, bbbb);
}
void InputVector(vector<int> &a, int &n) {
  cout << "Enter the count of elements of vector = ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cout << "Enter the element of vector = ";
    cin >> k;
    a.push_back(k);
  }
}
void InputVector_Of_Vectors(vector<vector<int> > &a) {
  for (int i = 0; i < a.size(); i++) {
    int k = 1;
    while (k != 0) {
      cin >> k;
      a[i].push_back(k);
	}
  }
}
int max(int a) { return a; }
int max(int a, int b) { return a > b ? a : b; }
int max(int a, int b, int c) { return a > max(b, c) ? a : max(b, c); }
double max(double a, double b) { return a > b ? a : b; }
char max(char a, char b) { return a > b ? a : b; }
string max(string a, string b) { return a > b ? a : b; }
int max(vector<int> a) {
  int max_element = a[0];
  for (int i = 0; i < a.size(); i++) {
    max_element = max(max_element, a[i]);
  }
  return max_element;
}
int max(vector<vector<int> > a) {
  int max_element = a[0][0];
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++)
      max_element = max(max_element, a[i][j]);
  }
  return max_element;
}