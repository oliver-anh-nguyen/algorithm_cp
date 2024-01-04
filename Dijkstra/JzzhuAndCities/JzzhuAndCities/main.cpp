//
//  main.cpp
//  JzzhuAndCities
//
//  Created by AnhNguyen on 03/01/2024.
//

#include <iostream>
#include <queue>
using namespace std;

#define pii pair<int, int>

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        a--;
        b--;
        graph[a].push_back({b, x});
        graph[b].push_back({a, x});
    }
    for (int i = 0; i < k; i++) {
        int s, x;
        cin >> s >> x;
        s--;
        graph[0].push_back({s, -x});
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<int> dis(n, 1e9);
    vector<bool> need(n, false);
    dis[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int s = q.top().second;
        int distance = q.top().first;
        q.pop();
        if (distance != dis[s]) continue;
        for (auto c : graph[s]) {
            if (c.second < 0) {
                c.second = -c.second;
                if (dis[c.first] > dis[s] + c.second) {
                    dis[c.first] = dis[s] + c.second;
                    q.push({dis[c.first], c.first});
                    need[c.first] = true;
                }
            } else {
                if (dis[c.first] >= dis[s] + c.second) {
                    dis[c.first] = dis[s] + c.second;
                    q.push({dis[c.first], c.first});
                    need[c.first] = false;
                }
            }
        }
    }
    int ans = k;
    for (auto c :  need) {
        ans -= c;
    }
    cout << ans << '\n';
    return 0;
}
