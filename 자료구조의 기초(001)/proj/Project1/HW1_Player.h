#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Player {
public:
	Player();
	Player(string, T, T);
	~Player();
	template <class U>
	friend ostream& operator << (ostream&, const Player<U>&);
	Player& operator = (const Player&);
private:
	string m_name;
	T m_height, m_weight;
};

#endif PLAYER_H