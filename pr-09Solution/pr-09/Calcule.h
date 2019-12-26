#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include "StackOnArray.h"
#include "StackOnList.h"

using namespace std;
int priority_f(string s) {
  if (s == "|") {
    return 2;
  }
  if (s == "max" || s == "min") {
    return 1;
  }
}
vector<string> ToReversePolishForm(string str) {
  vector<string> result;
  string num = "", f = "";
  stackInList<string> stack;
  for (int i = 0; i < str.size(); i++) {
    if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
      num += str[i];
    }
    if (str[i] == '(') {
      result.push_back(num);
      num = "";
      stack.push(f);
      f = "";
    }
    if (str[i] == ')') {
      result.push_back(num);
      num = "";
      result.push_back(stack.pop());
    }
    if (str[i] == ',') {
      result.push_back(num);
      num = "";
    }
    if (str[i] >= 'a' && str[i] <= 'z') {
      f += str[i];
    }
    if (str[i] == '|') {
      string a;
      a += '|';
      stack.push(a);
    }
    if (i == str.size() - 1) {
      result.push_back(num);
      num = "";
    }
  }
  while (!stack.IsEmpty()) {
    result.push_back(stack.pop());
  }
  int i = 0;
  while (i < result.size()) {
    if (result[i] == "") {
      result.erase(result.begin() + i, result.begin() + i + 1);
      i--;
    }
    i++;
  }
  return result;
}
int CalculateForm(vector<string> v) {
  stackInList<string> stack;
  int result = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] != "max" && v[i] != "min" && v[i] != "|") {
      stack.push(v[i]);
    } else {
      int first = stoi(stack.pop());
      int second = stoi(stack.pop());
      stack.push(to_string(first | second));
    }
  }
  return stoi(stack.pop());
}