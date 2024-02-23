#include <iostream>

using namespace std;

const int maxN = 1e3 + 5;

int m, n, parent[maxN * maxN];
char a[maxN][maxN];

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
    parent[pv] = pu;
}

int id(int i, int j) {
    return (i - 1) * n + j;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            a[i][j] = s[j-1];
        }
    }
    for (int i = 1; i <= m * n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i > 1 && a[i][j] == a[i-1][j]) {
                unionSet(id(i, j), id(i-1, j));
            }
            if (j > 1 && a[i][j] == a[i][j-1]) {
                unionSet(id(i, j), id(i, j-1));
            }
        }
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int u, v, s, t;
        cin >> u >> v >> s >> t;
        if (findSet(id(u, v)) == findSet(id(s, t))) {
            if (a[u][v] == '1') {
                cout << "decimal" << '\n';
            } else {
                cout << "binary" << '\n';
            }
        } else {
            cout << "neither" << '\n';
        }
    }
    return 0;
}
