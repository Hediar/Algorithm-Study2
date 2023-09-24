# https://deeply-silence-9a4.notion.site/f0d7304cc4774181ace73a6c488bd34c?pvs=4
import sys 
input = sys.stdin.readline

n = int(input())
signs = list(input().split())
visited = [0] * 10
result = []

def check(a, b, sign):
    if sign == '<':
        if a > b:
            return False
    elif sign == '>':
        if a < b:
            return False
    return True

def dfs(cnt, num):
    if cnt == n + 1: # 모든 숫자를 사용 완료
        result.append(num)
        return
    
    for i in range(10):
        if visited[i]: continue # 이미 사용한 숫자 

        if cnt == 0 or check(num[cnt-1], str(i), signs[cnt-1]): # 첫번째 숫자일때(그냥 선택가능) or 부등호 조건 만족할때
            visited[i] = 1 # 현재 선택된 숫자가 사용되지 않도록 방지 
            dfs(cnt+1, num+str(i)) # 현재까지 생성한 문자열 num에 추가해서 다음거 호출 
            visited[i] = 0 # 다음 반복에서 사용할 수 있게 

dfs(0, '')
result.sort()
print(result[-1])
print(result[0])