#include <bits/stdc++.h>
using namespace std;
int N,L,R,sum,cnt;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

vector<vector<int>> country;
int vis[54][54];
vector<pair<int,int>> v;

void dfs(int y, int x) {
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= N || vis[ny][nx]) continue;
        
        if(abs(country[ny][nx] - country[y][x]) >= L && abs(country[ny][nx] - country[y][x]) <= R) {
            vis[ny][nx] = 1;
            v.push_back({ny,nx});
            sum += country[ny][nx];
            dfs(ny,nx);
        }
    }
}

int main() {
    cin >> N >> L >> R;
    country.resize(N, vector<int>(N, false));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> country[i][j];
        }
    }
    
    while(true) {
        bool flag = 0;
        fill(&vis[0][0], &vis[0][0] + 54 * 54, 0);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!vis[i][j]) {
                    v.clear();
                    v.push_back({i,j});
                    vis[i][j] = 1;
                    sum = country[i][j];
                    dfs(i,j);
                    if(v.size() == 1) continue;
                    for(pair<int,int> tmp : v) {
                        country[tmp.first][tmp.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if(!flag) {
            break;
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}