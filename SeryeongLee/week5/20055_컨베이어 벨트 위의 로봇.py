# https://deeply-silence-9a4.notion.site/76755aead81742d69458a9da3b80b90b?pvs=4
import sys
input = sys.stdin.readline
from collections import deque

n, k = map(int,input().split())
belt = deque(list(map(int, input().split()))) # 내구도
robot = deque([0] * n)
result = 0

while 1:
    belt.rotate(1)
    robot.rotate(1)
    robot[-1] = 0 # 로봇이 내려가는 부분
    if sum(robot): # 로봇이 존재하는지 확인
        for i in range(n-2, -1, -1): # 로봇이 내려가는 부분인 n-1이 아닌 n-2 ~ 0번째 index까지 확인
            if robot[i] == 1 and robot[i+1] == 0 and belt[i+1] >= 1: # 로봇이 있음 & 다음칸에 로봇이 없음 & 다음칸의 벨트의 내구도가 1이상
                robot[i+1] = 1 # 이동
                robot[i] = 0 # 기존에 있던자리 0 으로 처리
                belt[i+1] -= 1 # 벨트의 내구도 감소 
        robot[-1] = 0 # 로봇이 벨트의 마지막 칸으로 이동했을 경우, 위로 올림 
    if robot[0] == 0 and belt[0] >= 1: # 가장 왼쪽에 로봇이 없음 & 내구도는 남아있음
        robot[0] = 1 # 로봇 올리기 
        belt[0] -= 1 # 내구도 감소 
    result += 1
    if belt.count(0)>= k:
        break
print(result)