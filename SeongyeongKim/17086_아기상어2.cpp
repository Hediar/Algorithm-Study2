#include <bits/stdc++.h>
using namespace std;

int N, M;
int _map[50][50];

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int maxDist = 0;

void bfs(int inputX, int inputY) {
	bool visited[50][50] = { false, };
	queue < pair<int, pair<int, int>>> q;

	q.push({ 0, {inputX, inputY} });
	visited[inputX][inputY] = true;

	while (!q.empty()) {
		int dist = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (_map[x][y]) {
			maxDist = max(dist, maxDist);
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (visited[nx][ny])
				continue;
			q.push({ dist + 1, {nx, ny} });
			visited[nx][ny] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> _map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//상어가 없는 위치이면
			//가장 가까운 상어까지의 거리가 몇인지 확인하고
			//최대라면 갱신하기
			if (_map[i][j]==0)
				bfs(i, j);
		}
	}

	cout << maxDist;

	return 0;
}