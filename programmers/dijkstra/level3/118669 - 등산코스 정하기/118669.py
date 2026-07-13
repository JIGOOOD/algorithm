from heapq import heappush, heappop

def solution(n, paths, gates, summits):
    top = 0
    mn = 2000000000002
    inf = 2000000000002
    
    # 노드 초기화
    adj = [[] * (n+1) for _ in range(n+1)]
    for a, b, c in paths:
        adj[a].append((c, b))
        adj[b].append((c, a))
    
    
    inten = [inf] * (n+1) # 이게 큰 값 구해야 함
    pq = []
    for g in gates:
        inten[g] = 0
        heappush(pq, (0, g))
    
    # 탐색 시간 복잡도를 O(1)로 만들기 위함
    gates_set = set(gates)
    summits_set = set(summits)
    
    while pq:
        cw, cur = heappop(pq)
        if inten[cur] != cw: continue
        if cur in summits_set: continue # 봉우리 한번만 거치도록
        
        for nw, nxt in adj[cur]:
            if nxt in gates_set: continue # 출발지 거치지 않도록
            if inten[nxt] > max(nw, cw):
                inten[nxt] = max(nw, cw)
                heappush(pq, (inten[nxt], nxt))
    for s in summits:
        if inten[s] < mn or (inten[s] == mn and s < top):
            mn = inten[s]
            top = s
    return [top, mn]