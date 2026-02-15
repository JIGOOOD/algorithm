#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int t[17];
int p[17];
int dp[17];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }

    for(int i=n; i>=1; i--){
        if(i + t[i] - 1 <= n){ // 상담 가능
            dp[i] = max(dp[i + t[i]] + p[i], dp[i+1]);
        }else{ // 상담 불가능
            dp[i] = dp[i+1];
        }
    }
    printf("%d", dp[1]);
}