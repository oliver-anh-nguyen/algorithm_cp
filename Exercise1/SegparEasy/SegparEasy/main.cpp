//
//  main.cpp
//  SegparEasy
//
//  Created by AnhNguyen on 02/12/2023.
//

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int n, k, a[15002];

int solve(int x) {
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (sum + a[i] <= x) {
            sum += a[i];
        } else {
            cnt += 1;
            sum = a[i];
        }
    }
    cnt += 1;
    if (cnt > k) {
        return false;
    }
    return true;
}

int main() {
    cin >> n >> k;
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r += a[i];
    }
    int res;
    while (l <= r) {
        int m = (l + r)/2;
        if(solve(m)) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << res << '\n';
    return 0;
}
