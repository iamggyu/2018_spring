/* Implement: Define each function of Teapot class */
#include "Teapot.h"

Teapot::Teapot(float x, float y, float z, float r) {
	center_pos = new float[3];
	center_pos[0] = x;
	center_pos[1] = y;
	center_pos[2] = z;
	size = r;
}

Teapot::~Teapot() {
	delete[] center_pos;
}

void Teapot::draw() const {
	glShadeModel(GL_SMOOTH);
	float ambient[] = { 0.1745,0.01175,0.01175,0.55 };
	float diffuse[] = { 0.61424,0.04136,0.04136,0.55 };
	float specular[] = { 0.727811,0.626959,0.626959,0.55 };
	float shininess[] = { 76.8 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(center_pos[0], center_pos[1], center_pos[2]);
	glutSolidTeapot(size);
	glPopMatrix();
}