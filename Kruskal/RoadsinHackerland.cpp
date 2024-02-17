#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MAX = 1e6;

int parent[MAX];
int Rank[MAX];
piii edges[MAX];
int n, m, sz[MAX];
vector<pii> graph[MAX];
int mx = 0;
long long ans[MAX];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        Rank[i] = 1;
    }
}

int findSet(int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

bool unionSet(int u, int v) {
    int pu = findSet(u);
    int pv = findSet(v);
    
    if (pu == pv) return false;
    
    if (Rank[pu] > Rank[pv]) {
        parent[pv] = pu;
    } else if (Rank[pu] < Rank[pv]) {
        parent[pu] = pv;
    } else {
        parent[pv] = pu;
        Rank[pu]++;
    }
    return true;
}

void kruskal() {
    sort(edges + 1, edges + 1 + m);
    makeSet(n);
    
    for (int u, v, w, i = 1; i <= m; i++) {
        u = edges[i].second.first;
        v = edges[i].second.second;
        w = edges[i].first;
        if(findSet(u) != findSet(v)) {
            unionSet(u, v);
            graph[u].push_back(pii(v, w));
            graph[v].push_back(pii(u, w));
        }
    }
}

void dfs(int u, int p, int b) {
    sz[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        int w = graph[u][i].second;
        if (v == p) {
            continue;
        }
        dfs(v, u, w);
        sz[u] += sz[v];
    }
    ans[b] += 1LL * sz[u] * (n - sz[u]);
    mx = max(mx, b);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }
    kruskal();
    dfs(1, 0, 0);
    for (int i = 0; i <= mx; i++) {
        ans[i + 1] += ans[i] / 2;
        ans[i] %= 2;
        if (ans[i + 1] > 0) {
            mx = max(mx, i + 1);
        }
    }
    for(int i = mx; i >= 0; i --) {
        cout << ans[i];
    }
    return 0;
}
