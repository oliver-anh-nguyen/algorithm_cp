//
//  main.cpp
//  SnapperChain
//
//  Created by AnhNguyen on 27/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc, n, k;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cin >> n >> k;
        int bitOne = 0;
        cout << "Case #" << i << ": ";
        for (int j = 0; j < n; j++) {
            if (k & 1 == 1) {
                bitOne++;
            }
            k >>= 1;
        }
        if (bitOne == n) {
            cout << "ON" << '\n';
        } else {
            cout << "OFF" << '\n';
        }
    }
    return 0;
}
