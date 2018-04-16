#include <string>
#include <fstream>
#include <vector>
#include <GL/glut.h>

using namespace std;

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

class vertex {
public:
	/* Implement constructor, setter, getter */

private:
	float pos[3];
};

class face {
public:
	/* Implement constructor, draw function */

private:
	vertex vtx[3];
};

class obj {
public:
	void draw();
	void ReadFromOBJFile(string filename);

private:
	vector<face> vFace;
};

void obj::draw() {
	/* Implement: draw all faces */
}

void obj::ReadFromOBJFile(string filename) {
	vector<vertex> vertices;
	ifstream input(filename);

	char sub;
	while (input >> sub) {
		if (sub == 'v') {
			/* Implement: read vertex data */
		}
		else if (sub == 'f') {
			/* Implement: read face data */
		}
	}
}

obj Cube;
float angle = 0;

void idle() {
	/* Implement: Change the rotation angle */
}

void renderScene() {
	glEnable(GL_DEPTH_TEST);
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
	gluLookAt(8.0f, 5.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	Cube.draw();

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	/* Implement: Read data from OBJ file */

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Drawing cube from obj");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();
}
