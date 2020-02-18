#include "NumberStream.h"
void NumberStream::write(int a ) {
  stringstream strings;
  strings << a;
  string s = strings.str();
  for (int i = 0; i < s.size(); i++) {
    SimpleStream::put(s[i]);
  }
}
int NumberStream::read() {
  char c = SimpleStream::get();
  int answer = 0;
  while (c >= '0' && c <= '9') {
    answer = answer * 10 + (c - '0');
    c = SimpleStream::get();
  }
  return answer;
}
