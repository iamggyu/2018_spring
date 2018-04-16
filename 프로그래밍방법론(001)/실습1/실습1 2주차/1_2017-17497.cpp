#include <cstdlib>
#include <ctime>
#include <iostream>
#include <GL/glut.h>
#define GET_COLOR (rand() * 1.0 / RAND_MAX)
#define PI 3.14159265358979323846

int n;

void drawPoint() {

	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	srand((unsigned int)time(NULL));

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	{
		glVertex2f(0.0, 0.0);

		//draw first point and store color value
		double first_color[3] = { GET_COLOR, GET_COLOR, GET_COLOR };
		glColor3f(first_color[0], first_color[1], first_color[2]);
		glVertex2f(0, 0.5);

		//draw another points
		for (int i = 1; i < n; i++)
		{
			double y = 0.5 * std::cos(PI * 2 / n * i);
			double x = 0.5 * std::sin(PI * 2 / n * i);
			glColor3f(GET_COLOR, GET_COLOR, GET_COLOR);
			glVertex2f(x, y);
		}

		//draw last points. use same color as first point
		glColor3f(first_color[0], first_color[1], first_color[2]);
		glVertex2f(0, 0.5);
	}
	glEnd();

	glutSwapBuffers();
}

void main(int argc, char **argv) {

	std::cin >> n;

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Hello OpenGL!");

	// register callbacks
	glutDisplayFunc(drawPoint);

	// enter GLUT event processing cyclea
	glutMainLoop();
}
