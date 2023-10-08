#include <iostream>

using namespace std;

int arr[301][301] = { 0, };

int n, m, r;

void rotate(){
    
    int y1 = 0;
    int x1 = 0;
    
    int y2 = n-1;
    int x2 = 0;
    
    int y3 = n-1;
    int x3 = m-1;
    
    int y4 = 0;
    int x4 = m-1;
    
    while((y1 < y2) && (x1 < x4)){
        
        int move = r % ((y2-y1)*2 + (x4-x1)*2);
        
        while(move--){
            
            int tmp = arr[y1][x1];

            for(int j=x1; j<x4; j++){
                arr[y1][j] = arr[y1][j+1];
            }
            
            for(int i=y4; i<y3; i++){
                arr[i][x4] = arr[i+1][x4];
            }
            
            for(int j=x3; j>x2; j--){
                arr[y3][j] = arr[y3][j-1];
            }
            
            for(int i=y2; i>y1; i--){
                arr[i][x2] = arr[i-1][x2];
            }
            
            arr[y1+1][x1] = tmp;
        }
        
        y1 += 1;
        x1 += 1;
        
        y2 -= 1;
        x2 += 1;
        
        y3 -= 1;
        x3 -= 1;
        
        y4 += 1;
        x4 -= 1;
    }
    
}

int main(void){
    
    cin >> n >> m >> r;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    rotate();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
