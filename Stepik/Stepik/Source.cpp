#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  map<string, string> m1;
  map<string, string> m2;
  string word;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string first = "", second = "";
    cin >> first >> second;
    m1.insert(make_pair(first, second));
    m2.insert(make_pair(second, first));
  }
  cin >> word;
  if (m1[word] == "") {
    cout << m2[word];
  } else {
    cout << m1[word];
  }
  return 0;
}