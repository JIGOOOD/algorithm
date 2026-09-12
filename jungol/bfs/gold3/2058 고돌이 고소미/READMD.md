## **💻 문제 정의**

https://jungol.co.kr/problem/2058

## **💡 접근 및 설계**

처음에는 따로 bfs 돌리는 걸 생각했는데, 그러면 가시돋친 부분 겹치는 부분을 구할 수 없고 그냥 로직 자체가 안돼서 기각했다.

아무리 생각해도 가시돋친 부분에서 만나지 않는 로직을 구현할 방법이 안 떠올라 AI에 힌트를 받아 풀었다.

### **✏️ 알고리즘 풀이**

1. 고돌이와 고순이의 위치 전체를 bfs에 넣고 돌린다.
   1. 상태 개수가 n^4이므로 25^4 ≤ 39만으로 완탐 가능하다.
   2. 한 초마다 둘이 동시에 움직인다고 생각한다. 각자 8방향 중 하나로 이동하거나, 그 자리에 머무를 수도 있다.
   3. 새로운 상태가 유효한지는 격자 범위 안에 있는지, 웅덩이가 아닌지, 체비셰프거리(행차이와 열차이 중 큰 값)이 2 이상인지를 검사한다.
   4. 둘다 집에 도착하면 멈춘다.

### **🗒️ 최종 제출 코드**

```cpp
#include <iostream>
#include <tuple>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int, int> tti;

int dist[27][27][27][27];
int board[27][27];
int dx[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int n;
    cin >> n;

    int mx, my, mhx, mhy;
    int wx, wy, whx, why;
    cin >> mx >> my >> mhx >> mhy;
    cin >> wx >> wy >> whx >> why;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }

    deque<tti> q;
    q.push_back({mx, my, wx, wy});
    dist[mx][my][wx][wy] = 1;

    while(!q.empty()){
        auto [cmx, cmy, cwx, cwy] = q.front(); q.pop_front();
        if(cmx == mhx && cmy == mhy && cwx == whx && cwy == why){
            cout << dist[cmx][cmy][cwx][cwy] - 1;
            break;
        }

        for(int i=0; i<9; i++){
            int nmx = cmx + dx[i];
            int nmy = cmy + dy[i];

            if(nmx <= 0 || nmx > n || nmy <= 0 || nmy > n) continue;
            if(board[nmx][nmy]) continue;

            for(int j=0; j<9; j++){
                int nwx = cwx + dx[j];
                int nwy = cwy + dy[j];

                if(nwx <= 0 || nwx > n || nwy <= 0 || nwy > n) continue;
                if(board[nwx][nwy]) continue;

                if(dist[nmx][nmy][nwx][nwy]) continue;
                if(max(abs(nmx-nwx), abs(nmy-nwy)) < 2) continue;

                dist[nmx][nmy][nwx][nwy] = dist[cmx][cmy][cwx][cwy] + 1;
                q.push_back({nmx, nmy, nwx, nwy});
            }
        }
    }
}
```

---

## **💭 오늘의 회고**

두 가지 상태를 동시에 다루는 bfs는 처음 풀어보는 것 같다. 신기하네. 좋은 경험이다.
