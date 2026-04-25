https://cocoon1787.tistory.com/396#google_vignette

### 문제 링크

https://www.acmicpc.net/problem/10986

### 난이도

★★ 아이디어가 잘 안떠오르고, 구현도 그리 쉽진 않음

### 알고리즘 분류

- 누적합 (Prefix Sum)
- 수학 (조합)

### 핵심 아이디어

1.  모듈러 연산 성질 활용

    구간 합 `sum(i~j) % M = 0` 이 되려면:

    `(PrefixSum[j] - PrefixSum[i]) % M = 0`
    → `PrefixSum[j] % M = PrefixSum[i] % M`

    즉, 누적합을 M으로 나눈 나머지가 같은 두 인덱스 쌍을 찾으면 됨

2.  풀이 흐름
    - 누적합을 구하면서 각 누적합을 M으로 나눈 나머지를 `cnt[]` 배열에 카운팅
    - 나머지가 같은 인덱스 쌍의 수 = `cnt[i] × (cnt[i] - 1) / 2` (조합)
    - 나머지가 0인 누적합은 그 자체로 조건을 만족하므로 `cnt[0]`을 별도로 더함

3.  최종 점화식

        ans = Σ cnt[i] × (cnt[i] - 1) / 2  +  cnt[0]
