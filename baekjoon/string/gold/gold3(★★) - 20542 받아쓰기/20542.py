import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s = input().strip()
t = input().strip()
dp = [[i] + [0]* m for i in range(n+1)]
dp[0] = [ i for i in range(m+1)]

for i in range(n):
    for j in range(m):
        if s[i] == 'i' and t[j] in ['j', 'l'] or s[i] == 'v' and t[j] == 'w' or s[i] == t[j]:
            dp[i+1][j+1] = dp[i][j]
        else:
            dp[i+1][j+1] = min(dp[i][j], dp[i+1][j], dp[i][j+1]) + 1
                

print(dp[n][m])