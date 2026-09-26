## **💻 문제 정의**

https://jungol.co.kr/problem/2499?cursor=OCwyLDU%3D

## **💡 접근 및 설계**

알고리즘이 안 떠올라 힌트를 받아 풀었다.

만약 처음부터 현재까지 본 배열이 1부터 s까지 커버할 수 있다면, 다음에 들어오는 수가 커버할 수 있는 범위는 “다음 수 ~ s + 다음 수” 이다.

이 범위가 계속 이어져야 한다. 이어지는 조건은 en +1 ≥ nst이다.

안이어진다면 en+1부터 만들어낼 수 없으므로 탐색을 종료한다.

### **🗒️ 최종 제출 코드**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a;

    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        a.push_back(num);
    }

    sort(a.begin(), a.end());

    int st = 1, en = 1;
    if(a[0] != 1) en = 0;
    else{
        for(int i=1; i<n; i++){
            int nst = a[i];
            int nen = en + a[i];
            if(nst <= en+1) en = nen;
            else break;
        }
    }
    cout << en+1;
    return 0;
}
```