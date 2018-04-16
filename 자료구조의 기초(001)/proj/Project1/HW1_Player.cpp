#include "HW1_Player.h"

template <class T>
Player<T>::Player() {
	m_name = "";
	m_height = 0;
	m_weight = 0;
}

template <class T>
Player<T>::Player(string name, T height, T weight) {
	m_name.assign(name);
	m_height = height;
	m_weight = weight;
}

template <class T>
Player<T>::~Player() {
}

template <class T>
ostream& operator<< (ostream& os, const Player<T>& pl) {
	os << "name : " << pl.m_name << " / height : " << 
		pl.m_height << "cm, weight : " << pl.m_weight << "kg";
	return os;
}

template<class T>
Player<T>& Player<T>::operator=(const Player<T>& pl) {
	this->m_name.assign(pl.m_name);
	this->m_height = pl.m_height;
	this->m_weight = pl.m_weight;
	return *this;
}