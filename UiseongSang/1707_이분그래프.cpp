#include <bits/stdc++.h>
#define RED  1
#define BLUE 2
using namespace std;
int k,V,E,a,b;
vector<int> adj[20004];
int visited[20004];

void dfs(int start) {
    if (!visited[start]) {
        visited[start] = RED;
    }
    int _size = adj[start].size();
    for (int i = 0; i < _size; i++) {
        int next = adj[start][i];
        if (!visited[next]) {
            if (visited[start] == RED) {
                visited[next] = BLUE;
            }
            else if (visited[start] == BLUE) {
                visited[next] = RED;
            }
            dfs(next);
        }
    }
}

bool isAnswer() {
    for (int i = 1; i <= V; i++) {
        int _size = adj[i].size();
        for (int j = 0; j < _size; j++) {
            int next = adj[i][j];
            if (visited[i] == visited[next]) {
                return 0;
            }
        }
    }
    return 1;
}

void solve() {
    for(int i = 1; i <= V; i++) {
        if(!visited[i]) {
            dfs(i);
        } 
    }

    if (isAnswer()) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }

    // 초기화
    for (int i = 0; i <= V; i++) {
        adj[i].clear();
    }
    memset(visited, false, sizeof(visited));
}

int main() {
    cin >> k;

    for(int i = 0; i < k; i++) {
        cin >> V >> E;
        for(int j = 0; j < E; j++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        solve();
    }
    return 0;
}
