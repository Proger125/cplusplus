#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int n;
  cout << "������� ��� = ";
  cin >> n;
  if (n >= 1984)
    n = (n - 1984) % 60;
  else
    n = 60 - (abs(n - 1984) % 60);
  int y = n / 12;
  int x = n % 12;
  switch (y) {
    case 0: {
      cout << "��� ����";
      break;
    }
    case 1: {
      cout << "��� �����";
      break;
    }
    case 2: {
      cout << "��� ���";
      break;
    }
    case 3: {
      cout << "��� ���";
      break;
    }
    case 4: {
      cout << "��� ����";
      break;
    }
  }
  switch (x) {
    case 0: {
      cout << "�� �����";
      break;
    }
    case 1: {
      cout << "�� ������";
      break;
    }
    case 2: {
      cout << "��� �����";
      break;
    }
    case 3: {
      cout << "��� �����";
      break;
    }
    case 4: {
      cout << "��� �������";
      break;
    }
    case 5: {
      cout << "�� ����";
      break;
    }
    case 6: {
      cout << "�� ������";
      break;
    }
    case 7: {
      cout << "�� ����";
      break;
    }
    case 8: {
      cout << "�� ��������";
      break;
    }
    case 9: {
      cout << "�� ������";
      break;
    }
    case 10: {
      cout << "�� ������";
      break;
    }
    case 11: {
      cout << "�� ������";
      break;
    }
  }
  cout << endl;
  system("pause");
  return 0;
}