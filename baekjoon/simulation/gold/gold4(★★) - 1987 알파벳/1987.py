import sys
input = sys.stdin.readline

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

r, c = map(int, input().split())
board = [[ord(ch) - 65 for ch in input().strip()] for _ in range(r)]

seen = set()
q = set()
start_bit = 1 << board[0][0]
q.add((0, 0, start_bit))

mx = 1

while q:
    x, y, visited = q.pop()

    if (x, y, visited) in seen:
        continue
    seen.add((x, y, visited))

    mx = max(mx, bin(visited).count('1'))
    if mx == 26:
        break

    for i in range(4):
        nx, ny = x + dr[i], y + dc[i]
        if 0 <= nx < r and 0 <= ny < c:
            bit = 1 << board[nx][ny]
            if not visited & bit: # bit 미방문
                q.add((nx, ny, visited | bit))

print(mx)
