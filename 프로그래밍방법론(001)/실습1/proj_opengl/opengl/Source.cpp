/* Implement: Include header files */

#include <vector>
#include "Sphere.h"
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
	lights.push_back(Light(0, 100, 100, 0));
	lights.push_back(Light(200, 0, 0, 1));
	lights[0].setAmbient(0.1, 0.1, 0.1, 1.0);
	lights[0].setDiffuse(0.3, 0.3, 0.3, 1.0);
	lights[0].setSpecular(1.0, 1.0, 1.0, 1.0);
	lights[1].setAmbient(0.5, 0.5, 0.5, 1.0);
	lights[1].setDiffuse(0.5, 0.5, 0.5, 1.0);
	lights[1].setSpecular(1.0, 1.0, 1.0, 1.0);
}

void idle() {
	/* Implement: Change the rotation angle */
	angle += 0.5;
	glutPostRedisplay();
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
	lights[0].draw();
	sphere.draw();
	teapot.draw();
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	lights[1].draw();

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
