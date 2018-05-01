
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
	default : return -1;
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
	default : return 0;
	}
}

vector<string> infix2postfix(vector<string> infix){
	stack<string> operator_stack;
	vector<string> postfix;
	//implement infix to postfix converter
	for(auto s : infix){
		
	}
	return postfix;
}

void main() {
	ifstream inFile("input.txt");

	vector<vector<string>> postfixs;
	vector<vector<string>> infixs;
	string equation;
	while(getline(inFile, equation)){
		//implement parsing the expression and save in infixs

	}

	for(auto infix:infixs){
		postfixs.push_back(infix2postfix(infix));
		for(auto s : postfixs.back()){
			cout << s << " ";		
		}
		cout << endl;
	}

}


