#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef pair<int, int> pii;

int a[1000002];
vector<int> v; // 길이별 LIS의 최소 끝값 배열

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    v.push_back(a[0]);
    for(int i=1; i<n; i++){
        if(v.back() < a[i]) v.push_back(a[i]);
        else{ // 배열 보다 작음
            auto it = lower_bound(v.begin(), v.end(), a[i]);
            v[it-v.begin()] = a[i];
        }
    }
    printf("%d", v.size());
}