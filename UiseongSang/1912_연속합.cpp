#include <bits/stdc++.h>
using namespace std;
int n, ret;

int main() {
    cin >> n;
    vector<int> vec;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    vector<int> dp;
    dp = vec;

    ret = dp[0];
    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i], dp[i-1]+vec[i] );
        ret = max(ret, dp[i]);
    }

    cout << ret;

    return 0;
}
