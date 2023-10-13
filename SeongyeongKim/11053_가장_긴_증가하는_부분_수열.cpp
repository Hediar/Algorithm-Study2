#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		dp[i] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			//arr[i]가 1부터 j까지 수열 arr의 값보다 큰지 확인
			if (arr[i] > arr[j]) {
				//큰 경우에는 dp[j]에 1을 더해주고 dp[i]와 크기를 비교하여 갱신
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	sort(dp, dp + n + 1);

	cout << dp[n];

	return 0;
}