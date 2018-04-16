#ifndef LEAGUE_H
#define LEAGUE_H

#include <iostream>
#include <string>
#include "HW1_Team.h"

using namespace std;

template <class T>
class League {
public:
	League();
	League(string, int);
	~League();
	Team<T>& operator [] (int);
	template <class U>
	friend ostream& operator << (ostream&, const League<U>&);
	League& operator = (const League&);
private:
	string m_name;
	Team<T>* m_list;
	int m_size;
};

#endif LEAGUE_H
