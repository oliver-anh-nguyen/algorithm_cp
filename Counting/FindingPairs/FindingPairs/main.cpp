//
//  main.cpp
//  FindingPairs
//
//  Created by AnhNguyen on 10/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        int n;
        cin >> n;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            cnt[tmp]++;
        }
        int ans = n;
        for (auto i: cnt) {
            ans += i.second * (i.second - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
