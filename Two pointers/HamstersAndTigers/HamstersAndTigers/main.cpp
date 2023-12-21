//
//  main.cpp
//  HamstersAndTigers
//
//  Created by AnhNguyen on 20/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cnt[2*1007];
    int n;
    cin >> n;
    cin >> s;
    s += s;
    int cnt_hamster = 0;
    for (int i = 0; i < 2*n; i++) {
        if (s[i] == 'H') {
            cnt_hamster += 1;
        }
        if (i == 0) {
            cnt[i] = 0;
        } else {
            cnt[i] = cnt[i-1];
        }
        if (s[i] == 'T') {
            cnt[i] += 1;
        }
    }
    cnt_hamster /= 2;
    int res = cnt[cnt_hamster - 1];
    for (int i = 1; i < 2 * n - cnt_hamster; i++) {
        int t = cnt[i + cnt_hamster - 1] - cnt[i - 1];
        res = min(res, t);
    }
    cout << res;
    return 0;
}
