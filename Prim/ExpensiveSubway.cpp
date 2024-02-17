#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int INF = 1e9;
const int maxN = 400 + 5;
typedef pair<int, int> ii;

int n, m;
map<string, int> stationIndex;
vector<ii> g[maxN];

pair<int, vector<int>> prim(int start) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
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
        res += dist[i];
    }
    return {res, dist};
}


int main() {
    while (true) {
        cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }
        
        stationIndex.clear();

        for (int i = 0; i < n; i++) {
            string stationName;
            cin >> stationName;
            stationIndex[stationName] = i;
            g[i].clear();
        }

        while (m--) {
            string from, to;
            int cost;
            cin >> from >> to >> cost;
            g[stationIndex[from]].push_back(ii(stationIndex[to], cost));
            g[stationIndex[to]].push_back(ii(stationIndex[from], cost));
        }

        string startStation;
        cin >> startStation;
        
        auto [res, dist] = prim(stationIndex[startStation]);
        bool isPossible = true;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) {
                isPossible = false;
                break;
            }
        }
        if (!isPossible) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << res << '\n';
        }
    }

    return 0;
}
