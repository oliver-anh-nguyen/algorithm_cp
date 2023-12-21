//
//  main.cpp
//  BitParty
//
//  Created by AnhNguyen on 03/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int maxC = 1005;

int r, b, c;
int m[maxC], s[maxC], p[maxC];

bool solve(long long t) {
    int capacity[maxC];
    for (int i = 0; i < c; i++) {
        long long minCap = min((long long)m[i], (long long)floor((long double)(t - p[i])/s[i]));
        capacity[i] = max(0LL, minCap);
    }
    sort(capacity, capacity + c, greater<int>());
    long long sum = 0;
    for (int i = 0; i < r; i++) {
        sum += 1LL*capacity[i];
    }
    return sum >= b;
}

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> r >> b >> c;
        int maxS = 0;
        int maxP = 0;
        for (int i = 0; i < c; i++) {
            cin >> m[i] >> s[i] >> p[i];
            maxS = max(maxS, s[i]);
            maxP = max(maxP, p[i]);
        }
        long long res, l = 0, r = 1LL*maxS*b + maxP;
        while (l <= r) {
            long long m = (l + r)/2;
            if (solve(m) == true) {
                r = m - 1;
                res = m;
            } else {
                l = m + 1;
            }
        }
        cout << "Case #" << t << ": " << res << '\n';
    }
    return 0;
}
