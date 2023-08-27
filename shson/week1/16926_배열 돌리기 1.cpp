#include <iostream>
#include <algorithm>

using namespace std;

int arr[301][301] = { 0, }; // 입력한 배열
int temp[300][300] = { 0, }; // 회전용 배열

int n, m, r;
    
void rotate(int m, int n, int r){
    
    int c = min(n,m)/2; // min(N, M) mod 2 = 0
        
    for(int inside = 0; inside < c; inside++) {
        
        // inside: 고리의 개수(=rotate()의 실행 횟수)를 세기 위한 변수
        int x = n - (inside+1);
        int y = m - (inside+1);
        
        int startX = inside;
        int startY = inside;
        
        for(int i = 0; i < x - inside; i++){ //왼쪽으로 이동
            temp[startX-1][startY] = arr[startX][startY];
            startX--;
        }
        
        for(int i = 0; i < x - inside; i++){ //오른쪽으로 이동
            temp[startX+1][startY] = arr[startX][startY];
            startX++;
        }
            
        for(int i = 0; i < y - inside; i++){ //아래쪽으로 이동
            temp[startX][startY+1] = arr[startX][startY];
            startY++;
        }
            
        for(int i = 0; i < y - inside; i++){ //위쪽으로 이동
            temp[startX][startY-1] = arr[startX][startY];
            startY--;
        }  
            
    }
    
    // 회전용 배열에 담은 내용을 원래 배열에 저장
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            arr[i][j] = temp[i][j];
        }
    }

}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin>>n>>m>>r;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }
    
    while(r>0) {
        rotate(m, n, r);
                
        r--;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
           cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    return 0;
}