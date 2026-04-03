답 봄 (GPT)

### 문제 링크

https://www.acmicpc.net/problem/1005

### 난이도

★★ 아이디어가 잘 안떠오르고, 구현도 그리 쉽진 않음

### 알고리즘 분류

- 위상정렬
- DP

### 핵심 아이디어

- w를 짓는 최소 완료 시간은 모든 선행 건물 중 가장 늦게 끝난 경로가 걸리는 시간임. 즉 최장경로 DP임.
  ```python
  dp[nxt] = max(dp[nxt], dp[cur] + time[nxt])
  ```
