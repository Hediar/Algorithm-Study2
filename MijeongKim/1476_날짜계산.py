# 1476, 28 - 44
'''
1476 날짜 계산
Silver 5
풀이 시간: 16분
'''
e, s, m = map(int, input().split())
year = 0

while True:
    year += 1
    if (year - e) % 15 == 0 and (year - s) % 28 == 0 and (year - m) % 19 == 0:
        print(year)
        break
