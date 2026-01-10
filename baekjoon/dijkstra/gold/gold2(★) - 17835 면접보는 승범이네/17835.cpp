#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
typedef pair<long long, int> pli;

vector<pli> adj[100002];
long long dist[100002];
vector<int> start;
const long long inf = LLONG_MAX;
int node, edge, k;

void init(){
    for(int i=1; i<=node; i++) dist[i] = inf;
}

void dfs(){
    init();
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for(int i: start){
        dist[i] = 0;
        pq.push({0, i});
    }

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        long long cw = cur.first;
        int cn = cur.second;
        if(cw != dist[cn]) continue;

        for(auto nxt: adj[cn]){
            long long nw = nxt.first;
            int nn = nxt.second;
            if(dist[nn] > cw + nw){
                dist[nn] = cw + nw;
                pq.push({dist[nn], nn});
            }
        }
    }
}

int main(){
    int u, v, c, s;
    scanf("%d %d %d", &node, &edge, &k);
    for(int i=0; i<edge; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[v].push_back({c, u});
    }
    for(int i=0; i<k; i++){
        scanf("%d", &s);
        start.push_back(s);
    }
    dfs();
    auto it = max_element(dist+1, dist+node+1);
    printf("%d\n%lld", it-dist, *it);
}