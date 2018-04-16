/* Implement: Include sphere.h */

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

Sphere sphere1(0, 0, 0, 3);	// Constructor with argument
Sphere sphere2(sphere1);	// Copy constructor
Sphere sphere3;				// Default constructor
float angle = 0;			// Rotation angle

void init() {
	sphere3 = sphere1;		// Assignment operator

	/* Set center position and size of each sphere */

	// Light setting
	float light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	float light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	float light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float light_position[] = { 5.0, 5.0, 5.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void idle() {
	/* Implement: Change the rotation angle */
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

	/* Implement: Rotate spheres */

	sphere1.draw();
	sphere2.draw();
	sphere3.draw();

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Drawing spheres");
	init();

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();
}
