# https://deeply-silence-9a4.notion.site/17086-658ab8f0569f42d9a80e306dec539168?pvs=4
import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

d = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (1, -1), (-1, 1), (1, 1)]

q = deque()

def bfs():
    while q:
        x, y = q.popleft()
        for dx, dy in d:
            nx = x + dx
            ny = y + dy

            # 범위 제한
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue

            # 상어가 없는 곳이고 방문하지 않은 곳일 경우
            if not graph[nx][ny]:
                # 거리 정보 업데이트
                graph[nx][ny] = graph[x][y] + 1
                q.append((nx, ny)) # 새 좌표

for i in range(N):
    for j in range(M):
        if graph[i][j]: # 상어 위치일 경우 
            q.append((i, j))

bfs()

print(max(map(max, graph)) - 1)