#include "Grid.h"
#include "GL/glut.h"

Grid::Grid(int xx, int yy) {
	x = xx;
	y = yy;
}

void Grid::draw() {
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(x + 1, y+1);
	glVertex2f(x+1, y);
	glVertex2f(x, y);
	glVertex2f(x, y+1);
	glEnd();
}

