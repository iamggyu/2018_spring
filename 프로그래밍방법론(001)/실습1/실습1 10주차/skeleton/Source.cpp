#include <time.h>

using namespace std;

/* Implement: Include header file(s) */
/* Implement: Control FPS if you need */
#include "Square_solution.h"

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

int sp_key;				// special key

Square sq(0, 0, 1, 1, 0, 0.2);

void processSpecialKeys(int key, int x, int y) {
	/* Implement: Set key input */
}

void idle() {
	/* Implement: Move the square */
}

void renderScene() {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	sq.draw();

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Drawing Square & Equilateral Triangle");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();
}
