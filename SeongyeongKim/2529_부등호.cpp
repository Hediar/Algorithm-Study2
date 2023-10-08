#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
char inputInequal[10]; //�Է� �޴� �ε�ȣ
bool visited[10] = { false, }; //��Ʈ��ŷ ������ �ʿ��� �湮 ����
string str = "";
string minStr = "99999999999";
string maxStr = "-1";

void backTracking(int pre, int level) {
	//level�� n+1�� ������ �ּ�, �ִ� ���ڿ� �Ǵ�
	if (level == n + 1) {
		minStr = min(minStr, str);
		maxStr = max(maxStr, str);
		return;
	}

	if (inputInequal[level - 1] == '>') {
		//�ε�ȣ�� >�϶��� pre���� ���� ���� Ž��
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
		//�ε�ȣ�� >�϶��� pre���� ū ���� 9���� Ž��
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

	//minStr�� maxStr�� �� �� �ִ� ��� ���� �Ǵ�
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