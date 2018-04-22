/* Implement: Include header files */
#include <vector>
#include "sphere.h"
#include "Teapot.h"
#include "Light.h"

using namespace std;

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

Sphere sphere(0, 0, 5, 3);
Teapot teapot(5, 0, -5, 4);
vector<Light> lights;
float angle = 0;

void init() {
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

	/* Implement: Set light properties */
	lights.push_back(Light());
	lights.push_back(Light());
}

void idle() {
	/* Implement: Change the rotation angle */
	angle += 0.1;
}

void renderScene() {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the correct perspective.
	gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);

	// Reset transformations
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Set the camera
	gluLookAt(25.0f, 25.0f, 25.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	/* Implement: draw each object */

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Drawing pearl sphere & ruby teapot");
	init();

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();
}
