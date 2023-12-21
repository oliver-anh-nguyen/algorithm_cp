//
//  main.cpp
//  GoodTrip
//
//  Created by AnhNguyen on 13/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length();
    LL ans = (LL)(n + 1) * n / 2;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            bool find = false;
            for (int k = j - 1; k >= i + 1; --k) {
                if (s[k] == s[j] && 2 * k - j >= i && s[2 * k - j] == s[j]) {
                    find = true;
                    cout << "l: " << i << ", r: " << j << ", x: " << k << ", k: " << j - k << endl;
                    break;
                }
            }
            if (find) break;
            --ans;
        }
    }

    cout << ans << endl;
    return 0;
}

// 010101
