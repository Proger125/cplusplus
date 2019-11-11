#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n, m, k = 1;
  cin >> n >> m;
  int a[100][100];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          a[i][j] = k;
          k++;
        } else {
          a[i][j] = 0;
		}
      } else {
        if (j % 2 == 0) {
          a[i][j] = 0;
        } else {
          a[i][j] = k;
          k++;
		}
	  }
	}
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] < 10) {
        cout << "   " << a[i][j];
      } else if (a[i][j] < 100) {
        cout << "  " << a[i][j];
      } else {
        cout << " " << a[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}