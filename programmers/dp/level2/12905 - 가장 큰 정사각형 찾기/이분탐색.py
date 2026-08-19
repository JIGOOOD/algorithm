def solution(board):
    n = len(board)
    m = len(board[0])

    # 누적합
    P = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(n):
        for j in range(m):
            P[i+1][j+1] = P[i][j+1] + P[i+1][j] - P[i][j] + board[i][j]

    # 변 길이 l짜리 정사각형이 존재하는가?
    def ok(l):
        tar = l * l
        for i in range(n - l + 1):
            for j in range(m - l + 1):
                if P[i+l][j+l] - P[i+l][j] - P[i][j+l] + P[i][j] == tar:
                    return True
        return False

    # 이분탐색
    st, en, ans = 1, min(n, m), 0
    while st <= en:
        mid = (st + en) // 2
        if ok(mid):
            ans = mid
            st = mid + 1
        else:
            en = mid - 1

    return ans * ans
