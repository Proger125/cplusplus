#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  ifstream fin("file.txt");
  set<string> s;
  int count = 0;
  while (!fin.eof()) {
    string str;
    getline(fin,str);
    s.insert(str);
  }
  for (auto i : s) {
    count++;
  }
  cout << "The amount of different strings = " << count << endl;
  fin.close();
  system("pause");
  return 0;
}