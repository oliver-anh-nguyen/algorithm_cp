#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int maxN = 1e6 + 5;
typedef pair<int, int> ii;

int n, m;
vector<ii> g[maxN];

int prim() {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v, w] : g[u]) {
            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dist[i]);
    }
    return res;
}

int main() {
    while (true) {
        cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            g[i].clear();
        }

        while (m--) {
            int i, j, c;
            cin >> i >> j >> c;
            g[i].push_back(ii(j, c));
            g[j].push_back(ii(i, c));
        }

        int result = prim();

        if (result == INF) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << result << '\n';
        }
    }

    return 0;
}
