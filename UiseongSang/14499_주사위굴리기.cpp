#include <iostream>
using namespace std;

int N, M, X, Y, K;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int board[20][20];
int dice[6] = {0};

void move_dice(int dir) {
    int ndice[6] = {0};
    switch (dir) {
        case 0: // 동쪽
            ndice[0] = dice[3];
            ndice[1] = dice[1];
            ndice[2] = dice[0];
            ndice[3] = dice[5];
            ndice[4] = dice[4];
            ndice[5] = dice[2];
            break;
        case 1: // 서쪽
            ndice[0] = dice[2];
            ndice[1] = dice[1];
            ndice[2] = dice[5];
            ndice[3] = dice[0];
            ndice[4] = dice[4];
            ndice[5] = dice[3];
            break;
        case 2: // 북쪽
            ndice[0] = dice[4];
            ndice[1] = dice[0];
            ndice[2] = dice[2];
            ndice[3] = dice[3];
            ndice[4] = dice[5];
            ndice[5] = dice[1];
            break;
        case 3: // 남쪽
            ndice[0] = dice[1];
            ndice[1] = dice[5];
            ndice[2] = dice[2];
            ndice[3] = dice[3];
            ndice[4] = dice[0];
            ndice[5] = dice[4];
            break;
        default:
            break;
    }

    for (int i = 0; i < 6; i++) {
        dice[i] = ndice[i];
    }
}

int main() {
    cin >> N >> M >> X >> Y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int dir;
    for (int i = 0; i < K; i++) {
        cin >> dir;
        --dir;
        int ny = Y + dy[dir];
        int nx = X + dx[dir];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue; // 범위 체크

        Y = ny;
        X = nx;
        
        move_dice(dir);

        cout << dice[0] << "\n"; // 주사위의 윗 면 출력

        if (board[ny][nx] == 0) {
            board[ny][nx] = dice[5];
        } else {
            dice[5] = board[ny][nx];
            board[ny][nx] = 0;
        }
    }
    return 0;
}
