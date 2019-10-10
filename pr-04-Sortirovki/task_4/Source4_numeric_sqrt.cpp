#include "functions.h"

int main() {
  int n;
  InputN(n);
  int k = numeric_sqrt_rec(n);
  cout << "The numeric key of your number = " << k << endl;
  system("pause");
  return 0;
}