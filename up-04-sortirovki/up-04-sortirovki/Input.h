#pragma once
#ifdef INPUT_H
#endif  // INPUT_H
#include <Windows.h>
#include <cstdlib>'
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string route;
int amount_i;
void InputFile() {
  srand(NULL);
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  string type, amount;
  cout << "������� ��� �������������� �����:" << endl;
  cout << "��� �������������� �� ����������� ������� ASC" << endl;
  cout << "��� �������������� �� �������� ������� DESC" << endl;
  cout << "��� �������������� �������� ������� RAND" << endl;
  getline(cin, type);
  cout << "�������� ���������� ���������: 10, 100, 1000, 10000 " << endl;
  getline(cin, amount);
  cout << "������� ������ ���������� = ";
  int start;
  cin >> start;
  cout << "������� ����� ���������� = ";
  int end;
  cin >> end;
  route = type + "/" + amount + "_elements.txt";
  ofstream fout(route);
  amount_i = stoi(amount);
  if (amount_i == end - start) {
    if (type == "ASC") {
      for (int i = start; i < end; i++) {
        fout << i << endl;
      }
    } else if (type == "DESC") {
      for (int i = end; i > start; i--) {
        fout << i << " ";
      }
    } else if (type == "RAND") {
      for (int i = 0; i < amount_i; i++) {
        fout << rand() % (end-start) +start << " ";
      }
    } else {
      cout << "�� ����� ������������ ���������";
      exit(0);
    }
  } else {
    cout << "��������� ���������� ��������� �����������";
    exit(0);
  }
  cin.clear();
  fout.close();
}
template <typename T>
void InputVector(vector<T>& a) {
  ifstream fin(route);
  if (fin.is_open()) {
    int i = 0;
    while (i < amount_i) {
      T k;
      fin >> k;
      a.push_back(k);
      i++;
    }
  } else {
    cout << "File wasn't open";
  }
  fin.close();
}
void ChooseSort(int& n) {
  cout << "��� ������������� ���������� ��������� ������� 1" << endl;
  cout << "��� ������������� ���������� ����� ������� 2" << endl;
  cout << "��� ������������� ���������� ��������� ������� 3" << endl;
  cout << "��� ������������� ���������� ׸�-����� ������� 4" << endl;
  cout << "��� ������������� ��������� ������� 5" << endl;
  cout << "��� ������������� ���������� ��������� ������� 6" << endl;
  cout << "��� ������������� ���������� ������� ������� 7" << endl;
  cout << "��� ������������� ���������� ������������ ������� ������� 8" << endl;
  cin >> n;
}