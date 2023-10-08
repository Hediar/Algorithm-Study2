#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
	
int T, L;

// Knight의 이동 경우의 수를 배열에 저장
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

// 보드
int map[300][300];
// 검사 여부
int check[300][300];
// 방문 여부
int visited[300][300];
// 방문한 좌표를 저장하는 Queue
queue<pair<int, int>> q;

void BFS(int destination_x, int destination_y) {

	while (!q.empty()) {
	    // Queue에서 x좌표와 y좌표를 불러와서 방문 여부를 체크한 후 pop()
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = 1;
		q.pop();
		
		// BFS 탐색 종료 조건
		// 원하는 좌표 값을 pop()한다면 Queue가 비어있다는 의미
		if (x == destination_x && y == destination_y) {
			cout << check[x][y] << '\n';
			return;
		}
        
        // BFS 탐색
		for (int i = 0; i < 8; i++) {
			int temp_x = x + dx[i];
			int temp_y = y + dy[i];
            
            // Knight의 다음 이동 좌표가 보드를 벗어나면 안되고, 이미 방문한 곳을 가서도 안됨
			if (temp_x >= 0 && temp_x < L && temp_y >= 0 && temp_y < L && visited[temp_x][temp_y] == 0) {
				visited[temp_x][temp_y] = 1;
				check[temp_x][temp_y] = check[x][y] + 1; // (이동 횟수 + 1) 연산
				q.push({ temp_x, temp_y }); // Queue에 다음 이동 좌표 저장
			}
		}
	}
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	
	while (T--) {
	    
		cin >> L;
		
		int knight_x, knight_y; // 시작점
		int destination_x, destination_y; // 목표점
		cin >> knight_x >> knight_y;
		cin >> destination_x >> destination_y;

		q.push({ knight_x, knight_y }); // 시작점을 Queue에 저장
		BFS(destination_x, destination_y); // BFS 탐색

		for (int i = 0; i < 300; i++) { // 초기화
			for (int j = 0; j < 300; j++) {
				check[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		
		while (!q.empty()){
			q.pop();
		}
	}
	
	return 0;
}