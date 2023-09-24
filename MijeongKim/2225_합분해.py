divider = 1000000000
n, k = map(int, input().split())

if n == 1: print(k)
elif k == 1: print(1)
else:
    dp = [[0 for i in range(k + 1)] for i in range(n + 1)]

    # 초기값 지정(k = 1이면 n에 상관 없이 답은 1)
    for i in range(1, n + 1): dp[i][1] = 1
    # 초기값 지정(n = 1이면 k에 상관 없이 답은 k)
    for i in range(1, k + 1): dp[1][i] = i

    # dp[n][k] = dp[n-1][k] + dp[n][k-1]
    for i in range(2, n + 1):
        for j in range(2, k + 1):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

    print(dp[n][k] % divider)
