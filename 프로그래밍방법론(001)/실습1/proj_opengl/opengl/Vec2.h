#pragma once

/* Implement: Define Vec2 class */

template<typename T>
class Vec2 {
public:
	Vec2() {}
	Vec2(const T& a, const T& b) { val[0] = a; val[1] = b; }
	Vec2(const Vec2<T>& v) { val[0] = v.val[0]; val[1] = v.val[1]; }

	void setPos(const T& a, const T& b);
	void draw() const;

	const T& operator[](std::size_t i) const; 

private:
	T val[2];
};

template<typename T>
const T& Vec2<T>::operator[](std::size_t i) const {
	return val[i];
}

template<typename T>
void Vec2<T>::setPos(const T& a, const T& b) { val[0] = a; val[1] = b; }

template<typename T, typename S>
Vec2<T> operator+(const Vec2<T>& a, const Vec2<S>& b) {
	return Vec2<T>(a[0] + b[0], a[1] + b[1]);
}

template<typename T, typename S>
Vec2<T> operator-(const Vec2<T>& a, const Vec2<S>& b) {
	return Vec2<T>(a[0] - b[0], a[1] - b[1]);
}

template<typename T, typename S>
Vec2<T> operator*(const Vec2<T>& a, const S& b) {
	return Vec2<T>(a[0] * b, a[1] * b);
}

template<typename T, typename S>
Vec2<T> operator+=(Vec2<T>& a, const Vec2<S>& b) {
	a.setPos(a[0] + b[0], a[1] + b[1]);
	return a;
}

template<typename T, typename S>
Vec2<T> operator-=(Vec2<T>& a, const Vec2<S>& b) {
	a.setPos(a[0] - b[0], a[1] - b[1]);
	return a;
}

template<typename T, typename S>
T dotProduct(Vec2<T> a, Vec2<S> b) {
	return a[0] * b[0] + a[1] * b[1];
}

template<typename T>
void Vec2<T>::draw() const {
	glColor3f(1, 1, 1);
	glPointSize(5.0f);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(val[0], val[1]);
	glEnd();
	glBegin(GL_POINTS);
	glVertex2f(val[0], val[1]);
	glEnd();
}