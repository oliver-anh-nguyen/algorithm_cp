//
//  main.cpp
//  Tourist
//
//  Created by AnhNguyen on 25/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long v;
int n, k;
string a[55];

bool option(pair<string, int> x, pair<string, int> y) {
    return x.second < y.second;
}

void solve() {
    cin >> n >> k >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    long long p = (k * (v-1)) % n;
    if (p == 0) p = n;
    
    vector<pair<string, int>> res;
    for (int i = 1; i <= k ; i++) {
        p += 1;
        if (p > n) p = 1;
        res.push_back(pair<string, int>(a[p], p));
    }
    sort(res.begin(), res.end(), option);
    for (pair<string, int> i : res) {
        cout << i.first << ' ';
    }
    cout << '\n';
}

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
