/*
lower_bound/upper_bound → O(n² log n)

루프 횟수: n(n-1)/2 ≈ 5×10⁷
log n ≈ log₂ 10000 ≈ 14
→ 총 연산 ≈ 5×10⁷ × 14 ≈ 7×10⁸

C++ 기준, 4초는 살짝 위험
- 일반적으로 1~2억 정도까지 1초에 가능
- 7억이면 4초 제한에서는 버겁거나 바로 터질 수 있음
*/

#include <bits/stdc++.h>
using namespace std;

int a[10002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long cnt = 0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            auto lb = lower_bound(a+j+1, a+n, -a[i]-a[j]);
            auto up = upper_bound(a+j+1, a+n, -a[i]-a[j]);
            cnt += up - lb;
        }
    }
    cout << cnt;
}