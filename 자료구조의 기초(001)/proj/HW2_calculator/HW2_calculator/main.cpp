#include "HW2_Calculator.h"
#include <iostream>

int main() {
	string str = "(2+5)*3*(2+1)";
	Calculator calc(str);
	cout << "infix: " << str << endl;
	cout << calc.getPostfixExp() << endl;
	cout << calc.calculate() << endl << endl;

	str = "1+(2*3/4)/5*6-(7+8)/9/(1*2+3-4)/5*(6-7)/(8)*9";
	calc.setInfixExp(str);
	cout << "infix: " << str << endl;
	cout << calc.getPostfixExp() << endl;
	cout << calc.calculate() << endl << endl;

	str = "((1)*2+(3-4-((5/6)+(7)-(8*9))))";
	calc.setInfixExp(str);
	cout << "infix: " << str << endl;
	cout << calc.getPostfixExp() << endl;
	cout << calc.calculate() << endl << endl;

	system("pause");
}