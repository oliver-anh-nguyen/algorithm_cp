//
//  main.cpp
//  Retakes
//
//  Created by AnhNguyen on 24/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int t[n + 5], c[n + 5], res[n + 5];
    priority_queue<p, vector<p>> heap;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> c[i];
    }
    int m = 0;
    for (int i = 1; i <= t[n - 1] + n; i++) {
        while (m < n && t[m] <= i) {
            heap.push({c[m] - t[m], m});
            m++;
        }
        if (!heap.empty()) {
            int id = heap.top().second;
            res[id] = i;
            heap.pop();
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}
