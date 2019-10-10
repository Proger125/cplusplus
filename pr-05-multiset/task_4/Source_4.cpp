#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<pair<string, string> > v;
  ifstream fin("file.txt");
  while (!fin.eof()) {
    string s, subs;
    fin >> s;
    fin >> subs;
    v.push_back(make_pair(s, subs));
  }
  for (int i = 0; i < v.size(); i++) {
    int k = -1;
    for (int j = 0; j < v[i].first.size(); j++) {
      if (v[i].second == v[i].first.substr(j, v[i].second.size())) {
        k = j;
        break;
      }
    }
    if (k != -1) {
      cout << "Yes. Position of it = " << k << endl;
    } else {
      cout << "No. Position of it = " << k << endl;
	}
  }
  fin.close();
  system("pause");
  return 0;
}