//
//  main.cpp
//  City
//
//  Created by AnhNguyen on 01/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
const int MAX_N = 501;
const int MAX_K = 2005;
int m, n, k;
int a[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0 , 0, 1, -1, 1, -1, -1, 1};
bool mark[8 * 1000005];


int main() {
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int>markSum;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int sum = 0;
            for (int t = 0; t < 8; t++) {
                int x = i + dx[t];
                int y = j + dy[t];
                if (x >= 1 && x <= m && y >= 1 && y <= n) {
                    sum += a[x][y];
                }
            }
            markSum.push_back(sum);
        }
    }
    for (int i = 1; i <= k; i++) {
        int c;
        cin >> c;
        if (find(markSum.begin(), markSum.end(), c) != markSum.end()) {
            cout << 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
    return 0;
}
