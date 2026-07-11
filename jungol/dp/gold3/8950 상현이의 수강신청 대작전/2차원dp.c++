#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int dp[5002][5002];
pair<int, int> a[5002];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> a[i].first >> a[i].second;
    }

    for(int i=1; i<=n; i++){
        int p, c;
        tie(p, c) = a[i];
        for(int w=1; w<=m; w++){
            if(w < c) dp[i][w] = dp[i-1][w];
            else dp[i][w] = max(dp[i-1][w], dp[i-1][w-c] + p);
        }
    }

    int w = m;
    stack<int> s;
    for(int i=n; i>=1; i--){
        if(dp[i][w] != dp[i-1][w]){
            s.push(i);
            w -= a[i].second;
        }
    }

    if(s.empty()) cout << -1;
    else{
        cout << s.size() << '\n';
        while(!s.empty()){
            cout << s.top() << ' ';
            s.pop();
        }
    }
}