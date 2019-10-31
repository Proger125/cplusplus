#include "Functions.h"

int main() {
  RationalNumber<int> first, second, result;
  InputNumber(first);
  InputNumber(second);
  Program<int> prog(first, second);
  prog.ShowThePower();
  system("pause");
  return 0;
}