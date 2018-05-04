#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

int dy[4] = { 0,1,-1,0 };
int dx[4] = { 1,0,0,-1 };

void floodfill(vector<vector<int>>& map, vector<vector<int>>& isVisit, int y, int x) {
	map[y][x] = -1;

	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY >= map.size() || nextY < 0 || nextX >= map[0].size() || nextX < 0) continue;
		if (isVisit[nextY][nextX] != 0) continue;
		if (map[nextY][nextX] != 0) continue;
		isVisit[nextY][nextX] = 1;
		floodfill(map, isVisit, nextY, nextX);
	}
}

//빈땅은 0, 경로는 1, 이미 땅은 2이다.
//지도가 주어졌을 때 땅을 갱신해준다.
void expand(vector<vector<int>>& map) {
	//맵의 경계위에 있는 점에서부터 시작한다.
	int init_y = -1, init_x = -1;

	for (int i = 0; i < map.size(); i++) {
		if (map[i][0] == 0) {
			init_y = i;
			init_x = 0;
			break;
		}
		if (map[i][map[i].size() - 1] == 0) {
			init_y = i;
			init_x = map[i].size() - 1;
			break;
		}
	}
	for (int i = 0; i < map[0].size(); i++) {
		if (map[0][i] == 0) {
			init_y = 0;
			init_x = i;
			break;
		}
		if (map[map.size() - 1][i] == 0) {
			init_y = map.size() - 1;
			init_x = i;
			break;
		}
	}

	//그 점을 시작으로 flood fill 한다
	//채워지는 점들은 -1로 변경한다.
	vector<vector<int>> isVisit;
	isVisit.resize(map.size());
	for (int i = 0; i < map.size(); i++)
		isVisit[i].resize(map[i].size());

	floodfill(map, isVisit, init_y, init_x);

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == -1)
				map[i][j] = 0;
			else if (map[i][j] == 0 || map[i][j] == 1)
				map[i][j] = 2;
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
