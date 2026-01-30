def make(dir, gen):
    res = [dir]
    for _ in range(gen):
        res2 = list(reversed(res)) # 뒤집기
        for i in range(len(res2)):
            res2[i] = (res2[i] + 1) % 4 # 반시계 회전
        res.extend(res2)
    return res

def lay(a, b, res):
    board[b][a] = 1
    dx = [1, 0, -1, 0]
    dy = [0, -1, 0, 1]
    for r in res:
        nx = a + dx[r]
        ny = b + dy[r]
        board[ny][nx] = 1
        a = nx
        b = ny

def cal():
    res = 0
    for i in range(100):
        for j in range(100):
            total = 0
            total += board[i][j] + board[i][j+1] + board[i+1][j] + board[i+1][j+1]
            if total == 4: res += 1
    return res

board = [[0]*101 for _ in range(101)]
n = int(input()) # 드래곤 커브 개수
for _ in range(n):
    x, y, d, g = list(map(int, input().split()))
    res = make(d, g)
    lay(x, y, res)

print(cal())
