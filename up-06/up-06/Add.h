#pragma once
#ifdef ADD_H
#endif  // ADD_H
#include <conio.h>
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
  string Tostring();
  friend ifstream &operator>>(ifstream &fin, Country &MyCountry);
};
class WorldPopulation {
 public:
  vector<Country> v;
  map<int, long long int> year_population;
  void ReadWorld();
  void CalcWorldPopulation();
  void WriteYearPopulation();
};
string Country::Tostring() {
  string result;
  result += this->name;
  result = result + "(" + this->code + ") : ";
  for (auto it = this->population.begin(); it != this->population.end(); it++) {
    result = result + to_string(it->second) + "[" + to_string(it->first) + "] ";
  }
  return result;
}
void WorldPopulation::ReadWorld() {
  ifstream fin("world_population_1960-2018.csv");
  while (!fin.eof()) {
    Country buf;
    fin >> buf;
    this->v.push_back(buf);
  }
  fin.close();
}
void WorldPopulation::CalcWorldPopulation() {
  for (int year = 1960; year < 2019; year++) {
    long long int result = 0;
    for (int i = 0; i < this->v.size(); i++) {
      auto it = this->v[i].population.find(year);
      result += it->second;
    }
    this->year_population.insert(make_pair(year, result));
  }
}
void WorldPopulation::WriteYearPopulation() {
  ofstream fout("result.txt");
  for (auto it = this->year_population.begin();
       it != this->year_population.end(); it++) {
    fout << it->first << " " << it->second << endl;
  }
  fout.close();
}
ifstream &operator>>(ifstream &fin, Country &MyCountry) {
  getline(fin, MyCountry.name, ';');
  getline(fin, MyCountry.code, ';');
  if (MyCountry.name[0] == '\n') {
    MyCountry.name.erase(0, 1);
  }
  int year = 1960;
  while (year < 2019) {
    string buf;
    if (year != 2018) {
      getline(fin, buf, ';');
    } else {
      getline(fin, buf, '\n');
    }
    long long int pop = 0;
    if (buf.length() != 0) {
      pop = stoi(buf);
    } else {
      pop = 0;
    }
    MyCountry.population.insert(make_pair(year, pop));
    year++;
  }
  return fin;
}