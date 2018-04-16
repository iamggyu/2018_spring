#include "HW1_BigOp.h"

void main() {
	BigNum a("123456789");
	BigNum b("978625314");
	BigNum c("45637");

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	cout << "c : " << c << endl;

	BigNum d = a + b;
	cout << "a + b : " << d << endl;
	
	BigNum e(a + c);
	cout << "a + c : " << e << endl;
	
	BigNum f; f = b + c;
	cout << "b + c : " << f << endl;

	cout << "a + b : " << a + b << endl;
	cout << "a + b + c : " << a + b + c << endl;

	BigNum g = a * b;
	cout << "a * b : " << g << endl;

	BigNum h(a * c);
	cout << "a * c : " << h << endl;

	BigNum i; i = b * c;
	cout << "b * c : " << i << endl;
	
	cout << "a * b * c : " << a * b * c << endl;

}