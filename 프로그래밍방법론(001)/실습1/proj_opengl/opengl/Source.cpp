#include <iostream>
#include <vector>

using namespace std;

#include "Vec2.h"

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

vector<Vec2> vectors;
int p;

void init() {
	/* Implement: calculate and store vectors */
	float x, y;
	cout << "1st vector a (x, y):" << endl;
	cin >> x >> y;
	vectors.push_back(Vec2(x, y));

	cout << "2nd vector b (x, y):" << endl;
	cin >> x >> y;
	vectors.push_back(Vec2(x, y));

	cout << "3rd vector c (x, y):" << endl;
	cin >> x >> y;
	cin.ignore(10, '\n');
	vectors.push_back(Vec2(x, y));

	cout << "scalar:" << endl;
	cin >> p;
	vectors.pu
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

	/* draw vectors */
	vectors[0].draw();
	vectors[1].draw();
	vectors[2].draw();
	(vectors[0] + vectors[1]).draw();
	(vectors[0] - vectors[1]).draw();
	(vectors[0] * p).draw();
	(vectors[0] / p).draw();
	(vectors[0] += vectors[2]).draw();
	(vectors[0] -= vectors[1]).draw();
	(vectors[1] *= p).draw();
	(vectors[1] /= p * p).draw();
	(Vec2(vectors[0][0] + vectors[1][0], vectors[0][1] - vectors[1][1])).draw();

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Draw vectors");
	init();

	// register callbacks
	glutDisplayFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();
}
