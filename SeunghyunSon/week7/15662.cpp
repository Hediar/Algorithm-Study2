#include <iostream>
#include <cstring>
 
using namespace std;
 
int d[1001][8]; // 톱니바퀴 정보 저장
int chk[1001]; // 회전 정보 저장
 
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 톱니바퀴 개수 입력
    int t;
    cin >> t;
 
    // 톱니바퀴 정보 입력
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> d[i][j];
        }
    }
 
    // 회전 횟수 입력
    int k;
    cin >> k;
 
    for (int i = 0; i < k; i++) {
        // 회전 정보 초기화
        memset(chk, 0, sizeof(chk));
        
        int x, y;
        cin >> x >> y;
        
        chk[x] = y;
        
        // 왼쪽으로 확인
        for (int j = x; j < t; j++) {
            if (d[j][2] != d[j+1][6]) {
                chk[j+1] = -chk[j];
            }
            else break;
        }
        
        // 오른쪽으로 확인
        for (int j = x; j > 1; j--) {
            if (d[j][6] != d[j-1][2]) {
                chk[j-1] = -chk[j];
            }
            else break;
        }
        
        // 회전
        for (int j = 1; j <= t; j++) {
            if (chk[j] == 0){
                continue;
            }
            else if (chk[j] == 1) {
                int tmp = d[j][7];
                for (int k = 7; k > 0; k--) {
                    d[j][k] = d[j][k-1];
                }
                d[j][0] = tmp;
            }
            else if (chk[j] == -1) {
                int tmp = d[j][0];
                for (int k = 0; k < 7; k++) {
                    d[j][k] = d[j][k+1];
                }
                d[j][7] = tmp;
            }
        }
    }
    
    int ans = 0;
    
    // 12시 방향이 1인지 체크
    for (int i = 1; i <= t; i++) {
        if (d[i][0] == 1){
            ans += 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
