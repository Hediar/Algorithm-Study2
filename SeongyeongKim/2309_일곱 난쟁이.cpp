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

	//9���� ���տ��� 100�� �� target
	//�θ��� ������ �� ���� target�� ��ġ�ϸ� �� ���� �����̰� �ƴ�
	int target = sum - 100;

	int notMem1, notMem2;

	//�ΰ��� for���� ����Ͽ� ������ ����
	//�̶�, �θ��� ���� target�� ��ġ�ϸ� ������ �ƴϰ� for�� Ż��
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if ((num[i] + num[j]) == target) {
				notMem1 = i;
				notMem2 = j;
				break;
			}
		}
	}

	vector<int> v; //��¥ �����̵�
	for (int i = 0; i < 9; i++) {
		if ((i == notMem1) || (i == notMem2))
			continue;
		v.push_back(num[i]);
	}

	sort(v.begin(), v.end());

	for (auto i : v) cout << i << '\n';
}