#include "Player.h"
#include "GL/glut.h"
#include <stack>
#include <string>


Player::Player(int x, int y, float r, float g, float b) {
	pos = new int[2];
	pos[0] = x;
	pos[1] = y;

	color = new float[3];
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

Player::~Player() {
	delete[] pos;
	delete[] color;
}

void Player::draw(vector<vector<int>>& p) {
	
	glBegin(GL_QUADS);
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < p[i].size(); j++) {
			if (p[i][j] == 0)
				continue;
			if (p[i][j] == 1)
				glColor3f(0.5, 0.5, 0.5);
			if (p[i][j] == 2)
				glColor3f(0.3, 0.5, 0.7);
			glVertex2f(i, j);
			glVertex2f(i + 1, j);
			glVertex2f(i + 1, j + 1);
			glVertex2f(i, j + 1);
		}
	}
	glEnd();


	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_POLYGON);
	glVertex2f(pos[0], pos[1]);
	glVertex2f(pos[0] + 1, pos[1]);
	glVertex2f(pos[0] + 1, pos[1] + 1);
	glVertex2f(pos[0], pos[1] + 1);
	glEnd();
}
void Player::setPos(int x ,int y) {
	pos[0] = x;
	pos[1] = y;
}

void Player::setDir(int d) {
	dir = d;
}
void Player::death(vector<vector<int>>& p) {
	setPos(50, 50);

	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < p[i].size(); j++) {
			if (p[i][j] == 1)
				p[i][j] = 0;
		}
	}

	life--;
}

string Player::getLife() {
	return to_string(life);
}

int Player::getDir() {
	return dir;
}
int Player::getX() {
	return pos[0];
}
int Player::getY() {
	return pos[1];
}
int Player::getIntRatio() {
	return ratio;
}
string Player::getRatio() {
	string str(std::to_string(ratio / 10));
	str.push_back('.');
	str.push_back(ratio % 10 + '0');
	str.push_back('%');
	return str;
}
void Player::setLife(int n) {
	life = n;
}
void Player::trace(vector<vector<int>>& p) {
	
}

void Player::move(vector<vector<int>>& p) {
	int prev = p[pos[0]][pos[1]];
	switch (dir) {
	case 0:
		if (pos[0] > 1) {
			pos[0]--;
			if (p[pos[0]][pos[1]] == 1) {
				death(p);
			}
			if (p[pos[0]][pos[1]] == 0) {
				p[pos[0]][pos[1]] = 1;
			}
			if (prev == 1 && p[pos[0]][pos[1]] == 2) {
				expand(p);
			}
		}
		break;
	case 1:
		if (pos[0] + 1 < 99) {
			pos[0]++;
			if (p[pos[0]][pos[1]] == 1) {
				death(p);
			}
			if (p[pos[0]][pos[1]] == 0) {
				p[pos[0]][pos[1]] = 1;
			}
			if (prev == 1 && p[pos[0]][pos[1]] == 2) {
				expand(p);
			}
		}
		break;
	case 2:
		if (pos[1] + 1 < 99) {
			pos[1]++;
			if (p[pos[0]][pos[1]] == 1) {
				death(p);
			}
			if (p[pos[0]][pos[1]] == 0) {
				p[pos[0]][pos[1]] = 1;
			}
			if (prev == 1 && p[pos[0]][pos[1]] == 2) {
				expand(p);
			}
		}
		break;
	case 3:
		if (pos[1] > 1) {
			pos[1]--;
			if (p[pos[0]][pos[1]] == 1) {
				death(p);
			}
			if (p[pos[0]][pos[1]] == 0) {
				p[pos[0]][pos[1]] = 1;
			}
			if (prev == 1 && p[pos[0]][pos[1]] == 2) {
				expand(p);
			}
		}
		break;
	default:
		pos[0] = pos[0];
		pos[1] = pos[1];
	}
}

void Player::expand(vector<vector<int>>& p) {
	//flood fill
	int init_y = 0, init_x = 0;

	//그 점을 시작으로 flood fill 한다
	//채워지는 점들은 -1로 변경한다.
	vector<vector<int>> isVisit;
	isVisit.resize(p.size());
	for (int i = 0; i < p.size(); i++)
		isVisit[i].resize(p[i].size());

	stack<pair<int, int>> st;
	st.push(pair<int, int>(0, 0));
	while (!st.empty()) {
		int y = st.top().first;
		int x = st.top().second;
		st.pop();
		p[y][x] = -1;

		for (int i = 0; i < 4; i++) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			if (nextY >= p.size() || nextY < 0 || nextX >= p[0].size() || nextX < 0) continue;
			if (isVisit[nextY][nextX] != 0) continue;
			if (p[nextY][nextX] != 0) continue;
			isVisit[nextY][nextX] = 1;
			st.push(make_pair(nextY, nextX));
		}
	}

	int Territory = (p.size()) * (p[0].size()), all = (p.size() - 2) * (p[0].size() - 2);
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < p[i].size(); j++) {
			if (p[i][j] == -1) {
				p[i][j] = 0;
				Territory--;
			}
			else if (p[i][j] == 0 || p[i][j] == 1)
				p[i][j] = 2;
		}
	}
	ratio = Territory * 1000 / all;
	return;
}