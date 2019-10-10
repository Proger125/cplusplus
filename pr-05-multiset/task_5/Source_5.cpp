#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;
void InputSet(multiset<int> &set) {
  ifstream fin("input.txt");
  while (!fin.eof()) {
    int k;
    fin >> k;
    set.insert(k);
  }
  fin.close();
}
void InputCommands(multimap<string, int> &map) {
  ifstream fin("commands.txt");
  while (!fin.eof()) {
    string s;
    int k;
    fin >> s;
    if (s != "find_min") {
      fin >> k;
    }
    map.insert(pair<string, int>(s, k));
  }
  fin.close();
}
void RealizationCommands(multiset<int> &set, multimap<string, int> &map) {
  for (auto it = map.begin(); it != map.end(); ++it) {
    if (it->first == "add") {
      cout << "We enter the " << it->second << " in your set" << endl;
      set.insert(it->second);
    } else if (it->first == "delete") {
      cout << "We delete " << it->second << " from your set" << endl;
      set.erase(it->second);
    } else if (it->first == "find_min") {
      cout << "The min element of set = " << *set.begin() << endl;
    } else if (it->first == "is_exist") {
      if (set.find(it->second) != set.end()) {
        cout << "Your element "<< it->second << " exists" << endl;
      } else {
        cout << "Your element "<< it->second <<" doesn't exist" << endl;
	  }
	}
  }
}
int main() {
  multiset<int> Myset;
  multimap<string, int> Mymap;
  InputSet(Myset);
  InputCommands(Mymap);
  RealizationCommands(Myset, Mymap);
  for (auto i : Myset) {
    cout << i << " ";
  }
  system("pause");
  return 0;
}