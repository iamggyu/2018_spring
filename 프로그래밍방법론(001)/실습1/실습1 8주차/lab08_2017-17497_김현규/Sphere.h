#pragma once

#include <GL/glut.h>

class Sphere {
public:
	Sphere(float x, float y, float z, float r);
	~Sphere();

	void draw() const;

private:
	float *center_pos;
	float radius;
};