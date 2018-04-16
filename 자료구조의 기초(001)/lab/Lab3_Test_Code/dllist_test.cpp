#include "dllist.h"

int main() {
	list numList;

	for (int i = 0; i < 10; i++) {
		numList.insert(i, 10 - i);
	}
	cout << "size : " << numList.getSize() << endl;
	numList.printAll();
	cout << "4 after : " << numList.find(4)->getNext()->getNum() << endl;
	cout << "7 before : " << numList.find(7)->getPrev()->getNum() << endl;
	cout << endl;

	numList.remove(3);
	numList.printAll();
	cout << "8 after : " << numList.find(8)->getNext()->getNum() << endl;
	cout << "6 before : " << numList.find(6)->getPrev()->getNum() << endl;
	cout << endl;

	numList.insert(7, 17);
	numList.printAll();
	cout << "3 after : " << numList.find(3)->getNext()->getNum() << endl;
	cout << "17 before : " << numList.find(17)->getPrev()->getNum() << endl;
	cout << "17 after : " << numList.find(17)->getNext()->getNum() << endl;
	cout << "2 before : " << numList.find(2)->getPrev()->getNum() << endl;

}