#include <iostream>
#include <algorithm>

using namespace std;

int r[7] = {0, -1, -1, -1, -1, -1, -1}; // 각 0~6 나머지가 처음 등장한 인덱스

int main(){
    int n;
    cin >> n;

    long long id;
    long long bf = 0;
    int mx = 0;
    for(int i=1; i<=n; i++){
        cin >> id;
        bf += id;
        int rr = bf % 7;
        if(r[rr] == -1) r[rr] = i;
        else mx = max(mx, i-r[rr]);
    }
    cout << mx;
}