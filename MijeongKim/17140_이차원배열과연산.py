def operation(A, size):
    for idx, row in enumerate(A):
        counts = []
        for n in set(row): # 행의 중복 제거
            if n == 0: continue # 0 제외한 숫자 카운팅
            counts.append((n, row.count(n)))
                
        counts = sorted(counts, key = lambda x: (x[1], x[0])) # 등장 횟수, 숫자 순서로 정렬
        counts_size = min(50, len(counts))
        size = max(size, counts_size * 2) # 행의 길이를 최대로 바꿔줌
        
        # A의 idx행 재구성
        A[idx] = []
        for i in range(counts_size):
            A[idx].extend(counts[i])
    
    # 최대 길이만큼 0 채우기
    for idx, row in enumerate(A):
        zero_size = size - len(row)
        A[idx].extend([0] * zero_size)
    
    return A, size

r, c, k = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(3)]
r_size = c_size = 3

for time in range(101):
    if r <= r_size and c <= c_size and A[r - 1][c - 1] == k:
        print(time)
        break
    if r_size >= c_size: # R 연산(행 기준)
        A, c_size = operation(A, c_size)
    else: # C 연산(열 기준)
        A, r_size = operation(list(zip(*A)), r_size)
        A = list(zip(*A)) # 전치 후 다시 원상복구
else: print(-1)  # 100초 이상
