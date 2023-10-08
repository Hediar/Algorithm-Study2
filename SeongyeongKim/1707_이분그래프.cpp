#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

vector<int> vertex[20001];
int color[20001];
int v, e;

void dfs(int k, int col) {
	color[k] = col;

	//Ž���ϴ� ��� k�� ����Ǿ� �ִ� ��� Ȯ��
	for (int i = 0; i < vertex[k].size(); i++) {
		int next = vertex[k][i];

		//Ȯ���� next ����� ���� ������ dfs ����
		//3���� col�� ���� ������ 
		//k�� ���� 1�̸� next�� 2�̰�, k�� ���� 2�̸� next�� 1�̾�� �ϱ� ����
		if(color[next] == 0)
			dfs(next, 3 - col);
	}
}


bool isBi() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < vertex[i].size(); j++) {
			int next = vertex[i][j];
			//���� ����� ��尡 ���� ���̸� �̺� �׷����� �ƴ�
			if (color[i] == color[next]) return false;
		}
	}
	
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		memset(color, 0, sizeof(color));
		for (int i = 0; i < 20001; i++) vertex[i].clear();

		cin >> v >> e;

		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;

			vertex[a].push_back(b);
			vertex[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) {
			//Ž���ϴ� ����� ������ ���� ��Ȳ�̸� 
			//dfs�� ���� i���� ����� ������ �� ����
			if (color[i] == 0) dfs(i, 1);
		}

		if (isBi()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}