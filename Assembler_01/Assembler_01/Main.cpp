#include <iostream>

using namespace std;

int main() {
  int a = 34524534;
  int b = pow(2, 16);
  cout.unsetf(ios::dec);
  cout.setf(ios::hex);
  cout << a << endl;
  int result;
	__asm {
		mov ebx, a
		mov ax, bx
		mul b
		mov ecx, eax
		mov eax, a
		cdq
		div b
		add ecx, eax
		mov result, ecx
  }
  cout << result << endl;
  system("pause");
  return 0;
}