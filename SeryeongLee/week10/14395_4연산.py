# https://deeply-silence-9a4.notion.site/bd4fbb6f00d54cbea423a3006259eb0b?pvs=4
from collections import deque
import sys
input = sys.stdin.readline

s, t = map(int, input().split())
q = deque()
visited = set()

if s == t:
    print(0)

elif t == 1:
    print('/')

else:
    q.append([s,''])
    # 시작하는 수와 연산을 안 한 상태를 q에 넣어주고 시작수를 방문처리 
    visited.add(s)
    while q:
        x, y = q.popleft()
        if x == t:
            print(y)
            break
        # 꺼냈을 때 원하는 값이면 출력
        else:
            if x ** 2 <= 10**9 and x**2 not in visited:
                visited.add(x**2)
                q.append([x**2, y+'*'])
            if x * 2 <= 10**9 and x*2 not in visited:
                visited.add(x*2)
                q.append([x*2, y+'+'])
            if x / x not in visited:
                visited.add(1)
                q.append([1, y+'/'])
        # 10 ** 9 이하의 수중에 연산이 가능한지
    else:
        print(-1)
        # 바꿀 수 없는 경우 