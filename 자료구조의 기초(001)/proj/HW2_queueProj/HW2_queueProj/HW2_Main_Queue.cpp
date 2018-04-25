#include "HW2_Queue.h"

void main() {

	cout << "# Initialization" << endl;
	Queue<int> a(5);
	cout << "Front : " << a.getFront() << endl;
	cout << "Rear : " << a.getRear() << endl;
	a.print();

	cout << endl << "# Push 7 times" << endl;
	for (int i = 0; i < 7; i++) {
		a.push(i);
		cout << "Push " << i << " (" << a.getSize() << "/" << a.getCapacity() << ")" << endl;
	}
	cout << "Front : " << a.getFront() << endl;
	cout << "Rear : " << a.getRear() << endl;
	a.print();

	cout << endl << "# Pop 4 times" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "Pop : " << a.pop();
		cout << " (" << a.getSize() << "/" << a.getCapacity() << ")" << endl;
	}
	cout << "Front : " << a.getFront() << endl;
	cout << "Rear : " << a.getRear() << endl;
	a.print();

	cout << endl << "# Push 9 times" << endl;
	for (int i = 100; i < 1000; i += 100) {
		a.push(i);
		cout << "Push " << i << " (" << a.getSize() << "/" << a.getCapacity() << ")" << endl;
	}
	cout << "Front : " << a.getFront() << endl;
	cout << "Rear : " << a.getRear() << endl;
	a.print();

	cout << endl << "# Pop 6 times" << endl;
	for (int i = 0; i < 6; i++) {
		cout << "Pop : " << a.pop();
		cout << " (" << a.getSize() << "/" << a.getCapacity() << ")" << endl;
	}
	cout << "Front : " << a.getFront() << endl;
	cout << "Rear : " << a.getRear() << endl;
	a.print();

	cout << endl << "# Shift -17" << endl;
	a.shift(-17);
	a.print();

	cout << endl << "# Shift 20" << endl;
	a.shift(20);
	a.print();

	cout << endl << "# Shift -74" << endl;
	a.shift(-74);
	a.print();

	cout << endl << "# Shift 3745822" << endl;
	a.shift(3745822);
	a.print();
	system("pause");
}