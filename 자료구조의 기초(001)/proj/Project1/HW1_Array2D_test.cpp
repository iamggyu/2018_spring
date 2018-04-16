#include "HW1_Array2D.h"

int main() {
	Array2D a(7);

	cout << "<Original Matrix>" << endl;
	cout << a << endl;

	Array2D b(7);
	cout << "<After MirrorRight>" << endl;
	b.MirrorRight();
	cout << b << endl;

	Array2D c(7);
	cout << "<After MirrorDown>" << endl;
	c.MirrorDown();
	cout << c << endl;

	Array2D d(7);
	cout << "<After MirrorNE45>" << endl;
	d.MirrorNE45();
	cout << d << endl;

	pair<int, int> t;
	t.first;


	Array2D e(7);
	cout << "<After MirrorSE45>" << endl;
	e.MirrorSE45();
	cout << e << endl;

	system("pause");
	return 0;
}