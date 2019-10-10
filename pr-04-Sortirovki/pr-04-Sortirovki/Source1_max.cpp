#include  "functions.h"

int main() {
  int a, b, c, n, m;
  double aa, bb;
  char aaa, bbb;
  string aaaa, bbbb;
  vector<int> v;
  InputString(aaaa, bbbb);
  InputInteger(a, b, c);
  InputDouble(aa, bb);
  InputChar(aaa, bbb);
  InputVector(v, n);
  cout << "Enter the count of rows = ";
  cin >> m;
  vector<vector<int> > vv(m);
  InputVector_Of_Vectors(vv);
  cout << "Max between first and second integer elements = " << max(a, b)
       << endl;
  cout << "Max between all integer elements = " << max(a, b, c) << endl;
  cout << "Max between all double elements = " << max(aa, bb) << endl;
  cout << "Max between all char elements = " << max(aaa, bbb) << endl;
  cout << "Max between all string elements = " << max(aaaa, bbbb) << endl;
  cout << "Max element of vector = " << max(v) << endl;
  cout << "Max element of vector of vectors = " << max(vv) << endl;
  system("pause");
  return 0;
}