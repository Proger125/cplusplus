#include "Head.h"
#include "gtest/gtest.h"

int main() {
  Fraction first, second, result;
  cin >> first;
  cin >> second;
  result = first / second;
  cout << result;
  testing::InitGoogleTest(&argc, argv);
  system("pause");
  return 0;
}