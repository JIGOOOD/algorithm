#include <iostream>
#include <cstring>

using namespace std;

char board[52][52];
int dp[52][52][2][5]; // i, j, dir, cnt(꺾은 횟수), i, j의 dir 방향으로 cnt 꺾어서 올 수 있는 횟수, dir = 0 = 위쪽, 1 = 왼쪽

int main(){
    int t, n, k;
    cin >> t;

    while(t--){
        cin >> n >> k;
        memset(dp, 0, sizeof(dp));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> board[i][j];
            }
        }

        if(board[1][0] != 'H') dp[2][1][0][0] = 1; // 위쪽 초기값
        if(board[0][1] != 'H') dp[1][2][1][0] = 1; // 왼쪽 초기값
        int ans = 0;
        for(int c=0; c<=k; c++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if((i == 1 && (j == 1 || j == 2)) || (i == 2 && j == 1)) continue;
                    if(board[i-1][j-1] == 'H') continue;
                    dp[i][j][0][c] += dp[i-1][j][0][c];
                    dp[i][j][1][c] += dp[i][j-1][1][c];
                    if(c > 0){
                        dp[i][j][0][c] += dp[i-1][j][1][c-1];
                        dp[i][j][1][c] += dp[i][j-1][0][c-1];
                    }
                }
            }
            ans += (dp[n][n][0][c] + dp[n][n][1][c]);
        }
        cout << ans << '\n';
    }
}