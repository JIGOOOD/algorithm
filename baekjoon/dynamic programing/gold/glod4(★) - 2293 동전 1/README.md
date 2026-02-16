답 봄 (지피티)

### 문제 링크

https://www.acmicpc.net/problem/2293

### 난이도

★ 힌트나 답을 보고 쉽게 풀 수 있음

### 알고리즘 분류

- DP

### 핵심 아이디어

1.  DP 정의: dp[i] = 금액 i를 만드는 경우의 수

    초기값: dp[0] = 1

2.  점화식: dp[i] += dp[i - coin]

    의미: i원을 만들기 위해 마지막에 coin을 사용했다고 가정하면 이전 상태는 i - coin 이다.

3.  반복문 순서에 따른 차이

    1️⃣ 조합 (순서 무시)

        for coin in coins:
            for i in range(coin, k+1):
                dp[i] += dp[i - coin]

    의미: 동전을 하나씩 확정하면서 누적, 동전 사용 순서가 고정됨

    -> 1+2와 2+1을 같은 경우로 처리

    ✔ 결과 → 조합 계산

    2️⃣ 순열 (순서 고려)

        for i in range(1, k+1):
            for coin in coins:
                if i - coin >= 0:
                    dp[i] += dp[i - coin]

    의미: i원을 만들 때 모든 동전을 시도, 이전 상태가 이미 순서별로 저장되어 있음

    -> 1+2와 2+1이 따로 계산됨

    ✔ 결과 → 순열 계산
