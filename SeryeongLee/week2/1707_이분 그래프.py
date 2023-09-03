# https://deeply-silence-9a4.notion.site/f13939158c2d4bc88e1ad572b6a83327?pvs=4
import sys 
from collections import deque
input = sys.stdin.readline

K = int(input())

def bfs(start, group):
    queue = deque([start])
    visited[start] = group
    while queue:
        x = queue.popleft()

        for i in graph[x]: # 해당 정점에서 갈 수 있는 하위 정점들 돌기
            if not visited[i]: # 방문 하지 않은 곳 추가
                queue.append(i)
                visited[i] = -1 * visited[x] # 상위 정점과 다른 그룹
            elif visited[i] == visited[x]: # 방문함 & 같은 그룹일때
                return False
    return True

for _ in range(K):
    v, e = map(int, input().split()) # 정점, 간선 
    graph = [[] for i in range(v+1)]
    visited = [False] * (v + 1)

    # e개줄 만큼 간선의 정보
    for _ in range(e):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    for i in range(1, v+1):
        if not visited[i]: # 방문한 곳이 아니라면 bfs
            result = bfs(i,1)
            if not result:
                break
    print('YES' if result else 'NO')
