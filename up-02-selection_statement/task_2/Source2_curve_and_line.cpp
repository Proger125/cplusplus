#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double a, b, c, d;
  double f, g;
  cout << "Enter parametres of the curve line";
  cout << "Enter a, b, c, d" << endl;
  cin >> a >> b >> c >> d;
  cout << "Enter parametres of the line";
  cout << "Enter f and g" << endl;
  cin >> f >> g;
  c = c - f;
  d = d - g;
  for (int x = -30000; x < 30001; x++) {
    if (a * x * x * x + b * x * x + c * x + d == 0) {
      cout << "The point of intersection: x = " << x << " y = " << f * x + g
           << endl;
    }
  }
  system("pause");
  return 0;
}