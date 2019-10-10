#include <iostream>

using namespace std;

int main() { 

	int x, y;
	cout << "Enter x and y" << endl;
	cin >> x >> y;
        if (x < 0 && y > 0)
          cout << "Point with cordinats x and y lies in the second quarter";
        else
          cout << "Point with cordinats x and y doesn't lie in the second quarter" << endl;
        system("pause");
	return 0; }