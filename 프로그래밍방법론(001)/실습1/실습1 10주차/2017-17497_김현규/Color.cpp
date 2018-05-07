/* Implement: Define each function of Color class */
#include "Color.h"

Color::Color(float r, float g, float b) {
	color = new float[3];
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

Color::~Color() {
	delete[] color;
}

void Color::setColor(float r, float g, float b) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
}