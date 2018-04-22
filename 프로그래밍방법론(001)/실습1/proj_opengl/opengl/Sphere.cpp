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

}