# https://deeply-silence-9a4.notion.site/14890-4f3af03c1e414662ab74e394e66c1878?pvs=4
import sys
input = sys.stdin.readline

n, l = map(int, input().split()) # 그래프의 크기를 결정하는 n, 경사로의 길이 l
graph = [list(map(int, input().split())) for _ in range(n)]
ans = 0

def check_line(line):# 라인 확인 
    for i in range(1, n): # 한 줄 내에 있는 라인 check
        if abs(line[i] - line[i-1]) > 1: # 높이차가 1보다 크면 false
            return False
        if line[i] < line[i-1]: # 현재칸이 이전 칸보다 작아지는 경우 ex) 2 -> 1
            for j in range(l): # 경사로의 길이만큼 반복
                if i + j >= n or line[i] != line[i + j] or slope[i + j]: # 그래프를 벗어나는 경우, 현재의 높이와 다른경우, 이미 경사로가 있는 경우
                    return False
                if line[i] == line[i + j]: # 현재 위치와 경사로의 높이가 같은지 확인 
                    slope[i + j] = True
        elif line[i] > line[i - 1]:
            for j in range(l):
                if i - j - 1 < 0 or line[i - 1] != line[i - j - 1] or slope[i - j - 1]:
                    return False
                if line[i - 1] == line[i - j - 1]: # 이전 위치와 경사로의 길이 
                    slope[i - j - 1] = True
    return True # 모든 조건을 통과할 경우 


for i in range(n):
    slope = [False] * n # 경로 설치 여부 초기화 
    if check_line([graph[i][j] for j in range(n)]): # 경사로 설치 가능할 경우 + 1
        ans += 1

for j in range(n):
    slope = [False] * n # 경로 설치 여부 초기화 
    if check_line([graph[i][j] for i in range(n)]): # 경사로 설치 가능할 경우 + 1
        ans += 1

print(ans)