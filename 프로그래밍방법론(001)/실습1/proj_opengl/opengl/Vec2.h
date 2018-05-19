#pragma once

#include <GL/glut.h>

using namespace std;

class Vec2 {
public:
	Vec2();
	Vec2(float x, float y);
	Vec2(const Vec2& v);

	void setPos(float x, float y);
	void draw() const;

	float& operator[](const unsigned int i);

	Vec2& operator+=(Vec2& v);
	Vec2& operator-=(Vec2& v);
	Vec2& operator*=(float s);
	Vec2& operator/=(float s);

private:
	float pos[2];
};

Vec2 operator+(Vec2& v1, Vec2& v2);
Vec2 operator-(Vec2& v1, Vec2& v2);
Vec2 operator*(Vec2& v, float s);
Vec2 operator/(Vec2& v, float s);