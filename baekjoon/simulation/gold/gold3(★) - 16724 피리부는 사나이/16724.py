n, m = list(map(int, input().split()))

board = list(input() for _ in range(n))
vis = [[0]*m for _ in range(n)]

safe = 0
for i in range(n):
    for j in range(m):
        if vis[i][j] != 0: continue
        s = [(i, j)]
        path = []
        while(s):
            cur = s.pop()
            x = cur[0]
            y = cur[1]
            if(vis[x][y]):
                if vis[x][y] == 1:
                    safe += 1
                break
            vis[x][y] = 1
            path.append((x, y))
            if(board[x][y] == 'D'):
                s.append((x+1, y))
            elif(board[x][y] == 'U'):
                s.append((x-1, y))
            elif(board[x][y] == 'L'):
                s.append((x, y-1))
            else: # board[x][y] == 'R'
                s.append((x, y+1))

        for x0, y0 in path:
            vis[x0][y0] = 2

print(safe)
