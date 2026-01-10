#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
   int t, n;
   scanf("%d", &t);

   for(int j=0; j<t; j++){
    int input[1000002];
    int dp[1000002];
    long long sum = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &input[i]);
    }
    
    int mx = -1;
    for(int i=n-1; i>=0; i--){
        mx = max(input[i], mx);
        dp[i] = mx;
    }

    for(int i=0; i<n; i++){
        if(dp[i] > input[i]) sum += (long long)(dp[i] - input[i]);
    }
    
    printf("%lld\n", sum);
   }
}