## **💻 문제 정의**

https://jungol.co.kr/problem/1141?cursor=OCwxMSww

## **💡 접근 및 설계**

스택 문제가 대충 스택인건 알겠는데, 풀이가 잘 안떠오른다.

### **✏️ 알고리즘 풀이**

i번째 소를 볼 수 있는 애들을 더함.

i번째 소를 넣기 전에, 이보다 작은 키의 소를 다 뺌 (나를 볼 수 없음)

그리고 스택에 있는 사이즈를 구하면 나를 볼 수 있는 소들만 남음. 그 값을 정답에 더함.

그리고 나를 넣음

### **🗒️ 최종 제출 코드**

```python
n = int(input())
s = []

ans = 0

for _ in range(n):
    h = int(input())
    while s and s[-1] <= h: s.pop()
    ans += len(s)
    s.append(h)

print(ans)
```