#include <iostream>

using namespace std;
int Fibonachi_check(int a) {
  int array_of_f[1000];
  int k = 0;
  array_of_f[0] = 1;
  array_of_f[1] = 1;
  int i = 2;
  while (i < 1000) {
    array_of_f[i] = array_of_f[i - 1] + array_of_f[i - 2];
    i++;
  }
  for (int j = 0; j < 1000; j++) {
    if (a == array_of_f[j]) {
      k = 1;
      break;
    } else {
      k = 0;
	}
  }
  return k;
}
int main() {
  int a, b;
  cout << "Enter the start of the gap = ";
  cin >> a;
  cout << "Enter the end of the gap = ";
  cin >> b;
  for (int i = a; i < b; ++i) {
    if (Fibonachi_check(i)) {
      cout << "The Fibonachi number = " << i << endl;
	}
  }
  system("pause");
  return 0;
}