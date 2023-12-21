//
//  main.cpp
//  Balanced
//
//  Created by AnhNguyen on 19/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] - a[j] > 5) {
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << '\n';
    return 0;
}
