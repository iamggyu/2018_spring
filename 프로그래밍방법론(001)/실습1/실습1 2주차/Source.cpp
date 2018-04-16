#include <iostream>
#include <GL/glut.h>
#include <math.h>

#define PI 3.141592
int num;

void drawPolygon(float center_x, float center_y, float center_z, float radius) {
	float r, g, b;

	glBegin(GL_POLYGON);
		// implement here
	glEnd();
}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawPolygon(0, 0, 0, 0.5);

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	std::cout << "How many sides does the polygon have? : ";
	std::cin >> num;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Polygon");

	// register callbacks
	glutDisplayFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();
}
