#include <iostream>

using namespace std;

long long a[1000002];
long long s[1000002];
int r[1002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        r[s[i] % m]++;
    }

    // 0인 개수 + 각 개수 c 몇
    long long res = r[0]; 
    for(int i=0; i<m; i++){
        res += (long long)r[i] * (r[i] - 1) / 2;
    }
    cout << res;
}