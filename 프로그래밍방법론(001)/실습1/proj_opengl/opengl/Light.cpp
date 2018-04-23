/* Implement: Define each function of Light class */
#include "Light.h"

Light::Light() {
	lightID = 0;
	center_pos = new float[3];
	ambient = new float[4];
	diffuse = new float[4];
	specular = new float[4];
}

Light::Light(float x, float y, float z, int L_ID) {
	lightID = L_ID;
	center_pos = new float[3];
	ambient = new float[4];
	diffuse = new float[4];
	specular = new float[4];
	center_pos[0] = x;
	center_pos[1] = y;
	center_pos[2] = z;
}

Light::Light(const Light& Lt) {
	lightID = Lt.lightID;
	center_pos = new float[3];
	ambient = new float[4];
	diffuse = new float[4];
	specular = new float[4];
	for (int i = 0; i < 3; i++) center_pos[i] = Lt.center_pos[i];
	for (int i = 0; i < 4; i++) {
		ambient[i] = Lt.ambient[i];
		diffuse[i] = Lt.diffuse[i];
		specular[i] = Lt.specular[i];
	}
}

Light::~Light() {
	delete[] center_pos;
	delete[] ambient;
	delete[] diffuse;
	delete[] specular;
}

void Light::setAmbient(float r, float g, float b, float a) {
	ambient[0] = r;
	ambient[1] = g;
	ambient[2] = b;
	ambient[3] = a;
}

void Light::setDiffuse(float r, float g, float b, float a) {
	diffuse[0] = r;
	diffuse[1] = g;
	diffuse[2] = b;
	diffuse[3] = a;
}

void Light::setSpecular(float r, float g, float b, float a) {
	specular[0] = r;
	specular[1] = g;
	specular[2] = b;
	specular[3] = a;
}

void Light::draw() const {
	float light_position[] = { center_pos[0], center_pos[1], center_pos[2], 1.0 };
	glLightfv(GL_LIGHT0 + lightID, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0 + lightID, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0 + lightID, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0 + lightID, GL_POSITION, light_position);
	glEnable(GL_LIGHT0 + lightID);
}