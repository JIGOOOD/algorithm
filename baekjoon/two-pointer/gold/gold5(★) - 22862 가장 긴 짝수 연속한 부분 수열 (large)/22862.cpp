#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pii;

int a[1000002];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    int st = 0, en = 0, mx = 0, even = 0, odd = 0;
    while(st <= en && en < n){
        if(a[en] % 2 == 0) even++;
        else odd++;

        if(odd > k){
            while(odd > k){
                if(a[st] % 2 == 0) even--;
                else odd--;
                st++;
            }
        }
        mx = max(mx, en-st+1-odd);
        en++;
    }
    printf("%d", mx);
}