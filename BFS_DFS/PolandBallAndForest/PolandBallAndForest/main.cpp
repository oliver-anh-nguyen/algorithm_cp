//
//  main.cpp
//  PolandBallAndForest
//
//  Created by AnhNguyen on 30/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n, visited[N];
vector <int> adj[N];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
