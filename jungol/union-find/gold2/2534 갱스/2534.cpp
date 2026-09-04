#include <iostream>
#include <vector>

using namespace std;

int p[1002];
int cnt[1002];

void init(int n){
    for(int i=1; i<=n; i++){
        p[i] = i;
        cnt[i] = 1;
    }
}

int find(int node){
    if(p[node] == node) return node;
    return p[node] = find(p[node]);
}

void join(int u, int v){
    int pu = find(u);
    int pv = find(v);

    if(pu == pv) return;
    if(cnt[pu] > cnt[pv]) swap(pu, pv); // v밑에 u

    p[pu] = pv;
    cnt[pv] += cnt[pu];
}

int main(){
    int n, m;
    cin >> n >> m;
    
    init(n);
    
    char c;
    int p, q;
    vector<vector<int>> e(n+1);

    for(int i=0; i<m; i++){
        cin >> c >> p >> q;
        if(c == 'F'){
            join(p, q);
        }else{
            e[p].push_back(q);
            e[q].push_back(p);
        }
    }

    for(int i=1; i<=n; i++){
        if(e[i].empty()) continue;

        int f = e[i][0];
        for(int j=1; j<e[i].size(); j++){
            join(f, e[i][j]);
        }
    }

    int res = 0;
    for(int i=1; i<=n; i++){
        if(find(i) == i) res++;
    }

    cout << res;
}