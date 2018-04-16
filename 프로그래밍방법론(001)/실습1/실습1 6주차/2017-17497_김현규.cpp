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
	vertex();
	vertex(int x, int y, int z);
	int getX();
	int getY();
	int getZ();
	void setX(int x);
	void setY(int y);
	void setZ(int z);

private:
	float pos[3];
};

class face {
public:
	/* Implement constructor, draw function */
	face();
	face(vertex p1, vertex p2, vertex p3);
	void draw();

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
	for (vector<face>::iterator iter = vFace.begin();
		iter != vFace.end(); iter++)
		(*iter).draw();
}

void obj::ReadFromOBJFile(string filename) {
	vector<vertex> vertices;
	ifstream input(filename);

	char sub;
	while (input >> sub) {
		if (sub == 'v') {
			/* Implement: read vertex data */
			float pt[3];
			input >> pt[0] >> pt[1] >> pt[2];
			vertices.push_back(vertex(pt[0], pt[1], pt[2]));
		}
		else if (sub == 'f') {
			/* Implement: read face data */
			int p_index[3];
			input >> p_index[0] >> p_index[1] >> p_index[2];
			vFace.push_back(face(vertices[p_index[0] - 1],
				vertices[p_index[1] - 1], vertices[p_index[2] - 1]));
		}
	}
}

obj Cube;
float angle = 0;

void idle() {
	/* Implement: Change the rotation angle */
	angle += 0.1;
	glutPostRedisplay();
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
	Cube.ReadFromOBJFile("cube.obj");

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

vertex::vertex() { }

vertex::vertex(int x, int y, int z) {
	pos[0] = x;	pos[1] = y;	pos[2] = z;
}

int vertex::getX() { return pos[0]; }
int vertex::getY() { return pos[1]; }
int vertex::getZ() { return pos[2]; }
void vertex::setX(int x) { pos[0] = x; }
void vertex::setY(int y) { pos[0] = y; }
void vertex::setZ(int z) { pos[0] = z; }

face::face() { }
face::face(vertex p1, vertex p2, vertex p3) {
	vtx[0] = p1;
	vtx[1] = p2;
	vtx[2] = p3;
}

void face::draw() {
	glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 1);
		glVertex3f(vtx[0].getX(), vtx[0].getY(), vtx[0].getZ());
		glColor3f(1, 1, 0);
		glVertex3f(vtx[1].getX(), vtx[1].getY(), vtx[1].getZ());
		glColor3f(0, 1, 1);
		glVertex3f(vtx[2].getX(), vtx[2].getY(), vtx[2].getZ());
	glEnd();
}