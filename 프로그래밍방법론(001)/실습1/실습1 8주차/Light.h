#pragma once

#include <GL/glut.h>

class Light {
public:
	Light();
	Light(float x, float y, float z, int L_ID);
	Light(const Light& Lt);
	~Light();

	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpecular(float r, float g, float b, float a);

	void draw() const;

private:
	int lightID;
	float *center_pos;
	float *ambient;
	float *diffuse;
	float *specular;
};