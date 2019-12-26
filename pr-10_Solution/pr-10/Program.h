#pragma once
#include <algorithm>
#include <cmath>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
template <typename T>

class Main {
  static list<string> l;
  static deque<string> d;
  static vector<string> v;
  void Read(istream& in, vector<T>& container) {
    istream_iterator<string> start(in), end;
    copy(start, end, container);
  }
  void Copy(vector<T>& first, vector<T>& second) {
    copy(first.begin(), second.end());
  }
  void Sort(vector<T>& container, bool (*peridicate)(T, T)) {
    sort(container.begin(), container.end(), peridicate);
  }
  void Erase(vector<T>& container, int k, char c) {
    container.erase(remove_if(
        container.begin(), container.end(),
        [](T el) -> bool {
          if (el.size() < k) return false;
          return c == el.at(k);
        },
        container.end()));
  }
  int Count(vector<T>& container, char c) {
    return container.count_if([](T el) -> bool {
      for (auto value : el) {
        if (value == c) return true;
        return false;
      }
    });
  }
  int Count(vector<T>& container, string str) {
    return container.count_if([](T el) -> bool { return el > str; });
  }
  void Permutations(vector<T>& container) {
    do {
    } while (next_permutation(container.begin(), container.end()));
  }
  void Write(ostream& out, vector<T>& container) {
    ostream_iterator<T> i(out, ", ");
    copy(container.begin(), container.end(), i);
  }
  void RWrite(ostream& out, vector<T>& container) {
    ostream_iterator<T> i(out, ", ");
    copy(container.rbegin(), container.rend(), i);
  }
  static bool FProgram() { return 0; }
  class Route {
   public:
    pair<size_t, string> car;
    string name;
    size_t number;
    bool operator==(const Route new_route) const {
      if (this->car.first == new_route.car.first &&
          this->car.second == new_route.car.second &&
          this->name == new_route.name && this->number == new_route.number)
        return true;
      return false;
    }
    bool operator==(const Route& second) const {
      if (car.first == second.car.first &&
          car.second == second.car.second && name == second.name &&
          number == second.number)
        return true;
      return false;
    }
    bool operator==(Route& second) {
      if (car.first == second.car.first &&
          car.second == second.car.second && name == second.name &&
          number == second.number)
        return true;
      return false;
    }
    Route() {
      car = make_pair(0, "");
      name = "";
      number = 0;
    }
    Route(const Route& second) {
      car = second.car;
      name = second.name;
      number = second.number;
    }
    Route(const Route&& second) {
      car = second.car;
      name = second.name;
      number = second.number;
    }
    Route& operator=(const Route& second) {
      car = second.car;
      name = second.name;
      number = second.number;
      return *this;
    }
    Route& operator=(const Route&& second) {
      car = second.car;
      name = second.name;
      number = second.number;
      return *this;
    }
    Route(pair<size_t, string> car, string name, size_t number) {
      car = car;
      name = name;
      number = number;
    }
  };
  vector<vector<string>> CarsWays;
  void ReadDate(string file) {
	ifstream in(file);
    string str;
    while (getline(in, str)) {
      stringstream in_(str);
      vector<string> vector;
      while (in >> str) {
        vector.push_back(str);
      }
      CarsWays.push_back(vector);
    }
  }
  vector<Route> Collect(vector<vector<string>>& CarsWays) {
    vector<Route> ans(CarsWays.size());
    transform(CarsWays.begin(), CarsWays.end(), ans.begin(),
                   [](vector<string> vector) -> Route {
                     return Route(make_pair(stoi(vector[2]), vector[3]),
                                  vector[1], stoi(vector[0]));
                   });
  }
  enum Sorts { number_way, number_car, name };
  void Sort(vector<Route>& vector, size_t type) {
    switch (type) {
      case name: {
        sort(vector.begin(), vector.end(),
             [](Route& l, Route& r) -> bool { return l.name_ < r.name_; });
        break;
      }
      case number_way: {
        sort(vector.begin(), vector.end(), [](Route& l, Route& r) -> bool {
          return l.car_.first < r.car_.first;
        });
        break;
      }
      case number_car: {
        sort(vector.begin(), vector.end(),
             [](Route& l, Route& r) -> bool { return l.number_ < r.number_; });
        break;
        break;
      }
    }
  }
  map<size_t, Route> MakeMap(vector<Route> vector) {
    map<size_t, Route> ans;
    for (auto value : vector) {
      ans[value.number_] = value;
    }
    return ans;
  }
  list<Route> UniqueList(vector<Route> vector) {
    list<Route> ans;
    vector.erase(unique(vector.begin(), vector.end()), vector.end());
    for (auto value : vector) {
      ans.push_back(value);
    }
    return ans;
  }
  list<pair<size_t, string>> CarsList(vector<Route> vector,
                                                     size_t way) {
    list<pair<size_t, string>> ans;
    vector.erase(remove_if(vector.begin(), vector.end(), [&](Route new_) {
      return new_.number_ != way;
    }));
    for (auto value : vector) {
      ans.push_back(value.car_);
    }
    return ans;
  }
  list<string> NamesList(vector<Route> vector, size_t way) {
    list<string> ans;
    vector.erase(remove_if(vector.begin(), vector.end(), [&](Route new_) {
      return new_.number_ != way;
    }));
    for (auto value : vector) {
      ans.push_back(value.name_);
    }
    return ans;
  }
  list<string> NamesByCarList(vector<Route> vector,
                                        string car_name) {
    list<string> ans;
    vector.erase(remove_if(vector.begin(), vector.end(), [&](Route new_) {
      return new_.car_.second != car_name;
    }));
    for (auto value : vector) {
      ans.push_back(value.name_);
    }
    return ans;
  }
  void EraseNumber(vector<Route>& vector, size_t way) {
    vector.erase(remove_if(vector.begin(), vector.end(), [&](Route new_) {
      return new_.number_ == way;
    }));
  }
  void EraseNumbersCars(vector<Route>& vector, size_t number) {
    vector.erase(remove_if(vector.begin(), vector.end(), [&](Route new_) {
      return new_.car.first == number;
    }));
  }
  size_t MaxCountWay(vector<Route>& vector) {
    map<size_t, size_t> countCars;
    for (auto value : vector) {
      countCars[value.number_]++;
    }

    return max_element(countCars.begin(), countCars.end(),
                            [](pair<size_t, size_t> f,
                               pair<size_t, size_t> s) -> bool {
                              return f.second < s.second;
                            })
        ->second;
  }
  size_t UnicalMarks(vector<Route>& vector, string mark) {
    return count_if(vector.begin(), vector.end(),
                         [&](Route new_) { return new_.car_.second == mark; });
  }
  size_t FindWayOfDriver(vector<Route>& vector, string name) {
    return find_if(vector.begin(), vector.end(),
                        [&](Route new_) { return new_.name_ == name; })
        ->number_;
  }
  size_t FindWayWithUnicalMark(std::vector<Route>& vector) {
    map<size_t, string> way_mark;
    for (auto value : vector) {
      if (way_mark[value.number_] == "" ||
          way_mark[value.number_] == value.car_.second) {
        way_mark[value.number_] = value.number_;
      } else {
        way_mark[value.number_] = "$$$";
      }
    }
    for (auto value : way_mark) {
      if (value.second != "$$$" && value.second != "") return value.first;
    }
  }
  size_t FindSpecificWay(vector<Route>& vector) {
    map<size_t, set<string>> marksOfWay;
    for (auto value : vector) {
      marksOfWay[value.number_].insert(value.car.second);
    }
    return max_element(marksOfWay.begin(), marksOfWay.end(),
                       [&](pair<size_t, set<string>> f,
                           pair<size_t, set<string>> s) -> bool {
                         return f.second.size() < s.second.size();
                       })
        ->first;
  }
  static bool SProgram() { return 0; }
};