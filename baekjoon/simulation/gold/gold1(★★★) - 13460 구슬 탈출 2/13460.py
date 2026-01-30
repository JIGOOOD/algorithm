from collections import deque

n, m = list(map(int, input().split()))
board = []
for i in range(n):
    board.append(list(input()))
    for j in range(m):
        if board[i][j] == 'R':
            rx, ry = i, j
        elif board[i][j] == 'B':
            bx, by = i, j

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

def bfs(rx, ry, bx, by):
    q = deque() # 갈 수 있는 곳들
    q.append((rx, ry, bx, by))
    vis = [] # 이미 방문한 곳들
    vis.append((rx, ry, bx, by))
    cnt = 0
    while q:
        for _ in range(len(q)): # cnt 증가하는 단위
            rx, ry, bx, by = q.popleft()
            if cnt > 10:
                print(-1)
                return
            if board[rx][ry] == 'O':
                print(cnt)
                return
            for dir in range(4):
                # 빨간 구슬 옮김
                nrx, nry = rx, ry
                while True:
                    nrx += dx[dir]
                    nry += dy[dir] 
                    if board[nrx][nry] == '#':
                        nrx -= dx[dir]
                        nry -= dy[dir]
                        break
                    if board[nrx][nry] == 'O':   
                        break
                nbx, nby = bx, by
                while True:
                    nbx += dx[dir]
                    nby += dy[dir]
                    if board[nbx][nby] == '#':
                        nbx -= dx[dir]
                        nby -= dy[dir]
                        break
                    if board[nbx][nby] == 'O':
                        break
                if board[nbx][nby] == 'O':
                    continue
                if nrx == nbx and nry == nby:
                    if abs(nrx - rx) + abs(nry - ry) > abs(nbx - bx) + abs(nby - by): # 더 많이 이동한 구슬이 더 늦게 이동한 구슬이므로 늦게 이동한 구슬 한칸 뒤로 이동
                        nrx -= dx[dir]
                        nry -= dy[dir]
                    else:
                        nbx -= dx[dir]
                        nby -= dy[dir]
                if (nrx, nry, nbx, nby) not in vis: # 방문해본적이 없는 위치라면 새로 큐에 추가 후 방문 처리
                    q.append((nrx, nry, nbx, nby))
                    vis.append((nrx, nry, nbx, nby))
        cnt += 1
    print(-1)
bfs(rx, ry, bx, by)