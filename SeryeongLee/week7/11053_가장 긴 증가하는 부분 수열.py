# https://deeply-silence-9a4.notion.site/a5bc9fb72eb249aead16702a45fd1152?pvs=4
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

dp = [1] * N 

for i in range(1, N):
    for j in range(i):
        if A[i] > A [j]:
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))