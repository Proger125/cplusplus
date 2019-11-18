#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
struct Person {
  string name, surname;
  double mid;
  int a, b, c;
};
bool comp(Person a, Person b) { return (a.a + a.b + a.c) > (b.a + b.b + b.c); }
int main() {
  long long n;
  cin >> n;
  vector<Person> v;
  for (long long i = 0; i < n; i++) {
    string name = "", surname = "";
    int a, b, c;
    cin >> name >> surname;
    cin >> a >> b >> c;
    Person p;
    p.name = name;
    p.surname = surname;
    p.a = a;
    p.b = b;
    p.c = c;
    p.mid = (double)(a + b + c) / 3.0;
    v.push_back(p);
  }
  stable_sort(v.begin(), v.end(), comp);
  for (int i = 0; i < n; i++) {
    cout << v[i].name << " " << v[i].surname << endl;
  }
}