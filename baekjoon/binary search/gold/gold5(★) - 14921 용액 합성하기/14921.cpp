#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef pair<int, int> pii;

long long a[5002];
long long v[3];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    sort(a, a+n);
    
    long long res = 3'000'000'001;
    for(int i=0; i<n-2; i++){
        int l = i+1, r = n-1;
        while(l < r){
            long long sum = a[l] + a[r] + a[i];
            if(abs(res) > abs(sum)){
                res = sum;
                v[0] = a[l];
                v[1] = a[r];
                v[2] = a[i];
            }

            if(sum > 0LL) r--;
            else if(sum < 0LL) l++;
            else{
                v[0] = a[l];
                v[1] = a[r];
                v[2] = a[i];
                sort(v, v+3);
                printf("%lld %lld %lld", v[0], v[1], v[2]);
                return 0;
            }
        }
    }
    sort(v, v+3);
    printf("%lld %lld %lld", v[0], v[1], v[2]);
}