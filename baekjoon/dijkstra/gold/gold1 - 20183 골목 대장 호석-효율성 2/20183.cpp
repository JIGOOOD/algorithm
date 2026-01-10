#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

vector<pair<long long, int>> adj[100002];
long long dist[100002];
int n, m, st, en; long long c;

void init(){
    for(int i=1; i<=n; i++) dist[i] = LLONG_MAX;
}

bool dfs(long long x) {
    init();
    priority_queue <
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;  

    dist[st] = 0;
    pq.push({0, st});
    while(!pq.empty()) {
        auto [cw, cur] = pq.top(); pq.pop();
        if(dist[cur] != cw) continue;
        for(auto [nw, nxt] : adj[cur]) {
            if(nw > x) continue;
            if(dist[nxt] <= nw + cw) continue;
            dist[nxt] = nw + cw;
            pq.push({dist[nxt], nxt});
        }
    }

    if(dist[en] > c) return 0;
    return 1;
}

int main() {
    long long lo = 1, hi = -1;
    scanf("%d %d %d %d %lld", &n, &m, &st, &en, &c);

    while(m--) {
        int u, v; long long cost;
        scanf("%d %d %lld", &u, &v, &cost);
        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
        hi = max(hi, cost);
    }

    while(lo < hi) {
        long long mid = (lo + hi) / 2;
        if(dfs(mid)) hi = mid;
        else lo = mid + 1;
    }

    if(dfs(lo)) printf("%lld", lo);
    else printf("-1");
}