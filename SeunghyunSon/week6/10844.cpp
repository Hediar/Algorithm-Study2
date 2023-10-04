#include<iostream>

#define MOD 1000000000

using namespace std;

int n = 0;
int result = 0;
int dp[101][10] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // N: 자리 수
    cin >> n;

    // 한 자리수는 무조건 계단수
    for (int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            // 끝 자리가 0이거나 9인 경우는 한 쪽 방향으로 밖에 진행하지 못함
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1] % MOD;
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1] % MOD;
            }
            // 그 이외의 경우는 왼쪽과 오른쪽 양방향으로 진행할 수 있음
            else{
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    
    // N 자리의 계단수를 모두 더는 반복문
    for (int i = 0; i <= 9; i++) {
        result = (result + dp[n][i]) % MOD;
    }
    
    cout << result << "\n";

    return 0;
}
