#pragma once
#include <vector>
#include "Grid.h"

using namespace std;

class Player {
public:
	Player(int x, int y, float r, float g, float b);
	~Player();
	void draw(vector<vector<int>>& p);
	void setPos(int x, int y);
	void setDir(int d);
	void death();
	int getDir();
	int getX();
	int getY();
	string getLife();
	void trace(vector<vector<int>>& p); //draw path
	void move(vector<vector<int>>& p); //change pos according to its direction
	void expand(); // 


private:
	int * pos;
	float * color;
	int dir; // direction
	int life = 3;
	int kill;
	string lose = "You Lose!!!";
};