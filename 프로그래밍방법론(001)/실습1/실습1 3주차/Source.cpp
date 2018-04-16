#include <iostream>
#include <GL/glut.h>
#include <math.h>

/* Include ReadFile */

#define PI 3.141592
int num;
float cen_x, cen_y, cen_z, r;	// center position & radius
float cen_r, cen_g, cen_b;		// center color
int menu_number;				// option
char pressed_key;				// keyboard

void init() {
	cen_r = cen_g = cen_b = 1;
	menu_number = 0;
}

void drawPolygon(float center_x, float center_y, float center_z, float radius) {
	/* modify your last week's code */
}

void drawPoint(float center_x, float center_y, float center_z, float radius) {
	/* implement */
}

void drawLine(float center_x, float center_y, float center_z, float radius) {
	/* implement */
}

void processNormalKeys(unsigned char key, int x, int y) {
	printf("You pressed %c at (%d, %d)\n", key, x, y);
	/* implement */
}

void processSpecialKeys(int key, int x, int y) {
	printf("You pressed %c at (%d, %d)\n", key, x, y);
	/* implement */
}

void sub_menu_function(int option) {
	printf("Sub menu %d has been selected\n", option);
	menu_number = option;
	/* implement if you need*/
}

void main_menu_function(int option) {
	printf("Main menu %d has been selected\n", option);
	if (option == 999)
		exit(0);
	else if (option == 0) {
		glClear(GL_COLOR_BUFFER_BIT);
		glutSwapBuffers();
	}
}

void renderScene(void) {
	glClearColor(0, 0, 0, 0);

	glClear(GL_COLOR_BUFFER_BIT);

	if (menu_number == 1)
		drawPoint(cen_x, cen_y, cen_z, r);
	else if (menu_number == 2)
		drawLine(cen_x, cen_y, cen_z, r);
	else if (menu_number == 3)
		drawPolygon(cen_x, cen_y, cen_z, r);

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	std::cout << "How many sides does the polygon have? : ";
	std::cin >> num;

	/* Read FIle */

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Menu selection & Drawing Primitives");

	/* Implement Popup menu */

	/* Implement Callback functions */

	// enter GLUT event processing cycle
	glutMainLoop();
}
