#include <iostream>
#include <vector>
#include "GL\glut.h"

using namespace std;

#include "Vec2.h"

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

vector<Vec2<double>> d_vectors;
vector<Vec2<float>> f_vectors;
vector<Vec2<int>> i_vectors;

void init() {
	/* Implement: calculate and store vectors */
	double x1, y1;
	cout << "1st vector a (double) (x, y):" << endl;
	cin >> x1 >> y1;
	d_vectors.push_back(Vec2<double>(x1, y1));

	float x2, y2;
	cout << "2nd vector b (float) (x, y):" << endl;
	cin >> x2 >> y2;
	f_vectors.push_back(Vec2<float>(x2, y2));

	int x3, y3;
	cout << "3rd vector c (int) (x, y):" << endl;
	cin >> x3 >> y3;
	i_vectors.push_back(Vec2<int>(x3, y3));

	d_vectors.push_back(d_vectors[0] + f_vectors[0]);
	d_vectors.push_back(d_vectors[0] - f_vectors[0]);
	d_vectors.push_back(d_vectors[0] * dotProduct(f_vectors[0], i_vectors[0]));
	d_vectors.push_back(d_vectors[0]);
	d_vectors[0] += i_vectors[0];
	d_vectors.push_back(d_vectors[0]);
	d_vectors[0] -= f_vectors[0];
	d_vectors.push_back(Vec2<double>(d_vectors[0][0] + f_vectors[0][0], d_vectors[0][1] - f_vectors[0][1]));
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
