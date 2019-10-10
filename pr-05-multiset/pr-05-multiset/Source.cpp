#include <iostream>
#include <set>

using namespace std;
template <typename T>
void InputSet(multiset<T> &Myset) {
  cout << "Enter the amount of elements = ";
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    T k;
    cin >> k;
    Myset.insert(k);
  }
}
template <typename T>
void Asociation(multiset<T> &Myset_1, multiset<T> &Myset_2, multiset<T> &Myset_3) {
  for (auto i: Myset_1) {
    Myset_3.insert(i);
  }
  for (auto i: Myset_2) {
    Myset_3.insert(i);
  }
  cout << "The asociation of two sets = " << endl;
  for (auto i: Myset_3) {
    cout << i << " ";
  }
  cout << endl;
}
template <typename T>
void Intersection(multiset<T> &Myset_1, multiset<T> &Myset_2, multiset<T> &Myset_3) {
  for (auto i: Myset_1) {
    for (auto j : Myset_2) {
      if (i == j) {
        Myset_3.insert(i);
	  }
	}
  }
  cout << "The intersection of two sets = " << endl;
  for (auto i: Myset_3) {
    cout << i << " ";
  }
  cout << endl;
}
template <typename T>
void Difference_1(multiset<T> &Myset_1, multiset<T> &Myset_2, multiset<T> &Myset_3) {
  for (auto i : Myset_1) {
    int f = 0;
    for (auto j : Myset_2) {
      if (i != j) {
        f = 1;
      } else {
        f = 0;
        break;
	  }
    }
    if (f == 1) {
      Myset_3.insert(i);
    }
  }
  cout << "The difference between first and second sets = " << endl;
  for (auto i : Myset_3) {
    cout << i << " ";
  }
  cout << endl;
}
template <typename T>
void Difference_2(multiset<T> &Myset_1, multiset<T> &Myset_2, multiset<T> &Myset_3) {
  for (auto i : Myset_2) {
    int f = 0;
    for (auto j : Myset_1) {
      if (i != j) {
        f = 1;
      } else {
        f = 0;
        break;
      }
    }
    if (f == 1) {
      Myset_3.insert(i);
    }
  }
  cout << "The difference between second and first sets = " << endl;
  for (auto i : Myset_3) {
    cout << i << " ";
  }
  cout << endl;
}
int main() {
  multiset<int> Myset_1;
  multiset<int> Myset_2;
  multiset<int> Myset_3;
  cout << "Enter the first set" << endl;
  InputSet(Myset_1);
  cout << "Enter the second set" << endl;
  InputSet(Myset_2);
  Asociation(Myset_1, Myset_2, Myset_3);
  Myset_3.clear();
  Intersection(Myset_1, Myset_2, Myset_3);
  Myset_3.clear();
  Difference_1(Myset_1, Myset_2, Myset_3);
  Myset_3.clear();
  Difference_2(Myset_1, Myset_2, Myset_3);
  system("pause");
  return 0;
}