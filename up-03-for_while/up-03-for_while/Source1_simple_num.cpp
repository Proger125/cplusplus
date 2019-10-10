#include <iostream>

using namespace std;
int simple_check(int a) {
  int k = 0;
  if (a == 2) {
    k = 1;
    return k;
  } else if (a == 3) {
    k = 1;
    return k;
  } else {
    for (int i = 2; i < (a / 2) + 1; i++) {
      if (a % i == 0) {
        k = 0;
        break;
      } else {
        k = 1;
      }
    }
    return k;
  }
}
int main() {
  int n;
  cout << "Enter n = ";
  cin >> n;
  int i = 1, k = 0;
  while (k < n) {
    if (simple_check(i)) {
      cout << "The simple number = " << i << endl;
      k++;
    }
    i++;
  }
  system("pause");
  return 0;
}