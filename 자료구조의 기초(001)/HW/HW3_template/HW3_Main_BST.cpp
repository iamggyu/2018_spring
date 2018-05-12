#include <iostream>
#include "HW3_BST.h"
using namespace std;

int main() {
	BST *dict = new BST();
	dict->insert(4, 4.44);
	dict->insert(3, 3.33);
	dict->insert(6, 6.66);
	dict->insert(1, 1.11);
	dict->insert(5, 5.55);
	dict->insert(8, 8.88);
	dict->insert(7, 7.77);
	dict->insert(9, 9.99);
	cout << "Inorder : \t"; dict->inorder(); cout << endl;
	cout << "Preorder : \t"; dict->preorder(); cout << endl;
	cout << "Postorder : \t"; dict->postorder(); cout << endl;
	cout << "Levelorder : \t"; dict->levelorder(); cout << endl;
}