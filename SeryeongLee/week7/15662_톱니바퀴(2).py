# https://deeply-silence-9a4.notion.site/a8365037a23a469ca010b6a5c840f796?pvs=4
from collections import deque

import sys
input = sys.stdin.readline
T = int(input()) # 톱니바퀴 개수 
gears = [0] + [deque(map(int, input().strip())) for _ in range(T)]
K = int(input()) # 회전 횟수
turn = [list(map(int, input().split())) for _ in range(K)] # 회전 방법 -> 회전하는 바퀴의 번호, 정수의 방향 

def solution(T, gears, K, turn):
    for t, direction in turn:
        turnElement = []
        # t 기준 오른쪽
        for i in range(t+1, T+1):
            if gears[i][6] != gears[i-1][2]:
                turnElement.append(i)
            else:
                break
        for i in range(t-1, 0, -1):
            if gears[i][2] != gears[i+1][6]:
                turnElement.append(i)
            else:
                break
        # t 기어 회전
        gears[t].rotate(direction)
        # t 기어와 맞닿은 극이 다른 기어 회전
        for element in turnElement:
            gears[element].rotate(-direction if (element - t)%2 else direction)
    return sum([gears[i][0] for i in range(1, T+1)])
        

# 맞닿은 극 확인 -> 12시 0, 3시 2, 8시 6

result = solution(T, gears, K, turn)
print(result)
