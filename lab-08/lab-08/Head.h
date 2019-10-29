#pragma once
#ifdef HEAD_H

#endif  // HEAD_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Fraction {
 public:
  int numerator, denominator;
  friend istream &operator>>(istream &fin, Fraction &frac);
  friend ostream &operator<<(ostream &fout, Fraction &frac);
  void Reduction();
  Fraction operator+(Fraction &frac);
  Fraction operator-(Fraction &frac);
  Fraction operator*(Fraction &frac);
  Fraction operator/(Fraction &frac);
};
void Fraction::Reduction() {
  int i = this->denominator;
  while (i >= 2) {
    if (this->denominator % i == 0 && this->numerator % i == 0) {
      this->denominator /= i;
      this->numerator /= i;
    }
    i--;
  }
}
istream &operator>>(istream &fin, Fraction &frac) {
  cout << "Enter the numerator = ";
  fin >> frac.numerator;
  cout << "Enter the denominator = ";
  fin >> frac.denominator;
  return fin;
}
ostream &operator<<(ostream &fout, Fraction &frac){
  fout << frac.numerator << " / " << frac.denominator << endl;
  return fout;
}
Fraction Fraction::operator+(Fraction &frac) {
  Fraction result;
  result.numerator =
      this->numerator * frac.denominator + frac.numerator * this->denominator;
  result.denominator = this->denominator * frac.denominator;
  result.Reduction();
  return result;
}
Fraction Fraction::operator-(Fraction &frac) {
  Fraction result;
  result.numerator =
      this->numerator * frac.denominator - frac.numerator * this->denominator;
  result.denominator = this->denominator * frac.denominator;
  result.Reduction();
  return result;
}
Fraction Fraction::operator*(Fraction &frac) {
  Fraction result;
  result.numerator = this->numerator * frac.numerator;
  result.denominator = this->denominator * frac.denominator;
  result.Reduction();
  return result;
}
Fraction Fraction::operator/(Fraction &frac) {
  Fraction result;
  result.numerator = this->numerator * frac.denominator;
  result.denominator = this->denominator * frac.numerator;
  result.Reduction();
  return result;
}