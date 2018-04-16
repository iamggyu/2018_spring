#include "HW1_Array2D.h"

Array2D::Array2D() {
	m_size = 0;
	m_array = NULL;
}

Array2D::Array2D(int size) {
	m_size = size;
	m_array = new int*[size];
	for (int i = 0; i < size; i++) 
		m_array[i] = new int[size];

	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			m_array[i][j] = i * m_size + j + 1;
}

Array2D::~Array2D() {
	for (int i = 0; i < m_size; i++) 
		delete[] m_array[i];
	delete[] m_array;
}

ostream& operator<< (ostream& os, const Array2D& arr) {
	for (int i = 0; i < arr.m_size; i++) {
		for (int j = 0; j < arr.m_size; j++) 
			cout << arr.m_array[i][j] << ' ';
		cout << endl;
	}
	return os;
}

void Array2D::swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Array2D::MirrorRight() {
	for (int i = 0; i < m_size; i++) 
		for (int j = 0; j < m_size / 2; j++) 
			swap(&m_array[i][j], &m_array[i][m_size - j - 1]);
}

void Array2D::MirrorDown() {
	for (int i = 0; i < m_size / 2; i++) 
		for (int j = 0; j < m_size; j++) 
			swap(&m_array[i][j], &m_array[m_size - i - 1][j]);
}

void Array2D::MirrorNE45() {
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size - i - 1; j++)
			swap(&m_array[i][j], &m_array[m_size - j - 1][m_size - i - 1]);
}

void Array2D::MirrorSE45() {
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < i; j++)
			swap(&m_array[i][j], &m_array[j][i]);
}