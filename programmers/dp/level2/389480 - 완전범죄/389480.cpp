#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int mx = 150;
int dp[42][122]; // dp[i][j]: i개 물건 처리 시, b의 흔적 j일때 a흔적 최솟값

int solution(vector<vector<int>> info, int n, int m) {
    fill(&dp[0][0], &dp[0][0]+42*122, mx);
    dp[0][0] = 0;
    
    int l = info.size();
    for(int i=1; i<=l; i++){ // i = 물건 처리 개수 (1-indexed로 만들기 위함)
        int a = info[i-1][0];
        int b = info[i-1][1];
        for(int j=0; j<m; j++){ // b 흔적 개수
            if(j < b) dp[i][j] = dp[i-1][j] + a; // a를 고름
            else dp[i][j] = min(dp[i-1][j] + a, dp[i-1][j-b]); // 각각 a고름, b고름
        }
    }
    
    int mn = mx;
    for(int i=0; i<m; i++){
        if(dp[l][i] < n) mn = min(mn, dp[l][i]);
    }
    
    if(mn == mx) return -1;
    else return mn;
}