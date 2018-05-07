#pragma once
#include "Quad.h"
#include "Color.h"

/* Implement: Define Quad class */
class Square : public Quad, public Color {
public:
	Square(float x, float y, float r, float g, float b, float sl);
	~Square();

	virtual void draw() const;
	float getSideLength() const;

private:
	float* side_length;
};