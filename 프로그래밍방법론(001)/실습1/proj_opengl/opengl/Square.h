#pragma once
/* Implement: Define Square class */
#include "Shape.h"

class Square : public Shape {
public:
	Square(float sz);
	virtual void draw() const;
private:
	float size;
};