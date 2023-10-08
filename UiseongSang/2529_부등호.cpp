#include <bits/stdc++.h>
using namespace std;

int k;
char ch[10];
bool vis[10] = {false, };
string minV = "9999999999";
string maxV = "-1";
string s;
void dfs(int prev, int cur);

void solve(int idx, int cur) {
    if(vis[idx] == false) {
        vis[idx] = true;
        s += (char)(idx + '0');
        dfs(idx, cur+1);
        vis[idx] = false;
        s.erase(cur, 1);
    }
}

void dfs(int prev, int cur) {
    if( cur == k + 1) {
        minV = min(minV, s);
        maxV = max(maxV, s);
        return;
    }

    if(ch[cur - 1] == '>') {
        for(int i = 0; i < prev; i++) {
            solve(i,cur);
        }
    } else {
        for(int i = prev + 1; i <= 9; i++) {
            solve(i,cur);
        }
    }
}

int main() {
    cin >> k;

    for(int i = 0; i < k; i++) {
        cin >> ch[i];
    }   

    for(int i = 0; i <= 9; i++) {
        vis[i] = true;
        s += (char)(i + '0');
        dfs(i,1);
        vis[i] = false;
        s.erase(0,1);
    }
    cout << maxV << "\n" << minV;
    return 0;
}