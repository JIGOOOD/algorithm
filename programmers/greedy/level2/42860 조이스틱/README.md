## **💻 문제 정의**

https://school.programmers.co.kr/learn/courses/30/lessons/42860

## **💡 접근 및 설계**

상하로 이동하는 거랑, 좌우로 이동하는 것의 최솟값 구하는 방법을 각각 구한 후 합한다.

상하 이동은 min(target 알파벳, - ‘A’, len(name), target 알파벳)

좌우 이동은 **오른쪽으로 어느 지점까지 가다가 꺾어서 반대편(왼쪽 wrap)으로 넘어가는 모든 "꺾는 지점"을 다 구해서, 그중 이동 거리가 최소인 경우를 찾는다.** (AI 도움)

### **🗒️ 최종 제출 코드**

```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int len = name.size();
    int answer = 0;

    // 1. 회전 비용 계산
    // 각 위치의 문자를 'A'에서 목표 문자로 바꾸는 데 필요한 최소 조작 횟수를 전부 더함
    // 위로 올리는 경우(tar-'A')와 아래로 내리는 경우(순환, 'Z'-tar+1) 중 짧은 쪽 선택
    for(int i=0; i<len; i++){
        char tar = name[i];
        answer += min(tar-'A', 'Z'-tar+1);
    }

    // 2. 이동 비용 계산
    // 커서는 0번 위치에서 출발.
    // 최적 경로는 "오른쪽으로 어디까지 가다가, 거기서 꺾어서 반대편(왼쪽 wrap)으로 넘어가는" 형태.
    // 그 "꺾는 지점" i를 전부 시도해서 이동 거리가 최소인 경우를 찾는다.

    int mn = len - 1; // 기본값: 안 꺾고 그냥 오른쪽 끝까지 쭉 가는 경우

    for(int i=0; i<len; i++){
        // i번 위치가 'A'면 애초에 방문할 필요가 없는 칸이므로 꺾는 지점으로 의미 없음
        if(name[i] == 'A') continue;

        // i보다 뒤쪽에서 아직 수정이 필요한(=A가 아닌) 첫 번째 위치를 탐색
        // i까지는 오른쪽으로 처리 완료했다고 가정하고, 남은 구간이 어디서부터 시작하는지 찾는 것
        int next = i+1;
        while(next < len && name[next] == 'A'){
            next++;
        }
        // next는 "i 이후 첫 non-A 위치" (없으면 len)

        // i번 위치에서 꺾는다고 가정했을 때 이동 비용
        // i*2        : 0->i까지 오른쪽 이동(i번) + 다시 0으로 되돌아옴(i번)
        //              (0으로 돌아가는 이유: 왼쪽으로 한 번 더 가면 wrap-around로 마지막 칸 점프 가능)
        // (len-next) : 0에서 wrap으로 마지막 칸(len-1)까지 점프한 뒤,
        //              거기서 왼쪽 방향(인덱스 감소)으로 next 위치까지 이동하는 비용
        int cost = i*2 + (len - next);

        // 지금까지 계산한 것 중 가장 작은 이동 비용으로 갱신
        if(cost < mn){
            mn = cost;
        }
    }

    // 3. 회전 비용 + 최소 이동 비용을 합쳐서 최종 답 반환
    answer += mn;
    return answer;
}
```
