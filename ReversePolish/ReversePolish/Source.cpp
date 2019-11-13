#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
bool IsDigit(char c) {
  if ((c <= '9' && c >= '0') || c == '.') {
    return true;
  }
  return false;
}
int main() {
  vector<string> v1;
  vector<string> v2;
  string str = "12+45.1*13";
  string str2 = "";
  string str3 = "";
  for (int i = 0; i < str.size(); i++) {
    if (IsDigit(str[i])) {
      str2 += str[i];
      v2.push_back(str3);
      str3 = "";
    } else {
      v1.push_back(str2);
      str2 = "";
      str3 += str[i];
    }
    if (i == str.size() - 1) {
      v1.push_back(str2);
    }
  }
  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << endl;
  }
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << endl;
  }
  system("pause");
  return 0;
}