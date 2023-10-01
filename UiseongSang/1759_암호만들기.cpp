#include <bits/stdc++.h>
using namespace std;
int L,C;
vector<char> v;
vector<char> res;

bool check() {
    int num_cnt = 0;
    for(int i = 0; i < L; i++) {
        if( res[i] == 'a' || 
            res[i] == 'e' || 
            res[i] == 'i' || 
            res[i] == 'o' || 
            res[i] == 'u') num_cnt++;
    }
    if(num_cnt >= 1 && L-num_cnt >= 2) return true;
    else return false;
}

void dfs(int d) {
    
    if(res.size() == L) {
        if(check()) {
            for(auto it : res) cout << it;
            cout << "\n";
        }
        return;
    }
    for(int i = d; i < C; i++) {
        res.push_back(v[i]);
        dfs(i+1);
        res.pop_back();
    }
}

int main() {
    cin >> L >> C;
    for(int i = 0; i < C; i++) {
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    dfs(0);
    return 0;
}