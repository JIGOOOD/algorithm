n = int(input())
w = [0] + list(map(int, input().split()))

inf = 1000000002

a = inf # dp[i-2] 기저 = dp[0]
b = 0 # dp[i-1] 기저 = dp[1]

for i in range(2, n+1):
    a, b = b, min(b + abs(w[i]-w[i-1]), a + abs(w[i]-w[i-2]))

print(b)