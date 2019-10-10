#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cctype>

using namespace std;

void InputMap(map<string, set<string> > &Mymap) {
  ifstream fin("input.txt");
  while (!fin.eof()) {
    string street, surname;
    fin >> street;
    fin >> surname;
    if (Mymap.find(street) == Mymap.end()) {
      Mymap.insert(make_pair(street, set<string>{surname}));
    } else {
      Mymap.find(street)->second.insert(surname);
	}
  }
  fin.close();
}

int main() {
  map <string, set<string> > Mymap;
  InputMap(Mymap);
  for (auto& it : Mymap) {
    cout << "On the street " << it.first << " live those people: " << endl;
	for (auto i : it.second) {
      cout << i << endl;
	}
  }
  system("pause");
  return 0;
}