#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
int Who(const int x, const int y, const int r1, const int r2) {
  if (x * x + y * y >= r2 * r2) {
    return 0;
  }
  if (x * x + y * y == r1 * r1) {
    return 0;
  }
  if (x == 0 || y == 0) {
    return 0;
  }
  if (x * x + y * y > r1 * r1) {
    if (x * y > 0) {
      return 1;
    } else {
      return -1;
    }
  } else {
    if (x * y > 0) {
      return -1;
    } else {
      return 1;
    }
  }
}
int main() {
  int r1, r2;
  int a, k;
  int n;
  int A_sum = 0, K_sum = 0;
  vector<pair<int, int> > v;
  cin >> r1 >> r2;
  cin >> a >> k;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  for (int i = 0; i < n; i++) {
    int point = Who(v[i].first, v[i].second, r1, r2);
    if (!point) {
      continue;
    } else {
      if (point == 1) {
        A_sum += a;
        K_sum -= a;
      } else {
        A_sum -= k;
        K_sum += k;
	  }
	}
  }
  cout << A_sum << endl;
  system("pause");
  return 0;
}