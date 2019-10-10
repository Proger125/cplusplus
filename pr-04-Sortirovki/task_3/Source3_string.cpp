#include "functions.h"

int main() {
  string a;
  int start, end;
  InputString(a);
  InputParametres(start, end);
  if (is_sym_rec(a, start, end)) {
    cout << "Your substring is symetric" << endl;
  } else {
    cout << "Your substring is't symetric" << endl;
  }
  system("pause");
  return 0;
}