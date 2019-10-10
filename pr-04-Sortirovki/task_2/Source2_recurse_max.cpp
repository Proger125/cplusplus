#include "function.h"

int main() {
  vector<int> a;
  int n;
  cout << "Enter n = ";
  cin >> n;
  InputVector(a, n);
  int k = recurse_max(a, 0, a[0], 0);
  cout <<"The index of max element = " << k << endl;
  system("pause");
  return 0;
}