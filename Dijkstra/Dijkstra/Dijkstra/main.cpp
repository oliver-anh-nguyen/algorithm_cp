//
//  main.cpp
//  Dijkstra
//
//  Created by AnhNguyen on 02/01/2024.
//

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;
vector<int> dist;
vector<int> path;
vector<vector<pii>> adj;
int n, m;

void dijkstra() {
    dist.assign(n + 1, INF);
    path.assign(n + 1, -1);
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        if (tmp.first != dist[u]) {
            continue;
        }
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                path[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void printPath(int s, int f) {
    if (s == f) {
        cout << f << " ";
    } else {
        if (path[f] == -1) {
            cout << -1 << '\n';
        } else {
            printPath(s, path[f]);
            cout << f << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    adj.assign(n + 1, vector<pii>());
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra();
    printPath(1, n);
    return 0;
}
