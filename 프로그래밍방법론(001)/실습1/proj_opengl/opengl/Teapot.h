#pragma once

#include <GL/glut.h>

class Teapot {
public:
	Teapot(float x, float y, float z, float s);
	~Teapot();

	void draw() const;

private:
	float *center_pos;
	float size;
};