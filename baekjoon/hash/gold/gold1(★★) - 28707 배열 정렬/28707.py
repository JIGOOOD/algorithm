import heapq
import sys
input = sys.stdin.readline

def main():
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    score = [[0]*n for _ in range(n)]

    for _ in range(m):
        l, r, c = list(map(int, input().split()))
        # 같은 l, r에 대해 다른 c 들어올 수 있으므로 최솟값 선택
        if score[l-1][r-1] == 0:
            score[l-1][r-1] = c
        else:
            score[l-1][r-1] = min(score[l-1][r-1], c)

    # 가장 최소 비용을 구해야 하니, deque말고 min_heap 사용
    heap = []
    heapq.heappush(heap, (0, tuple(a)))
    s = set()

    while heap:
        total, cur = heapq.heappop(heap)
        if cur in s: continue
        s.add(cur) # 최소힙 보장해야 하므로 pop할 때 방문 처리
        cur2 = list(cur)[:]
        if cur2 == sorted(cur2):
            print(total)
            return
        for i in range(n):
            for j in range(n):
                cur2 = list(cur)[:]
                if score[i][j] == 0: continue
                tmp = cur2[i]
                cur2[i] = cur2[j]
                cur2[j] = tmp
                if tuple(cur2) in s: continue
                heapq.heappush(heap,(total+score[i][j], tuple(cur2)))
                
    print(-1)
if __name__ == '__main__':
    main()
