def solution(board):
    n = len(board)
    m = len(board[0])

    # dp[i][j] = (i, j)를 오른쪽 아래 꼭짓점으로 하는 정사각형의 최대 변 길이
    dp = [[0] * m for _ in range(n)]
    answer = 0

    for i in range(n):
        for j in range(m):

            # 이 칸이 0이면 정사각형을 만들 수 없다
            if board[i][j] == 0:
                dp[i][j] = 0

            # 맨 윗줄이나 맨 왼쪽줄이면 위/왼쪽 이웃이 없으니 최대 1
            elif i == 0 or j == 0:
                dp[i][j] = 1

            # 나머지는 위, 왼쪽, 대각선 중 가장 작은 값 + 1
            else:
                up = dp[i - 1][j]
                left = dp[i][j - 1]
                diag = dp[i - 1][j - 1]
                dp[i][j] = min(up, left, diag) + 1

            # 가장 큰 변 길이를 계속 갱신
            if dp[i][j] > answer:
                answer = dp[i][j]

    return answer * answer