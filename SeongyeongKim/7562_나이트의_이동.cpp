#include <iostream>
#include <queue>
using namespace std;

//dx, dy�� ����Ʈ�� ������ �� �ִ� ������� �����ؼ� ���ϴ� �ִ� ��� ����
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool visited[300][300];
int minDis[300][300]; //�湮 Ƚ�� ���

int n;
int sx, sy, fx, fy;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (x == fx && y == fy) {
			cout << minDis[x][y] << '\n';
			break;
		}


		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//������ �ƴϰų� �湮������ pass
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (visited[nx][ny])
				continue;
			//���� ĭ�� �湮 Ƚ���� 1�� ����
			minDis[nx][ny] = minDis[x][y] + 1;
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	
	while (t--) {
		cin >> n;
		cin >> sx >> sy >> fx >> fy;

		//�ʱ�ȭ
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				minDis[i][j] = 0;
				visited[i][j] = false;
			}
		}

		//Ž�� ����
		bfs();
	}

	return 0;
}