#pragma once
#include "SimpleStream.h"
class NumberStream : public SimpleStream {
 public:
  NumberStream() { this->clear();};
  void write(int a);
  int read();
  NumberStream& operator<<(int num) {
    write(num);
    return *this;
  }

  NumberStream& operator<<(string st) {
    for (size_t i = 0; i < st.size(); i++) {
      SimpleStream::put(st[i]);
    }
    return *this;
  }
};
