#include "NumberStream.h"
#include "SimpleStream.h"

int main() {
  SimpleStream example("abcdef", 5);
  cout << example.isEnd() << endl;
  cout << example.peek() << endl;
  example.setPosition(1);
  example.clearTillPosition();
  example.setPosition(2);
  example.clear();
  cout << example.isEnd();
  system("pause");
  return 0;
}