#pragma once

#include <GL/glut.h>

class Sphere {
public:
	Sphere();
	Sphere(float x, float y, float z, float r);
	Sphere(const Sphere& sph);
	~Sphere();

	void setPos(float x, float y, float z);
	void setRadius(float r);
	void draw() const;

	inline float getX() const;
	inline float getY() const;
	inline float getZ() const;
	inline float getRadius() const;
	
	Sphere& operator=(const Sphere& sph);

private:
	float *center_pos;
	float radius;
};