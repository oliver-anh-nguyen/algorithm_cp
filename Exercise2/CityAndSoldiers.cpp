#include <iostream>

using namespace std;

const int maxN = 1e5 + 5;

int parent[maxN];

int findSet(int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
};

void unionSet(int u, int v) {
    int pu = findSet(u);
    int pv = findSet(v);
    if (pu == pv) return;
    parent[pu] = pv;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    while(q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            unionSet(a, b);
        }
        if (t == 2) {
            int a;
            cin >> a;
            int ap = findSet(a);
            parent[ap] = a;
            parent[a] = a;
        }
        if (t == 3) {
            int a;
            cin >> a;
            cout << findSet(a) << '\n';
        }
    }
    return 0;
}
