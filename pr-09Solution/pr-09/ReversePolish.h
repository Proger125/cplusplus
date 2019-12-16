#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "StackOnArray.h"
#include "StackOnList.h"

using namespace std;
int priority(char c) {
  if (c == '*' || c == '/') {
    return 2;
  }
  if (c == '+' || c == '-') {
    return 1;
  }
  if (c == '(' || c == ')') {
    return 0;
  }
}
double Calc(double first, double second, string s) {
  if (s == "+") {
    return second + first;
  }
  if (s == "-") {
    return second - first;
  }
  if (s == "*") {
    return second * first;
  }
  if (s == "/") {
    return second / first;
  }
}
vector<string> ToReversePolish(string str) {
  vector<string> result;
  string num = "";
  stackInList<char> stack;
  for (int i = 0; i < str.size(); i++) {
    if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
      num += str[i];
    }
    if (str[i] == '(') {
      result.push_back(num);
      num = "";
      stack.push(str[i]);
    }
    if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
      result.push_back(num);
      num = "";
      while (!stack.IsEmpty() && (priority(stack.top()) > priority(str[i]))) {
        string a;
        a += stack.pop();
        result.push_back(a);
      }
      stack.push(str[i]);
    }
    if (str[i] == ')') {
      result.push_back(num);
      num = "";
      while (!stack.IsEmpty() && (stack.top() != '(')) {
        string a;
        a += stack.pop();
        result.push_back(a);
      }
      char a = stack.pop();
    }
  }
  result.push_back(num);
  while (!stack.IsEmpty()) {
    string a;
    a += stack.pop();
    result.push_back(a);
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
double CalculateReversePolish(vector<string> v) {
  stackInList<string> stack;
  double result = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/") {
      stack.push(v[i]);
    } else {
      double first = stod(stack.pop());
      double second = stod(stack.pop());
      stack.push(to_string(Calc(first, second, v[i])));
	}
  }
  return stod(stack.pop());
}