#include <Windows.h>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  char c;
  cout << "Введите изначальное направление" << endl;
  cin >> c;
  int n1, n2;
  cout << "Введите два числа - посланные ему команды" << endl;
  cin >> n1 >> n2;
  int n = n1 + n2;
  switch (c) {
    case 'С': {
      if (n == 0) {
        cout << "С" << endl;
      } else if (n == 1) {
        cout << "З" << endl;
      } else if (n == 2 || n == -2) {
        cout << "Ю" << endl;
      } else if (n == 3 || n == -1) {
        cout << "В" << endl;
      }
      break;
    }
    case 'З': {
      if (n == 0) {
        cout << "З" << endl;
      } else if (n == 1) {
        cout << "Ю" << endl;
      } else if (n == 2 || n == -2) {
        cout << "В" << endl;
      } else if (n == 3 || n == -1) {
        cout << "С" << endl;
      }
      break;
    }
    case 'Ю': {
      if (n == 0) {
        cout << "Ю" << endl;
      } else if (n == 1) {
        cout << "В" << endl;
      } else if (n == 2 || n == -2) {
        cout << "С" << endl;
      } else if (n == 3 || n == -1) {
        cout << "З" << endl;
      }
      break;
    }
    case 'В': {
      if (n == 0) {
        cout << "В" << endl;
      } else if (n == 1) {
        cout << "С" << endl;
      } else if (n == 2 || n == -2) {
        cout << "З" << endl;
      } else if (n == 3 || n == -1) {
        cout << "Ю" << endl;
      }
      break;
    }
  }
  system("pause");
  return 0;
}