#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2e5 + 5;
vector<int> graph[MAX];
int low[MAX];
int num[MAX];
int n, m, counter;
long long sz[MAX], sum, critEdge;

void dfs(int u, int p) {
    counter++;
    low[u] = num[u] = counter;
    sz[u] = 1;
    for (int v : graph[u]) {
        if (v == p) continue;
        if (num[v] > 0) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs(v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[v]) {
                critEdge++;
                sum += sz[v] * (n - sz[v]) - 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int countComp = 0;
    counter = 0;
    sum = 0;
    critEdge = 0;
    for (int u = 1; u <= n; u++) {
        if (!num[u]) {
            dfs(u, u);
            countComp++;
        }
    }
    if (countComp == 1) {
        cout << sum + 1LL * (m - critEdge) * (1LL * n * (n-1) / 2 - m);
    }
    if (countComp == 2) {
        cout << 1LL * (m - critEdge) * sz[1] * (n - sz[1]);
    }
    if (countComp >= 3) {
        cout << 0;
    }
    return 0;
}
