#pragma once
#include<iostream>
using namespace std;

class Array2D {
public:
	Array2D();
	Array2D(int size);
	~Array2D();
	friend ostream& operator<< (ostream& os, const Array2D& arr);
	void swap(int *a, int *b);
	void MirrorRight();
	void MirrorDown();
	void MirrorNE45();
	void MirrorSE45();
private:
	int** m_array;
	int m_size;
};