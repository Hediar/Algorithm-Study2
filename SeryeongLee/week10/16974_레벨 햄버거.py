#https://deeply-silence-9a4.notion.site/17fe2606b3144a1ab6031cac16b3df23?pvs=4
import sys
input = sys.stdin.readline

N, X = map(int, input().split())

burger = [1] * 51
patty = [1] * 51

for i in range(1, N+1):
    burger[i] = 1 + burger[i-1] + 1 + burger[i-1] + 1 # 버거 레이아웃 개수
    patty[i] = patty[i-1] + 1 + patty[i-1] # 버거 패티 개수 

def eat(n, x):
    if n == 0: # 레이어가 없는 경우
        return x
    if x == 1: # 가장 아래 층의 가운데 패티일 경우
        return 0
    elif x <= 1 + burger[n-1]: # 가운데 패티 아래일 경우
        return eat(n-1, x-1)
    elif x == 1 + burger[n-1] + 1: # 가운데까지 먹을 경우
        return patty[n-1] + 1
    elif x <= burger[n-1] + burger[n-1] + 1 + 1: # n-1 까지 먹을경우
        return patty[n-1] + 1 + eat(n-1, (x-(burger[n-1] + 2)))
    else: # 다 먹을 경우
        return patty[n]
print(eat(N,X))