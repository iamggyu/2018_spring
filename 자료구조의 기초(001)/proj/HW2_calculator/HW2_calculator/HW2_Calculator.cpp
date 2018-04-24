#include "HW2_Calculator.h"
#include "HW2_Stack.h"
#include <iostream>

Calculator::Calculator(string str) {
	// TODO
	exp_infix = str;
}

int Calculator::getWeight(char op) const {
	// TODO
	switch (op) {
	case '(': return 1;
	case ')': return 1;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	}
}

void Calculator::setInfixExp(string str) {
	// TODO
	exp_infix = str;
}

int Calculator::calcTwoOperands(int operand1, int operand2, char op) const {
	// TODO
	switch (op) {
	case '+': return operand1 + operand2;
	case '-': return operand1 - operand2;
	case '*': return operand1 * operand2;
	case '/': return operand1 / operand2;
	default: return -1;
	}
}

string Calculator::getPostfixExp() const{
	// TODO
	string exp_postfix;
	Stack<char> st;

	for (string::size_type i = 0; i < exp_infix.size(); i++) {
		if (isdigit(exp_infix[i]))
			exp_postfix.push_back(exp_infix[i]);
		else if (st.isEmpty())
			st.push(exp_infix[i]);
		else if (getWeight(st.getTop()) < getWeight(exp_infix[i]) || exp_infix[i] == '(')
			st.push(exp_infix[i]);
		else {
			while (getWeight(st.getTop()) >= getWeight(exp_infix[i])) {
				if (st.getTop() != '(')
					exp_postfix.push_back(st.pop());
				else {
					st.pop();
					break;
				}
			}
			if(exp_infix[i] != '(' && exp_infix[i] != ')')
				st.push(exp_infix[i]);
		}
	}
	while (!st.isEmpty())
		exp_postfix.push_back(st.pop());
	return exp_postfix;
}

int Calculator::calculate() {
	// TODO
	Stack<int> st;
	string exp_postfix = getPostfixExp();
	for (string::size_type i = 0; i < exp_postfix.size(); i++) {
		if (isdigit(exp_postfix[i]))
			st.push(exp_postfix[i] - '0');
		else {
			st.push(calcTwoOperands(st.pop(), st.pop(), exp_postfix[i]));
		}
	}
	return st.pop();
}
