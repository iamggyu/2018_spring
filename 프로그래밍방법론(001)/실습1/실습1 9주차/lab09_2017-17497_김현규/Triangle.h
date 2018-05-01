#pragma once
/* Implement: Define EquiTri class */
#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle(float r);
	virtual void draw() const;
private:
	float radius;
};
