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
      cout << "Сто";
      break;
    }
    case 2: {
      cout << "Двести";
      break;
    }
    case 3: {
      cout << "Триста";
      break;
    }
    case 4: {
      cout << "Четыреста";
      break;
    }
    case 5: {
      cout << "Пятьсот";
      break;
    }
    case 6: {
      cout << "Шестьсот";
      break;
    }
    case 7: {
      cout << "Семсот";
      break;
    }
    case 8: {
      cout << "Восемсот";
      break;
    }
    case 9: {
      cout << "Девятьсот";
      break;
    }
  }
  cout << " ";
  switch (b) {
    case 1: {
      k = 1;
      switch (c) {
        case 1: {
          cout << "Одиннадцать";
          break;
        }
        case 2: {
          cout << "Двенадцать";
          break;
        }
        case 3: {
          cout << "Тринадцать";
          break;
        }
        case 4: {
          cout << "Четырнадцать";
          break;
        }
        case 5: {
          cout << "Пятнадцать";
          break;
        }
        case 6: {
          cout << "Шестнадцать";
          break;
        }
        case 7: {
          cout << "Семнадцать";
          break;
        }
        case 8: {
          cout << "Восемнадцать";
          break;
        }
        case 9: {
          cout << "Девятнадцать";
          break;
        }
      }
      break;
    }
    case 2: {
      cout << "Двадцать";
      break;
    }
    case 3: {
      cout << "Тридцать";
      break;
    }
    case 4: {
      cout << "Сорок";
      break;
    }
    case 5: {
      cout << "Пятьдесят";
      break;
    }
    case 6: {
      cout << "Шестьдесят";
      break;
    }
    case 7: {
      cout << "Семдесят";
      break;
    }
    case 8: {
      cout << "Восемдесят";
      break;
    }
    case 9: {
      cout << "Девяноста";
      break;
    }
  }
  cout << " ";
  if (k == 0) {
    switch (c) {
      case 2: {
        cout << "Два";
        break;
      }
      case 3: {
        cout << "Три";
        break;
      }
      case 4: {
        cout << "Четыре";
        break;
      }
      case 5: {
        cout << "Пять";
        break;
      }
      case 6: {
        cout << "Шесть";
        break;
      }
      case 7: {
        cout << "Сем";
        break;
      }
      case 8: {
        cout << "Восем";
        break;
      }
      case 9: {
        cout << "Девять";
        break;
      }
    }
  }
  cout << endl;
  system("pause");
  return 0;
}