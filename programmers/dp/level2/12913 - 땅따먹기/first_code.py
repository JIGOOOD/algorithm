def solution(land):
    n = len(land)
    dp = [[0] * 4 for _ in range(n)]
    dp[0] = land[0][:]
    
    for i in range(1, n):
        for j in range(4):
            for k in range(4):
                if j == k: continue
                dp[i][k] = max(dp[i][k], dp[i-1][j] + land[i][k])

    return max(dp[n-1])