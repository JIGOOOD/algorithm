#include <iostream>
#include <stack>

using namespace std;

int w[22][302]; // w[i][j]: 기업 i이 j원 고를 때의 이익
int dp[22][302]; // dp[i][j]: 기업 1~i까지 돈 j원을 골랐을 때의 최대 이익
int cost[22][302]; // cost[i][j]: dp[i][j] 선택할 때 기업 i가 고른 금액

int main(){
    int n, m;
    cin >> n >> m;
    
    int c, v;
    for(int i=0; i<n; i++){
        cin >> c;
        for(int j=1; j<=m; j++){
            cin >> v;
            w[j][c] = v;
        }
    }

    for(int i=1; i<=m; i++){ // 기업
        for(int j=0; j<=n; j++){ // 전체 돈
            for(int k=0; k<=j; k++){ // 기업 i가 선택한 돈
                int val = dp[i-1][j-k] + w[i][k];
                if(dp[i][j] < val){
                    dp[i][j] = val;
                    cost[i][j] = k;
                }
            }
        }
    }

    int mx = 0; // 최대 이익
    int total_cost = 0; // 최대 금액
    for(int i=0; i<=n; i++){
        if(mx < dp[m][i]){
            mx = dp[m][i];
            total_cost = i;
        }
    }
    cout << mx << '\n';

    stack<int> s;
    for(int i=m; i>=1; i--){
        s.push(cost[i][c]);
        c -= cost[i][c];
    }
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
}