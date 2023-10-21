#include <bits/stdc++.h>
using namespace std;
#define MAX 100004
int n;

int main() {
    int dp[MAX];

    cin >> n;
    
    for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

    cout << dp[n];
    return 0;
}
