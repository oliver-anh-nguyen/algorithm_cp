//
//  main.cpp
//  DenDuong
//
//  Created by AnhNguyen on 24/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, L;
vector<int> a;

int main() {
    cin >> n >> L;
    a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    double dLeft = a[1] - 0;
    double dRight = L - a[n];
    double dMid = 0;
    for (int i = 1; i < n; i++) {
        dMid = max(dMid, (a[i+1] - a[i]) / 2.0);
    }
    double ans = max(dLeft, max(dRight, dMid));
    cout << setprecision(2) << fixed << ans;
    return 0;
}
