#include <Windows.h>
#include <iostream>
using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int n;
  cout << "Enter n = ";
  cin >> n;
  int a, b, c;
  a = n / 100;
  b = (n / 10) % 10;
  c = n % 10;
  int k = 0;
  switch (a) {
    case 1: {
      cout << "���";
      break;
    }
    case 2: {
      cout << "������";
      break;
    }
    case 3: {
      cout << "������";
      break;
    }
    case 4: {
      cout << "���������";
      break;
    }
    case 5: {
      cout << "�������";
      break;
    }
    case 6: {
      cout << "��������";
      break;
    }
    case 7: {
      cout << "������";
      break;
    }
    case 8: {
      cout << "��������";
      break;
    }
    case 9: {
      cout << "���������";
      break;
    }
  }
  cout << " ";
  switch (b) {
    case 1: {
      k = 1;
      switch (c) {
        case 1: {
          cout << "�����������";
          break;
        }
        case 2: {
          cout << "����������";
          break;
        }
        case 3: {
          cout << "����������";
          break;
        }
        case 4: {
          cout << "������������";
          break;
        }
        case 5: {
          cout << "����������";
          break;
        }
        case 6: {
          cout << "�����������";
          break;
        }
        case 7: {
          cout << "����������";
          break;
        }
        case 8: {
          cout << "������������";
          break;
        }
        case 9: {
          cout << "������������";
          break;
        }
      }
      break;
    }
    case 2: {
      cout << "��������";
      break;
    }
    case 3: {
      cout << "��������";
      break;
    }
    case 4: {
      cout << "�����";
      break;
    }
    case 5: {
      cout << "���������";
      break;
    }
    case 6: {
      cout << "����������";
      break;
    }
    case 7: {
      cout << "��������";
      break;
    }
    case 8: {
      cout << "����������";
      break;
    }
    case 9: {
      cout << "���������";
      break;
    }
  }
  cout << " ";
  if (k == 0) {
    switch (c) {
      case 2: {
        cout << "���";
        break;
      }
      case 3: {
        cout << "���";
        break;
      }
      case 4: {
        cout << "������";
        break;
      }
      case 5: {
        cout << "����";
        break;
      }
      case 6: {
        cout << "�����";
        break;
      }
      case 7: {
        cout << "���";
        break;
      }
      case 8: {
        cout << "�����";
        break;
      }
      case 9: {
        cout << "������";
        break;
      }
    }
  }
  cout << endl;
  system("pause");
  return 0;
}