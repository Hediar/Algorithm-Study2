# https://deeply-silence-9a4.notion.site/81e353a993164d1287853ca41cd8a12d?pvs=4

import sys 
input = sys.stdin.readline
T = []
P = []
N = int(input())

for i in range(N):
    arr = list(map(int, input().split()))
    T.append(arr[0])
    P.append(arr[1])
ans = 0

def solution(day, sum):
    global ans
    if day == N: # 현재 날짜 
        ans = max(ans, sum) # 저장된 ans와 
        return
    if day > N: # N날을 넘으면 벗어나기 
        return
    solution(day + T[day], sum + P[day]) # 현재작업 기준으로 현재날짜+ T[day] 현재이익+ P[day]
    solution(day + 1, sum) # 현재 작업을 건너뛰고 다음날짜 + 현재 총 이익 
    
solution(0,0) # 초기 시작
print(ans)