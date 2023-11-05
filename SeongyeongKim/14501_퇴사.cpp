#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int maxMoney = 0;

vector<int> day;
vector<int> money;

//x�� ���� Ž���Ϸ��� �����̰�, sum�� ���� ���ڱ��� ���� ����
void dfs(int x, int sum) {
	//���� x�� n���� Ŀ���� �ش� dfs ����
	if (x > n) return;

	//maxMoney ����
	maxMoney = max(maxMoney, sum);
	//���� ���� x���� n���� ��������� ����
	for (int i = x; i < n; i++) {
		dfs(day[i] + i, sum + money[i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;

	int d, m;
	for (int i = 0; i < n; i++) {
		cin >> d >> m;
		day.push_back(d);
		money.push_back(m);
	}

	dfs(0, 0);

	cout << maxMoney;

	return 0;
}