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

	//탐색하는 노드 k와 연결되어 있는 노드 확인
	for (int i = 0; i < vertex[k].size(); i++) {
		int next = vertex[k][i];

		//확인할 next 노드의 색이 없으면 dfs 진행
		//3에서 col을 빼는 이유는 
		//k의 색이 1이면 next는 2이고, k의 색이 2이면 next는 1이어야 하기 때문
		if(color[next] == 0)
			dfs(next, 3 - col);
	}
}


bool isBi() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < vertex[i].size(); j++) {
			int next = vertex[i][j];
			//서로 연결된 노드가 같은 색이면 이분 그래프가 아님
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
			//탐색하는 노드의 색깔이 없는 상황이면 
			//dfs를 통해 i노드와 연결된 노드들의 색 지정
			if (color[i] == 0) dfs(i, 1);
		}

		if (isBi()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}