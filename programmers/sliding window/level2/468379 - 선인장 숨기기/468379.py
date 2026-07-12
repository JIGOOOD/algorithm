from collections import deque

def solution(m, n, h, w, drops):
    # board 초기화
    board = [[500005] * n for _ in range(m)]
    order = 1
    for r, c in drops:
        board[r][c] = order
        order += 1
        
    # 가로 슬라이딩 윈도우 O(m*n)
    # H[i][j] = 행 i에서 열 j부터 시작하는 가로 w칸 중 최소값
    H = [[0] * (n-w+1) for _ in range(m)] # n-w+1개만 계산하면 됨
    for i in range(m):
        dq = deque()
        for j in range(n):
            # 큰 값 제거
            while dq and board[i][dq[-1]] >= board[i][j]:
                dq.pop()
            # 현재 값 추가
            dq.append(j)
            # 범위 밖 제거
            if dq[0] <= j-w:
                dq.popleft()
            # 윈도우에 들면 갱신
            if j >= w-1:
                H[i][j-w+1] = board[i][dq[0]]
    
    # 세로 슬라이딩 윈도우
    # 가로로 이미 압축됐으니, h에서 세로만 압축하면 됨
    answer = [0, 0]
    mx = 0
    for j in range(n-w+1):
        dq = deque()
        for i in range(m):
            while dq and H[dq[-1]][j] >= H[i][j]:
                dq.pop()
            dq.append(i)
            if dq[0] <= i-h:
                dq.popleft()
            if i >= h-1:
                st = i-h+1 # 창의 시작 행
                v = H[dq[0]][j]
                # 더 늦게 젖으면 갱신, 동점이면 행↑ → 열↑ 우선
                if v > mx or (v == mx and (st < answer[0] or (st == answer[0] and j < answer[1]))):
                    mx = v
                    answer = [st, j]
                
    return answer