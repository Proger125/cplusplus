#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

void is_clear(string &s) {
  if (s[s.length() - 1] == ',' || s[s.length() - 1] == '.' ||
      s[s.length() - 1] == '!' || s[s.length() - 1] == '?' ||
      s[s.length() - 1] == ':' || s[s.length() - 1] == ';' ||
      s[s.length() - 1] == ')' || s[s.length() - 1] == '(') {
    s = s.substr(0, s.length() - 1);
  }
  if (s[0] == ',' || s[0] == '.' || s[0] == '!' || s[0] == '?' || s[0] == ':' ||
      s[0] == ';' || s[0] == ')' || s[0] == '(') {
    s = s.substr(1, s.length() - 1);
  }
  transform(s.begin(), s.end(), s.begin(), tolower);
}
int main() {
  ifstream fin("file.txt");
  map<string, int> dict;
  string s;
  while (!fin.eof()) {
    fin >> s;
    is_clear(s);
    if (dict.find(s) == dict.end()) {
      dict.insert(pair<string, int>(s, 1));
    } else {
      dict.at(s)++;
    }
  }
  for (auto it = dict.begin(); it != dict.end(); ++it) {
    cout << it->first << " : " << it->second << endl;
  }
  fin.close();
  system("pause");
  return 0;
}