#include <vector>
#include "Player.h"
#include "Zombie.h"
#include "Grid.h"
#include "GL/glut.h"
#include "math.h"
#include <time.h>
#include <string>


using namespace std;

Player pl(50, 50, 1, 1, 0);

Zombie z1(10, 10, 1, 0, 0);
Zombie z2(80, 80, 0, 1, 0);
Zombie z3(10, 80, 0, 0, 1);



vector<vector<int>> area; // store territory using Grid
string life = pl.getLife();
string r1 = "You've Killed  ";
string r2 = "  Zombies!!!";
string lose = "You Lose!!!";
clock_t st = clock();
clock_t ed;

int kills = 0;



#define WIDTH 600		// window's width
#define HEIGHT 750		// window's height
#define WIN_RATIO 700	
#define INIT_SIZE 6
#define BOARD_SIZE 100


void init() {

	area.resize(BOARD_SIZE);

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			area[i].push_back(0);
		}
	}

	for (int i = 0; i < INIT_SIZE; i++)
		for (int j = 0; j < INIT_SIZE; j++)
			area[BOARD_SIZE / 2 + i - INIT_SIZE / 2][BOARD_SIZE / 2 + j - INIT_SIZE / 2] = 2;

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
		
		if (pl.getLife() != "0" && pl.getLife() != "-1") {
			z1.setDir(rand() % 4);
			z2.setDir(rand() % 4);
			z3.setDir(rand() % 4);
		}

		pl.move(area);
		z1.movekill(area, pl);
		z2.movekill(area, pl);
		z3.movekill(area, pl);

		kills = 0;
		kills += 1 - z1.getIsAlive();
		kills += 1 - z2.getIsAlive();
		kills += 1 - z3.getIsAlive();

		st = ed;
	}
	life = pl.getLife();

	glutPostRedisplay();
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 125);

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 101);
	glVertex2f(0, 102);
	glVertex2f(100, 102);
	glVertex2f(100, 101);
	glEnd();


	pl.draw(area);
	z1.draw();
	z2.draw();
	z3.draw();

	glColor3f(0, 1, 1);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, r1+std::to_string(kills)+r2, 30, 120);
	if (pl.getLife() == "0") {
		pl.setDir(-1);
		z1.setDir(-1);
		z2.setDir(-1);
		z3.setDir(-1);
		glRasterPos2f(40, 50);
		for (int i = 0; i < lose.length(); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, lose[i]);
	}

	for (int i = 0; i < stoi(life); i++) {
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex2f(1 + 3 * i + 2 * i, 120);
		glVertex2f(1 + 3 * i + 2 * i, 110);
		glVertex2f(1 + 3 * (i + 1) + 2 * i, 110);
		glVertex2f(1 + 3 * (i + 1) + 2 * i, 120);
		glEnd();
	}
	
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, pl.getRatio(), 50, 110);
	if (pl.getIntRatio() > WIN_RATIO) {
		pl.setDir(-1);
		z1.setDir(-1);
		z2.setDir(-1);
		z3.setDir(-1);
		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "WIN!!!!", 40, 50);
		pl.setLife(-1);
	}

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 0);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Let's Play the Game");

	init();

	glutDisplayFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(idle);

	glutMainLoop();

}