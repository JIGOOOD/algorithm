n = int(input())
w = [0] + list(map(int, input().split()))

dp = [0] * (n+1)

for i in range(2, n+1):
    if i == 2: dp[i] = abs(w[i]-w[i-1])
    else: dp[i] = min(dp[i-1] + abs(w[i]-w[i-1]), dp[i-2] + abs(w[i]-w[i-2]))

print(dp[n])