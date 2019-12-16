#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<double> > v(m + 2, vector<double>(n + 2));
  vector<vector<double> > res(m, vector<double>(n));
  for (int i = 0; i < m + 2; i++) {
    for (int j = 0; j < n + 2; j++) {
      v[i][j] = 0;
    }
  }
  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      res[i - 1][j - 1] =
          res[i - 1][j - 1] + v[i - 1][j - 1] / 2 + v[i - 1][j] / 2 +
          v[i - 1][j + 1] / 2 + v[i][j - 1] / 2 + v[i][j] + v[i][j + 1] / 2 +
          v[i + 1][j - 1] / 2 + v[i + 1][j] / 2 + v[i + 1][j + 1] / 2;
    }
  }
  double max = res[0][0];
  int max_i = 0;
  int max_j = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (res[i][j] >= max) {
        max = res[i][j];
        max_i = i;
        max_j = j;
	  }
	}
  }
  double sec_max = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (res[i][j] >= sec_max && (i > max_i + 2 || i < max_i - 2 ||
                                   j > max_j + 2 || j < max_j - 2)) {
        sec_max = res[i][j];
	  }
	}
  }
  cout << max + sec_max << endl	;
  system("pause");
  return 0;
}