#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// dp[i] = i번째 원소를 마지막으로 하는 증가 부분 수열의 최대 합

int a[1002];
int dp[1002];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    int mx = 0;
    for(int i=0; i<n; i++){
        dp[i] = a[i];
        for(int j=0; j<i; j++){
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
        }
        mx = max(mx, dp[i]);
    }
    printf("%d", mx);
}