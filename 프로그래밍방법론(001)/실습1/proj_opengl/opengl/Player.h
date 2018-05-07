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
	void setLife(int n);
	void death(vector<vector<int>>& p);
	int getDir();
	int getX();
	int getY();
	string getLife();
	void trace(vector<vector<int>>& p); //draw path
	void move(vector<vector<int>>& p); //change pos according to its direction
	void expand(vector<vector<int>>& p); // 
	string getRatio();
	int getIntRatio();


private:
	int * pos;
	float * color;
	int dir; // direction
	int life = 3;
	int kill;
	int dy[4] = { 0,1,-1,0 };
	int dx[4] = { 1,0,0,-1 };
	int ratio = 2;
};