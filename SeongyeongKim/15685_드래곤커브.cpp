#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int map[100][100]; //�巡�� Ŀ�� ���
int n;
int x, y, d, g;
int cnt = 0;
int dx[4] = { 1, 0,-1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<int> dir;

void makeDragonCurve() {
	//���Ϳ� ũ�⸸ŭ �������� ���븦 ����
	int size = dir.size();
	for (int i = size - 1; i >= 0; i--) {
		int temp = (dir[i] + 1) % 4;
		x += dx[temp];
		y += dy[temp];
		map[x][y] = 1;
		//���� ���� �巡�� Ŀ�긦 �׸��� ���� ���� ���� ����
		dir.push_back(temp);
	}
}

void countSquare() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			//4���� �������� �巡�� Ŀ���̸� cnt++
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

		//������ �巡�� Ŀ�� �߰�
		map[x][y] = 1;

		//0���� �巡�� Ŀ�� �߰�
		x += dx[d];
		y += dy[d];
		map[x][y] = 1;
		dir.push_back(d);

		//���밡 ���� ������ �巡�� Ŀ�� �߰�
		while (g--) {
			makeDragonCurve();
		}
	}

	countSquare();
	cout << cnt;

	return 0;
}