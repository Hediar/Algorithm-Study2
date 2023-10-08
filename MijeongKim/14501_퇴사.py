n = int(input())
schedule = [list(map(int, input().split())) for _ in range(n)]
dp = [0] * (n + 1)

for i in range(n - 1, -1, -1):
    t, p = schedule[i]
    next_day = t + i
    if next_day <= n: dp[i] = max(p + dp[next_day], dp[i + 1])
    else: dp[i] = dp[i + 1]
print(dp[0])
