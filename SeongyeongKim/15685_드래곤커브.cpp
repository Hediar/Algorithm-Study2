#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int map[100][100]; //드래곤 커브 기록
int n;
int x, y, d, g;
int cnt = 0;
int dx[4] = { 1, 0,-1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<int> dir;

void makeDragonCurve() {
	//벡터에 크기만큼 역순으로 세대를 생성
	int size = dir.size();
	for (int i = size - 1; i >= 0; i--) {
		int temp = (dir[i] + 1) % 4;
		x += dx[temp];
		y += dy[temp];
		map[x][y] = 1;
		//다음 세대 드래곤 커브를 그리기 위해 방향 정보 저장
		dir.push_back(temp);
	}
}

void countSquare() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			//4개의 꼭짓점이 드래곤 커브이면 cnt++
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
				cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		dir.clear();
		cin >> x >> y >> d >> g;

		//시작점 드래곤 커브 추가
		map[x][y] = 1;

		//0세대 드래곤 커브 추가
		x += dx[d];
		y += dy[d];
		map[x][y] = 1;
		dir.push_back(d);

		//세대가 끝날 때까지 드래곤 커브 추가
		while (g--) {
			makeDragonCurve();
		}
	}

	countSquare();
	cout << cnt;

	return 0;
}