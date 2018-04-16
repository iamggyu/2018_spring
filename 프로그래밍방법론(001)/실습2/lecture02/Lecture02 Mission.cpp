#include <iostream>

using namespace std;

void main() {
	int input_num, first_term = 0, second_term = 1, next_term = 0;

	cout << "Enter the number of terms you want: ";
	cin >> input_num;
	cout << "Result of Fibonacci Series: ";

	for (int i = 1; i <= input_num; ++i) {

		if (i == 1)
			cout << first_term << " ";

		else if (i == 2) 
			cout << second_term << " ";

		else {
			first_term = second_term;
			second_term = next_term;
			next_term = first_term + second_term;

			cout << next_term << " ";
		}
	}
}