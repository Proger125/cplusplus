#include <iostream>
#include <cmath>

using namespace std;

double lapow(double x, int n) {
  double value = 1;
  for (int i = 0; i < n; i++) {
    value *= x;
  }
  return value;
}

int main() {
  double x;
  double eps;
  cout << "Enter x in interval from -1 to 1 = ";
  cin >> x;
  cout << "Enter Eps = ";
  cin >> eps;
  double value = 1, interm_value = 1./2;
  int i = 1, k = 3;
  double sec_value = 1;
  while (abs(sec_value) > eps) {
    sec_value = interm_value * lapow(x, i) * lapow(-1, i);
    value += sec_value;
    interm_value = interm_value * k;
    k++;
    interm_value = interm_value / k;
    k++;
    i++;
  }
  cout << value << endl;
  system("pause");
  return 0;
}