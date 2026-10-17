## **💻 문제 정의**

https://school.programmers.co.kr/learn/courses/30/lessons/214288

### **🗒️ 최종 제출 코드**

처음에는 그리디로 풀었더니 틀렸다. 바로 남는 상담원을 배치해버리면 뒤에 더 길어지는 상담이 있을 때를 잡아낼 수 없다.

```python
from heapq import heappush, heappop

def solution(k, n, reqs):
    answer = 0
    
    pqs = [[] for _ in range(k+1)] # 끝나는 시각, 요청 시각
    l = n-k # 추가 가능한 상담원 수
    
    for req_time, duration, k_type in reqs:
        pq = pqs[k_type]
        if not pq:
            heappush(pq, req_time + duration)
        elif pq[0] <= req_time:
            heappop(pq)
            heappush(pq, req_time + duration)
        else:
            if l:
                l -= 1
                heappush(pq, req_time + duration)
            else:
                heappush(pq, pq[0] + duration)
                answer += pq[0] - req_time
                heappop(pq)
    return answer
```

이후에는 https://school.programmers.co.kr/questions/64130 이 로직을 참고해서 풀었다.

```python
from heapq import heappush, heappop

def solution(k, n, reqs):
    cnt = [1] * (k+1) # 우선 한명씩 배치하고, 감소 효과가 큰 애들한테 배치함
    
    def simulate():
        answer = 0
        pqs = [[] for _ in range(k+1)] # 끝나는 시각, 요청 시각

        for req_time, duration, k_type in reqs:
            pq = pqs[k_type]
            if not pq:
                heappush(pq, req_time + duration)
            elif pq[0] <= req_time:
                heappop(pq)
                heappush(pq, req_time + duration)
            else:
                if len(pq) < cnt[k_type]:
                    heappush(pq, req_time + duration)
                else:
                    heappush(pq, pq[0] + duration)
                    answer += pq[0] - req_time
                    heappop(pq)
        return answer
    
    for _ in range(n-k):
        mx_type = 0 # 효과 큰 애 대기시간 긴 애
        mn_val = 1000000000
        for i in range(1, k+1): # i에게 배치
            cnt[i] += 1
            val = simulate()
            if mn_val > val:
                mn_val = val
                mx_type = i
            cnt[i] -= 1
        cnt[mx_type] += 1
              
    return simulate()
```

---

## **💭 오늘의 회고**

어렵다 흑흑