#include "HW1_Rectangle.h"

int main() {
	Rectangle a(0, 1, 4, 3);
	Rectangle b(2, 0, 3, 3);

	cout << a - b << endl;
	cout << b - a << endl;
	cout << a + b << endl;

	Rectangle c(a & b);
	Rectangle d(a | b);
	cout << c << endl;
	cout << d << endl;

	int x;
	cin >> x;
}