#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int t[17];
int p[17];
int mx = 0;

void dfs(int idx, int sum){
    if(idx > n){
        mx = max(mx, sum);
        return;
    }

    // 상담 하는 경우
    if(idx + t[idx] - 1 <= n){
        dfs(idx + t[idx], sum + p[idx]);
    }

    // 상담 안 하는 경우
    dfs(idx + 1, sum);
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }

    dfs(1, 0);
    printf("%d", mx);
}