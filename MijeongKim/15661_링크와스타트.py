'''
2309 일곱 난쟁이
Bronze 1
풀이 시간: 15분
'''
#### , 29
from sys import stdin
input = stdin.readline

def get_diff():  # 링크와 스타트팀 능력치 차이를 구함
    start_score = link_score = 0
    for i in range(n):
        for j in range(n):
            if visited[i] and visited[j]: start_score += ability_map[i][j]  # i, j의 visited가 모두 True이면 스타트팀
            if not visited[i] and not visited[j]: link_score += ability_map[i][j]  # i, j의 visited가 모두 False이면 링크팀
    return abs(start_score - link_score)

def back_tracking(idx, size):  # idx = 현재 인덱스, size = 스타트팀의 사람 수
    global ans
    if 1 <= size <= (n // 2):  # 스타트팀 팀의 최대 인원수가 1 이상 n // 2 이하면 유효한 팀 배정
        ans = min(ans, get_diff())  # 최소 차이값 갱신

    for i in range(idx, n):
        visited[i] = True  # 스타트팀에 i + 1번째 사람을 넣음
        back_tracking(i + 1, size + 1)
        visited[i] = False  # 다시 초기화

n = int(input())
ability_map = [list(map(int, input().split())) for _ in range(n)]
ans = 99999999
visited = [False] * n  # 스타트팀 여부

back_tracking(0, 0)
print(ans)
