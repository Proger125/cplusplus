#pragma once
#include <cmath>
#include <iostream>

using namespace std;

template <class T>
class RationalNumber {
 public:
  T numerator, denominator;
  RationalNumber();
  RationalNumber(T num, T denom);
  RationalNumber operator+() const;
  RationalNumber operator-() const;
  RationalNumber operator+=(RationalNumber<T> &num);
  RationalNumber operator-=(RationalNumber<T> &num);
  RationalNumber operator*=(RationalNumber<T> &num);
  RationalNumber operator/=(RationalNumber<T> &num);
  ostream operator<<(ostream &fout);
  RationalNumber operator+(RationalNumber<T> &num);
  RationalNumber operator-(RationalNumber<T> &num);
  RationalNumber operator*(RationalNumber<T> &num);
  RationalNumber operator/(RationalNumber<T> &num);
  bool operator==(RationalNumber<T> &num);
  bool operator!=(RationalNumber<T> &num);
  bool operator>(RationalNumber<T> &num);
  bool operator<(RationalNumber<T> &num);
  bool operator>=(RationalNumber<T> &num);
  bool operator<=(RationalNumber<T> &num);
  RationalNumber operator++();
  RationalNumber operator--();
};
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
  T i = this->denominator;
  T num = this->numerator;
  T denom = this->denominator;
  while (i >= 2) {
    if (denom % i == 0 && num % i == 0) {
      denom /= i;
      num /= i;
    }
    i--;
  }
  return RationalNumber(num, denom);
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator-() const {
  T num = this->numerator * (-1);
  return RationalNumber(num, this->denominator);
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator+=(RationalNumber<T> &num) {
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
RationalNumber<T> RationalNumber<T>::operator-=(RationalNumber<T> &num) {
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
RationalNumber<T> RationalNumber<T>::operator*=(RationalNumber<T> &num) {
  RationalNumber result;
  result.numerator = this->numerator * num.numerator;
  result.denominator = this->denominator * num.denominator;
  result = +result;
  this->numerator = result.numerator;
  this->denominator = result.denominator;
  return result;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator/=(RationalNumber<T> &num) {
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
RationalNumber<T> RationalNumber<T>::operator+(RationalNumber<T> &num) {
  RationalNumber result;
  result.numerator =
      this->numerator * num.denominator + num.numerator * this->denominator;
  result.denominator = this->denominator * num.denominator;
  result = +result;
  return result;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator-(RationalNumber<T> &num) {
  RationalNumber result;
  result.numerator =
      this->numerator * num.denominator - num.numerator * this->denominator;
  result.denominator = this->denominator * num.denominator;
  result = +result;
  return result;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator*(RationalNumber<T> &num) {
  RationalNumber result;
  result.numerator = this->numerator * num.numerator;
  result.denominator = this->denominator * num.denominator;
  result = +result;
  return result;
}
template <typename T>
RationalNumber<T> RationalNumber<T>::operator/(RationalNumber<T> &num) {
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
  RationalNumber<T> item(n, d);
  item = +item;
  num = item;
}
template <typename T>
bool RationalNumber<T>::operator==(RationalNumber<T> &num) {
  if (this->denominator == num.denominator && this->numerator == num.numerator) {
    return 1;
  } else {
    return 0;
  }
}
template <typename T>
bool RationalNumber<T>::operator!=(RationalNumber<T> &num) {
  if (this->denominator == num.denominator &&
      this->numerator == num.numerator) {
    return 0;
  } else {
    return 1;
  }
}
template<typename T>
bool RationalNumber<T>::operator>(RationalNumber<T> &num) {
  this->numerator =
      this->numerator * num.denominator;
  num.numerator =
      num.numerator * this->denominator;
  if (this->numerator > num.numerator) {
    return 1;
  } else {
    return 0;
  }
}
template <typename T>
bool RationalNumber<T>::operator<(RationalNumber<T> &num) {
  this->numerator = this->numerator * num.denominator;
  num.numerator = num.numerator * this->denominator;
  if (this->numerator < num.numerator) {
    return 1;
  } else {
    return 0;
  }
}
template <typename T>
bool RationalNumber<T>::operator>=(RationalNumber<T> &num) {
  this->numerator = this->numerator * num.denominator;
  num.numerator = num.numerator * this->denominator;
  if (this->numerator >= num.numerator) {
    return 1;
  } else {
    return 0;
  }
}
template <typename T>
bool RationalNumber<T>::operator<=(RationalNumber<T> &num) {
  this->numerator = this->numerator * num.denominator;
  num.numerator = num.numerator * this->denominator;
  if (this->numerator <= num.numerator) {
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