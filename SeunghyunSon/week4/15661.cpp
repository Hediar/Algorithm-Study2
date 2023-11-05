#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int map[21][21];
int n;
int ans = 987654321;

// 능력치 표 채우기(Sij)
void init(){
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
}

int main(void){
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    init();
    
    for(int i=0; i<n-1; i++){
        vector<int> combinate;
        
        for(int j=0; j<i; j++){ //스타트 팀 (1)
            combinate.push_back(1);
        }
        
        for(int j=0; j<n-i; j++){ //링크 팀 (0)
            combinate.push_back(0);
        }
        
        sort(combinate.begin(),combinate.end());
        
        do {
            int start = 0;
            int link = 0;
            
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i != j){
                        //스타트 팀의 능력치 
                        if(combinate[i] == 1 && combinate[j] == 1){
                            start += map[i][j];
                        }
                        
                        //링크 팀의 능력치 
                        else if(combinate[i] == 0 && combinate[j] == 0){
                            link += map[i][j];
                        }
                    }
                }
            }
            
            //두 팀의 차이의 최소 값 업데이트
            if(abs(start-link) < ans){
                ans = abs(start-link);
            }
            
        } while(next_permutation(combinate.begin(),combinate.end()));
        
    }
    
    cout << ans << endl;
    
    return 0;
}