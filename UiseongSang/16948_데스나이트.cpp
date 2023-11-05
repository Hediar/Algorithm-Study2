#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-2, -2, 0, 0, 2, 2};
const int dx[] = {-1, 1, -2, 2, -1, 1};
int n, r1, c1, r2, c2;
int dist[201][201];  // (r, c)까지의 최단 이동 횟수를 저장

void bfs() {
    queue<pair<int, int>> q;
    q.push({r1, c1});
    dist[r1][c1] = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == r2 && x == c2) {
            cout << dist[y][x];
            return;
        }

        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if( ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (dist[ny][nx] == -1) {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    cout << -1;
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    memset(dist, -1, sizeof(dist));
    
    if (r1 == r2 && c1 == c2) {
        cout << 0;
    } else {
        bfs();
    }

    return 0;
}
