#include "sphere.h"
/* Implement: Define each function of Sphere class */

void Sphere::draw() const {
	/* Implement: Draw sphere using glutSolidSphere(), glPushMatrix(), glPopMatrix() */
	glPushMatrix();
	glTranslatef(center_pos[0], center_pos[1], center_pos[2]);
	glutSolidSphere(radius, 10, 10);
	glPopMatrix();

	// Material setting
	float mat_emission[] = { 0.3, 0.0, 0.0, 1.0 };
	float mat_ambient[] = { 1.0, 0.5, 0.2, 1.0 };
	float mat_diffuse[] = { 0.3, 0.5, 0.5, 1.0 };
	float mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float mat_shininess[] = { 50 };

	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

}

Sphere::Sphere() {
	center_pos = new float[3];
	center_pos[0] = 0;
	center_pos[1] = 0;
	center_pos[2] = 0;
	radius = 0;
}

Sphere::Sphere(float x, float y, float z, float r) {
	center_pos = new float[3];
	center_pos[0] = x;
	center_pos[1] = y;
	center_pos[2] = z;
	radius = r;
}

Sphere::Sphere(const Sphere& sph) {
	center_pos = new float[3];
	center_pos[0] = sph.center_pos[0];
	center_pos[1] = sph.center_pos[1];
	center_pos[2] = sph.center_pos[2];
}

Sphere::~Sphere() {
	delete[] center_pos;
}

void Sphere::setPos(float x, float y, float z) {
	center_pos[0] = x;
	center_pos[1] = y;
	center_pos[2] = z;
}

void Sphere::setRadius(float r) {
	radius = r;
}

Sphere& Sphere::operator=(const Sphere& sph) {
	center_pos[0] = sph.center_pos[0];
	center_pos[1] = sph.center_pos[1];
	center_pos[2] = sph.center_pos[2];
	radius = sph.radius;
	return (*this);
}