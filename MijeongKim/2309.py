'''
2309 일곱 난쟁이
Bronze 1
풀이 시간: 15분
'''
def find_fake(dwarf, sub):  # 가짜 두 난쟁이의 좌표를 구하는 함수
    for i in range(9):
        for j in range(i + 1, 9):
            if dwarf[i] + dwarf[j] == sub: return [i, j]

dwarfs = sorted(int(input()) for i in range(9))  # 9명의 키를 입력받아 오름차순 정렬
sub = sum(dwarfs) - 100  # 가짜 두 난쟁이의 키 합을 구함
real_dwarfs = [dwarfs[i] for i in range(9) if i not in find_fake(dwarfs, sub)]  # 가짜 두 난쟁이가 아닌 키들만 필터링

for i in real_dwarfs: print(i)
