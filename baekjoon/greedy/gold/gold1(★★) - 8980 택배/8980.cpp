#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
vector<tuple<int, int, int>> info;
int truck[2002];

int main(){
    int n, c, m, a, b, cnt;
    scanf("%d %d %d", &n, &c, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &cnt);
        info.push_back({b, a, cnt});
    }
    sort(info.begin(), info.end());

    int res = 0;
    for(auto p: info){
        int st, en, weight;
        tie(en, st, weight) = p;

        for(int i=st; i<en; i++){ // 박스가 en에서는 내려지니까 제외
            // st~en 구간에 해당 박스를 얼마나 싣을 수 있는지 판별
            weight = min(weight, c-truck[i]);
        }
        // 싣을 수 있는 박스 최소 무게 결정 완료

        if(weight != 0){
            res += weight;
            for(int i=st; i<en; i++){
                truck[i] += weight;
            }
        }
    }
    printf("%d", res);
}