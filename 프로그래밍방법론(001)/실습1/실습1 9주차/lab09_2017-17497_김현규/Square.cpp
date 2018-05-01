/* Implement: Define each function of Square class */
#include "Square.h"
#include "GL\glut.h"

Square::Square(float sz) {
	size = sz;
}

void Square::draw() const {
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_QUADS);
		glVertex2f(pos[0] - size / 2.0, pos[1] - size / 2.0);
		glVertex2f(pos[0] - size / 2.0, pos[1] + size / 2.0);
		glVertex2f(pos[0] + size / 2.0, pos[1] + size / 2.0);
		glVertex2f(pos[0] + size / 2.0, pos[1] - size / 2.0);
	glEnd();
}