#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int num[9];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> num[i];
		sum += num[i];
	}

	//9명의 총합에서 100을 뺀 target
	//두명을 더했을 때 값이 target과 일치하면 그 둘은 난쟁이가 아님
	int target = sum - 100;

	int notMem1, notMem2;

	//두개의 for문을 사용하여 조합을 구현
	//이때, 두명의 합이 target과 일치하면 난쟁이 아니고 for문 탈출
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if ((num[i] + num[j]) == target) {
				notMem1 = i;
				notMem2 = j;
				break;
			}
		}
	}

	vector<int> v; //진짜 난쟁이들
	for (int i = 0; i < 9; i++) {
		if ((i == notMem1) || (i == notMem2))
			continue;
		v.push_back(num[i]);
	}

	sort(v.begin(), v.end());

	for (auto i : v) cout << i << '\n';
}