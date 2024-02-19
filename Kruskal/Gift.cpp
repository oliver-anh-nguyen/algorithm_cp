#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Edge {
    int u, v, a, b;
};

int n, m , par[205];
long long G, S;

bool cmp(Edge x, Edge y) {
    return x.a < y.a;
}

int getRoot(int u) {
    return u == par[u] ? u : par[u] = getRoot(par[u]);
}


int main() {
    cin >> n >> m >> G >> S;
    vector<Edge> edges(m);
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].a >> edges[i].b;
    }
    
    sort(edges.begin(), edges.end(), cmp);
    vector<Edge> curEdges;
    long long res = 2e18 + 5;
    
    for (Edge e: edges) {
        curEdges.push_back(e);
        int k = curEdges.size() - 1;
        while (k > 0 && curEdges[k].b < curEdges[k-1].b) {
            swap(curEdges[k], curEdges[k-1]);
            k--;
        }
        for (int u = 1; u <= n; u++) {
            par[u] = u;
        }
        int removeIndex = -1;
        for (int i = 0; i < curEdges.size(); i++) {
            int pu = getRoot(curEdges[i].u);
            int pv = getRoot(curEdges[i].v);
            if (pu != pv) {
                par[pv] = pu;
            } else {
                removeIndex = i;
            }
        }
        if (removeIndex != -1) {
            curEdges.erase(curEdges.begin() + removeIndex);
        }
        if (curEdges.size() == n - 1) {
            res = min(res, G * e.a + S * curEdges[n-2].b);
        }
    }
    cout << res;
    return 0;
}
