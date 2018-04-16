#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include "HW1_Player.h"

using namespace std;

template <class T>
class Team {
public:
	Team();
	Team(string, int);
	~Team();
	Player<T>& operator [] (int);
	template <class U>
	friend ostream& operator << (ostream&, const Team<U>&);
	Team& operator = (const Team&);
private:
	string m_name;
	Player<T>* m_list;
	int m_size;
};

#endif TEAM_H