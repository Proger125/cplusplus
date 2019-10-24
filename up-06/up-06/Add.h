#pragma once
#ifdef ADD_H
#endif  // ADD_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Country {
 public:
  string name, code;
  map<int, long long int> population;
  void GetCountry();
};
void Country::GetCountry() {
  ifstream fin("world_population_1960-2018.csv");
  getline(fin, name, ';');
  getline(fin, code, ';');
  int pop = 0;
  int year = 1960;
  while (year < 2019) {
    fin >> pop;
    population.insert(make_pair(year, pop));
    year++;
  }
  fin.close();
}