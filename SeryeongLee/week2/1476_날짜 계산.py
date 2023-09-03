# https://deeply-silence-9a4.notion.site/7159f1f4917a402bb2a01f53c31a6057?pvs=4

import sys 
input = sys.stdin.readline

e,s,m = map(int,input().split())
year = 1

while True:
    if ((year-e) % 15 == 0) and ((year-s) % 28 == 0) and ((year-m) % 19 == 0):
        break 
    year += 1

print(year)