#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void InputVector(vector<pair<int, int> > &v) {
  ifstream fin("input.txt");
  while (!fin.eof()) {
    int index, seconds;
    fin >> index >> seconds;
    v.push_back(make_pair(index, seconds));
  }
  fin.close();
}
int main() {
  vector<pair<int, int> > v;
  int k;
  cout << "Enter k first realizations = ";
  cin >> k;
  InputVector(v);
  int j = v.size();
  int seconds = 1;
  if (k < v.size()) {
    for (int i = 0; i < k; i++) {
      cout << "Realization of task: " << v[i].first << " on 0 second" << endl;
    }
  } else {
    for (int i = 0; i < v.size(); i++) {
      cout << "Realization of task: " << v[i].first << " on 0 second" << endl;
    }
    while (j < k) {
      for (int i = 0; i < v.size(); i++) {
        if (seconds % v[i].second == 0) {
          cout << "Realization of task: " << v[i].first << " on " << seconds << " second" << endl;
          j++;
        }
      }
      seconds++;
    }
  }
  system("pause");
  return 0;
}