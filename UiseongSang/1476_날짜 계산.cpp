#include <bits/stdc++.h>
using namespace std;
int E,S,M,ret = 1;

int main() {
    cin >> E >> S >> M;

    int i = 0;
    int j = 0;
    int k = 0;

    while(true) {
        i++; j++; k++;

        if(i > 15) i = 1;
        if(j > 28) j = 1;
        if(k > 19) k = 1;

        if(i == E && j == S && k == M) {
            cout << ret;
            break;
        }
        ret++;
    }
    return 0;
}