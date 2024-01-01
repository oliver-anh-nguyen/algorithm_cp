//
//  main.cpp
//  Cirarc
//
//  Created by AnhNguyen on 31/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int n, m;
vector<int> graph[N];
int edgeCount[N][N];
int visited[N];
int path[N];
int finishV;

void dfs(int u, int &finishV) {
    visited[u] = 1;
    for(int v: graph[u]) {
        if (edgeCount[u][v] == 0) {
            continue;
        }
        if (visited[v] == 2) {
            continue;
        }
        path[v] = u;
        if (visited[v] == 1) {
            finishV = v;
            break;
        }
        dfs(v, finishV);
        if (finishV != -1) {
            break;
        }
    }
    visited[u] = 2;
}

bool findCycle() {
    fill(visited, visited + n + 1, 0);
    finishV = -1;
    for (int u = 1; u <= n; u++) {
        if (visited[u] == 0) {
            dfs(u, finishV);
            if (finishV != -1) {
                return true;
            }
        }
    }
    return false;
}

vector <pair<int, int>> traceCycle() {
    vector <pair <int, int>> cycle;
    int v = finishV;
    do {
        int u = path[v];
        cycle.push_back({u, v});
        v = u;
    } while (v != finishV);
    return cycle;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (edgeCount[u][v] == 0) {
            graph[u].push_back(v);
        }
        edgeCount[u][v] += 1;
    }
    if (!findCycle()) {
        cout << -1 << '\n';
        return 0;
    }
    vector <pair<int, int>> cycle = traceCycle();
    vector <pair<int, int>> ans;
    for (auto edge: cycle) {
        int u = edge.first;
        int v = edge.second;
        if (edgeCount[u][v] > 1) {
            continue;
        }
        edgeCount[u][v] = 0;
        if (!findCycle()) {
            ans.push_back(edge);
        }
        edgeCount[u][v] = 1;
    }
    if (ans.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto edge: ans) {
        cout << edge.first << ' ' << edge.second << '\n';
    }
    return 0;
}
