#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}
int countDays(int month, bool IsV) {
  switch (month) {
    case 1: {
      return 31;
    }
    case 2: {
      if (IsV) {
        return 29;
      }
      return 28;
    }
    case 3: {
      return 31;
    }
    case 4: {
      return 30;
    }
    case 5: {
      return 31;
    }
    case 6: {
      return 30;
    }
    case 7: {
      return 31;
    }
    case 8: {
      return 31;
    }
    case 9: {
      return 30;
    }
    case 10: {
      return 31;
    }
    case 11: {
      return 30;
    }
    case 12: {
      return 31;
    }
  }
}
int main() {
  bool IsV;
  cin >> IsV;
  int k, sum_f = 0, sum_m = 0;
  cin >> k;
  vector<pair<int, int> > v;
  vector<int> points;
  for (int i = 0; i < k; i++) {
    int date, month;
    char slash;
    cin >> date >> slash >> month;
    v.push_back(make_pair(date, month));
  }
  sort(v.begin(), v.end(), comp);
  int n = 1;
  for (int i = 0; i < k - 1; i++) {
    if (v[i + 1].first - v[i].first == 1 ||
        (v[i].first == countDays(v[i].second, IsV) && v[i + 1].first == 1 &&
         v[i + 1].second - v[i].second == 1)) {
      n++;
    } else {
      points.push_back(n);
      n = 1;
    }
    if (n == 5) {
      points.push_back(n);
      n = 1;
    }
    if (i == k - 2) {
      points.push_back(n);
      n = 1;
    }
  }
  for (int i = 0; i < points.size(); i++) {
    switch (points[i]) {
      case 1: {
        sum_f += 1000;
        break;
      }
      case 2: {
        sum_f += 6000;
        break;
      }
      case 3: {
        sum_f += 9000;
        break;
      }
      case 4: {
        sum_f += 12000;
        break;
      }
      case 5: {
        sum_f += 12000;
        sum_m += 3;
        break;
      }
    }
  }
  cout << sum_f << " " << sum_m << endl;
  system("pause");
  return 0;
}