#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct ThreeBytes {
  string first;
  string second;
  string third;
  string result;
};
string FromHexToBin(string s) {
  string result = "";
  for (int i = 0; i < s.size(); i++) {
    switch (s[i]) {
      case '0': {
        result += "0000";
        break;
	  }
      case '1': {
        result += "0001";
        break;
      }
      case '2': {
        result += "0010";
        break;
      }
      case '3': {
        result += "0011";
        break;
      }
      case '4': {
        result += "0100";
        break;
      }
      case '5': {
        result += "0101";
        break;
      }
      case '6': {
        result += "0110";
        break;
      }
      case '7': {
        result += "0111";
        break;
      }
      case '8': {
        result += "1000";
        break;
      }
      case '9': {
        result += "1001";
        break;
      }
      case 'A': {
        result += "1010";
        break;
      }
      case 'B': {
        result += "1011";
        break;
      }
      case 'C': {
        result += "1100";
        break;
      }
      case 'D': {
        result += "1101";
        break;
      }
      case 'E': {
        result += "1110";
        break;
      }
      case 'F': {
        result += "1111";
        break;
      }
    }
  }
  return result;
}
int FromBinToDec(string s) {
  int result = 0;
  int deg = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '1') {
      result += pow(2, deg);
    }
    deg++;
  }
  return result;
}
int main() {
  string chars =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  int n;
  vector<string> hex;
  vector<ThreeBytes> bin;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string buf = "";
    cin >> buf;
    hex.push_back(buf);
  }
  int i = 0;
  while (i < n) {
    ThreeBytes val;
    val.first = FromHexToBin(hex[i]);
    i++;
    if (i == n) {
      val.result += val.first;
      val.result += "0000";
      bin.push_back(val);
      break;
    }
    val.second = FromHexToBin(hex[i]);
    i++;
    if (i == n) {
      val.result += val.first;
      val.result == val.second;
      val.result += "00";
      bin.push_back(val);
      break;
    }
    val.third = FromHexToBin(hex[i]);
    val.result += val.first;
    val.result += val.second;
    val.result += val.third;
    bin.push_back(val);
    i++;
  }
  for (int j = 0; j < bin.size(); j++) {
    if (bin[j].result.size() == 12) {
      string first = bin[j].result.substr(0, 6);
      cout << chars[FromBinToDec(first)];
      string second = bin[j].result.substr(6, 6);
      cout << chars[FromBinToDec(second)];
      cout << "==";
    }
    if (bin[j].result.size() == 18) {
      string first = bin[j].result.substr(0, 6);
      cout << chars[FromBinToDec(first)];
      string second = bin[j].result.substr(6, 6);
      cout << chars[FromBinToDec(second)];
      string third = bin[j].result.substr(12, 6);
      cout << chars[FromBinToDec(third)];
      cout << "=";
    }
    if (bin[j].result.size() == 24) {
      string first = bin[j].result.substr(0, 6);
      cout << chars[FromBinToDec(first)];
      string second = bin[j].result.substr(6, 6);
      cout << chars[FromBinToDec(second)];
      string third = bin[j].result.substr(12, 6);
      cout << chars[FromBinToDec(third)];
      string fourth = bin[j].result.substr(18, 6);
      cout << chars[FromBinToDec(fourth)];
    }
  }
  cout << endl;
  system("pause");
  return 0;
}