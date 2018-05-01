
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;


int getWeight(char ch) {
	switch (ch) {
	case '/':
	case '*': return 3;
	case '+':
	case '-': return 1;
	case '(': return 100;
	case ')': return 0;
	case '^': return 6;
	default: return -1;
	}
}

int topWeight(char ch) {
	switch (ch) {
	case '/':
	case '*': return 4;
	case '+':
	case '-': return 2;
	case '(': return 0;
	case ')': return 99;
	case '^': return 5;
	default: return 0;
	}
}

vector<string> infix2postfix(vector<string> infix) {
	stack<string> operator_stack;
	vector<string> postfix;
	//implement infix to postfix converter
	for (auto s : infix) {
		if (isdigit(s[0]))
			postfix.push_back(s);
		else {
			while (!operator_stack.empty() && getWeight(s[0]) < topWeight(operator_stack.top()[0])){
				postfix.push_back(operator_stack.top());
				operator_stack.pop();
			}
			if (s[0] == ')' && operator_stack.top()[0] == '(')
				operator_stack.pop();
			else
				operator_stack.push(s);
		}
	}
	while (!operator_stack.empty()) {
		postfix.push_back(operator_stack.top());
		operator_stack.pop();
	}
	return postfix;
}

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
	vector<vector<string>> infixs;
	string equation;
	while(getline(inFile, equation)){
		//implement parsing the expression and save in infixs
		infixs.push_back(vector<string>());
		size_t found = equation.find_first_of(" ");
		infixs.back().push_back(equation.substr(0, found));
		while (found != string::npos) {
			size_t nextFound = equation.find_first_of(" ", found + 1);
			infixs.back().push_back(equation.substr(found + 1, nextFound - found - 1));
			found = nextFound;
		}
	}

	for(auto infix:infixs){
		postfixs.push_back(infix2postfix(infix));
	}
	for (auto postfix : postfixs) {
		cout << evaluatePostfix(postfix) << endl;
	}
	system("pause");
}


