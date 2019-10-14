#pragma once
#ifdef FUNCTIONS_H

#endif  // FUNCTIONS_H
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class RationalNumber {
 public:
  int numerator, denominator;
  RationalNumber Sum(RationalNumber Num);
  RationalNumber Substraction(RationalNumber Num);
  RationalNumber Division(RationalNumber Num);
  RationalNumber Multiplication(RationalNumber Num);
  void Reduction();
};
void RationalNumber::Reduction() {
  int i = this->denominator;
  while (i >= 2) {
    if (this->denominator % i == 0 && this->numerator % i == 0) {
      this->denominator /= i;
      this->numerator /= i;
    }
    i--;
  }
}
RationalNumber RationalNumber::Multiplication(RationalNumber Num) {
  RationalNumber result;
  result.numerator = this->numerator * Num.numerator;
  result.denominator = this->denominator * Num.denominator;
  result.Reduction();
  return result;
}
RationalNumber RationalNumber::Division(RationalNumber Num) {
  RationalNumber result;
  result.numerator = this->numerator * Num.denominator;
  result.denominator = this->denominator * Num.numerator;
  result.Reduction();
  return result;
}
RationalNumber RationalNumber::Sum(RationalNumber Num) {
  RationalNumber result;
  result.numerator =
      this->numerator * Num.denominator + Num.numerator * this->denominator;
  result.denominator = this->denominator * Num.denominator;
  result.Reduction();
  return result;
}
RationalNumber RationalNumber::Substraction(RationalNumber Num) {
  RationalNumber result;
  result.numerator =
      this->numerator * Num.denominator - Num.numerator * this->denominator;
  result.denominator = this->denominator * Num.denominator;
  result.Reduction();
  return result;
}
void InputFraction(RationalNumber &Fraction) {
  int num, denom;
  cout << "Enter the Numerator = ";
  cin >> num;
  cout << "Enter the Denominator = ";
  cin >> denom;
  Fraction.denominator = denom;
  Fraction.numerator = num;
}