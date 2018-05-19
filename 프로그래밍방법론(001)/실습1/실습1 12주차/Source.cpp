#include <iostream>
#include <vector>

using namespace std;

#include "Vec2.h"

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

vector<Vec2<double>> d_vectors;
vector<Vec2<float>> f_vectors;
vector<Vec2<int>> i_vectors;

void init() {
	/* Implement: calculate and store vectors */
}

void renderScene() {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// coordinate axes
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();

	// draw vectors
	for (int i = 0; i < d_vectors.size(); i++)
		d_vectors[i].draw();
	for (int i = 0; i < f_vectors.size(); i++)
		f_vectors[i].draw();
	for (int i = 0; i < i_vectors.size(); i++)
		i_vectors[i].draw();

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Draw vectors using template");
	init();

	// register callbacks
	glutDisplayFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();
}
