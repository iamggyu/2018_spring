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
int Zombie::getX() {
	return pos[0];
}
int Zombie::getY() {
	return pos[1];
}
void Zombie::movekill(vector<vector<int>>& p, Player& pl) {
	switch (rand() % 4) {
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
	}
	if (p[pos[0]][pos[1]] == 1) pl.death();
}
void Zombie::remove() {

}