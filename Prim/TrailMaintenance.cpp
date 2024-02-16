#include <iostream>
#include <vector>
#include <queue>
//#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int maxN = 202;
int n, w, dist[maxN], visited[maxN];
vector<ii> graph[maxN];

int prim(int x) {
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e9;
        visited[i] = false;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, x));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v, w] : graph[u]) {
            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push(ii(w, v));
            }
        }
    }
    int res = 0;
    for (int i = 2; i <= n; i++) {
        if (dist[i] == 1e9) {
            return -1;
        }
        res += dist[i];
    }
    return res;
}

int main() {
    cin >> n >> w;
    for (int i = 1; i <= w; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(ii(v, c));
        graph[v].push_back(ii(u, c));
        cout << prim(1) << '\n';
    }
    return 0;
}
