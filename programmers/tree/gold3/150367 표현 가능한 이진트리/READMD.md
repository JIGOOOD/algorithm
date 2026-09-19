## **💻 문제 정의**

https://school.programmers.co.kr/learn/courses/30/lessons/150367

## **💡 접근 및 설계**

1. 십진수를 이진수로 바꾼다.
2. 이진수를 inorder 트리로 배치한다.
3. 트리의 루트부터 시작해 연결된 노드 수(1로 구성된 방문 가능한 노드)와 실제 트리의 1의 개수가 같은지 비교한다. 같으면 표현 가능이고, 다르면 표현 불가다.

### **🗒️ 최종 제출 코드**

```cpp
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> b; // 이진수 배열
int n;
int cnt;
int tree[70];
int idx; // b 인덱스

void init(){
    b.clear();
    n = 1;
    cnt = 0;
    memset(tree, 0, sizeof(tree));
    idx = 0;
}

// 10진수를 2진수로 바꾸는 함수
void ntb(long long num){
    while(num > 1){
        b.push_back(num % 2);
        num /= 2;
    }
    b.push_back(num);
    reverse(b.begin(), b.end());
}

// 이진수를 inorder로 배열
void inorder(int i){
    if(i > n) return;
    inorder(i*2);
    tree[i] = b[idx++];
    inorder(i*2+1);
}

void bfs(int cur){
    if(cur > n || !tree[cur]) return;

    int l = cur*2;
    int r = cur*2+1;

    if(l <= n && tree[l]){
        cnt++;
        bfs(l);
    }

    if(r <= n && tree[r]){
        cnt++;
        bfs(r);
    }
}

// tree가 이진트리 되는지 확인
bool tree_or_not(){
    int tar = 0;
    for(int i=1; i<=n; i++){
        if(tree[i]) tar++;
    }

    if(tree[1]){
        cnt++;
        bfs(1);
        if(tar != cnt) return false;
        else return true;

    }else return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(long long num: numbers){
        init();
        ntb(num);
        while(n <= b.size()) n *= 2; n--; // 포화 이진트리 크기 구하기
        while(b.size() < n) b.insert(b.begin(), 0); // 이진수도 포화 이진트리 크기에 맞추기
        inorder(1);
        answer.push_back(tree_or_not());
    }

    return answer;
}
```

---

## **💭 오늘의 회고**

트리를 까먹어서 이리저리 검색하며 풀었다.

### inorder, preorder, postorder

https://johoonday.tistory.com/233

preorder = 루트 → 왼쪽 → 오른쪽
inorder = 왼쪽 → 루트 → 오른쪽
postorder = 왼쪽 → 오른쪽 → 루트

```cpp
void preorder(int i) {
    if (i > n) return;

    cout << tree[i] << ' ';  // 루트
    preorder(i * 2);         // 왼쪽
    preorder(i * 2 + 1);     // 오른쪽
}

void inorder(int i) {
    if (i > n) return;

    inorder(i * 2);          // 왼쪽
    cout << tree[i] << ' ';  // 루트
    inorder(i * 2 + 1);      // 오른쪽
}

void postorder(int i) {
    if (i > n) return;

    postorder(i * 2);        // 왼쪽
    postorder(i * 2 + 1);    // 오른쪽
    cout << tree[i] << ' ';  // 루트
}

// preorder  : 1 2 4 5 3
// inorder   : 4 2 5 1 3
// postorder : 4 5 2 3 1
```

### 포화 트리 개수

포화 트리의 개수는 2\*k-1개여야 한다.

```cpp
while(n <= b.size()) n *= 2; n--; // 포화 이진트리 크기 구하기
```
