#include <Windows.h>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  char c;
  cout << "������� ����������� �����������" << endl;
  cin >> c;
  int n1, n2;
  cout << "������� ��� ����� - ��������� ��� �������" << endl;
  cin >> n1 >> n2;
  int n = n1 + n2;
  switch (c) {
    case '�': {
      if (n == 0) {
        cout << "�" << endl;
      } else if (n == 1) {
        cout << "�" << endl;
      } else if (n == 2 || n == -2) {
        cout << "�" << endl;
      } else if (n == 3 || n == -1) {
        cout << "�" << endl;
      }
      break;
    }
    case '�': {
      if (n == 0) {
        cout << "�" << endl;
      } else if (n == 1) {
        cout << "�" << endl;
      } else if (n == 2 || n == -2) {
        cout << "�" << endl;
      } else if (n == 3 || n == -1) {
        cout << "�" << endl;
      }
      break;
    }
    case '�': {
      if (n == 0) {
        cout << "�" << endl;
      } else if (n == 1) {
        cout << "�" << endl;
      } else if (n == 2 || n == -2) {
        cout << "�" << endl;
      } else if (n == 3 || n == -1) {
        cout << "�" << endl;
      }
      break;
    }
    case '�': {
      if (n == 0) {
        cout << "�" << endl;
      } else if (n == 1) {
        cout << "�" << endl;
      } else if (n == 2 || n == -2) {
        cout << "�" << endl;
      } else if (n == 3 || n == -1) {
        cout << "�" << endl;
      }
      break;
    }
  }
  system("pause");
  return 0;
}