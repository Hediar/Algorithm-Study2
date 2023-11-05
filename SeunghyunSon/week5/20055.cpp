#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N, K;
int result = 0;

deque<pair<int, int>> conveyor;

int main(void) {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    
    for (int i=0; i<2*N; i++) {
        int d;
        cin >> d;
        
        // 각각 로봇의 내구성과 로봇의 존재 여부
        conveyor.push_back({d, 0});
    }

    while(K>0){
        
        result++;

        // 1. 벨트 이동
        // 컨베이어 벨트의 마지막 원소를 앞으로 이동
        conveyor.push_front(conveyor.back());
        conveyor.pop_back();

        // 2. 로봇 이동
        // 로봇은 빈 공간에만 이동이 가능하며, 내구성이 1 이상인 경우에만 이동할 수 있음
        // 로봇은 오른쪽 방향(+1)으로 이동
        for (int i=N-2; i>=0; i--) {
            if (conveyor[i].second == 1 && conveyor[i+1].second == 0 && conveyor[i+1].first > 0) {
                
                // 로봇 이동
                conveyor[i].second = 0;
                conveyor[i+1].second = 1;
                
                // 내구성 감소
                if (--conveyor[i+1].first == 0) {
                    K--;
                }
            }
        }

        // 3. 로봇 올리기
        if (conveyor[0].first > 0 && conveyor[0].second == 0) {
            
            // 컨베이어 벨트의 첫 번째 칸에 로봇을 올림
            conveyor[0].second = 1;
            
            // 내구성이 1 이상인 경우에만 올릴 수 있음
            if (--conveyor[0].first == 0) {
                K--;
            }
        }
    }

    cout << result << '\n';

    return 0;
}