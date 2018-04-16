#pragma once
#include<iostream>
using namespace std;

class BigNum {
private:
	int *number;
	int size;
public:
	BigNum();
	BigNum(string num);
	BigNum(const BigNum& bignum);
	~BigNum();
	BigNum& operator= (const BigNum& bignum);
	BigNum operator+(const BigNum& bignum);
	BigNum operator*(const BigNum& bignum);
	friend ostream& operator<< (ostream& os, const BigNum& bignum);
};