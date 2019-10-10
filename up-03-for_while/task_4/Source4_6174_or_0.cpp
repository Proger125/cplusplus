#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int sbor_low(vector<int> a) {
  int n1 = 0;
  int pow = 1;
  for (int i = 0; i < a.size(); i++) {
    n1 += a[i] * pow;
    pow *= 10;
  }
  return n1;
}
int sbor_hight(vector<int> a) {
  int n2 = 0;
  int pow = 1;
  for (int i = 0; i < a.size(); i++) {
    n2 += a[i] * pow;
    pow *= 10;
  }
  return n2;
}
bool comp(int first, int second) { return (first > second); }
int main() {
  int n, n1 = 0, n2 = 0, h = 1;
  cout << " Enter n = ";
  cin >> n;
  vector<int> a;
  while (n > 0) {
    int k = n % 10;
    a.push_back(k);
    n /= 10;
  }
  sort(a.begin(), a.end());
  n1 = sbor_hight(a);
  sort(a.begin(), a.end(), comp);
  n2 = sbor_low(a);
   while (n1 - n2 != 0 || n1 - n2 != 6174) {
    n = n1 - n2;
     vector<int> b;
     while (n > 0) {
       int k = n % 10;
       b.push_back(k);
       n /= 10;
     }
     sort(b.begin(), b.end());
     n1 = sbor_hight(b);
     sort(b.begin(), b.end(), comp);
     n2 = sbor_low(b);
     if (n1 - n2 == 0 || n1 - n2 == 6174) {
       h = 1;
       break;
     } else {
       h = 0;
	 }
   }
   if (h) {
     cout << "This statement is true" << endl;
   } else {
     cout << "This statement is false" << endl;
   }
  system("pause");
  return 0;
}