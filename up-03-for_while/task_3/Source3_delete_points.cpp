#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  vector<int> a;
  cout << "Enter n = ";
  cin >> n;
  while (n > 0) {
    int k = n % 10;
    a.push_back(k);
    n /= 10;
  }
  for (int i = 0; i < a.size(); i++) {
    int k = a[i];
    int j = i + 1;
    while (j < a.size()) {
      if (a[j] == k) {
        a.erase(a.begin() + j);
      } else {
        j++;
      }
    }
  }
  for (int i = a.size() - 1; i >= 0; i--) {
    cout << a[i];
  }
  cout << endl;
  system("pause");
  return 0;
}