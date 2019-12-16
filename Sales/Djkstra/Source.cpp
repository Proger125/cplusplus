#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a[100][100];
  int prev[100][100];
  vector<int> path;
  int begin_index, end_index;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = 1000000;
      prev[i][j] = i;
      if (i == j) {
        a[i][j] = 0;
      }
    }
  }
  cin >> begin_index >> end_index;
  for (int i = 0; i < m; i++) {
    int j, k;
    int val;
    cin >> j >> k >> val;
    a[j - 1][k - 1] = val;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][k] < 1000000 && a[k][j] < 1000000 &&
            a[i][k] + a[k][j] < a[i][j]) {
          a[i][j] = a[i][k] + a[k][j];
          prev[i][j] = prev[k][j];
        }
      }
    }
  }
  if (a[begin_index - 1][end_index - 1] != 1000000) {
    cout << a[begin_index - 1][end_index - 1] << endl;
    int f = 1;
    while (f != end_index) {
      cout << prev[begin_index - 1][f] + 1 << " ";
      f++;
    }
    cout << end_index << " ";
  } else
    cout << 0 << endl;
  system("pause");
  return 0;
}