def solution(N, number):
    dp = [set() for _ in range(9)] # dp[i] = N을 i번 이용해서 만들 수 있는 모든 수의 집합
    
    for i in range(1, 9):
        dp[i].add(int(str(N)*i))
        for j in range(1, i):
            for f in dp[j]:
                for s in dp[i-j]:
                    dp[i].add(f + s)
                    dp[i].add(f - s)
                    dp[i].add(f * s)
                    if s != 0: dp[i].add(f // s)
        if number in dp[i]:
            return i
    return -1