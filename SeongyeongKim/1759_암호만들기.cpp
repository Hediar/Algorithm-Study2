#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;

//v�� �Է¹��� ���ڵ�, now�� ���� Ž���ϴ� ���� �ε���, str�� ���� ������� ��ȣ ����, cons�� vow�� ���� ���� ����
void dfs(vector<char> v, int now, string str, int cons, int vow) {
	
	str.push_back(v[now]); 

	//���� Ž���ϴ� ���ڰ� �������� ���������� ���� ���� ����
	if (v[now] == 'a' || v[now] == 'e' || v[now] == 'i' || v[now] == 'o' || v[now] == 'u')
		vow++;
	else
		cons++;

	//���ڿ� ������ l�� ��������, ���ǿ� �´��� ���� ����ϰ� 
	//dfs Ż���ϰ�, ���� ���� Ž�� ����
	if (str.length() == l) {
		if (vow >= 1 && cons >= 2)
			cout << str << '\n';
		return;
	}
	
	//���� ��� ������ ���������̹Ƿ�, now���� ū ������ Ž���ؾ� ��
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

	//�������� ����, ���� �̰� �����ؼ� ����ϸ� ���� ������?



	return 0;
}