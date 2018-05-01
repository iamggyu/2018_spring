/* Implement: Include header files */
#include <vector>

using namespace std;

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

vector<Shape*> shape;

void init() {
	/* Implement: Set each object */
	shape.push_back(new Triangle(0.2));
	shape.push_back(new Square(0.3));
}

void idle() {
	/* Implement: Move each object */
}

void renderScene() {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Implement: Draw each object */
	/* Implement: Display character*/

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Drawing Square & Equilateral Triangle");
	init();

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();
}
