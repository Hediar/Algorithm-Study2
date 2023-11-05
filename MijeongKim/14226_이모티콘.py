from collections import deque

s = int(input())
queue = deque([[1, 0, 0]])
visited = dict()

while queue:
    n, time, clipboard = queue.popleft()
    if s == n:
        print(time)
        break
    
    if visited.get((n, clipboard)): continue
    visited[(n, clipboard)] = True
    
    if n > 0:
        queue.append([n, time + 1, n]) # 복사
        queue.append([n - 1, time + 1, clipboard]) # 빼기
    if clipboard > 0: queue.append([n + clipboard, time + 1, clipboard]) # 붙여넣기
