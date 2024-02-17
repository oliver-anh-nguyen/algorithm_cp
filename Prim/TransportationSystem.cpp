#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int maxN = 1e9;

int distance(ii a, ii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void prim(vector <vector <ii>> &graph, vector<int> &dist) {
    vector<bool> visited(dist.size(), false);
    priority_queue <ii, vector <ii>, greater <ii>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v, w] : graph[u]) {
            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
        
    }
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, r;
        cin >> n >> r;
        vector <ii> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        vector<vector<ii>> graph(n, vector <ii>());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = distance(points[i], points[j]);
                graph[i].push_back({j, dist});
                graph[j].push_back({i, dist});
            }
        }
        vector<int> dist (n, maxN);
        prim(graph, dist);
        int state = 1;
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] > r * r) {
                state += 1;
                sum2 += sqrt(1.0 * dist[i]);
            } else {
                sum1 += sqrt(1.0 * dist[i]);
            }
        }
        cout << "Case #" << tc << ": " << state << " " << int(sum1 + 0.5) << " " << int(sum2 + 0.5) << '\n';
    }
    return 0;
}
