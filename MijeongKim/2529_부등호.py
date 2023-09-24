nums = [i for i in range(10)]
k, signs = int(input()), input().split()
used = [False for i in range(10)]
ans = []

def compare(i, j, sign):
    if sign == '<': return i < j
    return i > j

def solve(index, s, used):
    if index == k + 1:
        ans.append(s)
        return
    for i in range(10):
        if used[i]: continue
        if index == 0 or compare(int(s[-1]), i, signs[index - 1]):
            used[i] = True
            solve(index + 1, s + str(i), used)
            used[i] = False

solve(0, '', used)
print(ans[-1])
print(ans[0])
