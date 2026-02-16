#include <cstdio>

using namespace std;

int val[102];
int dp[10002];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%d", &val[i]);

    dp[0] = 1;
    for(int j=1; j<=n; j++){
        for(int i=1; i<=k; i++){
            if(i - val[j] < 0) continue;
            dp[i] += dp[i-val[j]];
        }
    }
    printf("%d", dp[k]);
}
