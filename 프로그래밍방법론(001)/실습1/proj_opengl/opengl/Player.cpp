#include "Player.h"
#include "GL/glut.h"
#include <string>


Player::Player(int x, int y, float r, float g, float b) {
	pos = new int[2];
	pos[0] = x;
	pos[1] = y;

	color = new float[3];
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

Player::~Player() {
	delete[] pos;
	delete[] color;
}

void Player::draw(vector<vector<int>>& p) {

	glBegin(GL_QUADS);
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < p[i].size(); j++) {
			if (p[i][j] == 0)
				glColor3f(0, 0, 0);
			if(p[i][j] == 1)
				glColor3f()
			glVertex2f(i, j);
			glVertex2f(i + 1, j);
			glVertex2f(i + 1, j + 1);
			glVertex2f(i, j + 1);
		}
	}


	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_POLYGON);
	glVertex2f(pos[0], pos[1]);
	glVertex2f(pos[0] + 1, pos[1]);
	glVertex2f(pos[0] + 1, pos[1] + 1);
	glVertex2f(pos[0], pos[1] + 1);
	glEnd();
}
void Player::setPos(int x ,int y) {
	pos[0] = x;
	pos[1] = y;
}

void Player::setDir(int d) {
	dir = d;
}
void Player::death() {
	life--;
	if (life == 0) {
		glRasterPos2f(50, 50);
		for (int i = 0; i < lose.length(); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, lose[i]);
	}
}

string Player::getLife() {
	return to_string(life);
}

int Player::getDir() {
	return dir;
}
int Player::getX() {
	return pos[0];
}
int Player::getY() {
	return pos[1];
}
void Player::trace(vector<vector<int>>& p) {
	
}

void Player::move(vector<vector<int>>& p) {
	switch (dir) {
	case 0:
		if (pos[0] > 1) {
			pos[0]--;
			if (p[pos[0]][pos[1]] == 1) {
				death();
			}
			if (p[pos[0]][pos[1]] == 0) {
				p[pos[0]][pos[1]] = 1;
			}
			
		}
		break;
	case 1:
		if (pos[0] + 1 < 99) {
			pos[0]++;
			if (p[pos[0]][pos[1]] == 1) {
				death();
			}
			if (p[pos[0]][pos[1]] == 0) {
				p[pos[0]][pos[1]] = 1;
			}
		}
		break;
	case 2:
		if (pos[1] + 1 < 99) {
			pos[1]++;
			if (p[pos[0]][pos[1]] == 1) {
				death();
			}
			if (p[pos[0]][pos[1]] == 0) {
				p[pos[0]][pos[1]] = 1;
			}
			
		}
		break;
	case 3:
		if (pos[1] > 1) {
			pos[1]--;
			if (p[pos[0]][pos[1]] == 1) {
				death();
			}
			if (p[pos[0]][pos[1]] == 0) {
				p[pos[0]][pos[1]] = 1;
			}
		}
		break;
	}
}
void Player::expand() {
	//flood fill
}