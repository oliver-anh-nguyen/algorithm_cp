//
//  main.cpp
//  QBBiShop
//
//  Created by AnhNguyen on 31/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int inf = 1e9;

const int dx[4] = { -1 , -1, 1, 1 };
const int dy[4] = { -1, 1, -1, 1 };

int n, m, sX, sY, eX, eY;
int obs[N][N], d[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> sX >> sY >> eX >> eY;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        obs[x][y] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = inf;
        }
    }
    queue<pair<int, int>> q;
    d[sX][sY] = 0;
    q.push({sX, sY});
    while (q.size()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for (int t = 0; t < 4; t++) {
            for (int step = 1; ;step++) {
                int x = u + dx[t] * step;
                int y = v + dy[t] * step;
                if (x < 1 || y < 1 || x > n || y > n) {
                    break;
                }
                if (obs[x][y]) {
                    break;
                }
                if (d[x][y] > d[u][v] + 1) {
                    d[x][y] = d[u][v] + 1;
                    q.push({ x, y });
                }
            }
        }
    }
    
    if (d[eX][eY] == inf) {
        cout << -1 << '\n';
    } else {
        cout << d[eX][eY] << '\n';
    }
    
    return 0;
}
