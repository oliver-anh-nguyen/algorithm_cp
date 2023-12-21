//
//  main.cpp
//  TroubleSort
//
//  Created by AnhNguyen on 25/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc, n;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cin >> n;
        vector<int> a = vector<int>(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        cout << "Case #" << i << ": ";
        vector<int> even, odd;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even.push_back(a[i]);
            } else {
                odd.push_back(a[i]);
            }
        }
        
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a[i] = even[i / 2];
            } else {
                a[i] = odd[i / 2];
            }
        }
        int res = -1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i+1]) {
                res = i;
                break;
            }
        }
        if (res == -1) {
            cout << "OK" << '\n';
        } else {
            cout << res << '\n';
        }
    }
    return 0;
}
