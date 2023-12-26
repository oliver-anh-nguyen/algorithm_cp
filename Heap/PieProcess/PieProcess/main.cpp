//
//  main.cpp
//  PieProcess
//
//  Created by AnhNguyen on 25/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int a[305];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, n, m;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> n >> m;
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[j];
            }
            sort(a + 1, a + 1 + m);
            for (int p = 1; p <= m; p++) {
                pq.push(a[p] + p*p - (p-1)*(p-1));
            }
            res += pq.top();
            pq.pop();
        }
        cout << "Case #" << tc << ": " << res << '\n';
    }
    return 0;
}

