#include <iostream>

using namespace std;

int main(){
    
    int E, S, M;
    cin >> E >> S >> M;
    
    // 문제에서 구하고자 하는 연도
    int result = 1;
    
    while(1){  
        // 최종 결과에서 E,S,M을 뺀 나머지가 E,S,M의 최댓값으로 나누어 떨어져야함
        if((result-E)%15 == 0 && (result-S)%28 == 0 && (result-M)%19 == 0){
            break;
        } else {
            result++;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}