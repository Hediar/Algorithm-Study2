# https://deeply-silence-9a4.notion.site/51fa784100d547acb33b5c8503977c93?pvs=4
import sys 
input = sys.stdin.readline

n, m, r = map(int, input().split())
data = [list(map(int,input().split())) for _ in range(n)]

for _ in range(r): # 회전 수 만큼 수행
    for i in range(min(n,m) // 2):
        x, y = i, i # 시작 index
        temp = data[x][y] 

        for j in range(i + 1, n - i): # 좌
            x = j 
            prev = data[x][y]
            data[x][y] = temp
            temp = prev
        
        for j in range(i + 1, m - i): # 하
            y = j
            prev = data[x][y]
            data[x][y] = temp
            temp = prev
        
        for j in range(i + 1, n - i): # 우
            x = n - j -1 
            prev = data[x][y]
            data[x][y] = temp
            temp = prev
        
        for j in range(i + 1, m - i): # 상 
            y = m - j - 1
            prev = data[x][y]
            data[x][y] = temp
            temp = prev

for i in range(n):
    for j in range(m):
        print(data[i][j], end=' ')
    print()