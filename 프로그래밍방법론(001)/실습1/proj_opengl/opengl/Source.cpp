#include <vector>
#include "Player.h"
#include "Zombie.h"
#include "Grid.h"
#include "GL/glut.h"
#include "math.h"
#include <time.h>


using namespace std;

Player pl(50, 50, 1, 1, 0);

Zombie z1(10, 10, 1, 0, 0);
Zombie z2(80, 80, 0, 1, 0);
Zombie z3(10, 80, 0, 0, 1);

vector<vector<int>> area; // store territory using Grid
string killscore = pl.getLife();
clock_t st = clock();
clock_t ed;



#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height




void init() {

	area.resize(1000);

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			area[i].push_back(0);
		}
	}
}

void draw_string(void * font, string str, float x, float y) {
	glRasterPos2f(x, y);
	for (int i = 0; i < str.length(); i++)
		glutBitmapCharacter(font, str[i]);
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT: if(pl.getDir() != 1) pl.setDir(0);
		break;
	case GLUT_KEY_RIGHT: if (pl.getDir() != 0) pl.setDir(1);
		break;
	case GLUT_KEY_UP: if (pl.getDir() != 3) pl.setDir(2);
		break;
	case GLUT_KEY_DOWN: if (pl.getDir() != 2) pl.setDir(3);
		break;
	}
}

void idle() {

	ed = clock();
	if (ed - st > 1000 / 30) {
		pl.move(area);
		z1.movekill(area, pl);
		z2.movekill(area, pl);
		z3.movekill(area, pl);

		st = ed;
	}

	killscore = pl.getLife();

	glutPostRedisplay();
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);


	pl.draw();
	z1.draw();
	z2.draw();
	z3.draw();

	glColor3f(0, 1, 1);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, killscore, 50, 95);

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Let's Play the Game");

	init();

	glutDisplayFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(idle);

	glutMainLoop();

}