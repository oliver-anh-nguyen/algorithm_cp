#include <iostream>
#include <vector>
#include <queue>


using namespace std;

typedef pair<int, int> ii;

const int N = 2e5 + 5;
const int INF = 1e9;
int n, m;
vector<ii> g[N];
int ans;

void prim() {
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    dist[1] = 0;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v, w]: g[u]) {
            if (!visited[v] && dist[v] > w)
            {
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
    }

    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp += dist[i];
    };
    cout << ans - tmp << '\n';
}

void solve() {
    ans = 0;
    for (int u, v, w, i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        u++;
        v++;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        ans += w;
    }
    prim();
    for (int i = 1; i <= n; i++) g[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        solve();
    }
    return 0;
}
