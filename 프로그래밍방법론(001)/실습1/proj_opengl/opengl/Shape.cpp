#include "Shape.h"

void Shape::setColor(float r, float g, float b) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void Shape::setPos(float x, float y) {
	pos[0] = x;
	pos[1] = y;
}

float Shape::getX() const {
	return pos[0];
}

float Shape::getY() const {
	return pos[1];
}