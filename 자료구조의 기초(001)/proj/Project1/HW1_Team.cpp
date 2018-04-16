#include "HW1_Team.h"

template <class T>
Team<T>::Team() {
	m_name = "";
	m_list = NULL;
	m_size = 0;
}

template <class T>
Team<T>::Team(string name, int size) {
	m_name.assign(name);
	m_size = size;
	m_list = new Player<T>[size];
}

template <class T>
Team<T>::~Team() {
	delete[] m_list;
}

template <class T>
Player<T>& Team<T>::operator[] (int i) {
	return m_list[i];
}

template <class T>
ostream& operator<< (ostream& os, const Team<T>& te) {
	os << "team : " << te.m_name << endl;
	for (int i = 0; i < te.m_size; i++)
		os << te.m_list[i] << endl;
	return os;
}

template <class T>
Team<T>& Team<T>::operator= (const Team<T>& te) {
	delete[] this->m_list;

	this->m_name.assign(te.m_name);
	this->m_size = te.m_size;
	this->m_list = new Player<T>[m_size];
	for (int i = 0; i < m_size; i++)
		m_list[i] = te.m_list[i];
	return *this;
}