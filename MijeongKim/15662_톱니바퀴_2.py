from collections import deque

def rotate_wheel(idx, d):
    global cur_right, cur_left, wheels
    origin_d = d  # 초기 방향 저장

    # 현재 톱니바퀴 기준으로 좌측 톱니바퀴 확인
    for i in range(idx - 1, -1, -1):
        if wheels[i][right] != cur_left:  # 극이 다르면 반대 방향으로 회전
            cur_left = wheels[i][left]
            d *= -1
            wheels[i].rotate(d)
        else: break

    d = origin_d
    
    # 현재 톱니바퀴 기준으로 우측 톱니바퀴 확인
    for i in range(idx + 1, t):
        if cur_right != wheels[i][left]:
            cur_right = wheels[i][right]
            d *= -1
            wheels[i].rotate(d)
        else: break

left, right = 6, 2  # left: 3시 방향, right: 9시 방향
t = int(input())
wheels = [deque(input()) for i in range(t)]  # n: 0, s: 1
k = int(input())

for _ in range(k):
    num, d = map(int, input().split())  # num: 톱니바퀴 번호, d: 방향
    idx = num - 1  # 인덱스로 사용하기 위해 1을 뺌
    
    cur_left, cur_right = wheels[idx][left], wheels[idx][right]
    wheels[idx].rotate(d)  # 1: 시계방향, -1: 반시계방향
    rotate_wheel(idx, d)

print(sum(1 for w in wheels if w[0] == '1'))