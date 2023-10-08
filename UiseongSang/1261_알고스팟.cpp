#include <bits/stdc++.h>
using namespace std;
int n,m,a[101][101],vis[101][101][2];;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void bfs() {
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0][0] = 1;
    vis[0][0][1] = 0;

    while(!q.empty()) {
        int y,x;
        tie(y,x) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx >= m || nx < 0) continue;
            
            if(vis[ny][nx][0] == 0) {
                vis[ny][nx][0] = 1;
                vis[ny][nx][1] = vis[y][x][1] + a[ny][nx];
                q.push({ny,nx});
            }
            else { 
                if(vis[ny][nx][1] > (vis[y][x][1] + a[ny][nx])){
                    vis[ny][nx][1] = vis[y][x][1] + a[ny][nx];
                    q.push({ny,nx});
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp;
            scanf("%1d", &tmp);
            a[i][j] = tmp;
        }
    }
    
    bfs();
    cout << vis[n-1][m-1][1];
    
    return 0;
}