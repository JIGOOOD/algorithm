답봄

### 문제 링크

https://www.acmicpc.net/problem/14921

### 난이도

★ 힌트나 답을 보고 쉽게 풀 수 있음

### 알고리즘 분류

- 투포인터

### 핵심 아이디어

- 값 하나를 중점으로 두고, 그 이후에 나오는 요소들에 대해 투포인터로 나머지 2개 선택
- 양쪽에서 0과 근접한 값을 향해 조여오는 형태

### 로직

    for i=0 to n-2
        l = i+1, r = n-1
        while(l < r)
            if(sum > 0) r--
            else if(sum < 0) l++
            else print
