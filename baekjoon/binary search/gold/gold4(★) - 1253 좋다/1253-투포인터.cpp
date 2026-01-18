#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int a[2002];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);

    int cnt = 0;
    for(int i=0; i<n; i++){
        int cur = a[i];
        int l = 0, r = n-1;
        while(l < r){
            if(l == i) l++;
            if(r == i) r--;
            if(l >= n || r < 0 || r == l) break;

            int sum = a[l] + a[r];
            if(sum > cur) r--;
            else if(sum < cur) l++;
            else{ // 맞는 조합 찾음
                cnt++;
                break;
            }
        }
    }
    printf("%d", cnt);
}