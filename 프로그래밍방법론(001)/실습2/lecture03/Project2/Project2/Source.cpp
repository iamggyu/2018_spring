#include<iostream>
using namespace std;
/*
class Student {
public:
	int id = 1;
};

Student* B(Student* s) {
	Student w = *s;
	w.id = 10;
	return &w;
}

void main() {
	Student c;
	Student *d = B(&c);
	Student e(*d);
	cout << (*d).id << endl;
	cout << e.id << endl;

	int a;
	cin >> a;
}*/


class Sphere {
public:
	Sphere() {
	
	}
	Sphere(Sphere orig) {
		a = orig.a;
	}
	int a = 0;
};

int main() {
	Sphere A;
	Sphere B(A);
	cout << B.a;
}