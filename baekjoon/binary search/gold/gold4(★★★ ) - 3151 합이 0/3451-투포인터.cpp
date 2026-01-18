/*
N 최대 10000
시간 복잡도 O(N^2) => 4초 시간 제한 넉넉하게 통과
10000 * 10000 = 1억
*/


#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef pair<int, int> pii;

int a[10002];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    
    long long cnt = 0;
    for(int i=0; i<n-2; i++){
        int l = i+1, r = n-1;
        while(l < r){
            int sum = a[l] + a[r] + a[i];
            if(sum > 0) r--;
            else if(sum < 0) l++;
            else{ // sum = 0
                if(a[l] == a[r]){ // 중복
                    // left~right 모두 같은 값이면 조합 C(n,2) = (n * n-1) / 2
                    cnt += (long long)(r-l+1)*(r-l)/2;
                    break;
                } else {
                    // l은 오른쪽으로만 가고, r은 왼쪽으로만 감 => 그냥 포인터 이동 개념은 시간 복잡도가 O(N)
                    int cnt_l = 1, cnt_r = 1;
                    while(l+cnt_l < r && a[l+cnt_l] == a[l]) cnt_l++;
                    while(r-cnt_r > l && a[r-cnt_r] == a[r]) cnt_r++;
                    cnt += (long long)cnt_l * cnt_r;
                    l += cnt_l;
                    r -= cnt_r;
                }
            }
        }
    }
    printf("%lld", cnt);
}