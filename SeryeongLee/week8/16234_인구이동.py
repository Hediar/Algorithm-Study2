# https://deeply-silence-9a4.notion.site/e91f5fb9a061441b84133770f5f0a3bd?pvs=4

# L <= 인구 차이 <= R 이면 국경선 오늘 하루 동안 열기
# 열렸으면 인구 이동 시작
# 국경선 열려있고 인접한 칸 -> 연합
# 연합 간의 인구수 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)
import sys
from collections import deque
input = sys.stdin.readline

N, L, R = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(i, j):
    queue = deque()
    union = []
    queue.append((i, j))
    union.append((i, j))

    while queue:
        x, y = queue.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == 0:
                if L <= abs(A[nx][ny] - A[x][y]) <= R:
                    visited[nx][ny] = 1
                    queue.append((nx, ny))
                    union.append((nx, ny))
    return union

result = 0
while True:
    visited = [[0 for _ in range(N)] for _ in range(N)]
    flag = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j] == 0:
                visited[i][j] = 1
                country = bfs(i,j)

                if len(country) > 1:
                    flag = 1
                    people = sum(A[x][y] for x, y in country) // len(country)

                    for x, y in country:
                        A[x][y] = people
    if flag == 0:
        print(result)
        break
    result += 1