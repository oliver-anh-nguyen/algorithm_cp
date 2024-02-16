#include <iostream>
#include <vector>
#include <set>
//#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000 + 5;

int parent[maxN], ranks[maxN];
int n, u, v;
vector<pair<int, int>> close;

void makeSet() {
    for (int i = 0; i <= maxN; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

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
    makeSet();
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        if (findSet(u) != findSet(v)) {
            unionSet(u, v);
        } else {
            close.push_back({u, v});
        }
    }
    set<int> s;
    for (int i = 1; i <= n; i++) {
        int x = findSet(i);
        s.insert(x);
    }
    int prev = -1;
    int idx = 0;
    cout << s.size() - 1 << '\n';
    for (int u : s) {
        if (prev == -1) {
            prev = u;
        } else {
            cout << close[idx].first << " " << close[idx].second << " " << prev << " " << u << '\n';
            idx++;
            prev = u;
        }
    }
    return 0;
}