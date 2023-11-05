#include <iostream>
#include <queue>

using namespace std;

int N;
const int MAX = 201;
int path[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;
int dy[] = {-1, 1, -2, 2, -1, 1};
int dx[] = {-2, -2, 0, 0, 2, 2};

void BFS(int y, int x) {
    path[y][x] = 0;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny > N || nx > N){
                continue;
            }
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                path[ny][nx] = path[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> N;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    BFS(b, a);

    if (path[d][c] == 0){
        cout << -1 << endl;
    }
    else{
        cout << path[d][c] << endl;
    }

    return 0;
}
