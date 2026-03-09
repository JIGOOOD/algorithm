import sys
input = sys.stdin.readline

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

r, c = list(map(int, input().split()))
board = [list(input().strip()) for _ in range(r)]
alph = [0] * 26
alph[ord(board[0][0]) - ord('A')] += 1

mx = 0

def bfs(x, y, l):
    global mx
    mx = max(mx, l)
    for dir in range(4):
        nx = x + dx[dir]
        ny = y + dy[dir]
        if nx < 0 or nx >= r or ny < 0 or ny >= c: continue
        if alph[ord(board[nx][ny]) - ord('A')] >= 1: continue
        alph[ord(board[nx][ny]) - ord('A')] += 1
        bfs(nx, ny, l+1)
        alph[ord(board[nx][ny]) - ord('A')] -= 1

bfs(0, 0, 1)
print(mx)
