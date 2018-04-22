#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <cmath>
using namespace std;

double evaluatePostfix(vector<string> postfix) {
	stack<double> number_stack;
	//implement evaluate postfix expression

	for (size_t i = 0; i < postfix.size(); i++) {
		if (postfix[i][0] <= '9' && postfix[i][0] >= '0') {
			number_stack.push(stod(postfix[i]));
			continue;
		}
		double a = number_stack.top();
		number_stack.pop();
		double b = number_stack.top();
		number_stack.pop();

		switch (postfix[i][0]) {
		case '+': number_stack.push(b + a); break;
		case '-': number_stack.push(b - a); break;
		case '*': number_stack.push(b * a); break;
		case '/': number_stack.push(b / a); break;
		case '^': number_stack.push(pow(b, a)); break;
		}
	}

	return number_stack.top();
}

void main() {
	ifstream inFile("input.txt");

	vector<vector<string>> postfixs;
	string equation;
	while (getline(inFile, equation)) {
		//implement parsing the expression
		postfixs.push_back(vector<string>());
		size_t found = equation.find_first_of(" ");
		postfixs.back().push_back(equation.substr(0, found));
		while (found != string::npos) {
			size_t nextFound = equation.find_first_of(" ", found + 1);
			postfixs.back().push_back(equation.substr(found + 1, nextFound - found - 1));
			found = nextFound;
		}
	}

	for (int i = 0; i< postfixs.size(); i++) {
		cout << "Result: " << evaluatePostfix(postfixs[i]) << endl;
	}
	system("pause");
}


