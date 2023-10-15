# https://deeply-silence-9a4.notion.site/dfc038d1389f4571b4743a5606ca75d0?pvs=4
from collections import deque
import sys
input = sys.stdin.readline

S = int(input())
queue = deque() # 화면 이모티콘 개수, 클립보드 이모티콘 개수
queue.append((1,0))

visited = dict()
visited[(1, 0)] = 0


while queue:
    screen, clipboard = queue.popleft()
    # 종료 조건
    if screen == S: # 이모티콘 S개를 만들면 종료
        print(visited[(screen, clipboard)]) # 연산횟수 출력
        break
    # 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
    if (screen, screen) not in visited.keys(): # 방문하지 않았을 때
        visited[(screen, screen)] = visited[(screen, clipboard)] + 1
        queue.append((screen, screen))
    # 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
    if (screen + clipboard, clipboard) not in visited.keys():
        visited[(screen + clipboard, clipboard)] = visited[(screen, clipboard)] + 1
        queue.append((screen + clipboard, clipboard))
    # 화면에 있는 이모티콘 중 하나를 삭제한다.
    if (screen -1, clipboard) not in visited.keys():
        visited[(screen - 1, clipboard)] = visited[(screen, clipboard)] + 1
        queue.append((screen - 1, clipboard))
