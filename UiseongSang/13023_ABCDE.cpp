#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> vec(2001);
vector<bool> vis(2001);
bool ans = false;

void dfs(int node, int cur) {
    if (node == 4) {
        ans = true;
        return;
    }
    vis[cur] = true;
    for(int i = 0; i < vec[cur].size(); i++){
        int next = vec[cur][i];
        if(vis[next]) continue;
        dfs(node+1, next);
    }
    vis[cur] = false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        vis[i] = 1;
        dfs(0,i);
        if(ans) break;
    }
    cout << ans;
       
    return 0;
}
