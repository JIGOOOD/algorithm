#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int seq[102]; // 입력
vector<int> plug; // 플러그에 꽂혀있는 기기
vector<int> order[102]; // 등장 순서

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=k; i++){
        scanf("%d", &seq[i]);
        order[seq[i]].push_back(i);
    }
    
    int multi = 0; // 꽂힌 플러그 수
    int res = 0; // 최소 플러그 뺀 수
    for(int i=1; i<=k; i++){
        if(find(plug.begin(), plug.end(), seq[i]) != plug.end()) continue; // 이미 꽂혀있음
        if(multi < n){ // 플러그 꽂기
            multi++;
        }
        else{ // 빼고 꽂기
            int mx = -1;
            int val;
            for(int p: plug){ // 꽂혀있는 애 중 나중에 등장 덜하는 애 찾기
                auto it = lower_bound(order[p].begin(), order[p].end(), i); // i이후에 p 언제 쓰이는지
                if(it == order[p].end()){
                    val = p;
                    break;
                }else{
                    if(*it > mx){
                        mx = *it;
                        val = p;
                    }
                }
            }
            plug.erase(remove(plug.begin(), plug.end(), val), plug.end()); // 플러그 뺌
            res++;
        }
        plug.push_back(seq[i]);
    }
    printf("%d", res);
}