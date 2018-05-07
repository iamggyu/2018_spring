#include "Zombie.h"
#include "GL/glut.h"

Zombie::Zombie(int x, int y, float r, float g, float b) {
	pos = new int[2];
	pos[0] = x;
	pos[1] = y;

	color = new float[3];
	color[0] = r;
	color[1] = g;
	color[2] = b;
}
Zombie::~Zombie() {
	delete[] pos;
	delete[] color;
}
void Zombie::draw() {
	if (isAlive == 0) return;
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_POLYGON);
	glVertex2f(pos[0], pos[1]);
	glVertex2f(pos[0]+1, pos[1]);
	glVertex2f(pos[0]+1, pos[1]+1);
	glVertex2f(pos[0], pos[1]+1);
	glEnd();
}
void Zombie::setPos(int x, int y) {
	pos[0] = x;
	pos[1] = y;
}
void Zombie::setDir(int d) {
	dir = d;
}
int Zombie::getX() {
	return pos[0];
}
int Zombie::getY() {
	return pos[1];
}
int Zombie::getIsAlive() {
	return isAlive;
}
void Zombie::movekill(vector<vector<int>>& p, Player& pl) {
	if (p[pos[0]][pos[1]] == 2) isAlive = 0;
	switch (dir) {
	case 0:
		if (pos[0] > 1 && p[pos[0]-1][pos[1]] != 2) pos[0]--;
		break;
	case 1:
		if (pos[0] + 1 < 99 && p[pos[0] + 1][pos[1]] != 2) pos[0]++;
		break;
	case 2:
		if (pos[1] + 1 < 99 && p[pos[0]][pos[1]+1] != 2) pos[1]++;
		break;
	case 3:
		if (pos[1] > 1 && p[pos[0]][pos[1]-1] != 2) pos[1]--;
		break;
	default:
		pos[0] = pos[0];
		pos[1] = pos[1];
	}
	if (p[pos[0]][pos[1]] == 1) pl.death(p);
}
void Zombie::remove() {

}