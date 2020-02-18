#pragma once
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class SimpleStream {
 private:
  string str;
  size_t position = 0;

 public:
  SimpleStream() {
    str = "";
    position = 0;
  };
  SimpleStream(string str, size_t position) {
    this->str = str;
    this->position = position;
  }
  string getStr() { return str; }
  void setStr(string s) { str = s; }
  size_t getPos() { return position; }
  void setPos(size_t pos) { position = pos; }
  bool isEnd() const;
  char peek() const;
  void setPosition(size_t new_position);
  SimpleStream& put(char c);
  SimpleStream& get(char& c);
  char get();
  void clear();
  void clearTillPosition();
  SimpleStream& unget();
  SimpleStream& putback(char c);
  friend ostream& operator<<(ostream& out, SimpleStream& stream);
  friend istream& operator>>(istream& in, SimpleStream& stream);
};
