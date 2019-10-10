#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>

using namespace std;
void InputSet(multiset<int> &Myset) {
  ifstream fin("input.txt");
  while (!fin.eof()) {
    int k;
    fin >> k;
    Myset.insert(k);
  }
  fin.close();
}
void Function(multiset<int> &Myset) {
  int size = Myset.size();
  for (int i = 0; i < Myset.size(); i++) {
    int min_element_1 = *Myset.begin();
    Myset.erase(Myset.begin());
    int min_element_2 = *Myset.begin();
    Myset.erase(Myset.begin());
    Myset.insert(min_element_1 + min_element_2);
  }
}
int main() {
  multiset<int> Myset;
  InputSet(Myset);
  Function(Myset);
  for (auto i : Myset) {
    cout << i << endl;
  }
  system("pause");
  return 0;
}