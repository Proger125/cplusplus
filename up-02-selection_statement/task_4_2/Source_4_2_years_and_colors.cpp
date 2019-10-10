#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int n;
  cout << "Введите год = ";
  cin >> n;
  if (n >= 1984)
    n = (n - 1984) % 60;
  else
    n = 60 - (abs(n - 1984) % 60);
  int y = n / 12;
  int x = n % 12;
  switch (y) {
    case 0: {
      cout << "Год зелён";
      break;
    }
    case 1: {
      cout << "Год красн";
      break;
    }
    case 2: {
      cout << "Год жёлт";
      break;
    }
    case 3: {
      cout << "Год бел";
      break;
    }
    case 4: {
      cout << "Год чёрн";
      break;
    }
  }
  switch (x) {
    case 0: {
      cout << "ой крысы";
      break;
    }
    case 1: {
      cout << "ой коровы";
      break;
    }
    case 2: {
      cout << "ого тигра";
      break;
    }
    case 3: {
      cout << "ого зайца";
      break;
    }
    case 4: {
      cout << "ого дракона";
      break;
    }
    case 5: {
      cout << "ой змеи";
      break;
    }
    case 6: {
      cout << "ой лошади";
      break;
    }
    case 7: {
      cout << "ой овцы";
      break;
    }
    case 8: {
      cout << "ой обезьяны";
      break;
    }
    case 9: {
      cout << "ой курицы";
      break;
    }
    case 10: {
      cout << "ой собаки";
      break;
    }
    case 11: {
      cout << "ой свиньи";
      break;
    }
  }
  cout << endl;
  system("pause");
  return 0;
}