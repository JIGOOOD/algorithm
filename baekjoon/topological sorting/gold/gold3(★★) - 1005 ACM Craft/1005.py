from collections import deque
import sys
input = sys.stdin.readline

t = int(input())
while t:
    n, k = list(map(int, input().split()))
    time = [0] + list(map(int, input().split()))
    adj = [[] for _ in range(n+1)]
    deg = [0] * (n+1)
    for _ in range(k):
        x, y = list(map(int, input().split()))
        adj[x].append(y)
        deg[y] += 1
    w = int(input())

    dp = time[:] # 각 건물 완성까지 걸리는 최소 시간
    q = deque()
    
    for i in range(1, n+1):
        if deg[i] == 0:
            q.append(i)

    while q:
        cur = q.popleft()
        for nxt in adj[cur]:
            dp[nxt] = max(dp[nxt], dp[cur] + time[nxt])
            deg[nxt] -= 1
            if deg[nxt] == 0:
                q.append(nxt)

    print(dp[w])
    t -= 1