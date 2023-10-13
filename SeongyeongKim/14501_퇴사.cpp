#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int maxMoney = 0;

vector<int> day;
vector<int> money;

//x는 현재 탐색하려는 일자이고, sum은 현재 일자까지 구한 가격
void dfs(int x, int sum) {
	//일자 x가 n보다 커지면 해당 dfs 종료
	if (x > n) return;

	//maxMoney 갱신
	maxMoney = max(maxMoney, sum);
	//현재 일자 x부터 n까지 재귀적으로 구함
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