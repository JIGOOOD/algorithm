#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int dp[5002];
bool take[5002][5002];
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
        for(int w=m; w>=c; w--){
            if(dp[w] < dp[w-c] + p){
                dp[w] = max(dp[w], dp[w-c] + p);
                take[i][w] = true;
            }
        }
    }

    int w = m;
    stack<int> s;
    for(int i=n; i>=1; i--){
        if(take[i][w]){
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