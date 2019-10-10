#include <iostream>

using namespace std;
int simple_check(int a) {
  int k = 0;
  for (int i = 1; i < a / 2; i++) {
    if (a % i == 0) {
      k = 0;
      break;
    } else {
      k = 1;
    }
  }
  return k;
}
int main() {
  int n;
  cout << "Enter n = ";
  cin >> n;
  int i = 1, k = 0;
  while (k < n) {
    if (simple_check(i)) {
      cout << i << endl;
      k++;
	}
    i++;
  }
  return 0;
}