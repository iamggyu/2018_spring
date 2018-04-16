#include "sllist.h"

int main() {

	list numList;

	for (int i = 0; i < 10; i++) {
		numList.insert(i, 10 - i);
	}

	cout << "size : " << numList.getSize() << endl;
	numList.printAll();
	cout << "4 after : " << numList.find(4)->getNext()->getNum() << endl;

	numList.remove(3);
	numList.printAll();

	return 0;
}