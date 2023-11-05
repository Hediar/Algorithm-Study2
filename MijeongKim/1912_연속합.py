def lcs(nums):
    cur = 0
    max_sum = -(10 ** 8)
    for num in nums:
        cur = max(cur + num, num)
        max_sum = max(max_sum, cur)
    return max_sum

n = int(input())
nums = list(map(int, input().split()))
print(lcs(nums))
