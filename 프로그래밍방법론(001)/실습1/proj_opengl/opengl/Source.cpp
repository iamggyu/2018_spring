#include <iostream>
#include <vector>
<<<<<<< HEAD
=======
#include "GL\glut.h"
>>>>>>> 0b621d251fee603fd6c43b8bba481c3b5bcbafd4

using namespace std;

#include "Vec2.h"

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

<<<<<<< HEAD
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
=======
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
>>>>>>> 0b621d251fee603fd6c43b8bba481c3b5bcbafd4
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

<<<<<<< HEAD
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
=======
	// draw vectors
	for (int i = 0; i < d_vectors.size(); i++)
		d_vectors[i].draw();
	for (int i = 0; i < f_vectors.size(); i++)
		f_vectors[i].draw();
	for (int i = 0; i < i_vectors.size(); i++)
		i_vectors[i].draw();
	(d_vectors[0] + f_vectors[0]).draw();
	(d_vectors[0] - f_vectors[0]).draw();
	(d_vectors[0] * dotProduct(f_vectors[0], i_vectors[0])).draw();
	(d_vectors[0] += i_vectors[0]).draw();
	(d_vectors[0] -= f_vectors[0]).draw();
	Vec2<double>(d_vectors[0][0] + f_vectors[0][0], d_vectors[0][1] - f_vectors[0][1]).draw();
>>>>>>> 0b621d251fee603fd6c43b8bba481c3b5bcbafd4

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
<<<<<<< HEAD
	glutCreateWindow("Draw vectors");
=======
	glutCreateWindow("Draw vectors using template");
>>>>>>> 0b621d251fee603fd6c43b8bba481c3b5bcbafd4
	init();

	// register callbacks
	glutDisplayFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();
}
