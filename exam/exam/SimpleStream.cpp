#include "SimpleStream.h"
bool SimpleStream::isEnd() const {
  if (position == str.size()) {
    return true;
  }
  return false;
}
char SimpleStream::peek() const { return str[position]; }
void SimpleStream::setPosition(size_t pos) {
  try {
    if (pos > str.size() || pos < 0) {
      throw out_of_range("Your position is very very big");
    } else {
      position = pos;
    }
  } catch (out_of_range) {
    position = str.size() - 1;
  }
}
SimpleStream& SimpleStream::put(char c) {
  str[position] = c;
  position++;
  return *this;
}
SimpleStream& SimpleStream::get(char& c) {
  if (isEnd()) {
    c = '\0';
  } else {
    c = str[position];
    position++;
  }
  return *this;
}
char SimpleStream::get() {
  if (isEnd()) {
    return '\0';
  } else {
    position++;
    return str[position - 1];
  }
}
void SimpleStream::clear() {
  str.clear();
  position = 0;
}
void SimpleStream::clearTillPosition() {
  if (isEnd()) {
    position = 0;
    str = "";
  } else {
    string s;
    for (int i = position; i < str.size(); i++) {
      s += str[i];
    }
    position = 0;
    str = s;
  }
}
SimpleStream& SimpleStream::unget() {
  try {
    if (position == 0) {
      throw out_of_range("You can't putback, because your position = 0");
    }
  } catch (out_of_range) {
    return *this;
  }
  position--;
  return *this;
}
SimpleStream& SimpleStream::putback(char c) {
  try {
    if (position == 0) {
      throw out_of_range("You can't putback, because your position = 0");
    }
  } catch (out_of_range) {
    return *this;
  }
  position--;
  str[position] = c;
  return *this;
}
ostream& operator<<(ostream& out, SimpleStream& stream) {
  if (stream.isEnd()) {
    return out;
  }
	for (int i = stream.position; i <= stream.str.size(); i++) {
    out << stream.str[i];
	}
	return out;
}
istream& operator>>(istream& in, SimpleStream& stream) {
  string s;
  in >> s;
  stream.str += s;
  stream.position += s.size();
  return in;
}