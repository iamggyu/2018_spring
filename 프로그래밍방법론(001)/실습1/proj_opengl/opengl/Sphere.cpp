/* Implement: Define each function of Sphere class */
#include "Sphere.h"

Sphere::Sphere(float x, float y, float z, float r) {
	center_pos = new float[3];
	center_pos[0] = x;
	center_pos[1] = y;
	center_pos[2] = z;
	radius = r;


	
}

Sphere::~Sphere() {
	delete[] center_pos;
}

void Sphere::draw() const {
	glShadeModel(GL_SMOOTH);
	float ambient[] = { 0.25,0.20725,0.20725,0.922 };
	float diffuse[] = { 1.0,0.829,0.829,0.922 };
	float specular[] = { 0.296648,0.296648,0.296648,0.922 };
	float shininess[] = { 11.264 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(center_pos[0], center_pos[1], center_pos[2]);
	glutSolidSphere(radius, 100, 100);
	glPopMatrix();
}