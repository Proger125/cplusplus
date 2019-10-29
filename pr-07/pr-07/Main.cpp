#include "Functions.h"

int main() {
  RationalNumber<int> first, second, result;
  InputNumber(first);
  InputNumber(second);
  --first;
  cout << first;
  system("pause");
  return 0;
}