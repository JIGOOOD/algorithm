#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
#include <set>

int gate[100002];

using namespace std;

int main(){
    int res = 0, g, p, mx = -1;
    set<int, greater<int>> s;

    scanf("%d %d", &g, &p);
    for(int i=1; i<=p; i++){
        scanf("%d", &gate[i]);
        mx = max(mx, gate[i]);
    }
    for(int i=1; i<=mx; i++) s.insert(i);

    for(int i=1; i<=p; i++){
        auto it = s.lower_bound(gate[i]);
        if(it == s.end()) break;
        else{
            res++;
            s.erase(it);
        }
    }
    printf("%d", res);
}