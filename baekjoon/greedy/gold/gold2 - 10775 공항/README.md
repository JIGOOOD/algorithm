### 알고리즘 분류

- 그리디
- 이분 탐색
- 자료구조(set)

### 핵심 아이디어: log n에 특정 원소를 지울 수 있어야 한다.

- vector(x) -> O(n)
- set, multiset, map, multimap (O)

### 로직

1. gi 중 등장하는 mx 값 구함
2. 1~mx까지 set에 넣기 (gi 이하 중 큰 값을 고르기 위해 역순 정렬)
3. 1~q 비행기 돌면서 set 이분 탐색(lower_bound) -> gi 이하 중 최댓값 찾기 가능 O(log N)
4. 만약 it가 end가 아니면 res++, it 제거, end면 break (도킹 X)
