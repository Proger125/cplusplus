#pragma once
#include <fstream>
#include <utility>
#include <vector>
#include "SimpleStream.h"
#include "NumberStream.h"

using Table = vector < pair < string, int >>;

class ReadWrite {
 public:
  Table Read(string file);
  void Write(string file, const Table&);
};