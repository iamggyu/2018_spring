#ifndef HW2_CALCULATOR_H
#define HW2_CALCULATOR_H

#include <string>

using namespace std;

class Calculator
{
public:
	Calculator(string str);
	void setInfixExp(string str);
	int getWeight(char op) const;
	string getPostfixExp() const;
	int calcTwoOperands(int operand1, int operand2, char op) const;
	int calculate();
private:
	string exp_infix;
};

#endif