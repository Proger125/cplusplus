#pragma once
#include <cmath>
#include <iostream>
#include <assert.h>

using namespace std;

template <class T>
class RationalNumber {
 public:
  T numerator, denominator;
  RationalNumber();
  RationalNumber(T num, T denom);
  RationalNumber operator+() const;
  RationalNumber operator-() const;
  RationalNumber operator+=(RationalNumber<T> num);
  RationalNumber operator-=(RationalNumber<T> num);
  RationalNumber operator*=(RationalNumber<T> num);
  RationalNumber operator/=(RationalNumber<T> num);
  ostream& operator<<(ostream &fout);
  RationalNumber operator+(RationalNumber<T> num);
  RationalNumber operator-(RationalNumber<T> num);
  RationalNumber operator*(RationalNumber<T> num);
  RationalNumber operator/(RationalNumber<T> num);
  bool operator==(RationalNumber<T> num);
  bool operator!=(RationalNumber<T> num);
  bool operator>(RationalNumber<T> num);
  bool operator<(RationalNumber<T> num);
  bool operator>=(RationalNumber<T> num);
  bool operator<=(RationalNumber<T> num);
  RationalNumber operator++();
  RationalNumber operator--();
};
template <class T>
class Program {
 public:
  RationalNumber<T> first, second;
  Program(RationalNumber<T> f, RationalNumber<T> s);
  void ShowThePower();
};
template <typename T>
Program<T>::Program<T>(RationalNumber<T> f, RationalNumber<T> s) {
  first = f;
  second = s;
}
template <typename T>
T gcd(T a, T b) {
  if (a > b) {
    if (b == 0)
      return a;
    else
      return gcd(b, a % b);
  } else {
    if (a == 0)
      return b;
    else
      return gcd(a, b % a);
  }
}
template <typename T>
void Program<T>::ShowThePower() {
  RationalNumber<T> result;
  result = first + second;
  cout << "The sum of your Rational Numbers = " << result << endl;
  result = first - second;
  cout << "The substraction of your Rational Numbers = " << result << endl;
  result = first * second;
  cout << "The multiplication of your Rational Numbers = " << result << endl;
  result = first / second;
  cout << "The division of your Rational Numbers = " << result << endl;
  if (first != second && first > second) {
    cout << "The numbers are not equal and the first is bigger than second"
         << endl;
  } else if (first != second && first < second) {
    cout << "The numbers are not equal and the second is bigger than first" << endl;
  } else if (first == second) {
    cout << "The numbers are equal" << endl;
  }
  result = ++first;
  cout << "The increment of first number = " << result << endl;
  result = --second;
  cout << "The dicrement of second number = " << result << endl;
}
template <typename T>
RationalNumber<T>::RationalNumber() {
  numerator = 0;
  denominator = 1;
}
template <typename T>
RationalNumber<T>::RationalNumber(T num, T denom) {
  numerator = num;
  denominator = denom;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator+() const {
  T nod = gcd(this->numerator, this->denominator);
  assert(this->denominator != 0 && "Your denominator = 0");
  return RationalNumber(this->numerator / nod, this->denominator / nod);
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator-() const {
  T num = this->numerator * (-1);
  return RationalNumber(num, this->denominator);
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator+=(RationalNumber<T> num) {
  RationalNumber<T> result;
  result.numerator =
      this->numerator * num.denominator + num.numerator * this->denominator;
  result.denominator = this->denominator * num.denominator;
  result = +result;
  this->numerator = result.numerator;
  this->denominator = result.denominator;
  return result;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator-=(RationalNumber<T> num) {
  RationalNumber<T> result;
  result.numerator =
      this->numerator * num.denominator - num.numerator * this->denominator;
  result.denominator = this->denominator * num.denominator;
  result = +result;
  this->numerator = result.numerator;
  this->denominator = result.denominator;
  return result;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator*=(RationalNumber<T> num) {
  RationalNumber result;
  result.numerator = this->numerator * num.numerator;
  result.denominator = this->denominator * num.denominator;
  result = +result;
  this->numerator = result.numerator;
  this->denominator = result.denominator;
  return result;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator/=(RationalNumber<T> num) {
  RationalNumber result;
  result.numerator = this->numerator * num.denominator;
  result.denominator = this->denominator * num.numerator;
  result = +result;
  this->numerator = result.numerator;
  this->denominator = result.denominator;
  return result;
}
template <typename T>
ostream &operator<<(ostream &fout, RationalNumber<T> &num) {
  fout << num.numerator << " / " << num.denominator << endl;
  return fout;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator+(RationalNumber<T> num) {
  RationalNumber result;
  result.numerator =
      this->numerator * num.denominator + num.numerator * this->denominator;
  result.denominator = this->denominator * num.denominator;
  result = +result;
  return result;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator-(RationalNumber<T> num) {
  RationalNumber result;
  result.numerator =
      this->numerator * num.denominator - num.numerator * this->denominator;
  result.denominator = this->denominator * num.denominator;
  result = +result;
  return result;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator*(RationalNumber<T> num) {
  RationalNumber result;
  result.numerator = this->numerator * num.numerator;
  result.denominator = this->denominator * num.denominator;
  result = +result;
  return result;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator/(RationalNumber<T> num) {
  RationalNumber result;
  result.numerator = this->numerator * num.denominator;
  result.denominator = this->denominator * num.numerator;
  result = +result;
  return result;
}
template <typename T>
void InputNumber(RationalNumber<T> &num) {
  T n, d;
  cout << "Enter the numerator = ";
  cin >> n;
  cout << "Enter the denominator = ";
  cin >> d;
  assert(d != 0 && "Your denominator = 0");
  RationalNumber<T> item(n, d);
  item = +item;
  num = item;
}
template <typename T>
bool RationalNumber<T>::operator==(RationalNumber<T> num) {
  if (this->denominator == num.denominator && this->numerator == num.numerator) {
    return 1;
  } else {
    return 0;
  }
}
template <typename T>
bool RationalNumber<T>::operator!=(RationalNumber<T> num) {
  if (this->denominator == num.denominator &&
      this->numerator == num.numerator) {
    return 0;
  } else {
    return 1;
  }
}
template<typename T>
bool RationalNumber<T>::operator>(RationalNumber<T> num) {
  T f, s;
  f = this->numerator * num.denominator;
  s = num.numerator * this->denominator;
  if (f > s) {
    return 1;
  } else {
    return 0;
  }
}
template <typename T>
bool RationalNumber<T>::operator<(RationalNumber<T> num) {
  T f, s;
  f = this->numerator * num.denominator;
  s = num.numerator * this->denominator;
  if (f < s) {
    return 1;
  } else {
    return 0;
  }
}
template <typename T>
bool RationalNumber<T>::operator>=(RationalNumber<T> num) {
  T f, s;
  f = this->numerator * num.denominator;
  s = num.numerator * this->denominator;
  if (f >= s) {
    return 1;
  } else {
    return 0;
  }
}
template <typename T>
bool RationalNumber<T>::operator<=(RationalNumber<T> num) {
  T f, s;
  f = this->numerator * num.denominator;
  s = num.numerator * this->denominator;
  if (f <= s) {
    return 1;
  } else {
    return 0;
  }
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator++(){
  this->numerator += this->denominator;
  return *this;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator--() {
  this->numerator -= this->denominator;
  return *this;
}
