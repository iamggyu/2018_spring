/* Implement: Include header files */
#include <vector>
#include "GL\glut.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

vector<Shape*> shape;
float speed = 0.01;

void draw_string(void * font, const char * str, float x, float y) {
	glColor3f(1, 1, 1);
	glRasterPos2f(x, y);
	for (int i = 0; i < strlen(str); i++)
		glutBitmapCharacter(font, str[i]);
}

void init() {
	/* Implement: Set each object */
	shape.push_back(new Triangle(0.2));
	shape.push_back(new Square(0.3));
	
	shape[0]->setColor(1, 0, 0);
	shape[0]->setPos(-0.5, -0.5);
	shape[1]->setColor(0, 1, 0);
	shape[1]->setPos(0.5, 0.5);
}

void idle() {
	/* Implement: Move each object */
	for (vector<Shape*>::iterator it = shape.begin(); it != shape.end(); it++) {
		float x = (*it)->getX();
		float y = (*it)->getY();
		if (x == -0.5 && y == -0.5) { x += speed; x = (x > 0.5 ? 0.5 : x); }
		else if (x ==  0.5 && y == -0.5) { y += speed; y = (y > 0.5 ? 0.5 : y); }
		else if (x == -0.5 && y ==  0.5) { y -= speed; y = (y < -0.5 ? -0.5 : y); }
		else if (x ==  0.5 && y ==  0.5) { x -= speed; x = (x < -0.5 ? -0.5 : x); }

		else if (x ==  0.5) { y += speed; y = (y > 0.5 ? 0.5 : y); }
		else if (x == -0.5) { y -= speed; y = (y < -0.5 ? -0.5 : y); }
		else if (y ==  0.5) { x -= speed; x = (x < -0.5 ? -0.5 : x); }
		else if (y == -0.5) { x += speed; x = (x > 0.5 ? 0.5 : x); }
		(*it)->setPos(x, y);
	}
	glutPostRedisplay();
}

void renderScene() {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Implement: Draw each object */
	for (vector<Shape*>::iterator it = shape.begin(); it < shape.end(); it++)
		(*it)->draw();

	/* Implement: Display character*/
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "2017-17497 KIM Hyeongyu", -0.5, 0.9);

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
