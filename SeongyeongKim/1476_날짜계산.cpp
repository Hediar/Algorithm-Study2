#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long int e, s, m; //1 ¡Â E ¡Â 15, 1 ¡Â S ¡Â 28, 1 ¡Â M ¡Â 19
	cin >> e >> s >> m;

	long long int year = 1;
	while (true) {
		if ((year - e) % 15 == 0 && (year - s) % 28 == 0 && (year - m) % 19 == 0)
			break;
		year++;
	}
	
	cout << year;

	return 0;
}