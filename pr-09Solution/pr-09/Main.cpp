#include <iostream>
#include "StackOnArray.h"
#include "StackOnList.h"
#include "ReversePolish.h"
#include "Calcule.h"
using namespace std;
int main() {
  //vector<string> v = ToReversePolish();
  //cout << CalculateReversePolish(v) << endl;
  string str = "4";
  vector<string> v = ToReversePolishForm(str);
  cout << CalculateForm(v);
  system("pause");
  return 0;
}