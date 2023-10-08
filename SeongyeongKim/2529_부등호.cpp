#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
char inputInequal[10]; //입력 받는 부등호
bool visited[10] = { false, }; //백트래킹 구현에 필요한 방문 여부
string str = "";
string minStr = "99999999999";
string maxStr = "-1";

void backTracking(int pre, int level) {
	//level이 n+1과 같으면 최소, 최대 문자열 판단
	if (level == n + 1) {
		minStr = min(minStr, str);
		maxStr = max(maxStr, str);
		return;
	}

	if (inputInequal[level - 1] == '>') {
		//부등호가 >일때는 pre보다 작은 값을 탐색
		for (int i = 0; i < pre; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				str += (char)(i + '0');
				backTracking(i, level + 1);
				visited[i] = false;
				str.erase(level, 1);
			}
		}
	}

	if (inputInequal[level - 1] == '<') {
		//부등호가 >일때는 pre보다 큰 값을 9까지 탐색
		for (int i = pre + 1; i <= 9; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				str += (char)(i + '0');
				backTracking(i, level + 1);
				visited[i] = false;
				str.erase(level, 1);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inputInequal[i];
	}

	//minStr과 maxStr에 들어갈 수 있는 모든 수를 판단
	for (int i = 0; i <= 9; i++) {
		visited[i] = true;
		str += (char)(i + '0');
		backTracking(i, 1);
		visited[i] = false;
		str.erase(0, 1);
	}

	cout << maxStr << '\n' << minStr;

	return 0;
}