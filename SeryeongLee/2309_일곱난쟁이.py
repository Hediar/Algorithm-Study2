# https://deeply-silence-9a4.notion.site/1c5ad7a8cbba4e8d83df3fdf839334c1?pvs=4
import sys 
input = sys.stdin.readline

arr = []
for i in range(9):
    arr.append(int(input()))
arr.sort()
# 모두 더한다음, 2명을 뺐을 때 그 합이 100이라면 해당 2명을 제외하고 출력한다.
num_sum = sum(arr)


for i in range(len(arr)):
    for j in range(i+1, len(arr)):
        if num_sum - arr[i] - arr[j] == 100:
            for k in range(len(arr)):
                if k == i or k == j:
                    pass
                else:
                    print(arr[k])
            break