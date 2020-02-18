#include "MyString.h"
MyString::MyString() { str = (char*)""; }
MyString::MyString(const char* new_str) { str = (char*)new_str; }
void MyString::Output() {
  int i = 0;
  while (str[i]) {
    cout << str[i];
    i++;
  }
  cout << endl;
}
char* MyString::Strchr(char c) {
  int i = 0;
  while (str[i] && str[i] != c) ++i;
  return c == str[i] ? (char*)str + i : NULL;
}
void MyString::Condense() {
  int i = 0;
  int j = 0;
  char* new_str = (char*)malloc(sizeof(char) * strlen(str));
  if (str[0] != ' ') {
    new_str[j] = str[i];
    j++;
  }
  for (int i = 1; i < strlen(str) - 1; i++) {
    if (str[i] != ' ') {
      new_str[j] = str[i];
      j++;
    }
    if (str[i] == ' ' && str[i - 1] != ' ' && str[i + 1] != ' ') {
      new_str[j] = str[i];
      j++;
    }
    if (str[i - 1] == ' ' && str[i] != ' ' && str[i + 1] == ' ') {
      new_str[j] = str[i];
      j++;
    }
    if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] != ' ') {
      new_str[j] = str[i];
      j++;
    }
  }
  if (str[strlen(str) - 1] != ' ') {
    new_str[j] = str[i];
    j++;
  }
  new_str[j] = '\0';
  str = new_str;
}
char* MyString::Substr(char* str, int start, int length) {
  char* s;
  int len = 0;
  for (int i = 0; str[i] != '\0'; i++) len++;
  if (length > 0) {
    if (start + length < len) len = start + length;
  } else
    len = len + length;
  int newlen = len - start + 1;
  s = new char[newlen];
  int j = 0;
  for (int i = start; i < len; i++) {
    s[j] = str[i];
    j++;
  }
  s[j] = '\0';
  return (s);
}
void MyString::DeleteWord(const char* word) {
  int length = strlen(word);
  int i = 0;
  int j = 0;
  char* new_str = (char*)malloc(sizeof(char) * strlen(str));
  while (i < strlen(str)) {
    char* substr = Substr(str, i, length);
    if (*substr == *word) {
      i += length - 1;
    } else {
      new_str[j] = str[i];
      j++;
    }
    i++;
  }
  new_str[j] = '\0';
  str = new_str;
}
char* MyString::ReverseWords() {
  vector<char*> v;
  char* result = (char*)malloc(sizeof(char) * strlen(str));
  int i = 0;
  while (i < strlen(str)) {
    if (str[i] == ' ' || i == 0) {
      char* word = (char*)malloc(sizeof(char) * strlen(str));
      int j = 0;
      if (i != 0) {
        i++;
      }
      while ((str[i] != ' ' || i == strlen(str) - 1) && str[i]) {
        word[j] = str[i];
        i++;
        j++;
      }
      word[j] = '\0';
      v.push_back(word);
      i--;
    }
    i++;
  }
  int k = 0;
  for (i = 0; i < v.size(); i++) {
    for (int j = strlen(v[i]) - 1; j >= 0; j--) {
      result[k] = v[i][j];
      k++;
    }
    result[k] = ' ';
    k++;
  }
  k--;
  result[k] = '\0';
  return result;
}
char* MyString::TheLongestWord() {
  vector<char*> v;
  char* result = (char*)malloc(sizeof(char) * strlen(str));
  int i = 0;
  while (i < strlen(str)) {
    if (str[i] == ' ' || i == 0) {
      char* word = (char*)malloc(sizeof(char) * strlen(str));
      int j = 0;
      if (i != 0) {
        i++;
      }
      while ((str[i] != ' ' || i == strlen(str) - 1) && str[i]) {
        word[j] = str[i];
        i++;
        j++;
      }
      word[j] = '\0';
      v.push_back(word);
      i--;
    }
    i++;
  }
  int size = 0;
  int size_i = 0;
  for (i = 0; i < v.size(); i++) {
    if (strlen(v[i]) > size) {
      size = strlen(v[i]);
      size_i = i;
    }
  }
  return v[size_i];
}
void MyString::OutputComments() {
  int i = 0;
  while (i < strlen(str)) {
    char* comment = (char*)malloc(sizeof(char) * strlen(str));
    int j = 0;
    if (str[i] == '/' && str[i + 1] == '/') {
      i += 2;
      while (str[i] != '\n') {
        if ((str[i] == '/' || str[i] == ' ') && j == 0) {
          i++;
        } else {
          comment[j] = str[i];
          j++;
          i++;
        }
      }
    }
    comment[j] = '\0';
    cout << comment << endl;
    i += 2;
  }
}
void MyString::ChangeSubStr(const char* str1, const char* str2) {
  int length1 = strlen(str1);
  int length2 = strlen(str2);
  int i = 0;
  int j = 0;
  char* new_str = (char*)malloc(sizeof(char) * strlen(str));
  while (i < strlen(str)) {
    char* substr = Substr(str, i, length1);
    if (*substr == *str1) {
      int k = 0;
      while (k < length2) {
        new_str[j] = str2[k];
        j++;
        k++;
	  }
      i += length1 - 1;
    } else {
      new_str[j] = str[i];
      j++;
    }
    i++;
  }
  new_str[j] = '\0';
  str = new_str;
}