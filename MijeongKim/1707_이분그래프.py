'''
1707 이분 그래프
Gold 4
풀이 시간: 1시간 이상
'''
from sys import setrecursionlimit, stdin
setrecursionlimit(10 ** 6)
input = stdin.readline

def dfs(i):
    # 인접 노드 탐색
    for v in graph[i]:
        if visited[v] == 0:
            visited[v] = 2 if visited[i] == 1 else 1  # 현재 노드와 다른 그룹으로 설정 
            if not dfs(v): return False
        elif visited[v] == visited[i]: return False  # 방문한 노드가 현재 노드의 그룹과 같으면 이분 그래프가 아님
    return True

k = int(input())
for _ in range(k):
    v, e = map(int, input().split())
    graph = [[] for _ in range(v)]
    visited = [0] * v  # 0: 방문 X, 1: 그룹 1, 2: 그룹 2
    
    for _ in range(e):
        a, b = map(int, input().split())
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)

    for i in range(v):
        if visited[i] == 0:
            visited[i] = 1
            result = dfs(i)  # 1번 노드부터 차례대로 탐색
            if not result: break
    print("YES" if result else "NO")
