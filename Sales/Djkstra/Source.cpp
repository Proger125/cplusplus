#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a[100][100];
  int d[100];
  int v[100];
  int begin_index, end_index;
  int n, m;
  int minindex, min, temp;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = 1000000;
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
  for (int i = 0; i < n; i++) {
    d[i] = 100000;
    v[i] = 1;
  }
  d[begin_index - 1] = 0;
  do {
    minindex = 100000;
    min = 100000;
    for (int i = 0; i < n; i++) {
      if (v[i] == 1 && d[i] < min) {
        min = d[i];
        minindex = i;
      }
    }
    if (minindex != 100000) {
      for (int i = 0; i < n; i++) {
        if (a[minindex][i] > 0) {
          temp = min + a[minindex][i];
          if (temp < d[i]) {
            d[i] = temp;
		  }
        }
      }
      v[minindex] = 0;
    }
  } while (minindex < 100000);


  if (d[end_index - 1]!= 100000) {
    cout << d[end_index - 1] << endl;
    int ver[100];
    int end = end_index - 1;
    ver[0] = end_index;
    int k = 1;
    int weight = d[end];
    while (end != begin_index - 1) {
      for (int i = 0; i < n; i++) {
        if (a[i][end] != 0) {
          int temp = weight - a[i][end];
          if (temp == d[i]) {
            weight = temp;
            end = i;
            ver[k] = i + 1;
            k++;
		  }
		}
	  }
    }
    for (int i = k - 1; i >= 0; i--) {
      cout << ver[i] << " ";
	}
  } else {
    cout << 0 << endl;
  }
  system("pause");
  return 0;
}