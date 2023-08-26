'''
16926 배열 돌리기 1
Silver 1
풀이 시간: 42분
'''
def create_result(row):
    size = (n + m - 2 * (row * 2 + 1)) * 2  # 루프의 길이
    turn = r % size  # 회전 수를 루프의 길이만큼 나눈 후 나머지를 구함(연산 횟수 최소화를 위함)
    loop = []  # 루프
    start = end = row  # 순회를 위한 x, y 좌표값 지정(루프의 시작점)
    
    for _ in range(size):  # 루프 좌표 배열을 구함
        loop.append([start, end])
        if start == row and end < m - 1 - row: end += 1
        elif end == m - 1 - row and start < n - 1 - row: start += 1
        elif start == n - 1 - row and end > row: end -= 1
        elif start > row and end == row: start -= 1
    
    for i in range(size):  # 구한 루프 좌표 배열을 순회하면서 result 맵의 값을 지정
        origin_x, origin_y = loop[i]  # 회전 이전의 x, y 좌표
        val_x, val_y = loop[(i + turn) % size]  # 회전 이후의 값을 가리키는 x, y 좌표
        result_maps[origin_x][origin_y] = maps[val_x][val_y]

n, m, r = map(int, input().split())
maps = [list(map(int, input().split())) for _ in range(n)]
result_maps = [[0 for _ in range(m)] for _ in range(n)]
limit = min(n, m) // 2  # 맵에 생길 수 있는 루프 수

for i in range(limit): create_result(i)  # 루프 수만큼 순회하면서 result 맵 생성
for row in result_maps: print(*row)
