def solution(board, skill):
    answer = 0
    n = len(board)
    m = len(board[0])
    
    diff = [[0] * (m+1) for _ in range(n+1)]
    
    for t, r1, c1, r2, c2, d in skill:
        if t == 1: # 공격
            diff[r1][c1] -= d
            diff[r1][c2+1] += d
            diff[r2+1][c1] += d
            diff[r2+1][c2+1] -= d
        else: # 힐
            diff[r1][c1] += d
            diff[r1][c2+1] -= d
            diff[r2+1][c1] -= d
            diff[r2+1][c2+1] += d
    
    # 가로 누적합
    for i in range(n):
        for j in range(1, m):
            diff[i][j] += diff[i][j-1]
    
    # 세로 누적합
    for j in range(m):
        for i in range(1, n):
            diff[i][j] += diff[i-1][j]
    
    for i in range(n):
        for j in range(m):
            if board[i][j] + diff[i][j] > 0: answer += 1
    
    return answer