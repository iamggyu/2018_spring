#include <iostream>
#include <GL/glut.h>

#define WIDTH 500		// window's width
#define HEIGHT 500		// window's height

void renderScene(void) {
	glClearColor(1, 1, 1, 1);

	glClear(GL_COLOR_BUFFER_BIT);

	/* Implement: Declare objects of point, line and triangle */
	/* Implement: Set colors of point, line and triangle */
	/* Implement: Set size of point and width of line*/
	/* Implement: Draw each point, line and triangle */

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
