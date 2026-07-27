#include <iostream>
#include <algorithm>

using namespace std;

int dp[102][102]; // dp[i][c] = i일차에 c개의 쿠폰 가진 상태에서 지불 비용 최솟값
bool except[102];
int inf = 1000002;

int main(){
    int n, m;
    cin >> n >> m;

    int day;
    for(int i=0; i<m; i++){
        cin >> day;
        except[day] = true;
    }

    fill(&dp[0][0], &dp[0][0] + 102 * 102, inf);
    dp[0][0] = 0;
    
    for(int i=1; i<=n; i++){
        for(int c=0; c<=52; c++){
            if(dp[i-1][c] == inf) continue; // 도달 불가능한 상태
            if(except[i]){
                dp[i][c] = min(dp[i][c], dp[i-1][c]);
                continue;
            }
            dp[i][c] = min(dp[i][c], dp[i-1][c] + 10000); // 하루권
            dp[min(i+2,n)][c+1] = min(dp[min(i+2,n)][c+1], dp[i-1][c] + 25000); // 3일권
            dp[min(i+4,n)][c+2] = min(dp[min(i+4,n)][c+2], dp[i-1][c] + 37000); // 5일권
            if(c >= 3) dp[i][c-3] = min(dp[i][c-3], dp[i-1][c]); // 쿠폰
        }
    }

    int mn = inf;
    for(int i=0; i<55; i++) mn = min(mn, dp[n][i]);
    cout << mn;
}