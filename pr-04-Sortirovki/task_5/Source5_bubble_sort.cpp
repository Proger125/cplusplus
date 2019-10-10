#include"bubble_sort.h"
int main() {
  vector<int> a;
  int n = InputN();
  InputVector(a, n);
  Bubble_sort(a, n);
  for (auto &element : a) {
    cout << element << endl;
  }
  system("pause");
  return 0;
}