#include "MyString.h"

int main() {
  MyString str("asdfghjkl");
  str.ChangeSubStr("asd", "dsa");
  str.Output();
  system("pause");
  return 0;
}