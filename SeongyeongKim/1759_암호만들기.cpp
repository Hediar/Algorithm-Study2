#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;

//v는 입력받은 문자들, now는 현재 탐색하는 문자 인덱스, str은 현재 만들어진 암호 상태, cons와 vow는 자음 모음 개수
void dfs(vector<char> v, int now, string str, int cons, int vow) {
	
	str.push_back(v[now]); 

	//현재 탐색하는 문자가 자음인지 모음인지에 따라 개수 증가
	if (v[now] == 'a' || v[now] == 'e' || v[now] == 'i' || v[now] == 'o' || v[now] == 'u')
		vow++;
	else
		cons++;

	//문자열 개수가 l고 같아지면, 조건에 맞는지 보고 출력하고 
	//dfs 탈출하고, 다음 문자 탐색 진행
	if (str.length() == l) {
		if (vow >= 1 && cons >= 2)
			cout << str << '\n';
		return;
	}
	
	//문자 출력 조건이 오름차순이므로, now보다 큰 값에서 탐색해야 함
	for (int i = now + 1; i < c; i++) {
		dfs(v, i, str, cons, vow);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> l >> c;

	vector<char> str(c);

	char inputChar;
	for (int i = 0; i < c; i++) {
		cin >> str[i];
	}

	sort(str.begin(), str.end());

	for (int i = 0; i <= c - l; i++) {
		dfs(str, i, "", 0, 0);
	}

	//조합으로 모음, 자음 뽑고 정렬해서 출력하면 되지 않을까?



	return 0;
}