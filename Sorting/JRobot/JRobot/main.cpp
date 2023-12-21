//
//  main.cpp
//  JRobot
//
//  Created by AnhNguyen on 24/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int h[1005][1005];
vector<int>a;

int main() {
    int n, m, u, v;
    cin >> n >> m;
    int idx = 0;
    a = vector<int>(m*n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> h[i][j];
            a[idx++] = h[i][j];
        }
    }
    cin >> u >> v;
    int x = h[u][v];
    int res = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n*m; i++) {
        if (a[i] > x) {
            x = a[i];
            res++;
        }
    }
    cout << res;
    return 0;
}
