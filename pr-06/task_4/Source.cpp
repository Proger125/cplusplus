#include "Function.h"

int main() {
  vector<Date> v;
  InputVector(v);
  for (int i = 0; i < v.size(); i++) {
    cout << "The next day of " << v[i].day << " " << v[i].month << " "
         << v[i].year << endl;
    cout << v[i].NextDay().day << " " << v[i].NextDay().month << " "
         << v[i].NextDay().year << endl;
  }
  for (int i = 0; i < v.size() - 1; i++) {
    cout << "The duration between two dates = " << v[i].Duration(v[i + 1])
         << endl;
  }
  system("pause");
  return 0;
}