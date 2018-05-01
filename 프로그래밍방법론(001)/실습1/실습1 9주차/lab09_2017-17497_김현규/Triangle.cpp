/* Implement: Define each function of Triangle class */
#include "Triangle.h"
#include "GL\glut.h"
#include <math.h>

Triangle::Triangle(float r) {
	radius = r;
}

void Triangle::draw() const {
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_TRIANGLES);
		glVertex2f(pos[0], pos[1] + radius);
		glVertex2f(pos[0] - radius * sqrt(3) / 2.0, pos[1] - radius / 2.0);
		glVertex2f(pos[0] + radius * sqrt(3) / 2.0, pos[1] - radius / 2.0);
	glEnd();
}