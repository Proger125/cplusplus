#pragma once
#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <regex>

using namespace std;

class MyString {
 private:
  char* str;
 public:
  MyString();
  MyString(const char* str);
  char* Strchr(char c);
  char* Substr(char* str, int start, int length);
  void Condense();
  void DeleteWord(const char* word);
  char* TheLongestWord();
  char* ReverseWords();
  void OutputComments();
  void ChangeSubStr(const char* str1, const char* str2);
  void Output();
};
