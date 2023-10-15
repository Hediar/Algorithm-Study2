#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> arr;
    vector<int> dp;

    cin >> n;
    arr.resize(n);
    dp.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ret = arr[0];
    dp[0] = arr[0];

    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ret = max(dp[i], ret);
    }

    cout << ret << endl;

    return 0;
}
