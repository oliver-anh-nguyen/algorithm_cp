#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

int parent[maxN], ranks[maxN], colors[maxN], idxColor[maxN], a[maxN];

int findSet(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void unionSet(int u, int v) {
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

int main() {
    int t, n, q, id, x, y;
    cin >> t;
    for (int tt = 1; tt <= t; tt++){
        cin >> n >> q;
        for (int i = 0; i < maxN; i++) {
            idxColor[i] = colors [i] = -1;
            parent[i] = i;
            ranks[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            if (idxColor[a[i]] == -1) {
                idxColor[a[i]] = i;
                colors[i] = a[i];
            } else {
                int u = idxColor[a[i]];
                unionSet(u, i);
                u = findSet(i);
                idxColor[a[i]] = u;
                colors[u] = a[i];
            }
        }
        cout << "Case " << tt << ":\n";
        for (int i = 1; i <= q; i++){
            cin >> id >> x;
            if (id == 1){
                cin >> y;
                if (x == y) continue;
                if (idxColor[x] != -1){
                    if (idxColor[y] != -1){
                        unionSet(idxColor[x], idxColor[y]);
                        int u = findSet(idxColor[x]);
                        idxColor[y] = u;
                        colors[u] = y;
                    } else {
                        idxColor[y] = idxColor[x];
                        colors[idxColor[x]] = y;
                    }
                    idxColor[x] = -1;
                }
            } else {
                int u = findSet(x);
                cout << colors[u] <<'\n';
            }
        }
    }
    return 0;
}
