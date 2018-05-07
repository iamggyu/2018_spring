#include <time.h>
#include "GL\glut.h"

using namespace std;

/* Implement: Include header file(s) */
/* Implement: Control FPS if you need */
#include "Square.h"

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

int sp_key;				// special key
int speed = 0.01;

clock_t start = clock();
clock_t end;

Square sq(0, 0, 1, 1, 0, 0.2);

void processSpecialKeys(int key, int x, int y) {
	/* Implement: Set key input */
	switch (key) {
	case GLUT_KEY_UP: sp_key = 0; break;
	case GLUT_KEY_LEFT: sp_key = 1; break;
	case GLUT_KEY_DOWN: sp_key = 2; break;
	case GLUT_KEY_RIGHT: sp_key = 3; break;
	}
}

void idle() {
	/* Implement: Move the square */
	end = clock();

	if (end - start > 1000 / 30) {
		float x = sq.getX(), y = sq.getY();
		switch (sp_key) {
		case 0: y += 0.02; break;
		case 1: x -= 0.02; break;
		case 2: y -= 0.02; break;
		case 3: x += 0.02; break;
		}
		sq.setPos(x, y);
		
		start = end;
	}
	sq.draw();

	glutPostRedisplay();
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
