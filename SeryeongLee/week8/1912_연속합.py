# https://deeply-silence-9a4.notion.site/36accb255cc54fe0bed9f876fc58e3c1?pvs=4
import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
dp = [0] * n
dp[0] = arr[0]

for i in range(1, n):
    dp[i] = max(arr[i], dp[i-1] + arr[i])
print(max(dp))