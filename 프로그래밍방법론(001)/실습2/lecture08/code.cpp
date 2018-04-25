
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

double evaluatePostfix(vector<string> postfix){
	stack<double> number_stack;
	//implement evaluate postfix expression

	return number_stack.top();
}

void main() {
	ifstream inFile("input.txt");

	vector<vector<string>> postfixs;
	string equation;
	while(getline(inFile, equation)){
		//implement parsing the expression

	}

	for(int i=0 ;i< postfixs.size(); i++){
		cout << "Result: " << evaluatePostfix(postfixs[i]) << endl;
	}	
}


