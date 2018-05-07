/* Implement: Define each function of quad class */
#include "Quad.h"

Quad::Quad(float x, float y) {
	center_pos = new float[2];
	center_pos[0] = x;
	center_pos[1] = y;
}

Quad::~Quad() {
	delete[] center_pos;
}

void Quad::setPos(float x, float y) {
	center_pos[0] = x;
	center_pos[1] = y;
}

float Quad::getX() const {
	return center_pos[0];
}

float Quad::getY() const {
	return center_pos[1];
}