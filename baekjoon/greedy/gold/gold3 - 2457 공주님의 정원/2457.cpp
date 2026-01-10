#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int>> f;

int main(){
    int n;
    scanf("%d", &n);

    int sm, sd, em, ed;
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &sm, &sd, &em, &ed);
        f.push_back({sm*100+sd, em*100+ed});
    }

    int t = 301; // 커버해야 하는 꽃 시작 날짜
    int cnt = 0;
    while(t < 1201){
        int nxt_t = t; // 다음에 커버할 날짜
        for(int i=0; i<n; i++){
            // 이미 피어있는 꽃 중 끝 날짜가 가장 긴 꽃 선택
            if(f[i].first <= t && f[i].second > nxt_t) nxt_t = f[i].second;
        }
        if(t == nxt_t){ // 더이상 꽃 선택할 수 없을 때
            printf("0");
            return 0;
        }
        cnt++;
        t = nxt_t;
    }
    printf("%d", cnt);
}