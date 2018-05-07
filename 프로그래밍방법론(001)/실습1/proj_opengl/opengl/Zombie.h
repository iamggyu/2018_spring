#pragma once
#pragma once
#include <vector>
#include "Grid.h"
#include "Player.h"

using namespace std;

class Zombie {
public:
	Zombie(int x, int y, float r, float g, float b);
	~Zombie();
	void draw();
	void setPos(int x, int y);
	int getX();
	int getY();
	void movekill(vector<vector<int>>& p, Player& pl);
	void remove();

private:
	int * pos;
	float * color;
	int dir; // direction
	int life;


};