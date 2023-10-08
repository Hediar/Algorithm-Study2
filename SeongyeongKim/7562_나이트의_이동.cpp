#include <iostream>
#include <queue>
using namespace std;

//dx, dy를 나이트가 움직일 수 있는 방법으로 설정해서 구하는 최단 경로 문제
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool visited[300][300];
int minDis[300][300]; //방문 횟수 기록

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

			//범위가 아니거나 방문했으면 pass
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (visited[nx][ny])
				continue;
			//이전 칸의 방문 횟수에 1을 더함
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

		//초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				minDis[i][j] = 0;
				visited[i][j] = false;
			}
		}

		//탐색 시작
		bfs();
	}

	return 0;
}