## **💻 문제 정의**

https://jungol.co.kr/problem/3074

## **💡 접근 및 설계**

아니 냅색 안한지 얼마나됐다고 그새 까먹었다….

꼭 도보, 자전거 둘 중 하나를 골라야 한다. 그래서 도달 못하는 경로를 탐색할 수 있기 때문에 이를 처리해줘야 한다.

### **🗒️ 최종 제출 코드**

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int n, k, mx = 0;
int _time[102][2];
int money[102][2];
int dp[102][100002];

int main(){
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    cin >> n >> k;
    int t1, t2, m1, m2;
    for(int i=1; i<=n; i++){
        cin >> _time[i][0] >> money[i][0] >> _time[i][1] >> money[i][1];
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            int t1 = _time[i][0];
            int t2 = _time[i][1];
            if(t1 <= j && dp[i-1][j-t1] != -1){
                dp[i][j] = max(dp[i][j], dp[i-1][j-t1] + money[i][0]);
            }
            if(t2 <= j && dp[i-1][j-t2] != -1){
                dp[i][j] =  max(dp[i][j], dp[i-1][j-t2] + money[i][1]);
            }
        }
    }
    
    int mx = 0;
    for(int i=0; i<=k; i++) mx = max(mx, dp[n][i]);
    cout << mx;
}
```