#include <iostream>
#include <stdio.h>
using namespace std;

int _map[300][300];

int n, m, r;

void rotation() {
	int tmp[300][300];
	for (int rot = 0; rot < min(n, m) / 2; rot++) {
		int x1 = rot, y1 = rot, x2 = n - 1 - rot, y2 = m - 1 - rot;
		//аб
		for (int i = y2 - 1; i >= y1; i--) tmp[x1][i] = _map[x1][i + 1];
		//го
		for (int i = x1 + 1; i <= x2; i++) tmp[i][y1] = _map[i - 1][y1];
		//©Л
		for (int i = y1 + 1; i <= y2; i++) tmp[x2][i] = _map[x2][i - 1];
		//╩С
		for (int i = x2 - 1; i >= x1; i--) tmp[i][y2] = _map[i + 1][y2];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			_map[i][j] = tmp[i][j];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
		}
	}

	while (r--) rotation();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << _map[i][j] << ' ';
		cout << '\n';
	}


	return 0;
}