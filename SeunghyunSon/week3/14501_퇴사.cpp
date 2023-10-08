#include <iostream>
#include <algorithm>

using namespace std;

int dp[16] = { 0, };
int cost[16] = { 0, };
int day[16] = { 0, };

void solution(int n) {
	for (int i = n; i > 0; i--) {
		if (i + day[i] > n + 1){
			dp[i] = dp[i + 1];
		} else {
		    // 마지막 상담 종료 날짜가 퇴사 날짜를 넘어가는 것을 방지하기 위해
		    // dp[i+day[i]]와 비교해야 함
			dp[i] = max(dp[i + 1], cost[i] + dp[i + day[i]]);
		}
	}
}

int main(void) {
    
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> day[i] >> cost[i];
	}

	solution(n);

	cout << dp[1] << '\n';
	
	return 0;
}