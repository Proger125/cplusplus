#pragma once
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class CountryFeature {
 public:
  string country_code;
  string region;
  string income_group;
  friend ifstream &operator>>(ifstream &fin, CountryFeature &count);
  friend ofstream &operator<<(ofstream &fout, CountryFeature &count);
};
class Country {
 public:
  string country_name;
  CountryFeature feature;
  friend ifstream &operator>>(ifstream &fin, Country &count);
  friend ofstream &operator<<(ofstream &fout, Country &count);
};
class WorldCountry {
 public:
  Country country;
  map<int, long long int> year_population;
  friend ifstream &operator>>(ifstream &fin, WorldCountry &wc);
  friend ofstream &operator<<(ofstream &fout, WorldCountry &wc);
};
class Program {
 public:
  vector<WorldCountry> v;
  set<string> all_regs;
  vector<pair<string, map<int, long long int> > > all_regs_with_pop;
  Program();
  ~Program();
  vector<WorldCountry> ChooseIncome(string income);
  set<string> UniqueRegion();
  vector<WorldCountry> ChooseCountryByRegion(string reg);
  vector<pair<string, map<int, long long int> > > CalcWorldRegionPopulation(
      set<string> &UniqueRegion);
  void WriteWorldRegionPopulation();
  int Main();
};
int Program::Main() {
	WriteWorldRegionPopulation();
	return 0;
}
class WorldRegionPopulation {
 public:
  string region;
  map<int, long long int> year_population;
  WorldRegionPopulation(vector<WorldCountry> v, string reg);
};
WorldRegionPopulation::WorldRegionPopulation(vector<WorldCountry> v,
                                             string reg) {
  region = reg;
  for (int year = 1960; year < 2019; year++) {
    int population_of_reg = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].country.feature.region == reg) {
        population_of_reg += v[i].year_population[year];
      }
    }
    year_population.insert(make_pair(year, population_of_reg));
  }
}
Program::Program() {
  ifstream fin("countries.csv");
  ifstream fik("world_population_1960-2018.csv");
  while (!fin.eof()) {
    WorldCountry c;
    fin >> c.country;
    fik >> c;
    v.push_back(c);
  }
  all_regs = UniqueRegion();
  all_regs_with_pop = CalcWorldRegionPopulation(all_regs);
  fik.close();
  fin.close();
}
Program::~Program() {
  
}
vector<WorldCountry> Program::ChooseCountryByRegion(string reg) {
  vector<WorldCountry> res;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].country.feature.region == reg) {
      res.push_back(v[i]);
    }
  }
  return res;
}
vector<pair<string, map<int, long long int> > >
Program::CalcWorldRegionPopulation(set<string> &UniqueRegion) {
  vector<pair<string, map<int, long long int> > > res;
  for (auto elem : UniqueRegion) {
    WorldRegionPopulation reg(v, elem);
    res.push_back(make_pair(elem, reg.year_population));
  }
  return res;
}
vector<WorldCountry> Program::ChooseIncome(string income) {
  vector<WorldCountry> result;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].country.feature.income_group == income) {
      result.push_back(v[i]);
    }
  }
  return result;
}
set<string> Program::UniqueRegion() {
  set<string> result;
  for (int i = 0; i < v.size(); i++) {
    result.insert(v[i].country.feature.region);
  }
  return result;
}
void Program::WriteWorldRegionPopulation() {
  ofstream fout("result.txt");
  fout << "Region" << " ";
  for (int year = 1960; year < 2019; year++) {
    fout << year << " ";
  }
  fout << endl;
  for (int i = 0; i < all_regs_with_pop.size(); i++) {
    fout << all_regs_with_pop[i].first << " ";
    for (auto it = all_regs_with_pop[i].second.begin();
         it != all_regs_with_pop[i].second.end(); it++) {
      fout << it->second << " ";
    }
    fout << endl;
  }
  fout.close();
}
ifstream &operator>>(ifstream &fin, CountryFeature &count) {
  getline(fin, count.country_code, ';');
  getline(fin, count.region, ';');
  getline(fin, count.income_group, ';');
  return fin;
}
ofstream &operator<<(ofstream &fout, CountryFeature &count) {
  fout << count.country_code << " " << count.income_group << " " << count.region
       << endl;
  return fout;
}
ifstream &operator>>(ifstream &fin, Country &count) {
  fin >> count.feature;
  getline(fin, count.country_name);
  return fin;
}
ofstream &operator<<(ofstream &fout, Country &count) {
  fout << count.country_name << endl;
  fout << count.feature;
  return fout;
}
ifstream &operator>>(ifstream &fin, WorldCountry &wc) {
  string name, code;
  getline(fin, name, ';');
  getline(fin, code, ';');
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
    wc.year_population.insert(make_pair(year, pop));
    year++;
  }
  return fin;
}