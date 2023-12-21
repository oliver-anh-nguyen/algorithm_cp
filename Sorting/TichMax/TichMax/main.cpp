//
//  main.cpp
//  TichMax
//
//  Created by AnhNguyen on 24/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int main() {
    long long res;
    int n;
    cin >> n;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long max1 = 1LL * a[n - 1] * a[n - 2] * a[n - 3];
    long long max2 = 1LL * a[0] * a[1] * a[n-1];
    res = max(max1, max2);
    cout << res << '\n';
    return 0;
}












