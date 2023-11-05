#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// R 연산 함수
void R(vector<vector<int>>& board) {
    
    int mx = 0;//가장 긴 리스트의 길이

    for (int i = 0; i < board.size(); i++) {
        vector<int> row = board[i];
        vector<pair<int, int>> elements;//(원소, 갯수)를 담을 그래프

        for (int j = 0; j < row.size(); j++) {
            if (row[j] == 0){
                continue;
            }
            
            int cnt = count(row.begin(), row.end(), row[j]);
            elements.push_back({row[j], cnt});
        }

        sort(elements.begin(), elements.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        // 크기가 100을 넘어서는 안 됨
        if (elements.size() > 50) elements.resize(50);

        vector<int> new_row;
        for (pair<int, int> elem : elements) {
            new_row.push_back(elem.first);
            new_row.push_back(elem.second);
        }

        mx = max(mx, (int)new_row.size());
        board[i] = new_row;
    }

    // 가장 긴 리스트에 맞춰 0 추가
    for (int i = 0; i < board.size(); i++) {
        while (board[i].size() < mx) {
            board[i].push_back(0);
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int r, c, k;
    cin >> r >> c >> k;
    r -= 1;
    c -= 1;

    vector<vector<int>> board(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }

    int time = 0;

    if (r < board.size() && c < board[0].size()) {
        if (board[r][c] == k) {
            cout << time << endl;
            return 0;
        }
    }

    while (true) {
        if (board.size() >= board[0].size()) {//행의 개수 >= 열의 개수 (R 연산)
            R(board);
        } else {//행의 개수 < 열의 개수 (C 연산)

            vector<vector<int>> transposed;
            transposed.resize(board[0].size(), vector<int>(board.size()));

            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    transposed[j][i] = board[i][j];
                }
            }

            R(transposed);
            board.resize(transposed[0].size(), vector<int>(transposed.size()));

            for (int i = 0; i < transposed.size(); i++) {
                for (int j = 0; j < transposed[0].size(); j++) {
                    board[j][i] = transposed[i][j];
                }
            }
        }

        time++;

        if (time > 100) {
            cout << -1 << endl;
            return 0;
        }

        if (r < board.size() && c < board[0].size()) {
            if (board[r][c] == k) {
                cout << time << endl;
                return 0;
            }
        }
    }

    return 0;
}
