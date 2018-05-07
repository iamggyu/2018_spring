#include<vector>
#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

int dy[4] = { 0,1,-1,0 };
int dx[4] = { 1,0,0,-1 };

void floodfill(vector<vector<int>>& p, vector<vector<int>>& isVisit, int y, int x) {
	p[y][x] = -1;

	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY >= p.size() || nextY < 0 || nextX >= p[0].size() || nextX < 0) continue;
		if (isVisit[nextY][nextX] != 0) continue;
		if (p[nextY][nextX] != 0) continue;
		isVisit[nextY][nextX] = 1;
		floodfill(p, isVisit, nextY, nextX);
	}
}

void expand(vector<vector<int>>& p) {
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

	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < p[i].size(); j++) {
			if (p[i][j] == -1)
				p[i][j] = 0;
			else if (p[i][j] == 0 || p[i][j] == 1)
				p[i][j] = 2;
		}
	}


	return;
}


int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	int h, w;
	input >> h >> w;
	vector<vector<int>> map;
	map.resize(h);
	for (int i = 0; i < h; i++) {
		map[i].resize(w);
		for (int j = 0; j < w; j++) {
			input >> map[i][j];
		}
	}

	expand(map);
	cout << endl << endl;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++)
			output << map[i][j] <<' ';
		output << endl;
	}
	system("pause");
}
