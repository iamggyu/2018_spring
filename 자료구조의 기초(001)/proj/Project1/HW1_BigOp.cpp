#include "HW1_BigOp.h"
#include <iostream>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;

BigNum::BigNum() {
	number = NULL;
	size = 0;
}

BigNum::BigNum(string num) {
	size = num.size();
	number = new int[size];

	for (int i = 0; i < size; i++)
		number[i] = num[i] - '0';
}

BigNum::BigNum(const BigNum& bignum) {
	this->size = bignum.size;
	this->number = new int[this->size];

	for (int i = 0; i < this->size; i++) {
		this->number[i] = bignum.number[i];
	}
}

BigNum::~BigNum() {
	delete[] number;
}

BigNum& BigNum::operator=(const BigNum& bignum) {
	delete[] this->number;
	this->size = bignum.size;
	this->number = new int[this->size];

	for (int i = 0; i < this->size; i++) {
		this->number[i] = bignum.number[i];
	}
	
	return *this;
}

BigNum BigNum::operator+(const BigNum& bignum) {
	BigNum res;
	res.size = max(this->size, bignum.size) + 1;
	res.number = new int[res.size];

	int carry = 0;
	for (int i = 0; i < res.size; i++) {
		int a1 = (i < this->size) ? this->number[this->size - i - 1] : 0;
		int b1 = (i < bignum.size) ? bignum.number[bignum.size - i - 1] : 0;
		int sum = a1 + b1 + carry;
		
		carry = sum / 10;
		res.number[res.size - i - 1] = sum % 10;
	}

	if (res.number[0] == 0) {
		BigNum res1;
		res1.size = res.size - 1;
		res1.number = new int[res1.size];

		for (int i = 0; i < res1.size; i++)
			res1.number[i] = res.number[i + 1];
		return res1;
	}
	return res;
}

BigNum BigNum::operator*(const BigNum& bignum) {
	BigNum res;
	res.size = this->size + bignum.size;
	res.number = new int[res.size];
	for (int i = 0; i < res.size; i++)
		res.number[i] = 0;

	for (int i = 0; i < bignum.size; i++) 
		for (int j = 0; j < this->size; j++) 
			res.number[res.size - i - j - 1] += this->number[this->size - j - 1] * bignum.number[bignum.size - i - 1];

	int carry;
	for (int i = 0; i < res.size - 1; i++) {
		carry = res.number[res.size - i - 1] / 10;
		res.number[res.size - i - 1] -= 10 * carry;
		res.number[res.size - i - 2] += carry;
	}
	
	if (res.number[0] == 0) {
		BigNum res1;
		res1.size = res.size - 1;
		res1.number = new int[res1.size];

		for (int i = 0; i < res1.size; i++)
			res1.number[i] = res.number[i + 1];
		return res1;
	}

	return res;
}

ostream& operator<<(ostream& os, const BigNum& bignum) {
	for (int i = 0; i < bignum.size; i++){
		os << bignum.number[i];
	}
	return os;
}