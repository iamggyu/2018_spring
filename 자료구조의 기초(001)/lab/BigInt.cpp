#include <iostream>
#include <string>

using namespace std;

int* String_To_Int(string Number) {

	int size = Number.size();
	int *NumInt = new int[size];

	for (int i = 0; i < size; i++)
		NumInt[i] = Number[i] - '0';

	return NumInt;
}

void CalculateSum(int *A, int A_size, int *B, int B_size) {
	// TODO
}

int main() {

	string As, Bs;
	int A_size, B_size;
	int *A, *B;

	cout << "Input number A : ";
	cin >> As;
	cout << "Input number B : ";
	cin >> Bs;

	A_size = As.size();
	B_size = Bs.size();

	A = String_To_Int(As);
	B = String_To_Int(Bs);

	CalculateSum(A, A_size, B, B_size);

	delete[] A;
	delete[] B;
}