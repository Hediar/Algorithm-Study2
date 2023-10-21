#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;


    int dp[100001];

    for (int i = 1; i <= N; i++) {
        dp[i] = i;

        //j*j를 빼는 이유는 제곱수를 찾아서 최소 항의 개수를 구하기 위함
        //ex)
        //dp[11]
        // = dp[11 - 1*1] +1 = dp[10] +1
        // = dp[11 - 2*2] +1 = dp[7] +1
        // = dp[11 - 3*3] +1 = d[2] +1
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[N];

    return 0;
}