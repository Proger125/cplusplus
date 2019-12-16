#include <cmath>
#include <iostream>

using namespace std;
int min(const int x, const int y) {
  if (x < y) {
    return x;
  }
  return y;
}
int min(const int x, const int y, const int z) {
  int preresult = min(x, y);
  int result = min(preresult, z);
  return result;
}
int min_sum(const int x, const int y, const int z) {
  int sum = 0;
  int preresult = min(x, y, z);
  if (x == preresult) {
    sum += min(y, z);
  } else if (y == preresult) {
    sum += min(x, z);
  } else {
    sum += min(x, y);
  }
  sum += preresult;
  return sum;
}
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int sum = min_sum(x, y, z);
  cout << sum << endl;
  system("pause");
  return 0;
}