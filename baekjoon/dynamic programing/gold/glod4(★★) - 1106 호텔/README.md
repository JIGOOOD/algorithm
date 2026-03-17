https://bio-info.tistory.com/218

### 문제 링크

https://www.acmicpc.net/problem/1106

### 난이도

★★ 아이디어가 잘 안떠오르고, 구현도 그리 쉽진 않음

### 알고리즘 분류

- DP

### 핵심 아이디어

1.  DP 정의: dp[i] = i명의 고객을 모으는 데 필요한 최소 비용

    초기값: dp[0] = 0, 나머지는 매우 큰 값 (INF)

2.  점화식: dp[i] = min(dp[i], dp[i - num_people] + cost)

    의미: i명을 모으기 위해 마지막으로 어떤 도시를 홍보했을 때 최소 비용 갱신

3.  dp 크기를 C+100으로 잡는 이유

    최적 해가 C명보다 약간 더 많은 고객을 모으는 경우가 존재할 수 있음

    → dp[C:]의 최솟값을 정답으로 출력

4.  반복문 순서: 동전 문제(조합)와 동일한 구조

        for cost, num_people in cost_list:
            for i in range(num_people, C+100):
                dp[i] = min(dp[i - num_people] + cost, dp[i])
