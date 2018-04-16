#include "HW1_League.h"

template <class T>
League<T>::League() {
	m_name = "";
	m_size = 0;
	m_list = NULL;
}

template <class T>
League<T>::League(string name, int size) {
	m_name.assign(name);
	m_size = size;
	m_list = new Team<T>[size];
}

template <class T>
League<T>::~League() {
	delete[] m_list;
}

template <class T>
Team<T>& League<T>::operator[] (int i) {
	return m_list[i];
}

template <class T>
ostream& operator<< (ostream& os, const League<T>& leag) {
	os << "league : " << leag.m_name << endl;
	for (int i = 0; i < leag.m_size; i++)
		os << leag.m_list[i];
	return os;
}

template <class T>
League<T>& League<T>::operator= (const League<T>& leag) {
	delete[] m_list;

	this->m_name.assign(leag);
	this->m_size = leag.m_size;
	this->m_list = new Team<T>[m_size];
	for (int i = 0; o < m_size; i++)
		m_list[i] = leag.m_list[i];
	return leag;
}