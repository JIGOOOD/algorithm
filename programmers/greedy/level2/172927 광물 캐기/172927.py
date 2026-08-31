from heapq import heappush, heappop;

def solution(picks, minerals):
    answer = 0
    ml = len(minerals)
    l = min(sum(picks) * 5, ml)
    
    cost = [[1,1,1], [5,1,1], [25,5,1]]
    
    # 1. 광물 리스트 만들기
    pl = []
    for i in range(3):
        while picks[i]:
            pl.append(i)
            picks[i] -= 1        
    
    # 2. 광물 5개 단위로 쪼개기
    q = []
    for i in range(0, l, 5):
        r = min(i+5, ml)
        chunk = minerals[i:r]
        heappush(q, [-chunk.count("diamond"), -chunk.count("iron"), -chunk.count("stone")])
    
    # 3. 곡괭이-광물 매핑하기
    for p in pl:
        if q:
            cur = heappop(q)
            for i in range(3):
                answer += (cost[p][i] * -cur[i])
    
    return answer