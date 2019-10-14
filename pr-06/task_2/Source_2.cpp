#include "Functions.h"

int main() {
  RationalNumber first, second, result;
  InputFraction(first);
  InputFraction(second);
  first.Reduction();
  second.Reduction();
  result = first.Sum(second);
  cout << "The Sum of your fractions = ";
  cout << result.numerator << " / " << result.denominator << endl;
  result = first.Substraction(second);
  cout << "The Substraction of your fractions = ";
  cout << result.numerator << " / " << result.denominator << endl;
  result = first.Multiplication(second);
  cout << "The Multiplication of your fractions = ";
  cout << result.numerator << " / " << result.denominator << endl;
  result = first.Division(second);
  cout << "The Division of your fractions = ";
  cout << result.numerator << " / " << result.denominator << endl;
  system("pause");
  return 0;
}