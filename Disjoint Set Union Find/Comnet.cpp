#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> ranks;

int findSet(int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void joinSet(int u, int v) {
    int pu = findSet(u);
    int pv = findSet(v);
    
    if (pu == pv) return;
    
    if (ranks[pu] > ranks[pv]) {
        parent[pv] = pu;
    } else if (ranks[pu] < ranks[pv]) {
        parent[pu] = pv;
    } else {
        parent[pv] = pu;
        ranks[pu]++;
    }
}

struct edge {
    int u, v, w;
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<edge> edges(m);
        for (int i = 0; i< m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            edges[i].u--;
            edges[i].v--;
        }
        while (q--) {
            vector<edge> edses_save = edges;
            int id, s;
            cin >> id;
            id--;
            cin >> s;
            while (s--) {
                int k, p;
                cin >> k >> p;
                k--;
                edges[k].w = p;
            }
            parent = ranks = vector<int>(n, 1);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            for (int i = 0; i < m; i++) {
                if (edges[i].w < edges[id].w) {
                    joinSet(edges[i].u, edges[i].v);
                }
            }
            if (findSet(edges[id].u) == findSet(edges[id].v)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            edges = edses_save;
        }
    }
    return 0;
}
