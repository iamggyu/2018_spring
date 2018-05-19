/* Implement: Define each function of Vec2 class */
#include "Vec2.h"

Vec2::Vec2() {
}
Vec2::Vec2(float x, float y) {
	pos[0] = x;
	pos[1] = y;
}
Vec2::Vec2(const Vec2& v) {
	pos[0] = v.pos[0];
	pos[1] = v.pos[1];
}
void Vec2::setPos(float x, float y) {
	pos[0] = x;
	pos[1] = y;
}
void Vec2::draw() const {
	glColor3f(1, 1, 1);
	glPointSize(5.0f);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(pos[0], pos[1]);
	glEnd();
	glBegin(GL_POINTS);
		glVertex2f(pos[0], pos[1]);
	glEnd();
}
float& Vec2::operator[](const unsigned int i) {
	if(i < 2)
		return pos[i];
}
Vec2& Vec2::operator+=(Vec2& v) {
	pos[0] += v.pos[0];
	pos[1] += v.pos[1];
	return *this;
}
Vec2& Vec2::operator-=(Vec2& v) {
	pos[0] -= v.pos[0];
	pos[1] -= v.pos[1];
	return *this;
}
Vec2& Vec2::operator*=(float s) {
	pos[0] *= s;
	pos[1] *= s;
	return *this;
}
Vec2& Vec2::operator/=(float s) {
	pos[0] /= s;
	pos[1] /= s;
	return *this;
}
Vec2 operator+(Vec2& v1, Vec2& v2) { 
	Vec2 newVec(v1);
	newVec += v2;
	return newVec;
}
Vec2 operator-(Vec2& v1, Vec2& v2) { 
	Vec2 newVec(v1);
	newVec -= v2;
	return newVec;
}
Vec2 operator*(Vec2& v1, float s) { 
	Vec2 newVec(v1);
	newVec *= s;
	return newVec;
}
Vec2 operator/(Vec2& v1, float s) { 
	Vec2 newVec(v1);
	newVec /= s;
	return newVec;
}