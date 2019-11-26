#include <iostream>
#include "StackOnArray.h"
#include "StackOnList.h"
using namespace std;
int main() {
  stackInList<int> stack1;
  stackInList<int> stack2;
  for (int i = 0; i < 10; i++) {
    stack1.push(i);
    stack2.push(i+1);
  }
  if (stack1 == stack2) {
    cout << 1;
  }
  while (stack1.size() != 0) {
    cout << stack1.top() << endl;
    int k = stack1.pop();
  }
  system("pause");
  return 0;
}