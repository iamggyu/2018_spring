/* Implement: Define each function of Teapot clas/* Implement: Define each function of Sphere class */
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

}