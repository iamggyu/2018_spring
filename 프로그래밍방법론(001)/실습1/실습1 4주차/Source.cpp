#include <iostream>
#include <GL/glut.h>

#define WIDTH 500		// window's width
#define HEIGHT 500		// window's height

const int size = 1000;		// vertex size
int vertex_num;				// number of vertex
float** vertex;				// respective vertex position
float** vertex_color;		// respective vertex color
float color[3];				// current color
int menu_number;			// option

void initVertex() {
	vertex_num = 0;

	/* Implement: Allocate vertex & vertex_color dynamically */
	vertex = new float*[size];
	for (int i = 0; i < size; i++)
		vertex[i] = new float[2];
}

void clearVertex() {
	/* Implement: De-allocate vertex & vertex_color */
	for (int i = 0; i < size; i++)
		delete[] vertex[i];
	delete[] vertex;
}

void init() {
	initVertex();

	color[0] = color[1] = color[2] = 1;
	menu_number = 0;
}

void drawPoint() {
	/* Implement: Display Point */
}

void drawLine() {
	/* Implement: Display Line */
}

void drawTriangle() {
	/* Implement: Display Triangle */
}
 void drawPolygon() {
	/* Implement: Display Polygon */
}

void processNormalKeys(unsigned char key, int x, int y) {
	printf("You pressed %c at (%d, %d)\n", key, x, y);
	/* Implement: Change vertex color to be drawn next */
	color[0] = key & 1;
	color[1] = key & 2;
	color[2] = key & 4;
}

void processMouse(int button, int state, int x, int y) {
	printf("Mouse button is clicked! (%d, %d, %d, %d)\n", button, state, x, y);
	/* Implement: Map window coordinate to screen coordinate */
	/* Implement: Store it (its color) into vertex (vertex_color) */
	vertex[vertex_num][0] = (x / (WIDTH / 2)) - 1;
	vertex[vertex_num++][1] = y;}

void sub_menu_function(int option) {
	printf("Sub menu %d has been selected\n", option);
	menu_number = option;
	/* implement if you need */
	glutPostRedisplay();
}

void main_menu_function(int option) {
	printf("Main menu %d has been selected\n", option);
	if (option == 999) {
		clearVertex();
		exit(0);
	}
	else if (option == 0) {
		clearVertex();
		initVertex();

		glClear(GL_COLOR_BUFFER_BIT);
		glutSwapBuffers();
	}
}

void renderScene(void) {
	glClearColor(0, 0, 0, 0);

	glClear(GL_COLOR_BUFFER_BIT);

	if (menu_number == 1)
		drawPoint();
	else if (menu_number == 2 || menu_number == 3 || menu_number == 4)
		drawLine();
	else if (menu_number == 5 || menu_number == 6 || menu_number == 7)
		drawTriangle();
	else if (menu_number == 8 || menu_number == 9 || menu_number == 10)
		drawPolygon();

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Menu selection & Drawing Primitives");
	init();

	/* Implement: Create Popup Menu */
	int mainmenu, submenu, polygonMode;
	polygonMode = glutCreateMenu(sub_menu_function);
	glutAddMenuEntry("Front Point", 8);
	glutAddMenuEntry("Front Line", 9);
	glutAddMenuEntry("Fill (default)", 10);

	submenu = glutCreateMenu(sub_menu_function);
	glutAddMenuEntry("Point", 1);
	glutAddMenuEntry("Line", 2);
	glutAddMenuEntry("Line Strip", 3);
	glutAddMenuEntry("Line Loop", 4);
	glutAddMenuEntry("Triangle", 5);
	glutAddMenuEntry("Triangle Strip", 6);
	glutAddMenuEntry("Triangle Fan", 7);
	glutAddMenuEntry("Polygon Mode", polygonMode);

	mainmenu = glutCreateMenu(main_menu_function);
	glutAddMenuEntry("Quit", 999);
	glutAddMenuEntry("Clear", 0);
	glutAddSubMenu("Draw Primitives", submenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	/* Implement: Register Callback functions */
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processMouse);

	// enter GLUT event processing cycle
	glutMainLoop();
}
