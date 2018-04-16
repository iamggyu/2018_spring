#include <iostream>
#include <GL/glut.h>

#define WIDTH 500		// window's width
#define HEIGHT 500		// window's height


class Color {
public:
	void setColor(float _r, float _g, float _b) {
		r = _r;
		g = _g;
		b = _b;
	}
	float getRed() const { return r; }
	float getGreen() const { return g; }
	float getBlue() const { return b; }
	float r, g, b;
};
class Vertex {
public:
	Vertex() {}
	Vertex(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	void draw() const {
		glPointSize(size);
		glBegin(GL_POINTS);
			glColor3f(color.getRed(), color.getGreen(), color.getBlue());
			glVertex3f(x, y, z);
		glEnd();
	}
	void setColor(float r, float g, float b) {
		color.setColor(r, g, b);
	}
	void setVertex(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	void setSize(float _size) { size = _size; }
	float getX() const { return x; }
	float getY() const { return y; }
	float getZ() const { return z; }
	float getSize() const { return size; }
	float x, y, z, size;
	Color color;
};

class Triangle {
public:
	Triangle(float x1, float y1, float z1, float x2, 
		float y2, float z2, float x3, float y3, float z3) {
		vertex[0].setVertex(x1, y1, z1);
		vertex[1].setVertex(x2, y2, z2);
		vertex[2].setVertex(x3, y3, z3);
	}
	void setColor(float r, float g, float b) {
		color.setColor(r, g, b);
	}
	void draw() const {
		glBegin(GL_TRIANGLES);
		glColor3f(color.getRed(), color.getGreen(), color.getBlue());
			glVertex3f(vertex[0].getX(), vertex[0].getY(), vertex[0].getZ());
			glVertex3f(vertex[1].getX(), vertex[1].getY(), vertex[1].getZ());
			glVertex3f(vertex[2].getX(), vertex[2].getY(), vertex[2].getZ());
		glEnd();
	}
	Color color;
	Vertex vertex[3];
};

class Line {
public:
	Line(float x1, float y1, float z1, float x2
		, float y2, float z2) {
		vertex[0].setVertex(x1, y1, z1);
		vertex[1].setVertex(x2, y2, z2);
	}
	void setColor(float r, float g, float b) {
		color.setColor(r, g, b);
	}
	void draw() const {
		glLineWidth(width);
		glBegin(GL_LINES);
		glColor3f(color.getRed(), color.getGreen(), color.getBlue());
			glVertex3f(vertex[0].getX(), vertex[0].getY(), vertex[0].getZ());
			glVertex3f(vertex[1].getX(), vertex[1].getY(), vertex[1].getZ());
		glEnd();
	}
	void setWidth(float _width) {
		width = _width;
	}
	float width;
	Color color;
	Vertex vertex[2];
};

void renderScene(void) {
	glClearColor(1, 1, 1, 1);

	glClear(GL_COLOR_BUFFER_BIT);

	/* Implement: Declare objects of point, line and triangle */
	Vertex v(0, 0.5, 0);
	Line l(-0.5, 0, 0, 0.5, 0, 0);
	Triangle t(0, -0.25, 0, -0.5, -0.75, 0, 0.5, -0.75, 0);

	/* Implement: Set colors of point, line and triangle */
	v.setColor(1, 0, 0);
	l.setColor(0, 1, 0);
	t.setColor(0, 0, 1);

	/* Implement: Set size of point and width of line*/
	v.setSize(20.0);
	l.setWidth(10.0);

	/* Implement: Draw each point, line and triangle */
	v.draw();
	l.draw();
	t.draw();

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Basic class exmaple");

	// register callbacks
	glutDisplayFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();
}