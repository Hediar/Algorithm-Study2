# https://deeply-silence-9a4.notion.site/4bab430e04834874b2a51268f01d773d?pvs=4
import sys 
input = sys.stdin.readline

N = int(input())
dp = [[0]*10 for _ in range(N+1)]

for i in range(1, 10):
    dp[1][i] = 1

for i in range(2, N+1):
    for j in range(10):
        # 0 일때
        if j == 0:
            dp[i][j] = dp[i-1][1]

        # 9 일때
        elif j == 9:
            dp[i][j] = dp[i-1][8]

        # 1 ~ 8 일때
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
print(sum(dp[N]) % 1000000000)