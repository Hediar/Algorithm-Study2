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
			//arr[i]�� 1���� j���� ���� arr�� ������ ū�� Ȯ��
			if (arr[i] > arr[j]) {
				//ū ��쿡�� dp[j]�� 1�� �����ְ� dp[i]�� ũ�⸦ ���Ͽ� ����
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	sort(dp, dp + n + 1);

	cout << dp[n];

	return 0;
}